//Project

#include <WiFi.h>    //1
#include <PubSubClient.h>

#define ssid  "MDM"
#define pass  "3112003&7"
#define led 22
#define ir 36

WiFiClient WiFiClienT;    
PubSubClient client(WiFiClienT);   

const char broker[]="broker.emqx.io";  
const int port=1883;

char message[100];  // global

void callback(char topic[] , byte* payload , unsigned int length  ){   
  Serial.println("topic :");
  Serial.println(topic);
  // digitalWrite(led,HIGH);

  for(int i=0 ; i< length ;i++){
      
      Serial.print((char)payload[i]);
      message[i]=(char)payload[i];   // 
      // strcmp(message,"on");
  }
  message[length] = '\0';
  Serial.println(message);
  
  if(!strcmp(message,"off")){           // to compare string
      digitalWrite(led,LOW);
      // delay(500);
      


  }else if(!strcmp(message,"on")){
        digitalWrite(led,HIGH);
        // delay(500);
  }
}


void setup() {
  
  pinMode(led,OUTPUT); //led
  pinMode(ir,INPUT); //ir
  Serial.begin(9600);
  WiFi.begin(ssid,pass);
  
  
  while(WiFi.status()!=WL_CONNECTED){
    Serial.println(WiFi.status());
    delay(500);
  }
  Serial.println(WiFi.status());
  Serial.println(WiFi.localIP());

  client.setServer(broker,port);  
  client.setCallback(callback);

  //client.connect("Secttttor_Mo1212675");   // id  
  while(!client.connect("Secttttor_Mo12126755123")){
    Serial.println("not yet");
    delay(500);
  }
  Serial.println("connected to broker");
  while(!client.subscribe("/sectorb5/msbah/3")){
    Serial.println("not yet");
    delay(500);
  }
      Serial.println("i subscribed to led");  
  
}

void loop() {
  client.loop();
  int read;
  read = digitalRead(ir);  // to string
  // Serial.println(read);
  if (read==0){
    client.publish("/sectorb5/msbah/1","object");
    client.publish("/sectorb5/msbah/2","yes");
          // digitalWrite(led,HIGH);

    // Serial.println(1);
        delay(500);

    
  }else{
    client.publish("/sectorb5/msbah/1","noobject");
    client.publish("/sectorb5/msbah/2","no");
          // digitalWrite(led,LOW);

    // Serial.println(2);
        delay(500);

  }
}

