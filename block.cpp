#include "minesweeper_game.h"
#include "block.h"


Block::Block(minesweeper_game *parent, std::size_t label): mine(false), state(CLOSED), label(label), number(0)
{
    m_parent = parent;
    //w_parent = widget_parent;
}

Block::~Block() {

}
void Block::open() {
    if (this->opened) return;
    std::cout<<"opening"<< this->label<<std::endl;
    this->opened=true;

    std::size_t button_width = m_parent->get_width();
    std::size_t temp_row = this->label / button_width;
    std::size_t temp_col = this->label % button_width;
    // case: if a mine's been opened
    if (mine) {
        this->setIcon(QIcon(mine_icon));
        this->m_parent->end_game();
    }

    // case: if opening is empty
    else if (number == 0) {
        QPixmap pixmap(25,25);
        pixmap.fill(QColor("darkGray"));
        QIcon colorIcon(pixmap);
        this->setIcon(colorIcon);

        this->update();
        this->m_parent->open_neighbors(temp_row, temp_col);
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
        }
    }
this->setIconSize(QSize(25, 25));
this->update();

}

void Block::left_click_handle() {
    std::cout<<"left click \n";
    if (flag || !(m_parent->is_game_active()) || this->opened) return;
    this->open();

}

void Block::right_click_handle() {
    std::cout<<"right click \n";
    if ((this->opened)|| (this->m_parent->is_game_active())) return;
    this->flag = !this->flag;
    if (this->flag == true) {
        this->setIcon(QIcon(flag_icon));
        std::cout<<"right click detected\n";
    }
    else if (this->flag == false) {
        this->setIcon(QIcon());
    }
    this->update();

}


void Block::mouse_release_event(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton)
                emit clicked(event);
    if (event->button() == Qt::RightButton)
                emit right_clicked();
}
