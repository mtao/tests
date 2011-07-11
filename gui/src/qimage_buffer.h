/*
 * qimage_buffer.h
 *
 *  Created on: Jul 10, 2011
 *      Author: Alexander Kondratskiy
 */

#ifndef QIMAGE_BUFFER_H_
#define QIMAGE_BUFFER_H_

#include "buffer.h"
#include <QImage>

class QImageBuffer : public Buffer {
public:
	QImageBuffer(int width, int height) : image_(width, height, QImage::Format_RGB32) { }
	~QImageBuffer() { }

	int width() const { return image_.width(); }
	int height() const { return image_.height(); }
	void setPixel(int x, int y, RGBColor const& color);
	QImage const& qimage() const { return image_; }

private:
	QImage image_;

};


#endif /* QIMAGE_BUFFER_H_ */
