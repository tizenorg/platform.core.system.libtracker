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

static char *service_name_str(tracker_service_e svc, char *buf, size_t len)
{
	char *str;

	if (!buf)
		return NULL;

	switch (svc) {
	case TRACKER_SERVICE_DOWNLOAD:
		str = "DOWNLOAD";
		break;
	case TRACKER_SERVICE_MEDIA:
		str = "MEDIA";
		break;
	case TRACKER_SERVICE_NETWORK:
		str = "NETWORK";
		break;
	case TRACKER_SERVICE_LOCATION:
		str = "LOCATION";
		break;
	case TRACKER_SERVICE_SENSOR:
		str = "SENSOR";
		break;
	case TRACKER_SERVICE_IOT:
		str = "IoT";
		break;
	default:
		str = "unknown";
		break;
	}

	snprintf(buf, len, "%s", str);
	return str;
}

static void start_service(tracker_service_e svc, int types)
{
	char buf[32];

	if (types < 0)
		return;

	_I("Service (%s) is started",
			service_name_str(svc, buf, sizeof(buf)));

	if (types & TRACKER_TYPE_POWER_LOCK)
		power_lock_ref(svc);
}

static void stop_service(tracker_service_e svc, int types)
{
	char buf[32];

	if (types < 0)
		return;

	_I("Service (%s) is stopped",
			service_name_str(svc, buf, sizeof(buf)));

	if (types & TRACKER_TYPE_POWER_LOCK)
		power_lock_unref(svc);
}

void start_service_download(int types)
{
	start_service(TRACKER_SERVICE_DOWNLOAD, types);
}

void stop_service_download(int types)
{
	stop_service(TRACKER_SERVICE_DOWNLOAD, types);
}

void start_service_media(int types)
{
	start_service(TRACKER_SERVICE_MEDIA, types);
}

void stop_service_media(int types)
{
	stop_service(TRACKER_SERVICE_MEDIA, types);
}

void start_service_network(int types)
{
	start_service(TRACKER_SERVICE_NETWORK, types);
}

void stop_service_network(int types)
{
	stop_service(TRACKER_SERVICE_NETWORK, types);
}

void start_service_location(int types)
{
	start_service(TRACKER_SERVICE_LOCATION, types);
}

void stop_service_location(int types)
{
	stop_service(TRACKER_SERVICE_LOCATION, types);
}

void start_service_sensor(int types)
{
	start_service(TRACKER_SERVICE_SENSOR, types);
}

void stop_service_sensor(int types)
{
	stop_service(TRACKER_SERVICE_SENSOR, types);
}

void start_service_iot(int types)
{
	start_service(TRACKER_SERVICE_IOT, types);
}

void stop_service_iot(int types)
{
	stop_service(TRACKER_SERVICE_IOT, types);
}
