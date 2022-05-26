#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>

char input();
int generaterandomnumber();

int main()

{

    
char hitenter;
int randomnumber;
char string[60]={"This text changes colors all the time when you press enter"};

    initscr();
    cbreak();
    noecho();
    nodelay(stdscr,true);
    start_color();
    
    init_pair(1, COLOR_BLACK, COLOR_RED);
    init_pair(2, COLOR_RED, COLOR_GREEN); 
    init_pair(3, COLOR_GREEN, COLOR_YELLOW); 
    init_pair(4, COLOR_YELLOW, COLOR_BLUE);
    init_pair(5, COLOR_BLUE, COLOR_MAGENTA);
    init_pair(6, COLOR_MAGENTA, COLOR_CYAN);
    init_pair(7, COLOR_CYAN, COLOR_WHITE);
    init_pair(8, COLOR_WHITE, COLOR_BLACK);
    init_pair(9, COLOR_BLACK, COLOR_GREEN);
    init_pair(10, COLOR_GREEN, COLOR_BLUE);
        
    WINDOW *thebox=newwin(5,60,10,10);
    box(thebox,0,0);
    
    
    mvwprintw(thebox,1,1,"%s", string);
    
    refresh();
    wrefresh(thebox);
    
    while(1)
    {
        hitenter=input();
        randomnumber=(rand()%(9+1));

        wattron(thebox,COLOR_PAIR(randomnumber));
        mvwprintw(thebox,1,1,"%s", string);
        wattroff(thebox,COLOR_PAIR(randomnumber));
        
       
        wrefresh(thebox);
        //refresh();
    }
        

        endwin();

        return 0;
}


char input()
{
    char temp;
    do
    {
        temp=getch();
    }
        while (temp!='\n');
        return temp;
}

int generaterandomnumber()
{
    int temp;
    srand(time(NULL));
    temp=(rand()%(9+1));
    return temp;    
}   