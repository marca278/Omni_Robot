//
// Created by marc on 04.12.22.
//
#include "Factory.h"
#include "tests.h"

using namespace Neo;

static IOmniDrive* initOmniDriveSubsystem() {
        
    IOmniDrive* omniDrive = Factory::createDriveSubsystem();

    return omniDrive;
}

static Turnable_HCSR04* initOmniFrontSensorSubsystem() {
        
    Turnable_HCSR04* frontSensor = Factory::createFrontDistanceSensor();

    return frontSensor;
}

extern "C" int omniApp() {
    IOmniDrive* drive = initOmniDriveSubsystem();
    ITurnableDistanceSensor* sensor = initOmniFrontSensorSubsystem();
    
    runTests(*drive, *sensor);


    return 0;
}

