/*
 * ImageViewer.h
 *
 *  Created on: Jun 25, 2011
 *      Author: g9sash
 */

#ifndef IMAGEVIEWER_H_
#define IMAGEVIEWER_H_

#include <QWidget>
class QImage;
class QLabel;

namespace RenderGui {

	class Viewer : public QWidget {

		Q_OBJECT

	public:
		Viewer(QWidget* parent = 0);

	public slots:
		void showImage(QImage const& image);


	private:
		void initGui();

	private:
		QLabel* label_;

	};

}


#endif /* IMAGEVIEWER_H_ */
