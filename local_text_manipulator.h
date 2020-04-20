//
// Created by willi on 4/16/2020.
//

#ifndef C___PRACTICE_LOCAL_TEXT_MANIPULATOR_H
#define C___PRACTICE_LOCAL_TEXT_MANIPULATOR_H

#include <iostream>
#include <map>
#include <vector>

class LocalTextManip{
public:
    LocalTextManip();
    void readFile();
    void workOnFile(std::map<int, std::vector<std::string>> map);

private:
    std::string localFileName;

};

#endif //C___PRACTICE_LOCAL_TEXT_MANIPULATOR_H
