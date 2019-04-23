#include <LiquidCrystal.h>
#include <Servo.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

Servo myservo;

int timerlenght = 3600;
int buzzpin = 13;
int timeleft = 30;
int pos = 130;
int flexpin = 0;
int previousmillis = 0;

int pass1 = 1;
int pass2 = 1;
int pass3 = 1;
int pass4 = 1;

int key1 = 0;
int key2 = 0;
int key3 = 0;
int key4 = 0;

int currentkey = 1;

int button1pin = 5;
int button2pin = 4;
int button3pin = 3;
int button4pin = 2;

int keydown = 0;

int locked = 0;

unsigned long startTime = millis ();
unsigned long interval = 1000;

void setup() {

  lcd.begin(16, 2);
  pinMode (buzzpin, OUTPUT);
  myservo.attach(6);
  Serial.begin(9600); 
  
  pinMode(button1pin, INPUT_PULLUP);  
  pinMode(button2pin, INPUT_PULLUP);  
  pinMode(button3pin, INPUT_PULLUP);  
  pinMode(button4pin, INPUT_PULLUP);  
  
}

void loop() {

if (millis () - startTime >= interval)
  {
  timeleft -= 1;
  startTime = millis();
  }

  myservo.write(pos);
  
  int flex = analogRead(flexpin); 

  
  lcd.setCursor(0, 0);
  lcd.print("Password: ");

  //if(key1 != 0) {
    lcd.print(key1);
  //}

//  if(key2 != 0) {
    lcd.print(key2);
 // }
  
 // if(key3 != 0) {
    lcd.print(key3);
  //}

  //if(key4 != 0) {
    lcd.print(key4);
  //}
  
  lcd.setCursor(0, 1);
  lcd.print("Doom in ");
  lcd.print(timeleft);

  Serial.println(flex);

  if (flex <= 370) {
    timeleft = 30;
  }

  if (timeleft <= 0) {
    digitalWrite(buzzpin, HIGH);
  }

  if (timeleft > 0) {
    digitalWrite(buzzpin, LOW);
  }

  if (digitalRead(button1pin) == LOW and keydown == 0)
  {
    keydown = 1;
    buttondown(1);
  }

  if (digitalRead(button2pin) == LOW and keydown == 0)
  {
    keydown = 1;
    buttondown(2);
  }

  if (digitalRead(button3pin) == LOW and keydown == 0)
  {
    keydown = 1;
    buttondown(3);
  }

  if (digitalRead(button4pin) == LOW and keydown == 0)
  {
    keydown = 1;
    buttondown(4);
  }

  if (digitalRead(button1pin) == HIGH and digitalRead(button2pin) == HIGH and digitalRead(button3pin) == HIGH and digitalRead(button4pin) == HIGH) {
    keydown = 0;
  }

  if (currentkey == 5) {
    
    currentkey = 1;
    
    if (locked == 1) {
    checkpassword();
    } 
    else if (locked == 0) {
      pass1 = key1;
      pass2 = key2;
      pass3 = key3;
      pass4 = key4;
      locked = 1;
      pos = 45;

      key1 = 0;
      key2 = 0;
      key3 = 0;
      key4 = 0;
    }

  }
  
}

void buttondown(int num) {

  if (num == 1) {
    
    if (currentkey == 1){
      key1 = 1;
      currentkey += 1;
    }
    else if (currentkey == 2){
      key2 = 1;
      currentkey += 1;
    }
    else if (currentkey == 3){
      key3 = 1;
      currentkey += 1;
    }
    else if (currentkey == 4){
      key4 = 1;
      currentkey += 1;
    }

  }

  if (num == 4) {
    
    if (currentkey == 1){
      key1 = 4;
      currentkey += 1;
    }
    else if (currentkey == 2){
      key2 = 4;
      currentkey += 1;
    }
    else if (currentkey == 3){
      key3 = 4;
      currentkey += 1;
    }
    else if (currentkey == 4){
      key4 = 4;
      currentkey += 1;
    }

  }

  if (num == 2) {
    
    if (currentkey == 1){
      key1 = 2;
      currentkey += 1;
    }
    else if (currentkey == 2){
      key2 = 2;
      currentkey += 1;
    }
    else if (currentkey == 3){
      key3 = 2;
      currentkey += 1;
    }
    else if (currentkey == 4){
      key4 = 2;
      currentkey += 1;
    }

  }

  if (num == 3) {
    
    if (currentkey == 1){
      key1 = 3;
      currentkey += 1;
    }
    else if (currentkey == 2){
      key2 = 3;
      currentkey += 1;
    }
    else if (currentkey == 3){
      key3 = 3;
      currentkey += 1;
    }
    else if (currentkey == 4){
      key4 = 3;
      currentkey += 1;
    }

  }
  
}

void checkpassword() {
  if (key1 == pass1 and key2== pass2 and key3 == pass3 and key4 == pass4) {
    pos = 130;
    locked = 0;
  } 

  key1 = 0;
  key2 = 0;
  key3 = 0;
  key4 = 0;
  
}
