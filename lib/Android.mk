# Copyright (c) 2017 Intel Corporation
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.


LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := libivp
LOCAL_SRC_FILES_64 := lib64/$(LOCAL_MODULE)$(TARGET_SHLIB_SUFFIX)
LOCAL_SRC_FILES_32 := lib/$(LOCAL_MODULE)$(TARGET_SHLIB_SUFFIX)
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_SUFFIX := $(TARGET_SHLIB_SUFFIX)
LOCAL_MULTILIB := both
LOCAL_PROPRIETARY_MODULE := true
LOCAL_EXPORT_C_INCLUDE_DIRS += $(LOCAL_PATH)
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE := libgrallocclient
LOCAL_SRC_FILES_64 := lib64/$(LOCAL_MODULE)$(TARGET_SHLIB_SUFFIX)
LOCAL_SRC_FILES_32 := lib/$(LOCAL_MODULE)$(TARGET_SHLIB_SUFFIX)
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_SUFFIX := $(TARGET_SHLIB_SUFFIX)
LOCAL_MULTILIB := both
LOCAL_PROPRIETARY_MODULE := true
LOCAL_EXPORT_C_INCLUDE_DIRS += $(LOCAL_PATH)
include $(BUILD_PREBUILT)

