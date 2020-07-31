#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>

double FirstNum;
double SecondNum;
double Answer;
bool typingSecondNumber = false;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0, SIGNAL(released()),this,SLOT(digitPressed()));
    connect(ui->pushButton_1, SIGNAL(released()),this,SLOT(digitPressed()));
    connect(ui->pushButton_2, SIGNAL(released()),this,SLOT(digitPressed()));
    connect(ui->pushButton_3, SIGNAL(released()),this,SLOT(digitPressed()));
    connect(ui->pushButton_4, SIGNAL(released()),this,SLOT(digitPressed()));
    connect(ui->pushButton_5, SIGNAL(released()),this,SLOT(digitPressed()));
    connect(ui->pushButton_6, SIGNAL(released()),this,SLOT(digitPressed()));
    connect(ui->pushButton_7, SIGNAL(released()),this,SLOT(digitPressed()));
    connect(ui->pushButton_8, SIGNAL(released()),this,SLOT(digitPressed()));
    connect(ui->pushButton_9, SIGNAL(released()),this,SLOT(digitPressed()));
    connect(ui->pushButton_Sign, SIGNAL(released()),this,SLOT(unaryOperator()));
    connect(ui->pushButton_percent, SIGNAL(released()),this,SLOT(unaryOperator()));
    connect(ui->pushButton_Add, SIGNAL(released()),this,SLOT(binaryOperator()));
    connect(ui->pushButton_Subtract, SIGNAL(released()),this,SLOT(binaryOperator()));
    connect(ui->pushButton_Multiply, SIGNAL(released()),this,SLOT(binaryOperator()));
    connect(ui->pushButton_divide, SIGNAL(released()),this,SLOT(binaryOperator()));

    ui->pushButton_Add->setCheckable(true);
    ui->pushButton_Subtract->setCheckable(true);
    ui->pushButton_Multiply->setCheckable(true);
    ui->pushButton_divide->setCheckable(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow :: digitPressed()
{
    QPushButton * button = (QPushButton *)sender();

    double labelNumber;
    QString newLabel;
    if((ui->pushButton_Add->isChecked() ||ui->pushButton_Subtract->isChecked() ||ui->pushButton_Multiply->isChecked() ||ui->pushButton_divide->isChecked() ) && (!typingSecondNumber) )
    {
        labelNumber =  button->text().toDouble();
        typingSecondNumber = true;
        newLabel = QString::number(labelNumber,'g',15);
    }
    else
    {
        if(ui->label->text().contains('.')&& button->text()=="0")
        {
            newLabel = ui->label->text() + button->text();
        }
        else
        {
            labelNumber = (ui->label->text() + button->text()).toDouble();
            newLabel = QString::number(labelNumber,'g',15);
        }
    }

    ui->label->setText(newLabel);
}

void MainWindow::on_pushButton_Decimal_released()
{
    ui->label->setText(ui->label->text() + ".");
}

void MainWindow::unaryOperator()
{
    QPushButton * button = (QPushButton *)sender();
    double labelNumber;
    QString newLabel;

    if(button->text() == "+/-")
    {
        labelNumber = ui->label->text().toDouble();
        labelNumber = labelNumber * -1;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
    }
    if(button->text() == "%")
    {
        labelNumber = ui->label->text().toDouble();
        labelNumber = labelNumber * 0.01;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
    }
}

void MainWindow::on_pushButton_Clear_released()
{
    ui->label->setText("0");
    ui->pushButton_Add->setChecked(false);
    ui->pushButton_Subtract->setChecked(false);
    ui->pushButton_Multiply->setChecked(false);
    ui->pushButton_divide->setChecked(false);
    typingSecondNumber = false;
    FirstNum = 0;
    SecondNum = 0;
    Answer = 0;
}

void MainWindow::binaryOperator()
{
    QPushButton * button = (QPushButton *)sender();


    FirstNum = ui->label->text().toDouble();
    button->setChecked(true);



}
void MainWindow::on_pushButton_Equalsto_released()
{
    QString newLabel;
    if(ui->pushButton_Add->isChecked())
    {
        SecondNum = ui->label->text().toDouble();
        Answer = FirstNum + SecondNum;
        newLabel = QString::number(Answer,'g',15);
        ui->label->setText(newLabel);
        ui->pushButton_Add->setChecked(false);
    }
    else if(ui->pushButton_Subtract->isChecked())
    {
        SecondNum = ui->label->text().toDouble();
        Answer = FirstNum - SecondNum;
        newLabel = QString::number(Answer,'g',15);
        ui->label->setText(newLabel);
        ui->pushButton_Subtract->setChecked(false);
    }
    else if(ui->pushButton_Multiply->isChecked())
    {
        SecondNum = ui->label->text().toDouble();
        Answer = FirstNum * SecondNum;
        newLabel = QString::number(Answer,'g',15);
        ui->label->setText(newLabel);
        ui->pushButton_Multiply->setChecked(false);
    }
    else if(ui->pushButton_divide->isChecked())
    {
        SecondNum = ui->label->text().toDouble();
        Answer = FirstNum / SecondNum;
        newLabel = QString::number(Answer,'g',15);
        ui->label->setText(newLabel);
        ui->pushButton_divide->setChecked(false);
    }
    newLabel = QString::number(Answer,'g',15);
    ui->label->setText(newLabel);
    typingSecondNumber = false;
}
