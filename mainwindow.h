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
    int spinbox_mines;
    int spinbox_height;
    int spinbox_width;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_instructions_clicked();

    void on_pushButton_readme_clicked();

    void on_pushButton_begin_clicked();


    void on_checkBox_medium_stateChanged(int arg1);

    void on_checkBox_easy_stateChanged(int arg1);

    void on_checkBox_hard_stateChanged(int arg1);

    void on_checkBox_custom_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;
    minesweeper_game *start_game;
    readme *readme_dialog;
    instructions *instr_dialog;
};




#endif // MAINWINDOW_H
