#include <StackArray.h>
#include <String.h>

String ways;
// declare a string message.
double rightSensor;
double leftSensor;
double frontSensor;
boolean deathEnd=false;
boolean twoWayCheckLeft=false;
boolean twoWayCheckRight=false;

// create a stack of characters.
StackArray <String> stack;

// startup point entry (runs once).
void setup () {
  // start serial communication.
  Serial.begin (9600);

  // set the printer of the stack.
  stack.setPrinter (Serial);

}



void removeDeathEnd(){

    while(true){ // poplanan move da possible way ��kana kadar d�necek
      String returnWay =  stack.pop();

      if(returnWay.length()<2){ // e�er poplanan move possible way i�ermiyorsa poplanan move u yap
        while(frontSensor >2){
          //d�z git
            if(frontSensor>2 && leftSensor>2)
            {
              twoWayCheckLeft=true;
              break;
            }
            else if(frontSensor>2 && rightSensor>2)
            {
              twoWayCheckRight=true;
              break;
            }

          }
          if(twoWayCheckLeft)
          {

            //d�z gider
            stack.push("l");
            twoWayCheckLeft=false;
          }
          else if(twoWayCheckRight)
          {
            if(returnWay.charAt(0) == 'l')
            {
               //d�z gider
               stack.push("r");
            }
            //else
            //{
            //}



            twoWayCheckRight=false;
          }
          else if(returnWay.charAt(0) == 'r'){ // poplanana g�re tersine d�ner ve devam eder
            //sola d�n
            }
          else if(returnWay.charAt(0) == 'l'){
            //sa�a d�n
            }

        }
      else{ // e�er possible way varsa
          if(returnWay.charAt(1)=='r'){ // sa�a d�nd�ysem sol sens�r� s�rekli kontrol ediyorum
            while(leftSensor<2){
            //d�z git
            }
            //sol tarafta yol var
            //junctionday�m stacki d�zeltmem gerekiyor
            //sola d�n
            returnWay.setCharAt(0,returnWay.charAt(1)); // possible way i al�nan yol olarak pushluyorum
            returnWay.setCharAt(1, '\0'); // possible wayi sildim (\0 null demek)
            stack.push(returnWay);

          }
          else if(returnWay.charAt(1)=='l'){ // �sttekinin tam ters y�n�
            while(rightSensor<2){
            //d�z git
            }
            //junctionday�m stacki d�zeltmem gerekiyor
            //sa�a d�n
            returnWay.setCharAt(0,returnWay.charAt(1)); // possible way i al�nan yol olarak pushluyorum
            returnWay.setCharAt(1, '\0'); // possible wayi sildim
            stack.push(returnWay);

          }
        break; //bu else ten sonra possible wayin ba��na geldim
        // bu yola daha �nce girmedi�im i�in bu fonksiyondan ��k�p normal yol alma d�ng�s�ne giriyorum

    }

  }
}

void checkPoints()
{

      //daha mant�kl� say�lar doubke a g�re ayarla.
    if(rightSensor >2 && leftSensor > 2)
    {
      if(rightSensor> leftSensor)
      {
        //sa�a d�n
        //ways[1] null eklemem gerekiyor mu ?
        stack.push("r");
      }
      else
      {
        //sola d�n
        stack.push("l");
      }

    }
    else if (rightSensor > 2 )
    {
        //sa�a d�n
        stack.push("r");
    }
    else if( leftSensor > 2)
    {
        //sola d�n
        stack.push("l");
    }
    else if((frontSensor == 2) && rightSensor ==2  && leftSensor ==2)
    {
      //deathend ise
      //motor 180 d�ner.
      deathEnd = true;

    }

}


// loop the main sketch.
void possibleWays(int rightSensor, int leftSensor)
{
  if(rightSensor >2)
  {

    stack.push("fr");
  }
  else if(leftSensor > 2)
  {

    stack.push("fl");
  }
  else if(rightSensor >2 && leftSensor > 2 )
  {

    stack.push("fr");


    stack.push("fl");
  }
}


void loop () {

 if(!(deathEnd))
 {
    while(frontSensor >2)
    {
    //motor d�z �al��t�r
    // right, left sensor bilgilerini al saniyede bir
      if(frontSensor>5)
      {
        //checkPOintleri possibleways olarak atmas�n diye. //ama mant�ken kontrol et.
         possibleWays(rightSensor, leftSensor);
      }

    }
    checkPoints();

 }
 else
 {
    //motor d�z, normale g�re yava� �al��s�n

    removeDeathEnd();
    deathEnd= false;

 }



}
