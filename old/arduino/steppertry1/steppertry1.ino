#include <Stepper.h>
#define STEPS 2038

Stepper stepper(STEPS, 4, 5, 6, 7);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  stepper.setSpeed(15);
  stepper.step(2036); //2038
  
  
 
}
