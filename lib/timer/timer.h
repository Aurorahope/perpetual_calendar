//
// Created by zxd on 2022/1/4.
//

#ifndef PERPETUAL_CALENDAR_TIMER_H
#define PERPETUAL_CALENDAR_TIMER_H

#include "stm32f4xx_hal.h"
#include "tim.h"

#define Tim2_time 100 //定时器2设定时间
#define Second_set 1000 //1s定时时长

typedef struct {
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
} User_time_st;//时间结构体

typedef struct {
    User_time_st time;
    uint8_t Second_dispose;//1s响应标志位
    uint8_t leap_year;//闰年标志位
} Perpetual_calendar_st;//万年历结构体

typedef struct {
    User_time_st time;
    uint8_t start;//闹钟开关
    uint8_t rep[7];//重复日期
} alarm_clock_st;//闹钟结构体

void time_response(void);//1s响应函数

#endif //PERPETUAL_CALENDAR_TIMER_H
