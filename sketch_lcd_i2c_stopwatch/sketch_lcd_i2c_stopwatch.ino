#include <LiquidCrystal_I2C.h>
#include <CountDown.h>
#include <avr/sleep.h>
#include <Tone.h>
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
CountDown timer;
Tone buzzerTone;
float desiredTime = 0;
bool timeButtonPressed = false, cancelButtonPressed = false;
const int buzzerPin = 8, potentiometerPin = A0, timeButtonPin = 2, cancelButtonPin = 7;
const int buttonCheckPeriod = 20;
void setup()
{
  set_sleep_mode (SLEEP_MODE_PWR_DOWN);  
  sleep_enable();
  buzzerTone.begin(buzzerPin);
  pinMode(buzzerPin, OUTPUT);
  pinMode(potentiometerPin, INPUT);  
  pinMode(timeButtonPin, INPUT);   
  pinMode(cancelButtonPin, INPUT);
  lcd.init(); 
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("How many second?");
  takeUserInput();
}


void loop()
{
  if (timeButtonPressed) {
    if (timer.remaining() > 0) {
      lcd.clear();
      lcd.print("Remaining: " + String(timer.remaining()));
      lcd.setCursor(0, 0);
    } else {
      lcd.clear();
      lcd.print("Remaining: " + String(timer.remaining()));
      lcd.setCursor(0, 0);
      lcd.setCursor(0, 1);
      lcd.print("Completed!");
      lcd.blink();
      buzzUser();
      sleep_cpu();
    }
  }
}

void takeUserInput() {
   while (!timeButtonPressed) {
    int sensorValue = analogRead(potentiometerPin); // read potentiometer value
    desiredTime = map(sensorValue, 0, 1023, 0, 255); //calculate value
    lcd.setCursor(0, 1);
    lcd.print(String(desiredTime)); //display current user choice 
    if (digitalRead(timeButtonPin)) {
      timeButtonPressed = true;
    }
  }
  timer.start(0, 0, 0, desiredTime);  //start timer
}

void buzzUser() {
    
    //playing fur elise by beethoven
  buzzerTone.play(NOTE_E4, 300);
  delay(350);
  buzzerTone.play(NOTE_DS4, 300);
  delay(350);
  buzzerTone.play(NOTE_E4, 300);
  delay(350);
  buzzerTone.play(NOTE_DS4, 300);
  delay(350);
  buzzerTone.play(NOTE_E4, 300);
  delay(350);
  buzzerTone.play(NOTE_B3, 300);
  delay(400);
  buzzerTone.play(NOTE_D4, 300);
  delay(400);
  buzzerTone.play(NOTE_C4, 300);
  delay(400);
  buzzerTone.play(NOTE_A4, 900);
  delay(1000);
  buzzerTone.play(NOTE_D3, 300);
  delay(350);
  buzzerTone.play(NOTE_F3, 300);
  delay(400);
  buzzerTone.play(NOTE_A3, 300);
  delay(400);
  buzzerTone.play(NOTE_B3, 900);
  delay(1000);
  buzzerTone.play(NOTE_F3, 300);
  delay(400);
  buzzerTone.play(NOTE_A3, 900);
  delay(1000);
  buzzerTone.play(NOTE_AS3, 300);
  delay(400);
  buzzerTone.play(NOTE_B3, 300);
  delay(400);
  buzzerTone.play(NOTE_C4, 900);
  delay(1000);
  delay(300);
  buzzerTone.play(NOTE_E4, 300);
  delay(400);
  buzzerTone.play(NOTE_DS4, 300);
  delay(400);
  buzzerTone.play(NOTE_E4, 300);
  delay(400);
  buzzerTone.play(NOTE_DS4, 300);
  delay(400);
  buzzerTone.play(NOTE_E4, 300);
  delay(400);
  buzzerTone.play(NOTE_B3, 300);
  delay(400);
  buzzerTone.play(NOTE_D4, 300);
  delay(400);
  buzzerTone.play(NOTE_C4, 300);
  delay(400);
  buzzerTone.play(NOTE_A3, 900);
  delay(1000);
  buzzerTone.play(NOTE_D3, 300);
  delay(400);
  buzzerTone.play(NOTE_F3, 300);
  delay(400);
  buzzerTone.play(NOTE_A3, 300);
  delay(400);
  buzzerTone.play(NOTE_B3, 900);
  delay(1000);
  buzzerTone.play(NOTE_F3, 300);
  delay(400);
  buzzerTone.play(NOTE_C4, 300);
  delay(400);
  buzzerTone.play(NOTE_B3, 300);
  delay(400);
  buzzerTone.play(NOTE_A3, 900);
  delay(1000);
  buzzerTone.play(NOTE_B3, 300);
  delay(400);
  buzzerTone.play(NOTE_C4, 300);
  delay(400);
  buzzerTone.play(NOTE_D4, 300);
  delay(400);
  buzzerTone.play(NOTE_E4, 900);
  delay(1000);
  buzzerTone.play(NOTE_G3, 300);
  delay(400);
  buzzerTone.play(NOTE_F4, 300);
  delay(400);
  buzzerTone.play(NOTE_E4, 300);
  delay(400);
  buzzerTone.play(NOTE_D4, 900);
  delay(1000);
  buzzerTone.play(NOTE_E3, 300);
  delay(400);
  buzzerTone.play(NOTE_E4, 300);
  delay(400);
  buzzerTone.play(NOTE_D4, 300);
  delay(400);
  buzzerTone.play(NOTE_C4, 900);
  delay(1000);
  buzzerTone.play(NOTE_D3, 300);
  delay(400);
  buzzerTone.play(NOTE_D4, 300);
  delay(400);
  buzzerTone.play(NOTE_C4, 300);
  delay(400);
  buzzerTone.play(NOTE_B3, 900);
  delay(1000);
  buzzerTone.play(NOTE_E4, 300);
  delay(400);
  buzzerTone.play(NOTE_DS4, 300);
  delay(350);
  buzzerTone.play(NOTE_E4, 300);
  delay(350);
  buzzerTone.play(NOTE_DS4, 300);
  delay(350);
  buzzerTone.play(NOTE_E4, 300);
  delay(350);
  buzzerTone.play(NOTE_B3, 300);
  delay(400);
  buzzerTone.play(NOTE_D4, 300);
  delay(400);
  buzzerTone.play(NOTE_C4, 300);
  delay(400);
  buzzerTone.play(NOTE_A3, 900);
  delay(1000);
  buzzerTone.play(NOTE_D3, 300);
  delay(400);
  buzzerTone.play(NOTE_F3, 300);
  delay(400);
  buzzerTone.play(NOTE_A3, 300);
  delay(400);
  buzzerTone.play(NOTE_B3, 900);
  delay(1000);
  buzzerTone.play(NOTE_F3, 300);
  delay(400);
  buzzerTone.play(NOTE_A3, 300);
  delay(400);
  buzzerTone.play(NOTE_B3, 300);
  delay(400);
  buzzerTone.play(NOTE_C4, 900);
  delay(1000);
  delay(300);
  buzzerTone.play(NOTE_E4, 300);
  delay(400);
  buzzerTone.play(NOTE_DS4, 300);
  delay(400);
  buzzerTone.play(NOTE_E4, 300);
  delay(400);
  buzzerTone.play(NOTE_DS4, 300);
  delay(400);
  buzzerTone.play(NOTE_E4, 300);
  delay(400);
  buzzerTone.play(NOTE_B3, 300);
  delay(400);
  buzzerTone.play(NOTE_D4, 300);
  delay(400);
  buzzerTone.play(NOTE_C4, 300);
  delay(400);
  buzzerTone.play(NOTE_A3, 900);
  delay(1000);
  buzzerTone.play(NOTE_D3, 300);
  delay(400);
  buzzerTone.play(NOTE_F3, 300);
  delay(400);
  buzzerTone.play(NOTE_A3, 300);
  delay(400);
  buzzerTone.play(NOTE_B3, 900);
  delay(1000);
  buzzerTone.play(NOTE_F3, 300);
  delay(400);
  buzzerTone.play(NOTE_C4, 300);
  delay(400);
  buzzerTone.play(NOTE_B3, 300);
  delay(400);
  buzzerTone.play(NOTE_A3, 900);
  delay(1000);

  delay(5000);  

  
}
