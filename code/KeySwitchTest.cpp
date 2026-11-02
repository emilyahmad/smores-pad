#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET -1
#define OLED_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int pins[] = {D2, D3, D7, D8};
const char* names[] = {"SW1", "SW2", "SW3", "SW4"};
bool last[4] = {HIGH, HIGH, HIGH, HIGH};
unsigned long pressCount[4] = {0, 0, 0, 0};
int lastPressed = -1;

void draw() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  // Line 1: live state of all four keys (# = held, . = up)
  display.setCursor(0, 0);
  display.print("Keys: ");
  for (int i = 0; i < 4; i++) {
    display.print(last[i] == LOW ? "# " : ". ");
  }

  // Line 2: last key pressed
  display.setCursor(0, 12);
  if (lastPressed >= 0) {
    display.print("Last: ");
    display.print(names[lastPressed]);
  } else {
    display.print("Press a key...");
  }

  // Line 3: press counts
  display.setCursor(0, 24);
  for (int i = 0; i < 4; i++) {
    display.print(pressCount[i]);
    display.print(" ");
  }
  display.display();
}

void setup() {
  Serial.begin(115200);
  delay(2000);

  for (int i = 0; i < 4; i++) pinMode(pins[i], INPUT_PULLUP);

  // Swapped pins: SDA = GPIO7, SCL = GPIO6
  Wire.begin(7, 6);

  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS)) {
    Serial.println("OLED not detected or initialization failed!");
    while (true) delay(1000);
  }

  Serial.println("Ready. Press keys.");
  draw();
}

void loop() {
  bool changed = false;
  for (int i = 0; i < 4; i++) {
    bool now = digitalRead(pins[i]);
    if (now != last[i]) {
      delay(10);                       // simple debounce
      now = digitalRead(pins[i]);
      if (now != last[i]) {
        last[i] = now;
        changed = true;
        if (now == LOW) {
          pressCount[i]++;
          lastPressed = i;
          Serial.printf("%s PRESSED\n", names[i]);
        } else {
          Serial.printf("%s released\n", names[i]);
        }
      }
    }
  }
  if (changed) draw();
}
