/*
 * ImageViewer.cpp
 *
 *  Created on: Jul 10, 2011
 *      Author: g9sash
 */

#include "ImageViewer.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QImage>
#include <QPixmap>

namespace RenderGui {

	Viewer::Viewer(QWidget* parent) : QWidget(parent) {
		initGui();
	}

	void Viewer::showImage(QImage const& image) {
		label_->setPixmap(QPixmap::fromImage(image));
	}

	void Viewer::initGui() {
		QVBoxLayout* layout = new QVBoxLayout();

		label_ = new QLabel();
		layout->addWidget(label_);

		this->setLayout(layout);
	}

}  // namespace RenderGui

