#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void digitPressed();
    void on_pushButton_Decimal_released();
    void unaryOperator();
    void on_pushButton_Clear_released();
    void binaryOperator();
    void on_pushButton_Equalsto_released();
};
#endif // MAINWINDOW_H
