/*****************************************************************************
 * Copyright (C) 2013 x265 project
 *
 * Authors: Steve Borho <steve@borho.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02111, USA.
 *
 * This program is also available under a commercial proprietary license.
 * For more information, contact us at licensing@multicorewareinc.com.
 *****************************************************************************/

#ifndef X265_YUV_H
#define X265_YUV_H

#include "output.h"
#include <fstream>
#include <stdio.h>

namespace x265 {
// private x265 namespace

class YUVOutput : public Output
{
protected:

    int width;

    int height;

    int depth;

    char *buf;

    std::ofstream ofs;

public:

    YUVOutput(const char *filename, int width, int height, int bitdepth);

    virtual ~YUVOutput();

    bool isFail() const                           { return ofs.fail(); }

    void release()                                { delete this; }

    bool writePicture(const x265_picture_t& pic);
};
}

#endif // ifndef X265_YUV_H
