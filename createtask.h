#ifndef CREATETASK_H
#define CREATETASK_H

#include <QDialog>
#include <QMessageBox>
#include <QDate>
#include <QException>

namespace Ui {
class CreateTask;
}

class CreateTask : public QDialog
{
    Q_OBJECT

public:
    explicit CreateTask(QWidget *parent = nullptr);
    ~CreateTask();

signals:
    void sendTaskData(const QString& taskName, const QString& taskDisc, const QDate& dateStart, const QDate& dateEnd);

private slots:
    void on_cancelBtn_clicked();

    void on_createTaskBtn_clicked();

private:
    Ui::CreateTask *ui;
};

#endif // CREATETASK_H
