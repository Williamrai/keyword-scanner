//
// Created by willi on 4/5/2020.
//

#ifndef C___PRACTICE_TEXTMANIPULATOR_H
#define C___PRACTICE_TEXTMANIPULATOR_H

#include <string>
#include <regex>
#include <vector>
#include <algorithm>
#include <map>

class TextManipulator{
private:
    std::string fileName;
    void sort(std::map<std::string, int>& MapType,std::vector<std::pair<std::string,int>>& vec);
    void sortWithoutCopyingFromMap(std::vector<std::pair<std::string,int>>& vec);
    void displayAll(std::map<std::string, int>& map,std::vector<std::pair<std::string,int>>& vec,int exportCode);
    void displaySpecific(std::map<std::string, int>& map);
    bool canBeOpened();//validator functions
    void ask();//ask user prompts

public:
    //constructors
    TextManipulator();

    //acessing functions
    std::vector<std::string> readAFile();
    std::string getFileName();

    //working functions
    bool setFileName(std::string fileName);
    void writeOnFile(std::vector<std::pair<std::string,int>>& vec,std::string fileName);
    void calcFrequenciesOfWords(std::vector<std::string> readData,int index);
    std::vector<std::string>  cancelDelims(std::string word, std::regex reg);

    //Destructor
    ~TextManipulator();
};
#endif //C___PRACTICE_TEXTMANIPULATOR_H

