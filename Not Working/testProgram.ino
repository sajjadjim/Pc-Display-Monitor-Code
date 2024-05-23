void setup() {
  // Start serial communication at a baud rate of 9600
  Serial.begin(112500);

  // Define the original string
  String myString = "Hello, Arduino World!";

  // Use the substring() method to get a part of the string
  // Here, we're getting the substring starting from index 0 to index 5, which will be "Hello"
  String greeting = myString.substring(0, 5);

  // Now, let's get another substring from index 7 to index 19, which will be "Arduino World"
  String location = myString.substring(7, 19);

  // Print the original string and the substrings to the Serial Monitor
  Serial.println("Original String: " + myString);
  Serial.println("Greeting: " + greeting);
  Serial.println("Location: " + location);
}

void loop() {
  // Nothing to do here
}
