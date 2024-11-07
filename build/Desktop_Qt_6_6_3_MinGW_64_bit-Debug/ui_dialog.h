/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *label_4;
    QDateEdit *dateEdit_2;
    QLabel *label_5;
    QLabel *label_3;
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit_3;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label;
    QDateEdit *dateEdit;
    QLineEdit *lineEdit_2;
    QWidget *page_2;
    QLabel *label_6;
    QLineEdit *lineEdit_4;
    QDialogButtonBox *buttonBox_2;
    QWidget *page_3;
    QTableView *tableView;
    QPushButton *pushButton;
    QWidget *page_4;
    QLineEdit *lineEdit_5;
    QLabel *label_7;
    QDialogButtonBox *buttonBox_3;
    QLabel *label_8;
    QDateEdit *dateEdit_3;
    QLabel *label_9;
    QLineEdit *lineEdit_6;
    QLabel *label_10;
    QLineEdit *lineEdit_7;
    QLabel *label_11;
    QDateEdit *dateEdit_4;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(477, 306);
        stackedWidget = new QStackedWidget(Dialog);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(10, 20, 461, 281));
        page = new QWidget();
        page->setObjectName("page");
        label_4 = new QLabel(page);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 130, 111, 16));
        dateEdit_2 = new QDateEdit(page);
        dateEdit_2->setObjectName("dateEdit_2");
        dateEdit_2->setGeometry(QRect(160, 100, 110, 22));
        label_5 = new QLabel(page);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(40, 160, 47, 14));
        label_3 = new QLabel(page);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 100, 101, 16));
        buttonBox = new QDialogButtonBox(page);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(20, 200, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit_3 = new QLineEdit(page);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(160, 160, 113, 20));
        label_2 = new QLabel(page);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 70, 101, 16));
        lineEdit = new QLineEdit(page);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(160, 40, 113, 20));
        label = new QLabel(page);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 40, 101, 16));
        dateEdit = new QDateEdit(page);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(160, 70, 110, 22));
        lineEdit_2 = new QLineEdit(page);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(160, 130, 113, 20));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        label_6 = new QLabel(page_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(90, 70, 201, 20));
        lineEdit_4 = new QLineEdit(page_2);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(110, 110, 113, 20));
        buttonBox_2 = new QDialogButtonBox(page_2);
        buttonBox_2->setObjectName("buttonBox_2");
        buttonBox_2->setGeometry(QRect(90, 180, 161, 23));
        buttonBox_2->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        tableView = new QTableView(page_3);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(0, 20, 461, 221));
        pushButton = new QPushButton(page_3);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(114, 250, 171, 23));
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        lineEdit_5 = new QLineEdit(page_4);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(210, 30, 113, 20));
        label_7 = new QLabel(page_4);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(90, 120, 111, 16));
        buttonBox_3 = new QDialogButtonBox(page_4);
        buttonBox_3->setObjectName("buttonBox_3");
        buttonBox_3->setGeometry(QRect(70, 190, 341, 32));
        buttonBox_3->setOrientation(Qt::Horizontal);
        buttonBox_3->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label_8 = new QLabel(page_4);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(90, 60, 101, 16));
        dateEdit_3 = new QDateEdit(page_4);
        dateEdit_3->setObjectName("dateEdit_3");
        dateEdit_3->setGeometry(QRect(210, 60, 110, 22));
        label_9 = new QLabel(page_4);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(90, 150, 47, 14));
        lineEdit_6 = new QLineEdit(page_4);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(210, 120, 113, 20));
        label_10 = new QLabel(page_4);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(90, 90, 101, 16));
        lineEdit_7 = new QLineEdit(page_4);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setGeometry(QRect(210, 150, 113, 20));
        label_11 = new QLabel(page_4);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(90, 30, 101, 16));
        dateEdit_4 = new QDateEdit(page_4);
        dateEdit_4->setObjectName("dateEdit_4");
        dateEdit_4->setGeometry(QRect(210, 90, 110, 22));
        stackedWidget->addWidget(page_4);

        retranslateUi(Dialog);

        stackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        label_4->setText(QCoreApplication::translate("Dialog", "STATUT_COMMANDE", nullptr));
        label_5->setText(QCoreApplication::translate("Dialog", "PRIX", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog", "DATE_LIVRAISON", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "DATE_COMMANDE", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "ID_COMMANDE ", nullptr));
        label_6->setText(QCoreApplication::translate("Dialog", "Donnez l'id a supprimer", nullptr));
        pushButton->setText(QCoreApplication::translate("Dialog", "close", nullptr));
        label_7->setText(QCoreApplication::translate("Dialog", "STATUT_COMMANDE", nullptr));
        label_8->setText(QCoreApplication::translate("Dialog", "DATE_COMMANDE", nullptr));
        label_9->setText(QCoreApplication::translate("Dialog", "PRIX", nullptr));
        label_10->setText(QCoreApplication::translate("Dialog", "DATE_LIVRAISON", nullptr));
        label_11->setText(QCoreApplication::translate("Dialog", "ID_COMMANDE ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
