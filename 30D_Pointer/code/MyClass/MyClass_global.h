#ifndef MYCLASS_GLOBAL_H
#define MYCLASS_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(MYCLASS_LIBRARY)
#define MYCLASS_EXPORT Q_DECL_EXPORT
#else
#define MYCLASS_EXPORT Q_DECL_IMPORT
#endif

#endif // MYCLASS_GLOBAL_H
