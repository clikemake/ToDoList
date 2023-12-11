#include "mainwindow.h"
#include "createtask.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    CreateTask c;
    w.show();
    QObject::connect(&c, &CreateTask::sendTaskData, &w, &MainWindow::resiveData);
    return a.exec();
}
