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

static int power_lock_ref = 0;

API int tracker_get_power_lock_ref(int *cnt)
{
	_I("Power Lock reference count: (%d)", power_lock_ref);
	*cnt = power_lock_ref;
	return TRACKER_ERROR_NONE;
}
