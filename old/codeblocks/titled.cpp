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

    while(true){ // poplanan move da possible way çýkana kadar dönecek
      String returnWay =  stack.pop();

      if(returnWay.length()<2){ // eðer poplanan move possible way içermiyorsa poplanan move u yap
        while(frontSensor >2){
          //düz git
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

            //düz gider
            stack.push("l");
            twoWayCheckLeft=false;
          }
          else if(twoWayCheckRight)
          {
            if(returnWay.charAt(0) == 'l')
            {
               //düz gider
               stack.push("r");
            }
            //else
            //{
            //}



            twoWayCheckRight=false;
          }
          else if(returnWay.charAt(0) == 'r'){ // poplanana göre tersine döner ve devam eder
            //sola dön
            }
          else if(returnWay.charAt(0) == 'l'){
            //saða dön
            }

        }
      else{ // eðer possible way varsa
          if(returnWay.charAt(1)=='r'){ // saða döndüysem sol sensörü sürekli kontrol ediyorum
            while(leftSensor<2){
            //düz git
            }
            //sol tarafta yol var
            //junctiondayým stacki düzeltmem gerekiyor
            //sola dön
            returnWay.setCharAt(0,returnWay.charAt(1)); // possible way i alýnan yol olarak pushluyorum
            returnWay.setCharAt(1, '\0'); // possible wayi sildim (\0 null demek)
            stack.push(returnWay);

          }
          else if(returnWay.charAt(1)=='l'){ // üsttekinin tam ters yönü
            while(rightSensor<2){
            //düz git
            }
            //junctiondayým stacki düzeltmem gerekiyor
            //saða dön
            returnWay.setCharAt(0,returnWay.charAt(1)); // possible way i alýnan yol olarak pushluyorum
            returnWay.setCharAt(1, '\0'); // possible wayi sildim
            stack.push(returnWay);

          }
        break; //bu else ten sonra possible wayin baþýna geldim
        // bu yola daha önce girmediðim için bu fonksiyondan çýkýp normal yol alma döngüsüne giriyorum

    }

  }
}

void checkPoints()
{

      //daha mantýklý sayýlar doubke a göre ayarla.
    if(rightSensor >2 && leftSensor > 2)
    {
      if(rightSensor> leftSensor)
      {
        //saða dön
        //ways[1] null eklemem gerekiyor mu ?
        stack.push("r");
      }
      else
      {
        //sola dön
        stack.push("l");
      }

    }
    else if (rightSensor > 2 )
    {
        //saða dön
        stack.push("r");
    }
    else if( leftSensor > 2)
    {
        //sola dön
        stack.push("l");
    }
    else if((frontSensor == 2) && rightSensor ==2  && leftSensor ==2)
    {
      //deathend ise
      //motor 180 döner.
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
    //motor düz çalýþtýr
    // right, left sensor bilgilerini al saniyede bir
      if(frontSensor>5)
      {
        //checkPOintleri possibleways olarak atmasýn diye. //ama mantýken kontrol et.
         possibleWays(rightSensor, leftSensor);
      }

    }
    checkPoints();

 }
 else
 {
    //motor düz, normale göre yavaþ çalýþsýn

    removeDeathEnd();
    deathEnd= false;

 }



}
