#include <SPIFFS.h>                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              #include <WiFi.h>
#include <WiFiClient.h>
#include <HTTPClient.h>
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <AWS_IOT.h>
#include <ArduinoJson.h>
#include <WiFiClientSecure.h>
#include <MQTTClient.h>
#include <esp_task_wdt.h>

#include "index.h" //Web page header file
#include "setting.h"

AsyncWebServer server(80);
AWS_IOT AWS_CLIENT;   


unsigned long lastTime = 0;
unsigned long timerDelay = 5000;


const char* WIFI_SSID = "ssid";
const char* WIFI_PASSWORD = "password";
const char* BaudRate = "baudarate";


char ssid[20];
char password[20];

char HOST_ADDRESS[]="a2vy8psrlkjjpu-ats.iot.us-east-2.amazonaws.com";
char CLIENT_ID[]= "RAMDOM";
char MQTT_TOPIC[]= "$aws/things/saurabh";

char rcvdPayload[512];
int publish_aws = 0;
int setup_aws = 0;
int push = 0;
int msgReceived =0;
int status = WL_IDLE_STATUS;

  int count =0;



//===============================================================
// Setup
//===============================================================

 //==================================
// AWS Setup
//===================================
void aws_setup()
{
 
  if(AWS_CLIENT.connect(HOST_ADDRESS,CLIENT_ID)== 0) // Connect to AWS using Host Address and Cliend ID
    {
        Serial.println("Connected to AWS");
        setup_aws=0;
        publish_aws=1;
        delay(1000);
    }
    else
    {
        Serial.println("AWS connection failed, Check the HOST Address");
        while(1);
    }

    delay(2000);
   
   if(0==AWS_CLIENT.subscribe(MQTT_TOPIC,mySubCallBackHandler))
   {
    Serial.println("Subscribe Sucessful");
    
   }
   else {
    Serial.println("Subscribe Unsucessfull!");
   }


   
   
 }

 
 //==================================
// Publish Setup
//===================================
void publish(){
  char payload[512];
  String RandNum = String(count);

  RandNum.toCharArray(payload, 512);

  if(AWS_CLIENT.publish(MQTT_TOPIC,payload)==0){
    Serial.print("Sucess");
    Serial.println(count);
    count++;
//    delay(500);
  }
  else {
    Serial.print("Fail");
  }
//    delay(500);
}

 //==================================
// Fetch Setup
//=================================== 

void mySubCallBackHandler (char *topicName, int payloadLen, char *payLoad)
{
    strncpy(rcvdPayload,payLoad,payloadLen);
    rcvdPayload[payloadLen] = 0;
    msgReceived = 1;
}
 
 //==================================
// Setup
//=================================== 
void setup(){
  Serial.begin(115200);
  Serial.println();
  Serial.println("Booting Sketch...");

  WiFi.mode(WIFI_AP); //Access Point mode
  WiFi.softAP("CODE_B", "12345678");    //Password length minimum 8 char
  IPAddress myIP = WiFi.softAPIP();
  Serial.print(myIP);
  //server.begin();


  
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html);});     //This is display page

  server.on("/setting", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", setting_html);});
 
  Serial.println("HTTP server started");
  server.on("/baudrate", HTTP_GET, [](AsyncWebServerRequest *request){
        String braudMssg;
            char braudrate[20];

    if (request->hasParam(BaudRate)){
              braudMssg = request->getParam(BaudRate)->value();
              Serial.println(braudMssg);  

              }
                       Serial.println(braudMssg);  

    });
 

   server.on("/get", HTTP_GET, [] (AsyncWebServerRequest *request) 
   {
    String inputMessage1;
    String inputMessage2;
    char ssid[20];
    char password[20];
    {
      if (request->hasParam(WIFI_SSID)||request->hasParam(WIFI_PASSWORD))
      {
        inputMessage1 = request->getParam(WIFI_SSID)->value();
        inputMessage2 = request->getParam(WIFI_PASSWORD)->value();
        }
    }    Serial.println(inputMessage1);
         Serial.println(inputMessage2);  
         inputMessage1.toCharArray(ssid, 20);
         inputMessage2.toCharArray(password, 20);
         
         
          WiFi.begin(ssid, password);
          if(WiFi.status()== WL_CONNECTED){
            WiFi.mode(WIFI_STA);
            Serial.println("WIFI CONNECTED");
            Serial.println(WiFi.localIP());
            setup_aws =1;
          }
          
   });
   
          
    server.begin();                  //Start server
 // Serial.print(inputMessage);};
}


 

void loop(){
  if(setup_aws == 1){
    aws_setup();
  }
  
  if(msgReceived == 1)
    {
        msgReceived = 0;
        //Serial.print("Received Message:");
        Serial.print("Received Message:");
        Serial.println(rcvdPayload);
    }
  if(publish_aws == 1){
    publish();
  }
}
