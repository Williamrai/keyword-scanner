//
// Created by willi on 4/24/2020.
//

#ifndef C___PRACTICE_UI_H
#define C___PRACTICE_UI_H

class ConsoleUI{
public:
    //constructor
    ConsoleUI();
    ConsoleUI(std::string fileName);

    //interactive options
    void welcomeBanner();
    void inputPrompt();
    void showMenu();
    void helpInfo();

    //accesing functions
    void getInput(int input);

    //destructor
    ~ConsoleUI();
private:
    std::string fileName;
    int workingMenu(int menuIndex);

};

#endif //C___PRACTICE_UI_H
