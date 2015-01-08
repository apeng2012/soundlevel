EESchema Schematic File Version 2
LIBS:soundlevel
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:power
LIBS:soundlevel-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Sound level meter"
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L LM358 U4
U 1 1 54A74816
P 7150 3550
F 0 "U4" H 7100 3750 60  0000 L CNN
F 1 "AD822A" H 7100 3300 60  0000 L CNN
F 2 "Housings_SOIC:SOIC-8_3.9x4.9mm_Pitch1.27mm" H 7150 3550 60  0001 C CNN
F 3 "" H 7150 3550 60  0000 C CNN
	1    7150 3550
	1    0    0    -1  
$EndComp
$Comp
L LM358 U4
U 2 1 54A74867
P 8600 3450
F 0 "U4" H 8550 3650 60  0000 L CNN
F 1 "AD822A" H 8550 3200 60  0000 L CNN
F 2 "Housings_SOIC:SOIC-8_3.9x4.9mm_Pitch1.27mm" H 8600 3450 60  0001 C CNN
F 3 "" H 8600 3450 60  0000 C CNN
	2    8600 3450
	1    0    0    1   
$EndComp
Wire Wire Line
	7650 3550 8100 3550
Wire Wire Line
	6650 3650 6650 4150
Wire Wire Line
	6650 4150 7850 4150
Wire Wire Line
	7850 4150 7850 3550
Connection ~ 7850 3550
$Comp
L R R9
U 1 1 54A7494F
P 7050 2750
F 0 "R9" V 7130 2750 40  0000 C CNN
F 1 "100k" V 7057 2751 40  0000 C CNN
F 2 "soundlevel:SMD-0603_R" V 6980 2750 30  0001 C CNN
F 3 "" H 7050 2750 30  0000 C CNN
	1    7050 2750
	0    1    1    0   
$EndComp
$Comp
L R R10
U 1 1 54A74A87
P 8500 2750
F 0 "R10" V 8580 2750 40  0000 C CNN
F 1 "100k" V 8507 2751 40  0000 C CNN
F 2 "soundlevel:SMD-0603_R" V 8430 2750 30  0001 C CNN
F 3 "" H 8500 2750 30  0000 C CNN
	1    8500 2750
	0    1    1    0   
$EndComp
Wire Wire Line
	7300 2750 8250 2750
Wire Wire Line
	8750 2750 9350 2750
Wire Wire Line
	9350 2750 9350 3450
Wire Wire Line
	8100 3350 7850 3350
Wire Wire Line
	7850 3350 7850 2750
Connection ~ 7850 2750
Wire Wire Line
	6800 2750 6650 2750
Wire Wire Line
	6650 2750 6650 3450
$Comp
L SPU0414HR5H-SB U1
U 1 1 54A74FC5
P 1150 3300
F 0 "U1" H 1150 3150 60  0000 C CNN
F 1 "SPU0410HR5H" H 1150 3450 60  0000 C CNN
F 2 "soundlevel:SPU04" H 1150 3300 60  0001 C CNN
F 3 "" H 1150 3300 60  0000 C CNN
	1    1150 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	1400 3250 1650 3250
Wire Wire Line
	6650 3450 6300 3450
Connection ~ 9350 3450
$Comp
L C C8
U 1 1 54A75530
P 9750 3750
F 0 "C8" V 9700 3600 40  0000 L CNN
F 1 "10u" V 9700 3825 40  0000 L CNN
F 2 "soundlevel:SMD-0603_C" H 9788 3600 30  0001 C CNN
F 3 "" H 9750 3750 60  0000 C CNN
	1    9750 3750
	-1   0    0    1   
$EndComp
$Comp
L +5V #PWR01
U 1 1 54A75644
P 7050 3150
F 0 "#PWR01" H 7050 3000 60  0001 C CNN
F 1 "+5V" H 7050 3290 60  0000 C CNN
F 2 "" H 7050 3150 60  0000 C CNN
F 3 "" H 7050 3150 60  0000 C CNN
	1    7050 3150
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR02
U 1 1 54A75673
P 8500 3850
F 0 "#PWR02" H 8500 3700 60  0001 C CNN
F 1 "+5V" H 8500 3990 60  0000 C CNN
F 2 "" H 8500 3850 60  0000 C CNN
F 3 "" H 8500 3850 60  0000 C CNN
	1    8500 3850
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR03
U 1 1 54A75707
P 7050 3950
F 0 "#PWR03" H 7050 3700 60  0001 C CNN
F 1 "GND" H 7050 3800 60  0000 C CNN
F 2 "" H 7050 3950 60  0000 C CNN
F 3 "" H 7050 3950 60  0000 C CNN
	1    7050 3950
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR04
U 1 1 54A75765
P 950 3350
F 0 "#PWR04" H 950 3100 60  0001 C CNN
F 1 "GND" V 950 3150 60  0000 C CNN
F 2 "" H 950 3350 60  0000 C CNN
F 3 "" H 950 3350 60  0000 C CNN
	1    950  3350
	0    1    1    0   
$EndComp
$Comp
L GND #PWR05
U 1 1 54A7579D
P 9750 3950
F 0 "#PWR05" H 9750 3700 60  0001 C CNN
F 1 "GND" H 9750 3800 60  0000 C CNN
F 2 "" H 9750 3950 60  0000 C CNN
F 3 "" H 9750 3950 60  0000 C CNN
	1    9750 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	9750 3450 9750 3550
$Comp
L GND #PWR06
U 1 1 54A75ACE
P 9850 3350
F 0 "#PWR06" H 9850 3100 60  0001 C CNN
F 1 "GND" V 9850 3150 60  0000 C CNN
F 2 "" H 9850 3350 60  0000 C CNN
F 3 "" H 9850 3350 60  0000 C CNN
	1    9850 3350
	0    1    1    0   
$EndComp
$Comp
L +5V #PWR07
U 1 1 54A75B15
P 9950 2750
F 0 "#PWR07" H 9950 2600 60  0001 C CNN
F 1 "+5V" V 9950 3000 60  0000 C CNN
F 2 "" H 9950 2750 60  0000 C CNN
F 3 "" H 9950 2750 60  0000 C CNN
	1    9950 2750
	1    0    0    -1  
$EndComp
Connection ~ 9750 3450
Text Notes 10050 3750 0    60   ~ 0
connect to KL25
$Comp
L GND #PWR08
U 1 1 54AE2506
P 2350 7100
F 0 "#PWR08" H 2350 6850 60  0001 C CNN
F 1 "GND" H 2350 6950 60  0000 C CNN
F 2 "" H 2350 7100 60  0000 C CNN
F 3 "" H 2350 7100 60  0000 C CNN
	1    2350 7100
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 6100 2750 6600
Wire Wire Line
	1950 6100 3150 6100
$Comp
L R R2
U 1 1 54AE2824
P 1700 6100
F 0 "R2" V 1780 6100 40  0000 C CNN
F 1 "1k" V 1707 6101 40  0000 C CNN
F 2 "soundlevel:SMD-0603_R" V 1630 6100 30  0001 C CNN
F 3 "" H 1700 6100 30  0000 C CNN
	1    1700 6100
	0    -1   -1   0   
$EndComp
$Comp
L +5V #PWR09
U 1 1 54AE29AE
P 1300 6100
F 0 "#PWR09" H 1300 5950 60  0001 C CNN
F 1 "+5V" V 1300 6350 60  0000 C CNN
F 2 "" H 1300 6100 60  0000 C CNN
F 3 "" H 1300 6100 60  0000 C CNN
	1    1300 6100
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1450 6100 1300 6100
Connection ~ 2350 6100
Wire Wire Line
	1400 3350 1500 3350
Wire Wire Line
	1500 3350 1500 3450
$Comp
L GND #PWR010
U 1 1 54A75736
P 1500 4350
F 0 "#PWR010" H 1500 4100 60  0001 C CNN
F 1 "GND" H 1500 4200 60  0000 C CNN
F 2 "" H 1500 4350 60  0000 C CNN
F 3 "" H 1500 4350 60  0000 C CNN
	1    1500 4350
	1    0    0    -1  
$EndComp
$Comp
L C C1
U 1 1 54A75208
P 1500 4150
F 0 "C1" H 1500 4250 40  0000 L CNN
F 1 "0" H 1506 4065 40  0000 L CNN
F 2 "soundlevel:SMD-0603_C" H 1538 4000 30  0001 C CNN
F 3 "" H 1500 4150 60  0000 C CNN
	1    1500 4150
	-1   0    0    1   
$EndComp
$Comp
L R R1
U 1 1 54A75165
P 1500 3700
F 0 "R1" V 1580 3700 40  0000 C CNN
F 1 "0" V 1507 3701 40  0000 C CNN
F 2 "soundlevel:SMD-0603_R" V 1430 3700 30  0001 C CNN
F 3 "" H 1500 3700 30  0000 C CNN
	1    1500 3700
	-1   0    0    1   
$EndComp
$Comp
L AD8542 U3
U 1 1 54AE3114
P 3050 3350
F 0 "U3" H 3000 3550 60  0000 L CNN
F 1 "AD8542" H 3000 3100 60  0000 L CNN
F 2 "Housings_SOIC:SOIC-8_3.9x4.9mm_Pitch1.27mm" H 3050 3350 60  0001 C CNN
F 3 "" H 3050 3350 60  0000 C CNN
	1    3050 3350
	1    0    0    -1  
$EndComp
$Comp
L C C4
U 1 1 54AE37F2
P 3150 6600
F 0 "C4" V 3100 6450 40  0000 L CNN
F 1 "10u" V 3100 6675 40  0000 L CNN
F 2 "soundlevel:SMD-0603_C" H 3188 6450 30  0001 C CNN
F 3 "" H 3150 6600 60  0000 C CNN
	1    3150 6600
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR011
U 1 1 54AE396B
P 3150 6800
F 0 "#PWR011" H 3150 6550 60  0001 C CNN
F 1 "GND" H 3150 6650 60  0000 C CNN
F 2 "" H 3150 6800 60  0000 C CNN
F 3 "" H 3150 6800 60  0000 C CNN
	1    3150 6800
	1    0    0    -1  
$EndComp
Wire Wire Line
	3150 6100 3150 6400
Connection ~ 2750 6100
$Comp
L C C2
U 1 1 54AE3AFD
P 1850 3250
F 0 "C2" V 1800 3100 40  0000 L CNN
F 1 "10u" V 1800 3325 40  0000 L CNN
F 2 "soundlevel:SMD-0603_C" H 1888 3100 30  0001 C CNN
F 3 "" H 1850 3250 60  0000 C CNN
	1    1850 3250
	0    1    1    0   
$EndComp
Wire Wire Line
	2050 3250 2550 3250
$Comp
L +5V #PWR012
U 1 1 54AE401C
P 2950 2950
F 0 "#PWR012" H 2950 2800 60  0001 C CNN
F 1 "+5V" H 2950 3090 60  0000 C CNN
F 2 "" H 2950 2950 60  0000 C CNN
F 3 "" H 2950 2950 60  0000 C CNN
	1    2950 2950
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR013
U 1 1 54AE4171
P 2950 3750
F 0 "#PWR013" H 2950 3500 60  0001 C CNN
F 1 "GND" H 2950 3600 60  0000 C CNN
F 2 "" H 2950 3750 60  0000 C CNN
F 3 "" H 2950 3750 60  0000 C CNN
	1    2950 3750
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR014
U 1 1 54AE41D6
P 8500 3050
F 0 "#PWR014" H 8500 2800 60  0001 C CNN
F 1 "GND" H 8500 2900 60  0000 C CNN
F 2 "" H 8500 3050 60  0000 C CNN
F 3 "" H 8500 3050 60  0000 C CNN
	1    8500 3050
	-1   0    0    1   
$EndComp
$Comp
L R R3
U 1 1 54AE43EE
P 2300 2800
F 0 "R3" V 2380 2800 40  0000 C CNN
F 1 "100k" V 2307 2801 40  0000 C CNN
F 2 "soundlevel:SMD-0603_R" V 2230 2800 30  0001 C CNN
F 3 "" H 2300 2800 30  0000 C CNN
	1    2300 2800
	-1   0    0    1   
$EndComp
Wire Wire Line
	2300 3050 2300 3250
Connection ~ 2300 3250
$Comp
L R R4
U 1 1 54AE48BC
P 2550 4050
F 0 "R4" V 2630 4050 40  0000 C CNN
F 1 "10k" V 2557 4051 40  0000 C CNN
F 2 "soundlevel:SMD-0603_R" V 2480 4050 30  0001 C CNN
F 3 "" H 2550 4050 30  0000 C CNN
	1    2550 4050
	-1   0    0    1   
$EndComp
$Comp
L R R5
U 1 1 54AE495E
P 3350 3800
F 0 "R5" V 3430 3800 40  0000 C CNN
F 1 "100k" V 3357 3801 40  0000 C CNN
F 2 "soundlevel:SMD-0603_R" V 3280 3800 30  0001 C CNN
F 3 "" H 3350 3800 30  0000 C CNN
	1    3350 3800
	0    1    1    0   
$EndComp
Wire Wire Line
	3550 3350 3850 3350
Wire Wire Line
	3700 3350 3700 3800
Wire Wire Line
	3700 3800 3600 3800
Wire Wire Line
	3100 3800 2550 3800
Wire Wire Line
	2550 3800 2550 3450
$Comp
L C C3
U 1 1 54AE4B42
P 2550 4500
F 0 "C3" H 2450 4400 40  0000 L CNN
F 1 "2u" H 2450 4600 40  0000 L CNN
F 2 "soundlevel:SMD-0603_C" H 2588 4350 30  0001 C CNN
F 3 "" H 2550 4500 60  0000 C CNN
	1    2550 4500
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR015
U 1 1 54AE4BD9
P 2550 4700
F 0 "#PWR015" H 2550 4450 60  0001 C CNN
F 1 "GND" H 2550 4550 60  0000 C CNN
F 2 "" H 2550 4700 60  0000 C CNN
F 3 "" H 2550 4700 60  0000 C CNN
	1    2550 4700
	1    0    0    -1  
$EndComp
$Comp
L C C5
U 1 1 54AE5371
P 4050 3350
F 0 "C5" V 4000 3200 40  0000 L CNN
F 1 "10u" V 4000 3425 40  0000 L CNN
F 2 "soundlevel:SMD-0603_C" H 4088 3200 30  0001 C CNN
F 3 "" H 4050 3350 60  0000 C CNN
	1    4050 3350
	0    1    1    0   
$EndComp
Wire Wire Line
	4250 3350 4600 3350
$Comp
L +5V #PWR016
U 1 1 54AE5378
P 5000 3050
F 0 "#PWR016" H 5000 2900 60  0001 C CNN
F 1 "+5V" H 5000 3190 60  0000 C CNN
F 2 "" H 5000 3050 60  0000 C CNN
F 3 "" H 5000 3050 60  0000 C CNN
	1    5000 3050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR017
U 1 1 54AE537E
P 5000 3850
F 0 "#PWR017" H 5000 3600 60  0001 C CNN
F 1 "GND" H 5000 3700 60  0000 C CNN
F 2 "" H 5000 3850 60  0000 C CNN
F 3 "" H 5000 3850 60  0000 C CNN
	1    5000 3850
	1    0    0    -1  
$EndComp
$Comp
L R R6
U 1 1 54AE5384
P 4350 2900
F 0 "R6" V 4430 2900 40  0000 C CNN
F 1 "100k" V 4357 2901 40  0000 C CNN
F 2 "soundlevel:SMD-0603_R" V 4280 2900 30  0001 C CNN
F 3 "" H 4350 2900 30  0000 C CNN
	1    4350 2900
	-1   0    0    1   
$EndComp
Wire Wire Line
	4350 3150 4350 3350
Connection ~ 4350 3350
$Comp
L R R7
U 1 1 54AE5392
P 4600 4150
F 0 "R7" V 4680 4150 40  0000 C CNN
F 1 "10k" V 4607 4151 40  0000 C CNN
F 2 "soundlevel:SMD-0603_R" V 4530 4150 30  0001 C CNN
F 3 "" H 4600 4150 30  0000 C CNN
	1    4600 4150
	-1   0    0    1   
$EndComp
$Comp
L R R8
U 1 1 54AE5398
P 5400 3900
F 0 "R8" V 5480 3900 40  0000 C CNN
F 1 "100k" V 5407 3901 40  0000 C CNN
F 2 "soundlevel:SMD-0603_R" V 5330 3900 30  0001 C CNN
F 3 "" H 5400 3900 30  0000 C CNN
	1    5400 3900
	0    1    1    0   
$EndComp
Wire Wire Line
	5600 3450 5900 3450
Wire Wire Line
	5750 3450 5750 3900
Wire Wire Line
	5750 3900 5650 3900
Wire Wire Line
	5150 3900 4600 3900
Wire Wire Line
	4600 3900 4600 3550
$Comp
L C C6
U 1 1 54AE53A3
P 4600 4600
F 0 "C6" H 4500 4500 40  0000 L CNN
F 1 "2u" H 4500 4700 40  0000 L CNN
F 2 "soundlevel:SMD-0603_C" H 4638 4450 30  0001 C CNN
F 3 "" H 4600 4600 60  0000 C CNN
	1    4600 4600
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR018
U 1 1 54AE53A9
P 4600 4800
F 0 "#PWR018" H 4600 4550 60  0001 C CNN
F 1 "GND" H 4600 4650 60  0000 C CNN
F 2 "" H 4600 4800 60  0000 C CNN
F 3 "" H 4600 4800 60  0000 C CNN
	1    4600 4800
	1    0    0    -1  
$EndComp
$Comp
L AD8542 U3
U 2 1 54AE536B
P 5100 3450
F 0 "U3" H 5050 3650 60  0000 L CNN
F 1 "AD8542" H 5050 3200 60  0000 L CNN
F 2 "Housings_SOIC:SOIC-8_3.9x4.9mm_Pitch1.27mm" H 5100 3450 60  0001 C CNN
F 3 "" H 5100 3450 60  0000 C CNN
	2    5100 3450
	1    0    0    -1  
$EndComp
Connection ~ 3700 3350
Wire Wire Line
	9100 3450 9950 3450
$Comp
L C C7
U 1 1 54AE648E
P 6100 3450
F 0 "C7" V 6050 3300 40  0000 L CNN
F 1 "10u" V 6050 3525 40  0000 L CNN
F 2 "soundlevel:SMD-0603_C" H 6138 3300 30  0001 C CNN
F 3 "" H 6100 3450 60  0000 C CNN
	1    6100 3450
	0    1    1    0   
$EndComp
Connection ~ 5750 3450
$Comp
L CONN_01X03 P1
U 1 1 54AE2F9E
P 10150 3350
F 0 "P1" H 10150 3550 50  0000 C CNN
F 1 "CONN_01X03" V 10250 3350 50  0000 C CNN
F 2 "soundlevel:PH-3A" H 10150 3350 60  0001 C CNN
F 3 "" H 10150 3350 60  0000 C CNN
	1    10150 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	9950 3350 9850 3350
$Comp
L TL431_SOT23-3 U2
U 1 1 54AE72CA
P 2350 6600
F 0 "U2" H 2500 6900 70  0000 C CNN
F 1 "TL431_SOT23-3" V 2150 6650 70  0000 C CNN
F 2 "SMD_Packages:SOT-23" H 2350 6600 60  0001 C CNN
F 3 "" H 2350 6600 60  0000 C CNN
	1    2350 6600
	1    0    0    -1  
$EndComp
$Comp
L +2V5 #PWR019
U 1 1 54AE745C
P 3150 6100
F 0 "#PWR019" H 3150 5950 60  0001 C CNN
F 1 "+2V5" H 3150 6240 60  0000 C CNN
F 2 "" H 3150 6100 60  0000 C CNN
F 3 "" H 3150 6100 60  0000 C CNN
	1    3150 6100
	1    0    0    -1  
$EndComp
$Comp
L +2V5 #PWR020
U 1 1 54AE7887
P 4350 2650
F 0 "#PWR020" H 4350 2500 60  0001 C CNN
F 1 "+2V5" H 4350 2790 60  0000 C CNN
F 2 "" H 4350 2650 60  0000 C CNN
F 3 "" H 4350 2650 60  0000 C CNN
	1    4350 2650
	1    0    0    -1  
$EndComp
$Comp
L +2V5 #PWR021
U 1 1 54AE79A5
P 2300 2550
F 0 "#PWR021" H 2300 2400 60  0001 C CNN
F 1 "+2V5" H 2300 2690 60  0000 C CNN
F 2 "" H 2300 2550 60  0000 C CNN
F 3 "" H 2300 2550 60  0000 C CNN
	1    2300 2550
	1    0    0    -1  
$EndComp
$Comp
L +2V5 #PWR022
U 1 1 54AE79C9
P 950 3250
F 0 "#PWR022" H 950 3100 60  0001 C CNN
F 1 "+2V5" V 950 3500 60  0000 C CNN
F 2 "" H 950 3250 60  0000 C CNN
F 3 "" H 950 3250 60  0000 C CNN
	1    950  3250
	0    -1   -1   0   
$EndComp
$Comp
L C C9
U 1 1 54AE8329
P 5100 4600
F 0 "C9" H 5000 4500 40  0000 L CNN
F 1 "10u" H 4950 4700 40  0000 L CNN
F 2 "soundlevel:SMD-0603_C" H 5138 4450 30  0001 C CNN
F 3 "" H 5100 4600 60  0000 C CNN
	1    5100 4600
	-1   0    0    1   
$EndComp
$Comp
L C C10
U 1 1 54AE837F
P 5400 4600
F 0 "C10" H 5300 4500 40  0000 L CNN
F 1 "0.1u" H 5250 4700 40  0000 L CNN
F 2 "soundlevel:SMD-0603_C" H 5438 4450 30  0001 C CNN
F 3 "" H 5400 4600 60  0000 C CNN
	1    5400 4600
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR?
U 1 1 54AE8562
P 5100 4800
F 0 "#PWR?" H 5100 4550 60  0001 C CNN
F 1 "GND" H 5100 4650 60  0000 C CNN
F 2 "" H 5100 4800 60  0000 C CNN
F 3 "" H 5100 4800 60  0000 C CNN
	1    5100 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	5100 4800 5400 4800
Wire Wire Line
	5100 4400 5400 4400
$Comp
L R R11
U 1 1 54AE87D9
P 9950 3000
F 0 "R11" H 10030 3000 40  0000 C CNN
F 1 "0" V 9957 3001 40  0000 C CNN
F 2 "soundlevel:SMD-0603_R" V 9880 3000 30  0001 C CNN
F 3 "" H 9950 3000 30  0000 C CNN
	1    9950 3000
	-1   0    0    1   
$EndComp
$Comp
L +5V #PWR?
U 1 1 54AE8A24
P 5100 4400
F 0 "#PWR?" H 5100 4250 60  0001 C CNN
F 1 "+5V" H 5100 4540 60  0000 C CNN
F 2 "" H 5100 4400 60  0000 C CNN
F 3 "" H 5100 4400 60  0000 C CNN
	1    5100 4400
	1    0    0    -1  
$EndComp
$Comp
L C C11
U 1 1 54AE8EC9
P 7050 4600
F 0 "C11" H 6950 4500 40  0000 L CNN
F 1 "10u" H 6900 4700 40  0000 L CNN
F 2 "soundlevel:SMD-0603_C" H 7088 4450 30  0001 C CNN
F 3 "" H 7050 4600 60  0000 C CNN
	1    7050 4600
	-1   0    0    1   
$EndComp
$Comp
L C C12
U 1 1 54AE8ECF
P 7350 4600
F 0 "C12" H 7250 4500 40  0000 L CNN
F 1 "0.1u" H 7200 4700 40  0000 L CNN
F 2 "soundlevel:SMD-0603_C" H 7388 4450 30  0001 C CNN
F 3 "" H 7350 4600 60  0000 C CNN
	1    7350 4600
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR?
U 1 1 54AE8ED5
P 7050 4800
F 0 "#PWR?" H 7050 4550 60  0001 C CNN
F 1 "GND" H 7050 4650 60  0000 C CNN
F 2 "" H 7050 4800 60  0000 C CNN
F 3 "" H 7050 4800 60  0000 C CNN
	1    7050 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	7050 4800 7350 4800
Wire Wire Line
	7050 4400 7350 4400
$Comp
L +5V #PWR?
U 1 1 54AE8EDD
P 7050 4400
F 0 "#PWR?" H 7050 4250 60  0001 C CNN
F 1 "+5V" H 7050 4540 60  0000 C CNN
F 2 "" H 7050 4400 60  0000 C CNN
F 3 "" H 7050 4400 60  0000 C CNN
	1    7050 4400
	1    0    0    -1  
$EndComp
$EndSCHEMATC
