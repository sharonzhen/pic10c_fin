#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsView>
#include "instructions.h"
#include "readme.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_instructions_clicked();

    void on_pushButton_readme_clicked();

    void on_pushButton_begin_clicked();

private:
    Ui::MainWindow *ui;
    //QGraphicsScene *main_menu_scene;
    //QGraphicsScene *game_scene;
    readme *readme_dialog;
    instructions *instr_dialog;
};

#endif // MAINWINDOW_H
