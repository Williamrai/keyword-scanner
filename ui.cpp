//
// Created by willi on 4/24/2020.
//
#include <iostream>
#include "ui.h"
#include <iomanip>
#include "textmanipulator.h"

TextManipulator textManipulator; // instance of TextManipulator

ConsoleUI::ConsoleUI(){}//default constructor

ConsoleUI::ConsoleUI(std::string fileName) { //overloading constructor
    this->fileName = fileName;
}//parameter constructor

//welcome banner
void ConsoleUI::welcomeBanner() {
    std::cout  << "----------------------------------------------------------------------------------------------------------------------\n";
	std::cout  << "                                                 WELCOME                                                               \n";
	std::cout  << "                                             TO KEYWORD PARSER                                                         \n";
	std::cout  << "                                       -By Tech Scholars Spring 2020                                                   \n";
	std::cout  << "------------------------------------------------------------------------------------------------------------------------\n";
	
}//welcomeBanner()

//instruction banner
void ConsoleUI::instructionBanner(){
	std::cout  << "   Instructions:- \n"; 
	std::cout  << "                                            --To use this program.--\n"
                  "                --First Enter the name of the file you want to read along with the extension.--\n";
    std::cout  << "                --Example: filename.txt or Filename.csv.--\n"<< std::endl;
    std::cout  << "------------------------------------------------------------------------------------------------------------------------\n";
	
}//instructionBanner();

//input prompt
void ConsoleUI::inputPrompt() {
    int again = 1;
    do{
        std::cout << "                 -Enter the name of the file to read : ";
        std::cin >> fileName;
        if(textManipulator.setFileName(fileName)){
            showMenu();
        } else{
            std::cout << "file could not be opened. Enter the correct name.  " << std::endl;
            again = 0;
        }
    }while (again == 0);



}//inputPrompt()

//menu ui
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
        std::cout << "        4 - Change fileName \n";
        std::cout << "        5 - Clear Screen \n";
        std::cout << "        6 - Exit.\n";
        std::cout << "**************************************************************************\n";

        std::cout << "Enter your choice and press return: ";
        std::cin >> optionNo;

        c = workingMenu(optionNo);

    }while(c!=0);

}//showMenu()

// menu core code
int ConsoleUI::workingMenu(int menuIndex) {
    int quit;

    switch (menuIndex){
        case 1:
            //search for keywords
            textManipulator.calcFrequenciesOfWords(textManipulator.readAFile(),menuIndex);
            quit = 1;
            break;
        case 2:
            //Display all keywords
            textManipulator.calcFrequenciesOfWords(textManipulator.readAFile(),menuIndex);
            quit = 1;
            break;
        case 3:
            //Export keywords to excel file
            textManipulator.calcFrequenciesOfWords(textManipulator.readAFile(),menuIndex);
            quit = 1;
            break;
        case 4:
            //Change filename
            std::cout << "Enter the name of the file : ";
            std::cin >> fileName;
            textManipulator.setFileName(fileName);
            showMenu();
            break;
        case 5:
            //quit
            system("clear");
            welcomeBanner();
            showMenu();
			quit = 0;
            break;
		
		case 6:
            //quit
            quit = 0;
            exit(0);
            break;
    }

    return quit;
}//working menu


//help info method
void ConsoleUI::helpInfo() {
    std::cout << "Help Info " << std::endl;
}//end of help info method

//run
void ConsoleUI::run(){
    inputPrompt();
}//end of run

ConsoleUI::~ConsoleUI() {}//default destructor


