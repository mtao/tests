TEMPLATE = app
TARGET = 
DEPENDPATH += .
INCLUDEPATH += . $(EIGEN_PATH)
message(Using Eigen found at $(EIGEN_PATH))

# Input
SOURCES += main.cpp
