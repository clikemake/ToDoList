#include "createtask.h"
#include "ui_createtask.h"
#include <QDebug>

CreateTask::CreateTask(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateTask)
{
    ui->setupUi(this);
    //connect(this, SIGNAL(sendTaskData(const QString& taskName, const QString& taskDisc, const QDate& dateStart, const QDate& dateEnd)), m, SLOT(resiveData(const QString& taskName, const QString& taskDisc, const QDate& dateStart, const QDate& dateEnd)));
    //connect(ui->createTaskBtn, &QPushButton::clicked, this, &CreateTask::on_createTaskBtn_clicked);
}

CreateTask::~CreateTask()
{
    delete ui;
}

void CreateTask::on_cancelBtn_clicked()
{
    this->close();
}


void CreateTask::on_createTaskBtn_clicked()
{
    if(ui->taskNameLineEdit->text().isEmpty() || ui->taskDiscPlainTextEdit->toPlainText().isEmpty()){
        QMessageBox::warning(this, "Ошибка", "Не заполнены обязательные поля '*'!", QMessageBox::Close);
    }

    if(!ui->dateStartLineEdit->text().isEmpty() || !ui->dateEndLineEdit->text().isEmpty()){
            QDate dateStart = QDate::fromString(ui->dateStartLineEdit->text(), "dd.MM.yyyy");
            QDate dateEnd = QDate::fromString(ui->dateEndLineEdit->text(), "dd.MM.yyyy");

            if(!ui->dateStartLineEdit->text().isEmpty() && !ui->dateEndLineEdit->text().isEmpty()){
                if(dateStart > dateEnd && dateStart.isValid() && dateEnd.isValid()){
                    QMessageBox::warning(this, "Ошибка", "Дата начала не может быть позже даты конца!", QMessageBox::Close);
                    qDebug()<<dateStart << "--" << dateEnd;
                }
            }

            if(!dateStart.isValid() || !dateEnd.isValid()){
                QMessageBox::warning(this, "Ошибка", "Неверный формат даты!", QMessageBox::Close);
                qDebug()<<dateStart << "--" << dateEnd;
            }
            else{
                QString taskName = ui->taskNameLineEdit->text();
                QString taskDisc = ui->taskDiscPlainTextEdit->toPlainText();
                try {
                    qDebug()<<"Sending task data";
                    emit sendTaskData(taskName, taskDisc, dateStart, dateEnd);
                    qDebug() << "Closing CreateTask form...";
                    this->close();

                } catch (std::exception&ex) {
                    QMessageBox::information(this, "Ошибка", ex.what(), QMessageBox::Close);
                }

        }
    }
}
