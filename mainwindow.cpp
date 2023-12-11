#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "createtask.h"
#include "customitemdelegate.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    CreateTask newTask;
    this->setAttribute(Qt::WA_QuitOnClose, false);

//    QObject::connect(&newTask,
//                     SIGNAL(sendTaskData(const QString& taskName, const QString& taskDisc, const QDate& dateStart, const QDate& dateEnd)),
//                     this, SLOT(resiveData(const QString& taskName, const QString& taskDisc, const QDate& dateStart, const QDate& dateEnd)));
    // Инициализация модели
    taskModel = new QStandardItemModel(this);
    ui->taskListView->setModel(taskModel);

    // Установка делегата для отображения данных
    ui->taskListView->setItemDelegate(new CustomItemDelegate(ui->taskListView));
}

MainWindow::~MainWindow()
{
    qDebug() << "delete MainWindow";
    if (newTask) {
        newTask->deleteLater();
    }
    delete ui;
}


void MainWindow::on_addTaskBtn_clicked()
{
    this->setDisabled(true);

    newTask = new CreateTask(this);
    newTask->setAttribute(Qt::WA_DeleteOnClose);
    newTask->setAttribute(Qt::WA_QuitOnClose, false);

    // Подключение сигнала sendTaskData к слоту resiveData
    QObject::connect(newTask, &CreateTask::sendTaskData, this, &MainWindow::resiveData);

    newTask->open();

    // Восстановить возможность взаимодействия с главной формой
    this->setEnabled(true);
}

void MainWindow::addItem(const QString& taskName, const QString& taskDisc, const QDate& dateStart, const QDate& dateEnd)
{
    QStandardItem *newItem = new QStandardItem(taskName);
    newItem->setData(taskDisc, Qt::UserRole + 1);
    newItem->setData(dateStart.toString("dd.MM.yyyy"), Qt::UserRole + 2);
    newItem->setData(dateEnd.toString("dd.MM.yyyy"), Qt::UserRole + 3);

    taskModel->appendRow(newItem);
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

    int result = qbox.exec();

    if (result == QMessageBox::Yes)
        QApplication::exit();
}

void MainWindow::resiveData(const QString& taskName, const QString& taskDisc, const QDate& dateStart, const QDate& dateEnd){
    qDebug() << "Received data in resiveData";
    addItem(taskName, taskDisc, dateStart, dateEnd);
    qDebug() << "Exiting resiveData";
}
