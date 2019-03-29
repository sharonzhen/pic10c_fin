# Minesweeper with a Bot (if I can finish the bot)
so I can stop wasting time trying to beat my record manually...
also, for PIC10C W'19 with Professor R. Salazar
# Layout
The main menu page provides

    - instructions
    - readme
    - begin game
    - game settings --according to normal minesweeper rules
        -> /radiobutton/ easy ()
        -> /radiobutton/ medium ()
        -> /radiobutton/ hard ()
        -> /radiobutton/ custom []x[] board, [] mines

# Inside 'begin game'

    - there will be a timer that starts once the first block is opened
    - there will be a countdown of remaining mines based on the # flags
    - there will be an option for bots <---- not sure I have time to finish that
    - create an object Block that is
        => opened or closed
        => has a mine or is empty or has a number (1 - 8)
        => has an i,j index, as a member variable
    - on first press, generate mines, then according to this, generate numbers

My first attempt at implementing it without a 2D-array did not work so I implemented it with a 2D-array and then made it into a 2D vector but it does not work at the moment so I am trying to fix it...


# References

I used [this video] to learn more about the UI for minesweeper, and various [documentations] to figure out how QGraphics* libraries work. This markdown README was written using the template provided by [dillinger.io]. Additionally, the rules are based on the rules defined on the [minesweeper website] that I play.
I looked up the source code of [QPushButton] so that the mines can be buttons with the properties I want. I'd like to [maybe reimplement the abstract button class] but maybe I don't need to??
Also I got [icons] from wikipedia and google, and learned to set [fixed button size] from stackoverflow.

# ToDos

 - I tried implementing the right-click according to [stackoverflow] but it did not work... at least this version runs and has all the left-click components.

[//]: # (These are reference links used in the body of this note and get stripped out when the markdown processor does its job. There is no need to format nicely because it shouldn't be seen. Thanks SO - http://stackoverflow.com/questions/4823468/store-comments-in-markdown-syntax)


   [this video]: <https://www.youtube.com/watch?v=T19h2nzkCzg>
   [documentations]: <https://doc.qt.io/>
   [dillinger.io]: <https://dillinger.io/>
   [minesweeper website]: <http://minesweeperonline.com/#150>
   [buttons]: <https://doc.qt.io/qt-5/qabstractbutton.html>
   [redefining abstract button members]: <https://doc.qt.io/qt-5/qabstractbutton-members.html>
   [QPushButton]: <https://code.woboq.org/qt5/qtbase/src/widgets/widgets/qpushbutton.cpp.html>
   [maybe reimplement the abstract button class]: <https://cep.xray.aps.anl.gov/software/qt4-x11-4.2.2-browser/d4/d5f/class_q_abstract_button.html>
   [icons]: <https://commons.wikimedia.org/wiki/Category:Minesweeper>
   [QIcon]: <https://code.woboq.org/qt5/qtbase/src/gui/image/qicon.cpp.html>
   [fixed button size]: <https://stackoverflow.com/questions/47226092/how-to-set-qpushbutton-size-in-qgridlayout-in-qt>
   [square to round]: <https://stackoverflow.com/questions/12734319/change-rectangular-qt-button-to-round>
   [numbers]: <https://stackoverflow.com/questions/17087123/writing-a-text-in-a-qpixmap>
   [stackoverflow]: <https://stackoverflow.com/questions/15658464/qt-rightclick-qpushbutton/15658863>
