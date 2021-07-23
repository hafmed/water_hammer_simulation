#ifndef water_hammer_simulation_H
#define water_hammer_simulation_H

#include <QMainWindow>
#include <QTimer>
#include "qcustomplot/qcustomplot.h"

namespace Ui {
class water_hammer_simulation;
}

class water_hammer_simulation : public QMainWindow
{
    Q_OBJECT

public:
    explicit water_hammer_simulation(QWidget *parent = 0);
    ~water_hammer_simulation();
    int k;
    int i;
    int j;
    QTimer *timer = new QTimer(this);

    QClipboard *pressePapiers = QApplication::clipboard();
    QString resultatsfr0="";
    QProgressDialog pd;

    int mcolones;
    int nLignes;

    double (*v)[20000] = new double[20000][20000];
    double (*h)[20000] = new double[20000][20000];
    double (*p)[20000] = new double[20000][20000];
    double PIPEZ[20000];

    double t,x,dx,daltat;
    int    m;

    int nparts; //8; // Le nombre d'intervalles dans l'axe de la conduite (n-1)
    double c; //761.96;        //Célérité  d'onde
    double g=9.81;          //Accélération  de la pesanteur
    double d; //0.763;         //Diamètre  de la conduite
    double L; //1523.9;        //Longueur  de la conduite
    double f; //0.02;          //Coefficient de frottement de Dracy-Weisbach
    double v0; //1.523;        //Vitesse intiale
    double h0; //218.07;       //La hauteur d'eau dans le réservoir
    double tmax; //20        //Temps total de simulation
    double tclose; //10;        //Temps de fermeture de la vanne

    double L_old;
    int  nparts_old;
    double tmax_old;
    double c_old;
    double Cd_old;

    //----HAF 23-4-2021-----
    double VR2;
    double HR2;
    double VLNPARTS;
    double HLNPARTS;
    double VL;
    double VR;
    double HL;
    double HR;
    double Cd;
    double Z1;
    double Z2;
    double dZ;
    double theta;
    //----------------------

public slots:
    void plotHAF(int k);
    void changeintervalTimeAnimation();
    void plotHAFTime();
    void StartAnimation();
    void intialplotHAF();
    void plotHAFVanne();
    void recalcul();

    void copy_table_in_Clipboard();
    void affichage_resultats();
    void checkDimVYforrecalcul();

    // HAF 27-4-2021
    void calculMethodeCaracteristique_Simplified();
    void calculMethodeCaracteristique_Complet();
    void calculMethodeLaxWendroff();
    void remplirtableau();
    void tabWidgetcurrentIndexChanged(int );

private:
    Ui::water_hammer_simulation *ui;
};

#endif // CB_H
