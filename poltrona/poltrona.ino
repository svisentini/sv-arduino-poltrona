/*
    Versao...: 1.4
    Data.....: 28/11/2021
    Autor....: Sidney Visentini        
             _
            | |
           _| |_
          |     |  sensorCimaMotor2
          |     |
          |  2  |
          |     |  sensorBaixoMotor2
          ------- 

             _
            | |
           _| |_
          |     |  sensorCimaMotor1
          |     |
          |  1  |
          |     |  sensorBaixoMotor1
          ------- 


*/

#include <LiquidCrystal.h>
const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


// Button State
const int ACTIVE = 0;

// Sensor State
const int PRESENT = 1;
const int OUT     = 0; 

// Inputs
int UP_BUTTON    = 52;   //  -> Botao de Subir
int DOWN_BUTTON  = 50;   //  -> Botao de Descer

int SENSOR_BOTON_MOTOR1 = 46;  
int SENSOR_TOP_MOTOR1   = 48;  
int SENSOR_BOTON_MOTOR2 = 42;  
int SENSOR_TOP_MOTOR2   = 44;  

// Outputs
int OUT1MOTOR1 = 24;
int OUT2MOTOR1 = 26;
int OUT1MOTOR2 = 28;
int OUT2MOTOR2 = 30;

int REFERENCE_5V = 40;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("----    M1: 0 0 ");   // 12,0  14,0 
  lcd.setCursor(0, 1);
  lcd.print("----    M2: 0 0 ");   // 12,1  14,1

  // Output motor pins
  pinMode(OUT1MOTOR1, OUTPUT);
  pinMode(OUT2MOTOR1, OUTPUT);
  pinMode(OUT1MOTOR2, OUTPUT);
  pinMode(OUT2MOTOR2, OUTPUT);
  pinMode(REFERENCE_5V, OUTPUT);

  // Input Buttons
  pinMode(UP_BUTTON, INPUT);
  pinMode(DOWN_BUTTON, INPUT);

  // Input Sensors
  pinMode(SENSOR_BOTON_MOTOR1, INPUT);
  pinMode(SENSOR_TOP_MOTOR1, INPUT);
  pinMode(SENSOR_BOTON_MOTOR2, INPUT);
  pinMode(SENSOR_TOP_MOTOR2, INPUT);
}

void loop() {

  digitalWrite(REFERENCE_5V, HIGH);

  if (digitalRead(UP_BUTTON) == ACTIVE){
      lcd.setCursor(0, 0);
      lcd.print(">>>>");
      upMoviment();
  } else {
      if (digitalRead(DOWN_BUTTON) == ACTIVE){
           lcd.setCursor(0, 0);
           lcd.print("<<<<");
           downMoviment();
      } else {
           lcd.setCursor(0, 0);
           lcd.print("----");
           stopMoviment();
      }
  }
  
  

  // ===========================================================
  
  showMotorData();
  showSensorData();

  delay(150);

}

void upMoviment(){
  if (digitalRead(SENSOR_TOP_MOTOR1) == OUT){
      stopMotor2();
      upMotor1();
  }
  else{
      stopMotor1();
      upMotor2();  
  }
}

void downMoviment(){
  if (digitalRead(SENSOR_BOTON_MOTOR2) == OUT){
      stopMotor1();
      downMotor2();
  }
  else{
      stopMotor2();
      downMotor1(); 
  } 
}

void stopMoviment(){
  stopMotor1();
  stopMotor2();
}

void upMotor1(){
  if (digitalRead(SENSOR_TOP_MOTOR1) == OUT){
      digitalWrite(OUT1MOTOR1, HIGH);
      digitalWrite(OUT2MOTOR1, LOW);
  } else {
    stopMotor1();
    upMotor2();
  }
}

void downMotor1(){
  if (digitalRead(SENSOR_BOTON_MOTOR1) == OUT){
      digitalWrite(OUT1MOTOR1, LOW);
      digitalWrite(OUT2MOTOR1, HIGH);
  } else {
    stopMotor1();
  }
}

void stopMotor1(){
  digitalWrite(OUT1MOTOR1, LOW);
  digitalWrite(OUT2MOTOR1, LOW);
}

void upMotor2(){
  if (digitalRead(SENSOR_TOP_MOTOR2) == OUT){
      digitalWrite(OUT1MOTOR2, HIGH);
      digitalWrite(OUT2MOTOR2, LOW);
  } else {
    stopMotor2();
  }
}

void downMotor2(){
  if (digitalRead(SENSOR_BOTON_MOTOR2) == OUT){
      digitalWrite(OUT1MOTOR2, LOW);
      digitalWrite(OUT2MOTOR2, HIGH);
  } else {
    stopMotor2();
    downMotor1();
  }
}

void stopMotor2(){
  digitalWrite(OUT1MOTOR2, LOW);
  digitalWrite(OUT2MOTOR2, LOW);
}

void showMotorData(){

    if (digitalRead(OUT1MOTOR1) == 0 and digitalRead(OUT2MOTOR1) == 0){
      lcd.setCursor(12, 0);  
      lcd.print("STOP ");
    }
    if (digitalRead(OUT1MOTOR1) == 1 and digitalRead(OUT2MOTOR1) == 0){
      lcd.setCursor(12, 0);  
      lcd.print("UP   ");
    }
    if (digitalRead(OUT1MOTOR1) == 0 and digitalRead(OUT2MOTOR1) == 1){
      lcd.setCursor(12, 0);  
      lcd.print("DOWN ");
    }

    if (digitalRead(OUT1MOTOR2) == 0 and digitalRead(OUT2MOTOR2) == 0){
      lcd.setCursor(12, 1);  
      lcd.print("STOP ");
    }
    if (digitalRead(OUT1MOTOR2) == 1 and digitalRead(OUT2MOTOR2) == 0){
      lcd.setCursor(12, 1);  
      lcd.print("UP   ");
    }
    if (digitalRead(OUT1MOTOR2) == 0 and digitalRead(OUT2MOTOR2) == 1){
      lcd.setCursor(12, 1);  
      lcd.print("DOWN ");
    }

}

void showSensorData(){
    if (digitalRead(SENSOR_BOTON_MOTOR1) == PRESENT){ lcd.setCursor(0, 1);  lcd.print("X");  } else {lcd.setCursor(0, 1);  lcd.print("-");  }
    if (digitalRead(SENSOR_TOP_MOTOR1)   == PRESENT){ lcd.setCursor(1, 1);  lcd.print("X");  } else {lcd.setCursor(1, 1);  lcd.print("-");  }
    if (digitalRead(SENSOR_BOTON_MOTOR2) == PRESENT){ lcd.setCursor(2, 1);  lcd.print("X");  } else {lcd.setCursor(2, 1);  lcd.print("-");  }
    if (digitalRead(SENSOR_TOP_MOTOR2)   == PRESENT){ lcd.setCursor(3, 1);  lcd.print("X");  } else {lcd.setCursor(3, 1);  lcd.print("-");  }

  
}
