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
