//v0.1 Este programa esta pensado para controlar los ventiladores del ordenador por el momento

// PINS
	const int PIN_FAN_PWM = 5 ;
	const int PIN_FANSPEED_UP = 2;
	const int PIN_FANSPEED_DOWN = 3;
// SETUP
	void setup (){
		Serial.begin(9600);
		PinSetup();
		setup_interrupts();
		}

// LOOP
	void loop (){
		fanspeed_inputs();
		fanSpeed_outputs();
		fanSpeed_PWM();
		check_fanspeed_change();
		set_last_fanspeed();
		}

// FUNCTIONS
	// PinSetup
		void PinSetup (){
			pinMode(PIN_FAN_PWM, OUTPUT);
			}

	// Fan
		int fanspeed = 50 ;     // Set the fanspeed 0-100
		int last_fanspeed = 0;  // Saves the last fanspeed value
		bool fanSpeedChange;    // true if fanspeed changed, false if not 

		void setup_interrupts (){
  		pinMode(PIN_FANSPEED_UP  , INPUT_PULLUP);
  		attachInterrupt(digitalPinToInterrupt(PIN_FANSPEED_UP), interrupt_fanspeed_up, CHANGE);
			
  		pinMode(PIN_FANSPEED_DOWN, INPUT_PULLUP);
  		attachInterrupt(digitalPinToInterrupt(PIN_FANSPEED_DOWN), interrupt_fanspeed_down, CHANGE);
			}

		void interrupt_fanspeed_up (){
			fanspeed = fanspeed + 5 ;
			}

		void interrupt_fanspeed_down (){
			fanspeed = fanspeed - 5 ;
			}

		void fanspeed_inputs (){
			//fanspeed = Serial.read();
			}

		void check_fanspeed_change(){
			if (last_fanspeed != fanspeed){fanSpeedChange = true ;}
			else {fanSpeedChange = false ;}
			}

		void fanSpeed_outputs (){
			if (fanSpeedChange == true){						// Para que solo muestre en caso de cambio
				Serial.print("fan speed is set to: ");
				Serial.print(fanspeed);
				Serial.print("%");
				Serial.println();
				}
			}

		void fanSpeed_PWM (){
			if (fanspeed < 0  ){fanspeed = 0  ;}
			if (fanspeed > 255){fanspeed = 255;}
			analogWrite(PIN_FAN_PWM, fanspeed);
			}

		void set_last_fanspeed (){
			if (last_fanspeed != fanspeed){
				last_fanspeed = fanspeed;
				}
			}