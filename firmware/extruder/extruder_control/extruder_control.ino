//used for when temperature is out of range of the temperature table
#define MAX_TEMP 230
#define MIN_TEMP 20
#define MIN_VOLTAGE 0
#define MAX_VOLTAGE 5

#define NUMTEMPS 25

float temperature_table [NUMTEMPS][2] {{0.8050847457627119, 220.0}, {0.8731019522776572, 215.0}, {0.9177215189873418, 210.0}, {0.9909456740442655, 205.0}, {1.0294117647058822, 200.0}, {1.0981308411214952, 195.0}, {1.141304347826087, 190.0}, {1.217948717948718, 185.0}, {1.2765089722675367, 180.0}, {1.3452655889145497, 170.0}, {1.4640883977900552, 160.0}, {1.6071428571428572, 150.0}, {1.7195629552549427, 140.0}, {1.8486756404689537, 130.0}, {1.9697773064687167, 120.0}, {2.0726495726495724, 110.0}, {2.163299663299663, 100.0}, {2.2504159733777036, 90.0}, {2.3076923076923084, 80.0}, {2.3474059003051884, 70.0}, {2.38905325443787, 60.0}, {2.4212598425196856, 50.0}, {2.463942307692308, 30.0}, {2.470501474926254, 25.0}, {2.4736194161097433, 22.5}};

int heaterPin = 4;
int thermistorPin = A0;
int ledPin = 13;

float voltage_to_temperature(float voltage)
{
	//do a simple liner interpolation betweem the nearest two temperature values
	float distance = 10.0;
	int nearest_index = 0;
	for (int i = 0; i < NUMTEMPS; i++) {
		float d = temperature_table[i][0] - voltage;
		if (fabs(d)<fabs(distance)){
			distance = d;
			nearest_index = i;
		}
	}
	/*Serial.print(distance);
	Serial.print(" ");*/
	
	float temperature = MAX_TEMP;
	float temperature_lower_value = 0;
	float temperature_upper_value =10;
	float voltage_lower_value = 0;
	float voltage_upper_value = 10;

	if (distance >0 ){
		//interpolate to nearest_index + 1
		temperature_lower_value = temperature_table[nearest_index][1];
		temperature_upper_value = MAX_TEMP;
		if (nearest_index > 0) temperature_upper_value = temperature_table[nearest_index-1][1];

		
		voltage_upper_value = temperature_table[nearest_index][0];
		voltage_lower_value = MIN_VOLTAGE;
		if (nearest_index > 0) voltage_lower_value = temperature_table[nearest_index-1][0];
	}else{
		//interpolate to nearest_index -1
		temperature_upper_value = temperature_table[nearest_index][1];
		temperature_lower_value = MIN_TEMP;
		if (nearest_index < NUMTEMPS-1) temperature_lower_value = temperature_table[nearest_index+1][1];

		voltage_lower_value = temperature_table[nearest_index][0];
		voltage_upper_value = MAX_VOLTAGE;
		if (nearest_index < NUMTEMPS-1) voltage_upper_value = temperature_table[nearest_index+1][0];


	};

	float temperature_diff = temperature_upper_value - temperature_lower_value;
	/*Serial.print("t ");
	Serial.print(temperature_upper_value);
	Serial.print(" ");
	Serial.print(temperature_lower_value);
	Serial.print(" ");*/
	Serial.print("v ");
	Serial.print(voltage_upper_value);
	Serial.print(" ");
	Serial.print(voltage_lower_value);
	Serial.print(" ");

	float voltage_diff = voltage_upper_value - voltage_lower_value;

	float voltage_ratio = (voltage - voltage_lower_value)/voltage_diff;

        Serial.print(temperature_diff * voltage_ratio);
        Serial.print(" ");

  
	temperature = temperature_lower_value - (temperature_diff * voltage_ratio);

	return temperature;
}

void setup() 
{
  pinMode(heaterPin, OUTPUT);
  digitalWrite(heaterPin, LOW);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}


void loop() 
{

  int sensorValue = analogRead(thermistorPin);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  Serial.print(voltage);
  Serial.print(" ");
  float temperature = voltage_to_temperature(voltage);
  Serial.println(temperature);
  
  if(voltage > 0.54){
    digitalWrite(heaterPin, HIGH);
    digitalWrite(ledPin, HIGH);
  }else{
    digitalWrite(heaterPin, LOW);
    digitalWrite(ledPin, LOW);
  }
  delay(200);
}
