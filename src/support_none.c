// Copyright (c) 2015-2019 LG Electronics, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// SPDX-License-Identifier: Apache-2.0

#include <errno.h>
#include <wca-support.h>

int wca_support_init(LSHandle *ls_wifi_handle, LSHandle *ls_cm_handle,
                wca_support_connman_update_callbacks *wca_callbacks,
                wca_support_callback callback, void *user_data)
{
	if (callback)
		callback(true, user_data);

	return 0;
}

void wca_support_release()
{
}

int wca_support_wifi_enable_tethering(wca_support_callback callback, void *user_data)
{
	if (callback)
		callback(true, user_data);

	return 0;
}

int wca_support_wifi_disable_tethering(wca_support_callback callback, void *user_data)
{
	if (callback)
		callback(true, user_data);

	return 0;
}

int wca_support_wifi_configure_country_code(wca_support_callback callback, void *user_data)
{
	if (callback)
		callback(true, user_data);

	return 0;
}

int wca_support_wifi_set_passthrough_params(jvalue_ref params, wca_support_passthrough_params_callback callback, void *user_data)
{
	if (callback)
		callback(true, NULL, user_data);

	return 0;
}

int wca_support_enable_wol_status(wca_support_callback callback, void *user_data)
{
	if (callback)
		callback(true, user_data);

	return 0;
}

int wca_support_disable_wol_status(wca_support_callback callback, void *user_data)
{
	if (callback)
		callback(true, user_data);

	return 0;
}
