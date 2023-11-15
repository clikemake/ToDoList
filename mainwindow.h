#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "createtask.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addTaskBtn_clicked();

    void on_exitBtn_clicked();

private:
    Ui::MainWindow *ui;
    CreateTask *newTask;
};
#endif // MAINWINDOW_H
