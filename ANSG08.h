#ifndef ANSG08_H
#define ANSG08_H

#include "stm32f1xx_hal.h"

#define Ch_enable  0x01 //Touch Channel Enable/Disable
#define i2c_id  	0x06 //I2C Address of ANSG08
#define Clock_ctrl  0x34 //Clock Control Register (init_cal_opt, Reserved, clk_sel, rb_sel)
#define Global_ctrl1 0x36 //Global Option Control Register1 
					//(response_off_ctrl, response_ctrl, bf_mode, Software Reset)
#define State_count 0x37 //Cal_pre_scale
#define Global_ctrl2 0x38 //Global Option Control Register2
							//(imp_sel,Single/Multi ,Cal_Hold_time,Reserved, ck_off)
							

typedef enum
{
	Sensitivity1				= 0x39,
	Sensitivity2							,
	Sensitivity3							,
	Sensitivity4							,
	Sensitivity5							,
	Sensitivity6							,
	Sensitivity7							,
	Sensitivity8
}Sensivity_Channel;

#define Cal_speed1 0x41 //Calibration Speed Control at BF mode
#define Cal_speed2 0x42 //Calibration Speed Control at BS mode

#define PromSet1	0x00 //EEPROM Holding Registers

#define PWM_ctrl1	0x43 //LED PWM control Register (D2,D1)
#define PWM_ctrl2	0x44 //LED PWM control Register (D4,D3)
#define PWM_ctrl3	0x45 //LED PWM control Register (D6,D5)
#define PWM_ctrl4	0x46 //LED PWM control Register (D8,D7)

#define Port_Mode	0x4F //Select the output port operation mode of each channel.
#define prom_cmd	0x5C //EEPROM Control Register
#define prom_addr	0x5F //EEPROM data address select register
#define Output  0x2A //Touch Output Data Register  (ch = 1bit)

#define ANSG08_Address  0x48


class ANSG08
{
	public:
		ANSG08(uint8_t _Address,I2C_HandleTypeDef *_hi2c);
		HAL_StatusTypeDef reset_EEPROM(void);
		void ChangeSensivity(Sensivity_Channel _Channel,uint8_t _Data);
		void ChangeAllSensivity(uint8_t _Data);
		void ReadSensor(void);
		uint8_t GetKeys(void);
		uint8_t* GetKeysArray(void);
	private:
		void ConvertKeyToArray(void);
		uint8_t ANSG08_Current_Address;
		I2C_HandleTypeDef *hi2c;
		uint8_t Data;
		uint8_t Array[8];
};

#endif
