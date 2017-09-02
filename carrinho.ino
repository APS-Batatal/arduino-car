#include "classes/motors.h";
#include "classes/infrared.h";

//VARIABLES
Infrared irL, irC, irR; //Sensores infravermelhos
Motors motors; //Controlador do motor
int ratio = 650; //Valor padrão do "preto"
String last;//Variavel para saber qual foi o último sensor que "viu" preto

// SETUP
void setup() {
  //Configurar os sensores
  irL.setup(A0);//Esquerdo
  irC.setup(A1);//Central
  irR.setup(A2);//Direito

  //Configurar o motor
  motors.setup();

  //pegar o valor atual do sensor central e atribuir um valor um pouco menor como o preto
  ratio = irC.get() - 100;
  last = "irC";//Definir o last padrão como o central
}

// SETUP
void loop() {
  //  Checar qual sensor está vendo a linha preta
  if(irC.get(ratio)) {
    //Se o central, para frente, etc...
    motors.go();
    last = "irC";
  } else if(irL.get(ratio)) {
    motors.left();
    last = "irL";
  } else if(irR.get(ratio)) {
    motors.right();
    last = "irR";
  } else {
    //Se ninguém esiver vendo o preto
    //Verificar quem foi o último a ver preto
    if (last == "irC") {
      motors.go(); 
    } else if(last == "irR"){
      motors.right();  
    } else if(last == "irL"){
      motors.left();
    }
  }
}
