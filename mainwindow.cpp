#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>

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

    labelNumber = (ui->label->text() + button->text()).toDouble();
    newLabel = QString::number(labelNumber,'g',15);
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
}

void MainWindow::binaryOperator()
{

}
void MainWindow::on_pushButton_Equalsto_released()
{

}
