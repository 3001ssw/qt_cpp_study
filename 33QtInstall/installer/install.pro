TEMPLATE = aux

INSTALLER = 01_Installer_Example

INPUT = $$PWD/config/config.xml $$PWD/packages

myexam.input = INPUT
myexam.output = $$INSTALLER
myexam.commands = C:/Qt/QtIFW-4.7.0/bin/binarycreator \
                       -c $$PWD/config/config.xml \
                       -p $$PWD/packages ${QMAKE_FILE_OUT}

myexam.CONFIG += target_predeps no_link combine

QMAKE_EXTRA_COMPILERS += myexam


