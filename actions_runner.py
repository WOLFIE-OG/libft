# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    actions_runner.py                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otodd <otodd@student.42london.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 11:56:46 by otodd             #+#    #+#              #
#    Updated: 2024/12/03 18:49:52 by otodd            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import os
import logging
from yaml import safe_load
from subprocess import Popen, PIPE
from uuid import uuid4
from pathlib import Path
from git import Repo
from git.util import RemoteProgress

JOB_NAME = "build"
COLORS = {
    "DEBUG": "\033[94m",
    "INFO": "\033[92m",
    "WARNING": "\033[93m",
    "ERROR": "\033[91m",
    "CRITICAL": "\033[95m",
    "RESET": "\033[0m",
}


class ColoredFormatter(logging.Formatter):
    def format(self, record):
        color = COLORS.get(record.levelname, COLORS["RESET"])
        record.levelname = f"{color}{record.levelname}{COLORS['RESET']}"
        return super().format(record)


console_handler = logging.StreamHandler()
console_handler.setLevel(logging.DEBUG)
log_format = "[%(levelname)s] :: [%(asctime)s] :: %(message)s"
formatter = ColoredFormatter(log_format, datefmt="%Y-%m-%d %H:%M:%S")
console_handler.setFormatter(formatter)
ID = uuid4().__str__()
logger = logging.getLogger("actions_runner")
logging.basicConfig(level=logging.DEBUG, filename=Path(ID + ".log"))
logger.addHandler(console_handler)

TMP_DIR = Path("/tmp/actions_runner")
if not os.path.exists(TMP_DIR):
    os.mkdir(TMP_DIR)

with open(".github/workflows/makefile.yml") as f:
    action = safe_load(f)

env = action["jobs"][JOB_NAME].get("env")
env_i = [item for item in action["jobs"][JOB_NAME].get("env", {}).keys()]
logger.info("Fetching repo url")
proc = Popen("git config --get remote.origin.url", stdout=PIPE, shell=True)
repo_url = proc.stdout.read().decode("utf-8").strip()
repo_dir = Path(TMP_DIR, os.getcwd().split("/")[0], ID)
os.mkdir(repo_dir)
logger.info(f"Cloning [{repo_url}] into {repo_dir}")


class Progress(RemoteProgress):
    def __init__(self) -> None:
        super().__init__()

    def update(self, *args):
        logger.info(self._cur_line)


Repo.clone_from(
    multi_options=["--recursive"], to_path=repo_dir, url=repo_url, progress=Progress()
)

logger.info(f"Running steps for {action.get("name")} on job {JOB_NAME}")

length = len(action["jobs"][JOB_NAME].get("steps"))
for index, step in enumerate(action["jobs"][JOB_NAME].get("steps")):
    if not step.get("run"):
        continue
    logger.info(f"{10 * '='}| Running step ({index} / {length}): {step.get("name")} |{10 * '='}")
    out = PIPE
    cmd_prep: str = step.get("run")
    for i in env_i:
        cmd_prep = cmd_prep.replace(f"${i}", env.get(i))
    proc = Popen(
        cmd_prep,
        stdout=out,
        stderr=out,
        cwd=(
            Path(repo_dir.__str__() + "/" + step.get("working-directory"))
            if step.get("working-directory")
            else Path(repo_dir)
        ),
        shell=True,
    )
    logger.debug(
        f"{5 * '='}| [ Step stdout start ] |{5 * '='}\n"
        + "\n".join([line.decode("utf-8").strip() for line in proc.stdout.readlines()])
    )
    ret = proc.wait(500)
    if ret != 0:
        logger.info(f"{5 * '='} [ Step stdout finish ] {5 * '='}")
        logger.error(f"{4 * '-'}| Step {index} failed! |{4 * '-'}")
        logger.error(f"CMD [{step.get("run")}]")
        logger.error(
            f"{5 * '='} [ Step stderr start ] {5 * '='}\n"
            + "\n".join(
                [line.decode("utf-8").strip() for line in proc.stderr.readlines()]
            )
        )
        logger.error(f" {5 * '='} [ Step stderr finish ] {5 * '='}")
        if step.get("continue-on-error", False) != True:
            exit()
            logger.info("Exiting")
    logger.info(f"{5 * '='} [ Step stdout finish ] {5 * '='}")
    logger.info(f"{10 * '='}| Finished step |{10 * '='}\n")
    
logger.warning(f"Cleaning tmp {repo_dir}")
os.system(f"rm -rf {repo_dir}")
logger.info("Exiting")