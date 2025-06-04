#include <WiFi.h>
#include <ESPAsyncWebServer.h>

// WiFi credentials
const char* ssid = "your-ssid";  // Replace with your network SSID
const char* password = "your-password";  // Replace with your network password

// Number of parking slots
#define TOTAL_SLOTS 5

// IR sensor pins
int irSensors[TOTAL_SLOTS] = {2, 3, 4, 5, 6};  // Define the GPIO pins for your IR sensors

// Variables to store the status of each slot
int slotStatus[TOTAL_SLOTS];

// Gate control pin
#define GATE_PIN 12  // Define the pin controlling the entrance gate mechanism

// Initialize the web server on port 80
AsyncWebServer server(80);

void setup() {
  Serial.begin(115200);

  // Setup IR sensors as input
  for (int i = 0; i < TOTAL_SLOTS; i++) {
    pinMode(irSensors[i], INPUT);
  }

  // Setup the gate control pin as output
  pinMode(GATE_PIN, OUTPUT);
  
  // Start with the gate closed
  digitalWrite(GATE_PIN, LOW);

  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Serve the web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    String html = "<!DOCTYPE html><html><head><meta name='viewport' content='width=device-width, initial-scale=1.0'>";
    html += "<style>body{text-align:center;font-family:Arial;}</style></head><body>";
    html += "<h1>Smart Parking System</h1>";
    html += "<h2>Available Slots: " + String(countAvailableSlots()) + "</h2>";
    html += "</body></html>";
    request->send(200, "text/html", html);
  });

  // Start server
  server.begin();
}

void loop() {
  // Update the slot statuses from IR sensors
  for (int i = 0; i < TOTAL_SLOTS; i++) {
    slotStatus[i] = digitalRead(irSensors[i]);
  }

  // Count available slots
  int availableSlots = countAvailableSlots();
  Serial.print("Available Slots: ");
  Serial.println(availableSlots);

  // Control the gate based on the availability of slots
  if (availableSlots == 0) {
    closeGate();  // No available slots, close the gate
  } else {
    openGate();  // Available slots, open the gate
  }

  delay(2000);  // Update every 2 seconds
}

// Count the number of available (free) slots
int countAvailableSlots() {
  int available = 0;
  for (int i = 0; i < TOTAL_SLOTS; i++) {
    if (slotStatus[i] == LOW) {  // Assuming LOW means the slot is free
      available++;
    }
  }
  return available;
}

// Open the gate
void openGate() {
  digitalWrite(GATE_PIN, HIGH);  // Set the gate pin HIGH to open the gate
  Serial.println("Gate Opened");
}

// Close the gate
void closeGate() {
  digitalWrite(GATE_PIN, LOW);  // Set the gate pin LOW to close the gate
  Serial.println("Gate Closed");
}
