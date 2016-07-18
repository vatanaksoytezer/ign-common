/*
 * Copyright (C) 2016 Open Source Robotics Foundation
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
 *
*/
#ifndef IGNITION_COMMON_FFMPEG_INC_HH_
#define IGNITION_COMMON_FFMPEG_INC_HH_

#include <ignition/common/config.hh>

#pragma GCC system_header

#ifdef HAVE_FFMPEG
#ifndef INT64_C
#define INT64_C(c) (c ## LL)
#define UINT64_C(c) (c ## ULL)
#endif

extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavutil/imgutils.h>
#include <libavutil/opt.h>
#include <libswscale/swscale.h>
}

#include <ignition/common/System.hh>

namespace ignition
{
  namespace common
  {
    /// \brief Helper function to avoid deprecation warnings.
    IGNITION_COMMON_VISIBLE
    AVFrame *AVFrameAlloc(void);

    /// \brief Helper function to avoid deprecation warnings.
    IGNITION_COMMON_VISIBLE
    void AVFrameUnref(AVFrame *_frame);

    /// \brief Helper function to avoid deprecation warnings.
    /// \param[in] _packet AVPacket structure that stores compressed data
    IGNITION_COMMON_VISIBLE
    void AVPacketUnref(AVPacket *_packet);
  }
}
#endif

#endif
