EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L 74xx:74HC595 U1
U 1 1 6050438E
P 4700 2450
F 0 "U1" H 4700 3231 50  0000 C CNN
F 1 "74HC595" H 4700 3140 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm" H 4700 2450 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74hc595.pdf" H 4700 2450 50  0001 C CNN
	1    4700 2450
	-1   0    0    -1  
$EndComp
$Comp
L Device:LED_RGBC Дырка1
U 1 1 605072C1
P 2650 2150
F 0 "Дырка1" H 2650 2647 50  0000 C CNN
F 1 "LED_RGBC" H 2650 2556 50  0000 C CNN
F 2 "LED_THT:LED_D5.0mm-4_RGB_Wide_Pins" H 2650 2100 50  0001 C CNN
F 3 "~" H 2650 2100 50  0001 C CNN
	1    2650 2150
	1    0    0    -1  
$EndComp
$Comp
L Device:LED_RGBC Дырка2
U 1 1 6050A646
P 2650 3000
F 0 "Дырка2" H 2650 3497 50  0000 C CNN
F 1 "LED_RGBC" H 2650 3406 50  0000 C CNN
F 2 "LED_THT:LED_D5.0mm-4_RGB_Wide_Pins" H 2650 2950 50  0001 C CNN
F 3 "~" H 2650 2950 50  0001 C CNN
	1    2650 3000
	1    0    0    -1  
$EndComp
$Comp
L Device:LED_RGBC Дырка3
U 1 1 6050BD47
P 2650 3850
F 0 "Дырка3" H 2650 4347 50  0000 C CNN
F 1 "LED_RGBC" H 2650 4256 50  0000 C CNN
F 2 "LED_THT:LED_D5.0mm-4_RGB_Wide_Pins" H 2650 3800 50  0001 C CNN
F 3 "~" H 2650 3800 50  0001 C CNN
	1    2650 3850
	1    0    0    -1  
$EndComp
$Comp
L Device:LED_RGBC Дырка4
U 1 1 6050D9BA
P 2650 4700
F 0 "Дырка4" H 2650 5197 50  0000 C CNN
F 1 "LED_RGBC" H 2650 5106 50  0000 C CNN
F 2 "LED_THT:LED_D5.0mm-4_RGB_Wide_Pins" H 2650 4650 50  0001 C CNN
F 3 "~" H 2650 4650 50  0001 C CNN
	1    2650 4700
	1    0    0    -1  
$EndComp
$Comp
L MCU_Module:Arduino_UNO_R2 Main1
U 1 1 60500BA3
P 7250 3000
F 0 "Main1" H 7250 4181 50  0000 C CNN
F 1 "Arduino_UNO_R2" H 7250 4090 50  0000 C CNN
F 2 "Module:Arduino_UNO_R2" H 7250 3000 50  0001 C CIN
F 3 "https://www.arduino.cc/en/Main/arduinoBoardUno" H 7250 3000 50  0001 C CNN
	1    7250 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	4700 1850 5200 1850
Wire Wire Line
	5100 2650 5650 2650
Wire Wire Line
	5100 2350 5200 2350
Wire Wire Line
	5200 2350 5200 1850
$Comp
L power:+1V5 #PWR01
U 1 1 6051E7C3
P 6250 1750
F 0 "#PWR01" H 6250 1600 50  0001 C CNN
F 1 "+1V5" H 6265 1923 50  0000 C CNN
F 2 "" H 6250 1750 50  0001 C CNN
F 3 "" H 6250 1750 50  0001 C CNN
	1    6250 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	6250 1750 5200 1750
Wire Wire Line
	5200 1750 5200 1850
Connection ~ 5200 1850
Wire Wire Line
	5100 2050 6050 2050
Wire Wire Line
	6050 2050 6050 3500
Wire Wire Line
	6050 3500 6750 3500
Wire Wire Line
	6750 3600 5950 3600
Wire Wire Line
	5950 3600 5950 2250
Wire Wire Line
	5950 2250 5100 2250
Wire Wire Line
	5100 2550 5850 2550
Wire Wire Line
	5850 2550 5850 3700
Wire Wire Line
	5850 3700 6750 3700
Wire Wire Line
	5650 4200 6200 4200
Wire Wire Line
	7150 4200 7150 4100
Wire Wire Line
	5650 2650 5650 3150
Wire Wire Line
	4700 3150 5650 3150
Connection ~ 5650 3150
Wire Wire Line
	5650 3150 5650 4200
$Comp
L 74xx:74HC595 U4
U 1 1 605276D5
P 4700 4000
F 0 "U4" H 4700 4781 50  0000 C CNN
F 1 "74HC595" H 4700 4690 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm" H 4700 4000 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74hc595.pdf" H 4700 4000 50  0001 C CNN
	1    4700 4000
	-1   0    0    -1  
$EndComp
Wire Wire Line
	4700 3400 5200 3400
Wire Wire Line
	5200 3400 5200 2350
Connection ~ 5200 2350
Wire Wire Line
	5100 3900 5200 3900
Wire Wire Line
	5200 3900 5200 3400
Connection ~ 5200 3400
Wire Wire Line
	5100 3600 5300 3600
Wire Wire Line
	5300 3600 5300 3200
Wire Wire Line
	5300 3200 6750 3200
Wire Wire Line
	5100 3800 5350 3800
Wire Wire Line
	5350 3800 5350 3300
Wire Wire Line
	5350 3300 6750 3300
Wire Wire Line
	5100 4100 5400 4100
Wire Wire Line
	5400 4100 5400 3400
Wire Wire Line
	5400 3400 6750 3400
Wire Wire Line
	5100 4200 5650 4200
Connection ~ 5650 4200
Wire Wire Line
	4700 4700 5650 4700
Wire Wire Line
	5650 4700 5650 4200
Wire Wire Line
	4300 2050 3350 2050
Wire Wire Line
	3350 2050 3350 1950
Wire Wire Line
	3350 1950 2850 1950
Wire Wire Line
	4300 2150 2850 2150
Wire Wire Line
	4300 2250 3350 2250
Wire Wire Line
	3350 2250 3350 2350
Wire Wire Line
	3350 2350 2850 2350
Wire Wire Line
	4300 2350 3450 2350
Wire Wire Line
	3450 2350 3450 2800
Wire Wire Line
	3450 2800 2850 2800
Wire Wire Line
	4300 2450 3550 2450
Wire Wire Line
	3550 2450 3550 3000
Wire Wire Line
	3550 3000 2850 3000
Wire Wire Line
	4300 2550 3650 2550
Wire Wire Line
	3650 2550 3650 3200
Wire Wire Line
	3650 3200 2850 3200
Wire Wire Line
	4300 3600 3350 3600
Wire Wire Line
	3350 3600 3350 3650
Wire Wire Line
	3350 3650 2850 3650
Wire Wire Line
	4300 3700 3400 3700
Wire Wire Line
	3400 3700 3400 3850
Wire Wire Line
	3400 3850 2850 3850
Wire Wire Line
	4300 3800 3450 3800
Wire Wire Line
	3450 3800 3450 4050
Wire Wire Line
	3450 4050 2850 4050
Wire Wire Line
	4300 3900 3500 3900
Wire Wire Line
	3500 3900 3500 4500
Wire Wire Line
	3500 4500 2850 4500
Wire Wire Line
	4300 4000 3550 4000
Wire Wire Line
	3550 4000 3550 4700
Wire Wire Line
	3550 4700 2850 4700
Wire Wire Line
	4300 4100 3600 4100
Wire Wire Line
	3600 4100 3600 4900
Wire Wire Line
	3600 4900 2850 4900
$Comp
L Connector_Generic:Conn_01x01 Первый_2
U 1 1 6053BD9F
P 1550 2150
F 0 "Первый_2" H 1630 2146 50  0000 L CNN
F 1 "Conn_01x01" H 1630 2101 50  0001 L CNN
F 2 "Connector:Banana_Jack_1Pin" H 1550 2150 50  0001 C CNN
F 3 "~" H 1550 2150 50  0001 C CNN
	1    1550 2150
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x01 Второй_2
U 1 1 6053D71C
P 1550 3000
F 0 "Второй_2" H 1630 2996 50  0000 L CNN
F 1 "Conn_01x01" H 1630 2951 50  0001 L CNN
F 2 "Connector:Banana_Jack_1Pin" H 1550 3000 50  0001 C CNN
F 3 "~" H 1550 3000 50  0001 C CNN
	1    1550 3000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02
U 1 1 60544102
P 5600 5250
F 0 "#PWR02" H 5600 5000 50  0001 C CNN
F 1 "GND" H 5605 5077 50  0000 C CNN
F 2 "" H 5600 5250 50  0001 C CNN
F 3 "" H 5600 5250 50  0001 C CNN
	1    5600 5250
	1    0    0    -1  
$EndComp
Wire Wire Line
	5600 5250 5600 5100
Wire Wire Line
	5600 4800 7150 4800
Connection ~ 7150 4200
Wire Wire Line
	5600 5100 4050 5100
Wire Wire Line
	2450 5100 2450 4700
Connection ~ 5600 5100
Wire Wire Line
	5600 5100 5600 4800
Wire Wire Line
	2450 4700 2450 3850
Connection ~ 2450 4700
Wire Wire Line
	2450 3850 2450 3000
Connection ~ 2450 3850
Wire Wire Line
	2450 2150 2450 3000
Connection ~ 2450 3000
Wire Wire Line
	1600 2150 1550 2150
$Comp
L Connector_Generic:Conn_01x01 Четвертый_2
U 1 1 6054115C
P 1550 4700
F 0 "Четвертый_2" H 1630 4696 50  0000 L CNN
F 1 "Conn_01x01" H 1630 4651 50  0001 L CNN
F 2 "Connector:Banana_Jack_1Pin" H 1550 4700 50  0001 C CNN
F 3 "~" H 1550 4700 50  0001 C CNN
	1    1550 4700
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x01 Третий_2
U 1 1 6053E39C
P 1550 3850
F 0 "Третий_2" H 1630 3846 50  0000 L CNN
F 1 "Conn_01x01" H 1630 3801 50  0001 L CNN
F 2 "Connector:Banana_Jack_1Pin" H 1550 3850 50  0001 C CNN
F 3 "~" H 1550 3850 50  0001 C CNN
	1    1550 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	1350 4700 1350 5450
Wire Wire Line
	7850 5450 7850 3300
Wire Wire Line
	7850 3300 7750 3300
Wire Wire Line
	1350 3850 1200 3850
Wire Wire Line
	1200 3850 1200 5600
Wire Wire Line
	8000 5600 8000 3200
Wire Wire Line
	8000 3200 7750 3200
Wire Wire Line
	7750 3100 8150 3100
Wire Wire Line
	8150 3100 8150 5750
Wire Wire Line
	1050 5750 1050 3000
Wire Wire Line
	1050 3000 1350 3000
Wire Wire Line
	1350 2150 900  2150
Wire Wire Line
	900  2150 900  5900
Wire Wire Line
	8300 5900 8300 3000
Wire Wire Line
	8300 3000 7750 3000
$Comp
L Connector_Generic:Conn_01x01 Первый_1
U 1 1 6056E879
P 8500 1600
F 0 "Первый_1" H 8580 1596 50  0000 L CNN
F 1 "1" H 8580 1551 50  0001 L CNN
F 2 "Connector:Banana_Jack_1Pin" H 8500 1600 50  0001 C CNN
F 3 "~" H 8500 1600 50  0001 C CNN
	1    8500 1600
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x01 Второй_1
U 1 1 6056FD0D
P 8500 1950
F 0 "Второй_1" H 8580 1946 50  0000 L CNN
F 1 "Conn_01x01" H 8580 1901 50  0001 L CNN
F 2 "Connector:Banana_Jack_1Pin" H 8500 1950 50  0001 C CNN
F 3 "~" H 8500 1950 50  0001 C CNN
	1    8500 1950
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x01 Третий_1
U 1 1 605730C5
P 8500 2300
F 0 "Третий_1" H 8580 2296 50  0000 L CNN
F 1 "Conn_01x01" H 8580 2251 50  0001 L CNN
F 2 "Connector:Banana_Jack_1Pin" H 8500 2300 50  0001 C CNN
F 3 "~" H 8500 2300 50  0001 C CNN
	1    8500 2300
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x01 Четвертый_1
U 1 1 605764B2
P 8500 2650
F 0 "Четвертый_1" H 8580 2646 50  0000 L CNN
F 1 "Conn_01x01" H 8580 2601 50  0001 L CNN
F 2 "Connector:Banana_Jack_1Pin" H 8500 2650 50  0001 C CNN
F 3 "~" H 8500 2650 50  0001 C CNN
	1    8500 2650
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R1k1
U 1 1 60586186
P 8200 1950
F 0 "R1k1" V 8096 1950 50  0000 C CNN
F 1 "R_Small" V 8095 1950 50  0001 C CNN
F 2 "Resistor_THT:R_Radial_Power_L7.0mm_W8.0mm_Px2.40mm_Py2.30mm" H 8200 1950 50  0001 C CNN
F 3 "~" H 8200 1950 50  0001 C CNN
	1    8200 1950
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R10k1
U 1 1 60587421
P 8200 2300
F 0 "R10k1" V 8096 2300 50  0000 C CNN
F 1 "R_Small" V 8095 2300 50  0001 C CNN
F 2 "Resistor_THT:R_Radial_Power_L7.0mm_W8.0mm_Px2.40mm_Py2.30mm" H 8200 2300 50  0001 C CNN
F 3 "~" H 8200 2300 50  0001 C CNN
	1    8200 2300
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R100k1
U 1 1 6058A256
P 8200 2650
F 0 "R100k1" V 8096 2650 50  0000 C CNN
F 1 "R_Small" V 8095 2650 50  0001 C CNN
F 2 "Resistor_THT:R_Radial_Power_L7.0mm_W8.0mm_Px2.40mm_Py2.30mm" H 8200 2650 50  0001 C CNN
F 3 "~" H 8200 2650 50  0001 C CNN
	1    8200 2650
	0    1    1    0   
$EndComp
Wire Wire Line
	6250 1750 7450 1750
Wire Wire Line
	7950 1750 7950 1600
Wire Wire Line
	7950 1600 8300 1600
Connection ~ 6250 1750
Wire Wire Line
	7950 1750 7950 1950
Wire Wire Line
	7950 1950 8100 1950
Connection ~ 7950 1750
Wire Wire Line
	7950 1950 7950 2300
Wire Wire Line
	7950 2300 8100 2300
Connection ~ 7950 1950
Wire Wire Line
	7950 2300 7950 2650
Wire Wire Line
	7950 2650 8100 2650
Connection ~ 7950 2300
Wire Wire Line
	7450 1750 7450 2000
Connection ~ 7450 1750
Wire Wire Line
	7450 1750 7950 1750
$Comp
L Device:R_Small R10k2
U 1 1 6059E5F3
P 2850 5200
F 0 "R10k2" H 2909 5200 50  0000 L CNN
F 1 "R_Small" H 2909 5155 50  0001 L CNN
F 2 "Resistor_THT:R_Radial_Power_L7.0mm_W8.0mm_Px2.40mm_Py2.30mm" H 2850 5200 50  0001 C CNN
F 3 "~" H 2850 5200 50  0001 C CNN
	1    2850 5200
	1    0    0    -1  
$EndComp
Connection ~ 2850 5100
Wire Wire Line
	2850 5100 2450 5100
$Comp
L Device:R_Small R10k3
U 1 1 6059EE0D
P 3250 5200
F 0 "R10k3" H 3309 5200 50  0000 L CNN
F 1 "R_Small" H 3309 5155 50  0001 L CNN
F 2 "Resistor_THT:R_Radial_Power_L7.0mm_W8.0mm_Px2.40mm_Py2.30mm" H 3250 5200 50  0001 C CNN
F 3 "~" H 3250 5200 50  0001 C CNN
	1    3250 5200
	1    0    0    -1  
$EndComp
Connection ~ 3250 5100
Wire Wire Line
	3250 5100 2850 5100
$Comp
L Device:R_Small R10k4
U 1 1 6059FC86
P 3650 5200
F 0 "R10k4" H 3709 5200 50  0000 L CNN
F 1 "R_Small" H 3709 5155 50  0001 L CNN
F 2 "Resistor_THT:R_Radial_Power_L7.0mm_W8.0mm_Px2.40mm_Py2.30mm" H 3650 5200 50  0001 C CNN
F 3 "~" H 3650 5200 50  0001 C CNN
	1    3650 5200
	1    0    0    -1  
$EndComp
Connection ~ 3650 5100
Wire Wire Line
	3650 5100 3250 5100
$Comp
L Device:R_Small R10k5
U 1 1 605A0676
P 4050 5200
F 0 "R10k5" H 4109 5200 50  0000 L CNN
F 1 "R_Small" H 4109 5155 50  0001 L CNN
F 2 "Resistor_THT:R_Radial_Power_L7.0mm_W8.0mm_Px2.40mm_Py2.30mm" H 4050 5200 50  0001 C CNN
F 3 "~" H 4050 5200 50  0001 C CNN
	1    4050 5200
	1    0    0    -1  
$EndComp
Connection ~ 4050 5100
Wire Wire Line
	4050 5100 3650 5100
Wire Wire Line
	1350 5450 2850 5450
Wire Wire Line
	2850 5450 2850 5300
Wire Wire Line
	1200 5600 3250 5600
Wire Wire Line
	3250 5600 3250 5300
Wire Wire Line
	1050 5750 3650 5750
Wire Wire Line
	3650 5750 3650 5300
Wire Wire Line
	900  5900 4050 5900
Wire Wire Line
	4050 5900 4050 5300
Wire Wire Line
	2850 5450 7850 5450
Connection ~ 2850 5450
Wire Wire Line
	3250 5600 8000 5600
Connection ~ 3250 5600
Wire Wire Line
	3650 5750 8150 5750
Connection ~ 3650 5750
Wire Wire Line
	4050 5900 8300 5900
Connection ~ 4050 5900
$Comp
L RF_Module:ESP-07 U2
U 1 1 605C5050
P 10200 2450
F 0 "U2" H 10200 3431 50  0000 C CNN
F 1 "ESP-07" H 10200 3340 50  0000 C CNN
F 2 "RF_Module:ESP-07" H 10200 2450 50  0001 C CNN
F 3 "http://wiki.ai-thinker.com/_media/esp8266/esp8266_series_modules_user_manual_v1.1.pdf" H 9850 2550 50  0001 C CNN
	1    10200 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	10200 3150 8450 3150
Wire Wire Line
	8450 4200 7150 4200
Wire Wire Line
	10200 1650 9300 1650
Wire Wire Line
	9300 1650 9300 1800
Wire Wire Line
	9300 1800 7350 1800
Wire Wire Line
	7350 1800 7350 2000
Wire Wire Line
	9600 2050 9600 1950
Wire Wire Line
	9600 1950 9300 1950
Wire Wire Line
	9300 1950 9300 1800
Connection ~ 9300 1800
Wire Wire Line
	10800 1950 10900 1950
Wire Wire Line
	10900 4300 6650 4300
Wire Wire Line
	6650 4300 6650 2500
Wire Wire Line
	6650 2500 6750 2500
Wire Wire Line
	10900 1950 10900 4300
Wire Wire Line
	6750 2400 6550 2400
Wire Wire Line
	6550 2400 6550 4400
Wire Wire Line
	6550 4400 11000 4400
Wire Wire Line
	11000 4400 11000 2150
Wire Wire Line
	11000 2150 10800 2150
$Comp
L Interface_Optical:TSOP21xx U3
U 1 1 60613363
P 9800 3600
F 0 "U3" H 9334 3558 50  0000 R CNN
F 1 "TSOP21xx" H 9334 3649 50  0000 R CNN
F 2 "OptoDevice:Vishay_MOLD-3Pin" H 9750 3225 50  0001 C CNN
F 3 "http://www.vishay.com/docs/82460/tsop45.pdf" H 10450 3900 50  0001 C CNN
	1    9800 3600
	-1   0    0    1   
$EndComp
Wire Wire Line
	7150 4800 7150 4500
Wire Wire Line
	8450 3150 8450 4200
Wire Wire Line
	9400 3400 8600 3400
Wire Wire Line
	8600 3400 8600 4500
Wire Wire Line
	8600 4500 7150 4500
Connection ~ 7150 4500
Wire Wire Line
	7150 4500 7150 4200
Wire Wire Line
	9400 3800 8750 3800
Wire Wire Line
	8750 3800 8750 1750
Wire Wire Line
	8750 1750 7950 1750
Wire Wire Line
	9400 3600 8900 3600
Wire Wire Line
	8900 3600 8900 4600
Wire Wire Line
	8900 4600 6450 4600
Wire Wire Line
	6450 4600 6450 3100
Wire Wire Line
	6450 3100 6750 3100
NoConn ~ 10800 1850
NoConn ~ 10800 2050
NoConn ~ 10800 2250
NoConn ~ 10800 2350
NoConn ~ 10800 2450
NoConn ~ 10800 2550
NoConn ~ 10800 2650
NoConn ~ 10800 2750
NoConn ~ 10800 2850
NoConn ~ 9600 1850
NoConn ~ 9600 2250
NoConn ~ 7750 3500
NoConn ~ 7750 3400
NoConn ~ 7750 2800
NoConn ~ 7750 2600
NoConn ~ 7750 2400
NoConn ~ 4300 2650
NoConn ~ 4300 2750
NoConn ~ 4300 2950
NoConn ~ 4300 4200
NoConn ~ 4300 4300
NoConn ~ 4300 4500
NoConn ~ 7150 2000
Wire Wire Line
	7150 4100 7250 4100
Connection ~ 7150 4100
Wire Wire Line
	7250 4100 7350 4100
Connection ~ 7250 4100
NoConn ~ 6750 2600
NoConn ~ 6750 2700
NoConn ~ 6750 2800
NoConn ~ 6750 2900
NoConn ~ 6750 3000
$Comp
L Device:LED DИгра_Завершена
U 1 1 60806786
P 6350 2150
F 0 "DИгра_Завершена" H 6343 2367 50  0000 C CNN
F 1 "LED" H 6343 2276 50  0000 C CNN
F 2 "" H 6350 2150 50  0001 C CNN
F 3 "~" H 6350 2150 50  0001 C CNN
	1    6350 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	6750 2600 6500 2600
Wire Wire Line
	6500 2600 6500 2150
Wire Wire Line
	6200 2150 6200 4200
Connection ~ 6200 4200
Wire Wire Line
	6200 4200 7150 4200
$EndSCHEMATC
