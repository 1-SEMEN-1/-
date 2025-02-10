#include <Servo.h>
Servo servo;
 
void setup() { 
 servo.attach(9);
} 

void loop() { 
// rotate counter-clockwise full-speed
servo.writeMicroseconds(1500);
delay(2000);

// rotation stopped
servo.writeMicroseconds(1500);
delay(1000);

// rotate clockwise full-speed
servo.writeMicroseconds(2000);
delay(2000);

// rotation stopped
servo.writeMicroseconds(1500);
delay(1000);
}
