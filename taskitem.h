#ifndef TASKITEM_H
#define TASKITEM_H

#include <QDialog>
#include <QDate>

#include "createtask.h"

namespace Ui {
class TaskItem;
}

class TaskItem : public QDialog
{
    Q_OBJECT

public:
    explicit TaskItem(QWidget *parent = nullptr);
    ~TaskItem();

private:
    Ui::TaskItem *ui;
    CreateTask* newCreate;
};

#endif // TASKITEM_H
