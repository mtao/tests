TEMPLATE = app
TARGET = RenderGui
INCLUDEPATH = ../simple_raytracer \
    ../objects \
    $(EIGEN_PATH)
LIBS += ../simple_raytracer/libsimple_raytracer.so
QT += core \
    gui
    
unix {
	# treat warnings as errors
	QMAKE_CXXFLAGS += -Werror
	# for debugging an profiling
	QMAKE_CXXFLAGS_DEBUG += -pg
	QMAKE_LFLAGS += -pg
	
	# optimizations
	QMAKE_CXXFLAGS_RELEASE += -O3
}    
    
HEADERS += src/ImageViewer.h \
	src/qimage_buffer.h
SOURCES += main.cpp \
	src/ImageViewer.cpp \
	src/qimage_buffer.cpp
FORMS += 
RESOURCES += 
