TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    course.cpp \
    course_list.cpp \
    student.cpp \
    studata_list.cpp \
    func.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    course.h \
    course_list.h \
    student.h \
    studata_list.h

