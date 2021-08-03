#!/bin/bash
arch=`uname -a`
pCPU=`nproc --all`
vCPU=`grep ^processor /proc/cpuinfo | wc -l`
uRAM=`free -m | grep Mem | awk '{print $3}'`
tRAM=`free -m | grep Mem | awk '{print $2}'`
uper=`free -m | grep Mem | awk '{printf("%.2f"), $3/$2*100}'`
tDSK=`df -Bg | grep '^/dev/' | grep -v '/boot$' | awk '{ft += $2} END {print ft}'`
uDSK=`df -Bm | grep '^/dev/' | grep -v '/boot$' | awk '{ut += $3} END {print ut}'`
dper=`df -Bm | grep '^/dev/' | grep -v '/boot$' | awk '{ut += $3} {ft += $2} END {printf("%d"),\
       	ut/ft*100}'`

wall "	#Architecture: $arch
	#CPU Physical: $pCPU
	#vCPU: $vCPU
	#Memory Usage: $uRAM/$tRAM"MB" ($uper%)
	#Disk Usage: $uDSK/$tDSK"Gb" ($dper%)
	#CPU Load:
	#Last boot:
	#LVM Use:
	#Connexions TCP:
	#User Log:
	#Network:
	#Sudo:"
