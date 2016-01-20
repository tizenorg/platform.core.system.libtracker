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

#define POWERLOCK_DEFAULT_REF 0

struct powerlock_ref {
	tracker_service_e service;
	unsigned int ref;
} lock_refs[] = {
	{ TRACKER_SERVICE_DOWNLOAD, POWERLOCK_DEFAULT_REF },
	{ TRACKER_SERVICE_MEDIA,    POWERLOCK_DEFAULT_REF },
	{ TRACKER_SERVICE_NETWORK,  POWERLOCK_DEFAULT_REF },
	{ TRACKER_SERVICE_LOCATION, POWERLOCK_DEFAULT_REF },
	{ TRACKER_SERVICE_SENSOR,   POWERLOCK_DEFAULT_REF },
	{ TRACKER_SERVICE_IOT,      POWERLOCK_DEFAULT_REF },
};

int get_power_lock_ref(void)
{
	int sum = 0, i;

	for (i = 0 ; i < ARRAY_SIZE(lock_refs) ; i++)
		sum += lock_refs[i].ref;

	_I("Total reference count of pid(%d) is (%d)",
				getpid(), sum);

	return sum;
}

void power_lock_ref(tracker_service_e service)
{
	int i;

	for (i = 0 ; i < ARRAY_SIZE(lock_refs) ; i++) {
		if (lock_refs[i].service != service)
			continue;
		lock_refs[i].ref++;
		_I("pid(%d) increases power lock reference count to (%d)",
				getpid(), lock_refs[i].ref);
		break;
	}
}

void power_lock_unref(tracker_service_e service)
{
	int i;

	for (i = 0 ; i < ARRAY_SIZE(lock_refs) ; i++) {
		if (lock_refs[i].service != service)
			continue;
		if (lock_refs[i].ref > 0)
			lock_refs[i].ref--;
		_I("pid(%d) decreases power lock reference count to (%d)",
				getpid(), lock_refs[i].ref);
		break;
	}
}
