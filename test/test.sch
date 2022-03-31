EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Motor control"
Date "2022-03-30"
Rev "v01"
Comp ""
Comment1 "Author: Leehaney George"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector:Conn_01x03_Female J3
U 1 1 62450CE1
P 2100 5450
F 0 "J3" H 2128 5476 50  0000 L CNN
F 1 "Motor_driver" H 2128 5385 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x03_P2.54mm_Vertical" H 2100 5450 50  0001 C CNN
F 3 "~" H 2100 5450 50  0001 C CNN
	1    2100 5450
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x04_Female J2
U 1 1 6245177A
P 2250 4150
F 0 "J2" H 2278 4126 50  0000 L CNN
F 1 "ENCODER" H 2278 4035 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x04_P2.54mm_Vertical" H 2250 4150 50  0001 C CNN
F 3 "~" H 2250 4150 50  0001 C CNN
	1    2250 4150
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x04_Female J1
U 1 1 62452045
P 2350 3400
F 0 "J1" H 2378 3376 50  0000 L CNN
F 1 "POWER" H 2378 3285 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x04_P2.54mm_Vertical" H 2350 3400 50  0001 C CNN
F 3 "~" H 2350 3400 50  0001 C CNN
	1    2350 3400
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x02_Female J10
U 1 1 624528E7
P 7350 1400
F 0 "J10" H 7378 1376 50  0000 L CNN
F 1 "12V_SOURCE" H 7378 1285 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x02_P2.54mm_Vertical" H 7350 1400 50  0001 C CNN
F 3 "~" H 7350 1400 50  0001 C CNN
	1    7350 1400
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x20_Female J5
U 1 1 62457CBB
P 3900 4750
F 0 "J5" H 3928 4726 50  0000 L CNN
F 1 "left_stm32" H 3928 4635 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x20_P2.54mm_Vertical" H 3900 4750 50  0001 C CNN
F 3 "~" H 3900 4750 50  0001 C CNN
	1    3900 4750
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x20_Female J7
U 1 1 62459176
P 5000 4850
F 0 "J7" H 4892 3625 50  0000 C CNN
F 1 "right_stm32" H 4892 3716 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x20_P2.54mm_Vertical" H 5000 4850 50  0001 C CNN
F 3 "~" H 5000 4850 50  0001 C CNN
	1    5000 4850
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x15_Female J4
U 1 1 6245BAAB
P 3550 1650
F 0 "J4" H 3578 1676 50  0000 L CNN
F 1 "Left_esp32" H 3578 1585 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x15_P2.54mm_Vertical" H 3550 1650 50  0001 C CNN
F 3 "~" H 3550 1650 50  0001 C CNN
	1    3550 1650
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x15_Female J6
U 1 1 6245DB0C
P 4350 1650
F 0 "J6" H 4242 725 50  0000 C CNN
F 1 "Right_esp32" H 4242 816 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x15_P2.54mm_Vertical" H 4350 1650 50  0001 C CNN
F 3 "~" H 4350 1650 50  0001 C CNN
	1    4350 1650
	-1   0    0    1   
$EndComp
Text Label 4550 950  0    50   ~ 0
5V
Text Label 4550 1050 0    50   ~ 0
GND
NoConn ~ 4550 1150
NoConn ~ 4550 1250
NoConn ~ 4550 1350
NoConn ~ 4550 1450
NoConn ~ 4550 1550
NoConn ~ 4550 1650
NoConn ~ 4550 1750
NoConn ~ 4550 1850
NoConn ~ 4550 1950
NoConn ~ 4550 2050
NoConn ~ 4550 2150
NoConn ~ 4550 2250
NoConn ~ 3350 950 
NoConn ~ 3350 1050
NoConn ~ 3350 1150
NoConn ~ 3350 1250
NoConn ~ 3350 1350
NoConn ~ 3350 1650
NoConn ~ 3350 1750
NoConn ~ 3350 1850
NoConn ~ 3350 1950
NoConn ~ 3350 2050
NoConn ~ 3350 2150
NoConn ~ 3350 2250
NoConn ~ 3350 2350
NoConn ~ 4550 2350
Text Label 7450 4800 0    50   ~ 0
curr_sig
Text Label 7450 4900 0    50   ~ 0
GND
Text Label 1900 5450 2    50   ~ 0
IN1
Text Label 1900 5550 2    50   ~ 0
IN2
Text Label 2050 4050 2    50   ~ 0
5V
Text Label 2050 4150 2    50   ~ 0
GND
Text Label 2050 4250 2    50   ~ 0
ENA
Text Label 2050 4350 2    50   ~ 0
ENB
$Comp
L Connector:Barrel_Jack J8
U 1 1 6246A8AF
P 7200 1000
F 0 "J8" H 7257 1325 50  0000 C CNN
F 1 "Barrel_Jack" H 7257 1234 50  0000 C CNN
F 2 "Connector_BarrelJack:BarrelJack_Wuerth_6941xx301002" H 7250 960 50  0001 C CNN
F 3 "~" H 7250 960 50  0001 C CNN
	1    7200 1000
	1    0    0    -1  
$EndComp
Text Label 7500 900  0    50   ~ 0
12V
Text Label 7150 1400 2    50   ~ 0
12V
Text Label 7150 1500 2    50   ~ 0
GND
Text Label 2150 3300 2    50   ~ 0
5V
Text Label 2150 3400 2    50   ~ 0
5V
Text Label 2150 3500 2    50   ~ 0
GND
Text Label 2150 3600 2    50   ~ 0
GND
Text Label 3350 1550 2    50   ~ 0
WIFI_TX
Wire Notes Line
	3000 700  4800 700 
Wire Notes Line
	5650 6050 5650 3500
Wire Notes Line
	5650 3500 3450 3500
Wire Notes Line
	3450 3500 3450 6050
Wire Notes Line
	3450 6050 5650 6050
$Comp
L Connector:Conn_01x03_Female J9
U 1 1 6245009E
P 7250 4800
F 0 "J9" H 7142 4475 50  0000 C CNN
F 1 "current_sensor" H 7142 4566 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x03_P2.54mm_Vertical" H 7250 4800 50  0001 C CNN
F 3 "~" H 7250 4800 50  0001 C CNN
	1    7250 4800
	-1   0    0    1   
$EndComp
Text Label 7450 4700 0    50   ~ 0
5V
Text Label 3700 5650 2    50   ~ 0
GND
Text Label 3700 5550 2    50   ~ 0
5V
NoConn ~ 3700 5750
Text Label 3700 5450 2    50   ~ 0
PB9
Text Label 3700 5350 2    50   ~ 0
PB8
Text Label 3700 5250 2    50   ~ 0
PB7
Text Label 3700 5150 2    50   ~ 0
PB6
Text Label 3700 5050 2    50   ~ 0
PB5
NoConn ~ 3700 4950
NoConn ~ 3700 4850
NoConn ~ 3700 4750
NoConn ~ 3700 4650
NoConn ~ 3700 4550
NoConn ~ 3700 4450
NoConn ~ 3700 4350
NoConn ~ 3700 4250
NoConn ~ 3700 4150
NoConn ~ 3700 4050
NoConn ~ 3700 3950
NoConn ~ 3700 3850
NoConn ~ 5200 5750
NoConn ~ 5200 5650
NoConn ~ 5200 5550
NoConn ~ 5200 5450
NoConn ~ 5200 5350
NoConn ~ 5200 5250
NoConn ~ 5200 5050
NoConn ~ 5200 4750
NoConn ~ 5200 4650
NoConn ~ 5200 4550
NoConn ~ 5200 4450
NoConn ~ 5200 4350
NoConn ~ 5200 4250
NoConn ~ 5200 4150
NoConn ~ 5200 4050
NoConn ~ 5200 3950
NoConn ~ 5200 3850
Text Label 1900 5800 2    50   ~ 0
IN1
Text Label 1900 5900 2    50   ~ 0
IN2
Text Label 2050 5700 0    50   ~ 0
PB7
Text Label 2050 5800 0    50   ~ 0
PB8
Text Label 2050 5900 0    50   ~ 0
PB9
Wire Wire Line
	1900 5900 2050 5900
Wire Wire Line
	1900 5800 2050 5800
Wire Wire Line
	1900 5700 2050 5700
Wire Notes Line
	1700 5200 2650 5200
Wire Notes Line
	2650 5200 2650 6200
Wire Notes Line
	2650 6200 1700 6200
Wire Notes Line
	1700 6200 1700 5200
Text Label 1900 5350 2    50   ~ 0
ENAB
Text Label 1900 5700 2    50   ~ 0
ENAB
Text Label 2050 4500 2    50   ~ 0
ENA
Text Label 2050 4600 2    50   ~ 0
ENB
Text Label 2250 4500 0    50   ~ 0
PB5
Text Label 2250 4600 0    50   ~ 0
PB6
Wire Wire Line
	2050 4600 2250 4600
Wire Wire Line
	2050 4500 2250 4500
Wire Notes Line
	2650 3950 1800 3950
Wire Notes Line
	1800 3950 1800 4800
Wire Notes Line
	1800 4800 2650 4800
Wire Notes Line
	2650 3950 2650 4800
Wire Notes Line
	1850 3100 1850 3850
Wire Notes Line
	1850 3850 2650 3850
Wire Notes Line
	2650 3850 2650 3100
Wire Notes Line
	2650 3100 1850 3100
Text Label 5200 5150 0    50   ~ 0
A0
Text Label 7250 5050 2    50   ~ 0
A0
Text Label 7450 5050 0    50   ~ 0
curr_sig
Wire Wire Line
	7450 5050 7250 5050
Wire Notes Line
	7000 5300 7850 5300
Wire Notes Line
	7850 5300 7850 4400
Wire Notes Line
	7850 4400 7000 4400
Wire Notes Line
	7000 4400 7000 5300
Text Label 3650 2600 2    50   ~ 0
WIFI_RX
Text Label 5200 4950 0    50   ~ 0
A2
Text Label 5200 4850 0    50   ~ 0
A3
Text Label 3900 2600 0    50   ~ 0
A2
Wire Wire Line
	3900 2600 3650 2600
Text Label 3350 1450 2    50   ~ 0
WIFI_RX
Text Notes 4100 5950 0    50   ~ 10
STM32F411CU6\n
Text Notes 5350 4950 0    50   ~ 0
TX\n
Text Notes 5350 4850 0    50   ~ 0
RX\n
Text Label 3650 2750 2    50   ~ 0
WIFI_TX
Text Label 3900 2750 0    50   ~ 0
A3
Wire Wire Line
	3650 2750 3900 2750
Wire Notes Line
	3000 2800 4800 2800
Wire Notes Line
	4800 700  4800 2800
Wire Notes Line
	3000 700  3000 2800
Text Notes 3550 650  0    50   ~ 10
ESP32-WROOM-32
Text Notes 1900 6150 0    50   ~ 10
MOTOR_DRIVER\n
Text Notes 2000 4750 0    50   ~ 10
ENCODER
Text Notes 2000 3800 0    50   ~ 10
POWER_SUPPLY
Text Notes 7100 5250 0    50   ~ 10
CURRENT_SENSOR\n
Wire Notes Line
	6850 600  6850 1950
Wire Notes Line
	6850 1950 7950 1950
Wire Notes Line
	7950 1950 7950 600 
Wire Notes Line
	7950 600  6850 600 
Text Notes 7100 1800 0    50   ~ 10
12V_SUPPLY
Text Label 7500 1100 0    50   ~ 0
GND
$EndSCHEMATC
