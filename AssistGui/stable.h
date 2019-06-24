#pragma once
#define NO_QDEBUG
///C头文件包含区
extern "C" {
}
///C++头文件包含区
#include <string>
#include <sstream>
#include <queue>
#include <list>
#include <vector>

///依赖库头文件包含
#include <QDebug>
#include <QThread>
#include <QProcess>
#include <QtWidgets/QApplication>
#include <QQueue>
#include <QFileDialog>
#include <QMessageBox>
#include <QListView>
#include <QTimer>
#include <QProcess>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QPainter>
#include <QStylePainter>
#include <QMouseEvent>
#include <QDate>
#include <QDesktopWidget>

///第三方库头文件包含
#include "global_define.h"
#include "Core.h"
#include "AppManager.h"
#include "../AssistCore/AssistCore.h"
#include "../AssistCore/AssistManager.h"
#include "../AssistCore/AssistWindowInterface.h"
#include "../AssistCore/DataManager.h"
#include "NetWork.h"
#include "../MedicalWidget/ButtonDelegate.h"
#include "../MedicalWidget/ButtonBoxDelegate.h"
#include "../MedicalWidget/TableHeaderView.h"
#include "../MedicalWidget/TableModel.h"
#include "../MedicalWidget/ButtonDialog.h"
#include "../MedicalWidget/SnMaskWidget.h"
#include "../MedicalWidget/HistoryDialog.h"

///本工程头文件包含

#pragma comment(lib,"libcrypto.lib")
#pragma comment(lib,"libssl.lib")
