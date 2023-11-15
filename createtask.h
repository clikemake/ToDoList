#ifndef CREATETASK_H
#define CREATETASK_H

#include <QDialog>

namespace Ui {
class CreateTask;
}

class CreateTask : public QDialog
{
    Q_OBJECT

public:
    explicit CreateTask(QWidget *parent = nullptr);
    ~CreateTask();

private slots:
    void on_cancelBtn_clicked();

private:
    Ui::CreateTask *ui;
};

#endif // CREATETASK_H
