#include <iostream>
#include "textmanipulator.h"
#include <string>
#include "json.hpp"
#include <fstream>
#include "local_text_manipulator.h"

using json = nlohmann::json;

using namespace std;


int main(){
//    string localFileName = "C:\\c++ codes\\local.csv";
//    ifstream isOpen(localFileName);
//    if (isOpen) {
//        string comment = "no need to open the file. The file is already in the cache";
//        cout << comment << endl;
//
//        LocalTextManip localTextManip;
//        localTextManip.readFile();
//    } else{

        string fileName;
        cout << "Enter filename "<< endl;
        cin >> fileName;

        TextManipulator textManipulator;
        textManipulator.setFileName(fileName);
        textManipulator.calcFrequenciesOfWords(textManipulator.readAFile());
        //textManipulator.readAFile();
    //}

    //isOpen.close();
    return 0;
}

