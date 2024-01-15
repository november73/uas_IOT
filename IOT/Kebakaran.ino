#define BLYNK_TEMPLATE_ID "TMPL6PY6kOk18"
#define BLYNK_TEMPLATE_NAME "Fire Alarem"
#define BLYNK_AUTH_TOKEN "s_3PWq6gE8yYVWeEGZKLQEAPj87-SNTu"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

 
char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "UMBANTEN1";  // type your wifi name
char pass[] = "aryajayasantika2020";  // type your wifi password
 

BlynkTimer timer;
int flag=0; 
void sendSensor(){ 
   int isButtonPressed = digitalRead(D1);
  if (isButtonPressed==0 && flag==0) {
    Serial.println("Fire in the House");  
    //Blynk.email("nayahnaya7113@gmail.com", "Alert", "Fire Detected!");
    Blynk.logEvent("Fire Alarem","Fire Detected");
    
    flag=1;
  }
  else if (isButtonPressed==1)
  {
    flag=0;
    
  }


 
}

void setup(){
  pinMode(D1, INPUT);
 
   Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  //dht.begin();
  timer.setInterval(5000L, sendSensor);
}

void loop(){
  Blynk.run();
  timer.run();
}