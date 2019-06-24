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
#include <QtWidgets/QApplication>
#include <QDesktopWidget>
#include <QQueue>
#include <QFileDialog>
#include <QMessageBox>
#include <QTimer>
#include <QProcess>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QListView>
#include <QPainter>
#include <QStylePainter>
#include <QStylePainter>
#include <QDate>
#include <QShowEvent>
///第三方库头文件包含
#include "global_define.h"
#include "Core.h"
#include "NetWork.h"
#include "AppManager.h"
#include "../Core/WindowInterface.h"
#include "../ExpertsCore/ExpertsCore.h"
#include "../ExpertsCore/ExpertsManager.h"
#include "../ExpertsCore/DataManager.h"
#include "../ExpertsCore/ExpertsWindowInterface.h"
#include "../MedicalWidget/ButtonDelegate.h"
#include "../MedicalWidget/TableHeaderView.h"
#include "../MedicalWidget/TableModel.h"
#include "../MedicalWidget/SnMaskWidget.h"
#include "../MedicalWidget/ButtonDialog.h"
#include "../MedicalWidget/HistoryDialog.h"
#include "../MedicalWidget/AppendHistoryDialog.h"

///本工程头文件包含

#pragma comment(lib,"libcrypto.lib")
#pragma comment(lib,"libssl.lib")
