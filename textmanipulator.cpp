#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <iomanip>
#include "textmanipulator.h"
#include "json.hpp"
#include <vector>
#include <algorithm>


using json = nlohmann::json;

TextManipulator::TextManipulator() {}

TextManipulator::TextManipulator(std::string fileName) {
    this->fileName = fileName;
}

//set file Name
void TextManipulator::setFileName(std::string fileName) {
    std::string location = "C:\\c++ codes\\";
    this->fileName = location + fileName;
    std::cout << this->fileName << std::endl;
}

//write data to file
void TextManipulator::writeOnFile(std::map<int, std::vector<std::string>> vMap) {
    std::string location = "C:\\c++ codes\\local.csv";
    std::string line;
    std::ofstream out;
    out.open(location);
    std::map<int, std::vector<std::string>>::iterator it;

    if (!out) {
        std::cout << fileName << " could not be opened." << std::endl;
    }

    for (it = vMap.begin(); it != vMap.end(); it++) {
        out << it->first << ", ";
        for (auto x = it->second.begin(); x != it->second.end(); x++) {
            out << *x << ",";
        }
        out << std::endl;
    }
    out.close();
}

//read data from file
std::vector<std::string> TextManipulator::readAFile() {
    std::ifstream iRead;
    std::string rS;
    iRead.open(fileName);
    std::string s;
    std::vector<std::string> values;
    std::string newString;
    std::string formattedString;

    if (!iRead) {
        std::cout << fileName << "could not be opened " << std::endl;
    }

    //reading and formatting process
    //step 1
    //where i am,
    while (getline(iRead, rS, ',')) {
        //std::cout << rS << std::endl;
        //s += rS;
        std::stringstream ss(rS);
        //step 2
        while (ss >> newString) {
            //where
//            std::cout << "before: " + newString << std::endl;
//            std::cout << "before size: " << newString.size()<< std::endl;
            //inspection
            for (int i = 0; i < newString.length(); i++) { //step 3
                if ((newString[i] >= 65 && newString[i] <= 122) ) { //step 4 remove unwanted characters
                    // remove char at position i
                    //newString.erase(0 + i);
//                    if(newString[i] == 47){
//                        newString[i] = '\n';
//                    }
                    formattedString += newString[i];
                }
            }

            //std::cout << "after : " + newString << std::endl;
            //after inspection
           //std::cout << "The formatted string: " << formattedString << std::endl;
           transform(formattedString.begin(), formattedString.end(), formattedString.begin(), ::tolower);

            if (!formattedString.empty()) //step 5
                //to lowercase letters
                //transform(formattedString.begin(),formattedString.end(),formattedString.begin(),::tolower);
                values.push_back(formattedString);
              formattedString.clear();
        }
    }

    //std::cout << "The read data is : " << s << std::endl;

//    for (int i = 0; i < values.size(); i++) {
//        std::cout << values[i] << std::endl;
//    }

    iRead.close();
    return values;
}

//Text Manipulator
typedef std::map<std::string, int> MapType;
typedef std::map<int, std::string> RepMapType;
typedef std::map<int, std::vector<std::string>> VecMapType;

void TextManipulator::calcFrequenciesOfWords(std::vector<std::string> data) {
    MapType m;
    RepMapType rMap;
    VecMapType vMap;
    std::vector<std::string> vKeywords;
    std::string keyword;

    //numberContainer.push_back(0);

    //values.push_back(0);

//    std::stringstream check(data[0]);
//    std::string words;
//    std::stringstream sToInt;
//    std::string convW;
//    std::string processWords;

//    while (check >> words) {
//        ++m[words];
//    }

    //processing recurring words into map with key
    std::vector<std::string>::iterator it;
    //data = ["asd","asd","hello","asd","hi"]
    //data[0] = asd
    for (it = data.begin(); it != data.end(); it++) {
        ++m[*it];
        //map string as a key and int as value
        //++m
        //m[asd] = m[asd] + value;
    }
    //Display
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "words " << std::setw(25) << " Frequencies" << std::endl;
    for (MapType::iterator it = m.begin(); it != m.end(); ++it) {
        std::cout << std::left << std::setw(12) << it->first
                  << std::right << std::setw(13) << it->second
                  << '\n';
    }

    //map[java] = 18

    //do this first
    //then ask a prompt to continue or not
    std::string ask;
    do{
        //Enter keywords to find
        std::cout << "Enter keywords you want to search. To exit enter -1" << std::endl;

        while (getline(std::cin, keyword) && keyword != "-1") {
            if (!keyword.empty()) {
                //std::cout << "entered " << keyword << " tp vector " << " ----- ";
                vKeywords.push_back(keyword);
            }
        }

        std::vector<std::string>::iterator kIt;
        MapType::iterator fIt;
        //Find the keyword in the map and
        // display the total occurance of that keyword
        for (kIt = vKeywords.begin(); kIt != vKeywords.end(); kIt++) {
            fIt = m.find(*kIt);
            if(fIt != m.end()){
                std::cout << std::left << std::setw(12) << fIt->first
                          << std::right << std::setw(13) << fIt->second
                          << "\n";
                std::cout << "------------------------------------------------";
                std::cout << std::endl;
            } else{
                std::cout << std::left << std::setw(12) << *kIt
                          << std::right << std::setw(13) << "keyword not found. check for spelling error!!"
                          << "\n";
                std::cout << "------------------------------------------------";
                std::cout << std::endl;
            }
        }

        std::cout <<"Want to search for something else? If yes type yes or y. otherwise enter any key to exit"  << std::endl;
        std::cin >> ask;
        transform(ask.begin(), ask.end(), ask.begin(), ::tolower); //to lowercase
    }while (ask == "yes" || ask == "y");



/*    //Swapping the key and values of the map
    MapType::iterator checkIt = m.begin();
    for(checkIt; checkIt!= m.end(); checkIt++){
        rMap[checkIt->second] += "\n" + checkIt->first;
    }

    for(RepMapType::iterator it = rMap.begin();it!=rMap.end();it++){
        std::cout << it->first << std::endl;
        std::cout << it->second << std::endl;
    }


    RepMapType::iterator  rIt = rMap.begin();
    std::string vString;
    std::string vNStr;
    std::vector<std::string> values;
    int numberCounter;

    //store in a map
    numberCounter = rIt->first;
    for(rIt; rIt!=rMap.end();rIt++){
        vString = rIt->second;
        //std::cout <<"number counter : " << numberCounter << std::endl;
        //std::cout <<"map key counter : " << rIt->first << std::endl;
        //std::cout << vString.size() << std::endl;
        std::stringstream vSS(vString);

        while (vSS >> vNStr){
            if(numberCounter!=rIt->first){
                values.clear();
                numberCounter = rIt->first;
            }
                values.push_back(vNStr);
                vMap[rIt->first] =  values;
        }
    }

    writeOnFile(vMap);*/

//    for(vIt=vMap.begin();vIt!=vMap.end();vIt++){
//        std::cout << "occurance : " << vIt->first << std::endl;
//       std::cout << "size of string : " << vIt->second.size() << std::endl;
//        for(auto i = vIt->second.begin(); i!=vIt->second.end();i++){
//            std::cout << *i << std::endl;
//        }
//    }

//    for( vIt=vMap.begin();vIt!=vMap.end();vIt++ ){
//        std::cout << vIt-> first << ", ";
//        for(auto x = vIt->second.begin();x!=vIt->second.end();x++){
//            std::cout << *x << ",";
//        }
//        std::cout << std::endl;
//    }


//    for(checkIt; checkIt!=m.end();checkIt++){
//        values.push_back(checkIt->first);
//        rMap[checkIt->second] = values;
//    }
//
//    for(RepMapType::iterator it = rMap.begin(); it!=rMap.end();it++){
//        std::cout << it->first <<  std::endl;
//        auto x = it->second.begin();
//        for(x; x!= it->second.end(); x++ ){
//            std::cout << " ";
//            std::cout << *x << std::endl;
//        }
//    }


//    //json
//    json j_map(m);
//    std::string s = j_map.dump();
//    std::cout << "map converted to json " << std::endl;
//    std::cout << s;






}

void TextManipulator::goToLowerCase(std::string formattedString) {
    transform(formattedString.begin(), formattedString.end(), formattedString.begin(), ::tolower);

}

void TextManipulator::changeAllToLowerCase() {}

TextManipulator::~TextManipulator() {}