#include <Stepper.h>

const int stepsPerRevolution = 2048;  //Dependent on stepper you are using, check datasheet.

Stepper stepper(stepsPerRevolution, 27, 26, 25, 33); // This should have been as in1, in2, in3, in4 but for some reason it does not work like that but works on this arrange. IDK...
  

  
void setup() 
{
  stepper.setSpeed(10);  // Setting the rpm of the stepper motor, check datasheet to find on what range of rmp your stepper can work.
}




void loop()
{    

    for(;;)
    {
        stepper.step(25);
        
    }
          
  


}
