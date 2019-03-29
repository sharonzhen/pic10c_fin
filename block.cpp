#include "block.h"
#include "minesweeper_game.h"

Block::Block(minesweeper_game *parent, std::size_t label): mine(false), state(CLOSED), label(label), number(0)
{
    m_parent = parent;


}

Block::~Block() {

}

void Block::left_click_handle() {
    if (flag || !(this->m_parent->is_game_active())) {
               return;
           }

    this->opened=true;

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


void Block::right_click_handle() {
    if ((this->opened)|| (this->m_parent->is_game_active()))
        return;
    this->flag = !this->flag;
    if (this->flag == true) {
        this->setIcon(QIcon(flag_icon));
        std::cout<<"right click detected\n";
    }
    //else if (this->flag == false)
    this->update();

}


void Block::mouse_release_event(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton)
                emit clicked(event);
            if (event->button() == Qt::RightButton)
                emit right_clicked();
}
