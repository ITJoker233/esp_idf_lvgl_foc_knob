#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#define SWITCH_BUTTON 5
#define PHASE_U_GPIO 15
#define PHASE_V_GPIO 16
#define PHASE_W_GPIO 17
#define MOTOR_PP     7
#define MT6701_SPI_HOST SPI3_HOST
#define MT6701_SPI_SCLK_GPIO 2
#define MT6701_SPI_MISO_GPIO 1
#define MT6701_SPI_MOSI_GPIO -1
#define MT6701_SPI_CS_GPIO 42

#define USING_MCPWM 0

#if !USING_MCPWM
#define LEDC_CHAN_0 1
#define LEDC_CHAN_1 2
#define LEDC_CHAN_2 3
#endif



void foc_init(void);
#ifdef __cplusplus

}
#endif