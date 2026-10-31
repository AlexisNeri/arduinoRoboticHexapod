/*
 * Autor: Alexis Romo
 * Fecha: 12/12/16
 * Lugar: Tlaquepaque, Jalisco, México
 */

#include <Servo.h>

//Pata1
Servo servo1;
Servo servo2;
//Pata2
Servo servo3;
Servo servo4;
//Pata3
Servo servo5;
Servo servo6;
//Pata4
Servo servo7;
Servo servo8;
//Pata5
Servo servo9;
Servo servo10;
//Pata6
Servo servo11;
Servo servo12;
//Estado de control por bluetooth
int estado = 'c';
//Pines para control de sensor ultrasonico
int trig = 48;
int echo = 49;
//Variables para almacenar lecturas de ultrasonico
long distancia;
long tiempo;

void setup() {
  //Pata1
  servo1.attach(2);
  servo2.attach(3);
  //Pata2
  servo3.attach(4);
  servo4.attach(5);
  //Pata3
  servo5.attach(6);
  servo6.attach(7);
  //Pata4
  servo7.attach(8);
  servo8.attach(9);
  //Pata5
  servo9.attach(10);
  servo10.attach(11);
  //Pata6
  servo11.attach(12);
  servo12.attach(13);
  //Inicia el puerto serial para comunicacion con el modulo Bluetooth
  Serial.begin(9600);
  pinMode(trig, OUTPUT); /*activación del pin 48 como salida: para el pulso ultrasónico*/
  pinMode(echo, INPUT); /*activación del pin 49 como entrada: tiempo del rebote del ultrasonido*/
}

void loop() {
  if(Serial.available() > 0){ // lee el bluetooth y almacena en estado
  estado = Serial.read();
  }
  switch(estado){
    //Boton Adelante
    case 'a':
      recorrido();
      if(distancia <=30){
        alto();
        delay(750);
      }
      else{
        adelante();
      }
      break;
    //Boton Izquierda
    case 'b':
      izquierda();
      break;
    //Boton Central
    case 'c':
      alto();
      break;
    //Boton Derecha
    case 'd':
      derecha();
      break;
    //Boton Atras
    case 'e':
      atras();
      break;
  }
}

void adelante(){
  int d_vertical_1 = 90;
  int d_vertical_2 = 90;
  int d_l_izquierda_1 = 115;
  int d_l_izquierda_2 = 65;
  int d_l_derecha_1 = 65;
  int d_l_derecha_2 = 115;
  
  //Subir grupo 2
  for(int i=1 ; i<=8 ; i++){
    d_vertical_1 += 5;
    d_vertical_2 -= 5;
    
    servo1.write(d_l_izquierda_2);
    servo2.write(d_vertical_2);
  
    servo3.write(d_l_derecha_1);
    servo4.write(d_vertical_1);
  
    servo5.write(d_l_izquierda_1);
    servo6.write(d_vertical_1);
  
    servo7.write(d_l_derecha_2);
    servo8.write(d_vertical_2);
  
    servo9.write(d_l_izquierda_2);
    servo10.write(d_vertical_2);
  
    servo11.write(d_l_derecha_1);
    servo12.write(d_vertical_1);
    
    delay(75);
  }

  //Centrar grupo 2
  for(int i=1 ; i<=5 ; i++){
    d_l_izquierda_1 -= 5;
    d_l_izquierda_2 += 5;
    d_l_derecha_1 += 5;
    d_l_derecha_2 -= 5;
    
    servo1.write(d_l_izquierda_2);
    servo2.write(d_vertical_2);
  
    servo3.write(d_l_derecha_1);
    servo4.write(d_vertical_1);
  
    servo5.write(d_l_izquierda_1);
    servo6.write(d_vertical_1);
  
    servo7.write(d_l_derecha_2);
    servo8.write(d_vertical_2);
  
    servo9.write(d_l_izquierda_2);
    servo10.write(d_vertical_2);
  
    servo11.write(d_l_derecha_1);
    servo12.write(d_vertical_1);
    
    delay(75);
  }

  //Paso atras grupo 2
  for(int i=1 ; i<=5 ; i++){
    d_l_izquierda_1 -= 5;
    d_l_izquierda_2 += 5;
    d_l_derecha_1 += 5;
    d_l_derecha_2 -= 5;
    
    servo1.write(d_l_izquierda_2);
    servo2.write(d_vertical_2);
  
    servo3.write(d_l_derecha_1);
    servo4.write(d_vertical_1);
  
    servo5.write(d_l_izquierda_1);
    servo6.write(d_vertical_1);
  
    servo7.write(d_l_derecha_2);
    servo8.write(d_vertical_2);
  
    servo9.write(d_l_izquierda_2);
    servo10.write(d_vertical_2);
  
    servo11.write(d_l_derecha_1);
    servo12.write(d_vertical_1);
    
    delay(75);
  }

   //Bajar grupo 2
   for(int i=1 ; i<=8 ; i++){
    d_vertical_1 -= 5;
    d_vertical_2 += 5;
    
    servo1.write(d_l_izquierda_2);
    servo2.write(d_vertical_2);
  
    servo3.write(d_l_derecha_1);
    servo4.write(d_vertical_1);
  
    servo5.write(d_l_izquierda_1);
    servo6.write(d_vertical_1);
  
    servo7.write(d_l_derecha_2);
    servo8.write(d_vertical_2);
  
    servo9.write(d_l_izquierda_2);
    servo10.write(d_vertical_2);
  
    servo11.write(d_l_derecha_1);
    servo12.write(d_vertical_1);
    
    delay(75);
  }

  //Subir grupo 1
  for(int i=1 ; i<=8 ; i++){
    d_vertical_1 -= 5;
    d_vertical_2 += 5;
    
    servo1.write(d_l_izquierda_2);
    servo2.write(d_vertical_2);
  
    servo3.write(d_l_derecha_1);
    servo4.write(d_vertical_1);
  
    servo5.write(d_l_izquierda_1);
    servo6.write(d_vertical_1);
  
    servo7.write(d_l_derecha_2);
    servo8.write(d_vertical_2);
  
    servo9.write(d_l_izquierda_2);
    servo10.write(d_vertical_2);
  
    servo11.write(d_l_derecha_1);
    servo12.write(d_vertical_1);
    
    delay(75);
  }

  //Centrar grupo 1
  for(int i=1 ; i<=5 ; i++){
    d_l_izquierda_1 += 5;
    d_l_izquierda_2 -= 5;
    d_l_derecha_1 -= 5;
    d_l_derecha_2 += 5;
    
    servo1.write(d_l_izquierda_2);
    servo2.write(d_vertical_2);
  
    servo3.write(d_l_derecha_1);
    servo4.write(d_vertical_1);
  
    servo5.write(d_l_izquierda_1);
    servo6.write(d_vertical_1);
  
    servo7.write(d_l_derecha_2);
    servo8.write(d_vertical_2);
  
    servo9.write(d_l_izquierda_2);
    servo10.write(d_vertical_2);
  
    servo11.write(d_l_derecha_1);
    servo12.write(d_vertical_1);
    
    delay(75);
  }

  //Paso atras grupo 1
  for(int i=1 ; i<=5 ; i++){
    d_l_izquierda_1 += 5;
    d_l_izquierda_2 -= 5;
    d_l_derecha_1 -= 5;
    d_l_derecha_2 += 5;
    
    servo1.write(d_l_izquierda_2);
    servo2.write(d_vertical_2);
  
    servo3.write(d_l_derecha_1);
    servo4.write(d_vertical_1);
  
    servo5.write(d_l_izquierda_1);
    servo6.write(d_vertical_1);
  
    servo7.write(d_l_derecha_2);
    servo8.write(d_vertical_2);
  
    servo9.write(d_l_izquierda_2);
    servo10.write(d_vertical_2);
  
    servo11.write(d_l_derecha_1);
    servo12.write(d_vertical_1);
    
    delay(75);
  }

  //Bajar grupo 1
   for(int i=1 ; i<=8 ; i++){
    d_vertical_1 += 5;
    d_vertical_2 -= 5;
    
    servo1.write(d_l_izquierda_2);
    servo2.write(d_vertical_2);
  
    servo3.write(d_l_derecha_1);
    servo4.write(d_vertical_1);
  
    servo5.write(d_l_izquierda_1);
    servo6.write(d_vertical_1);
  
    servo7.write(d_l_derecha_2);
    servo8.write(d_vertical_2);
  
    servo9.write(d_l_izquierda_2);
    servo10.write(d_vertical_2);
  
    servo11.write(d_l_derecha_1);
    servo12.write(d_vertical_1);
    
    delay(75);
  }
}

void atras(){
  int d_vertical_1 = 90;
  int d_vertical_2 = 90;
  int d_l_izquierda_1 = 115;
  int d_l_izquierda_2 = 65;
  int d_l_derecha_1 = 65;
  int d_l_derecha_2 = 115;
  
  //Subir grupo 1
  for(int i=1 ; i<=8 ; i++){
    d_vertical_1 -= 5;
    d_vertical_2 += 5;
    
    servo1.write(d_l_izquierda_2);
    servo2.write(d_vertical_2);
  
    servo3.write(d_l_derecha_1);
    servo4.write(d_vertical_1);
  
    servo5.write(d_l_izquierda_1);
    servo6.write(d_vertical_1);
  
    servo7.write(d_l_derecha_2);
    servo8.write(d_vertical_2);
  
    servo9.write(d_l_izquierda_2);
    servo10.write(d_vertical_2);
  
    servo11.write(d_l_derecha_1);
    servo12.write(d_vertical_1);
    
    delay(75);
  }

  //Centrar grupo 1
  for(int i=1 ; i<=5 ; i++){
    d_l_izquierda_1 -= 5;
    d_l_izquierda_2 += 5;
    d_l_derecha_1 += 5;
    d_l_derecha_2 -= 5;
    
    servo1.write(d_l_izquierda_2);
    servo2.write(d_vertical_2);
  
    servo3.write(d_l_derecha_1);
    servo4.write(d_vertical_1);
  
    servo5.write(d_l_izquierda_1);
    servo6.write(d_vertical_1);
  
    servo7.write(d_l_derecha_2);
    servo8.write(d_vertical_2);
  
    servo9.write(d_l_izquierda_2);
    servo10.write(d_vertical_2);
  
    servo11.write(d_l_derecha_1);
    servo12.write(d_vertical_1);
    
    delay(75);
  }

  //Paso adelante grupo 1
  for(int i=1 ; i<=5 ; i++){
    d_l_izquierda_1 -= 5;
    d_l_izquierda_2 += 5;
    d_l_derecha_1 += 5;
    d_l_derecha_2 -= 5;
    
    servo1.write(d_l_izquierda_2);
    servo2.write(d_vertical_2);
  
    servo3.write(d_l_derecha_1);
    servo4.write(d_vertical_1);
  
    servo5.write(d_l_izquierda_1);
    servo6.write(d_vertical_1);
  
    servo7.write(d_l_derecha_2);
    servo8.write(d_vertical_2);
  
    servo9.write(d_l_izquierda_2);
    servo10.write(d_vertical_2);
  
    servo11.write(d_l_derecha_1);
    servo12.write(d_vertical_1);
    
    delay(75);
  }

   //Bajar grupo 1
   for(int i=1 ; i<=8 ; i++){
    d_vertical_1 += 5;
    d_vertical_2 -= 5;
    
    servo1.write(d_l_izquierda_2);
    servo2.write(d_vertical_2);
  
    servo3.write(d_l_derecha_1);
    servo4.write(d_vertical_1);
  
    servo5.write(d_l_izquierda_1);
    servo6.write(d_vertical_1);
  
    servo7.write(d_l_derecha_2);
    servo8.write(d_vertical_2);
  
    servo9.write(d_l_izquierda_2);
    servo10.write(d_vertical_2);
  
    servo11.write(d_l_derecha_1);
    servo12.write(d_vertical_1);
    
    delay(75);
  }

  //Subir grupo 2
  for(int i=1 ; i<=8 ; i++){
    d_vertical_1 += 5;
    d_vertical_2 -= 5;
    
    servo1.write(d_l_izquierda_2);
    servo2.write(d_vertical_2);
  
    servo3.write(d_l_derecha_1);
    servo4.write(d_vertical_1);
  
    servo5.write(d_l_izquierda_1);
    servo6.write(d_vertical_1);
  
    servo7.write(d_l_derecha_2);
    servo8.write(d_vertical_2);
  
    servo9.write(d_l_izquierda_2);
    servo10.write(d_vertical_2);
  
    servo11.write(d_l_derecha_1);
    servo12.write(d_vertical_1);
    
    delay(75);
  }

  //Centrar grupo 2
  for(int i=1 ; i<=5 ; i++){
    d_l_izquierda_1 += 5;
    d_l_izquierda_2 -= 5;
    d_l_derecha_1 -= 5;
    d_l_derecha_2 += 5;
    
    servo1.write(d_l_izquierda_2);
    servo2.write(d_vertical_2);
  
    servo3.write(d_l_derecha_1);
    servo4.write(d_vertical_1);
  
    servo5.write(d_l_izquierda_1);
    servo6.write(d_vertical_1);
  
    servo7.write(d_l_derecha_2);
    servo8.write(d_vertical_2);
  
    servo9.write(d_l_izquierda_2);
    servo10.write(d_vertical_2);
  
    servo11.write(d_l_derecha_1);
    servo12.write(d_vertical_1);
    
    delay(75);
  }

  //Paso adelante grupo 2
  for(int i=1 ; i<=5 ; i++){
    d_l_izquierda_1 += 5;
    d_l_izquierda_2 -= 5;
    d_l_derecha_1 -= 5;
    d_l_derecha_2 += 5;
    
    servo1.write(d_l_izquierda_2);
    servo2.write(d_vertical_2);
  
    servo3.write(d_l_derecha_1);
    servo4.write(d_vertical_1);
  
    servo5.write(d_l_izquierda_1);
    servo6.write(d_vertical_1);
  
    servo7.write(d_l_derecha_2);
    servo8.write(d_vertical_2);
  
    servo9.write(d_l_izquierda_2);
    servo10.write(d_vertical_2);
  
    servo11.write(d_l_derecha_1);
    servo12.write(d_vertical_1);
    
    delay(75);
  }

  //Bajar grupo 2
   for(int i=1 ; i<=8 ; i++){
    d_vertical_1 -= 5;
    d_vertical_2 += 5;
    
    servo1.write(d_l_izquierda_2);
    servo2.write(d_vertical_2);
  
    servo3.write(d_l_derecha_1);
    servo4.write(d_vertical_1);
  
    servo5.write(d_l_izquierda_1);
    servo6.write(d_vertical_1);
  
    servo7.write(d_l_derecha_2);
    servo8.write(d_vertical_2);
  
    servo9.write(d_l_izquierda_2);
    servo10.write(d_vertical_2);
  
    servo11.write(d_l_derecha_1);
    servo12.write(d_vertical_1);
    
    delay(75);
  }
}

void derecha(){
  int d_vertical_1 = 90;
  int d_vertical_2 = 90;
  int d_l_izquierda_1 = 65;
  int d_l_izquierda_2 = 115;
  int d_l_derecha_1 = 65;
  int d_l_derecha_2 = 115;
  
  //Subir grupo 1
  for(int i=1 ; i<=8 ; i++){
    d_vertical_1 -= 5;
    d_vertical_2 += 5;
    
    servo1.write(d_l_izquierda_2);
    servo2.write(d_vertical_2);
  
    servo3.write(d_l_derecha_1);
    servo4.write(d_vertical_1);
  
    servo5.write(d_l_izquierda_1);
    servo6.write(d_vertical_1);
  
    servo7.write(d_l_derecha_2);
    servo8.write(d_vertical_2);
  
    servo9.write(d_l_izquierda_2);
    servo10.write(d_vertical_2);
  
    servo11.write(d_l_derecha_1);
    servo12.write(d_vertical_1);
    
    delay(75);
  }

  //Desplazar grupo 1 en sentido antihorario
  for(int i=1 ; i<=10 ; i++){
    d_l_izquierda_1 += 5;
    d_l_izquierda_2 -= 5;
    d_l_derecha_1 += 5;
    d_l_derecha_2 -= 5;
    
    servo1.write(d_l_izquierda_2);
    servo2.write(d_vertical_2);
  
    servo3.write(d_l_derecha_1);
    servo4.write(d_vertical_1);
  
    servo5.write(d_l_izquierda_1);
    servo6.write(d_vertical_1);
  
    servo7.write(d_l_derecha_2);
    servo8.write(d_vertical_2);
  
    servo9.write(d_l_izquierda_2);
    servo10.write(d_vertical_2);
  
    servo11.write(d_l_derecha_1);
    servo12.write(d_vertical_1);
    
    delay(75);
  }

   //Bajar grupo 1 y subir grupo 2
  for(int i=1 ; i<=16 ; i++){
    d_vertical_1 += 5;
    d_vertical_2 -= 5;
    
    servo1.write(d_l_izquierda_2);
    servo2.write(d_vertical_2);
  
    servo3.write(d_l_derecha_1);
    servo4.write(d_vertical_1);
  
    servo5.write(d_l_izquierda_1);
    servo6.write(d_vertical_1);
  
    servo7.write(d_l_derecha_2);
    servo8.write(d_vertical_2);
  
    servo9.write(d_l_izquierda_2);
    servo10.write(d_vertical_2);
  
    servo11.write(d_l_derecha_1);
    servo12.write(d_vertical_1);
    
    delay(75);
  }

  //Desplazar grupo 2 en sentido antihorario
  for(int i=1 ; i<=10 ; i++){
    d_l_izquierda_1 -= 5;
    d_l_izquierda_2 += 5;
    d_l_derecha_1 -= 5;
    d_l_derecha_2 += 5;
    
    servo1.write(d_l_izquierda_2);
    servo2.write(d_vertical_2);
  
    servo3.write(d_l_derecha_1);
    servo4.write(d_vertical_1);
  
    servo5.write(d_l_izquierda_1);
    servo6.write(d_vertical_1);
  
    servo7.write(d_l_derecha_2);
    servo8.write(d_vertical_2);
  
    servo9.write(d_l_izquierda_2);
    servo10.write(d_vertical_2);
  
    servo11.write(d_l_derecha_1);
    servo12.write(d_vertical_1);
    
    delay(75);
  }

  //Bajar grupo 2
  for(int i=1 ; i<=8 ; i++){
    d_vertical_1 -= 5;
    d_vertical_2 += 5;
    
    servo1.write(d_l_izquierda_2);
    servo2.write(d_vertical_2);
  
    servo3.write(d_l_derecha_1);
    servo4.write(d_vertical_1);
  
    servo5.write(d_l_izquierda_1);
    servo6.write(d_vertical_1);
  
    servo7.write(d_l_derecha_2);
    servo8.write(d_vertical_2);
  
    servo9.write(d_l_izquierda_2);
    servo10.write(d_vertical_2);
  
    servo11.write(d_l_derecha_1);
    servo12.write(d_vertical_1);
    
    delay(75);
  }
}

void izquierda(){
  int d_vertical_1 = 90;
  int d_vertical_2 = 90;
  int d_l_izquierda_1 = 65;
  int d_l_izquierda_2 = 115;
  int d_l_derecha_1 = 65;
  int d_l_derecha_2 = 115;
  
  //Subir grupo 2
  for(int i=1 ; i<=8 ; i++){
    d_vertical_1 += 5;
    d_vertical_2 -= 5;
    
    servo1.write(d_l_izquierda_2);
    servo2.write(d_vertical_2);
  
    servo3.write(d_l_derecha_1);
    servo4.write(d_vertical_1);
  
    servo5.write(d_l_izquierda_1);
    servo6.write(d_vertical_1);
  
    servo7.write(d_l_derecha_2);
    servo8.write(d_vertical_2);
  
    servo9.write(d_l_izquierda_2);
    servo10.write(d_vertical_2);
  
    servo11.write(d_l_derecha_1);
    servo12.write(d_vertical_1);
    
    delay(75);
  }

  //Desplazar grupo 1 en sentido antihorario
  for(int i=1 ; i<=10 ; i++){
    d_l_izquierda_1 += 5;
    d_l_izquierda_2 -= 5;
    d_l_derecha_1 += 5;
    d_l_derecha_2 -= 5;
    
    servo1.write(d_l_izquierda_2);
    servo2.write(d_vertical_2);
  
    servo3.write(d_l_derecha_1);
    servo4.write(d_vertical_1);
  
    servo5.write(d_l_izquierda_1);
    servo6.write(d_vertical_1);
  
    servo7.write(d_l_derecha_2);
    servo8.write(d_vertical_2);
  
    servo9.write(d_l_izquierda_2);
    servo10.write(d_vertical_2);
  
    servo11.write(d_l_derecha_1);
    servo12.write(d_vertical_1);
    
    delay(75);
  }

   //Bajar grupo 2 y subir grupo 1
  for(int i=1 ; i<=16 ; i++){
    d_vertical_1 -= 5;
    d_vertical_2 += 5;
    
    servo1.write(d_l_izquierda_2);
    servo2.write(d_vertical_2);
  
    servo3.write(d_l_derecha_1);
    servo4.write(d_vertical_1);
  
    servo5.write(d_l_izquierda_1);
    servo6.write(d_vertical_1);
  
    servo7.write(d_l_derecha_2);
    servo8.write(d_vertical_2);
  
    servo9.write(d_l_izquierda_2);
    servo10.write(d_vertical_2);
  
    servo11.write(d_l_derecha_1);
    servo12.write(d_vertical_1);
    
    delay(75);
  }

  //Desplazar grupo 2 en sentido antihorario
  for(int i=1 ; i<=10 ; i++){
    d_l_izquierda_1 -= 5;
    d_l_izquierda_2 += 5;
    d_l_derecha_1 -= 5;
    d_l_derecha_2 += 5;
    
    servo1.write(d_l_izquierda_2);
    servo2.write(d_vertical_2);
  
    servo3.write(d_l_derecha_1);
    servo4.write(d_vertical_1);
  
    servo5.write(d_l_izquierda_1);
    servo6.write(d_vertical_1);
  
    servo7.write(d_l_derecha_2);
    servo8.write(d_vertical_2);
  
    servo9.write(d_l_izquierda_2);
    servo10.write(d_vertical_2);
  
    servo11.write(d_l_derecha_1);
    servo12.write(d_vertical_1);
    
    delay(75);
  }

  //Bajar grupo 1
  for(int i=1 ; i<=8 ; i++){
    d_vertical_1 += 5;
    d_vertical_2 -= 5;
    
    servo1.write(d_l_izquierda_2);
    servo2.write(d_vertical_2);
  
    servo3.write(d_l_derecha_1);
    servo4.write(d_vertical_1);
  
    servo5.write(d_l_izquierda_1);
    servo6.write(d_vertical_1);
  
    servo7.write(d_l_derecha_2);
    servo8.write(d_vertical_2);
  
    servo9.write(d_l_izquierda_2);
    servo10.write(d_vertical_2);
  
    servo11.write(d_l_derecha_1);
    servo12.write(d_vertical_1);
    
    delay(75);
  }
}

void alto(){
  int posicion = 90;
  servo1.write(posicion);
  servo2.write(posicion);
  servo3.write(posicion);
  servo4.write(posicion);
  servo5.write(posicion);
  servo6.write(posicion);
  servo7.write(posicion);
  servo8.write(posicion);
  servo9.write(posicion);
  servo10.write(posicion);
  servo11.write(posicion);
  servo12.write(posicion);
  delay(15);
}

void recorrido(){
  digitalWrite(trig,LOW); /* Por cuestión de estabilización del sensor*/
  delayMicroseconds(5);
  digitalWrite(trig, HIGH); /* envío del pulso ultrasónico*/
  delayMicroseconds(10);
  tiempo=pulseIn(echo, HIGH); /* Función para medir la longitud del pulso entrante. Mide el tiempo transcurrido entre el envío
  del pulso ultrasónico y cuando el sensor recibe el rebote, es decir: desde que el pin 49 empieza a recibir el rebote, HIGH, hasta que
  deja de hacerlo, LOW, la longitud del pulso entrante*/
  distancia= int(0.017*tiempo); /*fórmula para calcular la distancia obteniendo un valor entero*/
}

/*
 * Autor: Alexis Romo
 * Fecha: 12/12/16
 * Lugar: Tlaquepaque, Jalisco, México
 */
