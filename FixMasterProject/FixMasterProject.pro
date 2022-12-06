TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    app.cpp \
    fixmaster.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    fixmaster.h

