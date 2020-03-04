#Copyright (c) Microsoft. All rights reserved.
#Licensed under the MIT license. See LICENSE file in the project root for full license information.

#this is CMakeLists.txt for iot_project

cmake_minimum_required(VERSION 2.8)

#Compile As C99
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

project(iot_project)

set(iot_project_h_files
    ./pnp_device.h
)

set(iot_project_c_files
    ./pnp_device.c
    ./main.c
)

# Find azure_iot_sdks Vcpkg package
find_package(azure_iot_sdks REQUIRED)

# Add source code from azure-iot-sdk-c as a subdirectory
#add_subdirectory(azure-iot-sdk-c)

# Include the capability model library.
#add_subdirectory(dcm_lib)
add_subdirectory(capability_model_lib)
add_subdirectory(dt_interface_lib)

# Add include directories to the build.
include_directories(.)
include_directories(${MQTT_INC_FOLDER} ${SHARED_UTIL_INC_FOLDER} ${UMOCK_C_INC_FOLDER} ${MACRO_UTILS_INC_FOLDER} ${IOTHUB_CLIENT_INC_FOLDER} ${DIGITALTWIN_CLIENT_INC_FOLDER})

add_executable(iot_project ${iot_project_c_files} ${iot_project_h_files})

target_link_libraries(iot_project
parson
iothub_client_mqtt_transport
iothub_client
digitaltwin_client
prov_auth_client
aziotsharedutil
umqtt
#dcm_lib
capability_model_lib
dt_interface_lib
)
