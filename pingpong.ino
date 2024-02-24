
// LCD DISPLAY
// -----------

// include library for lcd
#include <LiquidCrystal.h>

// lcd pins
const int rs = 12, en = 11, d4 = 6, d5 = 7, d6 = 8, d7 = 9;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);





// BUTTONS
// -------

// button pins
const int buttonWhite = 2;
const int buttonBlue = 4;

// counters for button presses
int countWhite = 0;
int countBlue = 0;
int countTotal = 0;

// first press variable
bool firstPress = true;





// LEDs 
// ----

// led pins
const int ledWhite = 3;
const int ledBlue = 5;





// INITIALISING
// ------------

void setup() {

    // ledWhite
    pinMode(ledWhite, OUTPUT);

    // ledBlue
    pinMode(ledBlue, OUTPUT);

    // buttonWhite
    pinMode(buttonWhite, INPUT);

    // buttonBlue
    pinMode(buttonBlue, INPUT);

    // lcd
    lcd.begin(16, 2);

}





// MAIN LOOP
// ---------

void loop() {

    // check if white button is pressed
    if (digitalRead(buttonWhite) == HIGH) {

        // check if this is the first press (var = true)
        if (firstPress) {
            firstPress = false;
            digitalWrite(ledWhite, HIGH); // turn on white led
        } 

        // if firstPress is false, count up
        else {
            countWhite++;      
            countTotal++;  
            if (countTotal % 2 == 0) { // when total number of counts is even switch led
                if (digitalRead(ledWhite) == HIGH) {
                    digitalWrite(ledWhite, LOW);
                    digitalWrite(ledBlue, HIGH);
                } else if (digitalRead(ledBlue) == HIGH) {
                    digitalWrite(ledBlue, LOW);
                    digitalWrite(ledWhite, HIGH);
                }
            }
        }

        delay(500); // debounce delay
    }


    // check if blue button is pressed
    if (digitalRead(buttonBlue) == HIGH) {

        // check if this is the first press (var = true)
        if (firstPress) {
            firstPress = false;
            digitalWrite(ledBlue, HIGH); // turn on blue led
        } 

        // if firstPress is false, count up
        else {
            countBlue++;
            countTotal++;
            if (countTotal % 2 == 0) { // when total number of counts is even switch led
                if (digitalRead(ledWhite) == HIGH) {
                    digitalWrite(ledWhite, LOW);
                    digitalWrite(ledBlue, HIGH);
                } else if (digitalRead(ledBlue) == HIGH) {
                    digitalWrite(ledBlue, LOW);
                    digitalWrite(ledWhite, HIGH);
                }
            }
        }

        delay(500); // debounce delay
    }

    // write to lcd display
    lcd.setCursor(0, 0); // first lcd row
    lcd.print("Team1  |  Team2");
    lcd.setCursor(0, 1); // second lcd row
    if (countWhite < 10) { // print leading zero if count is less than 10
        lcd.print("0");
    }
    lcd.print(countWhite);
    lcd.print("-----|-----");
    if (countBlue < 10) {  // print leading zero if count is less than 10
        lcd.print("0");
    }
    lcd.print(countBlue);

}
