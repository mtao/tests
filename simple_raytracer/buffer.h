/*
 * buffer.h
 *
 *  Created on: Jul 10, 2011
 *      Author: g9sash
 */

#ifndef BUFFER_H_
#define BUFFER_H_

#include "rgbcolor.h"

class Buffer {

public:
	virtual ~Buffer();

public:
	virtual int width() const = 0;
	virtual int height() const = 0;
	virtual void setPixel(int x, int y, RGBColor const& color) = 0;

};


#endif /* BUFFER_H_ */
