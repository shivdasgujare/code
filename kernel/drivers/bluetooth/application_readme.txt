This is readme for bluetooth related packages need for
getting bluetooth peripheral working.
======================================================

Bluez
=====

hciconfig
---------
	Gives info about the bluetooth hci on your pc
	Ensure the device is up and running and has required scan modes

$ hciconfig 
hci0:	Type: BR/EDR  Bus: USB
	BD Address: 7C:E9:D3:C5:E3:37  ACL MTU: 1021:8  SCO MTU: 64:1
	DOWN 
	RX bytes:1099 acl:0 sco:0 events:36 errors:0
	TX bytes:886 acl:0 sco:0 commands:36 errors:0

$ hciconfig -a
hci0:	Type: BR/EDR  Bus: USB
	BD Address: 7C:E9:D3:C5:E3:37  ACL MTU: 1021:8  SCO MTU: 64:1
	DOWN 
	RX bytes:1099 acl:0 sco:0 events:36 errors:0
	TX bytes:886 acl:0 sco:0 commands:36 errors:0
	Features: 0xbf 0xfe 0xcf 0xfe 0xdb 0xff 0x7b 0x87
	Packet type: DM1 DM3 DM5 DH1 DH3 DH5 HV1 HV2 HV3 
	Link policy: RSWITCH SNIFF 
	Link mode: SLAVE ACCEPT 

$ hciconfig hci0 up

$ hciconfig -a
hci0:	Type: BR/EDR  Bus: USB
	BD Address: 7C:E9:D3:C5:E3:37  ACL MTU: 1021:8  SCO MTU: 64:1
	UP RUNNING PSCAN 
	RX bytes:1921 acl:0 sco:0 events:69 errors:0
	TX bytes:1523 acl:0 sco:0 commands:69 errors:0
	Features: 0xbf 0xfe 0xcf 0xfe 0xdb 0xff 0x7b 0x87
	Packet type: DM1 DM3 DM5 DH1 DH3 DH5 HV1 HV2 HV3 
	Link policy: RSWITCH SNIFF 
	Link mode: SLAVE ACCEPT 
	Name: 'ubuntu-0'
	Class: 0x6e0100
	Service Classes: Networking, Rendering, Capturing, Audio, Telephony
	Device Class: Computer, Uncategorized
	HCI Version: 4.0 (0x6)  Revision: 0x10e5
	LMP Version: 4.0 (0x6)  Subversion: 0x220e
	Manufacturer: Broadcom Corporation (15)

hcitool
-------
	hcitool dev should also give some of this info

$ hcitool dev
Devices:
	hci0	7C:E9:D3:C5:E3:37


	hcitool inq and hcitool scan
		- Gives info about or rather identifies nearby bluetooth devices

Now, on nearby device ( Mobile ), switch ON bluetooth, and make the mobile
discoverable.
for ex. for Samsung Galaxy-Y android mobile
Settings -> Wireless and Networks -> Bluetooth -> Turn ON 
-> Discoverable ( Make device discoverable )

$ hcitool scan
Scanning ...
	38:EC:E4:50:2C:F7	GT-S5360

$ hcitool inq
Inquiring ...
	38:EC:E4:50:2C:F7	clock offset: 0x29e9	class: 0x5a020c


	hcitool info <Remote BTAddr>
		- Get info about remote bluetooth device

$ sudo hcitool info 38:EC:E4:50:2C:F7
Requesting information ...
	BD Address:  38:EC:E4:50:2C:F7
	Device Name: GT-S5360
	LMP Version: 4.0 (0x6) LMP Subversion: 0x4103
	Manufacturer: Broadcom Corporation (15)
	Features page 0: 0xbf 0xfe 0xcf 0xfe 0xdb 0xff 0x7b 0x87
		<3-slot packets> <5-slot packets> <encryption> <slot offset> 
		<timing accuracy> <role switch> <sniff mode> <RSSI> 
		<channel quality> <SCO link> <HV2 packets> <HV3 packets> 
		<u-law log> <A-law log> <CVSD> <paging scheme> <power control> 
		<transparent SCO> <broadcast encrypt> <EDR ACL 2 Mbps> 
		<EDR ACL 3 Mbps> <enhanced iscan> <interlaced iscan> 
		<interlaced pscan> <inquiry with RSSI> <extended SCO> 
		<EV4 packets> <EV5 packets> <AFH cap. slave> 
		<AFH class. slave> <LE support> <3-slot EDR ACL> 
		<5-slot EDR ACL> <sniff subrating> <pause encryption> 
		<AFH cap. master> <AFH class. master> <EDR eSCO 2 Mbps> 
		<EDR eSCO 3 Mbps> <3-slot EDR eSCO> <extended inquiry> 
		<LE and BR/EDR> <simple pairing> <encapsulated PDU> 
		<err. data report> <non-flush flag> <LSTO> <inquiry TX power> 
		<EPC> <extended features> 
	Features page 1: 0x01 0x00 0x00 0x00 0x00 0x00 0x00 0x00

l2ping
------
	l2ping <Remote BTAddr>
		- One way to see if we can communicate with a remote bluetooth device

$ sudo l2ping 38:EC:E4:50:2C:F7
Ping: 38:EC:E4:50:2C:F7 from 7C:E9:D3:C5:E3:37 (data size 44) ...
0 bytes from 38:EC:E4:50:2C:F7 id 0 time 8.66ms
0 bytes from 38:EC:E4:50:2C:F7 id 1 time 7.74ms
0 bytes from 38:EC:E4:50:2C:F7 id 2 time 6.77ms
0 bytes from 38:EC:E4:50:2C:F7 id 3 time 5.67ms
0 bytes from 38:EC:E4:50:2C:F7 id 4 time 7.89ms

Reference's
===========

1. command line bluetooth
	http://hanishkvc.wordpress.com/2007/05/16/short-and-simple-commandline-bluetooth-in-any-new-linux-distros/
2. Android Bluetooth
	http://processors.wiki.ti.com/index.php/Android-Adding_Bluetooth_Profile 
