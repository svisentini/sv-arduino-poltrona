/*
     Versao 1.2 
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

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int PRESENTE = 1;
const int AUSENTE = 0;

int tecla = A0;

int sensorCimaMotor1 = AUSENTE;
int sensorBaixoMotor1 = AUSENTE;
int sensorCimaMotor2 = AUSENTE;
int sensorBaixoMotor2 = AUSENTE;

int estadoUp = AUSENTE;
int estadoDown = AUSENTE;

int SAIDA1MOTOR1 = 30;
int SAIDA2MOTOR1 = 32;
int SAIDA1MOTOR2 = 34;
int SAIDA2MOTOR2 = 36;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("----    M1: 0 0 ");   // 12,0  14,0 
  lcd.setCursor(0, 1);
  lcd.print("----    M2: 0 0 ");   // 12,1  14,1

  // Define pinos de saída dos motores
  pinMode(SAIDA1MOTOR1, OUTPUT);
  pinMode(SAIDA2MOTOR1, OUTPUT);
  pinMode(SAIDA1MOTOR2, OUTPUT);
  pinMode(SAIDA2MOTOR2, OUTPUT);
}

void loop() {
  int valor = analogRead(tecla);


  // SENSOR CIMA MOTOR 1
  if (valor > 600 and valor < 800) {
     lcd.setCursor(0, 1);
     if (sensorCimaMotor1 == AUSENTE){
        sensorCimaMotor1 = PRESENTE;
        lcd.print("X");
     } else {
        sensorCimaMotor1 = AUSENTE;
        lcd.print("-");
     }
  }

  // SENSOR BAIXO MOTOR 1
  if (valor > 400 and valor < 500) {
     lcd.setCursor(1, 1);
     if (sensorBaixoMotor1 == AUSENTE){
        sensorBaixoMotor1 = PRESENTE;
        lcd.print("X");
     } else {
        sensorBaixoMotor1 = AUSENTE;
        lcd.print("-");
     }
  }

/*
  // SENSOR CIMA MOTOR 2
  if (valor > 0 and valor < 100) {
     lcd.setCursor(2, 1);
     if (sensorCimaMotor2 == AUSENTE){
        sensorCimaMotor2 = PRESENTE;
        lcd.print("X");
     } else {
        sensorCimaMotor2 = AUSENTE;
        lcd.print("-");
     }
  }
*/
  // SENSOR BAIXO MOTOR 2
  if (valor > 0 and valor < 100) {
     lcd.setCursor(3, 1);
     if (sensorBaixoMotor2 == AUSENTE){
        sensorBaixoMotor2 = PRESENTE;
        lcd.print("X");
     } else {
        sensorBaixoMotor2 = AUSENTE;
        lcd.print("-");
     }
  }

 // UP
  if (valor > 100 and valor < 200) {
     lcd.setCursor(0, 0);
     if (estadoUp == 0){
        estadoUp = 1;
        estadoDown = 0;
        lcd.print("<<<<");
     } else {
        estadoUp = 0;
        lcd.print("----");
     }
  }

  // DOWN
  if (valor > 300 and valor < 400) {
     lcd.setCursor(0, 0);
     if (estadoDown == 0){
        estadoDown = 1;
        estadoUp = 0;
        lcd.print(">>>>");
     } else {
        estadoDown = 0;
        lcd.print("----");
     }
  }

  // ===========================================================

  if (estadoUp == PRESENTE){
      movimentoSobe();  
  }  
  else{
      if (estadoDown == PRESENTE){
          movimentoDesce();
      }
      else {
          para();
      }
  }
  

  // ===========================================================
  
  exibeInfoMotores();

  delay(150);

}

void movimentoSobe(){
  if (sensorCimaMotor1 == AUSENTE){
      paraMotor2();
      sobeMotor1();
  }
  else{
      paraMotor1();
      sobeMotor2();  
  }
}

void movimentoDesce(){
  if (sensorBaixoMotor2 == AUSENTE){
      paraMotor1();
      desceMotor2();
  }
  else{
      paraMotor2();
      desceMotor1(); 
  } 
}

void para(){
  paraMotor1();
  paraMotor2();
}

void sobeMotor1(){
  if (sensorCimaMotor1 == AUSENTE){
      digitalWrite(SAIDA1MOTOR1, HIGH);
      digitalWrite(SAIDA2MOTOR1, LOW);
  } else {
    paraMotor1();
    sobeMotor2();
  }
}

void desceMotor1(){
  if (sensorBaixoMotor1 == AUSENTE){
      digitalWrite(SAIDA1MOTOR1, LOW);
      digitalWrite(SAIDA2MOTOR1, HIGH);
  } else {
    paraMotor1();
  }
}

void paraMotor1(){
  digitalWrite(SAIDA1MOTOR1, LOW);
  digitalWrite(SAIDA2MOTOR1, LOW);
}

void sobeMotor2(){
  if (sensorCimaMotor2 == AUSENTE){
      digitalWrite(SAIDA1MOTOR2, HIGH);
      digitalWrite(SAIDA2MOTOR2, LOW);
  } else {
    paraMotor2();
  }
}

void desceMotor2(){
  if (sensorBaixoMotor2 == AUSENTE){
      digitalWrite(SAIDA1MOTOR2, LOW);
      digitalWrite(SAIDA2MOTOR2, HIGH);
  } else {
    paraMotor2();
    desceMotor1();
  }
}

void paraMotor2(){
  digitalWrite(SAIDA1MOTOR2, LOW);
  digitalWrite(SAIDA2MOTOR2, LOW);
}

void exibeInfoMotores(){

    if (digitalRead(SAIDA1MOTOR1) == 0 and digitalRead(SAIDA2MOTOR1) == 0){
      lcd.setCursor(12, 0);  
      lcd.print("STOP ");
    }
    if (digitalRead(SAIDA1MOTOR1) == 1 and digitalRead(SAIDA2MOTOR1) == 0){
      lcd.setCursor(12, 0);  
      lcd.print("UP   ");
    }
    if (digitalRead(SAIDA1MOTOR1) == 0 and digitalRead(SAIDA2MOTOR1) == 1){
      lcd.setCursor(12, 0);  
      lcd.print("DOWN ");
    }

    if (digitalRead(SAIDA1MOTOR2) == 0 and digitalRead(SAIDA2MOTOR2) == 0){
      lcd.setCursor(12, 1);  
      lcd.print("STOP ");
    }
    if (digitalRead(SAIDA1MOTOR2) == 1 and digitalRead(SAIDA2MOTOR2) == 0){
      lcd.setCursor(12, 1);  
      lcd.print("UP   ");
    }
    if (digitalRead(SAIDA1MOTOR2) == 0 and digitalRead(SAIDA2MOTOR2) == 1){
      lcd.setCursor(12, 1);  
      lcd.print("DOWN ");
    }

    

  
  // Define pinos de saída dos motores
  //lcd.setCursor(12, 0);  lcd.print(digitalRead(SAIDA1MOTOR1));
  //lcd.setCursor(14, 0);  lcd.print(digitalRead(SAIDA2MOTOR1));
  //lcd.setCursor(12, 1);  lcd.print(digitalRead(SAIDA1MOTOR2));
  //lcd.setCursor(14, 1);  lcd.print(digitalRead(SAIDA2MOTOR2));
}
