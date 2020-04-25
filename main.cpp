#include <iostream>
#include "textmanipulator.h"
#include <string>
#include "json.hpp"
#include "ui.h"
#include <fstream>
#include "local_text_manipulator.h"

using json = nlohmann::json;

using namespace std;


int main(){

    ConsoleUI ui;
    ui.welcomeBanner();
    ui.inputPrompt();

    return 0;
}

