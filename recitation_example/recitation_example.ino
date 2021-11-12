#include <WiFi.h>

#include "webpage.h"  // contains string "body" html code
#include "html510.h"
HTML510Server h(80);

const char* ssid = "recitation";
const char* password = "lab4_mobility";

bool motor_status = true;

/*****************/
/* web handler   */
void handle_root() {
  h.sendhtml(body);
}

void handle_slider(){
  String s = "Motor PWM: ";
  int slider_pos = h.getVal();
  Serial.println(slider_pos);
  // handle motors here
  s = s + String(slider_pos);
  h.sendplain(s);
}

void disable_motors(){
  Serial.println("disabling motors");
  // disable motors here
  motor_status = false;
  h.sendplain("Disabled");

}

void enable_motors(){
  Serial.println("enabling motors");
  // enable motors here
  motor_status = true;
  h.sendplain("Enabled");
}

void toggle_motors(){
  if(motor_status){
    disable_motors();
  }
  else{
    enable_motors();
  }
}

void setup_motors(){
  // set motor pins to be output
  // set motor direction pins
  // initial pwm settings for motor channels
  // attach pwm signal to output pins
}

void setup() {
  Serial.begin(115200); delay(10);

  setup_motors();

  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);
  delay(100);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);
             
  h.begin();
  h.attachHandler("/ ",handle_root);
  h.attachHandler("/slider_1?val=",handle_slider);
  // h.attachHandler("/slider_r?val=",handle_slider);
  h.attachHandler("/toggle_motors",toggle_motors);
}

void loop(){
  h.serve();
  delay(10);
}
