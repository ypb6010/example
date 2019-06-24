#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(ASSISTCORE_LIB)
#  define ASSISTCORE_EXPORT Q_DECL_EXPORT
# else
#  define ASSISTCORE_EXPORT Q_DECL_IMPORT
# endif
#else
# define ASSISTCORE_EXPORT
#endif
