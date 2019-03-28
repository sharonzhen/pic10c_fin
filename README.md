# Board-less Minesweeper with a bot
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
    - there will be an option for bots
    - create an object Block that is
        => opened or closed
        => has a mine or is empty or has a number (1 - 8)
        => has an i,j index, as a member variable
    - on first press, generate mines, then according to this, generate numbers
    - there would be no board since I can just rely on the index of each block

My first attempt at implementing it without a 2D-array did not work so I implemented it with a 2D-array and then made it into a 2D vector but it does not work at the moment so I am trying to fix it...

# References

I used [this video] to learn more about the UI for minesweeper, and various [documentations] to figure out how QGraphics* libraries work. This markdown README was written using the template provided by [dillinger.io]. Additionally, the rules are based on the rules defined on the [minesweeper website] that I play.


# ToDos

 - MY CODE WON'T RUN I promise I will get this done by Friday morning

[//]: # (These are reference links used in the body of this note and get stripped out when the markdown processor does its job. There is no need to format nicely because it shouldn't be seen. Thanks SO - http://stackoverflow.com/questions/4823468/store-comments-in-markdown-syntax)


   [this video]: <https://www.youtube.com/watch?v=T19h2nzkCzg>
   [documentations]: <https://doc.qt.io/>
   [dillinger.io]: <https://dillinger.io/>
   [minesweeper website]: <http://minesweeperonline.com/#150>

