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

    double highH2,lowH2;
    double highV2,lowV2;

    double highp,lowp;

    //--for Qt5.9 win32
    // double (*v)[1000] = new double[70000][1000];

    std::size_t array_size=10000;
    double (*v)[1000] = new double[array_size][1000];
    double (*h)[1000] = new double[array_size][1000];
    double (*p)[1000] = new double[array_size][1000];
    double PIPEZ[1000];

    //    double (*v)[1000] = new double[1000][1000];
    //    double (*h)[1000] = new double[1000][1000];
    //    double (*p)[1000] = new double[1000][1000];
    //    double PIPEZ[1000];

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
    QString minmaxh;
    QString minmaxp;
    QString minmaxv;


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

    // HAF 10-7-2022
    void validationVanne();

private slots:
    void about();
    void help();
    #if defined(Q_OS_ANDROID)
        void on_verticalSlider_Zoom_valueChanged(int value);
    #endif


private:
    Ui::water_hammer_simulation *ui;
};

#endif // CB_H
