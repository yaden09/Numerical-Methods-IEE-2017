#-------------------------------------------------
#
# Project created by QtCreator 2017-10-12T13:22:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Sistema
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        sistema.cpp \
        elimguss.cpp \
        gaussseidel.cpp \
        euler.cpp \
        inte.cpp \
        newton_rap.cpp \
        punto_fijo.cpp \
        regresionlm.cpp \
    lagrange.cpp \
    lineal.cpp \
    deriv.cpp \
    runge.cpp \
    calculadora.cpp

HEADERS += \
        sistema.h \
        elimguss.h \
        gaussseidel.h \
        euler.h \
        inte.h \
        newton_rap.h \
        punto_fijo.h \
        regresionlm.h \
    lagrange.h \
    lineal.h \
    deriv.h \
    runge.h \
    calculadora.h

FORMS += \
        sistema.ui \
        elimguss.ui \
        gaussseidel.ui \
        euler.ui \
        inte.ui \
        newton_rap.ui \
        punto_fijo.ui \
        regresionlm.ui \
    lagrange.ui \
    lineal.ui \
    deriv.ui \
    runge.ui \
    calculadora.ui
