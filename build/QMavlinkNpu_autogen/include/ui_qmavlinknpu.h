/********************************************************************************
** Form generated from reading UI file 'qmavlinknpu.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QMAVLINKNPU_H
#define UI_QMAVLINKNPU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QMavlinkNpu
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *QMavlinkNpu)
    {
        if (QMavlinkNpu->objectName().isEmpty())
            QMavlinkNpu->setObjectName(QString::fromUtf8("QMavlinkNpu"));
        QMavlinkNpu->resize(800, 600);
        centralwidget = new QWidget(QMavlinkNpu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QMavlinkNpu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(QMavlinkNpu);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        QMavlinkNpu->setMenuBar(menubar);
        statusbar = new QStatusBar(QMavlinkNpu);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        QMavlinkNpu->setStatusBar(statusbar);

        retranslateUi(QMavlinkNpu);

        QMetaObject::connectSlotsByName(QMavlinkNpu);
    } // setupUi

    void retranslateUi(QMainWindow *QMavlinkNpu)
    {
        QMavlinkNpu->setWindowTitle(QCoreApplication::translate("QMavlinkNpu", "QMavlinkNpu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QMavlinkNpu: public Ui_QMavlinkNpu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QMAVLINKNPU_H
