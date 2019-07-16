# ZwaveMqttBridge

!!! NOT PART OF THE PROJECT !!!
Rough implementation of OpenZWAVE - MQTT(mosquitto) Bridge. uses Jsoncpp and mosquitopp libraries for compilation. 

for compile use:

g++ Zwave.cpp MessageStructure.cpp jsoncpp.cpp -I /usr/local/include/openzwave /usr/local/lib/libopenzwave.so -pthread -l mosquittopp -o Zwaver
