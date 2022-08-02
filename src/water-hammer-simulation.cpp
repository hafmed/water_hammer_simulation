// Metho_Approxi le 15-2-2017 / 23-4-2021 / 25-7-2021 / 9-8-2021
#include "water-hammer-simulation.h"
#include "ui_water-hammer-simulation.h"
#include <QDebug>
//#include <QDesktopWidget> //désactiver for Qt6
#include <QScreen>
#include <QMessageBox>
#include <QMetaEnum>
#include <math.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <constants.h>
using namespace std;
#include <iomanip>

water_hammer_simulation::water_hammer_simulation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::water_hammer_simulation)
{
    ui->setupUi(this);
    //ui->statusBar->showMessage("HAFIANE Mohamed (2021-2022) Ver: " APP_VERSION " Linux&Windows ; email : haftemp@gmail.com ; https://sites.google.com/site/courshaf");
    setWindowTitle(tr("Simulation du phénomène de coup de Bélier"));
    //------------------HAF 25-7-2020----------------------------
    ui->doubleSpinBox_Tclose->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
    ui->doubleSpinBox_Tclose->setGroupSeparatorShown(false);
    ui->lineEdit_C->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
    ui->lineEdit_C->setGroupSeparatorShown(false);
    ui->lineEdit_D->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
    ui->lineEdit_D->setGroupSeparatorShown(false);
    ui->lineEdit_f->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
    ui->lineEdit_f->setGroupSeparatorShown(false);
    ui->lineEdit_Ho->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
    ui->lineEdit_Ho->setGroupSeparatorShown(false);
    ui->lineEdit_L->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
    ui->lineEdit_L->setGroupSeparatorShown(false);
    ui->lineEdit_Vo->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
    ui->lineEdit_Vo->setGroupSeparatorShown(false);
    //------------------------------------------------------------
    checkDimVYforrecalcul();

    connect(timer, SIGNAL(timeout()), this, SLOT(plotHAFTime()));
    connect(ui->pushButton_StartAnimation, SIGNAL(clicked()), this, SLOT(StartAnimation()));
    connect(ui->pushButton_Calculer, SIGNAL(clicked()), this, SLOT(checkDimVYforrecalcul()));

    connect(ui->checkBox_ViteseAnimLente, SIGNAL(stateChanged(int)), this, SLOT(changeintervalTimeAnimation()));
    connect(ui->checkBox_ViteseAnimRapide, SIGNAL(stateChanged(int)), this, SLOT(changeintervalTimeAnimation()));
    connect(ui->checkBox_ViteseAnimRapideRapide, SIGNAL(stateChanged(int)), this, SLOT(changeintervalTimeAnimation()));

    connect(ui->horizontalSlider_k, SIGNAL(valueChanged(int)), this, SLOT(plotHAF(int)));
    connect(ui->radioButton_H, SIGNAL(clicked()), this, SLOT(intialplotHAF()));
    connect(ui->radioButton_V, SIGNAL(clicked()), this, SLOT(intialplotHAF()));
    connect(ui->radioButton_p, SIGNAL(clicked()), this, SLOT(intialplotHAF()));

    connect(ui->comboBox_Anim_Valid, SIGNAL(currentIndexChanged(int)), this, SLOT(plotHAFVanne()));
    connect(ui->radioButton_H, SIGNAL(clicked()), this, SLOT(plotHAFVanne()));
    connect(ui->radioButton_V, SIGNAL(clicked()), this, SLOT(plotHAFVanne()));
    connect(ui->radioButton_p, SIGNAL(clicked()), this, SLOT(plotHAFVanne()));

    connect(ui->spinBox_nparts, SIGNAL(valueChanged(int)), this, SLOT(checkDimVYforrecalcul()));
    connect(ui->lineEdit_C, SIGNAL(valueChanged(double)), this, SLOT(checkDimVYforrecalcul()));
    connect(ui->lineEdit_L, SIGNAL(valueChanged(double)), this, SLOT(checkDimVYforrecalcul()));
    connect(ui->doubleSpinBox_tempsSimulation, SIGNAL(valueChanged(double)), this, SLOT(checkDimVYforrecalcul()));
    connect(ui->doubleSpinBox_Cd, SIGNAL(valueChanged(double)), this, SLOT(checkDimVYforrecalcul()));

    connect(ui->doubleSpinBox_Tclose, SIGNAL(valueChanged(double)), this, SLOT(recalcul()));

    connect(ui->lineEdit_D, SIGNAL(valueChanged(double)), this, SLOT(recalcul()));
    connect(ui->lineEdit_f, SIGNAL(valueChanged(double)), this, SLOT(recalcul()));
    connect(ui->lineEdit_Ho, SIGNAL(valueChanged(double)), this, SLOT(recalcul()));
    connect(ui->lineEdit_Vo, SIGNAL(valueChanged(double)), this, SLOT(recalcul()));

    // HAF 15-7-2020
    connect(ui->pushButton_copy_table_in_Clipboard, SIGNAL(clicked()), this, SLOT(copy_table_in_Clipboard()));
    // HAF 29-04-2021
    pd.setWindowModality(Qt::ApplicationModal);
    pd.setLabelText(tr("Calcul en cours, Veuillez patienter!"));
    pd.setCancelButtonText(tr("Annuler"));
    pd.setFocus();
    pd.setAutoReset(true);
    pd.setEnabled(true);

    // HAF 23-4-2021
    connect(ui->doubleSpinBox_Cd, SIGNAL(valueChanged(double)), this, SLOT(recalcul()));
    connect(ui->lineEdit_Z1, SIGNAL(valueChanged(double)), this, SLOT(recalcul()));
    connect(ui->lineEdit_Z2, SIGNAL(valueChanged(double)), this, SLOT(recalcul()));

    connect(ui->pushButton_Calculer, SIGNAL(clicked()), this, SLOT(recalcul()));

    connect(ui->comboBox_Choisemethod, SIGNAL(currentIndexChanged(int)), this, SLOT(recalcul()));

    ui->checkBox_ViteseAnimRapide->setChecked(true);
    connect(ui->tabWidget, SIGNAL(currentChanged(int)), this, SLOT(tabWidgetcurrentIndexChanged(int)));
    /////------------------
    connect(ui->pushButton_about,SIGNAL(clicked()), this, SLOT(about()));
    connect(ui->pushButton_help,SIGNAL(clicked()), this, SLOT(help()));
    /////------------------
#if defined(Q_OS_ANDROID)
    ui->verticalSlider_Zoom->show();
#else
    ui->verticalSlider_Zoom->hide();
#endif
    /////---------------
    QString locale = QString(QLocale::system().name()).left(2);
    if (locale.length() < 2) locale = "en";
    if (locale!="fr")
    {
        ui->label_fig_config->setPixmap(QPixmap(QString::fromUtf8(":/icons/water-hammer-simulation_Reservoir_ang.png")));
    }
    /////--------------


}
water_hammer_simulation::~water_hammer_simulation()
{
    delete ui;
}
void water_hammer_simulation::calculMethodeLaxWendroff()
{
    pd.setLabelText(tr("Calcul en cours, Veuillez patienter!\n Méthode_Lax_Wendroff"));
    // Entrées
    nparts=ui->spinBox_nparts->value(); //8;
    c=ui->lineEdit_C->value(); //761.96;        //Célérité  d'onde
    d=ui->lineEdit_D->value(); //0.763;         //Diamètre  de la conduite
    L=ui->lineEdit_L->value(); //1523.9;        //Longueur  de la conduite
    f=ui->lineEdit_f->value(); //0.02;          //Coefficient de frottement
    v0=ui->lineEdit_Vo->value(); //1.523;        //Vitesse intiale
    h0=ui->lineEdit_Ho->value(); //218.07;       //La hauteur d'eau dans le réservoir
    tmax=ui->doubleSpinBox_tempsSimulation->value(); //20        //Temps total de simulation
    tclose=ui->doubleSpinBox_Tclose->value(); //10;        //Temps de fermeture de la vanne
    Z1=0;      //ui->lineEdit_Z1->value();
    Z2=0;      //ui->lineEdit_Z2->value();
    theta=(Z2-Z1)/L;
    dZ=(Z2-Z1)/nparts;
    Cd=ui->doubleSpinBox_Cd->value();
    dx=L/nparts;
    daltat=Cd*dx/c;
    // DELT=(DELL/(A+VZERO))/4; % (DT est 75% de la normale) pour voir phénomène de diffusion de la méthode ...
    // DELT=(DELL/(A+VZERO))/0.9; % (DT 110% de la normale) pour voir phénomène d'instabilité numérique de la
    // méthode ...
    m=int(tmax/daltat);

    mcolones=nparts+1;
    nLignes=m+1;

    // Conditions initiales
    for (j=0;j<=nparts;j++)
    {
        v[0][j]=v0;
        h[0][j]=h0-j*f*v0*v0*dx/(2*g*d);
    }
    // ----
    if (!timer->isActive()){
        pd.setRange(0,m);
    }
    t=daltat;
    for (i=1;i<=m;i++)
    {
        if (!timer->isActive()){
            pd.setValue(i);
            if(pd.wasCanceled()){break; }
        }

        h[i][0]=h0;

        v[i][0]=v[i-1][0]-0.5*(daltat/dx)*(g*(h[i-1][1]-h[i-1][0])+v[i-1][0]*(v[i-1][1]-v[i-1][0]))-
                f*v[i-1][0]*fabs(v[i-1][0])*daltat/(2*d);

        for (j=1;j<=nparts-1;j++)
        {
            v[i][j]=v[i-1][j]-0.5*(daltat/dx)*((h[i-1][j+1]-h[i-1][j-1])*g+v[i-1][j]*(v[i-1][j+1]-v[i-1][j-1]))+
                    0.5*(daltat/dx)*(daltat/dx)*(2*g*v[i-1][j]*(h[i-1][j+1]-2*h[i-1][j]+h[i-1][j-1])+
                    (c*c+v[i-1][j]*v[i-1][j])*(v[i-1][j+1]-2*v[i-1][j]+v[i-1][j-1]))-
                    f*v[i-1][j]*fabs(v[i-1][j])*daltat/(2*d);

            h[i][j]=h[i-1][j]-0.5*(daltat/dx)*(v[i-1][j]*(h[i-1][j+1]-h[i-1][j-1])+(c*c/g)*(v[i-1][j+1]-v[i-1][j-1]))+
                    0.5*(daltat/dx)*(daltat/dx)*((v[i-1][j]*v[i-1][j]+c*c)*(h[i-1][j+1]-2*h[i-1][j]+h[i-1][j-1])+
                    (2*c*c*v[i-1][j]/g)*(v[i-1][j+1]-2*v[i-1][j]+v[i-1][j-1]));
        }

        if (t>=tclose)
        {
            v[i][nparts]=0;
        }
        else
        {
            v[i][nparts]=v0*(1-(t/tclose));
        }

        h[i][nparts]=h[i-1][nparts]-0.5*(daltat/dx)*(v[i-1][nparts]*(h[i-1][nparts]-h[i-1][nparts-1])+
                (c*c/g)*(v[i-1][nparts]-v[i-1][nparts-1]));

        t=t+daltat;
    }
}

void water_hammer_simulation::calculMethodeCaracteristique_Complet()
{
    pd.setLabelText(tr("Calcul en cours, Veuillez patienter!\n MOC_Modele_Complet"));
    // Entrées
    nparts=ui->spinBox_nparts->value(); //8;
    c=ui->lineEdit_C->value(); //761.96;        //Célérité  d'onde
    d=ui->lineEdit_D->value(); //0.763;         //Diamètre  de la conduite
    L=ui->lineEdit_L->value(); //1523.9;        //Longueur  de la conduite
    f=ui->lineEdit_f->value(); //0.02;          //Coefficient de frottement
    v0=ui->lineEdit_Vo->value(); //1.523;        //Vitesse intiale
    h0=ui->lineEdit_Ho->value(); //218.07;       //La hauteur d'eau dans le réservoir
    tmax=ui->doubleSpinBox_tempsSimulation->value(); //20        //Temps total de simulation
    tclose=ui->doubleSpinBox_Tclose->value(); //10;        //Temps de fermeture de la vanne
    Z1=ui->lineEdit_Z1->value();
    Z2=ui->lineEdit_Z2->value();
    dZ=(Z2-Z1)/nparts;
    Cd=ui->doubleSpinBox_Cd->value();
    dx=L/nparts;
    theta=dZ/dx;
    daltat=Cd*dx/(c+v0);
    // DELT=(DELL/(A+VZERO))/4; % (DT est 75% de la normale) pour voir phénomène de diffusion de la méthode ...
    // DELT=(DELL/(A+VZERO))/0.9; % (DT 110% de la normale) pour voir phénomène d'instabilité numérique de la
    // méthode ...
    m=int(tmax/daltat);

    mcolones=nparts+1;
    nLignes=m+1;

    // Conditions initiales
    for (j=0;j<=nparts;j++)
    {
        v[0][j]=v0;
        h[0][j]=h0+Z1-j*f*v0*v0*dx/(2*g*d);
    }
    // ----
    if (!timer->isActive()){
        pd.setRange(0,m);
    }
    t=daltat;
    for (i=1;i<=m;i++)
    {
        if (!timer->isActive()){
            pd.setValue(i);
            if(pd.wasCanceled()){break; }
        }

        h[i][0]=h0+Z1;

        VR2=v[i-1][0]+c*daltat/dx*(v[i-1][1]-v[i-1][0]);
        HR2=h[i-1][0]+daltat/dx*(h[i-1][1]-h[i-1][0])*(c-VR2);
        v[i][0]=VR2+g/c*(h[i][0]-HR2)-g/c*daltat*VR2*sin(theta)-(f*daltat)/(2*d)*VR2*fabs(VR2);


        for (j=1;j<=nparts-1;j++)
        {
            VL=v[i-1][j]+c*daltat/dx*(v[i-1][j-1]-v[i-1][j]);
            VR=v[i-1][j]+c*daltat/dx*(v[i-1][j+1]-v[i-1][j]);
            HL=h[i-1][j]+daltat/dx*(h[i-1][j-1]-h[i-1][j])*(c+VL);
            HR=h[i-1][j]+daltat/dx*(h[i-1][j+1]-h[i-1][j])*(c-VR);
            v[i][j]=0.5*((VL+VR)+g/c*(HL-HR)+g/c*daltat*(VL-VR)*sin(theta)-(f*daltat)/(2*d)*(VL*fabs(VL)+VR*fabs(VR)));
            h[i][j]=0.5*(c/g*(VL-VR)+(HL+HR)+daltat*(VL+VR)*sin(theta)-c/g*(f*daltat)/(2*d)*(VL*fabs(VL)-VR*fabs(VR)));
        }

        if (t>=tclose)
        {
            v[i][nparts]=0;
        }
        else
        {
            v[i][nparts]=v0*(1-(t/tclose));
        }

        VLNPARTS=v[i][nparts]+c*daltat/dx*(v[i-1][nparts-1]-v[i][nparts]);
        HLNPARTS=h[i-1][nparts]+daltat/dx*(h[i-1][nparts-1]-h[i-1][nparts])*(c+VLNPARTS);
        h[i][nparts]=HLNPARTS+c/g*(VLNPARTS-v[i][nparts]-(f*daltat)/(2*d)*(VLNPARTS*fabs(VLNPARTS)))-VLNPARTS*daltat*sin(theta);

        t=t+daltat;
    }
}

void water_hammer_simulation::calculMethodeCaracteristique_Simplified()
{
    pd.setLabelText(tr("Calcul en cours, Veuillez patienter!\n MOC_Modele_Simplifié"));
    // Entrées
    nparts=ui->spinBox_nparts->value(); //8;
    c=ui->lineEdit_C->value(); //761.96;        //Célérité  d'onde
    d=ui->lineEdit_D->value(); //0.763;         //Diamètre  de la conduite
    L=ui->lineEdit_L->value(); //1523.9;        //Longueur  de la conduite
    f=ui->lineEdit_f->value(); //0.02;          //Coefficient de frottement
    v0=ui->lineEdit_Vo->value(); //1.523;        //Vitesse intiale
    h0=ui->lineEdit_Ho->value(); //218.07;       //La hauteur d'eau dans le réservoir
    tmax=ui->doubleSpinBox_tempsSimulation->value(); //20        //Temps total de simulation
    tclose=ui->doubleSpinBox_Tclose->value(); //10;        //Temps de fermeture de la vanne
    Z1=0;      //ui->lineEdit_Z1->value();
    Z2=0;      //ui->lineEdit_Z2->value();
    // theta=(Z2-Z1)/L;
    dZ=(Z2-Z1)/nparts;
    dx=L/nparts;
    daltat=dx/c;
    m=int(tmax/daltat);

    mcolones=nparts+1;
    nLignes=m+1;

    // Conditions initiales
    for (j=0;j<=nparts;j++)
    {
        v[0][j]=v0;
        h[0][j]=h0-j*f*v0*v0*dx/(2*g*d);
    }
    // ----
    if (!timer->isActive()){
        pd.setRange(0,m);
    }
    t=daltat;
    for (i=1;i<=m;i++)
    {
        if (!timer->isActive()){
            pd.setValue(i);
            if(pd.wasCanceled()){break; }
        }

        h[i][0]=h0;
        v[i][0]=v[i-1][1]+g/c*(h0-h[i-1][1])-f*daltat/(2*d)*v[i-1][1]*fabs(v[i-1][1]);

        for (j=1;j<=nparts-1;j++)
        {
            v[i][j]=0.5*((v[i-1][j-1]+v[i-1][j+1])+g/c*(h[i-1][j-1]-h[i-1][j+1])-
                    (f*daltat)/(2*d)*(v[i-1][j-1]*fabs(v[i-1][j-1])+v[i-1][j+1]*fabs(v[i-1][j+1])));
            h[i][j]=0.5*(c/g*(v[i-1][j-1]-v[i-1][j+1])+(h[i-1][j-1]+h[i-1][j+1])-
                    c/g*(f*daltat)/(2*d)*(v[i-1][j-1]*fabs(v[i-1][j-1])-v[i-1][j+1]*fabs(v[i-1][j+1])));
        }

        if (t>=tclose)
        {
            v[i][nparts]=0;
        }
        else
        {
            v[i][nparts]=v0*(1-(t/tclose));
        }
        h[i][nparts]=h[i-1][nparts-1]+c/g*(v[i-1][nparts-1]-v[i][nparts]-f*daltat/(2*d)*v[i-1][nparts-1]*fabs(v[i-1][nparts-1]));
        t=t+daltat;
    }
}

void water_hammer_simulation::remplirtableau()
{
    if (ui->tabWidget->currentIndex()==2){
        QStringList Horizontalheadtext;
        QStringList Verticalheadtext;
        ui->tableWidget->setColumnCount(mcolones);
        ui->tableWidget->setRowCount(nLignes);

        t=0;
        x=0;
        for (i=0; i < nLignes  ; i++)
        {
            // if (!timer->isActive()){
            pd.setValue(i);
            if(pd.wasCanceled()){break; }
            //}
            Horizontalheadtext+="x="+QString::number(x)+" (m)";
            x+=dx;
            for (j=0; j < mcolones ; j++){
                Verticalheadtext+="t="+QString::number(t)+" (s)";
                t+=daltat;
            }
        }
        ui->tableWidget->setStyleSheet("QTableView {selection-background-color: green;}");
        ui->tableWidget->setHorizontalHeaderLabels(Horizontalheadtext);
        ui->tableWidget->setVerticalHeaderLabels(Verticalheadtext);
        for (i=0; i < nLignes  ; i++)
        {
            if (!timer->isActive()){
                pd.setValue(i);
                if(pd.wasCanceled()){break; }
            }
            for (j=0; j < mcolones ; j++){
                if (ui->radioButton_H->isChecked()){
                    ui->tableWidget->setItem(i,j,new QTableWidgetItem(tr("%1").arg(h[i][j])));
                }else if(ui->radioButton_V->isChecked()){
                    ui->tableWidget->setItem(i,j,new QTableWidgetItem(tr("%1").arg(v[i][j])));
                }else if(ui->radioButton_p->isChecked()){
                    ui->tableWidget->setItem(i,j,new QTableWidgetItem(tr("%1").arg(p[i][j])));
                }
            }
        }
        //cout<<"pd close="<<endl;
        pd.close();
    }

}
void water_hammer_simulation::copy_table_in_Clipboard()
{
    pd.reset();
    pd.setLabelText(tr("Calcul en cours, Veuillez patienter!\n copier tableau dans presse paper"));
    t=0;
    x=0;
    resultatsfr0="t(s)/x(m)";
    for (j=0; j< mcolones ; j++)
    {
        if (!timer->isActive()){
            pd.setValue(i);
            if(pd.wasCanceled()){break; }
        }
        resultatsfr0+="\t"+QString::number(x);
        x+=dx;
    }
    for (i=0; i < nLignes  ; i++)
    {
        if (!timer->isActive()){
            pd.setValue(i);
            if(pd.wasCanceled()){break; }
        }
        resultatsfr0+="\n"+QString::number(t);
        for (j=0; j < mcolones ; j++){
            if (ui->radioButton_H->isChecked()){
                resultatsfr0+="\t"+QString::number(h[i][j]);
            }else if(ui->radioButton_V->isChecked()){
                resultatsfr0+="\t"+QString::number(v[i][j]);
            }else if(ui->radioButton_p->isChecked()){
                resultatsfr0+="\t"+QString::number(p[i][j]);
            }
        }
        t+=daltat;
    }
    pressePapiers->setText(resultatsfr0);
    pd.close();
}

void water_hammer_simulation::tabWidgetcurrentIndexChanged(int i)
{
    if (i==2){
        pd.reset();
        pd.setLabelText(tr("Calcul en cours, Veuillez patienter!\n remplir tableau"));
        pd.setRange(0,nLignes-1);

        remplirtableau();
    }
}

void water_hammer_simulation::checkDimVYforrecalcul()
{
    //HAF 7-9-2020
    L=ui->lineEdit_L->value();
    nparts=ui->spinBox_nparts->value();
    tmax=ui->doubleSpinBox_tempsSimulation->value();
    c=ui->lineEdit_C->value();

    Cd=ui->doubleSpinBox_Cd->value();
    dx=L/nparts;

    if (ui->comboBox_Choisemethod->currentIndex()==0){
        daltat=dx/c;
    }else if(ui->comboBox_Choisemethod->currentIndex()==1){
        daltat=Cd*dx/(c+v0);
    }else if(ui->comboBox_Choisemethod->currentIndex()==2){
        daltat=Cd*dx/c;
    }

    m=int(tmax/daltat);

    if (ui->radioButton_H->isChecked()){
        minmaxh="H";
    }else if(ui->radioButton_V->isChecked()){
        minmaxh="V";
    }else if(ui->radioButton_p->isChecked()){
        minmaxh="P";
    }
    minmaxh=minmaxh+ "("+QString::number(m)+" , "+QString::number(nparts+1)+")";
    ui->label_dimensionTab->setText(minmaxh);
    //cout<<"m="<<endl;
    if (m>int(array_size) || nparts>int(array_size) ) {
        QMessageBox errorMessage;
        errorMessage.setFixedSize(500, 200);
        errorMessage.critical(this, tr("Erreur données : Mémoire maximale allouée saturée!"),
                              tr("Augmenter (L ou C ou CFL) ou diminuer (Tmax ou nparts)"));
        errorMessage.show();
        ui->lineEdit_L->setValue(L_old);
        ui->spinBox_nparts->setValue(nparts_old);
        ui->doubleSpinBox_tempsSimulation->setValue(tmax_old);
        ui->lineEdit_C->setValue(c_old);
        ui->doubleSpinBox_Cd->setValue(Cd_old);
        return;
    }
    if (!(L_old==ui->lineEdit_L->value() && nparts_old==ui->spinBox_nparts->value() && tmax_old==ui->doubleSpinBox_tempsSimulation->value() &&
          c_old==ui->lineEdit_C->value()&& Cd_old==ui->doubleSpinBox_Cd->value()))
        recalcul();
}

void water_hammer_simulation::recalcul()
{
    int index=ui->comboBox_Choisemethod->currentIndex();
    if (index==0){
        ui->doubleSpinBox_Cd->hide();
        ui->label_Cd->hide();
        ui->lineEdit_Z1->hide();
        ui->lineEdit_Z2->hide();
        ui->label_Z1->hide();
        ui->label_uZ1->hide();
        ui->label_Z2->hide();
        ui->label_uZ2->hide();
    }else if(index==1){
        ui->doubleSpinBox_Cd->show();
        ui->label_Cd->show();
        ui->lineEdit_Z1->show();
        ui->lineEdit_Z2->show();
        ui->label_Z1->show();
        ui->label_uZ1->show();
        ui->label_Z2->show();
        ui->label_uZ2->show();
    }else if(index==2){
        ui->doubleSpinBox_Cd->show();
        ui->label_Cd->show();
        ui->lineEdit_Z1->hide();
        ui->lineEdit_Z2->hide();
        ui->label_Z1->hide();
        ui->label_uZ1->hide();
        ui->label_Z2->hide();
        ui->label_uZ2->hide();
    }

    L_old=ui->lineEdit_L->value();
    nparts_old=ui->spinBox_nparts->value();
    tmax_old=ui->doubleSpinBox_tempsSimulation->value();
    c_old=ui->lineEdit_C->value();
    Cd_old=ui->doubleSpinBox_Cd->value();

    ui->pushButton_StartAnimation->setText(tr("Commencer l'animation"));
    timer->stop();
    pd.reset();
    ui->customPlot_2->clearItems();
    if (index==0){
        calculMethodeCaracteristique_Simplified();
    }else if(index==1){
        calculMethodeCaracteristique_Complet();
    }else if(index==2){
        calculMethodeLaxWendroff();
    }
    plotHAF(0);
    plotHAFVanne();
    affichage_resultats();

    ui->verticalSlider_Zoom->setValue(0);
}
void water_hammer_simulation::changeintervalTimeAnimation()
{
    k=0;
    if (ui->checkBox_ViteseAnimLente->isChecked()){
        timer->setInterval(1000); //1s
    }
    if (ui->checkBox_ViteseAnimRapide->isChecked()||ui->checkBox_ViteseAnimRapideRapide->isChecked()){
        timer->setInterval(1);
    }

}
void water_hammer_simulation::StartAnimation()
{
    if (ui->horizontalSlider_k->value()==ui->horizontalSlider_k->maximum())
    {
        ui->horizontalSlider_k->setValue(0);
    }
    k=ui->horizontalSlider_k->value();
    if (ui->checkBox_ViteseAnimLente->isChecked()){
        timer->setInterval(1000); //1s
    }
    if (ui->checkBox_ViteseAnimRapide->isChecked()||ui->checkBox_ViteseAnimRapideRapide->isChecked()){
        timer->setInterval(1);
    }

    if (!timer->isActive()){
        double tmax=ui->doubleSpinBox_tempsSimulation->value();
        if ((k+1)*daltat>tmax) k=0;

        timer->start();

        ui->pushButton_StartAnimation->setText(tr("Arrêter l'animation"));
    }else{
        timer->stop();
        ui->pushButton_StartAnimation->setText(tr("Commencer l'animation"));
    }
    ui->comboBox_Anim_Valid->setCurrentIndex(0);
    ui->horizontalSlider_k->setValue(k);
}
void water_hammer_simulation::plotHAFTime()
{
    k=k+1;
    if (ui->checkBox_ViteseAnimRapideRapide->isChecked()){
        k=k+10;
    }
    plotHAF(k);
}
void water_hammer_simulation::intialplotHAF()
{
    k=0;
    plotHAF(k);
    ui->horizontalSlider_k->setValue(0);
    checkDimVYforrecalcul();
    affichage_resultats();
    tabWidgetcurrentIndexChanged(2);
}
void water_hammer_simulation::validationVanne()
{
    // Détermination Max H Vanne
    double highHvanne;
    highHvanne=h[0][mcolones-1];
    for(i=1;i<nLignes ;i++)
    {
        if(h[i][mcolones-1]>highHvanne){
            highHvanne=h[i][mcolones-1];
        }
    }
    /////cout<<"highHvanne="<<highHvanne<<endl;
    QString temptext;

    if (tclose>2*L/c){
        if (ui->radioButton_H->isChecked()){
            temptext="DH(Theo)="+QString::number((1000*2*L*v0)/(1000*g*tclose));
            temptext=temptext+" ; DH(Num)="+QString::number(abs(highHvanne-h[0][nparts]))+" ; E="+
                    QString::number((abs(highHvanne-h[0][nparts])-((1000*2*L*v0)/(1000*g*tclose)))/((1000*2*L*v0)/(1000*g*tclose))*100,'f',2)+
                    "%";
        }else{
            temptext="DP(Theo)="+QString::number((1000*2*L*v0)/(1000*tclose));//en kPa
            temptext=temptext+" ; DP(Num)="+QString::number(abs((highHvanne-h[0][nparts])*g))+" ; E="+
                    QString::number((abs((highHvanne-h[0][nparts])*g)-((1000*2*L*v0)/(1000*tclose)))/((1000*2*L*v0)/(1000*tclose))*100,'f',2)+
                    "%";
        }
    }else{
        if (ui->radioButton_H->isChecked()){
            temptext="DH(Theo)="+QString::number((1000*c*v0)/(1000*g));
            temptext=temptext+" ; DH(Num)="+QString::number(abs(highHvanne-h[0][nparts]))+" ; E="+
                    QString::number((abs(highHvanne-h[0][nparts])-((1000*c*v0)/(1000*g)))/((1000*c*v0)/(1000*g))*100,'f',2)+
                    "%";
        }else{
            temptext="DP(Theo)="+QString::number((1000*c*v0)/(1000));//en kPa
            temptext=temptext+" ; DP(Num)="+QString::number(abs((highHvanne-h[0][nparts])*g))+" ; E="+
                    QString::number((abs((highHvanne-h[0][nparts])*g)-((1000*c*v0)/(1000)))/((1000*c*v0)/(1000))*100,'f',2)+
                    "%";
        }
    }
    ui->label_DPtheo_DPnum->setText(temptext);
}
void water_hammer_simulation::plotHAF(int k)
{
    mcolones=nparts+1;
    nLignes=m+1;
    //
    for(i=0;i<nLignes ;i++)
    {
        for(j=0;j<mcolones;j++)
        {
            PIPEZ[j]=Z1+j*dZ;
            p[i][j]=1000*g*(h[i][j]-PIPEZ[j])/1000; //en kPa
        }
    }
    // Détermination Max et Mini de V et H
    double highH,lowH;
    double highV,lowV;
    highH=h[0][0];
    lowH=h[0][0];
    for(i=0;i<nLignes ;i++)
    {
        for(j=0;j<mcolones;j++)
        {
            if(h[i][j]>highH){
                highH=h[i][j];
            }else{
                if(h[i][j]<lowH){
                    lowH=h[i][j];
                }
            }
        }
    }
    minmaxh= "H, min="+QString::number(lowH)+" m"+ ", max="+QString::number(highH)+" m";
    //ui->radioButton_H->setText(minmaxh);
    highV=v[0][0];
    lowV=v[0][0];
    for(i=0;i<nLignes ;++i)

        for(j=0;j<mcolones;++j)
        {
            if(v[i][j]>highV)
                highV=v[i][j];
            else
                if(v[i][j]<lowV)
                    lowV=v[i][j];
        }
    minmaxv= "V, min="+QString::number(lowV)+" m/s"+ ", max="+QString::number(highV)+" m/s";
    //ui->radioButton_V->setText(minmaxv);
    // ui->statusBar->showMessage(minmaxv);
    //haf 25-4-2021
    highp=p[0][0];
    lowp=p[0][0];
    for(i=0;i<nLignes ;++i){
        for(j=0;j<mcolones;++j)
        {
            if(p[i][j]>highp)
                highp=p[i][j];
            else
                if(p[i][j]<lowp)
                    lowp=p[i][j];
        }
    }
    minmaxp= "P=rol*g*(H-z), min="+QString::number(lowp)+" kPa"+ ", max="+QString::number(highp)+" kPa";
    // ui->radioButton_p->setText(minmaxp);
    //   ui->statusBar->showMessage(minmaxp);
    //-----
    if ((k+1)*daltat>tmax){
        ui->pushButton_StartAnimation->setText(tr("Commencer l'animation"));
        timer->stop();
    }
    ui->horizontalSlider_k->setMaximum(nLignes-1);
    //------------------------------------------------
    QVector<double> x(mcolones), y(mcolones);
    for (j=0; j<mcolones; ++j)
    {
        x[j]=j*dx/L;
        if (ui->radioButton_H->isChecked()){
            y[j] = h[k][j] ;
        }else if(ui->radioButton_V->isChecked()){
            y[j] = v[k][j] ;
        }else if(ui->radioButton_p->isChecked()){
            y[j] = p[k][j] ;
        }
    }
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setName(tr("Simulation water_hammer_simulation"));
    ui->customPlot->graph(0)->setData(x, y);
    ui->customPlot->xAxis->setLabel("x/L (-)");
    ui->customPlot->xAxis->setRange(0, 1);
    if (ui->radioButton_H->isChecked()){
        ui->customPlot->yAxis->setLabel("H (m)");
        ui->customPlot->yAxis->setRange(lowH, highH);
        ui->statusBar->showMessage(minmaxh);
    }else if(ui->radioButton_V->isChecked()){
        ui->customPlot->yAxis->setLabel("V (m/s)");
        ui->customPlot->yAxis->setRange(lowV, highV);
        ui->statusBar->showMessage(minmaxv);
    }else if(ui->radioButton_p->isChecked()){
        ui->customPlot->yAxis->setLabel("P (kPa)");
        ui->customPlot->yAxis->setRange(lowp, highp);
        ui->statusBar->showMessage(minmaxp);
    }

    ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::red, Qt::white, 7));
    ui->customPlot->axisRect()->setupFullAxesBox();
    ui->customPlot->legend->setVisible(false);

    QString temps= "t="+QString::number(k*daltat, 'f', 3)+" s";
    ui->label_tempsSimulation->setText(temps);
    ui->horizontalSlider_k->setValue(k);

    ui->label_TempsRetour->setVisible(false);
    ui->customPlot->replot();
    pd.close();
}

void water_hammer_simulation::plotHAFVanne()
{
    ui->verticalSlider_Zoom->setValue(0);
    if (ui->comboBox_Anim_Valid->currentIndex()==0){
        ui->label_DPtheo_DPnum->hide();
    }else{
        ui->label_DPtheo_DPnum->show();
    }

    // Détermination Max et Mini de V et H
    highH2=h[0][0];
    lowH2=h[0][0];
    for(i=0;i<nLignes ;i++)
    {
        for(j=0;j<mcolones;j++)
        {
            if(h[i][j]>highH2){
                highH2=h[i][j];
            }else{
                if(h[i][j]<lowH2){
                    lowH2=h[i][j];
                }
            }
        }
    }
    minmaxh= "H, min="+QString::number(lowH2)+" m"+ ", max="+QString::number(highH2)+" m";
    //ui->radioButton_H->setText(minmaxh);
    //ui->statusBar->showMessage(minmaxh);
    highV2=v[0][0];
    lowV2=v[0][0];
    for(i=0;i<nLignes ;++i){
        for(j=0;j<mcolones;++j)
        {
            if(v[i][j]>highV2){
                highV2=v[i][j];
            }else{
                if(v[i][j]<lowV2){
                    lowV2=v[i][j];
                }
            }
        }
    }
    minmaxv= "V, min="+QString::number(lowV2)+" m/s"+ ", max="+QString::number(highV2)+" m/s";
    //ui->radioButton_V->setText(minmaxv);
    //ui->statusBar->showMessage(minmaxv);
    //haf 25-4-2021
    highp=p[0][0];
    lowp=p[0][0];
    for(i=0;i<nLignes ;++i){
        for(j=0;j<mcolones;++j)
        {
            if(p[i][j]>highp)
                highp=p[i][j];
            else
                if(p[i][j]<lowp)
                    lowp=p[i][j];
        }
    }
    minmaxp= "P=rol*g*(H-z), min="+QString::number(lowp)+" kPa"+ ", max="+QString::number(highp)+" kPa";
    //ui->radioButton_p->setText(minmaxp);
    //ui->statusBar->showMessage(minmaxp);
    //-----
    //------------------------------------------------
    QVector<double> xx(nLignes), yy(nLignes);
    for (i=0; i<nLignes; ++i)
    {
        //x[i] = i*1;
        xx[i]=i*daltat/(2*L/c);
        if (ui->radioButton_H->isChecked()){
            yy[i] = h[i][nparts] ; //vanne
        }else if(ui->radioButton_V->isChecked()){
            yy[i] = v[i][nparts] ;
        }else if(ui->radioButton_p->isChecked()){
            yy[i] = p[i][nparts] ;
        }
    }
    ui->customPlot_2->clearItems(); //HAF 25-04-2021
    ui->customPlot_2->addGraph();
    ui->customPlot_2->graph(0)->setName(tr("Validation water_hammer_simulation"));
    ui->customPlot_2->graph(0)->setData(xx, yy);
    ui->customPlot_2->xAxis->setLabel("t/(2*L/c) (-)"); //HAF-25-7-2020
    ui->customPlot_2->xAxis->setRange(-tmax/(2*L/c)*0.25, tmax/(2*L/c)); //HAF-17-7-2020

    if (ui->radioButton_H->isChecked() || ui->radioButton_p->isChecked()){
        if (ui->radioButton_H->isChecked()){
            ui->customPlot_2->yAxis->setLabel("H (m)");
            ui->customPlot_2->yAxis->setRange(lowH2-0.05*fabs(lowH2), highH2+0.05*fabs(highH2));
        }else{
            ui->customPlot_2->yAxis->setLabel("P (kPa)");
            ui->customPlot_2->yAxis->setRange(lowp-0.05*fabs(lowp), highp+0.05*fabs(highp));
        }

        QCPItemText *textLabel = new QCPItemText(ui->customPlot_2);
        textLabel->setPositionAlignment(Qt::AlignTop|Qt::AlignHCenter);
        textLabel->position->setType(QCPItemPosition::ptAxisRectRatio);
        textLabel->position->setCoords(0.19,  .89); // place position at center/top of axis rect
        if (ui->radioButton_H->isChecked()){
            textLabel->setText("H_vanne(t=0)");
        }else{
            textLabel->setText("P_vanne(t=0)");
        }
        textLabel->setFont(QFont(font().family(), 9)); // make font a bit larger
        textLabel->setPen(QPen(Qt::black)); // show black border around text
        // add the arrow:
        QCPItemLine *arrow = new QCPItemLine(ui->customPlot_2);
        // ---ui->customPlot_2->addItem(arrow);
        arrow->start->setParentAnchor(textLabel->topLeft);
        if (ui->radioButton_H->isChecked()){
            arrow->end->setCoords(0,  h[0][nparts]); // point to (4, 1.6) in x-y-plot coordinates
        }else{
            arrow->end->setCoords(0,  p[0][nparts]); // point to (4, 1.6) in x-y-plot coordinates
        }
        arrow->setHead(QCPLineEnding::esFlatArrow);
        // add the bracket at the top:
        QCPItemBracket *bracket = new QCPItemBracket(ui->customPlot_2);
        // ---ui->customPlot_2->addItem(bracket);
        if (ui->radioButton_H->isChecked()){
            bracket->left->setCoords(0, h[0][nparts]);
        }else{
            bracket->left->setCoords(0, p[0][nparts]);
        }
        bracket->setLength(13);
        // add the text label at the top:
        QCPItemText *wavePacketText = new QCPItemText(ui->customPlot_2);
        // ---ui->customPlot_2->addItem(wavePacketText);
        wavePacketText->position->setParentAnchor(bracket->center);
        wavePacketText->position->setCoords(-12.5, 0); // move 10 pixels to the top from bracket center anchor
        wavePacketText->setPositionAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        if (tclose>2*L/c){
            if (ui->radioButton_H->isChecked()){
                wavePacketText->setText("DH=(Rol*2*L*V_0/Tclose)/(Rol*g)");
                bracket->right->setCoords(0, h[0][nparts]+(1000*2*L*v0)/(1000*g*tclose));
            }else{
                wavePacketText->setText("DP=Rol*2*L*V_0/Tclose");
                bracket->right->setCoords(0, p[0][nparts]+(1000*2*L*v0)/tclose/1000); //en kPa
            }
        }else{
            QCPItemBracket *bracket2 = new QCPItemBracket(ui->customPlot_2);
            QCPItemText *wavePacketText2 = new QCPItemText(ui->customPlot_2);
            if (ui->radioButton_H->isChecked()){
                wavePacketText->setText("DH=Rol*C*V_0/(Rol*g)");
                bracket->right->setCoords(0, h[0][nparts]+(1000*c*v0)/(1000*g));
                // --- ui->customPlot_2->addItem(bracket2);
                bracket2->left->setCoords( 0, h[0][nparts]+(1000*c*v0)/(1000*g));
                bracket2->setLength(13);
                // ---ui->customPlot_2->addItem(wavePacketText2);
                wavePacketText2->position->setParentAnchor(bracket2->center);
                wavePacketText2->position->setCoords(-12.5, 0); // move 10 pixels to the top from bracket center anchor
                wavePacketText2->setPositionAlignment(Qt::AlignBottom|Qt::AlignHCenter);
                if (f!=0){
                    wavePacketText2->setText("   hf");
                }else{
                    wavePacketText2->setText("");
                }
                /////bracket2->right->setCoords(0, h[0][nparts]+(1000*c*v0)/(1000*g)+(h0-h[0][nparts]));
                bracket2->right->setCoords(0, h[0][nparts]+(1000*c*v0)/(1000*g)+(h[0][0]-h[0][nparts]));
            }else{
                wavePacketText->setText("DP=Rol*C*V_0");
                bracket->right->setCoords(0, p[0][nparts]+(1000*c*v0)/1000); //en kPa
                // --- ui->customPlot_2->addItem(bracket2);
                bracket2->left->setCoords( 0, p[0][nparts]+(1000*c*v0)/1000);//en kPa
                bracket2->setLength(13);
                // ---ui->customPlot_2->addItem(wavePacketText2);
                wavePacketText2->position->setParentAnchor(bracket2->center);
                wavePacketText2->position->setCoords(-12.5, 0); // move 10 pixels to the top from bracket center anchor
                wavePacketText2->setPositionAlignment(Qt::AlignBottom|Qt::AlignHCenter);
                if (f!=0){
                    wavePacketText2->setText("hf");
                }else{
                    wavePacketText2->setText("");
                }
                bracket2->right->setCoords(0, (h[0][nparts]-Z2+(1000*c*v0)/(1000*g)+(h[0][0]-h[0][nparts]+dZ))*(g));
                /////bracket2->right->setCoords(0, (p[0][nparts]+(1000*c*v0)+((h0*1000*g)-p[0][nparts]))/1000);
            }
        }
        ui->label_TempsRetour->setVisible(true);
        ui->label_TempsRetour->setText(QString(tr("Temps d'aller-retour de l'onde de pression (2*L/c)=%2 (s)"))
                                       .arg(2*L/c, 0, 'f', 2));
        wavePacketText->setFont(QFont(font().family(), 10));
        wavePacketText->setRotation(-90);
    }else{
        ui->customPlot_2->clearItems();
        ui->customPlot_2->yAxis->setLabel("V (m/s)");
        ui->customPlot_2->yAxis->setRange(lowV2-0.05*fabs(lowV2), highV2+0.05*fabs(highV2));
    }
    ui->customPlot_2->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::red, Qt::white, 7));
    ui->customPlot_2->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    //------------------------------------------------
    if (ui->radioButton_H->isChecked()){
        ui->customPlot_2->yAxis->setRange(lowH2-0.5*fabs(lowH2), highH2+0.25*fabs(highH2));
    }else if(ui->radioButton_V->isChecked()){
        ui->customPlot_2->yAxis->setRange(lowV2-0.15*fabs(lowV2), highV2+0.15*fabs(highV2));
    }else if(ui->radioButton_p->isChecked()){
        ui->customPlot_2->yAxis->setRange(lowp-0.15*fabs(lowp), highp+0.15*fabs(highp));
    }
    ui->customPlot_2->replot();
    pd.close();

    validationVanne();
}
void water_hammer_simulation::affichage_resultats(){
    nparts=ui->spinBox_nparts->value();
    c=ui->lineEdit_C->value();
    L=ui->lineEdit_L->value();
    tmax=ui->doubleSpinBox_tempsSimulation->value();

    Cd=ui->doubleSpinBox_Cd->value();

    if (ui->comboBox_Choisemethod->currentIndex()==0){
        daltat=dx/c;
    }else if(ui->comboBox_Choisemethod->currentIndex()==1){
        daltat=Cd*dx/(c+v0);
    }else if(ui->comboBox_Choisemethod->currentIndex()==2){
        daltat=Cd*dx/c;
    }

    dx=L/nparts;
    m=int(tmax/daltat);
    mcolones=nparts+1;
    nLignes=m+1;

    QString daltattext=" dt="+QString::number(daltat,'f',3)+" (s)";
    ui->label_dt->setText(daltattext);

    /* Affichage */
    //    ofstream myfile;
    //    myfile.open ("returns_water_hammer_simulation.txt");
    //    for (i=0; i < nLignes  ; i++)
    //    {
    //        if (!timer->isActive()){
    //            pd.setValue(i);
    //        }
    //        myfile<< "\n";
    //        for (j=0; j < mcolones ; j++){
    //            if (ui->radioButton_H->isChecked()){
    //                myfile << setprecision(6)<< h[i][j] << " ";
    //            }else if(ui->radioButton_V->isChecked()){
    //                myfile << setprecision(6)<< v[i][j] << " ";
    //            }else if(ui->radioButton_p->isChecked()){
    //                myfile << setprecision(6)<< p[i][j] << " ";
    //            }
    //        }
    //        myfile << endl;
    //    }
    //--
}
/// for Android 10-7-2022
/// 10-7-2022
void water_hammer_simulation::help()
{
    QString link = "https://sites.google.com/site/courshaf";
    QDesktopServices::openUrl(QUrl(link));
}
#if defined(Q_OS_ANDROID)
void water_hammer_simulation::about()
{
    QMessageBox msgBox(this);
    msgBox.setWindowTitle(tr("À propos"));
    msgBox.setTextFormat(Qt::RichText);
    QString pubabout=tr("Avec différentes méthodes numériques cette application simule le phénomène de coup de Bélier ; \n")+
            "Ver. "+ APP_VERSION +tr(" sur Linux, Windows et Android ; \n")+
            "("+ QString("%1").arg(BLD_DATE) +tr(") ; ")+
            "\n HAFIANE Mohamed ; e-mail for feedback: thakir.dz@gmail.com"+
            tr(" ou ")+
            "mohammed.hafiane@univ-saida.dz;\n\n"+
            tr("Page web : ")+
            "https://sites.google.com/site/courshaf; \n\n"+
            tr("Programmé avec C++ (mingw64) avec comme IDE (Qt Creator) et avec ")+
            " Qt Ver. " +QT_VERSION_STR;
    msgBox.setText(pubabout);
    msgBox.exec();
}
void water_hammer_simulation::on_verticalSlider_Zoom_valueChanged(int value)
{
    if (value==0){
        if (ui->radioButton_H->isChecked()){
            ui->customPlot_2->yAxis->setRange(lowH2-0.5*fabs(lowH2), highH2+0.25*fabs(highH2));
        }else if(ui->radioButton_V->isChecked()){
            ui->customPlot_2->yAxis->setRange(lowV2-0.15*fabs(lowV2), highV2+0.15*fabs(highV2));
        }else if(ui->radioButton_p->isChecked()){
            ui->customPlot_2->yAxis->setRange(lowp-0.15*fabs(lowp), highp+0.15*fabs(highp));
        }
    }else{
        if (ui->radioButton_H->isChecked()){
            ui->customPlot_2->yAxis->setRange(lowH2, highH2-value*0.1*highH2);
        }else if(ui->radioButton_V->isChecked()){
            ui->customPlot_2->yAxis->setRange(lowV2, highV2-value*0.1*highV2);
        }else if(ui->radioButton_p->isChecked()){
            ui->customPlot_2->yAxis->setRange(lowp, highp-value*0.1*highp);
        }
    }
    ui->customPlot_2->replot();
    pd.close();
    validationVanne();
}
#else
void water_hammer_simulation::about()
{
    QMessageBox msgBox(this);
    msgBox.setWindowTitle(tr("À propos"));
    msgBox.setTextFormat(Qt::RichText);
    QString pubabout=tr("Avec différentes méthodes numériques cette application simule le phénomène de coup de Bélier ; \n")+
            "Ver. "+ APP_VERSION +tr(" sur Linux, Windows et Android ; \n")+
            "("+ QString("%1").arg(BLD_DATE) +tr(") ; ")+
            "\n HAFIANE Mohamed ; e-mail"+ tr(" pour (feedback) :")+" <a href=\"mailto:thakir.dz@gmail.com?"+
            "subject=About%20Application%20water_hammer_simulation\">thakir.dz@gmail.com</a>"+
            tr(" ou ")+
            "<a href=\"mailto:mohammed.hafiane@univ-saida.dz?subject=About%20Application%20water_hammer_simulation\">mohammed.hafiane@univ-saida.dz</a>"+" ;\n\n"+
            tr("Page web : ")+
            "<a href='https://sites.google.com/site/courshaf'>https://sites.google.com/site/courshaf</a>"+" ;\n\n"+
            tr("Programmé avec C++ (mingw64) avec comme IDE (Qt Creator) et avec ")+
            " Qt Ver. " +QT_VERSION_STR;

    msgBox.setText(pubabout);
    msgBox.exec();
}
#endif



