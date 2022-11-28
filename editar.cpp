#include "editar.h"
#include "ui_editar.h"

Editar::Editar(QWidget *parent,int id,QString todo) :
    QDialog(parent),
    ui(new Ui::Editar)
{
    ui->setupUi(this);

    ui->label->setText(QString::number(id));
    ui->lineEdit->setText(todo);

}

Editar::~Editar()
{
    delete ui;
}

void Editar::on_pushButton_clicked()
{

    QString id = ui->label->text();

    QSqlQuery query;
    QString sql = "delete from todos where id=" + id;
    query.prepare(sql);

    if(query.exec()){
        close();
    }
    else {
        qDebug()<<"Falha ao deletar a tarefa";
    }

}


void Editar::on_pushButton_2_clicked()
{
    if(ui->lineEdit->text() == ""){
        QMessageBox::warning(this, "Aviso", "Campo nao pode ficar vazio");
        return;
    }

    QString id = ui->label->text();


    QSqlQuery query;
    QString sql = "update todos set todos='" + ui->lineEdit->text() +"' where id =" + id;
    query.prepare(sql);

    if(query.exec()){
        close();
    }
    else {
        qDebug()<<"Falha ao atualizar os dados";
    }
}

