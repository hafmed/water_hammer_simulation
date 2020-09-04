// Metho_Approxi le 15-2-2017 Marche bien 17-7-2020

#include "water-hammer-simulation.h"
#include "ui_water-hammer-simulation.h"
#include <QDebug>
#include <QDesktopWidget>
#include <QScreen>
#include <QMessageBox>
#include <QMetaEnum>

#include <math.h>
#include <iostream>
#include <iostream>
#include <fstream>

#include <stdlib.h>

using namespace std;
#include <iomanip>

water_hammer_simulation::water_hammer_simulation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::water_hammer_simulation)
{
    ui->setupUi(this);
    ui->statusBar->showMessage("HAFIANE Mohamed (2019-2020) Ver: " APP_VERSION " Linux&Windows ; email : haftemp@gmail.com");
    setWindowTitle("Simulation du phénomène de coup de Bélier avec la méthode des caractéristiques");
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

    k=0;
    plotHAF(k);
    affichage_resultats();

    connect(timer, SIGNAL(timeout()), this, SLOT(plotHAFTime()));
    connect(ui->pushButton_StartAnimation, SIGNAL(clicked()), this, SLOT(StartAnimation()));

    connect(ui->checkBox_ViteseAnimLente, SIGNAL(stateChanged(int)), this, SLOT(changeintervalTimeAnimation(int)));
    connect(ui->checkBox_ViteseAnimRapide, SIGNAL(stateChanged(int)), this, SLOT(changeintervalTimeAnimation(int)));

    connect(ui->horizontalSlider_k, SIGNAL(valueChanged(int)), this, SLOT(plotHAF(int)));
    connect(ui->radioButton_H, SIGNAL(clicked()), this, SLOT(intialplotHAF()));
    connect(ui->radioButton_V, SIGNAL(clicked()), this, SLOT(intialplotHAF()));

    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(plotHAFVanne()));
    connect(ui->radioButton_H, SIGNAL(clicked()), this, SLOT(plotHAFVanne()));
    connect(ui->radioButton_V, SIGNAL(clicked()), this, SLOT(plotHAFVanne()));

    connect(ui->doubleSpinBox_Tclose, SIGNAL(valueChanged(double)), this, SLOT(recalcul()));
    connect(ui->spinBox_tempsSimulation, SIGNAL(valueChanged(int)), this, SLOT(recalcul()));
    connect(ui->spinBox_nparts, SIGNAL(valueChanged(int)), this, SLOT(recalcul()));
    connect(ui->lineEdit_C, SIGNAL(valueChanged(double)), this, SLOT(recalcul()));
    connect(ui->lineEdit_D, SIGNAL(valueChanged(double)), this, SLOT(recalcul()));
    connect(ui->lineEdit_f, SIGNAL(valueChanged(double)), this, SLOT(recalcul()));

    connect(ui->lineEdit_Ho, SIGNAL(valueChanged(double)), this, SLOT(recalcul()));
    connect(ui->lineEdit_L, SIGNAL(valueChanged(double)), this, SLOT(recalcul()));
    connect(ui->lineEdit_Vo, SIGNAL(valueChanged(double)), this, SLOT(recalcul()));

    // HAF 15-7-2020
    connect(ui->pushButton_copy_table_in_Clipboard, SIGNAL(clicked()), this, SLOT(copy_table_in_Clipboard()));
    pd.setWindowModality(Qt::ApplicationModal);
    pd.setLabelText("Calcul en cours, Veuillez patienter!");
    pd.setCancelButtonText("Annuler");
    pd.setFocus();
    pd.setAutoReset(true);
    pd.setEnabled(true);
}
water_hammer_simulation::~water_hammer_simulation()
{
    delete ui;
}
void water_hammer_simulation::recalcul()
{
    ui->pushButton_StartAnimation->setText("Start Animation");
    timer->stop();
    pd.reset();
    ui->customPlot_2->clearItems();
    intialplotHAF();
    plotHAFVanne();
    affichage_resultats();
}
void water_hammer_simulation::changeintervalTimeAnimation(int interv)
{
    k=0;
    if (ui->checkBox_ViteseAnimLente->isChecked()){
        timer->setInterval(1000); //1s
    }
    if (ui->checkBox_ViteseAnimRapide->isChecked()){
        timer->setInterval(1);
    }
}
void water_hammer_simulation::StartAnimation()
{
    k=ui->horizontalSlider_k->value();
    if (ui->checkBox_ViteseAnimLente->isChecked()){
        timer->setInterval(1000); //1s
    }
    if (ui->checkBox_ViteseAnimRapide->isChecked()){
        timer->setInterval(1);
    }

    if (!timer->isActive()){
        double tmax=ui->spinBox_tempsSimulation->value();
        if ((k+1)*daltat>tmax) k=0;

        timer->start();

        ui->pushButton_StartAnimation->setText("Stop Animation");
    }else{
        timer->stop();
        ui->pushButton_StartAnimation->setText("Start Animation");
    }
    ui->comboBox->setCurrentIndex(0);
    ui->horizontalSlider_k->setValue(k);
}
void water_hammer_simulation::plotHAFTime()
{
    k=k+1;
    plotHAF(k);
}
void water_hammer_simulation::intialplotHAF()
{
    k=0;
    plotHAF(k);
    ui->horizontalSlider_k->setValue(0);
    affichage_resultats();
}
void water_hammer_simulation::plotHAF(int k)
{
    QString temps;

    // Entrées
    int nparts=ui->spinBox_nparts->value(); //8; // Le nombre d'intervalles dans l'axe de la conduite (n-1)
    double c=ui->lineEdit_C->value(); //761.96;        //Célérité  d'onde
    double g=9.81;          //Accélération  de la pesanteur
    double d=ui->lineEdit_D->value(); //0.763;         //Diamètre  de la conduite
    double L=ui->lineEdit_L->value(); //1523.9;        //Longueur  de la conduite
    double f=ui->lineEdit_f->value(); //0.02;          //Coefficient de frottement de Dracy-Weisbach
    double v0=ui->lineEdit_Vo->value(); //1.523;        //Vitesse intiale
    double h0=ui->lineEdit_Ho->value(); //218.07;       //La hauteur d'eau dans le réservoir
    double tmax=ui->spinBox_tempsSimulation->value(); //20        //Temps total de simulation
    double tclos=ui->doubleSpinBox_Tclose->value(); //10;        //Temps de fermeture de la vanne
    dx=L/nparts;
    daltat=dx/c;
    int    m=tmax/daltat;

    // Conditions initiales
    for (i=0;i<=nparts;i++)
    {
        j=0;
        v[j][i]=v0;
        h[j][i]=h0-i*f*v0*v0*dx/(2*g*d);
    }
    if (!timer->isActive()){
        pd.setRange(0,m-1);
    }
    t=daltat;
    for (j=1;j<=m;j++)
    {
        if (!timer->isActive()){
            pd.setValue(j);
            if(pd.wasCanceled()){break; }
        }
        i=0;
        h[j][i]=h0;
        v[j][i]=v[j-1][i+1]+g/c*(h[j][i]-h[j-1][i+1])-f*daltat/(2*d)*v[j-1][i+1]*fabs(v[j-1][i+1]);

        for (i=1;i<=nparts-1;i++)
        {
            v[j][i]=0.5*((v[j-1][i-1]+v[j-1][i+1])+g/c*(h[j-1][i-1]-h[j-1][i+1])-
                    (f*daltat)/(2*d)*(v[j-1][i-1]*fabs(v[j-1][i-1])+v[j-1][i+1]*fabs(v[j-1][i+1])));
            h[j][i]=0.5*(c/g*(v[j-1][i-1]-v[j-1][i+1])+(h[j-1][i-1]+h[j-1][i+1])-
                    c/g*(f*daltat)/(2*d)*(v[j-1][i-1]*fabs(v[j-1][i-1])-v[j-1][i+1]*fabs(v[j-1][i+1])));
        }

        i=nparts;
        if (t>=tclos)
        {
            v[j][i]=0;
        }
        else
        {
            v[j][i]=v0*(1-(t/tclos));
        }
        h[j][i]=h[j-1][i-1]+c/g*(v[j-1][i-1]-v[j][i]-f*daltat/(2*d)*v[j-1][i-1]*fabs(v[j-1][i-1]));

        t=t+daltat;

    }

    mcolones=nparts+1;
    nLignes=m+1;

    // Détermination Max et Mini de V et H
    double highH,lowH;
    double highV,lowV;
    highH=h[0][0];
    lowH=h[0][0];

    for(j=0;j<nLignes ;j++)
    {
        for(i=0;i<mcolones;i++)
        {
            if(h[j][i]>highH){
                highH=h[j][i];
            }else{
                if(h[j][i]<lowH){
                    lowH=h[j][i];
                }
            }
        }
    }
    QString minmaxh= "H, min="+QString::number(lowH)+" m"+ ", max="+QString::number(highH)+" m";
    ui->radioButton_H->setText(minmaxh);
    highV=v[0][0];
    lowV=v[0][0];

    for(j=0;j<nLignes ;++j)

        for(i=0;i<mcolones;++i)
        {
            if(v[j][i]>highV)
                highV=v[j][i];
            else
                if(v[j][i]<lowV)
                    lowV=v[j][i];
        }

    QString minmaxv= "V, min="+QString::number(lowV)+" m/s"+ ", max="+QString::number(highV)+" m/s";
    ui->radioButton_V->setText(minmaxv);

    if ((k+1)*daltat>tmax){
        ui->pushButton_StartAnimation->setText("Start Animation");
        timer->stop();
    }

    ui->horizontalSlider_k->setMaximum(nLignes-1);
    //------------------------------------------------
    QVector<double> x(mcolones), y(mcolones);
    for (i=0; i<mcolones; ++i)
    {
        x[i]=i*dx/L;
        if (ui->radioButton_H->isChecked()){
            y[i] = h[k][i] ;
        }else{
            y[i] = v[k][i] ;
        }
    }

    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setName("Simulation water_hammer_simulation");
    ui->customPlot->graph(0)->setData(x, y);
    ui->customPlot->xAxis->setLabel("x/L (-)");
    ui->customPlot->xAxis->setRange(0, 1);
    if (ui->radioButton_H->isChecked()){
        ui->customPlot->yAxis->setLabel("H (m)");
        ui->customPlot->yAxis->setRange(lowH-0.05*fabs(lowH), highH+0.05*fabs(highH));
    }else{
        ui->customPlot->yAxis->setLabel("V (m/s)");
        ui->customPlot->yAxis->setRange(lowV-0.05*fabs(lowV), highV+0.05*fabs(highV));
    }

    ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::red, Qt::white, 7));
    ui->customPlot->axisRect()->setupFullAxesBox();
    ui->customPlot->legend->setVisible(false);

    temps= "t="+QString::number(k*daltat, 'f', 2)+" s";
    ui->label_tempsSimulation->setText(temps);
    ui->horizontalSlider_k->setValue(k);

    ui->label_TempsRetour->setVisible(false);
    ui->customPlot->replot();
    pd.close();
}

void water_hammer_simulation::plotHAFVanne()
{
    // Entrées
    int nparts=ui->spinBox_nparts->value(); //8;
    double c=ui->lineEdit_C->value(); //761.96;        //Célérité  d'onde
    double g=9.81;          //Accélération  de la pesanteur
    double d=ui->lineEdit_D->value(); //0.763;         //Diamètre  de la conduite
    double L=ui->lineEdit_L->value(); //1523.9;        //Longueur  de la conduite
    double f=ui->lineEdit_f->value(); //0.02;          //Coefficient de frottement
    double v0=ui->lineEdit_Vo->value(); //1.523;        //Vitesse intiale
    double h0=ui->lineEdit_Ho->value(); //218.07;       //La hauteur d'eau dans le réservoir
    double tmax=ui->spinBox_tempsSimulation->value(); //20        //Temps total de simulation
    double tclos=ui->doubleSpinBox_Tclose->value(); //10;        //Temps de fermeture de la vanne
    dx=L/nparts;
    daltat=dx/c;
    int    m=tmax/daltat;

    mcolones=nparts+1;
    nLignes=m+1;

    // Conditions initiales
    for (i=0;i<=nparts;i++)
    {
        j=0;
        v[j][i]=v0;
        h[j][i]=h0-i*f*v0*v0*dx/(2*g*d);
    }
    // ----
    if (!timer->isActive()){
        pd.setRange(0,m);
    }
    t=daltat;
    for (j=1;j<=m;j++)
    {
        if (!timer->isActive()){
            pd.setValue(j);
            if(pd.wasCanceled()){break; }
        }
        i=0;
        h[j][i]=h0;
        v[j][i]=v[j-1][i+1]+g/c*(h[j][i]-h[j-1][i+1])-f*daltat/(2*d)*v[j-1][i+1]*fabs(v[j-1][i+1]);

        for (i=1;i<=nparts-1;i++)
        {
            v[j][i]=0.5*((v[j-1][i-1]+v[j-1][i+1])+g/c*(h[j-1][i-1]-h[j-1][i+1])-
                    (f*daltat)/(2*d)*(v[j-1][i-1]*fabs(v[j-1][i-1])+v[j-1][i+1]*fabs(v[j-1][i+1])));
            h[j][i]=0.5*(c/g*(v[j-1][i-1]-v[j-1][i+1])+(h[j-1][i-1]+h[j-1][i+1])-
                    c/g*(f*daltat)/(2*d)*(v[j-1][i-1]*fabs(v[j-1][i-1])-v[j-1][i+1]*fabs(v[j-1][i+1])));
        }

        i=nparts;
        if (t>=tclos)
        {
            v[j][i]=0;
        }
        else
        {
            v[j][i]=v0*(1-(t/tclos));
        }
        h[j][i]=h[j-1][i-1]+c/g*(v[j-1][i-1]-v[j][i]-f*daltat/(2*d)*v[j-1][i-1]*fabs(v[j-1][i-1]));
        t=t+daltat;
    }
    // Détermination Max et Mini de V et H
    double highH2,lowH2;
    double highV2,lowV2;
    highH2=h[0][0];
    lowH2=h[0][0];
    for(j=0;j<nLignes ;j++)
    {
        for(i=0;i<mcolones;i++)
        {
            if(h[j][i]>highH2){
                highH2=h[j][i];
            }else{
                if(h[j][i]<lowH2){
                    lowH2=h[j][i];
                }
            }
        }
    }
    QString minmaxh= "H, min="+QString::number(lowH2)+" m"+ ", max="+QString::number(highH2)+" m";
    ui->radioButton_H->setText(minmaxh);
    highV2=v[0][0];
    lowV2=v[0][0];

    for(j=0;j<nLignes ;++j)

        for(i=0;i<mcolones;++i)
        {
            if(v[j][i]>highV2)
                highV2=v[j][i];
            else
                if(v[j][i]<lowV2)
                    lowV2=v[j][i];
        }

    QString minmaxv= "V, min="+QString::number(lowV2)+" m/s"+ ", max="+QString::number(highV2)+" m/s";
    ui->radioButton_V->setText(minmaxv);

    //------------------------------------------------
    QVector<double> xx(nLignes), yy(nLignes);
    for (i=0; i<nLignes; ++i)
    {
        //x[i] = i*1;
        xx[i]=i*daltat/(2*L/c);
        if (ui->radioButton_H->isChecked()){
            yy[i] = h[i][nparts] ; //vanne
        }else{
            yy[i] = v[i][nparts] ;
        }
    }

    ui->customPlot_2->addGraph();
    ui->customPlot_2->graph(0)->setName("Validation water_hammer_simulation");
    ui->customPlot_2->graph(0)->setData(xx, yy);
    ui->customPlot_2->xAxis->setLabel("t/(2*L/c) (-)"); //HAF-25-7-2020
    ui->customPlot_2->xAxis->setRange(-tmax/(2*L/c)*0.1, tmax/(2*L/c)); //HAF-17-7-2020

    if (ui->radioButton_H->isChecked()){
        ui->customPlot_2->yAxis->setLabel("H (m)");
        ui->customPlot_2->yAxis->setRange(lowH2-0.05*fabs(lowH2), highH2+0.05*fabs(highH2));

        QCPItemText *textLabel = new QCPItemText(ui->customPlot_2);
        textLabel->setPositionAlignment(Qt::AlignTop|Qt::AlignHCenter);
        textLabel->position->setType(QCPItemPosition::ptAxisRectRatio);
        textLabel->position->setCoords(0.25,  .75); // place position at center/top of axis rect
        textLabel->setText("H_vanne(t=0)");
        textLabel->setFont(QFont(font().family(), 9)); // make font a bit larger
        textLabel->setPen(QPen(Qt::black)); // show black border around text

        // add the arrow:
        QCPItemLine *arrow = new QCPItemLine(ui->customPlot_2);
        // ---ui->customPlot_2->addItem(arrow);
        arrow->start->setParentAnchor(textLabel->top);
        arrow->end->setCoords(0,  h[0][nparts]); // point to (4, 1.6) in x-y-plot coordinates
        arrow->setHead(QCPLineEnding::esFlatArrow);

        // add the bracket at the top:
        QCPItemBracket *bracket = new QCPItemBracket(ui->customPlot_2);
        // ---ui->customPlot_2->addItem(bracket);
        bracket->left->setCoords(0, h[0][nparts]);

        bracket->setLength(13);

        // add the text label at the top:
        QCPItemText *wavePacketText = new QCPItemText(ui->customPlot_2);
        // ---ui->customPlot_2->addItem(wavePacketText);
        wavePacketText->position->setParentAnchor(bracket->center);
        wavePacketText->position->setCoords(-12.5, 0); // move 10 pixels to the top from bracket center anchor
        wavePacketText->setPositionAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        if (tclos>2*L/c){
            wavePacketText->setText("DP=Rol*2*L*V_0/Tclose");
            bracket->right->setCoords(0, h[0][nparts]+(1000*2*L*v0)/(1000*9.81*tclos));
        }else{
            wavePacketText->setText("DP=Rol*C*V_0");
            bracket->right->setCoords(0, h[0][nparts]+(1000*c*v0)/(1000*9.81));

            QCPItemBracket *bracket2 = new QCPItemBracket(ui->customPlot_2);
            // --- ui->customPlot_2->addItem(bracket2);
            bracket2->left->setCoords( 0, h[0][nparts]+(1000*c*v0)/(1000*9.81));

            bracket2->setLength(13);

            QCPItemText *wavePacketText2 = new QCPItemText(ui->customPlot_2);
            // ---ui->customPlot_2->addItem(wavePacketText2);
            wavePacketText2->position->setParentAnchor(bracket2->center);
            wavePacketText2->position->setCoords(-12.5, 0); // move 10 pixels to the top from bracket center anchor
            wavePacketText2->setPositionAlignment(Qt::AlignBottom|Qt::AlignHCenter);

            wavePacketText2->setText("DH");
            bracket2->right->setCoords(0, h[0][nparts]+(1000*c*v0)/(1000*9.81)+(h0-h[0][nparts]));
        }

        ui->label_TempsRetour->setVisible(true);
        ui->label_TempsRetour->setText(QString("Temps d'aller-retour de l'onde de pression (2*L/c)= %2 (s)")
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
    ui->customPlot_2->replot();
    pd.close();

}
void water_hammer_simulation::copy_table_in_Clipboard(){
    pressePapiers->setText(resultatsfr0);
}
void water_hammer_simulation::affichage_resultats(){
    int nparts=ui->spinBox_nparts->value();
    double c=ui->lineEdit_C->value();
    double L=ui->lineEdit_L->value();
    double tmax=ui->spinBox_tempsSimulation->value();

    dx=L/nparts;
    daltat=dx/c;

    int    m=tmax/daltat;

    mcolones=nparts+1;
    nLignes=m+1;

    /* Affichage */
    ofstream myfile;
    myfile.open ("returns_water_hammer_simulation.txt");

    QStringList Horizontalheadtext;
    QStringList Verticalheadtext;

    ui->tableWidget->setColumnCount(mcolones);
    ui->tableWidget->setRowCount(nLignes);

    for (j=0; j < nLignes  ; j++)
    {
        myfile<< "\n";
        for (i=0; i < mcolones ; i++){
            if (ui->radioButton_H->isChecked()){
                myfile << setprecision(6)<< h[j][i] << " ";
            }else{
                myfile << setprecision(6)<< v[j][i] << " ";
            }
        }
        myfile << endl;
    }

    t=0;
    x=0;
    for (j=0; j < nLignes  ; j++)
    {
        Horizontalheadtext+="x="+QString::number(x)+" (m)";
        x+=dx;
        for (i=0; i < mcolones ; i++){
            Verticalheadtext+="t="+QString::number(t)+" (s)";
            t+=daltat;
        }
    }

    ui->tableWidget->setStyleSheet("QTableView {selection-background-color: green;}");
    ui->tableWidget->setHorizontalHeaderLabels(Horizontalheadtext);
    ui->tableWidget->setVerticalHeaderLabels(Verticalheadtext);

    for (j=0; j < nLignes  ; j++)
    {
        for (i=0; i < mcolones ; i++)
            if (ui->radioButton_H->isChecked()){
                ui->tableWidget->setItem(j,i,new QTableWidgetItem(tr("%1").arg(h[j][i])));
            }else{
                ui->tableWidget->setItem(j,i,new QTableWidgetItem(tr("%1").arg(v[j][i])));
            }
    }
    resultatsfr0="";
    for (j=0; j < nLignes  ; j++)
    {
        resultatsfr0+="\n";
        for (i=0; i < mcolones ; i++)
            if (ui->radioButton_H->isChecked()){
                resultatsfr0+=QString::number(j)+"\t"+QString::number(h[j][i]);
            }else{
                resultatsfr0+=QString::number(j)+"\t"+QString::number(v[j][i]);             }
    }
}
