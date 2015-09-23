#include "menu.hpp"

int main()
{
    Menu menu;

    while(!menu.isEnd()){
        menu.promptUser();
    }

    return 0;
}
