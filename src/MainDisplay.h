#include "../libs/chesto/src/RootDisplay.hpp"

#ifdef __WIIU__
#define PLATFORM "Wii U"
 #endif
 
class MainDisplay : public RootDisplay
{
    public:
        MainDisplay();
        ~MainDisplay();

        bool process(InputEvents* events);
        void render(Element* parent);

        void beginInitialLoad();
        void checkConfigCreated();
        
	    bool showingSplash = true;
	    bool renderedSplash = false;

        bool configCreated = false;      
};