TARGET = sudoku
TEMPLATE = app
SOURCES = main.cpp \
    viewlocation.cpp

QT = core gui
QT += webenginewidgets
QT += webengine webenginewidgets

RESOURCES += \
    app.qrc \
    app.qrc

HEADERS += \
    viewlocation.h \
