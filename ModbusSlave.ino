#include <ModbusSerial.h>
#include <Modbus.h>
#include <DallasTemperature.h>
#include <OneWire.h>


#define ONE_WIRE_BUS 3

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
ModbusSerial mb;



void setup()
{

  /* add setup code here */
  mb.config(&Serial,19200,SERIAL_8N1);
  mb.setSlaveId(10);
  mb.addIreg(100);
  mb.addIreg(101);
  mb.addCoil(50);
  mb.addCoil(51);
  
  sensors.begin();
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  
  
  
  

}

void loop()
{

  /* add main program code here */
 
  
  sensors.requestTemperatures();
  float t1 = sensors.getTempCByIndex(0);
  float t2 = sensors.getTempCByIndex(1);
  mb.task();
  mb.Ireg(100, (int)t1);
  mb.Ireg(101, (int)t2);
  
  if (mb.Coil(50)){
	  
	  digitalWrite(11,LOW);
	  
  }else{
	  
	  digitalWrite(11,HIGH);
  }
  
  if (mb.Coil(51)){
	  
	  digitalWrite(12,LOW);
	  
  }else{
	  
	  digitalWrite(12,HIGH);
  }
  
  
  
  
  
  
  
  
  

}


