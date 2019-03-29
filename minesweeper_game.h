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

#define CLOSED 1
#define OPEN 0
#define FLAGGED -1


class Block : public QPushButton
{
    Q_OBJECT

    const QString flag_icon = "/Users/Sharn/minesweeper/flag.png";
    const QString mine_icon = "/Users/Sharn/minesweeper/bomb.png";

    const QString a = "/Users/Sharn/minesweeper/a.png"; // for numbers 1-8
    const QString b = "/Users/Sharn/minesweeper/b.png";
    const QString c = "/Users/Sharn/minesweeper/c.png";
    const QString d = "/Users/Sharn/minesweeper/d.png";
    const QString e = "/Users/Sharn/minesweeper/e.png";
    const QString f = "/Users/Sharn/minesweeper/f.png";
    const QString g = "/Users/Sharn/minesweeper/g.png";
    const QString h = "/Users/Sharn/minesweeper/h.png";
//     const QString flag_icon = ":/flag.png";
//     const QString mine_icon = ":/bomb.png";
//     const QString a = ":/a.png"; // for numbers 1-8
//     const QString b = ":/b.png";
//     const QString c = ":/c.png";
//     const QString d = ":/d.png";
//     const QString e = ":/e.png";
//     const QString f = ":/f.png";
//     const QString g = ":/g.png";
//     const QString h = ":/h.png";


private slots:
    void right_click_handle();



public:
    explicit Block(QWidget *parent = nullptr, std::size_t label=0);
    ~Block();
    bool mine;
    int state; // { OPEN, CLOSED, FLAGGED }
    std::size_t label;/* label calculated from an array[n][m] as array[i][j] = (i*m + j) */
    std::size_t number; // to represent numbers 1-8, i.e. number of neighboring mines

};

class minesweeper_game : public QDialog
{
    Q_OBJECT
    std::size_t m_height;
    std::size_t m_width;
    std::size_t m_mines;

public:
    explicit minesweeper_game(QWidget *parent = nullptr, std::size_t height=16, std::size_t width=16,
                         std::size_t mines=40);
    ~minesweeper_game();
    int calculate_label(std::size_t i, std::size_t j, std::size_t col_size) {return (i*col_size + j);} // to calculate label of each cell
    void populate_blocks();
    void populate_mines_and_numbers();

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

};



#endif // MINESWEEPER_GAME_H
