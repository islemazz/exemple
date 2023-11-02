#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"plantation.h"
#include <QString>
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include <QIntValidator>
using namespace std;
#include"plantation.h"
#include"connection.h"
#include <iostream>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    P = Plantation();
    ui->lineEdit_id_plant->setValidator(new QIntValidator(100, 99999999, this));
ui->tab_plantation->setModel(P.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_Ajouter_clicked()
{
qDebug();
    int IdPlant = ui->lineEdit_id_plant->text().toInt();
        QString NomPlant = ui->lineEdit_nom_plant->text();
        QString TypePlant = ui->lineEdit_type_plant->text();
        Plantation P(IdPlant, NomPlant, TypePlant);
        P = Plantation(IdPlant, NomPlant, TypePlant);
            Plantation P1;
            P1.setIdPlant(ui->lineEdit_id_plant->text().toInt());
            P1.setNomPlant(ui->lineEdit_nom_plant->text());
            P1.setTypePlant(ui->lineEdit_type_plant->text());

            bool test = P1.ajouter();
            QMessageBox msgBox;
            if (test)
            {msgBox.setText("Ajout avec succès.");
                ui->tab_plantation->setModel(P.afficher()); }
            else
                msgBox.setText("Échec d'ajout");
            msgBox.exec();
        }






/*
bool test=P.ajouter();
if  (test){
    ui->tableView->setModel(P.afficher());
    QMessageBox::information(nullptr, QObject::tr("data base is open"),
                QObject::tr("ajout avec success.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
   QMessageBox::critical(nullptr, QObject::tr("data base isn't open"),
                QObject::tr(" ajout non effectué.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
}*/



void MainWindow::on_pb_supprimer_clicked()
{
    Plantation P1; P1.setIdPlant(ui->le_id_supp->text().toInt());
    bool test=P1.supprimer(P1.getIdPlant());
    QMessageBox msgBox;
    if (test)
       { msgBox.setText("supprimer avec success.");
            ui->tab_plantation->setModel(P.afficher());
    }
    else
        msgBox.setText("Echeck de suppression");
        msgBox.exec();
}


void MainWindow::on_pb_modifier_clicked() {
    int IdPlant = ui->le_id->text().toInt();
    int newSuperficie = ui->le_superficie->text().toInt();
    QString newEtat = ui->le_etatsol->text();

    Plantation P;
    bool test = P.modifier(IdPlant, newSuperficie, newEtat);

    if (test) {
        QMessageBox::information(nullptr, "Modification Successful", "Modification effectuée avec succès.");
    } else {
        QMessageBox::critical(nullptr, "Modification Failed", "Échec de la modification.");
    }
}







