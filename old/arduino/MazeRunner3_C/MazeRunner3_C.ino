#include <StackArray.h>
#include <String.h>

#define WALL 1
#define SIZE 20
#define INIT_X 1
#define INIT_Y 1
#define FINISH_X 18
#define FINISH_Y 18
#define FRAME_DELAY 100  //Decrement the value for less delay per step.

int maze [SIZE][SIZE] =
{
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,0,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1},
    {1,1,1,0,1,1,0,1,1,0,1,1,1,1,1,0,1,1,0,1},
    {1,1,1,0,1,1,0,0,0,0,1,1,0,1,1,0,1,1,0,1},
    {1,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1},
    {1,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1},
    {1,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1},
    {1,1,1,0,1,1,0,1,1,0,1,1,0,1,1,1,1,1,0,1},
    {1,1,1,0,0,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1},
    {1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1},
    {1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};
int absoluteDirection = 0;
int done = false;


String ways;

double rightSensor;
double leftSensor;
double frontSensor;
boolean deathEnd = false;

StackArray <String> stack;



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




void setup () 
{
    Serial.begin (250000);
}



void removeDeathEnd() 
{
    
      //motor 180 döner
      turn(BACK);
      
      while (true) 
      { 
           // poplanan move da possible way çıkana kadar dönecek
            String returnWay =  stack.pop();
        
            if (returnWay.length() < 2) 
            {
                  // eğer poplanan move possible way içermiyorsa poplanan move u yap
                  
                  if (returnWay.charAt(0) == 'r') 
                  { 
                      // poplanana göre tersine döner ve devam eder
                      while( !readLeft() )
                      {
                        //düz git
                        proceed();
                      }
                      //sola dön
                      turn(LEFT);
                  }
                  else if (returnWay.charAt(0) == 'l') 
                  {
                      while( !readRight() )
                      {
                         //düz git
                         proceed();
                      }
                      //sağa dönüş
                      turn(RIGHT);
                  }
            }
        
            // eğer possible way varsa 
            else 
            { 
                
                  if ( returnWay.charAt(0) == 'f' )
                  {
                        if (returnWay.charAt(1) == 'r') // sağa döndüysem sol sensörü sürekli kontrol ediyorum
                        { 
                              while ( !readLeft() ) 
                              {
                                  //düz git
                                  proceed();
                              }
                              //sol tarafta yol var, sola dön
                              
                              
                              //junctiondayım stacki düzeltmem gerekiyor
                              returnWay.setCharAt(0, returnWay.charAt(1)); // possible way i alınan yol olarak pushluyorum
                              returnWay.setCharAt(1, '\0'); // possible wayi sildim
                              stack.push(returnWay);
                          
                              //sola dönüş
                              turn(LEFT);
                        }
                        else if (returnWay.charAt(1) == 'l') // üsttekinin tam ters yönü
                        { 
                              while ( !readRight() ) 
                              {
                                //düz git
                                proceed();
                              }
                              //sağa dönücem
                              turn(RIGHT);
                              
                              //junctiondayım stacki düzeltmem gerekiyor
                              returnWay.setCharAt(0, returnWay.charAt(1)); // possible way i alınan yol olarak pushluyorum
                              returnWay.setCharAt(1, '\0'); // possible wayi sildim
                              stack.push(returnWay);
                        }
                  }
                  else
                  {
                      if(returnWay.charAt(0) == 'r')
                      {
                           while ( !readLeft() ) 
                           {
                               //düz git
                               proceed();
                           }
                          returnWay.setCharAt(0, returnWay.charAt(1)); // possible way i alınan yol olarak pushluyorum
                          returnWay.setCharAt(1, '\0'); // possible wayi sildim
                          stack.push(returnWay);        
                      }
            
                      else if(returnWay.charAt(0) == 'l')
                      {
                           while ( !readRight() ) 
                           {
                              //düz git
                              proceed();
                           }
                           //returnWay right olarak pushladım.
                          returnWay.setCharAt(0, returnWay.charAt(1)); // possible way i alınan yol olarak pushluyorum
                          returnWay.setCharAt(1, '\0'); // possible wayi sildim
                          stack.push(returnWay);
                      }
                  
                      break; //bu else ten sonra possible wayin başına geldim
                      // bu yola daha önce girmediğim için bu fonksiyondan çıkıp normal yol alma döngüsüne giriyorum
                  }
            }
        }
}       
void checkPoints()
{
      //Serial.println("function checkPoints requested.");
      //daha mantıklı sayılar doubke a göre ayarla. tmm.
      if ( readRight() && readLeft() )
      {
            switch ( rand()%2 )
            {
                case 0:
                    //ways[1] null eklemem gerekiyor mu ? bilmem.
                    stack.push("rl");
                    //sağa dön
                    turn(RIGHT);
                break;
                
                case 1:
                
                    stack.push("lr");
                    //sola dön
                    turn(LEFT);
                break;
            }
    
      }
      else if ( readRight() )
      {
            stack.push("r");
            //sağa dön
            turn(RIGHT);
      }
      else if ( readLeft() )
      {
            stack.push("l");
            //sola dön
            turn(LEFT);
      }
      else if ( !readForward() && !readRight()  && !readLeft() )
      {
            //deathend ise
            deathEnd = true;
      }
}



void possibleWays()
{
      if ( readRight() && readLeft() )
      {
          //Serial.println("in possibleWays: condition#1");
          stack.push("fr");
          stack.push("fl");
      }
      else if ( readRight() )
      {
          //Serial.println("in possibleWays: condition#2");
          stack.push("fr");
      }
      else if ( readLeft() )
      {
          //Serial.println("in possibleWays: condition#3");
          stack.push("fl");
      }
      
}

void clearScreen() 
{
    Serial.println(" ");
    Serial.println("-------------------------------------------");
    Serial.println(" ");
}

void printMaze()
{
    int holder = maze[pos.y][pos.x];
    maze[pos.y][pos.x] = 'o';

    clearScreen();
    for (int i=0; i<SIZE; i++)
    {
        for (int j=0; j<SIZE; j++)
        {
            Serial.print(" ");
            switch(maze[i][j])
            {
                case WALL:
                    Serial.print("X");
                break;

                case 'o':
                    Serial.print("o");
                break;

                default:
                    Serial.print(" ");
                    break;
            }
            
        }
        Serial.println();
    }

//    Serial.print("pos: ");
//    Serial.print(pos.x);
//    Serial.print(",");
//    Serial.println(pos.y);
//    Serial.println(absoluteDirection);
//    Serial.print("f:"); Serial.print(readForward()); Serial.print(" "); Serial.print("r:"); Serial.print(readRight()); Serial.print(" "); Serial.print("l:"); Serial.println(readLeft()); 

    delay(250);
    maze[pos.y][pos.x] = holder;
}



void turn ( int where )
{
    //Serial.print("function turn requested with the direction: ");
    //Serial.println(where);
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
        default:
            Serial.println("ERROR reading sensory input! /f");
            
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
        default:
            Serial.println("ERROR reading sensory input! /r");
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
        default:
            Serial.println("ERROR reading sensory input! /l");
    }
}






void loop () {

        
    printMaze();
    deathEnd = false;
    

    
    while ( !done )
    {
    
          if ( !(deathEnd) )
          {
                while ( readForward() )
                {
                      //motor düz çalıştır
                      proceed();
                      
                      // right, left sensor bilgilerini al saniyede bir
                      possibleWays();
                }
                //Serial.println("Exited while(readForward())");
                checkPoints();
        
          }
          else
          {
                //while: bir possible wayde daha fazla ilerleyemiyorsan diğer possible a bak. varsa diğerine gerek yok.
                //possiblewaysleri ziyaret etmesi için
                //deathendler karışıyor.DENEEEĞĞĞĞĞĞĞ
            
            
                //motor düz, normale göre yavaş çalışsın
                
                
                // checkPoints(); // deathEnd true ise checkPoints yapmaya gerek yok
                removeDeathEnd();
                deathEnd = false;
          }
        
    
    }
    Serial.println("DONE !");
    return 0;

}
