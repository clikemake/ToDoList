#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QtGui>

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


void MainWindow::on_addTaskBtn_clicked()
{
    newTask = new CreateTask(this);
    newTask->open();
}


void MainWindow::on_exitBtn_clicked()
{
    //Окно подтверждения выхода
    QMessageBox qbox;
    qbox.setIcon(QMessageBox::Question);
    qbox.setWindowTitle("Выход");
    qbox.setText("Вы действительно хотите выйти?");
    qbox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    QAbstractButton* btnY = qbox.button(QMessageBox::Yes);
    btnY->setText("Да");
    QAbstractButton* btnN = qbox.button(QMessageBox::No);
    btnN->setText("Нет");
    qbox.exec();

    //QMessageBox::StandardButton reply = qbox.question(this, "", "", QMessageBox::Yes | QMessageBox::No);
        //QMessageBox::question(this, "Выход", "Вы действительно хотите выйти?", QMessageBox::Yes | QMessageBox::No);

    //if(reply == btnY)
      //  QApplication::exit();
}

