#include "plantation.h"
#include<QString>
#include<QObject>
#include <iostream>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>

using namespace std;


// Constructors
Plantation::Plantation()
{
    IdPlant = 0;
    NomPlant = "";
    TypePlant = "";
    EtatSol = "";
    DatePlant = QDate();
    Superficie = 0;
    Quantite = 0;
    Etoile = 0;
}

Plantation::Plantation(int id, QString nom, QString type, QString etat, QDate date, int superficie, int quantite, int etoile) {
    IdPlant = id;
    NomPlant = nom;
    TypePlant = type;
    EtatSol = etat;
    DatePlant = date;
    this->Superficie = superficie;
    this->Quantite = quantite;
    this->Etoile = etoile;
}
Plantation::Plantation(int id, QString nom, QString type) {
    IdPlant = id;
    NomPlant = nom;
    TypePlant = type;
}
// Getters
int Plantation::getIdPlant() const {
    return IdPlant;
}

QString Plantation::getNomPlant() const {
    return NomPlant;
}

QString Plantation::getTypePlant() const {
    return TypePlant;
}

QString Plantation::getEtatSol() const {
    return EtatSol;
}

QDate Plantation::getDatePlant() const {
    return DatePlant;
}

int Plantation::getSuperficie() const {
    return Superficie;
}

int Plantation::getQuantite() const {
    return Quantite;
}

int Plantation::getEtoile() const {
    return Etoile;
}

// Setters
void Plantation::setIdPlant(int id) {
    this->IdPlant = id;
}

void Plantation::setNomPlant(const QString &nom) {
    this->NomPlant = nom;
}

void Plantation::setTypePlant(const QString &type) {
    this->TypePlant = type;
}

void Plantation::setEtatSol(const QString &etat) {
    this->EtatSol = etat;
}

void Plantation::setDatePlant(const QDate &date) {
    this->DatePlant = date;
}

void Plantation::setSuperficie(int superficie) {
    this->Superficie = superficie;
}

void Plantation::setQuantite(int quantite) {
    this->Quantite = quantite;
}

void Plantation::setEtoile(int etoile) {
    this->Etoile = etoile;
}

//ajouter

bool Plantation::ajouter() {
    QSqlQuery query;
    QString IdPlant_String = QString::number(IdPlant);
    QString Superficie_String = QString::number(Superficie);
    QString Quantite_String = QString::number(Quantite);
    QString Etoile_String = QString::number(Etoile);

    query.prepare("INSERT INTO GS_PLANTATION (ID_PLANT, NOM_PLANT, TYPE_PLANT, DATE_PLANT, SUPERFICIE, ETAT_SOL, QUANTITE, ETOILE) "
                  "VALUES (:ID_PLANT, :NOM_PLANT, :TYPE_PLANT, :DATE_PLANT, :SUPERFICIE, :ETAT_SOL, :QUANTITE, :ETOILE)");
    query.bindValue(":ID_PLANT", IdPlant_String);
    query.bindValue(":NOM_PLANT", NomPlant);
    query.bindValue(":TYPE_PLANT", TypePlant);
    query.bindValue(":DATE_PLANT", DatePlant); // Check if DatePlant is also needed in the query
    query.bindValue(":SUPERFICIE", Superficie_String);
    query.bindValue(":ETAT_SOL", EtatSol);
    query.bindValue(":QUANTITE", Quantite_String);
    query.bindValue(":ETOILE", Etoile_String);

    if (query.exec()) {
        return true; // Return true on successful query execution
    } else {
        qDebug() << "Error in ajouter: " << query.lastError().text();
        return false; // Return false if an error occurs
    }
}

//supprimer

bool Plantation::supprimer(int IdPlant) {
    QSqlQuery query;
    query.prepare("DELETE FROM GS_PLANTATION WHERE ID_PLANT = :IdPlant");
    query.bindValue(":IdPlant", IdPlant); // Use the correct placeholder here

    return query.exec();
}
//Modifier
bool Plantation::modifier(int IdPlant, int newSuperficie, const QString &newEtat) {
    QSqlQuery query;
    query.prepare("UPDATE GS_PLANTATION SET SUPERFICIE = :SUPERFICIE, ETAT_SOL = :ETAT_SOL WHERE ID_PLANT = :ID_PLANT");
    query.bindValue(":ID_PLANT", IdPlant);
    query.bindValue(":SUPERFICIE", newSuperficie);
    query.bindValue(":ETAT_SOL", newEtat);

    return query.exec();
}
//afficher
QSqlQueryModel* Plantation::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT* FROM GS_PLANTATION");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PLANTATION"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_PLANT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_PLANT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE_PLANT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("SUPERFICIE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ETAT_SOL"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("QUANTITE"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("ETOILE"));

    return model;
}


