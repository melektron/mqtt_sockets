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
L Interface_USB:CH340G U2
U 1 1 5FD06249
P 5850 3350
F 0 "U2" H 5250 2700 50  0000 C CNN
F 1 "CH340G" H 5250 2800 50  0000 C CNN
F 2 "Package_SO:SOIC-16_3.9x9.9mm_P1.27mm" H 5900 2800 50  0001 L CNN
F 3 "http://www.datasheet5.com/pdf-local-2195953" H 5500 4150 50  0001 C CNN
	1    5850 3350
	1    0    0    -1  
$EndComp
$Comp
L Connector:USB_B_Mini J1
U 1 1 5FD07F34
P 2800 2700
F 0 "J1" H 2857 3167 50  0000 C CNN
F 1 "USB_B_Mini" H 2857 3076 50  0000 C CNN
F 2 "Elektron_Components_1:USB-MiniB_LCSC-C46398" H 2950 2650 50  0001 C CNN
F 3 "~" H 2950 2650 50  0001 C CNN
	1    2800 2700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR01
U 1 1 5FD0CFCB
P 2800 3200
F 0 "#PWR01" H 2800 2950 50  0001 C CNN
F 1 "GND" H 2805 3027 50  0000 C CNN
F 2 "" H 2800 3200 50  0001 C CNN
F 3 "" H 2800 3200 50  0001 C CNN
	1    2800 3200
	1    0    0    -1  
$EndComp
Text GLabel 3200 2700 2    50   Input ~ 0
D+
Text GLabel 3200 2800 2    50   Input ~ 0
D-
Wire Wire Line
	3200 2700 3100 2700
Wire Wire Line
	3200 2800 3100 2800
Text GLabel 5350 3250 0    50   Input ~ 0
D+
Text GLabel 5350 3350 0    50   Input ~ 0
D-
Wire Wire Line
	5350 3250 5450 3250
Wire Wire Line
	5350 3350 5450 3350
$Comp
L Regulator_Linear:AMS1117-3.3 U1
U 1 1 5FD0DE10
P 2950 4250
F 0 "U1" H 2950 4492 50  0000 C CNN
F 1 "AMS1117-3.3" H 2950 4401 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-223-3_TabPin2" H 2950 4450 50  0001 C CNN
F 3 "http://www.advanced-monolithic.com/pdf/ds1117.pdf" H 3050 4000 50  0001 C CNN
	1    2950 4250
	1    0    0    -1  
$EndComp
$Comp
L Device:C C2
U 1 1 5FD11BBB
P 3400 4400
F 0 "C2" H 3515 4446 50  0000 L CNN
F 1 "C" H 3515 4355 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 3438 4250 50  0001 C CNN
F 3 "~" H 3400 4400 50  0001 C CNN
	1    3400 4400
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 5FD122D2
P 2500 4400
F 0 "C1" H 2615 4446 50  0000 L CNN
F 1 "C" H 2615 4355 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 2538 4250 50  0001 C CNN
F 3 "~" H 2500 4400 50  0001 C CNN
	1    2500 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	2650 4250 2500 4250
Wire Wire Line
	3250 4250 3400 4250
Wire Wire Line
	2500 4550 2950 4550
Connection ~ 2950 4550
Wire Wire Line
	2950 4550 3400 4550
Wire Wire Line
	2800 3200 2800 3100
$Comp
L power:GND #PWR02
U 1 1 5FD12E98
P 2950 4650
F 0 "#PWR02" H 2950 4400 50  0001 C CNN
F 1 "GND" H 2955 4477 50  0000 C CNN
F 2 "" H 2950 4650 50  0001 C CNN
F 3 "" H 2950 4650 50  0001 C CNN
	1    2950 4650
	1    0    0    -1  
$EndComp
Wire Wire Line
	2950 4650 2950 4550
Text GLabel 3200 2500 2    50   Input ~ 0
VBUS
Wire Wire Line
	3200 2500 3100 2500
Text GLabel 2350 4250 0    50   Input ~ 0
VBUS
Wire Wire Line
	2350 4250 2500 4250
Connection ~ 2500 4250
$Comp
L power:+3V3 #PWR03
U 1 1 5FD14729
P 3600 4250
F 0 "#PWR03" H 3600 4100 50  0001 C CNN
F 1 "+3V3" H 3615 4423 50  0000 C CNN
F 2 "" H 3600 4250 50  0001 C CNN
F 3 "" H 3600 4250 50  0001 C CNN
	1    3600 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3600 4250 3400 4250
Connection ~ 3400 4250
$Comp
L Connector:Conn_01x08_Male J2
U 1 1 5FCC2D73
P 8400 2750
F 0 "J2" V 8327 2678 50  0000 C CNN
F 1 "Conn_01x08_Male" V 8236 2678 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x08_P2.54mm_Horizontal" H 8400 2750 50  0001 C CNN
F 3 "~" H 8400 2750 50  0001 C CNN
	1    8400 2750
	-1   0    0    1   
$EndComp
$Comp
L power:+3V3 #PWR09
U 1 1 5FCD128E
P 7700 3050
F 0 "#PWR09" H 7700 2900 50  0001 C CNN
F 1 "+3V3" H 7715 3223 50  0000 C CNN
F 2 "" H 7700 3050 50  0001 C CNN
F 3 "" H 7700 3050 50  0001 C CNN
	1    7700 3050
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR07
U 1 1 5FCD234C
P 5850 4050
F 0 "#PWR07" H 5850 3800 50  0001 C CNN
F 1 "GND" H 5855 3877 50  0000 C CNN
F 2 "" H 5850 4050 50  0001 C CNN
F 3 "" H 5850 4050 50  0001 C CNN
	1    5850 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	5850 3950 5850 4050
$Comp
L Device:Crystal Y1
U 1 1 5FCD350E
P 5100 3650
F 0 "Y1" V 5146 3519 50  0000 R CNN
F 1 "12MHz" V 5100 3550 50  0000 R CNN
F 2 "Crystal:Crystal_HC49-4H_Vertical" H 5100 3650 50  0001 C CNN
F 3 "~" H 5100 3650 50  0001 C CNN
	1    5100 3650
	0    -1   -1   0   
$EndComp
$Comp
L Device:C C3
U 1 1 5FCD50F1
P 4800 3500
F 0 "C3" H 4600 3550 50  0000 L CNN
F 1 "C" H 4650 3450 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D3.0mm_W2.0mm_P2.50mm" H 4838 3350 50  0001 C CNN
F 3 "~" H 4800 3500 50  0001 C CNN
	1    4800 3500
	0    1    1    0   
$EndComp
$Comp
L Device:C C4
U 1 1 5FCD5844
P 4800 3800
F 0 "C4" H 4915 3846 50  0000 L CNN
F 1 "C" H 4915 3755 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D3.0mm_W2.0mm_P2.50mm" H 4838 3650 50  0001 C CNN
F 3 "~" H 4800 3800 50  0001 C CNN
	1    4800 3800
	0    1    1    0   
$EndComp
Wire Wire Line
	4650 3500 4600 3500
Wire Wire Line
	4600 3500 4600 3650
Wire Wire Line
	4600 3800 4650 3800
$Comp
L power:GND #PWR04
U 1 1 5FCD5F7D
P 4500 3650
F 0 "#PWR04" H 4500 3400 50  0001 C CNN
F 1 "GND" H 4505 3477 50  0000 C CNN
F 2 "" H 4500 3650 50  0001 C CNN
F 3 "" H 4500 3650 50  0001 C CNN
	1    4500 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 3650 4500 3650
Connection ~ 4600 3650
Wire Wire Line
	4600 3650 4600 3800
Wire Wire Line
	4950 3500 5100 3500
Wire Wire Line
	5450 3500 5450 3550
Connection ~ 5100 3500
Wire Wire Line
	5100 3500 5450 3500
Wire Wire Line
	4950 3800 5100 3800
Wire Wire Line
	5450 3800 5450 3750
Connection ~ 5100 3800
Wire Wire Line
	5100 3800 5450 3800
Wire Wire Line
	8100 3050 8200 3050
$Comp
L power:GND #PWR08
U 1 1 5FCD77A5
P 7700 2350
F 0 "#PWR08" H 7700 2100 50  0001 C CNN
F 1 "GND" V 7600 2300 50  0000 C CNN
F 2 "" H 7700 2350 50  0001 C CNN
F 3 "" H 7700 2350 50  0001 C CNN
	1    7700 2350
	0    1    1    0   
$EndComp
Wire Wire Line
	8100 2350 8200 2350
$Comp
L power:+3V3 #PWR06
U 1 1 5FCD8449
P 5850 2650
F 0 "#PWR06" H 5850 2500 50  0001 C CNN
F 1 "+3V3" H 5865 2823 50  0000 C CNN
F 2 "" H 5850 2650 50  0001 C CNN
F 3 "" H 5850 2650 50  0001 C CNN
	1    5850 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	5850 2650 5850 2750
$Comp
L Device:C C5
U 1 1 5FCD8F12
P 5600 2650
F 0 "C5" H 5400 2700 50  0000 L CNN
F 1 "C" H 5450 2600 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 5638 2500 50  0001 C CNN
F 3 "~" H 5600 2650 50  0001 C CNN
	1    5600 2650
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR05
U 1 1 5FCD96DD
P 5350 2650
F 0 "#PWR05" H 5350 2400 50  0001 C CNN
F 1 "GND" H 5355 2477 50  0000 C CNN
F 2 "" H 5350 2650 50  0001 C CNN
F 3 "" H 5350 2650 50  0001 C CNN
	1    5350 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	5350 2650 5450 2650
Wire Wire Line
	5750 2650 5750 2750
$Comp
L Jumper:SolderJumper_2_Open JP1
U 1 1 5FCDAD31
P 7950 2350
F 0 "JP1" H 8150 2400 50  0000 C CNN
F 1 "SolderJumper_2_Open" H 7950 3050 50  0000 C CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_RoundedPad1.0x1.5mm" H 7950 2350 50  0001 C CNN
F 3 "~" H 7950 2350 50  0001 C CNN
	1    7950 2350
	1    0    0    -1  
$EndComp
$Comp
L Jumper:SolderJumper_2_Open JP2
U 1 1 5FCDB6D6
P 7950 2450
F 0 "JP2" H 8150 2500 50  0000 C CNN
F 1 "SolderJumper_2_Open" H 7950 3200 50  0000 C CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_RoundedPad1.0x1.5mm" H 7950 2450 50  0001 C CNN
F 3 "~" H 7950 2450 50  0001 C CNN
	1    7950 2450
	1    0    0    -1  
$EndComp
$Comp
L Jumper:SolderJumper_2_Open JP3
U 1 1 5FCDB943
P 7950 2550
F 0 "JP3" H 8150 2600 50  0000 C CNN
F 1 "SolderJumper_2_Open" H 7950 3350 50  0000 C CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_RoundedPad1.0x1.5mm" H 7950 2550 50  0001 C CNN
F 3 "~" H 7950 2550 50  0001 C CNN
	1    7950 2550
	1    0    0    -1  
$EndComp
$Comp
L Jumper:SolderJumper_2_Open JP4
U 1 1 5FCDBB0A
P 7950 2650
F 0 "JP4" H 8150 2700 50  0000 C CNN
F 1 "SolderJumper_2_Open" H 7950 3500 50  0000 C CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_RoundedPad1.0x1.5mm" H 7950 2650 50  0001 C CNN
F 3 "~" H 7950 2650 50  0001 C CNN
	1    7950 2650
	1    0    0    -1  
$EndComp
$Comp
L Jumper:SolderJumper_2_Open JP5
U 1 1 5FCDBD38
P 7950 2750
F 0 "JP5" H 8150 2800 50  0000 C CNN
F 1 "SolderJumper_2_Open" H 7950 3650 50  0000 C CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_RoundedPad1.0x1.5mm" H 7950 2750 50  0001 C CNN
F 3 "~" H 7950 2750 50  0001 C CNN
	1    7950 2750
	1    0    0    -1  
$EndComp
$Comp
L Jumper:SolderJumper_2_Open JP6
U 1 1 5FCDC036
P 7950 2850
F 0 "JP6" H 8150 2900 50  0000 C CNN
F 1 "SolderJumper_2_Open" H 7950 3800 50  0000 C CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_RoundedPad1.0x1.5mm" H 7950 2850 50  0001 C CNN
F 3 "~" H 7950 2850 50  0001 C CNN
	1    7950 2850
	1    0    0    -1  
$EndComp
$Comp
L Jumper:SolderJumper_2_Open JP7
U 1 1 5FCDC255
P 7950 2950
F 0 "JP7" H 8150 3000 50  0000 C CNN
F 1 "SolderJumper_2_Open" H 7950 3950 50  0000 C CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_RoundedPad1.0x1.5mm" H 7950 2950 50  0001 C CNN
F 3 "~" H 7950 2950 50  0001 C CNN
	1    7950 2950
	1    0    0    -1  
$EndComp
$Comp
L Jumper:SolderJumper_2_Open JP8
U 1 1 5FCDC465
P 7950 3050
F 0 "JP8" H 8150 3100 50  0000 C CNN
F 1 "SolderJumper_2_Open" H 7950 4100 50  0000 C CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_RoundedPad1.0x1.5mm" H 7950 3050 50  0001 C CNN
F 3 "~" H 7950 3050 50  0001 C CNN
	1    7950 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	8100 2950 8200 2950
Wire Wire Line
	8100 2850 8200 2850
Wire Wire Line
	8100 2750 8200 2750
Wire Wire Line
	8100 2650 8200 2650
Wire Wire Line
	8100 2550 8200 2550
Wire Wire Line
	8100 2450 8200 2450
Wire Wire Line
	7700 3050 7800 3050
Wire Wire Line
	7700 2350 7800 2350
Text GLabel 6350 2950 2    50   Input ~ 0
TX
Text GLabel 6350 3050 2    50   Input ~ 0
RX
Wire Wire Line
	6350 3050 6250 3050
Wire Wire Line
	6350 2950 6250 2950
Text GLabel 6350 3750 2    50   Input ~ 0
RTS
Text GLabel 6350 3650 2    50   Input ~ 0
DTR
Wire Wire Line
	6350 3650 6250 3650
Wire Wire Line
	6350 3750 6250 3750
Text GLabel 7700 2950 0    50   Input ~ 0
RTS
Text GLabel 7700 2550 0    50   Input ~ 0
DTR
Wire Wire Line
	7700 2550 7800 2550
Wire Wire Line
	7700 2950 7800 2950
Text GLabel 7700 2750 0    50   Input ~ 0
RX
Text GLabel 7700 2650 0    50   Input ~ 0
TX
Wire Wire Line
	7700 2650 7800 2650
Wire Wire Line
	7700 2750 7800 2750
$Comp
L Device:LED D1
U 1 1 5FCEC462
P 7550 5500
F 0 "D1" V 7589 5382 50  0000 R CNN
F 1 "RST" V 7498 5382 50  0000 R CNN
F 2 "LED_THT:LED_D5.0mm" H 7550 5500 50  0001 C CNN
F 3 "~" H 7550 5500 50  0001 C CNN
	1    7550 5500
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D2
U 1 1 5FCED322
P 7900 5500
F 0 "D2" V 7939 5382 50  0000 R CNN
F 1 "IO0" V 7848 5382 50  0000 R CNN
F 2 "LED_THT:LED_D5.0mm" H 7900 5500 50  0001 C CNN
F 3 "~" H 7900 5500 50  0001 C CNN
	1    7900 5500
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D3
U 1 1 5FCEDAFD
P 8250 5500
F 0 "D3" V 8289 5382 50  0000 R CNN
F 1 "IO2" V 8198 5382 50  0000 R CNN
F 2 "LED_THT:LED_D5.0mm" H 8250 5500 50  0001 C CNN
F 3 "~" H 8250 5500 50  0001 C CNN
	1    8250 5500
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7550 5650 7900 5650
Connection ~ 7900 5650
Wire Wire Line
	7900 5650 8250 5650
$Comp
L power:GND #PWR011
U 1 1 5FCEEC76
P 7900 5750
F 0 "#PWR011" H 7900 5500 50  0001 C CNN
F 1 "GND" H 7905 5577 50  0000 C CNN
F 2 "" H 7900 5750 50  0001 C CNN
F 3 "" H 7900 5750 50  0001 C CNN
	1    7900 5750
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 5FCF2BC3
P 7550 5150
F 0 "R2" H 7620 5196 50  0000 L CNN
F 1 "330" H 7620 5105 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad0.98x0.95mm_HandSolder" V 7480 5150 50  0001 C CNN
F 3 "~" H 7550 5150 50  0001 C CNN
	1    7550 5150
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 5FCF3463
P 7900 5150
F 0 "R4" H 7970 5196 50  0000 L CNN
F 1 "330" H 7970 5105 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad0.98x0.95mm_HandSolder" V 7830 5150 50  0001 C CNN
F 3 "~" H 7900 5150 50  0001 C CNN
	1    7900 5150
	1    0    0    -1  
$EndComp
$Comp
L Device:R R6
U 1 1 5FCF3683
P 8250 5150
F 0 "R6" H 8320 5196 50  0000 L CNN
F 1 "330" H 8320 5105 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad0.98x0.95mm_HandSolder" V 8180 5150 50  0001 C CNN
F 3 "~" H 8250 5150 50  0001 C CNN
	1    8250 5150
	1    0    0    -1  
$EndComp
Wire Wire Line
	8250 5300 8250 5350
Wire Wire Line
	7900 5300 7900 5350
Wire Wire Line
	7550 5300 7550 5350
Text GLabel 7700 2450 0    50   Input ~ 0
IO2
Wire Wire Line
	7700 2450 7800 2450
Text GLabel 8250 4900 1    50   Input ~ 0
IO2
Text GLabel 7550 4900 1    50   Input ~ 0
RTS
Text GLabel 7900 4900 1    50   Input ~ 0
DTR
Wire Wire Line
	7550 4900 7550 5000
Wire Wire Line
	7900 4900 7900 5000
Wire Wire Line
	8250 4900 8250 5000
Wire Wire Line
	7900 5650 7900 5750
$EndSCHEMATC
