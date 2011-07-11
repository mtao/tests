TEMPLATE = app
TARGET = RenderGui
INCLUDEPATH = ../simple_raytracer \
    ../objects \
    $(EIGEN_PATH)
LIBS += ../simple_raytracer/libsimple_raytracer.so
QT += core \
    gui
HEADERS += src/ImageViewer.h \
	src/qimage_buffer.h
SOURCES += main.cpp \
	src/ImageViewer.cpp \
	src/qimage_buffer.cpp
FORMS += 
RESOURCES += 
