#include "dialog.h"
#include "ui_dialog.h"
#include "commande.h"
#include <QMessageBox>
#include <QtCharts/QChart>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChartView>
#include <QtCharts>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QVBoxLayout>
#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
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
void Dialog::afficherStatistiques() {
    QSqlQuery query;
    int livrees = 0, nonLivrees = 0, en_cours = 0;

    // Requête pour les commandes livrées
    if (query.exec("SELECT COUNT(*) FROM commande WHERE statut_commande = 'Livrée'")) {
        if (query.next()) livrees = query.value(0).toInt();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la récupération des données pour les commandes livrées.");
        return;
    }

    // Requête pour les commandes non livrées
    if (query.exec("SELECT COUNT(*) FROM commande WHERE statut_commande = 'Non Livrée'")) {
        if (query.next()) nonLivrees = query.value(0).toInt();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la récupération des données pour les commandes non livrées.");
        return;
    }

    if (query.exec("SELECT COUNT(*) FROM commande WHERE statut_commande = 'en cours'")) {
        if (query.next()) en_cours = query.value(0).toInt();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la récupération des données pour les commandes non livrées.");
        return;
    }

    // Création du graphique circulaire
    QPieSeries *series = new QPieSeries();
    series->append("Livrée", livrees);
    series->append("Non Livrée", nonLivrees);
    series->append("en cours", en_cours);

    // Ajouter des labels avec pourcentages
    for (auto slice : series->slices()) {
        slice->setLabel(QString("%1 (%2%)")
                        .arg(slice->label())
                        .arg(slice->percentage() * 100, 0, 'f', 1));
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques des commandes : Livrées vs Non Livrées vs en cours");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // Vue pour afficher le graphique
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Ajouter le graphique au widget statistiques (statistiquesWidget dans le fichier .ui)
    QVBoxLayout *layout = qobject_cast<QVBoxLayout *>(ui->tableView_2->layout());
    if (!layout) {
        layout = new QVBoxLayout();
        ui->tableView_2->setLayout(layout);
    }

    // Nettoyer les anciens widgets
    QLayoutItem *child;
    while ((child = layout->takeAt(0)) != nullptr) {
        delete child->widget();
        delete child;
    }

    // Ajouter la vue du graphique au layout
    layout->addWidget(chartView);
}



void Dialog::sendsms(QString num, QString nom)
{
    QNetworkAccessManager* manager = new QNetworkAccessManager();

        // Twilio API URL
        QString accountSID = "AC801f672d0abf85107f4066a656281549";
        QString authToken = "4b499f38a221aa5c05ba25155cce2130";
        QString fromNumber = "+15752187869"; // Your Twilio number
        QString toNumber = "+216"+num; // Recipient number
        QString message = "salut "+nom+", votre commande est en cours de traitement";

        QString url = QString("https://api.twilio.com/2010-04-01/Accounts/%1/Messages.json").arg(accountSID);
        QNetworkRequest request((QUrl(url)));

        // Authentication
        QByteArray credentials = QString("%1:%2").arg(accountSID, authToken).toUtf8().toBase64();
        request.setRawHeader("Authorization", "Basic " + credentials);

        // Data to send
        QUrlQuery params;
        params.addQueryItem("From", fromNumber);
        params.addQueryItem("To", toNumber);
        params.addQueryItem("Body", message);

        // Send the request
        QNetworkReply* reply = manager->post(request, params.toString(QUrl::FullyEncoded).toUtf8());
        QObject::connect(reply, &QNetworkReply::finished, [reply]() {
            if (reply->error() == QNetworkReply::NoError) {
                qDebug() << "SMS sent successfully!";
            } else {
                qDebug() << "Failed to send SMS:" << reply->errorString();
            }
            reply->deleteLater();
        });
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

void Dialog::on_pushButton_2_clicked()
{
    reject();
}

void Dialog::on_lineEdit_8_textChanged(const QString &arg1)
{
    Commande c;
    ui->tableView->setModel(c.rechercher(arg1));
}

void Dialog::on_pushButton_3_clicked()
{
    Commande c;
    QString type = ui->comboBox->currentText();
    if(type=="ASC")
         ui->tableView->setModel(c.tri1());
    else
        ui->tableView->setModel(c.tri2());
}


void Dialog::on_calendarWidget_activated(const QDate &date)
{
    QSqlQuery query;
       query.prepare("SELECT id_commande FROM commande WHERE date_livraison = :date");
       query.bindValue(":date", date.toString("dd-MM-YYYY")); // Format date as a string for SQL

       if (!query.exec()) {
           QMessageBox::critical(this, "Query Error", query.lastError().text());
           return;
       }

       // Assuming you have a QListWidget in your UI named listWidget
       ui->listWidget->clear(); // Clear the list to show fresh results

       while (query.next()) {
           QString id_commande = query.value(0).toString(); // Get the matricule from the first column
           ui->listWidget->addItem(id_commande);           // Add the matricule to the list widget
       }

       if (ui->listWidget->count() == 0) {
           QMessageBox::information(this, "No Results", "No id_commande found for the selected date.");
       }
}
void Dialog::updateCalendarColors()
{
    QSqlQuery query;
       query.prepare("SELECT DATE_LIVRAISON, statut_commande FROM commande");

       if (!query.exec()) {
           QMessageBox::critical(this, "Query Error", query.lastError().text());
           return;
       }



       // Loop through the query results and set the background color based on status
       while (query.next()) {
            QDate dateString = query.value(0).toDate();
           QString status = query.value(1).toString();
           //QDate dateLivraison = QDate::fromString(dateString, "dd-MM-yyyy");

                  // Debug: Print the values for checking
                  qDebug() << "Date:" << dateString << "Status:" << status;
           if (dateString.isValid()) {
               QTextCharFormat format;

               // Set the background color based on the status
               if (status == "en cours") {
                   format.setBackground(Qt::yellow);  // Yellow for 'en cours'
               } else if (status == "Livree") {
                   format.setBackground(Qt::green);   // Green for 'Livrée'
               } else if (status == "Non Livree") {
                   format.setBackground(Qt::red);     // Red for 'Non Livrée'
               }

               // Apply the format to the specific date on the calendar
              ui->calendarWidget->setDateTextFormat(dateString, format);
           }
           else
               qDebug() << "fail!";
       }
}

void Dialog::on_calendarWidget_clicked(const QDate &date)
{
    QSqlQuery query;
       query.prepare("SELECT id_commande FROM commande WHERE date_livraison = :date");
       query.bindValue(":date", date); // Format date as a string for SQL

       if (!query.exec()) {
           QMessageBox::critical(this, "Query Error", query.lastError().text());
           return;
       }

       // Assuming you have a QListWidget in your UI named listWidget
       ui->listWidget->clear(); // Clear the list to show fresh results

       while (query.next()) {
           QString id_commande = query.value(0).toString(); // Get the matricule from the first column
           ui->listWidget->addItem(id_commande);           // Add the matricule to the list widget
       }

       if (ui->listWidget->count() == 0) {
           QMessageBox::information(this, "No Results", "No icommande found for the selected date.");
       }
}

