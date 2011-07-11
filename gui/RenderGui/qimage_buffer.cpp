/*
 * qimage_buffer.cpp
 *
 *  Created on: Jul 10, 2011
 *      Author: Alexander Kondratskiy
 */

#include "qimage_buffer.h"

void QImageBuffer::setPixel(int x, int y, RGBColor const& color) {
	image_.setPixel(x, y, ColorOps::toUint(color));
}


