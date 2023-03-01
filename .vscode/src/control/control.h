/*
 * Copyright (C) 2020-2021  Joshua Minter
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

#ifndef RS_CONTROL_H
#define RS_CONTROL_H
#include <libavutil/avutil.h>

typedef struct RSControl {
   void *extra;
   void (*destroy)(struct RSControl *control);
   int (*wantsSave)(struct RSControl *control);
} RSControl;

static av_always_inline int rsControlWantsSave(RSControl *control) {
   return control->wantsSave(control);
}

void rsControlDestroy(RSControl *control);

int rsDebugControlCreate(RSControl *control);
int rsX11ControlCreate(RSControl *control);
int rsCommandControlCreate(RSControl *control);
int rsDefaultControlCreate(RSControl *control);

#define RS_COMMAND_CONTROL_PATH "/tmp/replay-sorcery/control.sock"

#endif
