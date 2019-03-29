#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QLabel>
#include "instructions.h"
#include "readme.h"
#include "minesweeper_game.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int spinbox_mines;
    int spinbox_height;
    int spinbox_width;

private slots:
    void on_pushButton_instructions_clicked();

    void on_pushButton_readme_clicked();

    void on_pushButton_begin_clicked();


    void on_checkBox_medium_stateChanged(int arg1);

    void on_checkBox_easy_stateChanged(int arg1);

    void on_checkBox_hard_stateChanged(int arg1);

    void on_checkBox_custom_stateChanged(int arg1);

    void set_spinbox_mines(int arg1){spinbox_mines=arg1;}

    void set_spinbox_height(int arg1){spinbox_height=arg1;}

    void set_spinbox_width(int arg1){spinbox_width=arg1;}

private:
    Ui::MainWindow *ui;
    minesweeper_game *start_game;
    readme *readme_dialog;
    instructions *instr_dialog;
};




#endif // MAINWINDOW_H
