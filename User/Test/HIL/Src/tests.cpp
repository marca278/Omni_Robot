#include"tests.h"
#include "stm32g4xx_hal.h"
#include "usart.h"
#include "tim.h"

#include <cstdio>

using namespace Neo;

static void driveTest(IOmniDrive& drive);

static void motor_left_front_forward(IOmniDrive &drive);
static void drive_forward(IOmniDrive &drive);
static void drive_back(IOmniDrive &drive);

static void sonicSensorTest(ITurnableDistanceSensor& sensor);
static void sonicSensorAutoTest(ITurnableDistanceSensor& sensor);

int runTests(IOmniDrive& drive, ITurnableDistanceSensor& sensor)
{
    uint8_t data[10];

    while (true)
    {
        HAL_UART_Receive(&hlpuart1, data, 3, HAL_MAX_DELAY);

        switch ((char)data[0])
        {
        case 'd':
            driveTest(drive);
            break;
        case 's':
            sonicSensorTest(sensor);
            break;
        case 'a':
            sonicSensorAutoTest(sensor);
            break;    
        default:
            break;
        }
    }

    return 0;
}

static void driveTest(IOmniDrive& drive)
{
    drive_forward(drive);
    HAL_Delay(2000);
    // drive->activeBreak();
    // HAL_Delay(1000);
    // drive_back(*drive);
    // HAL_Delay(2000);

    drive.activeBreak();
    HAL_Delay(1000);
    HAL_UART_Transmit(&hlpuart1, (const uint8_t *)("Left Front\n\r"), sizeof("Left Front\n\r"), HAL_MAX_DELAY);
    drive.move(Direction::forward, 0.2, Direction::forward, 0, Direction::forward, 0, Direction::forward, 0);
    HAL_Delay(3000);
    drive.activeBreak();
    HAL_Delay(1000);
    HAL_UART_Transmit(&hlpuart1, (const uint8_t *)("Left Rear\n\r"), sizeof("Left Rear\n\r"), HAL_MAX_DELAY);
    drive.move(Direction::forward, 0.0, Direction::forward, 0.2, Direction::forward, 0, Direction::forward, 0);
    HAL_Delay(3000);
    drive.activeBreak();
    HAL_Delay(1000);
    HAL_UART_Transmit(&hlpuart1, (const uint8_t *)("Right Front\n\r"), sizeof("Right Front\n\r"), HAL_MAX_DELAY);
    drive.move(Direction::forward, 0.0, Direction::forward, 0, Direction::forward, 0.2, Direction::forward, 0);
    HAL_Delay(3000);
    drive.activeBreak();
    HAL_Delay(1000);
    HAL_UART_Transmit(&hlpuart1, (const uint8_t *)("Right Rear\n\r"), sizeof("Right Rear\n\r"), HAL_MAX_DELAY);
    drive.move(Direction::forward, 0.0, Direction::forward, 0, Direction::forward, 0, Direction::forward, 0.2);
    HAL_Delay(3000);
    drive.activeBreak();
    HAL_Delay(1000);
    drive.stop();
}

static void motor_left_front_forward(IOmniDrive &drive)
{
    drive.move(Direction::forward, 0.2, Direction::forward, 0, Direction::forward, 0, Direction::forward, 0);
}

static void drive_forward(IOmniDrive &drive)
{
    drive.setSpeed(0.5);
    drive.moveForward();
}

static void drive_back(IOmniDrive &drive)
{
    drive.setSpeed(0.5);
    drive.moveBack();
}

static void sonicSensorTest(ITurnableDistanceSensor& sensor)
{
    sensor.startMeasuring();
    
    sensor.pan(0);
    HAL_Delay(3000);
    sensor.pan(90);
    HAL_Delay(3000);
    sensor.pan(180);
    HAL_Delay(3000);

    for (int i = 0; i< 10; i++)
    {
        HAL_Delay(1000);
        float distance = sensor.getDistance();
        sensor.pan(i*20);
        printf("Sonic Measure %.1f\r\n", distance);
    }
}

static void sonicSensorAutoTest(ITurnableDistanceSensor& sensor)
{
    sensor.startAutoMeasuring();
    

    for (int i = 0; i< 20; i++)
    {
        HAL_Delay(1000);
        float distance = sensor.getDistance();
        printf("Sonic Measure %.1f\r\n", distance);
    }
}