#include "instructions.h"
#include "ui_instructions.h"

instructions::instructions(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::instructions)
{
    ui->setupUi(this);
}

instructions::~instructions()
{
    delete ui;
}

void instructions::on_pushButton_back_clicked()
{
    delete this;
}
