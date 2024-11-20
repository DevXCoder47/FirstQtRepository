#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), step(0)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_AddButton_clicked()
{
    if(ui->progressBar->value() + step > ui->progressBar->maximum()){
        renderMessage("Can't add more");
    }
    else{
        ui->progressBar->setValue(ui->progressBar->value() + step);
    }
}

void MainWindow::on_TakeButton_clicked()
{
    if(ui->progressBar->value() - step < ui->progressBar->minimum()){
        renderMessage("Can't take more");
    }
    else{
        ui->progressBar->setValue(ui->progressBar->value() - step);
    }
}
void MainWindow::on_StepBox_valueChanged(int val)
{
    step = val;
}
void MainWindow::renderMessage(const QString msg){
    setMessage(msg);
    qDebug().nospace().noquote() << TITLE << ": " << getMessage();
    QMessageBox::warning(this, TITLE, getMessage());
}

