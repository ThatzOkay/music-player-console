#include "../libs/chesto/src/TextElement.hpp"
#include "../libs/chesto/src/Button.hpp"

class SetupScreen : public Element
{
public:
    SetupScreen();
    ~SetupScreen();

    void render(Element *parent) override;
    bool process(InputEvents *event) override;

private:
    ImageElement icon;
    TextElement title;
    TextElement text;
    Button btnQuit;
};