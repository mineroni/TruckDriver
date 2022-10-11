@echo off
REM Copying file to compiling folder
copy /y C:\Users\gtadj\Documents\Backup\Work\5.2023\Temalab\communicators\Truckdriver\driveAssembly_subscriber.cxx C:\Users\gtadj\AppData\Local\Packages\CanonicalGroupLimited.Ubuntu18.04LTS_79rhkp1fndgsc\LocalState\rootfs\home\ronald\truckDriver\src

REM Compiling driveAssembly_subscriber.cxx file (with other files)
ubuntu1804 run "cd ~/truckDriver/src/ && sudo rm -d objs -r && sudo make -f makefile_driveAssembly_armv7Linux4gcc7.5.0"

REM Sending driveAssembly_subscriber file to BeagleBone
scp C:\Users\gtadj\AppData\Local\Packages\CanonicalGroupLimited.Ubuntu18.04LTS_79rhkp1fndgsc\LocalState\rootfs\home\ronald\truckDriver\src\objs\armv7Linux4gcc7.5.0\driveAssembly_subscriber debian@192.168.7.2:.

REM pause