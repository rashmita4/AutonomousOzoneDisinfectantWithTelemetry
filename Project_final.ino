// Autonomous Ozone Disinfectant With Telemetry

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h> 

// Enter Auth Token in the Blynk App.
char auth[] = "Auth Token for blynk";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Wi-Fi name";
char pass[] = "Enter Wi-Fi password";

BlynkTimer timer;
WidgetLCD lcd(V1);
const int analog_ip = A0;
float sensor_volt; 
float RS_gas; 
float ratio; 
float O3_ppm;
float z;
float R0 = 2.42; //-Replace the name "R0" with the value of R0 in the calibration -/ 

void myTimerEvent()
{
  
  int sensorValue = analogRead (analog_ip); 
  sensor_volt = ((float)sensorValue / 1024) * 3.3; 
  RS_gas = (5.0 - sensor_volt) / sensor_volt; // Depend on RL on yor module 
  ratio = RS_gas / R0; // ratio = RS/R0 
  z = pow(ratio, 2.3348);
  O3_ppm=(9.4783*z)/1000;

  
 //Printing output on serial monitor
  Serial.print("sensor_volt = "); 
  Serial.println(sensor_volt); 
  Serial.print("RS_ratio = "); 
  Serial.println(RS_gas); 
  Serial.print("Rs/R0 = "); 
  Serial.println(ratio); 
  Serial.print("Ozone in ppm = "); 
  Serial.println(O3_ppm); 
  Serial.print("\n\n"); 
  Blynk.virtualWrite(V3, O3_ppm);//To display value on Gauge in Blynk

  if (isnan(O3_ppm)){
    Serial.println("Failed to read from sensor!");
    return;
  }
  if ((O3_ppm)>0.3){
    lcd.print(0, 0, "Disinfection Complete");
    lcd.print(0, 1, "Wait to enter");

    delay(240000); // 4 minutes delay
    if ((O3_ppm)<0.02){
      lcd.print(0, 0, "Disinfection Complete");
      lcd.print(0, 1, "Safe to enter");

      
    }
    else return;
  }
   
}
void setup()
{
  // Debug console
  Serial.begin(9600);//or 115200
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(300000L, myTimerEvent); //To run the loop every 5 minutes
}

void loop()
{
  Blynk.run();
  timer.run();
}
