# Copyright (c) Microsoft. All rights reserved.
# Licensed under the MIT license. See LICENSE file in the project root for full license information.

# This is CMakeLists.txt for capability_model_lib.

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

project("capability_model_lib")

# Capability model library header files.
set(capability_model_lib_h_files
    ./include/pnp_schema_types.h
    ./include/pnp_schema_serializer.h
    ./include/sample_device_impl.h
)

# Capability model library source files.
set(capability_model_lib_c_files
    ./src/pnp_schema_serializer.c
    ./src/sample_device_impl.c
)

# Capability model library target.
add_library(capability_model_lib ${capability_model_lib_c_files} ${capability_model_lib_h_files})

# Capability model library public include path.
target_include_directories(capability_model_lib PUBLIC include)

include_directories(.)
include_directories(${azure_iot_sdks_SOURCE_DIR}/deps/parson ${UMOCK_C_INC_FOLDER} ${SHARED_UTIL_INC_FOLDER} ${MACRO_UTILS_INC_FOLDER})

# Find azure_iot_sdks Vcpkg package
# find_package(azure_iot_sdks REQUIRED)

# Link requried library here if needed.
target_link_libraries(capability_model_lib
parson
aziotsharedutil
prov_auth_client
)