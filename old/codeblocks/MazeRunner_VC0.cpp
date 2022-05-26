#include <string>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

#define FRAME_DELAY 100  //Decrement the value for less delay per step.

#define WALL 32787
#define SIZE 20
#define INIT_X 1
#define INIT_Y 1
#define FINISH_X 18
#define FINISH_Y 18

using namespace std;

int maze [SIZE][SIZE] =
{
    {WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL},
    {WALL,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,WALL,WALL,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,WALL},
    {WALL,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL,WALL,WALL,WALL,WALL,  0 ,WALL,WALL,WALL,WALL},
    {WALL,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL,WALL,WALL,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL},
    {WALL,WALL,WALL,  0 ,WALL,WALL,  0 ,  0 ,  0 ,  0 ,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL},
    {WALL,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL},
    {WALL,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL},
    {WALL,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL},
    {WALL,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL,WALL,WALL,WALL,WALL,  0 ,WALL},
    {WALL,WALL,WALL,  0 ,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,  0 ,WALL,WALL,WALL,WALL,WALL,  0 ,WALL},
    {WALL,WALL,WALL,  0 ,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,  0 ,WALL,WALL,WALL,WALL,WALL,  0 ,WALL},
    {WALL,WALL,WALL,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,WALL},
    {WALL,WALL,WALL,WALL,WALL,WALL,  0 ,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL},
    {WALL,WALL,WALL,WALL,WALL,WALL,  0 ,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL},
    {WALL,WALL,WALL,WALL,WALL,WALL,  0 ,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL},
    {WALL,WALL,WALL,WALL,WALL,WALL,  0 ,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL},
    {WALL,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,WALL,WALL,WALL,WALL},
    {WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,  0 ,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL},
    {WALL,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,WALL},
    {WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL}
};

int absoluteDirection = 0;
int done = false;


string Stack[100] = "\0";
string ways;

string stack ( string command, string input )
{
    static int lineHolder = 0;

    if ( command == "pop" )
    {
        return Stack[(lineHolder--)-1];
    }

    else if ( command == "push" )
    {
        Stack[lineHolder++] = input;
        return "0";
    }
}



double rightSensor;
double leftSensor;
double frontSensor;
bool deathEnd = false;




enum directions
{
    NORTH = 1,
    SOUTH = -1,
    EAST = 0,
    WEST = 2
};


int FORWARD = 0;
int RIGHT = -1;
int LEFT = 1;
int BACK = 2;


struct Position
{
    int x = 1;
    int y = 1;

} pos;

void printMaze()
{
    int holder = maze[pos.y][pos.x];
    maze[pos.y][pos.x] = 'o';

    system("cls");
    for (int i=0; i<SIZE; i++)
    {
        for (int j=0; j<SIZE; j++)
        {
            switch(maze[i][j])
            {
                case WALL:
                    printf(" %c", 254);
                break;

                case 'o':
                    printf(" %c", 'o');
                break;

                default:
                    printf(" %c", ' ');
                break;
            }

        }
        printf("\n");
    }

    Sleep ( FRAME_DELAY );

    maze[pos.y][pos.x] = holder;
}



void turn ( int where )
{
    int prevFORWARD = FORWARD;
    int prevRIGHT = RIGHT;
    int prevLEFT = LEFT;
    int prevBACK = BACK;

    if ( where == FORWARD )
    {
        ;
    }
    else if ( where == RIGHT )
    {
        absoluteDirection--;

        FORWARD = prevRIGHT;
        RIGHT = prevBACK;
        LEFT = prevFORWARD;
        BACK = prevLEFT;
    }

    else if ( where == LEFT )
    {
        absoluteDirection++;

        FORWARD = prevLEFT;
        RIGHT = prevFORWARD;
        LEFT = prevBACK;
        BACK = prevRIGHT;
    }

    else if ( where == BACK )
    {
        absoluteDirection += 2;

        FORWARD = prevBACK;
        RIGHT = prevLEFT;
        LEFT = prevRIGHT;
        BACK = prevFORWARD;
    }
    else
    {
        printf("\nIn function turn(int where) %d passed to function.  FATAL ERROR", where);
        exit(-1);
    }
}



void proceed ()
{
    switch ( absoluteDirection%4 )
    {
        case 0:
            pos.x++;
            break;

        case 1: case -3:
            pos.y--;
            break;

        case 2: case -2:
            pos.x--;
            break;

        case 3: case -1:
            pos.y++;
            break;
    }

    if ( pos.x == FINISH_X && pos.y == FINISH_Y ) { done = true; }

    printMaze();
}




bool readForward()
{
    switch ( absoluteDirection%4 )
    {
        case 0:
            if ( maze[pos.y][pos.x+1] != WALL ) { return true; }
            else { return false; }
        break;

        case 1: case -3:
            if ( maze[pos.y-1][pos.x] != WALL ) { return true; }
            else { return false; }
        break;

        case 2: case -2:
            if ( maze[pos.y][pos.x-1] != WALL ) { return true; }
            else { return false; }
        break;

        case 3: case -1:
            if ( maze[pos.y+1][pos.x] != WALL ) { return true; }
            else { return false; }
        break;
    }
}


bool readRight()
{
    switch ( absoluteDirection%4 )
    {
        case 0:
            if ( maze[pos.y+1][pos.x] != WALL ) { return true; }
            else { return false; }
        break;

        case 1: case -3:
            if ( maze[pos.y][pos.x+1] != WALL ) { return true; }
            else { return false; }
        break;

        case 2: case -2:
            if ( maze[pos.y-1][pos.x] != WALL ) { return true; }
            else { return false; }
        break;

        case 3: case -1:
            if ( maze[pos.y][pos.x-1] != WALL ) { return true; }
            else { return false; }
        break;
    }
}


bool readLeft()
{
    switch ( absoluteDirection%4 )
    {
        case 0:
            if ( maze[pos.y-1][pos.x] != WALL ) { return true; }
            else { return false; }
        break;

        case 1: case -3:
            if ( maze[pos.y][pos.x-1] != WALL ) { return true; }
            else { return false; }
        break;

        case 2: case -2:
            if ( maze[pos.y+1][pos.x] != WALL ) { return true; }
            else { return false; }
        break;

        case 3: case -1:
            if ( maze[pos.y][pos.x+1] != WALL ) { return true; }
            else { return false; }
        break;
    }
}




void removeDeathEnd()
{
      turn(BACK);

      while (true)
      {
           // poplanan move da possible way ��kana kadar d�necek
            string returnWay =  stack("pop","");

            printf("\n#rde: return way is: %s\n", returnWay.c_str());
            system("pause");

            if (returnWay.length() < 2)
            {
                  // e�er poplanan move possible way i�ermiyorsa poplanan move u yap

                  if (returnWay[0] == 'r')
                  {
                      // poplanana g�re tersine d�ner ve devam eder
                      while( !readLeft() )
                      {
                        //d�z git
                        proceed();
                      }
                      //sola d�n
                      turn(LEFT);
                  }
                  else if (returnWay[0] == 'l')
                  {
                      while( !readRight() )
                      {
                         //d�z git
                         proceed();
                      }
                      //sa�a d�n��
                      turn(RIGHT);
                  }
            }

            // e�er possible way varsa
            else
            {
                  if ( returnWay[0] == 'f' )
                  {
                        if (returnWay[1] == 'r') // sa�a d�nd�ysem sol sens�r� s�rekli kontrol ediyorum
                        {
                              while ( !readLeft() )
                              {
                                  proceed();
                              }

                              returnWay[0] = returnWay[1];
                              returnWay[1] = '\0';

                              stack("push", returnWay);

                              printf("\n#rde: re-pushing: %s\n", returnWay.c_str());
                              system("pause");

                              turn(LEFT);
                        }
                        else if (returnWay[1] == 'l') // �sttekinin tam ters y�n�
                        {
                              while ( !readRight() )
                              {
                                proceed();
                              }

                              returnWay[0] = returnWay[1];
                              returnWay[1] = '\0';

                              stack("push", returnWay);

                              printf("\n#rde: re-pushing: %s\n", returnWay.c_str());
                              system("pause");

                              turn(RIGHT);
                        }
                  }
                  else
                  {
                      if(returnWay[0] == 'r')
                      {
                           while ( !readLeft() )
                           {
                               proceed();
                           }

                          returnWay[0] = returnWay[1];
                          returnWay[1] = '\0';

                          stack("push", returnWay);

                          printf("\n#rde: re-pushing: %s\n", returnWay.c_str());
                          system("pause");
                      }

                      else if(returnWay[0] == 'l')
                      {
                           while ( !readRight() )
                           {
                              proceed();
                           }

                          returnWay[0] = returnWay[1];
                          returnWay[1] = '\0';

                          stack("push", returnWay);

                          printf("\n#rde: re-pushing: %s\n", returnWay.c_str());
                          system("pause");
                      }

                      break; //bu else ten sonra possible wayin ba��na geldim
                      // bu yola daha �nce girmedi�im i�in bu fonksiyondan ��k�p normal yol alma d�ng�s�ne giriyorum
                  }
            }
        }

}

void checkPoints()
{
      if ( readRight() && readLeft() ) //(Burada hangisi daha uzaksa oraya gidiyordu)
      {
            switch ( rand()%2 )
            {
                case 0:
                    stack("push", "rl");
                    turn(RIGHT);

                    printf("\n#cp: pushed rl\n");
                    system("pause");
                break;

                case 1:
                    stack("push", "lr");
                    turn(LEFT);

                    printf("\n#cp: pushed lr\n");
                    system("pause");
                break;
            }

      }
      else if ( readRight() )
      {
            stack("push", "r");
            turn(RIGHT);

            printf("\n#cp: pushed r\n");
            system("pause");
      }
      else if ( readLeft() )
      {
            stack("push", "l");
            turn(LEFT);

            printf("#cp: pushed l\n");
            system("pause");
      }
      else if ( !readForward() )
      {
            deathEnd = true;
            printf("#cp: dead-end = true\n");
            system("pause");
      }
}



void possibleWays()
{
      if ( readRight() && readLeft() )
      {
          stack("push", "fr");
          stack("push", "fl");

          printf("\n#pw: pushed both\n");
          system("pause");
      }
      else if ( readRight() )
      {
          stack("push", "fr");
          printf("\n#pw: pushed fr\n");
          system("pause");
      }
      else if ( readLeft() )
      {
          stack("push", "fl");
          printf("\n#pw: pushed fl\n");
          system("pause");
      }
}



int main () {

    printMaze();

    while ( !done )
    {
          if ( !(deathEnd) )
          {
                while ( readForward() )
                {

                      proceed();
                      possibleWays();

                }
                checkPoints();

          }
          else
          {
                removeDeathEnd();
                deathEnd = false;
          }
    }
    printf("DONE !");
    return 0;

}
