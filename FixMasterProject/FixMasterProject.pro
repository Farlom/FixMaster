TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    app.cpp \
    fixmaster.cpp \
    master.cpp \
    salary.cpp \
    client.cpp \
    tools.cpp \
    fixorder.cpp \
    shiporder.cpp \
    annual.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    fixmaster.h \
    master.h \
    salary.h \
    client.h \
    tools.h \
    fixorder.h \
    shiporder.h \
    annual.h

