
#include "../libs/chesto/src/TextElement.hpp"
#include "../libs/chesto/src/Button.hpp"

class TestScreen : public Element
{
    public:
        TestScreen();
        ~TestScreen();
        
        bool process(InputEvents *event);
        void render(Element *parent);
        
    private:
        TextElement testText;
        Button btnQuit;
};