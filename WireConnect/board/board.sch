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
L MCU_Module:Arduino_Nano_Every A?
U 1 1 605DDF46
P 2100 3350
F 0 "A?" V 2146 2306 50  0000 R CNN
F 1 "Arduino_Nano_Every" V 2055 2306 50  0000 R CNN
F 2 "Module:Arduino_Nano" H 2100 3350 50  0001 C CIN
F 3 "https://content.arduino.cc/assets/NANOEveryV3.0_sch.pdf" H 2100 3350 50  0001 C CNN
	1    2100 3350
	0    -1   -1   0   
$EndComp
$Comp
L 74xx:74HC595 U?
U 1 1 605E5CF2
P 4750 2500
F 0 "U?" H 4750 3281 50  0000 C CNN
F 1 "74HC595" H 4750 3190 50  0000 C CNN
F 2 "" H 4750 2500 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74hc595.pdf" H 4750 2500 50  0001 C CNN
	1    4750 2500
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC595 U?
U 1 1 605E91AA
P 4750 4050
F 0 "U?" H 4750 4831 50  0000 C CNN
F 1 "74HC595" H 4750 4740 50  0000 C CNN
F 2 "" H 4750 4050 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74hc595.pdf" H 4750 4050 50  0001 C CNN
	1    4750 4050
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 605E937C
P 1200 5050
F 0 "#PWR?" H 1200 4900 50  0001 C CNN
F 1 "+5V" H 1215 5223 50  0000 C CNN
F 2 "" H 1200 5050 50  0001 C CNN
F 3 "" H 1200 5050 50  0001 C CNN
	1    1200 5050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 605EAECC
P 1200 5200
F 0 "#PWR?" H 1200 4950 50  0001 C CNN
F 1 "GND" H 1205 5027 50  0000 C CNN
F 2 "" H 1200 5200 50  0001 C CNN
F 3 "" H 1200 5200 50  0001 C CNN
	1    1200 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	1200 5050 1000 5050
Wire Wire Line
	1000 5050 1000 3450
Wire Wire Line
	1000 3450 1100 3450
Wire Wire Line
	1200 5050 1750 5050
Wire Wire Line
	3200 5050 3200 3450
Wire Wire Line
	3200 3450 4150 3450
Connection ~ 1200 5050
Wire Wire Line
	3200 3450 3200 1900
Wire Wire Line
	3200 1900 4100 1900
Connection ~ 3200 3450
Wire Wire Line
	1200 5200 950  5200
Wire Wire Line
	950  5200 950  2750
Wire Wire Line
	950  2750 3100 2750
Wire Wire Line
	3100 2750 3100 3350
Wire Wire Line
	1200 5200 1350 5200
Wire Wire Line
	4750 5200 4750 4800
Connection ~ 1200 5200
Wire Wire Line
	4100 5200 4100 3200
Wire Wire Line
	4100 3200 4350 3200
Connection ~ 4100 5200
Wire Wire Line
	4100 5200 4750 5200
Wire Wire Line
	4350 2700 4350 3200
Connection ~ 4350 3200
Wire Wire Line
	4350 3200 4750 3200
Wire Wire Line
	4350 4250 4350 4800
Wire Wire Line
	4350 4800 4750 4800
Connection ~ 4750 4800
Wire Wire Line
	4750 4800 4750 4750
Wire Wire Line
	4350 2400 4100 2400
Wire Wire Line
	4100 2400 4100 1900
Connection ~ 4100 1900
Wire Wire Line
	4100 1900 4750 1900
Wire Wire Line
	4350 3950 4150 3950
Wire Wire Line
	4150 3950 4150 3450
Connection ~ 4150 3450
Wire Wire Line
	4150 3450 4750 3450
Wire Wire Line
	4350 2100 3450 2100
Wire Wire Line
	3450 2100 3450 3950
Wire Wire Line
	2300 3950 2300 3850
Wire Wire Line
	4350 2300 3400 2300
Wire Wire Line
	3400 2300 3400 3900
Wire Wire Line
	3400 3900 2400 3900
Wire Wire Line
	2400 3900 2400 3850
Wire Wire Line
	4350 2600 3500 2600
Wire Wire Line
	3500 2600 3500 4000
Wire Wire Line
	3500 4000 3450 4000
Wire Wire Line
	2000 4000 2000 3850
Wire Wire Line
	4350 3650 3550 3650
Wire Wire Line
	3550 3650 3550 4050
Wire Wire Line
	3550 4050 2100 4050
Wire Wire Line
	2100 4050 2100 3850
Wire Wire Line
	3450 3950 2300 3950
Wire Wire Line
	4350 4150 3450 4150
Wire Wire Line
	3450 4150 3450 4000
Connection ~ 3450 4000
Wire Wire Line
	3450 4000 2000 4000
Wire Wire Line
	4350 3850 3600 3850
Wire Wire Line
	3600 3850 3600 4100
Wire Wire Line
	3600 4100 2200 4100
Wire Wire Line
	2200 4100 2200 3850
$Comp
L Device:LED_RGBC D?
U 1 1 605F59A6
P 6000 2150
F 0 "D?" H 6000 2647 50  0000 C CNN
F 1 "LED_RGBC" H 6000 2556 50  0000 C CNN
F 2 "" H 6000 2100 50  0001 C CNN
F 3 "~" H 6000 2100 50  0001 C CNN
	1    6000 2150
	-1   0    0    -1  
$EndComp
$Comp
L Device:LED_RGBC D?
U 1 1 605F9CC7
P 6000 3000
F 0 "D?" H 6000 3497 50  0000 C CNN
F 1 "LED_RGBC" H 6000 3406 50  0000 C CNN
F 2 "" H 6000 2950 50  0001 C CNN
F 3 "~" H 6000 2950 50  0001 C CNN
	1    6000 3000
	-1   0    0    -1  
$EndComp
$Comp
L Device:LED_RGBC D?
U 1 1 605FB1B9
P 6000 3850
F 0 "D?" H 6000 4347 50  0000 C CNN
F 1 "LED_RGBC" H 6000 4256 50  0000 C CNN
F 2 "" H 6000 3800 50  0001 C CNN
F 3 "~" H 6000 3800 50  0001 C CNN
	1    6000 3850
	-1   0    0    -1  
$EndComp
$Comp
L Device:LED_RGBC D?
U 1 1 605FC75C
P 6000 4750
F 0 "D?" H 6000 5247 50  0000 C CNN
F 1 "LED_RGBC" H 6000 5156 50  0000 C CNN
F 2 "" H 6000 4700 50  0001 C CNN
F 3 "~" H 6000 4700 50  0001 C CNN
	1    6000 4750
	-1   0    0    -1  
$EndComp
Wire Wire Line
	5150 2100 5400 2100
Wire Wire Line
	5400 2100 5400 1950
Wire Wire Line
	5400 1950 5800 1950
Wire Wire Line
	5150 2200 5450 2200
Wire Wire Line
	5450 2200 5450 2150
Wire Wire Line
	5450 2150 5800 2150
Wire Wire Line
	5150 2300 5800 2300
Wire Wire Line
	5800 2300 5800 2350
Wire Wire Line
	5150 2400 5750 2400
Wire Wire Line
	5750 2400 5750 2800
Wire Wire Line
	5750 2800 5800 2800
Wire Wire Line
	5150 2500 5700 2500
Wire Wire Line
	5700 2500 5700 3000
Wire Wire Line
	5700 3000 5800 3000
Wire Wire Line
	5150 2600 5650 2600
Wire Wire Line
	5650 2600 5650 3200
Wire Wire Line
	5650 3200 5800 3200
Wire Wire Line
	5150 3650 5800 3650
Wire Wire Line
	5150 3750 5800 3750
Wire Wire Line
	5800 3750 5800 3850
Wire Wire Line
	5150 3850 5750 3850
Wire Wire Line
	5750 3850 5750 4050
Wire Wire Line
	5750 4050 5800 4050
Wire Wire Line
	5150 3950 5700 3950
Wire Wire Line
	5700 3950 5700 4550
Wire Wire Line
	5700 4550 5800 4550
Wire Wire Line
	5150 4050 5650 4050
Wire Wire Line
	5650 4050 5650 4750
Wire Wire Line
	5650 4750 5800 4750
Wire Wire Line
	5150 4150 5600 4150
Wire Wire Line
	5600 4150 5600 4950
Wire Wire Line
	5600 4950 5800 4950
$Comp
L Connector:Conn_01x01_Female J?
U 1 1 6060D925
P 7400 2150
F 0 "J?" H 7428 2176 50  0000 L CNN
F 1 "Conn_01x01_Female" H 7428 2085 50  0000 L CNN
F 2 "" H 7400 2150 50  0001 C CNN
F 3 "~" H 7400 2150 50  0001 C CNN
	1    7400 2150
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female J?
U 1 1 6060EFDE
P 7450 3000
F 0 "J?" H 7478 3026 50  0000 L CNN
F 1 "Conn_01x01_Female" H 7478 2935 50  0000 L CNN
F 2 "" H 7450 3000 50  0001 C CNN
F 3 "~" H 7450 3000 50  0001 C CNN
	1    7450 3000
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female J?
U 1 1 60610D16
P 7450 3850
F 0 "J?" H 7478 3876 50  0000 L CNN
F 1 "Conn_01x01_Female" H 7478 3785 50  0000 L CNN
F 2 "" H 7450 3850 50  0001 C CNN
F 3 "~" H 7450 3850 50  0001 C CNN
	1    7450 3850
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female J?
U 1 1 606128E1
P 7450 4750
F 0 "J?" H 7478 4776 50  0000 L CNN
F 1 "Conn_01x01_Female" H 7478 4685 50  0000 L CNN
F 2 "" H 7450 4750 50  0001 C CNN
F 3 "~" H 7450 4750 50  0001 C CNN
	1    7450 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	6200 2150 6200 2450
Wire Wire Line
	6200 3000 6200 3300
Connection ~ 6200 3000
Wire Wire Line
	6200 3850 6200 4150
Connection ~ 6200 3850
Wire Wire Line
	6200 4750 6200 5050
Wire Wire Line
	6200 5200 4750 5200
Connection ~ 6200 4750
Connection ~ 4750 5200
$Comp
L Device:R R10000
U 1 1 60620084
P 6550 2300
F 0 "R10000" H 6620 2346 50  0000 L CNN
F 1 "R" H 6620 2255 50  0000 L CNN
F 2 "" V 6480 2300 50  0001 C CNN
F 3 "~" H 6550 2300 50  0001 C CNN
	1    6550 2300
	1    0    0    -1  
$EndComp
$Comp
L Device:R R10000
U 1 1 606210AA
P 6600 3150
F 0 "R10000" H 6670 3196 50  0000 L CNN
F 1 "R" H 6670 3105 50  0000 L CNN
F 2 "" V 6530 3150 50  0001 C CNN
F 3 "~" H 6600 3150 50  0001 C CNN
	1    6600 3150
	1    0    0    -1  
$EndComp
$Comp
L Device:R R10000
U 1 1 60624F1B
P 6650 4000
F 0 "R10000" H 6720 4046 50  0000 L CNN
F 1 "R" H 6720 3955 50  0000 L CNN
F 2 "" V 6580 4000 50  0001 C CNN
F 3 "~" H 6650 4000 50  0001 C CNN
	1    6650 4000
	1    0    0    -1  
$EndComp
$Comp
L Device:R R10000
U 1 1 60626E07
P 6700 4900
F 0 "R10000" H 6770 4946 50  0000 L CNN
F 1 "R" H 6770 4855 50  0000 L CNN
F 2 "" V 6630 4900 50  0001 C CNN
F 3 "~" H 6700 4900 50  0001 C CNN
	1    6700 4900
	1    0    0    -1  
$EndComp
Wire Wire Line
	7200 2150 6900 2150
Wire Wire Line
	7250 3000 6850 3000
Wire Wire Line
	7250 4750 6750 4750
Wire Wire Line
	6550 2450 6200 2450
Connection ~ 6200 2450
Wire Wire Line
	6200 2450 6200 3000
Wire Wire Line
	6600 3300 6200 3300
Connection ~ 6200 3300
Wire Wire Line
	6200 3300 6200 3850
Wire Wire Line
	6650 4150 6200 4150
Connection ~ 6200 4150
Wire Wire Line
	6200 4150 6200 4750
Wire Wire Line
	6700 5050 6200 5050
Connection ~ 6200 5050
Wire Wire Line
	6200 5050 6200 5200
Wire Wire Line
	7250 3850 6800 3850
Wire Wire Line
	2400 2850 2400 1550
Wire Wire Line
	2400 1550 6750 1550
Wire Wire Line
	6750 1550 6750 4750
Connection ~ 6750 4750
Wire Wire Line
	6750 4750 6700 4750
Wire Wire Line
	6800 3850 6800 1500
Wire Wire Line
	6800 1500 2300 1500
Wire Wire Line
	2300 1500 2300 2850
Connection ~ 6800 3850
Wire Wire Line
	6800 3850 6650 3850
Wire Wire Line
	2200 2850 2200 1450
Wire Wire Line
	2200 1450 6850 1450
Wire Wire Line
	6850 1450 6850 3000
Connection ~ 6850 3000
Wire Wire Line
	6850 3000 6600 3000
Wire Wire Line
	6900 2150 6900 1400
Wire Wire Line
	6900 1400 2100 1400
Wire Wire Line
	2100 1400 2100 2850
Connection ~ 6900 2150
Wire Wire Line
	6900 2150 6550 2150
$Comp
L Device:LED D?
U 1 1 606A3EE8
P 2050 5550
F 0 "D?" H 2043 5767 50  0000 C CNN
F 1 "LED_R" H 2043 5676 50  0000 C CNN
F 2 "" H 2050 5550 50  0001 C CNN
F 3 "~" H 2050 5550 50  0001 C CNN
	1    2050 5550
	-1   0    0    -1  
$EndComp
$Comp
L Device:LED D?
U 1 1 606A8690
P 2050 5950
F 0 "D?" H 2043 6167 50  0000 C CNN
F 1 "LED_G" H 2043 6076 50  0000 C CNN
F 2 "" H 2050 5950 50  0001 C CNN
F 3 "~" H 2050 5950 50  0001 C CNN
	1    2050 5950
	-1   0    0    -1  
$EndComp
$Comp
L Device:LED D?
U 1 1 606ABDDD
P 2050 6350
F 0 "D?" H 2043 6567 50  0000 C CNN
F 1 "LED_B" H 2043 6476 50  0000 C CNN
F 2 "" H 2050 6350 50  0001 C CNN
F 3 "~" H 2050 6350 50  0001 C CNN
	1    2050 6350
	-1   0    0    -1  
$EndComp
$Comp
L Device:LED D?
U 1 1 606AF436
P 2050 6700
F 0 "D?" H 2043 6917 50  0000 C CNN
F 1 "LED_P" H 2043 6826 50  0000 C CNN
F 2 "" H 2050 6700 50  0001 C CNN
F 3 "~" H 2050 6700 50  0001 C CNN
	1    2050 6700
	-1   0    0    -1  
$EndComp
Wire Wire Line
	1750 5050 1750 5550
Wire Wire Line
	1750 6700 1900 6700
Connection ~ 1750 5050
Wire Wire Line
	1750 5050 2450 5050
Wire Wire Line
	1750 6350 1900 6350
Connection ~ 1750 6350
Wire Wire Line
	1750 6350 1750 6700
Wire Wire Line
	1900 5950 1750 5950
Connection ~ 1750 5950
Wire Wire Line
	1750 5950 1750 6350
Wire Wire Line
	1750 5550 1900 5550
Connection ~ 1750 5550
Wire Wire Line
	1750 5550 1750 5950
Wire Wire Line
	2200 5550 2300 5550
Wire Wire Line
	2300 5550 2300 5200
Connection ~ 2300 5200
Wire Wire Line
	2300 5200 4100 5200
Wire Wire Line
	2300 5550 2300 5950
Wire Wire Line
	2300 6700 2200 6700
Connection ~ 2300 5550
Wire Wire Line
	2200 6350 2300 6350
Connection ~ 2300 6350
Wire Wire Line
	2300 6350 2300 6700
Wire Wire Line
	2200 5950 2300 5950
Connection ~ 2300 5950
Wire Wire Line
	2300 5950 2300 6350
$Comp
L Connector:Conn_01x01_Female J?
U 1 1 606D4271
P 3250 5550
F 0 "J?" H 3278 5576 50  0000 L CNN
F 1 "Conn_01x01_Female" H 3278 5485 50  0000 L CNN
F 2 "" H 3250 5550 50  0001 C CNN
F 3 "~" H 3250 5550 50  0001 C CNN
	1    3250 5550
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female J?
U 1 1 606D557D
P 3250 5950
F 0 "J?" H 3278 5976 50  0000 L CNN
F 1 "Conn_01x01_Female" H 3278 5885 50  0000 L CNN
F 2 "" H 3250 5950 50  0001 C CNN
F 3 "~" H 3250 5950 50  0001 C CNN
	1    3250 5950
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female J?
U 1 1 606DA380
P 3250 6350
F 0 "J?" H 3278 6376 50  0000 L CNN
F 1 "Conn_01x01_Female" H 3278 6285 50  0000 L CNN
F 2 "" H 3250 6350 50  0001 C CNN
F 3 "~" H 3250 6350 50  0001 C CNN
	1    3250 6350
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female J?
U 1 1 606DF1D4
P 3250 6700
F 0 "J?" H 3278 6726 50  0000 L CNN
F 1 "Conn_01x01_Female" H 3278 6635 50  0000 L CNN
F 2 "" H 3250 6700 50  0001 C CNN
F 3 "~" H 3250 6700 50  0001 C CNN
	1    3250 6700
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1000
U 1 1 606E3D41
P 2800 5950
F 0 "R1000" V 2593 5950 50  0000 C CNN
F 1 "R" V 2684 5950 50  0000 C CNN
F 2 "" V 2730 5950 50  0001 C CNN
F 3 "~" H 2800 5950 50  0001 C CNN
	1    2800 5950
	0    1    1    0   
$EndComp
$Comp
L Device:R R10000
U 1 1 606EF199
P 2800 6350
F 0 "R10000" V 2593 6350 50  0000 C CNN
F 1 "R" V 2684 6350 50  0000 C CNN
F 2 "" V 2730 6350 50  0001 C CNN
F 3 "~" H 2800 6350 50  0001 C CNN
	1    2800 6350
	0    1    1    0   
$EndComp
$Comp
L Device:R R100000
U 1 1 606F3D1A
P 2800 6700
F 0 "R100000" V 2593 6700 50  0000 C CNN
F 1 "R" V 2684 6700 50  0000 C CNN
F 2 "" V 2730 6700 50  0001 C CNN
F 3 "~" H 2800 6700 50  0001 C CNN
	1    2800 6700
	0    1    1    0   
$EndComp
Wire Wire Line
	2450 5050 2450 5550
Wire Wire Line
	2450 6700 2650 6700
Connection ~ 2450 5050
Wire Wire Line
	2450 5050 3200 5050
Wire Wire Line
	2450 6350 2650 6350
Connection ~ 2450 6350
Wire Wire Line
	2450 6350 2450 6700
Wire Wire Line
	2450 5950 2650 5950
Connection ~ 2450 5950
Wire Wire Line
	2450 5950 2450 6350
Wire Wire Line
	2450 5550 3050 5550
Connection ~ 2450 5550
Wire Wire Line
	2450 5550 2450 5950
Wire Wire Line
	2950 5950 3050 5950
Wire Wire Line
	2950 6350 3050 6350
Wire Wire Line
	2950 6700 3050 6700
$Comp
L Device:LED D?
U 1 1 6071FA36
P 1500 4300
F 0 "D?" H 1493 4517 50  0000 C CNN
F 1 "LED_Done" H 1493 4426 50  0000 C CNN
F 2 "" H 1500 4300 50  0001 C CNN
F 3 "~" H 1500 4300 50  0001 C CNN
	1    1500 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	1600 3850 1600 4000
Wire Wire Line
	1600 4000 1650 4000
Wire Wire Line
	1650 4000 1650 4300
Wire Wire Line
	1350 4300 1350 5200
Connection ~ 1350 5200
Wire Wire Line
	1350 5200 2300 5200
$EndSCHEMATC
