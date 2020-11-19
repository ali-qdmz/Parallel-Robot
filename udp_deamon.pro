QT += core network
QT -= gui

CONFIG += c++11

TARGET = udp_deamon
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    qdeamonapp.cpp

HEADERS += \
    qdeamonapp.h
