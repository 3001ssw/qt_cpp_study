#ifndef MYLIBRARY_GLOBAL_H
#define MYLIBRARY_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(MYLIBRARY_LIBRARY)
#  define MYLIBRARY_EXPORT Q_DECL_EXPORT
#else
#  define MYLIBRARY_EXPORT Q_DECL_IMPORT
#endif

#endif // MYLIBRARY_GLOBAL_H
