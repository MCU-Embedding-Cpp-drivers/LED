#include "LED.hpp"
#include "GPIO.hpp"

/**
 * @brief LED点亮
 * 
 */
void LED::on(void){
    GPIO::write(0); // 低电平驱动
}

/**
 * @brief LED熄灭
 * 
 */
void LED::off(void){
	GPIO::write(1); // 高电平关闭
}

