#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_10_clicked()
{
    Dialog dialog(this); // Create a dialog with MainWindow as the parent
    dialog.switchToPage1();
    dialog.exec();

}

void MainWindow::on_pushButton_7_clicked()
{
    Dialog dialog(this); // Create a dialog with MainWindow as the parent
    dialog.switchToPage2();
    dialog.exec();
}

void MainWindow::on_pushButton_9_clicked()
{
    Dialog dialog(this); // Create a dialog with MainWindow as the parent
    dialog.switchToPage3();
    dialog.affichage();
    dialog.exec();
}

void MainWindow::on_pushButton_8_clicked()
{
    Dialog dialog(this); // Create a dialog with MainWindow as the parent
    dialog.switchToPage4();
    dialog.affichage();
    dialog.exec();
}
