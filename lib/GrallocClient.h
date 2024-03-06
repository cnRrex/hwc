/*
// Copyright (c) 2017 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
*/

#ifndef INTEL_UFO_GRALLOC_CLIENT_H
#define INTEL_UFO_GRALLOC_CLIENT_H

#include <utils/Singleton.h>
#include <ufo/gralloc.h>


namespace grallocclient {

using namespace android;

/** \deprecated */
typedef BufferMetaData buffer_info_t; //grallocclient::BufferMetaData
typedef intel_ufo_buffer_media_details_t buffer_media_details_t;

/** This class is a wrapper to the functionality exposed by the UFO gralloc module.
 *
 * While this class currently just tracks and returns gralloc info, longer term
 * we are likely to want to track much more info about buffers.
 */
class ANDROID_API GrallocClient : public Singleton<GrallocClient>
{
public:
    static const GrallocClient& get() { return getInstance(); }

    bool check() const;

    int getBufferInfo(buffer_handle_t handle, buffer_info_t* info) const;
    int queryMediaDetails(buffer_handle_t handle, buffer_media_details_t*) const;
    int updateMediaDetails(buffer_handle_t handle, buffer_media_details_t*) const;
    int setBufferPavpSession(buffer_handle_t handle, uint32_t session, uint32_t instance, uint32_t is_encrypted) const;
    int setBufferColorRange(buffer_handle_t handle, uint32_t color) const;
    int setBufferMmcMode(buffer_handle_t handle, uint32_t mmc_mode) const;
    int setBufferKeyFrame(buffer_handle_t handle, uint32_t is_key_frame) const;
    int setBufferCodecType(buffer_handle_t handle, uint32_t codec, uint32_t is_interlaced) const;
    int getBufferPrime(buffer_handle_t handle, int *prime) const;
    int setBufferFrameUpdatedFlag(buffer_handle_t handle, uint32_t is_updated) const;
    int setBufferFrameEncodedFlag(buffer_handle_t handle, uint32_t is_encoded) const;
    int setBufferCompressionHint(buffer_handle_t handle, uint32_t hint) const;
    int getBufferCompressionHint(buffer_handle_t handle, uint32_t* hint) const;


private:
    GrallocClient();
    friend class Singleton<GrallocClient>;

private:
    gralloc_module_t const * mGralloc;
};


/**
 * \return true if gralloc module was loaded and verified
 */
inline bool GrallocClient::check() const
{
    return mGralloc;
}


} // namespace gralloc

#endif // INTEL_UFO_GRALLOC_CLIENT_H
