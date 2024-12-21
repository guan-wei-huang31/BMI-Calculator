#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDoubleValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QDoubleValidator* double_validator = new QDoubleValidator();
    ui->lineEdit_Weight->setValidator(double_validator);
    ui->lineEdit_height->setValidator(double_validator);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btmCalculate_clicked()
{
    bool check;
    QString result;
    height = ui->lineEdit_height->text().toDouble(&check);
    if(!check){
        result = "Wrong Height.\nEnter Again.";
        ui->labelResult->setText(result);
        return;
    }
    weight = ui->lineEdit_Weight->text().toDouble(&check);
    if(!check){
        result = "Wrong Weight.\nEnter Again.";
        ui->labelResult->setText(result);
        return;
    }
    double bmiResult = weight / ((height/100) * (height/100));
    result += "Reslut: " + QString::number(bmiResult) + "\n";
    if (bmiResult < 18.5){
        result += "Underweight";
    }else if(bmiResult < 22.9){
        result += "Normal";
    }else{
        result += "Overweight";
    }

    ui->labelResult->setText(result);
}

