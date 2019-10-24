//Juan Carlos Catú Similox

//Descargar las librerias para que el proyecto pueda cargarse a la placa
#include <Key.h>
#include <LiquidCrystal.h>
#include <Keypad.h>
#include <Servo.h> 
#include <Wire.h>

LiquidCrystal lcd (7,8,9,10,11,12);
 


const byte filas = 4;
const byte columnas = 4;
byte pinsFilas[filas] =  {21,20, 19,18};
byte pinsColumnas[columnas] = {17,16,15,14}; 

char teclas [filas][columnas] = {
  
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'},
  };
  
 Keypad teclado = Keypad(makeKeymap(teclas), pinsFilas, pinsColumnas, filas, columnas);


char tecla;
char char1;
char char2;
char char3;
char char4;
int c = 0; 
int angulo = 90; 
Servo myservo; 

void setup() {

 Serial.begin(9600);
 
 lcd.begin(16,2);

 myservo.attach(13); 
 myservo.write(angulo);
 
	lcd.setCursor(0, 0);
        lcd.print("EXPO CUAUHTE");
       
        lcd.setCursor(0, 1);
        lcd.print("BIENVENIDOS...");
 delay(1000);
 Serial.println("PUERTA ABIERTA");
 LimpiaFila1();
 PuertaAbierta();
 delay(1000);
 Serial.println("Espere por favor....");
 LimpiaFila1();
 Espere();
delay(1000);
Serial.println("INGRESE LA CLAVE");
 LimpiaFila1();
 IntroPassword(); 
}

void loop() {

  tecla = teclado.getKey();
  
  if(tecla != NO_KEY && c<4){
  
   switch (c){
     case 0:
    c++;
    char1 = tecla;
    Serial.print("*");
    PrintChar1();
    delay (50);
    break;
     case 1:
     char2 = tecla;
     c++;
    Serial.print("*");
    PrintChar2();
    delay (50);
    break;
    case 2:    
    char3 = tecla;
    c++;
    Serial.print("*");
    PrintChar3();
    delay (50);
    break;
    case 3:    
    char4 = tecla;
    c++;     
    Serial.println("*");
    PrintChar4();
    delay (50);
    break;
  }
  }
  if(char1 == '1' && char2 == '1' && char3 == '1' && char4 == '1'){
  switch (angulo){
     case 90:
     angulo = 179;
     myservo.write(angulo);
  delay(15);                 
 Serial.println("PUERTA CERRADA");
 LimpiaFila1();
 PuertaCerrada();
 delay(3000);
LimpiaPassword();
    break;
     case 179:
      angulo = 90;
      myservo.write(angulo);
  delay(15);                
 Serial.println("PUERTA ABIERTA");
 LimpiaFila1();
 PuertaAbierta();
 delay(3000);
 LimpiaPassword();
    break;
   
  
  }
 
}
else if(c >= 4 && (char1 != '1' ||  char2 != '1' ||  char3 != '1' || char4 != '1')){
  Serial.println("CORRECTA");
  LimpiaDisplay();
  PassIncorrecta();
  delay(3000);
  Serial.println("Espere por favor....");
  LimpiaDisplay();
  lcd.setCursor(0, 0);
  lcd.print("EXPO CUAUH");
  Espere();
  delay(3000);
  Serial.println("INGRESE LA CLAVE:");
  LimpiaFila1();
  IntroPassword();
  c = 0;
  }

if (c >= 4){

Serial.println("Espere por favor....");
LimpiaFila1();
Espere();
delay(3000);
c = 0;
Serial.println("INGRESE LA CLAVE:");
LimpiaFila1();
IntroPassword();
}
  }
  
void LimpiaFila0()
{
 for(int i = 0; i < 16; i++){
	lcd.setCursor(i, 0);
	lcd.print(" ");
	}
}

void LimpiaFila1()
{
 for(int i = 0; i < 16; i++){
	lcd.setCursor(i, 1);
	lcd.print(" ");
	}
}

void LimpiaDisplay()
{
 for(int i = 0; i < 16; i++){
	lcd.setCursor(i, 0);
	lcd.print(" ");
        lcd.setCursor(i, 1);
	lcd.print(" ");
	}
}

void PuertaAbierta()
{
  lcd.setCursor(0, 1);
  lcd.print("PUERTA ABIERTA");
}

void PuertaCerrada()
{
  lcd.setCursor(0, 1);
  lcd.print("PUERTA CERRADA");
}

void Espere()
{
  lcd.setCursor(0, 1);
  lcd.print("ESPERE POR FAVOR");
}

void IntroPassword()
{
  lcd.setCursor(0, 1);
  lcd.print("CLAVE:");
}

void PrintChar1()
{
  lcd.setCursor(11, 1);
  lcd.print("*");
}

void PrintChar2()
{
  lcd.setCursor(12, 1);
  lcd.print("*");
}

void PrintChar3()
{
  lcd.setCursor(13, 1);
  lcd.print("*");
}

void PrintChar4()
{
  lcd.setCursor(14, 1);
  lcd.print("*");
}

void PassIncorrecta()
{
  lcd.setCursor(0, 0);
  lcd.print("CLAVE");
  lcd.setCursor(0, 1);
  lcd.print("INCORRECTA!!!!!");
}

void LimpiaPassword()
{
 char1 = '*'; 
 char2 = '*';
 char3 = '*';
 char4 = '*';
 }
