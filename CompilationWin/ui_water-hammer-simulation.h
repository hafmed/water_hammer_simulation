/********************************************************************************
** Form generated from reading UI file 'water-hammer-simulation.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WATER_2D_HAMMER_2D_SIMULATION_H
#define UI_WATER_2D_HAMMER_2D_SIMULATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot/qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_water_hammer_simulation
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_StartAnimation;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *checkBox_ViteseAnimLente;
    QCheckBox *checkBox_ViteseAnimRapide;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinBox_tempsSimulation;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_15;
    QDoubleSpinBox *doubleSpinBox_Tclose;
    QLabel *label_16;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QSpinBox *spinBox_nparts;
    QLabel *label_12;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_47;
    QDoubleSpinBox *lineEdit_C;
    QLabel *label_17;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_51;
    QDoubleSpinBox *lineEdit_f;
    QLabel *label_21;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_46;
    QDoubleSpinBox *lineEdit_D;
    QLabel *label_14;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_48;
    QDoubleSpinBox *lineEdit_L;
    QLabel *label_18;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_50;
    QDoubleSpinBox *lineEdit_Ho;
    QLabel *label_20;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_49;
    QDoubleSpinBox *lineEdit_Vo;
    QLabel *label_19;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_6;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_12;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_copy_table_in_Clipboard;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_14;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_5;
    QSlider *horizontalSlider_k;
    QLabel *label_tempsSimulation;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_13;
    QRadioButton *radioButton_H;
    QRadioButton *radioButton_V;
    QLabel *label_TempsRetour;
    QStackedWidget *stackedWidget;
    QWidget *page_3;
    QVBoxLayout *verticalLayout_2;
    QCustomPlot *customPlot;
    QWidget *page_4;
    QVBoxLayout *verticalLayout_3;
    QCustomPlot *customPlot_2;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *water_hammer_simulation)
    {
        if (water_hammer_simulation->objectName().isEmpty())
            water_hammer_simulation->setObjectName(QString::fromUtf8("water_hammer_simulation"));
        water_hammer_simulation->resize(668, 701);
        water_hammer_simulation->setMinimumSize(QSize(0, 701));
        water_hammer_simulation->setAutoFillBackground(false);
        centralWidget = new QWidget(water_hammer_simulation);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton_StartAnimation = new QPushButton(centralWidget);
        pushButton_StartAnimation->setObjectName(QString::fromUtf8("pushButton_StartAnimation"));

        verticalLayout->addWidget(pushButton_StartAnimation);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setMaximumSize(QSize(16777215, 235));
        tabWidget->setAutoFillBackground(false);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_4 = new QVBoxLayout(tab);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QFont font;
        font.setPointSize(8);
        font.setItalic(false);
        label_4->setFont(font);

        horizontalLayout_11->addWidget(label_4);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        checkBox_ViteseAnimLente = new QCheckBox(tab);
        checkBox_ViteseAnimLente->setObjectName(QString::fromUtf8("checkBox_ViteseAnimLente"));
        checkBox_ViteseAnimLente->setAutoExclusive(true);

        horizontalLayout_4->addWidget(checkBox_ViteseAnimLente);

        checkBox_ViteseAnimRapide = new QCheckBox(tab);
        checkBox_ViteseAnimRapide->setObjectName(QString::fromUtf8("checkBox_ViteseAnimRapide"));
        checkBox_ViteseAnimRapide->setChecked(true);
        checkBox_ViteseAnimRapide->setAutoExclusive(true);

        horizontalLayout_4->addWidget(checkBox_ViteseAnimRapide);


        horizontalLayout_11->addLayout(horizontalLayout_4);


        verticalLayout_4->addLayout(horizontalLayout_11);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(16777215, 21));

        horizontalLayout->addWidget(label);

        spinBox_tempsSimulation = new QSpinBox(tab);
        spinBox_tempsSimulation->setObjectName(QString::fromUtf8("spinBox_tempsSimulation"));
        spinBox_tempsSimulation->setMaximumSize(QSize(100, 21));
        spinBox_tempsSimulation->setAlignment(Qt::AlignCenter);
        spinBox_tempsSimulation->setMinimum(1);
        spinBox_tempsSimulation->setMaximum(3600000);
        spinBox_tempsSimulation->setValue(180);

        horizontalLayout->addWidget(spinBox_tempsSimulation);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(16777215, 21));

        horizontalLayout->addWidget(label_2);


        horizontalLayout_9->addLayout(horizontalLayout);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_15 = new QLabel(tab);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setMaximumSize(QSize(16777215, 21));

        horizontalLayout_8->addWidget(label_15);

        doubleSpinBox_Tclose = new QDoubleSpinBox(tab);
        doubleSpinBox_Tclose->setObjectName(QString::fromUtf8("doubleSpinBox_Tclose"));
        doubleSpinBox_Tclose->setMaximumSize(QSize(100, 21));
        doubleSpinBox_Tclose->setAlignment(Qt::AlignCenter);
        doubleSpinBox_Tclose->setDecimals(1);
        doubleSpinBox_Tclose->setMinimum(0.000000000000000);
        doubleSpinBox_Tclose->setMaximum(3600.000000000000000);
        doubleSpinBox_Tclose->setSingleStep(0.100000000000000);
        doubleSpinBox_Tclose->setValue(1.000000000000000);

        horizontalLayout_8->addWidget(doubleSpinBox_Tclose);

        label_16 = new QLabel(tab);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setMaximumSize(QSize(16777215, 21));

        horizontalLayout_8->addWidget(label_16);


        horizontalLayout_9->addLayout(horizontalLayout_8);


        verticalLayout_4->addLayout(horizontalLayout_9);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(16777215, 21));

        horizontalLayout_2->addWidget(label_3);

        spinBox_nparts = new QSpinBox(tab);
        spinBox_nparts->setObjectName(QString::fromUtf8("spinBox_nparts"));
        spinBox_nparts->setMaximumSize(QSize(100, 21));
        spinBox_nparts->setAlignment(Qt::AlignCenter);
        spinBox_nparts->setMinimum(1);
        spinBox_nparts->setMaximum(100000);
        spinBox_nparts->setValue(8);

        horizontalLayout_2->addWidget(spinBox_nparts);

        label_12 = new QLabel(tab);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMaximumSize(QSize(16777215, 21));

        horizontalLayout_2->addWidget(label_12);


        verticalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_47 = new QLabel(tab);
        label_47->setObjectName(QString::fromUtf8("label_47"));
        label_47->setMaximumSize(QSize(16777215, 21));

        horizontalLayout_3->addWidget(label_47);

        lineEdit_C = new QDoubleSpinBox(tab);
        lineEdit_C->setObjectName(QString::fromUtf8("lineEdit_C"));
        lineEdit_C->setMinimumSize(QSize(0, 31));
        lineEdit_C->setMaximumSize(QSize(16777215, 45));
        lineEdit_C->setInputMethodHints(Qt::ImhFormattedNumbersOnly|Qt::ImhPreferNumbers);
        lineEdit_C->setAlignment(Qt::AlignCenter);
        lineEdit_C->setButtonSymbols(QAbstractSpinBox::NoButtons);
        lineEdit_C->setDecimals(2);
        lineEdit_C->setMinimum(1.000000000000000);
        lineEdit_C->setMaximum(100000.000000000000000);
        lineEdit_C->setSingleStep(0.000010000000000);
        lineEdit_C->setValue(761.960000000000036);

        horizontalLayout_3->addWidget(lineEdit_C);

        label_17 = new QLabel(tab);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setMaximumSize(QSize(16777215, 21));

        horizontalLayout_3->addWidget(label_17);


        horizontalLayout_7->addLayout(horizontalLayout_3);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setSpacing(6);
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        label_51 = new QLabel(tab);
        label_51->setObjectName(QString::fromUtf8("label_51"));

        horizontalLayout_21->addWidget(label_51);

        lineEdit_f = new QDoubleSpinBox(tab);
        lineEdit_f->setObjectName(QString::fromUtf8("lineEdit_f"));
        lineEdit_f->setMinimumSize(QSize(0, 31));
        lineEdit_f->setInputMethodHints(Qt::ImhFormattedNumbersOnly|Qt::ImhPreferNumbers);
        lineEdit_f->setAlignment(Qt::AlignCenter);
        lineEdit_f->setButtonSymbols(QAbstractSpinBox::NoButtons);
        lineEdit_f->setDecimals(5);
        lineEdit_f->setMinimum(0.000000000000000);
        lineEdit_f->setMaximum(1.000000000000000);
        lineEdit_f->setSingleStep(0.000010000000000);
        lineEdit_f->setValue(0.020000000000000);

        horizontalLayout_21->addWidget(lineEdit_f);

        label_21 = new QLabel(tab);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setMaximumSize(QSize(16777215, 21));

        horizontalLayout_21->addWidget(label_21);


        horizontalLayout_7->addLayout(horizontalLayout_21);


        verticalLayout_4->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label_46 = new QLabel(tab);
        label_46->setObjectName(QString::fromUtf8("label_46"));

        horizontalLayout_16->addWidget(label_46);

        lineEdit_D = new QDoubleSpinBox(tab);
        lineEdit_D->setObjectName(QString::fromUtf8("lineEdit_D"));
        lineEdit_D->setMinimumSize(QSize(0, 31));
        lineEdit_D->setMaximumSize(QSize(16777215, 30));
        lineEdit_D->setInputMethodHints(Qt::ImhFormattedNumbersOnly|Qt::ImhPreferNumbers);
        lineEdit_D->setAlignment(Qt::AlignCenter);
        lineEdit_D->setButtonSymbols(QAbstractSpinBox::NoButtons);
        lineEdit_D->setDecimals(3);
        lineEdit_D->setMinimum(0.001000000000000);
        lineEdit_D->setMaximum(360.000000000000000);
        lineEdit_D->setSingleStep(0.000010000000000);
        lineEdit_D->setValue(0.763000000000000);

        horizontalLayout_16->addWidget(lineEdit_D);

        label_14 = new QLabel(tab);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setMaximumSize(QSize(16777215, 21));

        horizontalLayout_16->addWidget(label_14);


        horizontalLayout_6->addLayout(horizontalLayout_16);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        label_48 = new QLabel(tab);
        label_48->setObjectName(QString::fromUtf8("label_48"));

        horizontalLayout_18->addWidget(label_48);

        lineEdit_L = new QDoubleSpinBox(tab);
        lineEdit_L->setObjectName(QString::fromUtf8("lineEdit_L"));
        lineEdit_L->setMinimumSize(QSize(0, 31));
        lineEdit_L->setInputMethodHints(Qt::ImhFormattedNumbersOnly|Qt::ImhPreferNumbers);
        lineEdit_L->setAlignment(Qt::AlignCenter);
        lineEdit_L->setButtonSymbols(QAbstractSpinBox::NoButtons);
        lineEdit_L->setDecimals(2);
        lineEdit_L->setMinimum(0.010000000000000);
        lineEdit_L->setMaximum(100000.000000000000000);
        lineEdit_L->setSingleStep(0.000010000000000);
        lineEdit_L->setValue(1523.900000000000091);

        horizontalLayout_18->addWidget(lineEdit_L);

        label_18 = new QLabel(tab);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setMaximumSize(QSize(16777215, 21));

        horizontalLayout_18->addWidget(label_18);


        horizontalLayout_6->addLayout(horizontalLayout_18);


        verticalLayout_4->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        label_50 = new QLabel(tab);
        label_50->setObjectName(QString::fromUtf8("label_50"));

        horizontalLayout_20->addWidget(label_50);

        lineEdit_Ho = new QDoubleSpinBox(tab);
        lineEdit_Ho->setObjectName(QString::fromUtf8("lineEdit_Ho"));
        lineEdit_Ho->setMinimumSize(QSize(0, 31));
        lineEdit_Ho->setInputMethodHints(Qt::ImhFormattedNumbersOnly|Qt::ImhPreferNumbers);
        lineEdit_Ho->setAlignment(Qt::AlignCenter);
        lineEdit_Ho->setButtonSymbols(QAbstractSpinBox::NoButtons);
        lineEdit_Ho->setDecimals(2);
        lineEdit_Ho->setMinimum(0.010000000000000);
        lineEdit_Ho->setMaximum(100000.000000000000000);
        lineEdit_Ho->setSingleStep(0.000010000000000);
        lineEdit_Ho->setValue(218.069999999999993);

        horizontalLayout_20->addWidget(lineEdit_Ho);

        label_20 = new QLabel(tab);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setMaximumSize(QSize(16777215, 21));

        horizontalLayout_20->addWidget(label_20);


        horizontalLayout_5->addLayout(horizontalLayout_20);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        label_49 = new QLabel(tab);
        label_49->setObjectName(QString::fromUtf8("label_49"));

        horizontalLayout_19->addWidget(label_49);

        lineEdit_Vo = new QDoubleSpinBox(tab);
        lineEdit_Vo->setObjectName(QString::fromUtf8("lineEdit_Vo"));
        lineEdit_Vo->setMinimumSize(QSize(0, 31));
        lineEdit_Vo->setInputMethodHints(Qt::ImhFormattedNumbersOnly|Qt::ImhPreferNumbers);
        lineEdit_Vo->setAlignment(Qt::AlignCenter);
        lineEdit_Vo->setButtonSymbols(QAbstractSpinBox::NoButtons);
        lineEdit_Vo->setDecimals(3);
        lineEdit_Vo->setMinimum(0.001000000000000);
        lineEdit_Vo->setMaximum(1000.000000000000000);
        lineEdit_Vo->setSingleStep(0.000010000000000);
        lineEdit_Vo->setValue(1.523000000000000);

        horizontalLayout_19->addWidget(lineEdit_Vo);

        label_19 = new QLabel(tab);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setMaximumSize(QSize(16777215, 21));

        horizontalLayout_19->addWidget(label_19);


        horizontalLayout_5->addLayout(horizontalLayout_19);


        verticalLayout_4->addLayout(horizontalLayout_5);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_5 = new QVBoxLayout(tab_2);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/icons/water-hammer-simulation_Reservoir.png")));
        label_6->setScaledContents(true);
        label_6->setWordWrap(false);

        verticalLayout_5->addWidget(label_6);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_6 = new QVBoxLayout(tab_3);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer);

        pushButton_copy_table_in_Clipboard = new QPushButton(tab_3);
        pushButton_copy_table_in_Clipboard->setObjectName(QString::fromUtf8("pushButton_copy_table_in_Clipboard"));

        horizontalLayout_12->addWidget(pushButton_copy_table_in_Clipboard);


        verticalLayout_6->addLayout(horizontalLayout_12);

        tableWidget = new QTableWidget(tab_3);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setMinimumSize(QSize(350, 0));
        tableWidget->setEditTriggers(QAbstractItemView::AllEditTriggers);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectItems);

        verticalLayout_6->addWidget(tableWidget);

        tabWidget->addTab(tab_3, QString());

        verticalLayout->addWidget(tabWidget);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_10->addWidget(label_5);

        horizontalSlider_k = new QSlider(centralWidget);
        horizontalSlider_k->setObjectName(QString::fromUtf8("horizontalSlider_k"));
        horizontalSlider_k->setAutoFillBackground(true);
        horizontalSlider_k->setMaximum(80);
        horizontalSlider_k->setOrientation(Qt::Horizontal);
        horizontalSlider_k->setInvertedAppearance(false);
        horizontalSlider_k->setInvertedControls(false);
        horizontalSlider_k->setTickPosition(QSlider::NoTicks);
        horizontalSlider_k->setTickInterval(1);

        horizontalLayout_10->addWidget(horizontalSlider_k);


        horizontalLayout_14->addLayout(horizontalLayout_10);

        label_tempsSimulation = new QLabel(centralWidget);
        label_tempsSimulation->setObjectName(QString::fromUtf8("label_tempsSimulation"));
        label_tempsSimulation->setMaximumSize(QSize(16777215, 25));
        label_tempsSimulation->setAlignment(Qt::AlignCenter);

        horizontalLayout_14->addWidget(label_tempsSimulation);


        verticalLayout->addLayout(horizontalLayout_14);

        comboBox = new QComboBox(centralWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        verticalLayout->addWidget(comboBox);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        radioButton_H = new QRadioButton(centralWidget);
        radioButton_H->setObjectName(QString::fromUtf8("radioButton_H"));
        radioButton_H->setChecked(true);

        horizontalLayout_13->addWidget(radioButton_H);

        radioButton_V = new QRadioButton(centralWidget);
        radioButton_V->setObjectName(QString::fromUtf8("radioButton_V"));

        horizontalLayout_13->addWidget(radioButton_V);


        verticalLayout->addLayout(horizontalLayout_13);

        label_TempsRetour = new QLabel(centralWidget);
        label_TempsRetour->setObjectName(QString::fromUtf8("label_TempsRetour"));
        label_TempsRetour->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_TempsRetour);

        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        verticalLayout_2 = new QVBoxLayout(page_3);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        customPlot = new QCustomPlot(page_3);
        customPlot->setObjectName(QString::fromUtf8("customPlot"));
        customPlot->setEnabled(true);
        customPlot->setMinimumSize(QSize(0, 0));

        verticalLayout_2->addWidget(customPlot);

        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        verticalLayout_3 = new QVBoxLayout(page_4);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        customPlot_2 = new QCustomPlot(page_4);
        customPlot_2->setObjectName(QString::fromUtf8("customPlot_2"));
        customPlot_2->setEnabled(true);

        verticalLayout_3->addWidget(customPlot_2);

        stackedWidget->addWidget(page_4);

        verticalLayout->addWidget(stackedWidget);

        water_hammer_simulation->setCentralWidget(centralWidget);
        stackedWidget->raise();
        pushButton_StartAnimation->raise();
        comboBox->raise();
        label_TempsRetour->raise();
        tabWidget->raise();
        statusBar = new QStatusBar(water_hammer_simulation);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        water_hammer_simulation->setStatusBar(statusBar);

        retranslateUi(water_hammer_simulation);
        QObject::connect(comboBox, SIGNAL(currentIndexChanged(int)), stackedWidget, SLOT(setCurrentIndex(int)));

        tabWidget->setCurrentIndex(0);
        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(water_hammer_simulation);
    } // setupUi

    void retranslateUi(QMainWindow *water_hammer_simulation)
    {
        water_hammer_simulation->setWindowTitle(QApplication::translate("water_hammer_simulation", "QCustomPlot plot examples", nullptr));
        pushButton_StartAnimation->setText(QApplication::translate("water_hammer_simulation", "Start Animation", nullptr));
        label_4->setText(QApplication::translate("water_hammer_simulation", "Vitesse d'Animation", nullptr));
        checkBox_ViteseAnimLente->setText(QApplication::translate("water_hammer_simulation", "Lente", nullptr));
        checkBox_ViteseAnimRapide->setText(QApplication::translate("water_hammer_simulation", "Rapide", nullptr));
        label->setText(QApplication::translate("water_hammer_simulation", "Tmax", nullptr));
#ifndef QT_NO_TOOLTIP
        spinBox_tempsSimulation->setToolTip(QApplication::translate("water_hammer_simulation", "Le temps total de simulation", nullptr));
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("water_hammer_simulation", "s", nullptr));
        label_15->setText(QApplication::translate("water_hammer_simulation", "Tclose", nullptr));
#ifndef QT_NO_TOOLTIP
        doubleSpinBox_Tclose->setToolTip(QApplication::translate("water_hammer_simulation", "Le temps de fermeture de la vanne", nullptr));
#endif // QT_NO_TOOLTIP
        label_16->setText(QApplication::translate("water_hammer_simulation", "s", nullptr));
        label_3->setText(QApplication::translate("water_hammer_simulation", "nparts", nullptr));
#ifndef QT_NO_TOOLTIP
        spinBox_nparts->setToolTip(QApplication::translate("water_hammer_simulation", "Le nombre d'intervalles dans l'axe de la conduite (Nombre de points -1)", nullptr));
#endif // QT_NO_TOOLTIP
        label_12->setText(QString());
        label_47->setText(QApplication::translate("water_hammer_simulation", "C", nullptr));
#ifndef QT_NO_TOOLTIP
        lineEdit_C->setToolTip(QApplication::translate("water_hammer_simulation", "La c\303\251l\303\251rit\303\251  d'onde", nullptr));
#endif // QT_NO_TOOLTIP
        label_17->setText(QApplication::translate("water_hammer_simulation", "m/s", nullptr));
        label_51->setText(QApplication::translate("water_hammer_simulation", "f", nullptr));
#ifndef QT_NO_TOOLTIP
        lineEdit_f->setToolTip(QApplication::translate("water_hammer_simulation", "Le coefficient de frottement de Dracy-Weisbach : Top=1/8.f.rol.V.abs(V)", nullptr));
#endif // QT_NO_TOOLTIP
        label_21->setText(QString());
        label_46->setText(QApplication::translate("water_hammer_simulation", "D", nullptr));
#ifndef QT_NO_TOOLTIP
        lineEdit_D->setToolTip(QApplication::translate("water_hammer_simulation", "Le diam\303\250tre  de la conduite", nullptr));
#endif // QT_NO_TOOLTIP
        label_14->setText(QApplication::translate("water_hammer_simulation", "m", nullptr));
        label_48->setText(QApplication::translate("water_hammer_simulation", "L", nullptr));
#ifndef QT_NO_TOOLTIP
        lineEdit_L->setToolTip(QApplication::translate("water_hammer_simulation", "La longueur  de la conduite", nullptr));
#endif // QT_NO_TOOLTIP
        label_18->setText(QApplication::translate("water_hammer_simulation", "m", nullptr));
        label_50->setText(QApplication::translate("water_hammer_simulation", "Ho", nullptr));
#ifndef QT_NO_TOOLTIP
        lineEdit_Ho->setToolTip(QApplication::translate("water_hammer_simulation", "La hauteur d'eau dans le r\303\251servoir", nullptr));
#endif // QT_NO_TOOLTIP
        label_20->setText(QApplication::translate("water_hammer_simulation", "m", nullptr));
        label_49->setText(QApplication::translate("water_hammer_simulation", "Vo", nullptr));
#ifndef QT_NO_TOOLTIP
        lineEdit_Vo->setToolTip(QApplication::translate("water_hammer_simulation", "La vitesse intiale d'eau dans la conduite", nullptr));
#endif // QT_NO_TOOLTIP
        label_19->setText(QApplication::translate("water_hammer_simulation", "m/s", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("water_hammer_simulation", "Param\303\250tres de simulation", nullptr));
        label_6->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("water_hammer_simulation", "Configration physique", nullptr));
        pushButton_copy_table_in_Clipboard->setText(QApplication::translate("water_hammer_simulation", "Copy tableau dans presse-papiers", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("water_hammer_simulation", "Info", nullptr));
        label_5->setText(QApplication::translate("water_hammer_simulation", "t (s)", nullptr));
        label_tempsSimulation->setText(QApplication::translate("water_hammer_simulation", "TextLabel", nullptr));
        comboBox->setItemText(0, QApplication::translate("water_hammer_simulation", "Animation", nullptr));
        comboBox->setItemText(1, QApplication::translate("water_hammer_simulation", "Validation th\303\251orique (Vanne)", nullptr));

        radioButton_H->setText(QApplication::translate("water_hammer_simulation", "H", nullptr));
        radioButton_V->setText(QApplication::translate("water_hammer_simulation", "V", nullptr));
        label_TempsRetour->setText(QApplication::translate("water_hammer_simulation", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class water_hammer_simulation: public Ui_water_hammer_simulation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WATER_2D_HAMMER_2D_SIMULATION_H
