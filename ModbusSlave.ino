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
  sensors.begin();
  
  
  

}

void loop()
{

  /* add main program code here */
 
  mb.task();
   sensors.requestTemperatures();
  mb.Ireg(100, (int)sensors.getTempCByIndex(0));
  mb.Ireg(101, (int)sensors.getTempCByIndex(1));
  
  
  
  
  

}
