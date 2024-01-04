# Copyright (c) 2015-2024 LG Electronics, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 2.8.7)

project(webos-connman-adapter-support C)

include(webOS/webOS)
webos_modules_init(1 0 0 QUALIFIER RC9)
webos_component(1 0 0)

include(FindPkgConfig)

pkg_check_modules(GLIB2 REQUIRED glib-2.0)
include_directories(${GLIB2_INCLUDE_DIRS})
webos_add_compiler_flags(ALL ${GLIB2_CFLAGS_OTHER})

pkg_check_modules(LUNASERVICE2 REQUIRED luna-service2)
include_directories(${LUNASERVICE2_INCLUDE_DIRS})
webos_add_compiler_flags(ALL ${LUNASERVICE2_CFLAGS_OTHER})

pkg_check_modules(PBNJSON_C REQUIRED pbnjson_c)
include_directories(${PBNJSON_C_INCLUDE_DIRS})
webos_add_compiler_flags(ALL ${PBNJSON_C_CFLAGS_OTHER})

pkg_check_modules(GIO-UNIX REQUIRED gio-unix-2.0)
include_directories(${GIO-UNIX_INCLUDE_DIRS})
webos_add_compiler_flags(ALL ${GIO-UNIX_CFLAGS_OTHER})

pkg_check_modules(PMLOG REQUIRED PmLogLib)
include_directories(${PMLOG_INCLUDE_DIRS})
webos_add_compiler_flags(ALL ${PMLOG_CFLAGS_OTHER})

pkg_check_modules(LUNAPREFS REQUIRED luna-prefs)
include_directories(${LUNAPREFS_INCLUDE_DIRS})
webos_add_compiler_flags(ALL ${LUNAPREFS_CFLAGS_OTHER})

pkg_check_modules(WCA_SUPPORT_API REQUIRED wca-support-api>=0.1.0)
include_directories(${WCA_SUPPORT_API_INCLUDE_DIRS})
webos_add_compiler_flags(ALL ${WCA_SUPPORT_API_CFLAGS_OTHER})

set(SUPPORT_IMPL "none")
set(EXTRA_IMPL_FILES "")
set(EXTRA_LIBRARIES "")

message(STATUS "Selected ${SUPPORT_IMPL} implementation ..")

file(GLOB SOURCES
        "src/connman_dbus.c" "src/lunaservice_utils.c" "src/logging.c"
        src/support_${SUPPORT_IMPL}.c ${EXTRA_IMPL_FILES})

webos_add_linker_options(ALL --no-undefined)
add_library(wca-support SHARED ${SOURCES})
target_link_libraries(wca-support
		${GLIB2_LDFLAGS}
		${LUNASERVICE2_LDFLAGS}
		${PBNJSON_C_LDFLAGS}
		${GIO-UNIX_LDFLAGS}
		${PMLOG_LDFLAGS}
		${LUNAPREFS_LDFLAGS}
		${EXTRA_LIBRARIES}
		)
webos_build_library(NAME wca-support TARGET wca-support NOHEADERS)

webos_build_pkgconfig(files/pkgconfig/wca-support)
