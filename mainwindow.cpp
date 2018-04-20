#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include <qmath.h>
double firstOperand;
bool isTyping;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){

    this->setFixedSize(size());
    ui->setupUi(this);
    ui->plus->setCheckable(true);
    ui->minus->setCheckable(true);
    ui->multiply->setCheckable(true);
    ui->slash->setCheckable(true);
    ui->pow->setCheckable(true);
    connect(ui->one, SIGNAL(released()), this, SLOT(numberClick()));//===================================
    connect(ui->two, SIGNAL(released()), this, SLOT(numberClick()));
    connect(ui->three, SIGNAL(released()), this, SLOT(numberClick()));
    connect(ui->four, SIGNAL(released()), this, SLOT(numberClick()));
    connect(ui->five, SIGNAL(released()), this, SLOT(numberClick()));
    connect(ui->six, SIGNAL(released()), this, SLOT(numberClick()));//              numbers
    connect(ui->seven, SIGNAL(released()), this, SLOT(numberClick()));
    connect(ui->eight, SIGNAL(released()), this, SLOT(numberClick()));
    connect(ui->nine, SIGNAL(released()), this, SLOT(numberClick()));
    connect(ui->zero, SIGNAL(released()), this, SLOT(numberClick()));//===================================
    connect(ui->dot, SIGNAL(released()), this, SLOT(dotClick()));//   dot
    connect(ui->sign,SIGNAL(released()),this,SLOT(signClick()));//  sign
    connect(ui->plus, SIGNAL(released()), this, SLOT(operationClick()));//==============================
    connect(ui->minus, SIGNAL(released()), this, SLOT(operationClick()));
    connect(ui->pow, SIGNAL(released()), this, SLOT(operationClick()));
    connect(ui->multiply, SIGNAL(released()), this, SLOT(operationClick()));//    operations
    connect(ui->slash, SIGNAL(released()), this, SLOT(operationClick()));//=============================
    connect(ui->clear, SIGNAL(released()), this, SLOT(clear()));//  clear
    connect(ui->enter,SIGNAL(released()),this,SLOT(compute()));//compute;
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::numberClick(){
    QPushButton * button = (QPushButton*)sender();
    double number;
    QString newText;
    if((ui->plus->isChecked()||ui->pow->isChecked()||ui->minus->isChecked()||ui->slash->isChecked()||ui->multiply->isChecked())&&!isTyping){
        number = button->text().toDouble();
        isTyping = true;
        newText = QString::number(number);
    }
    else{
        if(ui->lineEdit->text().contains(".") && button->text()=="0"){
        newText = ui->lineEdit->text()+button->text();
        }
        else{
            number = (ui->lineEdit->text()+button->text()).toDouble();
            newText = QString::number(number);
        }
    }
    ui->lineEdit->setText(newText);
}
void MainWindow::dotClick(){
    ui->lineEdit->setText(ui->lineEdit->text()+".");
}

void MainWindow::signClick(){
    QPushButton * button = (QPushButton*)sender();
    double number;
    QString newText;
    if(button->text()=="±"){
        number = ui->lineEdit->text().toDouble();
        number *=-1;
        newText = QString::number(number);
        ui->lineEdit->setText(newText);
    }
}

void MainWindow::operationClick(){
    QPushButton * button = (QPushButton*)sender();
    firstOperand = ui->lineEdit->text().toDouble();
    button->setChecked(true);
}

void MainWindow::clear(){
    ui->plus->setChecked(false);
    ui->minus->setChecked(false);
    ui->multiply->setChecked(false);
    ui->slash->setChecked(false);
    ui->pow->setChecked(false);
    isTyping = false;
    ui->lineEdit->setText(false);
}

void MainWindow::compute(){
    double number,secondNumber;
    QString newText;
    secondNumber = ui->lineEdit->text().toDouble();
    if(ui->plus->isChecked()){
        number = firstOperand+secondNumber;
        ui->plus->setChecked(false);
    }
    else if(ui->minus->isChecked()){
        number = firstOperand-secondNumber;
        ui->minus->setChecked(false);
    }
    else if (ui->slash->isChecked()&&secondNumber!=0){
        number  = firstOperand / secondNumber;
        ui->slash->setChecked(false);
    }
    else if (ui->multiply->isChecked()){
        number  = firstOperand * secondNumber;
        ui->multiply->setChecked(false);
    }
    else if (ui->pow->isChecked()){
        number = pow(firstOperand,secondNumber);
        ui->pow->setChecked(false);
    }
    else{
        number  = firstOperand;
}
    newText = QString::number(number);
    ui->lineEdit->setText(newText);
    isTyping = false;
}

void MainWindow::on_sin_clicked()
{
    double number = (ui->lineEdit->text().toDouble())*3.14/180;
    ui->lineEdit->setText(QString::number((sin(number))));
}

void MainWindow::on_cos_clicked()
{
    double number = (ui->lineEdit->text().toDouble())*3.14/180;
    ui->lineEdit->setText(QString::number((cos(number))));
}

void MainWindow::on_tan_clicked()
{
    double number = (ui->lineEdit->text().toDouble())*3.14/180;
    ui->lineEdit->setText(QString::number((tan(number))));
}

void MainWindow::on_ctg_clicked()
{
    double number = (ui->lineEdit->text().toDouble())*3.14/180;
    ui->lineEdit->setText(QString::number((1/tan(number))));
}

void MainWindow::on_precent_clicked()
{
    double number = ui->lineEdit->text().toDouble();
    ui->lineEdit->setText(QString::number(number/100));
}

void MainWindow::on_inverse_clicked()
{
    double number = ui->lineEdit->text().toDouble();
    ui->lineEdit->setText(QString::number(1/number));
}

void MainWindow::on_sqrt_clicked()
{
    double number = ui->lineEdit->text().toDouble();
    ui->lineEdit->setText(QString::number(sqrt(number)));
}

