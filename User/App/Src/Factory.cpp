#include "Factory.h"

#include "CubeGpio.h"
#include "CubePwmChannel.h"
#include "CubeInputCapture.h"
#include "L298N.h"
#include "OmniDrive.h"
#include "main.h"
#include "tim.h"
#include "Servo.h"
#include "Turnable_HCSR04.h"

namespace Neo
{

    IOmniDrive *Factory::createDriveSubsystem()
    {
        CubeGpio *leftFrontSetForward = new CubeGpio(SetLeftFrontForward_GPIO_Port, SetLeftFrontForward_Pin);
        CubeGpio *leftFrontSetBack = new CubeGpio(SetLeftFrontBack_GPIO_Port, SetLeftFrontBack_Pin);
        CubeGpio *leftRearSetForward = new CubeGpio(SetLeftRearForward_GPIO_Port, SetLeftRearForward_Pin);
        CubeGpio *leftRearSetBack = new CubeGpio(SetLeftRearBack_GPIO_Port, SetLeftRearBack_Pin);

        CubeGpio *rightFrontSetForward = new CubeGpio(SetRightFrontForward_GPIO_Port, SetRightFrontForward_Pin);
        CubeGpio *rightFrontSetBack = new CubeGpio(SetRightFrontBack_GPIO_Port, SetRightFrontBack_Pin);
        CubeGpio *rightRearSetForward = new CubeGpio(SetRightRearForward_GPIO_Port, SetRightRearForward_Pin);
        CubeGpio *rightRearSetBack = new CubeGpio(SetRightRearBack_GPIO_Port, SetRightRearBack_Pin);

        CubeTimer *drivePwmTimer = new CubeTimer(htim2);
        CubePwmChannel *pwmLeftFront = new CubePwmChannel(*drivePwmTimer, CubeTimer::ChannelNumber::Channel_3);
        CubePwmChannel *pwmLeftRear = new CubePwmChannel(*drivePwmTimer, CubeTimer::ChannelNumber::Channel_4);
        CubePwmChannel *pwmRightFront = new CubePwmChannel(*drivePwmTimer, CubeTimer::ChannelNumber::Channel_1);
        CubePwmChannel *pwmRightRear = new CubePwmChannel(*drivePwmTimer, CubeTimer::ChannelNumber::Channel_2);

        L298N *leftFrontMotor = L298N::factoryNew(*pwmLeftFront, *leftFrontSetForward, *leftFrontSetBack);
        L298N *leftRearMotor = L298N::factoryNew(*pwmLeftRear, *leftRearSetForward, *leftRearSetBack);
        L298N *rightFrontMotor = L298N::factoryNew(*pwmRightFront, *rightFrontSetForward, *rightFrontSetBack);
        L298N *rightRearMotor = L298N::factoryNew(*pwmRightRear, *rightRearSetForward, *rightRearSetBack);

        OmniDrive *drive = new OmniDrive(*leftRearMotor, *leftFrontMotor, *rightRearMotor, *rightFrontMotor);

        return drive;
    }

    Turnable_HCSR04 *Factory::createFrontDistanceSensor()
    {
        CubeTimer *timer = new CubeTimer(htim1);
        CubeTimer *servoTimer = new CubeTimer(htim3);

        CubePwmChannel *triggerPwm = new CubePwmChannel(*timer, CubeTimer::ChannelNumber::Channel_3);

        CubeInputCapture *echoChannel = new CubeInputCapture(*timer, CubeTimer::ChannelNumber::Channel_4);

        CubePwmChannel *servoPwm = new CubePwmChannel(*servoTimer, CubeTimer::ChannelNumber::Channel_1);

        Servo *pan = Servo::factoryNew(*servoPwm);
        pan->setLowerLimit(10);
        pan->setUpperLimit(170);

        // HC_SR04* frontSensor = new HC_SR04(*echoChannel, *triggerPwm);
        Turnable_HCSR04 *frontSensor = new Turnable_HCSR04(*echoChannel, *triggerPwm, *pan);

        return frontSensor;
    }

} // namespace Neo
