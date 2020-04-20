//
// Created by willi on 4/5/2020.
//

#ifndef C___PRACTICE_TEXTMANIPULATOR_H
#define C___PRACTICE_TEXTMANIPULATOR_H

#include <string>
#include <regex>
#include <vector>

class TextManipulator{
private:
    std::string fileName;
public:
    //constructors
    TextManipulator();
    TextManipulator(std::string fileName);

    //acessing functions
    std::vector<std::string> readAFile();
    std::string getFileName();

    //working functions
    void setFileName(std::string fileName);
    void writeOnFile(std::map<int,std::vector<std::string>> VecMapType);
    void changeAllToLowerCase();
    void calcFrequenciesOfWords(std::vector<std::string> readData);
    void goToLowerCase(std::string formattedString);
    std::vector<std::string>  cancelDelims(std::string word, std::regex reg);

    //Destructor
    ~TextManipulator();
};
#endif //C___PRACTICE_TEXTMANIPULATOR_H
