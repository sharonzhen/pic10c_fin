#ifndef MINESWEEPER_GAME_H
#define MINESWEEPER_GAME_H

#include <QDialog>
#include <QLabel>
#include <QWidget>
#include <QLCDNumber>
#include <QGridLayout>
#include <QPushButton>
#include <QIcon>
#include <vector>
#include <cstdlib>
#include <ctime>

#define CLOSED 1
#define OPEN 0
#define FLAGGED -1


class Block : public QPushButton
{
    Q_OBJECT
    QIcon flag_icon;
    QIcon mine_icon;
    QIcon a; // for numbers 1-8
    QIcon b;
    QIcon c;
    QIcon d;
    QIcon e;
    QIcon f;
    QIcon g;
    QIcon h;


public:
    explicit Block(QWidget *parent = nullptr, std::size_t label=0);
    ~Block();
    bool mine;
    int state; // { OPEN, CLOSED, FLAGGED }
    std::size_t label;/* label calculated from an array[n][m] as array[i][j] = (i*m + j) */
    char number; // 'a'-'h', '`' or any other char if there's no number, to represent numbers 1-8, i.e. number of neighboring mines


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
    QWidget *minesweeper_block;
    QLCDNumber *timer;
    QLCDNumber *mines_left;

};



#endif // MINESWEEPER_GAME_H
