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
cpur=`top -bn1 | grep '^%Cpu' | cut -c 9- | awk '{printf("%.1f%%"), $1 + $3}'`
when=`who -b | awk '{print $3 " " $4}'`
lvmn=`lsblk | grep "lvm" | wc -l`
lvme=`if [ $lvmn -eq 0 ]; then echo no; else echo yes; fi`
ip=`hostname -I`
maca=`ip a | grep ether | awk '{print "(" $2 ")"}'`
esta=`netstat -anp | grep ESTABLISHED | wc -l`
user=`users | wc -w`
cmds=`grep sudo /var/log/auth.log | wc -l`

wall "	#Architecture: $arch
	#CPU Physical: $pCPU
	#vCPU: $vCPU
	#Memory Usage: $uRAM/$tRAM"MB" ($uper%)
	#Disk Usage: $uDSK/$tDSK"Gb" ($dper%)
	#CPU Load: $cpur
	#Last boot: $when
	#LVM Use: $lvme
	#Connexions TCP: $esta "ESTABLISHED"
	#User Log: $user
	#Network: "IP "$ip$maca
	#Sudo: $cmds cmd"
