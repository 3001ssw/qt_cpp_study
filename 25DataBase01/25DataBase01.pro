QT = core
# qmake면 아래 추가
QT += sql

# cmake면 아래 추가
# find_package(Qt6 COMPONENTS Sql REQUIRED)
# target_link_lllibraries(mytarget PRIVATE Qt6::Sql)

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
