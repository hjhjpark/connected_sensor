#include "mine.h"
#include <ESP8266WiFi.h>
#include <WiFiClient.h>


mine::mine(void) {
    _host = "hjhjpark";
    _url = "2-52-43-244-213.us-west-2.compute.amazonaws.com";
    _httpPort = 8083;
}

void mine::setapikey(String apikey) {
    _apikey = apikey;

}

boolean Sogang::send(int pm25, int pm10) {
  WiFiClient client;
  if (!client.connect(_host, _httpPort)) {
    Serial.print("connection failed: ");
    return(false);
  }

  String payload = "format=4&macapikey="+ _apikey +"&type=D&value="+ String(pm25)+","+ String(pm10) +"&seq="+ String(_seq++);
  String getheader = "GET "+ String(_url) + String()+ "&"+ payload +" HTTP/1.1"
  client.println(getheader);
  client.println("User-Agent: ESP8266 Kyuho Kim");  
  client.println("Host: " + String(_host));  
  client.println("Connection: close");  
  client.println();

  Serial.println(getheader);
  while (client.connected()) {
    String line = client.readStringUntil('\n');
    Serial.println(line);
  }
  Serial.println("Done mine.");
}
