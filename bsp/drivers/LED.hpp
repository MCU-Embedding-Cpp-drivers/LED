#ifndef __LED_HPP
#define __LED_HPP

#include "GPIO.hpp"


/**
 * @brief LED 驱动类
 *
 * 提供：
 * - on()       : 点亮
 * - off()      : 熄灭
 * - toggle()   : 翻转（继承自 GPIO）
 */
class LED : public GPIO {
public:
    enum LED_State {
        OFF = 0,
        ON,
        TOGGLE,
    };

	enum DriveMode {
		ActiveHigh, // 高电平点亮
		ActiveLow	// 低电平点亮
	};

	LED(GPIO_TypeDef* port, uint16_t pin, DriveMode drive_mode);

	void on(void);

    void off(void);

	using GPIO::toggle; // 继承翻转函数 // 显式把 toggle 暴露在 LED 类
    
    LED_State read(void);

    DriveMode drivemode(void){
        return _drive_mode;
    }

private:
    DriveMode _drive_mode;
  
};


#endif //! __LED_HPP
