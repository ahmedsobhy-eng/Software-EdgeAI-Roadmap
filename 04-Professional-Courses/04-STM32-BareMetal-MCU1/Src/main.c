#include <stdint.h>

#define SCB_CPACR     (*(volatile uint32_t *)0xE000ED88U)
#define RCC_AHB1ENR   (*(volatile uint32_t *)0x40023830U)
#define GPIOC_MODER   (*(volatile uint32_t *)0x40020800U)
#define GPIOC_ODR     (*(volatile uint32_t *)0x40020814U)

int main(void)
{
    /* 1. تفعيل وحدة الـ FPU لمنع توقف المعالج (HardFault) */
    SCB_CPACR |= (0xFU << 20);

    /* 2. توصيل الكهرباء لبورت C */
    RCC_AHB1ENR |= (1U << 2);
    volatile uint32_t delay = RCC_AHB1ENR;
    (void)delay;

    /* 3. ضبط الرجل PC13 كمخرج كهرباء */
    GPIOC_MODER &= ~(3U << 26);
    GPIOC_MODER |=  (1U << 26);

    while (1)
    {
        /* 4. عكس حالة اللمبة الزرقاء */
        GPIOC_ODR ^= (1U << 13);
        for (volatile uint32_t i = 0; i < 600000U; i++);
    }
}
