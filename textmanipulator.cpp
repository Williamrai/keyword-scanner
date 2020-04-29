#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <iomanip>
#include "textmanipulator.h"
#include <vector>
#include <algorithm>

typedef std::map<std::string, int> MapType;
typedef std::pair<std::string,int> pair;

TextManipulator::TextManipulator() {} //default constructor


//set file Name
bool TextManipulator::setFileName(std::string fileName) {
    std::string location = "C:\\c++ codes\\";
    //std::cout << this->fileName << std::endl;
    this->fileName = location + fileName;
    return canBeOpened();
}//TextManipulator::setFileName(param)


bool TextManipulator::canBeOpened() {
    std::ifstream out;
    out.open(fileName);
    if (!out) {
        return false;
    }//end of if
    else{
        return true;
    }
}


//write data to file
void TextManipulator::writeOnFile(std::vector<std::pair<std::string, int> > &vec,std::string fileName) {
    std::string location = "C:\\c++ codes\\"+ fileName+".csv";
    std::string line;
    std::ofstream out;
    out.open(location);
    std::cout << fileName << " saved." << std::endl;
    //std::map<int, std::vector<std::string>>::iterator it;

    if (!out) {
        std::cout << fileName << " could not be opened." << std::endl;
    }//end of if

    for(auto const &pair:vec){
        out << pair.first << "," << pair.second <<"," << std::endl;
    }

    /*for (it = vMap.begin(); it != vMap.end(); it++) {
        out << it->first << ", ";
        for (auto x = it->second.begin(); x != it->second.end(); x++) {
            out << *x << ",";
        }
        out << std::endl;
    }*///end of for
    out.close();//closing the stream
}//TextManipulator::writeOnFile(param)


//read data from file
std::vector<std::string> TextManipulator::readAFile() {
    std::ifstream iRead;
    std::string rS; // variable to store a line read  from file
    std::string newString; // // string that handles a stream of single word
    std::string formattedString; // string that stores a nearly perfect formatted word
    std::vector<std::string> values; //a vector that stores each word

    iRead.open(fileName); //opening the file
    if (!iRead) {
        std::cout << fileName << "could not be opened " << std::endl;
    }
    //reading and formatting process
    //step 1
    while (getline(iRead, rS, ',')) {
        std::stringstream ss(rS);
        //step 2
        while (ss >> newString) {
            //inspection
            for (int i = 0; i < newString.length(); i++) { //step 3
                if ((newString[i] >= 65 && newString[i] <= 122) || (newString[i] == 43) ) { //step 4 remove unwanted characters
                    // remove char at position i
                    //newString.erase(0 + i);
//                    if(newString[i] == 47){
//                        newString[i] = '\n';
//                    }
                    formattedString += newString[i];
                }
            }//end of for loop

           transform(formattedString.begin(), formattedString.end(), formattedString.begin(), ::tolower);

            if (!formattedString.empty()) //step 5
                values.push_back(formattedString);
                formattedString.clear();
        }//end nested while loop
    }//end first while loop

    iRead.close();//closing the stream
    return values;
}//TextManipulator::readAFile(param)


//Calc Frequencies
//typedef std::map<int, std::string> RepMapType;
//typedef std::map<int, std::vector<std::string>> VecMapType;
void TextManipulator::calcFrequenciesOfWords(std::vector<std::string> data,int optionMenu) {
    MapType m;
    std::vector<pair> vec;
    //RepMapType rMap;
    //VecMapType vMap;

    //processing recurring words into map with key
    std::vector<std::string>::iterator it;
    for (it = data.begin(); it != data.end(); it++) {
        ++m[*it]; // increment if there is repetition of words
        //map string as a key and int as value
        //++m
        //m[asd] = m[asd] + value;
    }

    std::string saveFileName;
    if(optionMenu == 2){
        sort(m,vec);
        displayAll(m,vec,0);
        ask();

    } else if(optionMenu == 1){
        displaySpecific(m);
    } else{
        sort(m,vec);
        std::cout << "Enter a save file name" << std::endl;
        std::cin >> saveFileName;
        writeOnFile(vec,saveFileName);
    }
//    //json
//    json j_map(m);
//    std::string s = j_map.dump();
//    std::cout << "map converted to json " << std::endl;
//    std::cout << s;
}//TextManipulator::calcFrequenciesOfWords

//ask
void  TextManipulator::ask(){
    char c = ' ';
    std::cout << "To go back to menu press b, otherwise press any key to quit " << std::endl;
    std::cin >> c;
    if(c == 'b'){
        return;
    }else if(c == 'q'){
        exit(0);
    }
}//end ask()


//sort
void TextManipulator::sort(std::map<std::string, int>& map,std::vector<pair>& vec) {

    std::copy(map.begin(),
              map.end(),
              std::back_inserter<std::vector<pair>>(vec));

    std::sort(vec.begin(),
              vec.end(),
              [](const pair& l, const pair& r){
                    //std::cout << l.second << " :: " << r.second << std::endl;
                    //std::cout << l.first << " :: " << r.first << std::endl;
                        if(l.second != r.second)
                            return l.second > r.second;
                        return l.first > r.first;
    });

    // print the vector
    /*for (auto const &pair: vec) {
        std::cout << '{' << pair.first << "," << pair.second << '}' << '\n';
    }*/
}//TextManipulator::sort(param)


//sort without copying values from map
void TextManipulator::sortWithoutCopyingFromMap(std::vector<std::pair<std::string, int>> &vec) {
    std::sort(vec.begin(),
              vec.end(),
              [](const pair& l, const pair& r){
                  //std::cout << l.second << " :: " << r.second << std::endl;
                  //std::cout << l.first << " :: " << r.first << std::endl;
                  if(l.second != r.second)
                      return l.second > r.second;
                  return l.first > r.first;
              });
}//end


//display all in descending orders
//1 is code for exporting to csv
void TextManipulator::displayAll(std::map<std::string, int> &map, std::vector<std::pair<std::string, int> > &vec,int exportCode) {
    //Displaying with format
    std::cout <<"---------------------------------------------" << std::endl;
    std::cout << "words " << std::setw(25) << " Frequencies" << std::endl;
    for (auto const &pair: vec) {
        std::cout << std::left << std::setw(12) << pair.first
                  << std::right << std::setw(13) << pair.second
                  << '\n';
    }//end
    std::cout << std::endl;

    //write all keywords in the format of csv
//    if(exportCode == 1){
//        writeOnFile(vec,"test");
//    }

}//display


//display searched keywords
void TextManipulator::displaySpecific(std::map<std::string, int> &map) {
    std::vector<std::string> vKeywords;
    std::string keyword;
    std::vector<pair> vecForCsv;
    //do this first
    //then ask a prompt to continue or not
    std::string ask;
    do{
        //Enter keywords to find
        std::cout << "--Enter keywords you want to search. To exit enter -1--" << std::endl;

        while (getline(std::cin, keyword) && keyword != "-1") {
            if (!keyword.empty()) {
                //std::cout << "entered " << keyword << " tp vector " << " ----- ";
                vKeywords.push_back(keyword);
            }
        }//end of while loop

        std::vector<std::string>::iterator kIt;
        MapType::iterator fIt;

        //Find the keyword in the map and
        // display the total occurance of that keyword
        std::cout << "------------------------------------------------\n";
        std::cout << "words " << std::setw(25) << " Frequencies" << std::endl;
        for (kIt = vKeywords.begin(); kIt != vKeywords.end(); kIt++) {
            fIt = map.find(*kIt);
            if(fIt != map.end()){
                vecForCsv.push_back(std::make_pair(fIt->first,fIt->second));

            } else{
                std::cout << std::left << std::setw(12) << *kIt
                          << std::right << std::setw(13) << "keyword not found. check for spelling error!!"
                          << "\n";
            }
//
//                //std::cout << "------------------------------------------------";
               // std::cout << std::endl;
        }//end of for loop

        sortWithoutCopyingFromMap(vecForCsv);
        for(auto const &pair:vecForCsv){
            std::cout << std::left << std::setw(12) << pair.first
                      << std::right << std::setw(13) << pair.second
                      << "\n";
        }

        std::cout << std::endl;
        std::cout << std::endl;

        std::cout <<"--Want to search for something else? then press y.--\n"
                    "--Want to export this as csv. press x. Otherwise enter any other key to return to menu--"  << std::endl;
        std::cin >> ask;
        transform(ask.begin(), ask.end(), ask.begin(), ::tolower); //to lowercase

        if(ask == "x"){
            std::string saveFileName;
            std::cout << "Enter a save fileName" << std::endl;
            std::cin >> saveFileName;
            writeOnFile(vecForCsv,saveFileName);
        }

        if(ask == "y"){
            vKeywords.clear();
            vecForCsv.clear();
        }

    }while (ask == "yes" || ask == "y"); // end of do while
}

//destructor
TextManipulator::~TextManipulator() {}
