class Infrared {
	// VARIABLES
	int analogPin;//pin (analógico) do sensor

	// SETUP
	public: setup(int _analogPin) {
		// Define qual o pin do sensor
		analogPin = _analogPin;
	}
	// confere se o sensor esá captando acima de um determinado valor
	public: get(int value){
		return (analogRead(analogPin) > value)? true : false;
	}
	// retorna o valor que o sensor está captando
	public: get(){
		return analogRead(analogPin);
	}
};