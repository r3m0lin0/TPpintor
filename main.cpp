#include <iostream>
#include <ncurses.h>
#include <pintor.h>

using namespace std;

bool gameover;

void setup();
void input();
void update();
void draw();

pintor elpintor;

int main()
{
    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);

    if (has_colors()) int start_color();

    setup();

    while (!gameover)
    {
        input();
        update();
        draw();
    }

    endwin();

   
    cout << "Adios!" << endl<<endl;
  
    return 0;
}

void setup()
{
    gameover = FALSE;
    int puntaje = 0;
    elpintor.setup();
}

void input()
{
    int teclas = getch();
    
    switch (teclas){
    case KEY_LEFT:
     elpintor.setx(elpintor.getx()-1);
     break;
    case KEY_RIGHT:
    elpintor.setx(elpintor.getx()+1);
     break;
    case 27: 
      gameover = true ;
      break;
    default:
        break;
    }
}


void update()
{
}


void draw()
{
    erase();
    box(stdscr,0,0);
    
    elpintor.draw();

    refresh;
    delay_output (20);
}

void GameOver(){
    for (int y=10; y<16; y++) mvhline ( y,40, ' ' , 40);
    mvaddch(9,39, ACS_ULCORNER);
    mvaddch(9,80, ACS_URCORNER);
    mvaddch(16,39, ACS_LLCORNER);
    mvaddch(16,80, ACS_LRCORNER);

    mvhline (9,40, ACS_HLINE, 40);
    mvhline (16,40, ACS_HLINE, 40);
    mvvline (10,39, ACS_HLINE, 6);
    mvvline (10,80, ACS_HLINE, 6);

    mvprintw(12,55,"Se te ha caido la pintura! (╥﹏╥ԅ)");
    mvprintw(13,50,"Quieres intentarlo nuevamente? s/n: ");
    int opcion=getch();
    if (opcion== 's'|| opcion=='S'|| opcion== 'y'){ gameover=false; setup();}
    else if (opcion=='n' || opcion=='N'){gameover=true;}
    
}


