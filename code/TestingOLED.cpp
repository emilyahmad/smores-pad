
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET -1
#define OLED_ADDRESS 0x3C

Adafruit_SSD1306 display(
  SCREEN_WIDTH,
  SCREEN_HEIGHT,
  &Wire,
  OLED_RESET
);

void setup() {
  Serial.begin(115200);

  // XIAO ESP32C3: SDA = GPIO6, SCL = GPIO7
  Wire.begin(6, 7);

  // Initialize the OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS)) {
    Serial.println("OLED not detected or initialization failed!");
    while (true) {
      delay(1000);
    }
  }

  // Clear the screen
  display.clearDisplay();

  // Set up text
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);

  // Print text
  display.println("blub blub blub blub");
  display.println("i miss u <333");

  // Send the text to the screen
  display.display();

  Serial.println("OLED initialized successfully!");
}

void loop() {
  // Nothing else needed for this test
}
