/*
 * libtracker
 * Copyright (c) 2016 Samsung Electronics Co., Ltd All Rights Reserved
 *
 * Licensed under the Apache License, Version 2.0 (the "License"),
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
*/

#include "tracker.h"
#include "tracker_private.h"

API int tracker_get_power_lock_ref(int *cnt)
{
	int ref;

	ref = get_power_lock_ref();
	if (ref < 0) {
		_E("Failed to get power lock reference count(%d)", ref);
		return ref;
	}

	*cnt = ref;
	return TRACKER_ERROR_NONE;
}

API int tracker_start_services(int services)
{
	if (services < 0)
		return TRACKER_ERROR_INVALID_PARAMETER;

	if (services & TRACKER_SERVICE_DOWNLOAD)
		start_service_download();
	if (services & TRACKER_SERVICE_MEDIA)
		start_service_media();
	if (services & TRACKER_SERVICE_NETWORK)
		start_service_network();
	if (services & TRACKER_SERVICE_LOCATION)
		start_service_location();
	if (services & TRACKER_SERVICE_SENSOR)
		start_service_sensor();
	if (services & TRACKER_SERVICE_IOT)
		start_service_iot();

	return TRACKER_ERROR_NONE;
}

API int tracker_stop_services(int services)
{
	if (services < 0)
		return TRACKER_ERROR_INVALID_PARAMETER;

	if (services & TRACKER_SERVICE_DOWNLOAD)
		stop_service_download();
	if (services & TRACKER_SERVICE_MEDIA)
		stop_service_media();
	if (services & TRACKER_SERVICE_NETWORK)
		stop_service_network();
	if (services & TRACKER_SERVICE_LOCATION)
		stop_service_location();
	if (services & TRACKER_SERVICE_SENSOR)
		stop_service_sensor();
	if (services & TRACKER_SERVICE_IOT)
		stop_service_iot();

	return TRACKER_ERROR_NONE;
}
