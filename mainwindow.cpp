#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_instructions_clicked()
{
    // this is its parent
    instr_dialog = new instructions(this);
    instr_dialog->show();
}

void MainWindow::on_pushButton_readme_clicked()
{
    readme_dialog = new readme(this);
    readme_dialog->show();
}

void MainWindow::on_pushButton_begin_clicked()
{
    /* sminesweeper_game(QWidget *parent = nullptr, std::size_t height=16, std::size_t width=16,
                         std::size_t mines=40); */
    if (ui->checkBox_easy->isChecked())
        start_game = new minesweeper_game(this, 9,9,10);
    if (ui->checkBox_medium->isChecked())
        start_game = new minesweeper_game(this, 16,16,40);
    if (ui->checkBox_hard->isChecked())
        start_game = new minesweeper_game(this, 16,30,99);
    if (ui->checkBox_custom->isChecked())
        start_game = new minesweeper_game(this, spinbox_height, spinbox_width, spinbox_mines);
    hide();
}



void MainWindow::on_checkBox_medium_stateChanged(int arg1)
{
    /* 0 is unchecked
     * 1 is partially checked
     * 2 is checked
    */
    if(arg1) {
        ui->checkBox_easy->setCheckState(Qt::Unchecked);
        ui->checkBox_hard->setCheckState(Qt::Unchecked);
        ui->checkBox_custom->setCheckState(Qt::Unchecked);
    }
}

void MainWindow::on_checkBox_easy_stateChanged(int arg1)
{
    if(arg1) {
        ui->checkBox_medium->setCheckState(Qt::Unchecked);
        ui->checkBox_hard->setCheckState(Qt::Unchecked);
        ui->checkBox_custom->setCheckState(Qt::Unchecked);
    }

}

void MainWindow::on_checkBox_hard_stateChanged(int arg1)
{
    if(arg1) {
        ui->checkBox_easy->setCheckState(Qt::Unchecked);
        ui->checkBox_medium->setCheckState(Qt::Unchecked);
        ui->checkBox_custom->setCheckState(Qt::Unchecked);
    }
}

void MainWindow::on_checkBox_custom_stateChanged(int arg1)
{
    ui->spinBox_mines->setValue(5);
    ui->spinBox_width->setValue(5);
    ui->spinBox_height->setValue(5);
    if(arg1) {
        ui->checkBox_easy->setCheckState(Qt::Unchecked);
        ui->checkBox_hard->setCheckState(Qt::Unchecked);
        ui->checkBox_medium->setCheckState(Qt::Unchecked);
    }

     spinbox_mines = ui->spinBox_mines->value();
     spinbox_height = ui->spinBox_height->value();
     spinbox_width = ui->spinBox_width->value();

     if ((spinbox_height == 0) || (spinbox_width ==0)) throw std::runtime_error("height or width can't be zero \n");
}
