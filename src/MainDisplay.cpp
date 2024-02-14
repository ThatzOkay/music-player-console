#include "MainDisplay.h"
#include "Utils.h"
#include "SetupScreen.h"

#if defined(__WIIU__)
#include <whb/log.h>
#endif

#ifndef __VITA__
using namespace std::string_literals; // for ""s
#endif

MainDisplay::MainDisplay()
{
    #if defined(__WIIU__)
    WHBLogPrintf("init of MainDisplay");
    #endif

    //setScreenResolution(960, 544);
}

MainDisplay::~MainDisplay()
{
}

void MainDisplay::beginInitialLoad()
{
    checkConfigCreated();
}

void MainDisplay::render(Element *parent)
{
    if (showingSplash)
        renderedSplash = true;

    renderBackground(true);
    RootDisplay::render(parent);
}

bool MainDisplay::process(InputEvents *event)
{
    if (!RootDisplay::subscreen && showingSplash && renderedSplash && event->noop)
    {   
        showingSplash = false;

        beginInitialLoad();

        if (!configCreated) {
            RootDisplay::switchSubscreen(new SetupScreen());
            return true;
        }

        return true;
    }

    return RootDisplay::process(event);
}

void MainDisplay::checkConfigCreated()
{
    if (fileExists(ROOT_PATH "provider.json"))
    {
        this->configCreated = true;   
    }
}