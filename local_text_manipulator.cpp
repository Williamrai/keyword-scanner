//
// Created by willi on 4/16/2020.
//

#include <iostream>
#include "local_text_manipulator.h"
#include <fstream>
#include <map>
#include <vector>
#include <sstream>


LocalTextManip::LocalTextManip(){
    this -> localFileName = "C:\\c++ codes\\local.csv";
}

typedef std::map<int, std::vector<std::string>> MAP;

void LocalTextManip::readFile() {
    std::ifstream open(localFileName);
    std::string datas;
    std::string ndatas;
    int number = 0;
    int numPasser = 0;
    MAP m;
    std::vector<std::string> values;


    while(getline(open,datas,',')){
        std::stringstream ss(datas);
            while(ss >> ndatas ){
                //std::cout << ndatas << std::endl;
                if(std::stringstream(ndatas) >> number){ //check if there is a number
                    //std::cout << number << std::endl
                    numPasser = number;
                    if(numPasser > 1){
                        values.clear();
                    }
                }else{
                    //std::cout << numPasser << std::endl;
                    values.push_back(ndatas);
                    m[numPasser] = values;
                }
            }
    }

    workOnFile(m);
}

void LocalTextManip::workOnFile(MAP m) {
    MAP::iterator it = m.begin();

    for(it;it!=m.end();it++){
        std::cout << it->first << std::endl;
        for(auto x = it->second.begin(); x!=it->second.end();x++){
            std::cout << "----------------";
            std::cout<< *x << std::endl;
        }
    }
}