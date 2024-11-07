#ifndef COMMANDE_H
#define COMMANDE_H
#include <QString>
#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlQuery>

class Commande
{
    QString ID_COMMANDE;
    QString DATE_COMMANDE;
    QString DATE_LIVRAISON;
    QString STATUT_COMMANDE;
    QString PRIX;
public:
    Commande();
    Commande(QString ID_COMMANDE,QString DATE_COMMANDE,QString DATE_LIVRAISON,QString STATUT_COMMANDE,QString PRIX);
    Commande(QString DATE_COMMANDE,QString DATE_LIVRAISON,QString STATUT_COMMANDE,QString PRIX);
    void Ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(QString id);
    bool modifier();
};

#endif // COMMANDE_H
