/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPlainTextEdit *plainTextEdit;
    QPlainTextEdit *plainTextEdit_2;
    QPlainTextEdit *plainTextEdit_3;
    QPlainTextEdit *plainTextEdit_4;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPlainTextEdit *plainTextEdit_5;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(599, 733);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 50, 450, 450));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(100, 600, 100, 40));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(220, 600, 100, 40));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(340, 600, 100, 40));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(460, 600, 100, 40));
        plainTextEdit = new QPlainTextEdit(centralWidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(130, 520, 70, 40));
        plainTextEdit_2 = new QPlainTextEdit(centralWidget);
        plainTextEdit_2->setObjectName(QStringLiteral("plainTextEdit_2"));
        plainTextEdit_2->setGeometry(QRect(250, 520, 70, 40));
        plainTextEdit_3 = new QPlainTextEdit(centralWidget);
        plainTextEdit_3->setObjectName(QStringLiteral("plainTextEdit_3"));
        plainTextEdit_3->setGeometry(QRect(370, 520, 70, 40));
        plainTextEdit_4 = new QPlainTextEdit(centralWidget);
        plainTextEdit_4->setObjectName(QStringLiteral("plainTextEdit_4"));
        plainTextEdit_4->setGeometry(QRect(490, 520, 70, 40));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(100, 520, 25, 40));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(220, 520, 25, 40));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(340, 520, 25, 40));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(460, 520, 25, 40));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(300, 565, 25, 30));
        plainTextEdit_5 = new QPlainTextEdit(centralWidget);
        plainTextEdit_5->setObjectName(QStringLiteral("plainTextEdit_5"));
        plainTextEdit_5->setGeometry(QRect(330, 565, 70, 30));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 599, 28));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Solid Line", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Dotted Line", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "Dashed Line", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "Thick Line", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "X1", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Y1", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "X2", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Y2", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "W", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
