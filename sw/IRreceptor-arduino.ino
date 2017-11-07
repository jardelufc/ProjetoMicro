// IR Receiver Code...
#include <IRremote.h>
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(3, 4, 5, 7, 6, 8);

int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(53,OUTPUT); // Led outputs ...
  pinMode(51,OUTPUT);
  pinMode(49,OUTPUT);
  lcd.print("IR Waiting...");
}
void turnoff() {
  digitalWrite(53,LOW);
  digitalWrite(51,LOW);
  digitalWrite(49,LOW);
  }
void loop() {
  lcd.setCursor(0,1);
  if (irrecv.decode(&results)) {
    Serial.println(results.value);
    lcd.print(results.value);
    if(results.value == 881415973)
     {
      turnoff();
      digitalWrite(53,HIGH);
      }

       if(results.value == 1451704665)
     {
      turnoff();
      digitalWrite(51,HIGH);
      }


       if(results.value == 356939811)
     {
      turnoff();
      digitalWrite(49,HIGH);
      }

          if(results.value == 948321248)
     {
      turnoff();
      digitalWrite(49,HIGH);
      }

          if(results.value == 948321232)
     {
      turnoff();
      digitalWrite(51,HIGH);
      }

          if(results.value == 948321264 )
     {
      turnoff();
      digitalWrite(53,HIGH);
      }

    



    
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}
