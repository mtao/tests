/*
 * array_buffer.h
 *
 *  Created on: Jul 10, 2011
 *      Author: Alexander Kondratskiy
 */

#ifndef ARRAY_BUFFER_H_
#define ARRAY_BUFFER_H_

#include "buffer.h"
#include "Eigen/Core"

typedef Eigen::Array<RGBColor, Eigen::Dynamic, Eigen::Dynamic> RGBStorage;


class ArrayBuffer : public Buffer {
public:
	ArrayBuffer(int width, int height) : array_(height, width) { }
	~ArrayBuffer() { }

	int width() const { return array_.cols(); }
	int height() const { return array_.rows(); }
	void setPixel(int x, int y, RGBColor const& color) {
		array_(y, x) = color;
	}

private:
	RGBStorage array_;

};


#endif /* ARRAY_BUFFER_H_ */
