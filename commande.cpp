#include "commande.h"

Commande::Commande()
{

}
Commande::Commande(QString ID_COMMANDE,QString DATE_COMMANDE,QString DATE_LIVRAISON,QString STATUT_COMMANDE,QString PRIX)
{
    this->ID_COMMANDE=ID_COMMANDE;
    this->DATE_COMMANDE=DATE_COMMANDE;
    this->DATE_LIVRAISON=DATE_LIVRAISON;
    this->STATUT_COMMANDE=STATUT_COMMANDE;
    this->PRIX=PRIX;
}
Commande::Commande(QString DATE_COMMANDE,QString DATE_LIVRAISON,QString STATUT_COMMANDE,QString PRIX)
{
    this->DATE_COMMANDE=DATE_COMMANDE;
    this->DATE_LIVRAISON=DATE_LIVRAISON;
    this->STATUT_COMMANDE=STATUT_COMMANDE;
    this->PRIX=PRIX;
}
void Commande::Ajouter()
{
    QSqlQuery query;
    query.prepare("insert into COMMANDE (ID_COMMANDE,DATE_COMMANDE,DATE_LIVRAISON,STATUT_COMMANDE,PRIX) values (:ID_COMMANDE,:DATE_COMMANDE,:DATE_LIVRAISON,:STATUT_COMMANDE,:PRIX)");
    query.bindValue(":ID_COMMANDE", ID_COMMANDE);
    query.bindValue(":DATE_COMMANDE", DATE_COMMANDE);
    query.bindValue(":DATE_LIVRAISON", DATE_LIVRAISON);
    query.bindValue(":STATUT_COMMANDE", STATUT_COMMANDE);
    query.bindValue(":PRIX", PRIX);
    if(query.exec()){qDebug()<<"saved\n";}

       else{qDebug()<<"not saved!!!\n";}
}
QSqlQueryModel * Commande::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select * from COMMANDE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_COMMANDE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_COMMANDE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_LIVRAISON"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("STATUT_COMMANDE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRIX"));
    return model;
}
bool Commande::supprimer(QString id)
{
        QSqlQuery query;
        query.prepare("delete from COMMANDE where ID_COMMANDE = :id");
        query.bindValue(":id", id);
        return query.exec();
}
bool Commande::modifier()
{
    QSqlQuery query;
          query.prepare("update  COMMANDE set  DATE_COMMANDE=:DATE_COMMANDE, DATE_LIVRAISON=:DATE_LIVRAISON,STATUT_COMMANDE=:STATUT_COMMANDE,PRIX=:PRIX where(ID_COMMANDE=:ID_COMMANDE)");
          query.bindValue(":ID_COMMANDE",ID_COMMANDE);
          query.bindValue(":DATE_COMMANDE", DATE_COMMANDE);
          query.bindValue(":DATE_LIVRAISON", DATE_LIVRAISON);
          query.bindValue(":STATUT_COMMANDE", STATUT_COMMANDE);
          query.bindValue(":PRIX", PRIX);

        return query.exec();
}
