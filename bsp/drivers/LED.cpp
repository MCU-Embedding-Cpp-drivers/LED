#include "LED.hpp"
#include "GPIO.hpp"
#include "stm32g4xx_hal_gpio.h"

/**
 * @brief LED构造函数，构造一个LED对象
 *
 * @param port LED所在port
 * @param pin LED所在pin
 * @param drive_mode led驱动模式
 * @arg LED::ActiveHigh 高电平点亮
 * @arg LED::ActiveLow  低电平点亮
 */
LED::LED(GPIO_TypeDef* port, uint16_t pin, DriveMode drive_mode) : GPIO(port, pin), _drive_mode(_drive_mode) {
}

/**
 * @brief LED点亮
 *
 */
void LED::on(void) {
	switch (_drive_mode) {
		case LED::ActiveHigh: // 高电平驱动
			GPIO::write(1);

		case LED::ActiveLow: // 低电平驱动
			GPIO::write(0);

		default: // 异常情况，_drive_mode被意外修改
			return;
	}
}

/**
 * @brief LED熄灭
 *
 */
void LED::off(void) {
	switch (_drive_mode) {
		case LED::ActiveHigh: // 高电平驱动
			GPIO::write(0);

		case LED::ActiveLow: // 低电平驱动
			GPIO::write(1);

		default: // 异常情况，_drive_mode被意外修改
			return;
	}
}

/**
 * @brief 返回当前LED亮灭状态（与驱动方式(_drive_mode)有关）
 *
 * @return LED::LED_State
 */
LED::LED_State LED::read(void) {
	switch (_drive_mode) {
		case LED::ActiveHigh:
			return (GPIO::read() == GPIO_PIN_SET) ? ON : OFF;

		case LED::ActiveLow:
			return (GPIO::read() == GPIO_PIN_RESET) ? OFF : ON;

		default: // 异常情况，_drive_mode被意外修改
			return OFF;
	}
}
