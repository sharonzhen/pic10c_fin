#ifndef MINESWEEPER_GAME_H
#define MINESWEEPER_GAME_H

#include <QDialog>
#include <QLabel>
#include <QWidget>
#include <QLCDNumber>
#include <QGridLayout>
#include <QPushButton>
#include <QIcon>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <QPixmap>
#include <QPainter>
#include <QFont>
#include <QString>
#include "block.h"

class minesweeper_game : public QDialog
{
    Q_OBJECT
    std::size_t m_height;
    std::size_t m_width;
    std::size_t m_mines;
    const QString flag_icon = "/Users/Sharn/minesweeper/flag.png";
    const QString mine_icon = "/Users/Sharn/minesweeper/bomb.png";
    const QString emoji_icon = "/Users/Sharn/minesweeper/emoj.png";
    const QString dead_icon = "/Users/Sharn/minesweeper/dead.png";

public:
    explicit minesweeper_game(QWidget *parent = nullptr, std::size_t height=16, std::size_t width=16,
                         std::size_t mines=40);
    ~minesweeper_game();
    int calculate_label(std::size_t i, std::size_t j, std::size_t col_size) {return (i*col_size + j);} // to calculate label of each cell
    void populate_blocks();
    void populate_mines_and_numbers();
    void end_game();
    bool is_game_active();

private slots:


private:
    std::vector<std::vector<Block*>> block_matrix;
    QGridLayout *matrix;
    QGridLayout *general_grid;
    QWidget *minesweeper_block;
    QWidget *minesweeper_parent;
    QLCDNumber *timer;
    QLCDNumber *mines_left;

    QPushButton *restart_button;
    bool ended = false;


};



#endif // MINESWEEPER_GAME_H
