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
P 2450 3700
F 0 "PSU1" H 2400 4050 50  0000 C CNN
F 1 "AZ-Delivery_AC-03-3_3v3_PSU" H 2400 4150 50  0000 C CNN
F 2 "Elektron_Components_1:AZ-Delivery_AC-03-3_3v3_PSU" H 2450 4100 50  0001 C CNN
F 3 "" H 2450 3700 50  0001 C CNN
	1    2450 3700
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
P 3700 3550
F 0 "#PWR0101" H 3700 3300 50  0001 C CNN
F 1 "GND" H 3705 3377 50  0000 C CNN
F 2 "" H 3700 3550 50  0001 C CNN
F 3 "" H 3700 3550 50  0001 C CNN
	1    3700 3550
	-1   0    0    1   
$EndComp
$Comp
L power:+3V3 #PWR0102
U 1 1 5FCA4B2F
P 3700 3850
F 0 "#PWR0102" H 3700 3700 50  0001 C CNN
F 1 "+3V3" H 3715 4023 50  0000 C CNN
F 2 "" H 3700 3850 50  0001 C CNN
F 3 "" H 3700 3850 50  0001 C CNN
	1    3700 3850
	-1   0    0    1   
$EndComp
Wire Wire Line
	2050 3650 1650 3650
Wire Wire Line
	2050 3750 1650 3750
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
P 1450 3750
F 0 "J1" H 1368 3425 50  0000 C CNN
F 1 "Screw_Terminal_01x02" H 1368 3516 50  0000 C CNN
F 2 "TerminalBlock:TerminalBlock_bornier-2_P5.08mm" H 1450 3750 50  0001 C CNN
F 3 "~" H 1450 3750 50  0001 C CNN
	1    1450 3750
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x08_Female J2
U 1 1 5FCA22B9
P 8600 4800
F 0 "J2" V 8765 4730 50  0000 C CNN
F 1 "Conn_01x08_Female" V 8674 4730 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x08_P2.54mm_Vertical" H 8600 4800 50  0001 C CNN
F 3 "~" H 8600 4800 50  0001 C CNN
	1    8600 4800
	0    -1   -1   0   
$EndComp
$Comp
L power:+3V3 #PWR05
U 1 1 5FCABF66
P 8300 5100
F 0 "#PWR05" H 8300 4950 50  0001 C CNN
F 1 "+3V3" H 8315 5273 50  0000 C CNN
F 2 "" H 8300 5100 50  0001 C CNN
F 3 "" H 8300 5100 50  0001 C CNN
	1    8300 5100
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR07
U 1 1 5FCAC774
P 9000 5100
F 0 "#PWR07" H 9000 4850 50  0001 C CNN
F 1 "GND" H 9005 4927 50  0000 C CNN
F 2 "" H 9000 5100 50  0001 C CNN
F 3 "" H 9000 5100 50  0001 C CNN
	1    9000 5100
	1    0    0    -1  
$EndComp
Text GLabel 8400 5100 3    50   Input ~ 0
RST
Text GLabel 8500 5100 3    50   Input ~ 0
EN
Text GLabel 8600 5100 3    50   Input ~ 0
TX
Text GLabel 8700 5100 3    50   Input ~ 0
RX
Text GLabel 8800 5100 3    50   Input ~ 0
IO0
Text GLabel 8900 5100 3    50   Input ~ 0
IO2
Wire Wire Line
	8300 5000 8300 5100
Wire Wire Line
	8400 5000 8400 5100
Wire Wire Line
	8500 5000 8500 5100
Wire Wire Line
	8600 5000 8600 5100
Wire Wire Line
	8700 5000 8700 5100
Wire Wire Line
	8800 5000 8800 5100
Wire Wire Line
	8900 5000 8900 5100
Wire Wire Line
	9000 5000 9000 5100
$Comp
L Device:CP C1
U 1 1 5FCB7935
P 3150 3700
F 0 "C1" H 3200 3500 50  0000 R CNN
F 1 "100u" H 3250 3950 50  0000 R CNN
F 2 "Capacitor_THT:CP_Radial_D5.0mm_P2.00mm" H 3188 3550 50  0001 C CNN
F 3 "~" H 3150 3700 50  0001 C CNN
	1    3150 3700
	-1   0    0    1   
$EndComp
$Comp
L Device:C C2
U 1 1 5FCB8A3B
P 3500 3700
F 0 "C2" H 3450 3900 50  0000 L CNN
F 1 "100n" H 3450 3450 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 3538 3550 50  0001 C CNN
F 3 "~" H 3500 3700 50  0001 C CNN
	1    3500 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	3700 3550 3500 3550
Wire Wire Line
	2850 3550 2850 3650
Connection ~ 3150 3550
Wire Wire Line
	3150 3550 2850 3550
Connection ~ 3500 3550
Wire Wire Line
	3500 3550 3150 3550
Wire Wire Line
	2850 3750 2850 3850
Wire Wire Line
	2850 3850 3150 3850
Connection ~ 3150 3850
Wire Wire Line
	3150 3850 3500 3850
Connection ~ 3500 3850
Wire Wire Line
	3500 3850 3700 3850
$Comp
L Elektron_Components_1:433MHz-RF-Tx-Module U2
U 1 1 5FCBD0E5
P 8500 1850
F 0 "U2" H 8678 1896 50  0000 L CNN
F 1 "433MHz-RF-Tx-Module" H 8678 1805 50  0000 L CNN
F 2 "Elektron_Components_1:433MHz-RF-Tx-Module_Horizontal" H 8500 2350 50  0001 C CNN
F 3 "" H 8500 2350 50  0001 C CNN
	1    8500 1850
	1    0    0    -1  
$EndComp
$Comp
L Elektron_Components_1:433MHz-RF-Rx-Module U3
U 1 1 5FCBEB87
P 8500 2450
F 0 "U3" H 8678 2501 50  0000 L CNN
F 1 "433MHz-RF-Rx-Module" H 8678 2410 50  0000 L CNN
F 2 "Elektron_Components_1:433MHz-RF-Rx-Module_Vertical" H 8500 2700 50  0001 C CNN
F 3 "" H 8500 2700 50  0001 C CNN
	1    8500 2450
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR01
U 1 1 5FCBFBEB
P 8000 1850
F 0 "#PWR01" H 8000 1700 50  0001 C CNN
F 1 "+3V3" H 8015 2023 50  0000 C CNN
F 2 "" H 8000 1850 50  0001 C CNN
F 3 "" H 8000 1850 50  0001 C CNN
	1    8000 1850
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR02
U 1 1 5FCC0ADD
P 8000 1950
F 0 "#PWR02" H 8000 1700 50  0001 C CNN
F 1 "GND" H 8005 1777 50  0000 C CNN
F 2 "" H 8000 1950 50  0001 C CNN
F 3 "" H 8000 1950 50  0001 C CNN
	1    8000 1950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR04
U 1 1 5FCC11E2
P 8000 2600
F 0 "#PWR04" H 8000 2350 50  0001 C CNN
F 1 "GND" H 8005 2427 50  0000 C CNN
F 2 "" H 8000 2600 50  0001 C CNN
F 3 "" H 8000 2600 50  0001 C CNN
	1    8000 2600
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR03
U 1 1 5FCC15FD
P 8000 2300
F 0 "#PWR03" H 8000 2150 50  0001 C CNN
F 1 "+3V3" H 8015 2473 50  0000 C CNN
F 2 "" H 8000 2300 50  0001 C CNN
F 3 "" H 8000 2300 50  0001 C CNN
	1    8000 2300
	0    -1   -1   0   
$EndComp
Text GLabel 8200 1750 0    50   Input ~ 0
IO2
Text GLabel 8150 2450 0    50   Input ~ 0
IO0
Wire Wire Line
	8300 2400 8250 2400
Wire Wire Line
	8250 2400 8250 2450
Wire Wire Line
	8250 2500 8300 2500
Wire Wire Line
	8150 2450 8250 2450
Connection ~ 8250 2450
Wire Wire Line
	8250 2450 8250 2500
Wire Wire Line
	8200 1750 8300 1750
Wire Wire Line
	8000 1850 8300 1850
Wire Wire Line
	8000 1950 8300 1950
Wire Wire Line
	8000 2600 8300 2600
Wire Wire Line
	8000 2300 8300 2300
$Comp
L Switch:SW_Push SW1
U 1 1 5FCC8368
P 8600 3700
F 0 "SW1" H 8600 3985 50  0000 C CNN
F 1 "SW_Push" H 8600 3894 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm_H5mm" H 8600 3900 50  0001 C CNN
F 3 "~" H 8600 3900 50  0001 C CNN
	1    8600 3700
	1    0    0    -1  
$EndComp
Text GLabel 8200 3700 0    50   Input ~ 0
RST
$Comp
L Device:C C3
U 1 1 5FCC8B2D
P 8300 3850
F 0 "C3" H 8250 4050 50  0000 L CNN
F 1 "100n" H 8250 3600 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 8338 3700 50  0001 C CNN
F 3 "~" H 8300 3850 50  0001 C CNN
	1    8300 3850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR06
U 1 1 5FCC94D2
P 8950 3700
F 0 "#PWR06" H 8950 3450 50  0001 C CNN
F 1 "GND" H 8955 3527 50  0000 C CNN
F 2 "" H 8950 3700 50  0001 C CNN
F 3 "" H 8950 3700 50  0001 C CNN
	1    8950 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	8950 3700 8800 3700
Wire Wire Line
	8200 3700 8300 3700
Connection ~ 8300 3700
Wire Wire Line
	8300 3700 8400 3700
$Comp
L power:GND #PWR0103
U 1 1 5FCECDE5
P 8300 4200
F 0 "#PWR0103" H 8300 3950 50  0001 C CNN
F 1 "GND" H 8305 4027 50  0000 C CNN
F 2 "" H 8300 4200 50  0001 C CNN
F 3 "" H 8300 4200 50  0001 C CNN
	1    8300 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	8300 4000 8300 4200
$EndSCHEMATC
