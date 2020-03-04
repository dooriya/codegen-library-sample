# Copyright (c) Microsoft. All rights reserved.
# Licensed under the MIT license. See LICENSE file in the project root for full license information.

# This is CMakeLists.txt for dt_interface_lib.

cmake_minimum_required(VERSION 2.8)

# Compile As C99
if (CMAKE_VERSION VERSION_LESS "3.1")
    if (CMAKE_C_COMPILER_ID STREQUAL "GNU" OR CMAKE_C_COMPILER_ID STREQUAL "Clang")
        set (CMAKE_C_FLAGS "--std=c99 /DWIN32 /D_WINDOWS /W3")
        if (NOT IN_OPENWRT)
            set (CMAKE_CXX_FLAGS "--std=c++11 /DWIN32 /D_WINDOWS /W3 /GR /EHsc")
        endif()
    endif()
else()
    set (CMAKE_C_STANDARD 99)
    set (CMAKE_CXX_STANDARD 11)
endif()

project("dt_interface_lib")

# Digital Twin interface library header files.
set(dt_interface_lib_h_files
    ./include/deviceinfo_interface.h
    ./include/sensor_interface.h
    ./include/utility/digitaltwin_client_helper.h
)

# Digital Twin interface library source files.
set(dt_interface_lib_c_files
    ./src/deviceinfo_interface.c
    ./src/sensor_interface.c
    ./src/utility/digitaltwin_client_helper.c
)

# Capability model library target.
add_library(dt_interface_lib ${dt_interface_lib_c_files} ${dt_interface_lib_h_files})

# Find azure_iot_sdks Vcpkg package
find_package(azure_iot_sdks REQUIRED)

# Capability model library public include path.
target_include_directories(dt_interface_lib PUBLIC include)
target_include_directories(dt_interface_lib PUBLIC include/utility)

include_directories(.)
include_directories(${azure_iot_sdks_SOURCE_DIR}/deps/parson ${UMOCK_C_INC_FOLDER} ${SHARED_UTIL_INC_FOLDER} ${MACRO_UTILS_INC_FOLDER} ${MQTT_INC_FOLDER} ${IOTHUB_CLIENT_INC_FOLDER} ${DIGITALTWIN_CLIENT_INC_FOLDER})

# Link requried library here if needed.
target_link_libraries(dt_interface_lib
parson
aziotsharedutil
prov_auth_client
iothub_client_mqtt_transport
iothub_client
digitaltwin_client
umqtt
capability_model_lib
)