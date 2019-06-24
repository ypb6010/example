#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(EXPERTSCORE_LIB)
#  define EXPERTSCORE_EXPORT Q_DECL_EXPORT
# else
#  define EXPERTSCORE_EXPORT Q_DECL_IMPORT
# endif
#else
# define EXPERTSCORE_EXPORT
#endif
