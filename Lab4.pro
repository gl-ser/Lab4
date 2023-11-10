#----------------------------------------------------------------------------#
#                       *** ЛАБОРАТОРНАЯ РАБОТА № 4 ***                      #
#                                                                            #
# Проект для Qt 5                                                            #
#                                                                            #
# Автор ГЛУЩЕНКО Сергей Юрьевич                                              #
#                                                                            #
#                                                   Москва, НИИ ТП, 2023 год #
#----------------------------------------------------------------------------#

QT += core widgets

TARGET = Lab4
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

DESTDIR = $$PWD/APP  #Размещение исполняемого файла

SOURCES += \
        main.cpp \
        MainWindow.cpp \
    TelemetricFile.cpp

HEADERS += \
        MainWindow.h \
    TelemetricFile.h

FORMS += \
        MainWindow.ui

RESOURCES += \
    Icons.qrc
