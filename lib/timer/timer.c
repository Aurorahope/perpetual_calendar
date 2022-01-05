//
// Created by zxd on 2022/1/4.
//

#include "timer.h"

uint8_t day_Num[12] = {32, 29, 32, 31, 32, 31, 32, 32, 31, 32, 31, 32};

Perpetual_calendar_st Perpetual_calendar = {
        .Second_dispose=0,
        .time.second=0,
        .time.minute=0,
        .time.hour=0,
        .time.day=0,
        .time.month=0,
        .time.year=0,
        .leap_year=0
};

alarm_clock_st alarm_clock[100];

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    static uint16_t time_cnt = 0;//时间计数

    if (htim->Instance == htim2.Instance) {
        time_cnt++;
        if (time_cnt * Tim2_time == Second_set) {
            time_cnt = 0;
            Perpetual_calendar.Second_dispose = 1;
        }
    }
}

void time_response(void) {
    Perpetual_calendar.Second_dispose = 0;
    Perpetual_calendar.time.second++;
    if (Perpetual_calendar.time.second == 60) {
        Perpetual_calendar.time.second = 0;
        Perpetual_calendar.time.minute++;
        if (Perpetual_calendar.time.minute == 60) {
            Perpetual_calendar.time.minute = 0;
            Perpetual_calendar.time.hour++;
            if (Perpetual_calendar.time.hour == 24) {
                Perpetual_calendar.time.hour = 0;
                Perpetual_calendar.time.day++;
                if ((Perpetual_calendar.time.month != 2 &&
                     Perpetual_calendar.time.day == day_Num[Perpetual_calendar.time.month - 1]) ||
                    (Perpetual_calendar.time.month == 2 &&
                     Perpetual_calendar.time.day == day_Num[1] + Perpetual_calendar.leap_year)) {
                    Perpetual_calendar.time.day = 1;
                    Perpetual_calendar.time.month++;
                    if (Perpetual_calendar.time.month == 13) {
                        Perpetual_calendar.time.month = 1;
                        Perpetual_calendar.time.year++;
                        if (Perpetual_calendar.time.year % 4 == 0) {
                            if (Perpetual_calendar.time.year % 400 == 0)
                                Perpetual_calendar.leap_year = 1;
                            else if (Perpetual_calendar.time.year % 100 == 0)
                                Perpetual_calendar.leap_year = 0;
                            else
                                Perpetual_calendar.leap_year = 1;
                        }
                    }
                }
            }
        }

    }
}
