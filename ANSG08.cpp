#include "ANSG08.h"

ANSG08::ANSG08(uint8_t _Address,I2C_HandleTypeDef *_hi2c)
{
	ANSG08_Current_Address = _Address;
	hi2c = _hi2c;
}

HAL_StatusTypeDef ANSG08::reset_EEPROM(void)
{
	uint8_t Data = 0x00;
	return HAL_I2C_Mem_Write(hi2c,ANSG08_Current_Address,PromSet1,1,&Data,1,10);
}

void ANSG08::ChangeSensivity(Sensivity_Channel _Channel,uint8_t _Data)
{
	HAL_I2C_Mem_Write(hi2c,ANSG08_Current_Address,_Channel,1,&_Data,1,10);
}

void ANSG08::ChangeAllSensivity(uint8_t _Data)
{
	Sensivity_Channel Channel = Sensitivity1;
	ChangeSensivity( Channel, _Data);
	
	Channel = Sensitivity2;
	ChangeSensivity( Channel, _Data);
	
	Channel = Sensitivity3;
	ChangeSensivity( Channel, _Data);
	
	Channel = Sensitivity4;
	ChangeSensivity( Channel, _Data);
	
	Channel = Sensitivity5;
	ChangeSensivity( Channel, _Data);
	
	Channel = Sensitivity6;
	ChangeSensivity( Channel, _Data);
	
	Channel = Sensitivity7;
	ChangeSensivity( Channel, _Data);
	
	Channel = Sensitivity8;
	ChangeSensivity( Channel, _Data);
}

void ANSG08::ReadSensor(void)
{
	HAL_I2C_Mem_Read(hi2c,ANSG08_Current_Address,Output,1,&Data,1,10);
}

uint8_t ANSG08::GetKeys(void)
{
	return Data;
}

uint8_t* ANSG08::GetKeysArray(void)
{
	ConvertKeyToArray();
	return Array;
}

void ANSG08::ConvertKeyToArray(void)
{
	Array[0] = Array[1] = Array[2] = Array[3] = Array[4] = Array[5] = Array[6] = Array[7] = 0;
	
	if((Data & 0x01) == 0x01)
	{
		Array[0] = 1;
	}
	
	if((Data & 0x02) == 0x02)
	{
		Array[1] = 1;
	}
	
	if((Data & 0x02) == 0x04)
	{
		Array[2] = 1;
	}
	
	if((Data & 0x02) == 0x08)
	{
		Array[3] = 1;
	}
	
	if((Data & 0x10) == 0x10)
	{
		Array[4] = 1;
	}
	
	if((Data & 0x20) == 0x20)
	{
		Array[5] = 1;
	}
	
	if((Data & 0x40) == 0x40)
	{
		Array[6] = 1;
	}
	
	if((Data & 0x80) == 0x80)
	{
		Array[7] = 1;
	}
}
