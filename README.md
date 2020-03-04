# Build the Generated CMake Project on Windows

One of the features VS Code Digital Twin tooling provides is generating stub code based on the Device Capability Model (DCM) you specified.

Follow the steps to use the generated code with the Azure IoT Device C SDK source to compile a device app.

For more details about setting up your development environment for compiling the C Device SDK. Check the [instructions](https://github.com/Azure/azure-iot-sdk-c/blob/master/iothub_client/readme.md#compiling-the-c-device-sdk) for each platform.

## Prerequisite
1. Install [Build Tools for Visual Studio](https://visualstudio.microsoft.com/thank-you-downloading-visual-studio/?sku=BuildTools&rel=16) with C++ build tools and NuGet package manager component workloads. Or if you already have [Visual Studio (Community, Professional, or Enterprise) 2019, 2017 or 2015](https://www.visualstudio.com/downloads/) with same workloads installed.

1. Install [git](http://www.git-scm.com/). Confirm git is in your PATH by typing `git version` from a command prompt.

1. Install [CMake](https://cmake.org/). Make sure it is in your PATH by typing `cmake -version` from a command prompt. CMake will be used to create Visual Studio projects to build libraries and samples.

## Build with Source Code of Azure IoT Device C SDK
1. Go to the **root folder of your generated app**.
    ```cmd
    cd sample_lib
    ```

1. git clone the preview release of the Azure IoT Device C SDK to your app folder using the `public-preview` branch.
    ```cmd
    git clone https://github.com/Azure/azure-iot-sdk-c --recursive -b public-preview
    ```
    > The `--recursive` argument instructs git to clone other GitHub repos this SDK depends on. Dependencies are listed [here](https://github.com/Azure/azure-iot-sdk-c/blob/master/.gitmodules).

    NOTE: Or you can copy the source code of Azure IoT Device C SDK to your app folder if you already have a local copy.

1. Create a folder for your CMake build.
    ```cmd
    mkdir cmake
    cd cmake
    ```

1. Run CMake to build your app with `azure-iot-sdk-c` source code.
    ```cmd
    cmake .. -Duse_prov_client=ON -Dhsm_type_symm_key:BOOL=ON
    cmake --build . -- /p:Configuration=Release
    ```

1. Once the build has succeeded, you can test it by specifying the IoT Hub device connection string as its parameter.
    ```cmd
    .\Release\sample_lib.exe "[IoTHub device connection string]"
    ```
