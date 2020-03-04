# Copyright (c) Microsoft. All rights reserved.
# Licensed under the MIT license. See LICENSE file in the project root for full license information.

# This is CMakeLists.txt for dcm_lib.

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

project("dcm_lib")

# Capability model library header files.
set(dcm_lib_h_files
    ./include/pnp_schema_types.h
	./include/sample_device_impl.h
    ./include/pnp_schema_serializer.h
	./include/deviceinfo_interface.h
    ./include/sensor_interface.h
    ./include/utility/digitaltwin_client_helper.h
)

# Capability model library source files.
set(dcm_lib_c_files   
    ./src/sample_device_impl.c
	./src/pnp_schema_serializer.c
	./src/deviceinfo_interface.c
    ./src/sensor_interface.c
    ./src/utility/digitaltwin_client_helper.c
)

# Capability model library target.
add_library(dcm_lib ${dcm_lib_c_files} ${dcm_lib_h_files})

# Capability model library public include path.
target_include_directories(dcm_lib PUBLIC include)
target_include_directories(dcm_lib PUBLIC include/utility)

# Find azure_iot_sdks Vcpkg package
find_package(azure_iot_sdks REQUIRED)

include_directories(.)
include_directories(${MQTT_INC_FOLDER} ${SHARED_UTIL_INC_FOLDER} ${UMOCK_C_INC_FOLDER} ${MACRO_UTILS_INC_FOLDER} ${IOTHUB_CLIENT_INC_FOLDER} ${DIGITALTWIN_CLIENT_INC_FOLDER})

# Link requried library here if needed.
target_link_libraries(dcm_lib
parson
iothub_client_mqtt_transport
iothub_client
digitaltwin_client
prov_auth_client
aziotsharedutil
umqtt
)