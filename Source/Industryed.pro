QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Behaviours/behaviour.cpp \
    Behaviours/furnacebehaviour.cpp \
    GUI/globalresourcedisplaywidget.cpp \
    GUI/hotbarwidget.cpp \
    GUI/itemdisplaywidget.cpp \
    Managers/resourcemanager.cpp \
    main.cpp \
    mainwindow.cpp \
    renderscene.cpp \
    renderview.cpp \
    renderwidget.cpp \
    texture.cpp \
    tile.cpp \
    worldgenerator.cpp \
    flowlayout.cpp

HEADERS += \
    Behaviours/behaviour.h \
    Behaviours/furnacebehaviour.h \
    GUI/globalresourcedisplaywidget.h \
    GUI/hotbarwidget.h \
    GUI/itemdisplaywidget.h \
    Managers/resourcemanager.h \
    Globals.h \
    item.h \
    mainwindow.h \
    renderscene.h \
    renderview.h \
    renderwidget.h \
    texture.h \
    tile.h \
    tiledatamodel.h \
    worldgenerator.h \
    flowlayout.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=
