@echo off

set ip=192.168.1.2
set source=C:\Users\gtadj\Documents\Backup\Work\5.2023\Temalab\communicators_v0.2\Truckdriver\driveAssembly_subscriber.cxx
set destination=C:\Users\gtadj\AppData\Local\Packages\CanonicalGroupLimited.Ubuntu18.04LTS_79rhkp1fndgsc\LocalState\rootfs\home\ronald\truckDriver\src
set compiled=C:\Users\gtadj\AppData\Local\Packages\CanonicalGroupLimited.Ubuntu18.04LTS_79rhkp1fndgsc\LocalState\rootfs\home\ronald\truckDriver\src\objs\armv7Linux4gcc7.5.0\driveAssembly_subscriber

REM Copying file to compiling folder
copy /y %source% %destination%

REM Compiling driveAssembly_subscriber.cxx file (with other files)
ubuntu1804 run "cd ~/truckDriver/src/ && sudo rm -d objs -r && sudo make -f makefile_driveAssembly_armv7Linux4gcc7.5.0"

REM Sending driveAssembly_subscriber file to BeagleBone
scp %compiled% debian@%ip%:.

REM Starting project on remote device
ssh debian@%ip% "config-pin P9.14 pwm ; config-pin P9.16 pwm ; config-pin P9.22 pwm ; ./driveAssembly_subscriber"

REM pause