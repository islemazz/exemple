#ifndef PLANTATION_H
#define PLANTATION_H
#include<QString>
#include <QObject>
#include <QDate>
#include <QSqlQuery>
#include<QSqlQueryModel>
#include<iostream>
using namespace std;
class Plantation {

public:
// Constructors
    Plantation();
    Plantation(int id, QString nom, QString type, QString etat, QDate date, int superficie, int quantite, int etoile);
    Plantation(int id, QString nom, QString type);
// Getters
    int getIdPlant() const;
    QString getNomPlant() const;
    QString getTypePlant() const;
    QString getEtatSol() const;
    QDate getDatePlant() const;
    int getSuperficie() const;
    int getQuantite() const;
    int getEtoile() const;

// Setters
    void setIdPlant(int id);
    void setNomPlant(const QString &nom);
    void setTypePlant(const QString &type);
    void setEtatSol(const QString &etat);
    void setDatePlant(const QDate &date);
    void setSuperficie(int superficie);
    void setQuantite(int quantite);
    void setEtoile(int etoile);




    // CRUD Functions
    QSqlQueryModel*afficher(); // Display details of a specific plantation
    bool ajouter(); // Add a new plantation to the database
    bool supprimer(int); // Delete a plantation by ID
    bool modifier(int plantID, int newSuperficie, const QString &newEtat); // Modify attributes of a selected plantation by ID


    // Other Common Functions
    void searchByType(const QString &type);
    void sortByDate();
    void generatePDF();
    void getStatisticsBySoilAndType();


    // Innovative Functions
    void rateProduction(int plantID, int Etoile);
    void viewHistoricLastAddition();


private:
    // Attributes
    int IdPlant;
    QString NomPlant;
    QString TypePlant;
    QString EtatSol;
    QDate DatePlant;
    int Superficie;
    int Quantite;
    int Etoile;


};

#endif // PLANTATION_H
