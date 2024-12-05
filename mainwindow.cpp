#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include <QPdfWriter>
#include <QPainter>
#include <QDate>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDesktopServices>
#include <QUrl>
#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int ret=A.connect_arduino(); // lancer la connexion à arduino
        switch(ret){
        case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
            break;
        case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
           break;
        case(-1):qDebug() << "arduino is not available";
        }
         QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
         //le slot update_label suite à la reception du signal readyRead (reception des données).

         // Configure un QTimer pour lire les données périodiquement
             QTimer *timer = new QTimer(this);
             connect(timer, &QTimer::timeout, this, &MainWindow::update_label);
             timer->start(1000); // Lecture toutes les 1 seconde

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


void MainWindow::on_pushButton_13_clicked()
{
    Dialog dialog(this); // Create a dialog with MainWindow as the parent
    dialog.switchToPage5();
    dialog.afficherStatistiques();
    dialog.exec();
}


void MainWindow::on_pushButton_11_clicked()
{
    QPdfWriter pdf("C:/Users/Lenovo/Desktop/Commande/commande.pdf");

           QPainter painter(&pdf);
           int i = 4100;
          const QImage image("C:/Users/Lenovo/Desktop/Commande/logo_sy.png");
                       const QPoint imageCoordinates(155,0);
                       int width1 = 2000;
                       int height1 = 2000;
                       QImage img=image.scaled(width1,height1);
                       painter.drawImage(imageCoordinates, img );

                  QColor dateColor(0x4a5bcf);
                  painter.setPen(dateColor);

                  painter.setFont(QFont("Montserrat SemiBold", 11));
                  QDate cd = QDate::currentDate();
                  painter.drawText(7700,250,cd.toString("Ariana, El Ghazela"));
                  painter.drawText(8100,500,cd.toString("dd/MM/yyyy"));

                  QColor titleColor(0x341763);
                  painter.setPen(titleColor);
                  painter.setFont(QFont("Montserrat SemiBold", 25));

                  painter.drawText(3000,2700,"Liste des Commande");

                  painter.setPen(Qt::black);
                  painter.setFont(QFont("Time New Roman", 15));
                  //painter.drawRect(100,100,9400,2500);
                  painter.drawRect(100,3300,9400,500);

                  painter.setFont(QFont("Montserrat SemiBold", 10));
                              painter.drawText(300,3600,"id_commande");
                              painter.drawText(2000,3600,"date_commande");
                              painter.drawText(4000,3600,"date_livraison");
                              painter.drawText(6000,3600,"statut");
                              painter.drawText(8000,3600,"prix");

                  painter.setFont(QFont("Montserrat", 10));
                  painter.drawRect(100,3300,9400,9000);

                  QSqlQuery query;
                  query.prepare("select * from commande");
                  query.exec();
                  int y=4300;
                  while (query.next())
                  {
                      painter.drawLine(100,y,9490,y);
                      y+=500;
                      painter.drawText(300,i,query.value(0).toString());
                          painter.drawText(2000,i,query.value(1).toString());
                          painter.drawText(4000,i,query.value(2).toString());
                          painter.drawText(6000,i,query.value(3).toString());
                          painter.drawText(8000,i,query.value(4).toString());

                     i = i + 500;
                  }

                  int reponse = QMessageBox::question(this, "Génerer PDF", "PDF Enregistré.\nVous voulez l'affichez ?", QMessageBox::Yes |  QMessageBox::No);
                  if (reponse == QMessageBox::Yes)
                  {
                      QDesktopServices::openUrl( QUrl::fromLocalFile("C:/Users/Lenovo/Desktop/Commande/commande.pdf"));
                      painter.end();
                  }
                  else
                  {
                      painter.end();
                  }
}

void MainWindow::on_pushButton_14_clicked()
{
    Dialog dialog(this); // Create a dialog with MainWindow as the parent
    dialog.switchToPage6();
    dialog.updateCalendarColors();
    dialog.exec();
}

/*void MainWindow::update_label(){

QByteArray data1 = A.read_from_arduino();
data= data+data1;
qDebug()<< data;
// Find the index of the second line
    int start = data.indexOf("\r\n") + 2;  // Move past the first \r\n
    int end = data.indexOf("\r\n", start);

    QByteArray value = data.mid(start, end - start).trimmed();
    qDebug() << "Extracted value:" << value;

QMessageBox::information(this, "Temperateur trés élevée\n Temperateur : " , "temperateur est :" +value);
}


void MainWindow::on_pushButton_12_clicked()
{
    A.write_to_arduino("1");
    data="";
    return;
}*/




void MainWindow::update_label()
{
    static QByteArray data;       // Accumulation des données reçues
    static double lastTemperature = -9999.0;  // Pour suivre les changements de température

    // Envoyer la commande pour lire la température
    A.write_to_arduino("1");

    // Lire les nouvelles données de l'Arduino
    QByteArray data1 = A.read_from_arduino();
    data += data1;  // Ajouter les nouvelles données reçues
    qDebug() << "Données reçues :" << data;

    // Cherche une valeur complète (délimitée par \r\n)
    int start = data.indexOf("\r\n") + 2;
    int end = data.indexOf("\r\n", start);

    if (start > 1 && end > start) {
        QByteArray value = data.mid(start, end - start).trimmed();
        qDebug() << "Valeur extraite :" << value;

        data.remove(0, end + 2);  // Supprime les données déjà traitées

        // Convertir la valeur en température
        bool ok;
        double temperature = value.toDouble(&ok);

        if (ok) {
            qDebug() << "Température actuelle :" << temperature << "°C";



            // Vérifie si la température a changé par rapport à la précédente
            if (temperature != lastTemperature) {
                lastTemperature = temperature;

                // Déclencher une alerte si la température dépasse un seuil élevé
                if (temperature > 30.0) {  // Exemple de seuil d'alerte : 30°C
                    QMessageBox::warning(this, "Alerte Température",
                                         "Température très élevée : " + QString::number(temperature) + "°C");
                }
            }
        } else {
            qDebug() << "Erreur : impossible de convertir la valeur en température.";
        }
    }
}

