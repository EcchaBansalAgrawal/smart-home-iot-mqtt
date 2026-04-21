// Include required libraries
#include <ESP8266WiFi.h>     // WiFi library for ESP8266
#include <PubSubClient.h>    // MQTT client library

// WiFi credentials (replace with your network details)
const char* ssid     = "NETWORK_NAME";
const char* password = "NETWORK_PASSWORD";

// MQTT Broker IP (Raspberry Pi running Mosquitto)
const char* mqtt_server = "IP_ADDRESS_OF_RASPBERRY_PI";

// ----------- CONFIGURATION (EDIT FOR EACH NODE) -----------

// Unique client ID for each ESP device
#define CLIENT_ID   "ESP04_Relay4"   

// MQTT topic this device will subscribe to
#define MQTT_TOPIC  "kitchen/light" 

// GPIO pin connected to relay
#define RELAY_PIN 0   

// ---------------------------------------------------------

// Create WiFi and MQTT client objects
WiFiClient espClient;
PubSubClient client(espClient);


// ----------- FUNCTION: CONNECT TO WIFI -----------
void setup_wifi() {
  delay(10);

  WiFi.mode(WIFI_STA);             // Set ESP as Station mode
  WiFi.begin(ssid, password);      // Start WiFi connection

  int timeout = 0;

  // Wait for connection (max ~10 seconds)
  while (WiFi.status() != WL_CONNECTED && timeout < 20) {
    delay(500);
    timeout++;
  }

  // Extra delay for stability after connection
  delay(1000); 
}


// ----------- FUNCTION: MQTT MESSAGE CALLBACK -----------
// This function runs whenever a message is received on subscribed topic
void callback(char* topic, byte* payload, unsigned int length) {

  String message = "";

  // Convert received byte payload into String
  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }

  // Control relay based on message
  if (message == "ON") {
    digitalWrite(RELAY_PIN, LOW);   // Relay ON (active-LOW)
  } 
  else if (message == "OFF") {
    digitalWrite(RELAY_PIN, HIGH);  // Relay OFF
  }
}


// ----------- FUNCTION: RECONNECT TO MQTT BROKER -----------
void reconnect() {

  int retries = 0;

  // Try to reconnect up to 5 times
  while (!client.connected() && retries < 5) {  

    // Attempt connection with client ID
    if (client.connect(CLIENT_ID)) {

      // Subscribe to topic after successful connection
      client.subscribe(MQTT_TOPIC);

    } else {

      // Wait before retrying
      delay(2000);
      retries++;
    }
  }
}


// ----------- SETUP FUNCTION (RUNS ONCE) -----------
void setup() {

  // IMPORTANT: Set relay OFF before anything else
  // GPIO0 LOW during boot = flash mode (can break startup)
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH);  // Relay OFF (safe state)

  // Serial disabled to save memory & free GPIO pins
  // Uncomment if debugging required
  // Serial.begin(115200);

  // Connect to WiFi
  setup_wifi();

  // Configure MQTT server and port
  client.setServer(mqtt_server, 1883);

  // Set keep-alive interval (seconds)
  client.setKeepAlive(60);

  // Set callback function for incoming messages
  client.setCallback(callback);
}


// ----------- LOOP FUNCTION (RUNS CONTINUOUSLY) -----------
void loop() {

  // Ensure MQTT connection is alive
  if (!client.connected()) {
    reconnect();
  }

  // Process incoming MQTT messages
  client.loop();

  // Small delay to avoid watchdog reset
  delay(100);
}