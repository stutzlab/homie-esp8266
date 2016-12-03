# Copyright 2014-present PlatformIO <contact@platformio.org>
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#    http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import hashlib
import json
import os
import uuid
from copy import deepcopy
from os import environ, getenv, listdir, remove
from os.path import dirname, getmtime, isdir, isfile, join
from time import time

import requests
from lockfile import LockFailed, LockFile

from platformio import __version__, exception, util
from platformio.exception import InvalidSettingName, InvalidSettingValue

DEFAULT_SETTINGS = {
    "check_platformio_interval": {
        "description": "Check for the new PlatformIO interval (days)",
        "value": 3
    },
    "check_platforms_interval": {
        "description": "Check for the platform updates interval (days)",
        "value": 7
    },
    "check_libraries_interval": {
        "description": "Check for the library updates interval (days)",
        "value": 7
    },
    "auto_update_platforms": {
        "description": "Automatically update platforms (Yes/No)",
        "value": False
    },
    "auto_update_libraries": {
        "description": "Automatically update libraries (Yes/No)",
        "value": False
    },
    "force_verbose": {
        "description": "Force verbose output when processing environments",
        "value": False
    },
    "enable_ssl": {
        "description": "Enable SSL for PlatformIO Services",
        "value": False
    },
    "enable_telemetry": {
        "description":
        ("Telemetry service <http://docs.platformio.org/en/stable/"
         "userguide/cmd_settings.html?#enable-telemetry> (Yes/No)"),
        "value": True
    }
}

SESSION_VARS = {"command_ctx": Non