#ifndef PNP_SCHEMA_TYPES_H
#define PNP_SCHEMA_TYPES_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
* Type definition for PnP schema
*/

/**
* @brief Result of DigitalTwin command execution.
*/
typedef enum DIGITALTWIN_COMMAND_RESULT_TAG
{
    DIGITALTWIN_COMMAND_OK,
    DIGITALTWIN_COMMAND_TIMEOUT,
    DIGITALTWIN_COMMAND_ERROR
} DIGITALTWIN_COMMAND_RESULT;

typedef struct SENSOR_LOCATION_TAG
{
    double latitude;

    double longitude;

} SENSOR_LOCATION;

typedef struct SENSOR_BLINK_blinkResponse_TAG
{
    char* description;

} SENSOR_BLINK_blinkResponse;

typedef struct SENSOR_UPDATEFIRMWARE_updateFirmwareResponse_TAG
{
    char* description;

    int statusCode;

} SENSOR_UPDATEFIRMWARE_updateFirmwareResponse;

typedef struct SENSOR_UPDATEFIRMWARE_firmwareRequest_TAG
{
    char* firmwareUri;

    bool retry;

} SENSOR_UPDATEFIRMWARE_firmwareRequest;

#ifdef __cplusplus
}
#endif

#endif  // PNP_SCHEMA_TYPES_H