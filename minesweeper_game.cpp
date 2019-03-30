#include "minesweeper_game.h"
#include "ui_minesweeper_game.h"
#include "mainwindow.h"
#include <QBoxLayout>

class Block;

minesweeper_game::minesweeper_game(QWidget *parent, std::size_t height, std::size_t width, std::size_t mines) :
    QDialog(parent), m_width(width), m_mines(mines), m_height(height), ui(new Ui::minesweeper_game),
    block_matrix(height, std::vector<Block*>(width, nullptr))
{
    m_parent = parent;
    srand((unsigned)time(0));
    /*                  ui::minesweeper_game
     * (general_grid)   timer, mines_left, restart_button
     * (matrix grid)        minesweeper_block
     */
    /*                  ui::minesweeper_game
     * (general_grid)   ^ this <--timer, mines_left, restart_button
     *                  ^ minesweeper_block  <--each block
     */
//    minesweeper_parent = new QWidget(this);
//    minesweeper_block = new QWidget(minesweeper_parent);
    minesweeper_block = new QWidget(this); // block w/ matrix


    const QSize LCD_size = QSize(140, 60);
    const QSize button_size = QSize(60, 60);

    //timer = new QLCDNumber(minesweeper_parent);
    timer = new QLCDNumber(this);
    timer->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    timer->setFixedSize(LCD_size);
    timer->setDigitCount(3);
    timer->display(999);

//    mines_left = new QLCDNumber(minesweeper_parent);
    mines_left = new QLCDNumber(this);
    mines_left->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    mines_left->setFixedSize(LCD_size);

//    restart_button = new QPushButton(minesweeper_parent);
    restart_button = new QPushButton(this);
    restart_button->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    restart_button->setFixedSize(button_size);
    restart_button->setIcon(QIcon(emoji_icon));
    restart_button->setIconSize(QSize(40,40));

    general_grid = new QGridLayout();
    matrix = new QGridLayout();
    matrix->setHorizontalSpacing(3);
    matrix->setVerticalSpacing(6);

    general_grid->addWidget(timer, 0, 0);
    general_grid->addWidget(restart_button, 0, 1);
    general_grid->addWidget(mines_left, 0, 2);
    general_grid->addWidget(minesweeper_block, 1, 0, -1, -1);

    minesweeper_block->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    //minesweeper_block->setLayout(matrix);

    general_grid->addLayout(matrix,1,1);
    this->setLayout(general_grid);
//   minesweeper_block->setLayout(matrix);
//    minesweeper_parent->setLayout(general_grid);
    //minesweeper_parent->show();

    ui->setupUi(this);

}

minesweeper_game::~minesweeper_game()
{
    delete ui;
    //delete minesweeper_parent;
    //delete minesweeper_block;
    //delete timer;
    //delete mines_left;
}

void minesweeper_game::populate_blocks() {
    const QSize block_size = QSize(40, 40);
    std::size_t label=0;
    for (std::size_t i=0; i < m_height ; ++i) {
        for (std::size_t j=0; j< m_width; ++j) {
            block_matrix[i][j] = new Block(this, label);
            block_matrix[i][j] -> setFixedSize(block_size);
            block_matrix[i][j] -> setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
            QObject::connect(block_matrix[i][j], SIGNAL(released()), block_matrix[i][j], SLOT(left_click_handle()));
            QObject::connect(block_matrix[i][j], SIGNAL(right_clicked()), block_matrix[i][j], SLOT(right_click_handle()));

            matrix->addWidget(block_matrix[i][j], i, j);
            //block_matrix[i][j]->raise();
            ++label;
        }
    }

    //this->setLayout(matrix);
}

void minesweeper_game::populate_mines_and_numbers() {
    std::size_t cells = m_height * m_width;
    if (m_mines > cells) throw std::runtime_error("too many mines\n");

    std::vector<std::size_t> rand_numbers;
    for (std::size_t i=0; i<cells; ++i)
        rand_numbers.push_back(i);
    std::random_shuffle(rand_numbers.begin(), rand_numbers.end());

    /* populate mines */
    int row=0, col=0;

    for (std::size_t i=0; i<m_mines; ++i) {
        row = rand_numbers[i] / m_width; // to determine which row
        col = rand_numbers[i] % m_width; // to determine which column

         block_matrix[row][col]->mine = true; // dont need to check anymore, since the numbers are unique

         /* cases [j--][k--] [j][k--] [j++][k--]
          *       [j--][k  ] [j][k  ] [j++][k  ]
          *       [j--][k++] [j][k++] [j++][k++] increase the number of surrounding blocks
          */
         for (int j=-1; j<=1; ++j) {
             for (int k=-1; k<=1; ++k) {
                 if (j==0 && k==0) continue; // skip the current mine
                 if (((row+j) >= 0) && ((row+j) < m_height) &&
                         ((col+k) >= 0) && ((col+k) < m_width))
                     block_matrix[row+j][col+k]->number++;
             /* edge cases in case rows and columns go out of bound */
             }
         }
    }
}

void minesweeper_game::end_game() {
    std::cout<<"inside end_game()\n";
    this->ended = true;
    for (std::size_t i=0; i<m_height; ++i) {
        for (std::size_t j=0; j<m_width; ++j) {
            if (block_matrix[i][j]->mine)
                block_matrix[i][j]->setIcon(QIcon(mine_icon));
        }
    }
    this->restart_button->setIcon(QIcon(dead_icon));
    this->update();
}



void minesweeper_game::open_neighbors(int row, int col) {
    for (int j = -1; j <= 1; ++j) {
        for (int k = -1; k <= 1; ++k){
            if (j == 0 && k==0) continue;
            if (((row+j)>=0)
                    && ((row+j) <m_height)
                    && ((col+k) >= 0)
                    && ((col+k) < m_width))
            {
                block_matrix[row+j][col+k]->open();
            }
        }
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


