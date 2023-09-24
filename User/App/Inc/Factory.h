#ifndef FACTORY_H
#define FACTORY_H

#include "IOmniDrive.h"
#include "HC_SR04.h"
#include "Turnable_HCSR04.h"

namespace Neo
{

    /// @brief Create Omni Subsystems
    class Factory
    {
    public:
        /// @brief
        /// @return
        static IOmniDrive *createDriveSubsystem();

        static Turnable_HCSR04 *createFrontDistanceSensor();
    };

} // namespace Neo

#endif