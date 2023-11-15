#include "createtask.h"
#include "ui_createtask.h"

CreateTask::CreateTask(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateTask)
{
    ui->setupUi(this);
}

CreateTask::~CreateTask()
{
    delete ui;
}

void CreateTask::on_cancelBtn_clicked()
{
    this->close();
}

