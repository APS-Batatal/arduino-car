#include "classes/motors.h";
#include "classes/infrared.h";

// CONSTANTS
const int ratio = 600; // Valor padrão do "preto"
const int lost = 500; // tempo para considerar a linha como perdida

//VARIABLES
Infrared irL, irC, irR; //Sensores infravermelhos
Motors motors; //Controlador do motor
String actual = "none"; //Controlar qual o comando atual
String last = "none"; //Controlar qual o último comando
int lostTimer = lost; //"timer" de linha linha perdida

// SETUP
void setup() {
  //Configurar os sensores
  irL.setup(A0); // Esquerdo
  irC.setup(A1); // Central
  irR.setup(A2); // Direito

  //Configurar o motor
  motors.setup();

  Serial.begin(9600);
}

// SETUP
void loop() {
  // Checar sensores
  checkSensors();
  if(actual != "none") {
    // Se algum sensor está vendo a linha
    motors.command(actual);
  } else {
    // Se nenhum sensor está vendo a linha
    if(lostTimer > 0){
      Serial.println(lostTimer);
      // iniciar o lostTimer
      lostTimer--;
        // Se houver um último comando
      if(last != "none") {
           motors.command(last);
      } else {
        motors.go();
      }
    } else {
      if(last == "go") {
        motors.left(true);
      }
    }
  }
  delay(1);
}

void checkSensors() {
  if(irC.is(ratio)) { 
    actual = "go";
    last = "go";
    lostTimer = lost;
  } else if(irL.is(ratio)) {
    actual = "left";
    last = "left";
    lostTimer = lost;
  } else if(irR.is(ratio)) {
    actual = "right";
    last = "right";
    lostTimer = lost;
  } else {
    actual = "none";
  }
}


