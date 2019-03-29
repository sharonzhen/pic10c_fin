#include "minesweeper_game.h"
#include "ui_minesweeper_game.h"

Block::Block(QWidget *parent, std::size_t label):
    QPushButton(parent), mine(false), state(CLOSED), label(label), number(0)
{



}

Block::~Block() {

}

void Block::right_click_handle() {
   // std::cout<<"inside right_click_handle\n";
    if(mine) {
        //     QPixmap pixmap("image_path");
        //     QIcon ButtonIcon(pixmap);
        //     button->setIcon(ButtonIcon);
        //     button->setIconSize(pixmap.rect().size());
//        QPixmap map(mine_icon);
//        QIcon someIcon(map);
//        this->setIcon(someIcon);
         this->setIcon(QIcon(mine_icon));
    }
    else {
        switch(number) {
        case 1:
            this->setIcon(QIcon(a));
            break;
        case 2:
            this->setIcon(QIcon(b));
            break;
        case 3:
            this->setIcon(QIcon(c));
            break;
        case 4:
            this->setIcon(QIcon(d));
            break;
        case 5:
            this->setIcon(QIcon(e));
            break;
        case 6:
            this->setIcon(QIcon(f));
            break;
        case 7:
            this->setIcon(QIcon(g));
            break;
        case 8:
            this->setIcon(QIcon(h));
            break;
        default:
            QPixmap pixmap(25,25);
            pixmap.fill(QColor("darkGray"));
            QIcon colorIcon(pixmap);
            this->setIcon(colorIcon);
            break;
        }
    }
this->setIconSize(QSize(25, 25));
this->update();

}


minesweeper_game::minesweeper_game(QWidget *parent, std::size_t height, std::size_t width, std::size_t mines) :
    QDialog(parent), m_height(height), m_width(width), m_mines(mines), block_matrix(height, std::vector<Block*>(width, nullptr))
{
    srand((unsigned)time(0));
    minesweeper_parent = new QWidget();
    minesweeper_block = new QWidget(minesweeper_parent);

    const QSize LCD_size = QSize(140, 60);
    const QSize button_size = QSize(60, 60);

    timer = new QLCDNumber(minesweeper_parent);
    timer->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    timer->setFixedSize(LCD_size);

    mines_left = new QLCDNumber(minesweeper_parent);
    mines_left->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    mines_left->setFixedSize(LCD_size);

    restart_button = new QPushButton(minesweeper_parent);
    restart_button->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    restart_button->setFixedSize(button_size);
    //restart_button->setIcon(QIcon("/Users/Sharn/minesweeper/emoj.png"));
    //restart_button->setIconSize(button_size);


    //general_layout = new QVBoxLayout();
    //top_layout = new QHBoxLayout();

    general_grid = new QGridLayout();
    matrix = new QGridLayout();
    matrix->setHorizontalSpacing(3);
    matrix->setVerticalSpacing(6);

    //minesweeper_parent->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    general_grid->addWidget(timer, 0, 0);
    general_grid->addWidget(restart_button, 0, 1);
    general_grid->addWidget(mines_left, 0, 2);
    general_grid->addWidget(minesweeper_block, 1, 0, -1, -1);

    minesweeper_block->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    minesweeper_block->setLayout(matrix);
    minesweeper_parent->setLayout(general_grid);
    minesweeper_parent->show();

}

minesweeper_game::~minesweeper_game()
{
    delete minesweeper_parent;
    //delete minesweeper_block;
    //delete timer;
    //delete mines_left;
}

void minesweeper_game::populate_blocks() {
    const QSize block_size = QSize(40, 40);
    std::size_t label=0;
    for (std::size_t i=0; i < m_height ; ++i) {
        for (std::size_t j=0; j< m_width; ++j) {
            block_matrix[i][j] = new Block(minesweeper_block, label);
            block_matrix[i][j] -> setFixedSize(block_size);
            block_matrix[i][j] -> setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
            QObject::connect(block_matrix[i][j], SIGNAL(released()), block_matrix[i][j], SLOT(right_click_handle()));
            matrix->addWidget(block_matrix[i][j], i, j);
            ++label;
        }
    }
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


