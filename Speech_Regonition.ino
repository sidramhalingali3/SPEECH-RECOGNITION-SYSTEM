String text = "";  // Initialize the input string

void setup() {
  pinMode(13, OUTPUT);     
  Serial.begin(9600);       // Start Serial communication
}

void loop() {
  while (Serial.available()) {
    delay(10);              // Small delay to allow all characters to arrive
    char c = Serial.read(); // Read incoming character
    text += c;              // Append character to text
  }

  if (text.length() > 0) {
    text.trim();            // Remove whitespace and newline characters
    Serial.println("Received: " + text);  // Print received command

     if (text == "ON") {
      digitalWrite(13, HIGH);    // Turn OFF the LED
    }
    else if (text == "OFF") {
      digitalWrite(13, LOW);    // Turn OFF the LED
    }

    text = "";  // Clear the text after processing
  }
}
