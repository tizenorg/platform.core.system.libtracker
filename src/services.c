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

char *service_name_str(tracker_service_e svc, char *buf, size_t len)
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

void power_lock_ref_download(void)
{
	power_lock_ref(TRACKER_SERVICE_DOWNLOAD);
}

void power_lock_unref_download(void)
{
	power_lock_unref(TRACKER_SERVICE_DOWNLOAD);
}

void power_lock_ref_media(void)
{
	power_lock_ref(TRACKER_SERVICE_MEDIA);
}

void power_lock_unref_media(void)
{
	power_lock_unref(TRACKER_SERVICE_MEDIA);
}

void power_lock_ref_network(void)
{
	power_lock_ref(TRACKER_SERVICE_NETWORK);
}

void power_lock_unref_network(void)
{
	power_lock_unref(TRACKER_SERVICE_NETWORK);
}

void power_lock_ref_location(void)
{
	power_lock_ref(TRACKER_SERVICE_LOCATION);
}

void power_lock_unref_location(void)
{
	power_lock_unref(TRACKER_SERVICE_LOCATION);
}

void power_lock_ref_sensor(void)
{
	power_lock_ref(TRACKER_SERVICE_SENSOR);
}

void power_lock_unref_sensor(void)
{
	power_lock_unref(TRACKER_SERVICE_SENSOR);
}

void power_lock_ref_iot(void)
{
	power_lock_ref(TRACKER_SERVICE_IOT);
}

void power_lock_unref_iot(void)
{
	power_lock_unref(TRACKER_SERVICE_IOT);
}
