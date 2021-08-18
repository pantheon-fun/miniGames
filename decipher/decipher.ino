// TODO create functions for tm1638


//MODES:
/**
 *
 * 0. Push button which diode is lit on                         !
 *
 * 1. Push buttons to turn all leds on                          !
 * 
 * 2. Simon says                                                !
 * 
 * 3. Push buttons to get sum of 21                             !
 * 
 * 4. button change digit. Right digit - led on. all leds - win !
 * 
 * 5. Simply wait
 *
 * 6. Balance the decode path 
 * 
*/

int mode;

void setup(){
    pinMode(11, OUTPUT);
    digitalWrite(11, HIGH);
    randomSeed(analogRead(A0))
    mode = random(7);
}

void led_on(int led){
    NULL;
}
void led_off(int led){
    NULL;
}
void leds_on(){
    NULL;
}
void leds_off(){
    NULL;
}
int get_button(){
    NULL;
}
void failure(){
    NULL;
}
void win(){
    NULL;
}
void lcd_print(String msg){
    NULL;
}

void loop(){
    int sum = 0;
    switch(mode){
        case 0:
            leds_off();
            int retries = random(10,15);
            for(int i = 0; i < retries, i++){
                delay(250);
                int led = random(8);
                led_on(led);
                int btn;
                while(btn != led){
                    btn = get_button();
                    if(btn > -1 && btn != led){
                        failure();
                        return;
                    }
                }
            }
            win();
        case 1:
            leds_off();
            int leds[8];
            for(int i = 0; i < 8; i++){
                leds[i] = random(2);
                if(leds[i] == 1){
                    led_on(i);
                } else {
                    led_off(i);
                }
            }
            unsigned long timer = millis();
            while(true){
                if(millis()-timer > 10000){
                    failure();
                }
                sum = 1;
                for(int i = 0; i < 8; i++){
                    if(leds[i] == 0){
                        sum = 0;
                        break;
                    }
                }
                int btn = get_button();
                if(btn == -1){
                    continue;
                }
                if(leds[btn] == 1){
                    leds[btn] = 0;
                    led_off(btn);
                } else {
                    leds[btn] = 1;
                    led_on(btn);
                }
                delay(150);
            }
            win();
        case 2:
            leds_off();
            for(int i = 1; i < 6; i++){
                int leds[i];
                for(int j = 0; j < i; j++){
                    leds[j] = random(8);
                    led_on(j);
                    delay(150);
                    leds_off();
                    int btn = -1;
                    while(btn < 0){
                        btn = get_button();
                        if(btn == j){
                            break;
                        } else if(btn == -1){
                            continue;
                        } else {
                            failure();
                        }
                    }
                }
            }
            win();
        case 3:
            leds_off();
            int leds[8] = {0,0,0,0,0,0,0,0};
            int leds_n[8] = {1,2,3,4,5,6,7,8};
            for(int i = 0; i < 8; i++){
                int j = random(0, 8);
                int _temp = leds_n[i]
                leds_n[i] = leds_n[j]
                leds_n[j] = _temp
            }
            unsigned long timer = millis();
            while(sum != 21){
                if(millis()-timer > 25000){
                    failure();
                }
                int btn = get_button();
                if(btn < 0){
                    continue;
                }
                if(leds[btn] == 0){
                    leds[btn] = 1;
                    led_on(btn);
                } else {
                    leds[btn] = 0;
                    led_off(btn);
                }
                for(int i = 0; i < 8; i++){
                    if(leds[i] == 1){
                        sum += leds_n[i];
                        lcd_print(String(sum));
                    }
                }
            }
            win();
        case 4:
            leds_off();
            int digits[8];
            for(int i = 0; i < 8; i++){
                digits[i] = random(10);
            }
            int lcd_digits[8] = {0,0,0,0,0,0,0,0};
            unsigned long timer = millis();
            while(sum != 8){
                sum = 0;
                if(millis() - timer > 15000){
                    failure();
                }
                int btn = get_button();
                if(btn == -1){
                    continue;
                }
                lcd_digits[btn]++;
                if(lcd_digits[btn] > 9){
                    lcd_digits[btn] == 0;
                }
                String msg;
                for(int i = 0; i< 8; i++){
                    msg.concat(lcd_digits[i]);
                    if(lcd_digits[i] == digits[i]){
                        sum += 1;
                    }
                }
            }
            win();
    }
}

