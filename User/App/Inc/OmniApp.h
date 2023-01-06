//
// Created by marc on 04.12.22.
//

#ifndef OMNI_OMNIAPP_H
#define OMNI_OMNIAPP_H

#include "OmniDrive.h"

namespace Neo {

extern "C" int omniApp();

class OmniApp
{
private:
    OmniDrive* drive;

public:
    OmniApp(/* args */);
    ~OmniApp() = default;

private:
    void init();
};


} // Neo

#endif //OMNI_OMNIAPP_H
