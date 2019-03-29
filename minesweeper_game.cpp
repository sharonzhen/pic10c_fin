#include "minesweeper_game.h"
#include "ui_minesweeper_game.h"




Block::Block(QWidget *parent, std::size_t label):
    QPushButton(parent), mine(false), state(CLOSED), label(label), number('`')
{
    QIcon flag_icon;
    QIcon mine_icon;

    // for numbers 1-8
    /* void QIcon::addFile(const QString &fileName, const QSize &size, Mode mode, State state) */

    flag_icon.addFile("flag.png", QSize(15,15));
    mine_icon.addFile("flag.png", QSize(15,15));

    a.addFile("a.png", QSize(15,15));
    b.addFile("b.png", QSize(15,15));
    c.addFile("c.png", QSize(15,15));
    d.addFile("d.png", QSize(15,15));
    e.addFile("e.png", QSize(15,15));
    f.addFile("f.png", QSize(15,15));
    g.addFile("g.png", QSize(15,15));
    h.addFile("h.png", QSize(15,15));

}

Block::~Block() {

}


minesweeper_game::minesweeper_game(QWidget *parent, std::size_t height, std::size_t width, std::size_t mines) :
    QDialog(parent), m_height(height), m_width(width), m_mines(mines), block_matrix(height, std::vector<Block*>(width, nullptr))
{
    srand((unsigned)time(0));
    minesweeper_block = new QWidget();
    timer = new QLCDNumber();
    mines_left = new QLCDNumber();
    populate_blocks();
    //matrix = new QGridLayout(minesweeper_block, );
}

minesweeper_game::~minesweeper_game()
{
    delete minesweeper_block;
    delete timer;
    delete mines_left;
}

void minesweeper_game::populate_blocks() {
    std::size_t label=0;
    for (std::size_t i=0; i < m_height ; ++i)
        for (std::size_t j=0; j< m_width; ++j) {
            block_matrix[i][j] = new Block(this, label);
            block_matrix[i][j]->show();
            ++label;
        }
}

void minesweeper_game::populate_mines_and_numbers() {
    std::size_t cells = m_height * m_width;
    if (m_mines < cells) throw std::runtime_error("too many mines\n");
    std::size_t rando = 0;
    std::size_t m=0, i=0, j=0;

    while (m<m_mines) { // generate m_mines unique numbers in the range of (0 - cells-1)
        rando = rand() % cells; // label to place the mine
        j = rando % m_width;    // to determine which column
        i = rando / m_width;    // to determine which row

        /* if mine already exists */
        if (block_matrix[i][j]->mine) continue;

        /* when adding a mine, increase the counters for the 8 adjacent blocks*/
        block_matrix[i][j]->mine = true;
        if (i < (m_height-1)) {                     // room to go down
            block_matrix[i++][j]->number++;         // (1) [i++][j]
            if (j < (m_width-1))
                block_matrix[i++][j++]->number++;   // (5) [i++][j++]
            if (j > 0)
                block_matrix[i++][j--]->number++;   // (6) [i++][j--]
        }
        if (i > 0) {                                // room to go up
            block_matrix[i--][j]->number++;         // (2) [i--][j]
            if (j < (m_width-1))
                block_matrix[i--][j++]->number++;   // (7) [i--][j++]
            if (j > 0)
                block_matrix [i--][j--]->number++;  // (8) [i--][j--]
        }

        if (j < (m_width-1))
            block_matrix[i][j++]->number++;         // (3) [i][j++]
        if (j>0)
            block_matrix[i][j--]->number++;         // (4) [i][j--]
        ++m;
    }

}



/*
class Block
    enum State {Closed, Open, Flagged};
    int label;
    int number; // 1-8, 0 if there's no number
    bool mine;
    explicit Block(QWidget *parent = nullptr, int label=0): label(label), number(0), mine(false){}
*/
/*
class Minesweeper

    int m_height;
    int m_width;
    int m_mines;
pubic
    void populate_blocks();
    void populate_mines();
    void populate_numbers();

private:
    Block *set_of_blocks;
    std::vector<std::vector<Block>> bock_matrix;
    QGridLayout *m_field;

};
*/


