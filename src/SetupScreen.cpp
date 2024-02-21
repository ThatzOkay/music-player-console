#include "../libs/chesto/src/Constraint.hpp"
#include "../libs/chesto/src/Container.hpp"
#include "../libs/chesto/src/RootDisplay.hpp"

#include "SetupScreen.h"
#include "MainDisplay.h"
#include "ThemeManager.h"
#include "main.h"

SetupScreen::SetupScreen()
    : icon(RAMFS "res/icon.png")
    , title("Setup", 50 - 25)
    , text((std::string("The screen resolution is ") + std::to_string(MainDisplay::screenWidth) + "x" + std::to_string(SCREEN_HEIGHT)).c_str(), 40)
    , btnQuit("Quit", SELECT_BUTTON, false, 15)
{ 

    Container* logoCon = new Container(ROW_LAYOUT, 10);
	icon.resize(35, 35);
	logoCon->add(&icon);
	logoCon->add(&title);

    Container* underLogoCon = new Container(ROW_LAYOUT, 10);

    underLogoCon->add(&icon);
    underLogoCon->add(&title);

    // constraints
    logoCon->constrain(ALIGN_TOP | ALIGN_CENTER_HORIZONTAL, 10);
    underLogoCon->constrain(ALIGN_BOTTOM | ALIGN_CENTER_HORIZONTAL, 100);
    text.constrain(ALIGN_CENTER_BOTH);
    btnQuit.constrain(ALIGN_LEFT | ALIGN_BOTTOM, 90);

	btnQuit.action = quit;

	super::append(logoCon);
    super::append(&text);
	super::append(underLogoCon);
    super::append(&btnQuit);
}

SetupScreen::~SetupScreen()
{
}

void SetupScreen::render(Element *parent)
{
    super::render(parent);
}

bool SetupScreen::process(InputEvents* events) {
    
    return super::process(events);
}