#include <iostream>
#include "ui.h"

int main(){

    ConsoleUI ui;
    ui.welcomeBanner();
    ui.instructionBanner();
    ui.run();

    return 0;
}


