#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->karticka01, SIGNAL(clicked()), this, SLOT(klikKarticky()));
    connect(ui->karticka02, SIGNAL(clicked()), this, SLOT(klikKarticky()));
    connect(ui->karticka03, SIGNAL(clicked()), this, SLOT(klikKarticky()));
    connect(ui->karticka04, SIGNAL(clicked()), this, SLOT(klikKarticky()));
    connect(ui->karticka05, SIGNAL(clicked()), this, SLOT(klikKarticky()));
    connect(ui->karticka06, SIGNAL(clicked()), this, SLOT(klikKarticky()));
    connect(ui->karticka07, SIGNAL(clicked()), this, SLOT(klikKarticky()));
    connect(ui->karticka08, SIGNAL(clicked()), this, SLOT(klikKarticky()));
    connect(ui->karticka09, SIGNAL(clicked()), this, SLOT(klikKarticky()));
    connect(ui->karticka10, SIGNAL(clicked()), this, SLOT(klikKarticky()));
    connect(ui->karticka11, SIGNAL(clicked()), this, SLOT(klikKarticky()));
    connect(ui->karticka12, SIGNAL(clicked()), this, SLOT(klikKarticky()));
    connect(ui->karticka13, SIGNAL(clicked()), this, SLOT(klikKarticky()));
    connect(ui->karticka14, SIGNAL(clicked()), this, SLOT(klikKarticky()));
    connect(ui->karticka15, SIGNAL(clicked()), this, SLOT(klikKarticky()));
    connect(ui->karticka16, SIGNAL(clicked()), this, SLOT(klikKarticky()));
    zacitHru();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_start_clicked()
{
    zacitHru();
}

void MainWindow::zacitHru()
{
    zacalokolo=false;
    zbyvaparu=8;
    randomizer();
    ui->gridLayout->setEnabled(true);
    QList<QPushButton *> btns =  ui->centralwidget->findChildren<QPushButton*>();
    foreach (QPushButton* b, btns) {
        b->setEnabled(true);
        b->setText("");
    }
    ui->start->setText("Restart hry");
}

void MainWindow::klikKarticky()
{
    currentTile=qobject_cast<QPushButton*>(sender());
    priradCislo();
    currentTile->setEnabled(false);
    if(!zacalokolo){
        previousTile=currentTile;
        zacalokolo=true;
    }else{
        vysledekkola();
        zacalokolo=false;
    }

}

void MainWindow::priradCislo()
{
    QString karticky=currentTile->objectName();
    int indexpole = karticky.midRef(8,2).toInt();
    currentTile->setText(QString::number(pole[indexpole-1]));
}

void MainWindow::randomizer()
{
    /*int i,j;
    for (i=0,j=1;i<17;i++) {
        pole[i]=j;
        if(j==(i+1)/2)
        {
            j++;
        }
    }*/
    shuffle_array(pole,16);
}

void MainWindow::shuffle_array(int arr[], int n)
{
    srand(time(0));
    random_shuffle(arr, arr + n);
}

void MainWindow::vysledekkola()
{
    if(currentTile->text()==previousTile->text())
    {
        zbyvaparu--;
    }else{
        ui->centralwidget->setEnabled(false);
        QTimer::singleShot(1000, this, SLOT(obnovenikarticek()));
    }
}

void MainWindow::obnovenikarticek()
{
    currentTile->setText("");
    previousTile->setText("");

    currentTile->setEnabled(true);
    previousTile->setEnabled(true);

    ui->centralwidget->setEnabled(true);
}

