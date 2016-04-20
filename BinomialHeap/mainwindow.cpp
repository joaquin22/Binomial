#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "binomialheap.h"

BinomialHeap binomial(0);
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*BinomialHeap binomial(0);
    for(int i = 1; i <= 10;i++){
        binomial.Add(new Nodo(i));
    }

    binomial.Add(new Nodo(1));
    cout<<"menor: "<<binomial.menor_mayor->key<<endl;
    binomial.DeleteMin();

    binomial.Delete(2);

    binomial.PrintDot("ejemplo.dot");
    cout<<"menor: "<<binomial.menor_mayor->key<<endl;*/
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_Add_clicked()
{
    binomial.Add(new Nodo(ui->txt_Add->text().toInt()));
    binomial.Merge();
    ui->txt_Add->clear();
    ui->lbl_Min->setNum(binomial.menor_mayor->key);
    binomial.PrintDot("ejemplo.dot");
    system(" dot -Tpng ejemplo.dot -o ejemplo.png");
    QPixmap *MyPix = new QPixmap("ejemplo.png");
    ui->label->setPixmap(*MyPix);
    delete MyPix;
}

void MainWindow::on_pushButton_clicked()
{
    if(!binomial.hijos.empty()){
        binomial.Delete(ui->txt_Delete->text().toInt());
        ui->txt_Delete->clear();
        ui->lbl_Min->setNum(binomial.menor_mayor->key);
        binomial.PrintDot("ejemplo.dot");
        system(" dot -Tpng ejemplo.dot -o ejemplo.png");
        QPixmap *MyPix = new QPixmap("ejemplo.png");
        ui->label->setPixmap(*MyPix);
        delete MyPix;
    }else{
        ui->label->clear();
    }
}

void MainWindow::on_btn_Accept_clicked()
{
    int Datos = ui->txt_datos->text().toInt();
    for (int i = 1; i<=Datos;i++){
        binomial.Add(new Nodo(i));
        binomial.Merge();
    }
    ui->txt_datos->clear();
    ui->lbl_Min->setNum(binomial.menor_mayor->key);
    binomial.PrintDot("ejemplo.dot");
    system(" dot -Tpng ejemplo.dot -o ejemplo.png");
    QPixmap *MyPix = new QPixmap("ejemplo.png");
    ui->label->setPixmap(*MyPix);
    delete MyPix;
}

void MainWindow::on_btn_deleteMin_clicked()
{
    if(!binomial.hijos.empty()){
        binomial.DeleteMin();
        ui->lbl_Min->setNum(binomial.menor_mayor->key);
        binomial.PrintDot("ejemplo.dot");
        system(" dot -Tpng ejemplo.dot -o ejemplo.png");
        QPixmap *MyPix = new QPixmap("ejemplo.png");
        ui->label->setPixmap(*MyPix);
        delete MyPix;
    }else{
        ui->label->clear();
    }
}

void MainWindow::on_btn_DeleteHeap_clicked()
{
    binomial.~BinomialHeap();
    ui->label->clear();
    ui->lbl_Min->setNum(binomial.menor_mayor->key);
}

void MainWindow::on_pushButton_2_clicked()
{
    close();
}
