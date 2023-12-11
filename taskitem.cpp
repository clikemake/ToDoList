#include "taskitem.h"
#include "ui_taskitem.h"

TaskItem::TaskItem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TaskItem)
{
    ui->setupUi(this);
    newCreate = new CreateTask();
    //connect(newCreate, &CreateTask::sendTaskData, this, );
}

TaskItem::~TaskItem()
{
    delete ui;
}


