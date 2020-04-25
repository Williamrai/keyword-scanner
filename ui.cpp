//
// Created by willi on 4/24/2020.
//
#include <iostream>
#include "ui.h"
#include "textmanipulator.h"

TextManipulator textManipulator;

ConsoleUI::ConsoleUI(){}//default constructor

ConsoleUI::ConsoleUI(std::string fileName) { //overloading constructor
    this->fileName = fileName;
}//parameter constructor


void ConsoleUI::welcomeBanner() {
    std::cout << "**************************WELCOME******************************************\n";
    std::cout << "***************************************************************************\n";
    std::cout << "--To use this program.--\n"
                 "--First Enter the name of the file you want to read along with the extension.--\n";
    std::cout << "--Example: filename.txt or Filename.csv.--\n"<< std::endl;

}//welcomeBanner()


void ConsoleUI::inputPrompt() {
    int again = 1;
    do{
        std::cout << "Enter the name of the file : ";
        std::cin >> fileName;
        if(textManipulator.setFileName(fileName)){
            showMenu();
        } else{
            std::cout << "file could not be opened. Enter the correct name.  " << std::endl;
            again = 0;
        }
    }while (again == 0);



}//inputPrompt()


void ConsoleUI::showMenu() {
    int c = 0;
    int optionNo;

    std::cout << std::endl;

    do{
        std::cout << "                       Choose one option from the menu                     \n";
        std::cout << "**************************************************************************\n";
        std::cout << "        1 - Search for keywords.\n";
        std::cout << "        2 - Display all keywords\n";
        std::cout << "        3 - Export keywords to excel file\n";
        std::cout << "        4 - Exit.\n";
        std::cout << "**************************************************************************\n";

        std::cout << "Enter your choice and press return: ";
        std::cin >> optionNo;

        c = workingMenu(optionNo);

    }while(c!=0);

}//showMenu()


int ConsoleUI::workingMenu(int menuIndex) {
    int quit;

    switch (menuIndex){
        case 1:
            //std::cout << menuIndex << std::endl;
            textManipulator.calcFrequenciesOfWords(textManipulator.readAFile(),menuIndex);
            quit = 1;
            break;
        case 2:
            //std::cout << menuIndex << std::endl;
            textManipulator.calcFrequenciesOfWords(textManipulator.readAFile(),menuIndex);
            quit = 1;
            break;
        case 3:
            //std::cout << menuIndex << std::endl;
            textManipulator.calcFrequenciesOfWords(textManipulator.readAFile(),menuIndex);
            quit = 1;
            break;
        case 4:
            //std::cout << menuIndex << std::endl;
            quit = 0;
            break;
    }

    //std::cout << "value : " << quit << std::endl;
    return quit;
}//working menu


void ConsoleUI::helpInfo() {
    std::cout << "Help Info " << std::endl;
}


ConsoleUI::~ConsoleUI() {}//default destructor

