#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(MEDICALWIDGET_LIB)
#  define MEDICALWIDGET_EXPORT Q_DECL_EXPORT
# else
#  define MEDICALWIDGET_EXPORT Q_DECL_IMPORT
# endif
#else
# define MEDICALWIDGET_EXPORT
#endif
