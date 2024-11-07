#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void switchToPage2();
    void switchToPage1();
    void switchToPage3();
    void switchToPage4();
    void affichage();
    Ui::Dialog *ui;
private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_2_accepted();

    void on_pushButton_clicked();

    void on_buttonBox_rejected();

    void on_buttonBox_2_rejected();

    void on_buttonBox_3_accepted();

    void on_buttonBox_3_rejected();

private:

};

#endif // DIALOG_H
