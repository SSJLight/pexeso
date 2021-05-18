#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <bits/stdc++.h>
#include <string>
#include <windows.h>
#include <QTimer>
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QPushButton* previousTile;
    QPushButton* currentTile;
    int pole[16]={1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8};
    bool zacalokolo;
    int zbyvaparu;


private slots:
    void on_start_clicked();
    void zacitHru();
    void klikKarticky();
    void priradCislo();
    void randomizer();
    void shuffle_array(int arr[], int n);
    void vysledekkola();
    void obnovenikarticek();
private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
