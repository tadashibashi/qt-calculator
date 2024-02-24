#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QStyle>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnAdd_clicked()
{
    try {
        ui->txtResult->setText(QString::number(performOp(MathOp::Add)));
    }
    catch(int errIndex)
    {
        ui->txtResult->setText("Error: input " + QString::number(errIndex));
    }
}


void MainWindow::on_btnSub_clicked()
{
    try {
        ui->txtResult->setText(QString::number(performOp(MathOp::Sub)));
    }
    catch(int errIndex)
    {
        ui->txtResult->setText("Error: input " + QString::number(errIndex + 1));
    }
}

float MainWindow::performOp(MathOp op) const
{
    bool ok;
    float num1 = ui->txtNumFirst->text().toFloat(&ok);

    if (!ok)
        throw 0;

    float num2 = ui->txtNumSecond->text().toFloat(&ok);

    if (!ok)
        throw 1;

    switch(op)
    {
    case MathOp::Add:
        return num1 + num2;
    case MathOp::Sub:
        return num1 - num2;
    case MathOp::Div:
        return num1 / num2;
    case MathOp::Mult:
        return num1 * num2;
    default:
        throw std::runtime_error("Operation not recognized");
    }
}


void MainWindow::on_btnDiv_clicked()
{
    try {
        ui->txtResult->setText(QString::number(performOp(MathOp::Div)));
    }
    catch(int errIndex)
    {
        ui->txtResult->setText("Error: input " + QString::number(errIndex + 1));
    }
}


void MainWindow::on_btnMult_clicked()
{
    try {
        ui->txtResult->setText(QString::number(performOp(MathOp::Mult)));
    }
    catch(int errIndex)
    {
        ui->txtResult->setText("Error: input " + QString::number(errIndex + 1));
    }
}

