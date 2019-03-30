#ifndef BLOCK_H
#define BLOCK_H

#include <QObject>
#include <QWidget>
#include <QDialog>
#include <QLabel>
#include <QGridLayout>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <QPushButton>
#include <QMouseEvent>
#include <iostream>
#include <QLCDNumber>

#define CLOSED 1
#define OPEN 0
#define FLAGGED -1

class minesweeper_game;

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
    void left_click_handle();
    void right_click_handle();


    /* from stackoverflow: https://stackoverflow.com/questions/15658464/qt-rightclick-qpushbutton/15658863 */
signals:
    void right_clicked();

protected:
    void mouse_release_event(QMouseEvent *event);

public:
    explicit Block(minesweeper_game *parent = nullptr, std::size_t label=0);
    ~Block();
    bool mine;
    int state; // { OPEN, CLOSED, FLAGGED }
    std::size_t label;/* label calculated from an array[n][m] as array[i][j] = (i*m + j) */
    std::size_t number; // to represent numbers 1-8, i.e. number of neighboring mines
    bool opened = false;
    bool flag = false;
    minesweeper_game *m_parent;
    //QWidget *w_parent;
    void open();

};


#endif // BLOCK_H
