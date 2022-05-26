#include <string>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#define FRAME_DELAY 100  //Decrement the value for less delay per step.

#define WALL 32787
#define SIZE 20
#define INIT_X 1
#define INIT_Y 1
#define FINISH_X 18
#define FINISH_Y 18

using namespace std;

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


int turn ( int where )
{
    int prevFORWARD = FORWARD;
    int prevRIGHT = RIGHT;
    int prevLEFT = LEFT;
    int prevBACK = BACK;

    if ( where == RIGHT )
    {
        analogWrite ( RIGHT_MOTOR_F, speed - SLOW_DOWN );
        delay ( XXXX );
        analogWrite ( RIGHT_MOTOR_F, speed );
    }

    else if ( where == LEFT )
    {
        analogWrite ( LEFT_MOTOR_F, speed - SLOW_DOWN );
        delay ( XXXX );
        analogWrite ( LEFT_MOTOR_F, speed );

    }

    else if ( where == BACK )
    {
        analogWrite ( RIGHT_MOTOR_F, speed );
        analogWrite ( LEFT_MOTOR_B, speed );
        delay ( XXXX );
        analogWrite ( LEFT_MOTOR_F, speed );

    }
    else
    {
        return -1;
    }
}



void proceed ()
{
    analogWrite ( RIGHT_MOTOR_B, 0 );
    analogWrite ( LEFT_MOTOR_B, 0 );

    analogWrite ( RIGHT_MOTOR_F, speed );
    analogWrite ( LEFT_MOTOR_F, speed );
}




int readForward()
{
    Wire.beginTransmission(ADDRESS);
    Wire.write(byte(DISTANCE_ADDR));
    Wire.endTransmission();

    Wire.requestFrom(ADDRESS, 2);

    if (2 <= Wire.available())
    {
        distance_raw[0] = Wire.read();
        distance_raw[1] = Wire.read();

        distance_cm = (distance_raw[0] * 16 + distance_raw[1]) / 16 / (int)pow(2, shift);

        return distance_cm;
    }
    else
    {
        return -1;
    }
}


int readRight()
{
    return analogRead ( RIGHT_SENSOR );
}


int readLeft()
{
    return analogRead ( LEFT_SENSOR );
}




void removeDeathEnd()
{
    turn(BACK);

    while (true)
    {
        // poplanan move da possible way ��kana kadar d�necek
        string returnWay =  stack("pop","");

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
            break;

            case 1:
                stack("push", "lr");
                turn(LEFT);
            break;
        }

    }
    else if ( readRight() )
    {
        stack("push", "r");
        turn(RIGHT);
    }
    else if ( readLeft() )
    {
        stack("push", "l");
        turn(LEFT);
    }
    else if ( !readForward() )
    {
        deathEnd = true;
    }
}



void possibleWays()
{
    if ( readRight() && readLeft() )
    {
        stack("push", "fr");
        stack("push", "fl");
    }
    else if ( readRight() )
    {
        stack("push", "fr");
    }
    else if ( readLeft() )
    {
        stack("push", "fl");
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
