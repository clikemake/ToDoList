#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QStyledItemDelegate>
#include <QStandardItemModel>
#include <QPainter>
#include <QString>
#include <QDate>

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

public slots:
    void resiveData(const QString& taskName, const QString& taskDisc, const QDate& dateStart, const QDate& dateEnd);

private slots:
    void on_addTaskBtn_clicked();

    void on_exitBtn_clicked();

private:
    Ui::MainWindow *ui;
    CreateTask *newTask;
    QStandardItemModel *taskModel;
    void addItem(const QString& taskName, const QString& taskDisc, const QDate& dateStart, const QDate& dateEnd);
};
#endif // MAINWINDOW_H
