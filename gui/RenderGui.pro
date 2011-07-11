TEMPLATE = app
TARGET = RenderGui
INCLUDEPATH = ../simple_raytracer \
    ../objects \
    $(EIGEN_PATH)
    
LIBS += ../simple_raytracer/libsimple_raytracer.so
QT += core \
    gui
HEADERS += RenderGui/qimage_buffer.h \
    RenderGui/ImageViewer.h
SOURCES += RenderGui/qimage_buffer.cpp \
    RenderGui/ImageViewer.cpp \
    main.cpp
FORMS += 
RESOURCES += 
