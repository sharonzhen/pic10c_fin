#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //main_menu_scene = new QGraphicsScene(this);

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

}
