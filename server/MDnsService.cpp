/**
 * Copyright (c) 2022, The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define LOG_TAG "MDnsService"

#include "MDnsService.h"

#include "binder_utils/BinderUtil.h"
#include "binder_utils/NetdPermissions.h"

#include <android-base/strings.h>
#include <binder/Status.h>

#include <string>
#include <vector>

using android::net::mdns::aidl::DiscoveryInfo;
using android::net::mdns::aidl::GetAddressInfo;
using android::net::mdns::aidl::IMDnsEventListener;
using android::net::mdns::aidl::RegistrationInfo;
using android::net::mdns::aidl::ResolutionInfo;

namespace android::net {

// TODO: DnsResolver has same macro definition but returns ScopedAStatus. Move these macros to
// BinderUtil.h to do the same permission check.
#define ENFORCE_ANY_PERMISSION(...)                                \
    do {                                                           \
        binder::Status status = checkAnyPermission({__VA_ARGS__}); \
        if (!status.isOk()) {                                      \
            return status;                                         \
        }                                                          \
    } while (0)

#define ENFORCE_NETWORK_STACK_PERMISSIONS() \
    ENFORCE_ANY_PERMISSION(PERM_NETWORK_STACK, PERM_MAINLINE_NETWORK_STACK)

status_t MDnsService::start() {
    IPCThreadState::self()->disableBackgroundScheduling(true);
    const status_t ret = BinderService<MDnsService>::publish();
    if (ret != android::OK) {
        return ret;
    }
    return android::OK;
}

binder::Status MDnsService::startDaemon() {
    ENFORCE_NETWORK_STACK_PERMISSIONS();
    // default no-op
    return binder::Status::ok();
}

binder::Status MDnsService::stopDaemon() {
    ENFORCE_NETWORK_STACK_PERMISSIONS();
    // default no-op
    return binder::Status::ok();
}

binder::Status MDnsService::registerService(const RegistrationInfo& /*info*/) {
    ENFORCE_NETWORK_STACK_PERMISSIONS();
    // default no-op
    return binder::Status::ok();
}

binder::Status MDnsService::discover(const DiscoveryInfo& /*info*/) {
    ENFORCE_NETWORK_STACK_PERMISSIONS();
    // default no-op
    return binder::Status::ok();
}

binder::Status MDnsService::resolve(const ResolutionInfo& /*info*/) {
    ENFORCE_NETWORK_STACK_PERMISSIONS();
    // default no-op
    return binder::Status::ok();
}

binder::Status MDnsService::getServiceAddress(const GetAddressInfo& /*info*/) {
    ENFORCE_NETWORK_STACK_PERMISSIONS();
    // default no-op
    return binder::Status::ok();
}

binder::Status MDnsService::stopOperation(int32_t /*id*/) {
    ENFORCE_NETWORK_STACK_PERMISSIONS();
    // default no-op
    return binder::Status::ok();
}

binder::Status MDnsService::registerEventListener(
        const android::sp<IMDnsEventListener>& /*listener*/) {
    ENFORCE_NETWORK_STACK_PERMISSIONS();
    // default no-op
    return binder::Status::ok();
}

binder::Status MDnsService::unregisterEventListener(
        const android::sp<IMDnsEventListener>& /*listener*/) {
    ENFORCE_NETWORK_STACK_PERMISSIONS();
    // default no-op
    return binder::Status::ok();
}

}  // namespace android::net
