TEMPLATE = app
TARGET = RenderGui
INCLUDEPATH = ../simple_raytracer \
    ../objects \
    $(EIGEN_PATH)
QT += core \
    gui
    
include(../utils/inc.pro)

LIBS += ../simple_raytracer/libsimple_raytracer.$$STATIC_LIB_EXTENSION

HEADERS += src/ImageViewer.h \
	src/qimage_buffer.h
SOURCES += main.cpp \
	src/ImageViewer.cpp \
	src/qimage_buffer.cpp
FORMS += 
RESOURCES += 
