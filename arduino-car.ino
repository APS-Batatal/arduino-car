#include "classes/motors.h";
#include "classes/infrared.h";

// CONSTANTS
const int ratio = 600; // Valor padrão do "preto"

//VARIABLES
Infrared irL, irR; //Sensores infravermelhos
Motors motors; //Controlador do motor
String last = "none";

// SETUP
void setup() {
  //Configurar os sensores
  irL.setup(A0); // Esquerdo
  irR.setup(A1); // Direito

  //Configurar o motor
  motors.setup();

  Serial.begin(9600);
}

// SETUP
void loop() {
  if(irL.is(ratio) && irR.is(ratio)) {
    motors.go();
    int rdn = (rand() % 100 + 1);
    if(rdn<=50) {
      last = "left";
    } else {
      last = "right";
    }
    
  } else if(irL.is(ratio)) {
    motors.left();
    last = "left";
  }else if(irR.is(ratio)) {
    motors.right();
    last = "right";
  } else {
    if(last == "left") {
      motors.left(true);
    } else if(last == "right") {
      motors.right(true);
    } else {
      motors.go();
    }
  }
}

