/* 
 *  #define XXXX YYYY komutu, kod derlenmeden önce koddaki bütün XXXX ifadelerini YYYY ile değiştirir.
 *  Örneğin, ilk satırdaki ( #define MOTOR1_A 5 ) komutu koddaki bütün MOTOR1_A ifadesini 5 sayısı ile değiştirecektir. 
 *  Bu şekilde isimlendirmeler kodun düzenli ve anlaşılabilir olmasını sağlar. 
*/

#define MOTOR1_A 5
#define MOTOR1_B 6
#define MOTOR2_A 10
#define MOTOR2_B 11
//Motor pinlerinin tanımlanması. İki motorun da ( motor A, motor B ) hangi girişinin hangi Arduino pini ile kontrol edileceği belirlendi. 

#define TRIG_PIN 3
#define ECHO_PIN 9
//HC_SR 04 ultrasonik mesafe sensörünün kontrol pinlerinin hangi Arduino pinine bağlı olacağının belirlenmesi.

#define TURN_DELAY 500
//Aracın 90° dönebilmesi için ne kadar süre boyunca motorların birbirne ters yönde çalışmasını belirleyen süre değeri ( milisaniye ).

#define SPEED 175
//Motorlara analog olarak ne kadar güç verileceğinin tanımlanması. ( Arduino'nun analog (PWM) çıkışı 0-255 arasında değerler alır. ( 0->0V, 255->5V )




int distance() 
{
    // Sensörün vericisinden çıkan ses dalgasının herhangi bir engele çarpıp alıcıya geri dönme süresini ölçerek ve üzerinde matematiksel hesaplamalar yaparak mesafenin ölçülmesi.
  
    long duration;
    int dis;
    
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
    
    duration = pulseIn(ECHO_PIN, HIGH);
    dis = duration*0.034/2;
  
    return dis;
}


// Aşağıdaki dört fonksiyon, gereken şekilde motorları sürerek aracın temel hareketlerini oluşturacaktır.

void forward ( int vel ) //İki motor da ileri.
{
    analogWrite ( MOTOR1_A, vel );
    analogWrite ( MOTOR2_A, vel );
  
    digitalWrite ( MOTOR1_B, LOW );
    digitalWrite ( MOTOR2_B, LOW );
}

void backward ( int vel ) //İki motor da geri.
{
    analogWrite ( MOTOR1_B, vel );
    analogWrite ( MOTOR2_B, vel );
  
    digitalWrite ( MOTOR1_A, LOW );
    digitalWrite ( MOTOR2_A, LOW );
}

void right ( int vel )  //Sağ motor geri, sol motor iler.
{
    digitalWrite ( MOTOR1_B, LOW );
    digitalWrite ( MOTOR2_A, LOW );
    
    analogWrite ( MOTOR1_A, vel );
    analogWrite ( MOTOR2_B, vel );
    
    delay ( TURN_DELAY );
    
    analogWrite ( MOTOR1_A, 0 );
    analogWrite ( MOTOR2_B, 0 );
}

void left ( int vel )  //Sol motor geri, sağ motor ileri.
{
    digitalWrite ( MOTOR1_A, LOW );
    digitalWrite ( MOTOR2_B, LOW );
    
    analogWrite ( MOTOR1_B, vel );
    analogWrite ( MOTOR2_A, vel );
  
    delay ( TURN_DELAY );
  
    analogWrite ( MOTOR1_B, 0 );
    analogWrite ( MOTOR2_A, 0 );
}

void idle()  //Motorları durdur.
{
    digitalWrite ( MOTOR1_A, LOW );
    digitalWrite ( MOTOR1_B, LOW );
    digitalWrite ( MOTOR2_A, LOW );
    digitalWrite ( MOTOR2_B, LOW );
}


void setup()
{
    pinMode(MOTOR1_A, OUTPUT);  
    pinMode(MOTOR1_B, OUTPUT); 
    pinMode(MOTOR2_A, OUTPUT); 
    pinMode(MOTOR2_B, OUTPUT); 
  
    pinMode(TRIG_PIN, OUTPUT); 
    pinMode(ECHO_PIN, INPUT); 
    Serial.begin(9600); 
}


void loop()
{
     while(distance()>5)
     {
        forward(SPEED);
     }
     // 5cm'den yakın bir engel olmadığı sürece araç ileriye gidecektir.
     
     int choice = rand()%2 + 1 ;  //Aracın rastgele sağa ya da sola dönmesi için, 1 ve 2 sayılarıdan birinin rastgele seçilmesi.

     if(choice==1)
     {
        right(SPEED);
     }
     if(choice==2)
     {
        left(SPEED);
     }
}
