#include<PantheonDuino.h>
int leds1 = 0;
int leds2 = 0;
char arrColors[4] = {'r', 'g', 'b', 'p'};
float Vin = 5.0;
int R1 = 10000;
byte shotArr[2];


int rgbStart(char color, int number) // Возвращает индекс напряжения
{  
    int innerLeds = 0; // Внутренняя переменная для работы со сдвиговым массивом
    int retVal = 0; // Переменная для возврата значения из функции
    if(color == 'r'){
        innerLeds += 1;
        retVal = 0;
    } else if (color == 'g') {
        innerLeds += 2;
        retVal = 1;
    } else if (color == 'b') {
        innerLeds += 4;
        retVal = 2;
    } else if (color == 'p') {
        innerLeds += 5;
    }
    if(number == 1){
        leds1 += innerLeds;
    } else if (number == 2){
        leds1 += innerLeds * 8;
    } else if (number == 3){
        leds2 += innerLeds;
    } else if (number == 4){
        leds2 += innerLeds * 8;
    }
}

void swap( char &left, char &right )  // Вспомогательная функция для перемешивания массива
{
char tmp = left;
left = right;
right = tmp;
}

void setup() {
    Serial.begin(9600);
    //getShot(7, &Serial, shotArr);
    randomSeed(analogRead(5)); // Случайный сид рандома
    for(size_t i = 0; i < 4; i++) { 
        swap(arrColors[i], arrColors[random(0, 3)]);
    }
    for(int i = 0; i < 4; i++){
        rgbStart(arrColors[i], i+1);
        Serial.println(arrColors[i]);
    }
    digitalWrite(6, LOW);
    shiftOut(9, 10, MSBFIRST, leds1);
    shiftOut(7, 8, MSBFIRST, leds2);
//    shiftOut(11, 12, MSBFIRST, leds1);
//    shiftOut(9, 10, MSBFIRST, leds2);
    digitalWrite(6, HIGH);
}


int checkResist(int pin, char color){
    int raw = analogRead(pin);
    if (raw) {
        float Vout = (raw*Vin)/1024.0;
        float R2 = R1*((Vin/Vout)-1);
        Serial.println(R2);
        delay(50);
        if(color == 'r'){
            if(R2 < 400) return 1;
        } else if (color == 'g'){
            if(R2 > 600 && R2 < 1800) return 1;
        } else if (color == 'b'){
            if(R2 > 8000 && R2 < 12000) return 1;
        } else if (color == 'p'){
            if(R2 > 60000) return 1;
        } else {
            return 0;
        }
    }
}

void blink(int pin){
    for(int i = 0; i < 15; i++){
        digitalWrite(pin, HIGH);
        delay(50);
        digitalWrite(pin, LOW);
        delay(50);
    }
}

void(* resetFunc) (void) = 0; // Функция перезапуска

void loop() {
    // A0 - 1, A1 - 2, A3 - 3, A4 - 4
    // r - 0 ohm
    // g - 1k ohm
    // b - 10k ohm
    // p - 100k ohm
    int sum = 0;
    for(int i = 0; i < 4; i++){
        sum += checkResist(i, arrColors[i]);
    }
    if(sum == 4){
        byte arr[2];
        digitalWrite(2, HIGH);
        //getShot(7, &Serial, shotArr);
        //if(arr[0] == shotArr[0] && arr[1] == shotArr[1]){
            //digitalWrite(2, HIGH); // Светодиод что всё выполнено
            //delay(10000000000); // Остановка "навсегда"
        //} else {
            //blink(2);
            //resetFunc();
        //}
    }
}
