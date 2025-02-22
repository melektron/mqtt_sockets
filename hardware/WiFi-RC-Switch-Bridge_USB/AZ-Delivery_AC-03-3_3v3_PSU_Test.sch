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
L Elektron_Components_1:AZ-Delivery_AC-03-3_3v3_PSU PSU1
U 1 1 5FCA0A99
P 3850 3700
F 0 "PSU1" H 3800 4050 50  0000 C CNN
F 1 "AZ-Delivery_AC-03-3_3v3_PSU" H 3800 4150 50  0000 C CNN
F 2 "Elektron_Components_1:AZ-Delivery_AC-03-3_3v3_PSU" H 3850 4100 50  0001 C CNN
F 3 "" H 3850 3700 50  0001 C CNN
	1    3850 3700
	1    0    0    -1  
$EndComp
$Comp
L Elektron_Components_1:ESP8266_ESP01 U1
U 1 1 5FCA1DDF
P 6100 3700
F 0 "U1" H 6100 4115 50  0000 C CNN
F 1 "ESP8266_ESP01" H 6100 4024 50  0000 C CNN
F 2 "Elektron_Components_1:ESP8266_ESP01" H 6100 4300 50  0001 C CNN
F 3 "" H 5700 4250 50  0001 C CNN
	1    6100 3700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 5FCA3029
P 4450 3550
F 0 "#PWR0101" H 4450 3300 50  0001 C CNN
F 1 "GND" H 4455 3377 50  0000 C CNN
F 2 "" H 4450 3550 50  0001 C CNN
F 3 "" H 4450 3550 50  0001 C CNN
	1    4450 3550
	-1   0    0    1   
$EndComp
$Comp
L power:+3V3 #PWR0102
U 1 1 5FCA4B2F
P 4450 3850
F 0 "#PWR0102" H 4450 3700 50  0001 C CNN
F 1 "+3V3" H 4465 4023 50  0000 C CNN
F 2 "" H 4450 3850 50  0001 C CNN
F 3 "" H 4450 3850 50  0001 C CNN
	1    4450 3850
	-1   0    0    1   
$EndComp
Wire Wire Line
	4250 3650 4450 3650
Wire Wire Line
	4450 3650 4450 3550
Wire Wire Line
	4250 3750 4450 3750
Wire Wire Line
	4450 3750 4450 3850
Wire Wire Line
	3450 3650 3050 3650
Wire Wire Line
	3450 3750 3050 3750
$Comp
L power:+3V3 #PWR0105
U 1 1 5FCA9835
P 6550 3450
F 0 "#PWR0105" H 6550 3300 50  0001 C CNN
F 1 "+3V3" H 6565 3623 50  0000 C CNN
F 2 "" H 6550 3450 50  0001 C CNN
F 3 "" H 6550 3450 50  0001 C CNN
	1    6550 3450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0106
U 1 1 5FCAA6A2
P 5650 3950
F 0 "#PWR0106" H 5650 3700 50  0001 C CNN
F 1 "GND" H 5655 3777 50  0000 C CNN
F 2 "" H 5650 3950 50  0001 C CNN
F 3 "" H 5650 3950 50  0001 C CNN
	1    5650 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	6400 3550 6550 3550
Wire Wire Line
	6550 3550 6550 3450
Wire Wire Line
	5800 3850 5650 3850
Wire Wire Line
	5650 3850 5650 3950
$Comp
L Device:R R3
U 1 1 5FCAC133
P 7050 3650
F 0 "R3" V 6843 3650 50  0000 C CNN
F 1 "R" V 6934 3650 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 6980 3650 50  0001 C CNN
F 3 "~" H 7050 3650 50  0001 C CNN
	1    7050 3650
	0    1    1    0   
$EndComp
$Comp
L Device:R R4
U 1 1 5FCACA58
P 7050 3750
F 0 "R4" V 7150 3750 50  0000 C CNN
F 1 "R" V 7250 3750 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 6980 3750 50  0001 C CNN
F 3 "~" H 7050 3750 50  0001 C CNN
	1    7050 3750
	0    1    1    0   
$EndComp
$Comp
L Device:R R1
U 1 1 5FCAF00D
P 5200 3650
F 0 "R1" V 4993 3650 50  0000 C CNN
F 1 "R" V 5084 3650 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 5130 3650 50  0001 C CNN
F 3 "~" H 5200 3650 50  0001 C CNN
	1    5200 3650
	0    1    1    0   
$EndComp
$Comp
L Device:R R2
U 1 1 5FCAF013
P 5200 3750
F 0 "R2" V 5300 3750 50  0000 C CNN
F 1 "R" V 5400 3750 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 5130 3750 50  0001 C CNN
F 3 "~" H 5200 3750 50  0001 C CNN
	1    5200 3750
	0    1    1    0   
$EndComp
Wire Wire Line
	7200 3650 7250 3650
Wire Wire Line
	7250 3650 7250 3750
Wire Wire Line
	7250 3750 7200 3750
Wire Wire Line
	5050 3650 5000 3650
Wire Wire Line
	5000 3650 5000 3750
Wire Wire Line
	5000 3750 5050 3750
$Comp
L power:+3V3 #PWR0107
U 1 1 5FCB073E
P 5000 3500
F 0 "#PWR0107" H 5000 3350 50  0001 C CNN
F 1 "+3V3" H 5015 3673 50  0000 C CNN
F 2 "" H 5000 3500 50  0001 C CNN
F 3 "" H 5000 3500 50  0001 C CNN
	1    5000 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 3500 5000 3650
Connection ~ 5000 3650
$Comp
L power:+3V3 #PWR0108
U 1 1 5FCB165C
P 7250 3500
F 0 "#PWR0108" H 7250 3350 50  0001 C CNN
F 1 "+3V3" H 7265 3673 50  0000 C CNN
F 2 "" H 7250 3500 50  0001 C CNN
F 3 "" H 7250 3500 50  0001 C CNN
	1    7250 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	7250 3500 7250 3650
Connection ~ 7250 3650
Wire Wire Line
	6400 3650 6800 3650
Wire Wire Line
	6400 3750 6800 3750
Wire Wire Line
	5350 3650 5450 3650
Wire Wire Line
	5350 3750 5450 3750
Text GLabel 5450 3850 3    50   Input ~ 0
IO2
Text GLabel 5450 3550 1    50   Input ~ 0
IO0
Text GLabel 6800 3550 1    50   Input ~ 0
RST
Text GLabel 6800 3850 3    50   Input ~ 0
EN
Wire Wire Line
	6800 3550 6800 3650
Connection ~ 6800 3650
Wire Wire Line
	6800 3650 6900 3650
Wire Wire Line
	6800 3750 6800 3850
Connection ~ 6800 3750
Wire Wire Line
	6800 3750 6900 3750
Wire Wire Line
	5450 3750 5450 3850
Connection ~ 5450 3750
Wire Wire Line
	5450 3750 5800 3750
Wire Wire Line
	5450 3550 5450 3650
Connection ~ 5450 3650
Wire Wire Line
	5450 3650 5800 3650
Text GLabel 5650 3500 1    50   Input ~ 0
RX
Text GLabel 6550 3900 3    50   Input ~ 0
TX
Wire Wire Line
	6400 3850 6550 3850
Wire Wire Line
	6550 3850 6550 3900
Wire Wire Line
	5650 3500 5650 3550
Wire Wire Line
	5650 3550 5800 3550
$Comp
L Connector:Screw_Terminal_01x02 J1
U 1 1 5FCBBA49
P 2850 3750
F 0 "J1" H 2768 3425 50  0000 C CNN
F 1 "Screw_Terminal_01x02" H 2768 3516 50  0000 C CNN
F 2 "TerminalBlock:TerminalBlock_bornier-2_P5.08mm" H 2850 3750 50  0001 C CNN
F 3 "~" H 2850 3750 50  0001 C CNN
	1    2850 3750
	-1   0    0    1   
$EndComp
$EndSCHEMATC
