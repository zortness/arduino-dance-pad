#include <Keyboard.h>

/*
 * Read from force resistors on analog pins
 * translate to button states
 * send button states as keyboard presses
 */
const bool DEBUG = false;
 
// pin mappings
const int btn_up = A4;
const int btn_down = A5;
const int btn_left = A7;
const int btn_right = A2;
const int btn_A = A1;
const int btn_B = A8;
const int btn_select = A9;
const int btn_start = A0;
const int btn_extraL = A6;
const int btn_extraR = A3;

// keyboard mappings
const int btn_up_key = KEY_UP_ARROW;
const int btn_down_key = KEY_DOWN_ARROW;
const int btn_left_key = KEY_LEFT_ARROW;
const int btn_right_key = KEY_RIGHT_ARROW;
const int btn_A_key = 0x41; // ascii 'A'
const int btn_B_key = 0x42; // ascii 'B'
const int btn_start_key = KEY_RETURN;
const int btn_select_key = KEY_ESC;
const int btn_extraL_key = KEY_PAGE_UP;
const int btn_extraR_key = KEY_PAGE_DOWN;

// analog threshold to trigger a button
const int threshold = 100;
/*
 * values on my controller pull down in the range from ~450 to ~20 when pressed
 * we'll say anything under 100 counts as contact
 */

// last read analog value for each button
int btn_up_val = 0;
int btn_down_val = 0;
int btn_left_val = 0;
int btn_right_val = 0;
int btn_A_val = 0;
int btn_B_val = 0;
int btn_select_val = 0;
int btn_start_val = 0;
int btn_extraL_val = 0;
int btn_extraR_val = 0;

bool btn_up_state = false;
bool btn_down_state = false;
bool btn_left_state = false;
bool btn_right_state = false;
bool btn_A_state = false;
bool btn_B_state = false;
bool btn_select_state = false;
bool btn_start_state = false;
bool btn_extraL_state = false;
bool btn_extraR_state = false;

void setup() {
  if (DEBUG) {
    // initialize serial communications at 9600 bps:
    Serial.begin(9600);
  }
  Keyboard.begin();
}

void loop() {

  readCurrentVals();

  checkAndSendState();

  if (DEBUG) {
    printDebugVals();
    // wait half a second
    delay(500);
  }
  
}

void readCurrentVals() {
  // read the analog in value:
  btn_up_val = analogRead(btn_up);
  btn_down_val = analogRead(btn_down);
  btn_left_val = analogRead(btn_left);
  btn_right_val = analogRead(btn_right);
  btn_A_val = analogRead(btn_A);
  btn_B_val = analogRead(btn_B);
  btn_select_val = analogRead(btn_select);
  btn_start_val = analogRead(btn_start);
  btn_extraL_val = analogRead(btn_extraL);
  btn_extraR_val = analogRead(btn_extraR);
}

void checkAndSendState() {
  // UP
  if (btn_up_val <= threshold && !btn_up_state) {
    btn_up_state = true;
    Keyboard.press(btn_up_key);
  } else if (btn_up_val > threshold && btn_up_state) {
    btn_up_state = false;
    Keyboard.release(btn_up_key);
  }

  // DOWN
  if (btn_down_val <= threshold && !btn_down_state) {
    btn_down_state = true;
    Keyboard.press(btn_down_key);
  } else if (btn_down_val > threshold && btn_down_state) {
    btn_down_state = false;
    Keyboard.release(btn_down_key);
  }

  // LEFT
  if (btn_left_val <= threshold && !btn_left_state) {
    btn_left_state = true;
    Keyboard.press(btn_left_key);
  } else if (btn_left_val > threshold && btn_left_state) {
    btn_left_state = false;
    Keyboard.release(btn_left_key);
  }

  // RIGHT
  if (btn_right_val <= threshold && !btn_right_state) {
    btn_right_state = true;
    Keyboard.press(btn_right_key);
  } else if (btn_right_val > threshold && btn_right_state) {
    btn_right_state = false;
    Keyboard.release(btn_right_key);
  }

  // A
  if (btn_A_val <= threshold && !btn_A_state) {
    btn_A_state = true;
    Keyboard.press(btn_A_key);
  } else if (btn_A_val > threshold && btn_A_state) {
    btn_A_state = false;
    Keyboard.release(btn_A_key);
  }

  // B
  if (btn_B_val <= threshold && !btn_B_state) {
    btn_B_state = true;
    Keyboard.press(btn_B_key);
  } else if (btn_B_val > threshold && btn_B_state) {
    btn_B_state = false;
    Keyboard.release(btn_B_key);
  }

  // SELECT
  if (btn_select_val <= threshold && !btn_select_state) {
    btn_select_state = true;
    Keyboard.press(btn_select_key);
  } else if (btn_select_val > threshold && btn_select_state) {
    btn_select_state = false;
    Keyboard.release(btn_select_key);
  }

  // START
  if (btn_start_val <= threshold && !btn_start_state) {
    btn_start_state = true;
    Keyboard.press(btn_start_key);
  } else if (btn_start_val > threshold && btn_start_state) {
    btn_start_state = false;
    Keyboard.release(btn_start_key);
  }

  // EXTRA-L
  if (btn_extraL_val <= threshold && !btn_extraL_state) {
    btn_extraL_state = true;
    Keyboard.press(btn_extraL_key);
  } else if (btn_extraL_val > threshold && btn_extraL_state) {
    btn_extraL_state = false;
    Keyboard.release(btn_extraL_key);
  }

  // EXTRA-R
  if (btn_extraR_val <= threshold && !btn_extraR_state) {
    btn_extraR_state = true;
    Keyboard.press(btn_extraR_key);
  } else if (btn_extraR_val > threshold && btn_extraR_state) {
    btn_extraR_state = false;
    Keyboard.release(btn_extraR_key);
  }
}

void printDebugVals() {
  // print the results to the serial monitor:
  Serial.print("^:");  Serial.println(btn_up_val);
  Serial.print("V: "); Serial.println(btn_down_val);
  Serial.print("<: "); Serial.println(btn_left_val);
  Serial.print(">: "); Serial.println(btn_right_val);
  Serial.print("A: "); Serial.println(btn_A_val);
  Serial.print("B: "); Serial.println(btn_B_val);
  Serial.print("SEL: "); Serial.println(btn_select_val);
  Serial.print("STR: "); Serial.println(btn_start_val);
  Serial.print("L: "); Serial.println(btn_extraL_val);
  Serial.print("R: "); Serial.println(btn_extraR_val);
}

