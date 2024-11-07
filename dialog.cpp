#include "dialog.h"
#include "ui_dialog.h"
#include "commande.h"
#include <QMessageBox>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}
void Dialog::switchToPage1()
{
    ui->stackedWidget->setCurrentIndex(0);
}
void Dialog::switchToPage2()
{
    ui->stackedWidget->setCurrentIndex(1);
}
void Dialog::switchToPage3()
{
    ui->stackedWidget->setCurrentIndex(2);
}
void Dialog::switchToPage4()
{
    ui->stackedWidget->setCurrentIndex(3);
}
//ajout
void Dialog::on_buttonBox_accepted()
{
    QString ID_COMMANDE = ui->lineEdit->text();
    QString DATE_COMMANDE = ui->dateEdit->date().toString();
    QString DATE_LIVRAISON = ui->dateEdit_2->date().toString();
    QString STATUT_COMMANDE = ui->lineEdit_2->text();
    QString PRIX = ui->lineEdit_3->text();
    QDate DATE_COMMANDEE = ui->dateEdit->date();
    QDate DATE_LIVRAISONN = ui->dateEdit_2->date();
    QDate dateActuelle = QDate::currentDate();
    Commande C(ID_COMMANDE,DATE_COMMANDE,DATE_LIVRAISON,STATUT_COMMANDE,PRIX);
    if (ID_COMMANDE=="" || DATE_COMMANDE=="" || DATE_LIVRAISON=="" || STATUT_COMMANDE=="" || PRIX=="" ) {

        QMessageBox::warning(this, "Champs manquants", "Veuillez remplir tous les champs");
    } else {
        if(PRIX.toInt()<=0)
        {
            QMessageBox::warning(this, "Erreur", "Veuillez introduire un Prix >= 0 ");
        }
        else if(DATE_COMMANDEE < dateActuelle || DATE_LIVRAISONN < dateActuelle) {
                   QMessageBox::warning(this, "Erreur", "Veuillez saisir une date valide");
        }
        else{

    C.Ajouter();
    accept();
        }
    }
}
//supprision
void Dialog::on_buttonBox_2_accepted()
{
    QString ID = ui->lineEdit_4->text();
    Commande C;
    C.supprimer(ID);
    accept();
}

//afichage
void Dialog::affichage()
{
    Commande C;
    ui->tableView->setModel(C.afficher());
}

//modifier
void Dialog::on_buttonBox_3_accepted()
{
    QString ID_COMMANDE = ui->lineEdit_5->text();
    QString DATE_COMMANDE = ui->dateEdit_3->date().toString();
    QString DATE_LIVRAISON = ui->dateEdit_4->date().toString();
    QString STATUT_COMMANDE = ui->lineEdit_6->text();
    QString PRIX = ui->lineEdit_7->text();
    QDate DATE_COMMANDEE = ui->dateEdit_3->date();
    QDate DATE_LIVRAISONN = ui->dateEdit_4->date();
    QDate dateActuelle = QDate::currentDate();
    Commande C(ID_COMMANDE,DATE_COMMANDE,DATE_LIVRAISON,STATUT_COMMANDE,PRIX);
    if (ID_COMMANDE=="" || DATE_COMMANDE=="" || DATE_LIVRAISON=="" || STATUT_COMMANDE=="" || PRIX=="" ) {

        QMessageBox::warning(this, "Champs manquants", "Veuillez remplir tous les champs");
    } else {
        if(PRIX.toInt()<=0)
        {
            QMessageBox::warning(this, "Erreur", "Veuillez introduire un Prix >= 0 ");
        }
        else if(DATE_COMMANDEE < dateActuelle || DATE_LIVRAISONN < dateActuelle) {
                   QMessageBox::warning(this, "Erreur", "Veuillez saisir une date valide");
        }
        else{

    C.modifier();
    accept();
        }
    }
}
























//les buttons annuler
void Dialog::on_buttonBox_rejected()
{
    reject();
}

void Dialog::on_buttonBox_2_rejected()
{
    reject();
}
void Dialog::on_pushButton_clicked()
{
    accept();
}


void Dialog::on_buttonBox_3_rejected()
{
    reject();
}
