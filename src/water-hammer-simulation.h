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

    double (*v)[10000] = new double[100000][10000];
    double (*h)[10000] = new double[100000][10000];

    double t,x,dx,daltat;


public slots:
    void plotHAF(int k);
    void changeintervalTimeAnimation(int interv);
    void  plotHAFTime();
    void  StartAnimation();
    void  intialplotHAF();
    void  plotHAFVanne();
    void  recalcul();

    void copy_table_in_Clipboard();
    void affichage_resultats();

private:
    Ui::water_hammer_simulation *ui;
};

#endif // CB_H
