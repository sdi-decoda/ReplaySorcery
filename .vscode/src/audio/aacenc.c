/*
 * Copyright (C) 2020  Joshua Minter
 *
 * This file is part of ReplaySorcery.
 *
 * ReplaySorcery is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * ReplaySorcery is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with ReplaySorcery.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "../config.h"
#include "../encoder/ffenc.h"
#include "aencoder.h"

int rsAacEncoderCreate(RSEncoder *encoder, const AVCodecParameters *params) {
   int ret;
   if (rsConfig.audioProfile == FF_PROFILE_AAC_HE) {
      av_log(NULL, AV_LOG_WARNING, "High profile is not supported\n");
   }
   if ((ret = rsFFmpegEncoderCreate(encoder, "aac", "aformat=fltp")) < 0) {
      goto error;
   }
   if ((ret = rsFFmpegEncoderOpen(encoder, params, NULL)) < 0) {
      goto error;
   }

   return 0;
error:
   rsEncoderDestroy(encoder);
   return ret;
}
