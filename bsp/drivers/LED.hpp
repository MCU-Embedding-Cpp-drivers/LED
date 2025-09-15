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
    using GPIO::GPIO;   // 继承构造函数
    
    void on(void);

    void off(void);

	using GPIO::toggle; // 继承翻转函数 // 显式把 toggle 暴露在 LED 类
};

#endif //! __LED_HPP
