//
// Created by zxd on 2022/1/4.
//

#ifndef PERPETUAL_CALENDAR_DIS_H
#define PERPETUAL_CALENDAR_DIS_H

#include "stm32f4xx_hal.h"

typedef enum
{
    DIS_HOUR,
    DIS_YEAR,
    DIS_PASSWORD,
    DIS_,
} Dis;

void dis_uartscreen(Dis display_num);

#endif //PERPETUAL_CALENDAR_DIS_H
