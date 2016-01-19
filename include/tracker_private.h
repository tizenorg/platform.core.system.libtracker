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


#ifndef __LIBTRACKER_TRACKER_PRIVATE_H__
#define __LIBTRACKER_TRACKER_PRIVATE_H__

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <dlog.h>

#ifndef API
#define API __attribute__ ((visibility("default")))
#endif

#ifdef LOG_TAG
#undef LOG_TAG
#endif
#define LOG_TAG "LIBTRACKER"

#define _E(fmt, arg...) LOGE(fmt, ##arg)
#define _D(fmt, arg...) LOGD(fmt, ##arg)
#define _I(fmt, arg...) LOGI(fmt, ##arg)

#define _SE(fmt, arg...) SECURE_LOGE(fmt, ##arg)
#define _SD(fmt, arg...) SECURE_LOGD(fmt, ##arg)
#define _SI(fmt, arg...) SECURE_LOGI(fmt, ##arg)

#define ARRAY_SIZE(name) (sizeof(name)/sizeof(name[0]))

#endif /* __LIBTRACKER_TRACKER_PRIVATE_H__ */
