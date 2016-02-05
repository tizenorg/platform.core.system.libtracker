/*
 * libtracker
 * Copyright (c) 2016 Samsung Electronics Co., Ltd All Rights Reserved
 *
 * Licensed under the Apache License, Version 2.0 (the License);
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#ifndef __LIBTRACKER_TRACKER_H__
#define __LIBTRACKER_TRACKER_H__

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @addtogroup LIBTRACKER_MODULE
 * @{
 */

#include <tizen.h>

/**
 * @brief Enumeration of error codes for libtracker
 */
typedef enum {
	TRACKER_ERROR_NONE              = TIZEN_ERROR_NONE,              /**< Successful */
	TRACKER_ERROR_INVALID_PARAMETER = TIZEN_ERROR_INVALID_PARAMETER, /**< Invalid parameter */
	TRACKER_ERROR_OUT_OF_MEMORY     = TIZEN_ERROR_OUT_OF_MEMORY,     /**< Out of memory */
	TRACKER_ERROR_IO_ERROR          = TIZEN_ERROR_IO_ERROR,          /**< An input/output error occurred */
	TRACKER_ERROR_PERMISSION_DENIED = TIZEN_ERROR_PERMISSION_DENIED, /**< No permission to use the API */
	TRACKER_ERROR_NOT_SUPPORTED     = TIZEN_ERROR_NOT_SUPPORTED,     /**< The api is not supported */
} tracker_error_e;

typedef enum {
	TRACKER_SERVICE_DOWNLOAD = 1 << 0, /**< download services */
	TRACKER_SERVICE_MEDIA    = 1 << 1, /**< media operations */
	TRACKER_SERVICE_NETWORK  = 1 << 2, /**< network services */
	TRACKER_SERVICE_LOCATION = 1 << 3, /**< location services */
	TRACKER_SERVICE_SENSOR   = 1 << 4, /**< sensor information */
	TRACKER_SERVICE_IOT      = 1 << 5, /**< IoT services */
} tracker_service_e;

/**
 * @brief   Gets the reference count of the Power Lock operation
 * @since_tizen 3.0
 * @param[out] count The reference count of the Power Lock operation
 * @return  @c 0 on success,
 *          otherwise a negative error value
 * @retval  #TRACKER_ERROR_NONE Successful
 * @retval  #TRACKER_ERROR_INVALID_PARAMETER The input parameter is invalid
 * @retval  #TRACKER_ERROR_PERMISSION_DENIED No permission to use the API
 */
int tracker_get_power_lock_ref(int *count);

/**
 * @brief   Gets the total count of the Power Lock operation
 * @since_tizen 3.0
 * @param[out] count The total count of the Power Lock operation
 * @return  @c 0 on success,
 *          otherwise a negative error value
 * @retval  #TRACKER_ERROR_NONE Successful
 * @retval  #TRACKER_ERROR_INVALID_PARAMETER The input parameter is invalid
 * @retval  #TRACKER_ERROR_PERMISSION_DENIED No permission to use the API
 */
int tracker_get_power_lock_total(int *count);

/**
 * @brief   Start tracking for information of services
 * @details The api should be used only in the framework, not in applications
 * @since_tizen 3.0
 * @param[in] services The services to use internally
 * @return  @c 0 on success,
 *          otherwise a negative error value
 * @retval  #TRACKER_ERROR_NONE Successful
 * @retval  #TRACKER_ERROR_INVALID_PARAMETER The input parameter is invalid
 * @retval  #TRACKER_ERROR_PERMISSION_DENIED No permission to use the API
 */
int tracker_start_services(int services);

/**
 * @brief   Stop tracking for information of services
 * @details The api should be used only in the framework, not in applications
 * @since_tizen 3.0
 * @param[in] services The services not to use internally
 * @return  @c 0 on success,
 *          otherwise a negative error value
 * @retval  #TRACKER_ERROR_NONE Successful
 * @retval  #TRACKER_ERROR_INVALID_PARAMETER The input parameter is invalid
 * @retval  #TRACKER_ERROR_PERMISSION_DENIED No permission to use the API
 */
int tracker_stop_services(int services);

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* __LIBTRACKER_TRACKER_H__ */
