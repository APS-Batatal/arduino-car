#include <ControleDC.h>//Inclui a biblioteca da shield
class Motors {
  // VARIABLES
  //definine os pins do motor (são fixos, já que se trada de uma shield)
  #define M1A 2
  #define M1B 3
  #define M2A 4
  #define M2B 5

  // SETUP
  public: setup(){
    //chama a função que inicia os motores
    inicializaDriveMotor(M1A,M1B,M2A,M2B);
  }

  // METHODS

  // move o carrinho para a direita
  public: right(bool inAxis = false){
    horarioM1();

    // confere se ele deve girar no próprio eixo
    if(inAxis) {
      anti_horarioM2();
    } else {
      pararM2();
    }
  }
  
  // move o carrinho para a esquerda
  public: left(bool inAxis = false) {
    horarioM2();
    // confere se ele deve girar no próprio eixo
    if(inAxis) {
      anti_horarioM1();
    } else {
      pararM1();
    }
  }

  // move o carrinho para frente
  public: go() {
    horarioM1();
    horarioM2();
  }

  // move o carrinho para trás
  public:back() {
    anti_horarioM1();
    anti_horarioM2();
  }

  // para o carrinho
  public: stop() {
    pararM1();
    pararM2();
  }

  // Define o comando dos motores por uma string
  public: command(String _command) {
    if(_command == "go"){
      this->go(); 
    } else if(_command == "left") {
      this->left();
    } else if(_command == "right") {
      this->right();
    } else if(_command == "back") {
      this->back();
    } else if(_command == "stop") {
      this->stop();
    }
  }
};