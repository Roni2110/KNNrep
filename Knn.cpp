
#include "Knn.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

Knn::Knn(int k, string file, string disName, vector<double> v1) {
    this->k = k;
    this->file = file;
    this->disName = disName;
    this->vecInput = v1;
}

void Knn::uploadFiles(std::string stringPath) {
    double res;
    string tempByLine, tempByComma;
    //file pointer
    fstream fin;
    //open an existing file
    fin.open(stringPath, ios::in);
    //getting data from file into two vectors
    while(fin >> tempByLine) {
        stringstream ss(tempByLine);
        vector<double> temp;
        while(getline(ss, tempByComma, ',')) {
            if(isalpha(tempByComma[0])) {
                stringVec.push_back(tempByComma);
            } else {
                temp.push_back(stod(tempByComma));
            }
        }
        if(temp.size() != vecInput.size()) {
            cout << "vectors are not in the same size!" << endl;
            exit(0);
        }
        //calling the distance method according to disName
        if(this->disName == "MAN") {
            res = DistanceClass::getManDis(temp,vecInput);
            doubleVec.push_back(res);
        } else if(this->disName == "AUC") {
            res = DistanceClass::getEucDis(temp, vecInput);
            doubleVec.push_back(res);
        } else if(this->disName == "CHB") {
            res = DistanceClass::getChebDis(temp, vecInput);
            doubleVec.push_back(res);
        } else if(this->disName == "CAN") {
            res = DistanceClass::getCanDis(temp, vecInput);
            doubleVec.push_back(res);
        } else {
            res = DistanceClass::getMinkDis(temp, vecInput);
            doubleVec.push_back(res);
        }
    }
    pushingToPairs(doubleVec, stringVec);
}

void Knn::pushingToPairs(vector<double> d1, vector<std::string> s1) {
    for(int i = 0; i < d1.size(); i++) {
        resVec.emplace_back(d1.at(i), s1.at(i));
    }
}

void Knn::sortingByDistance(vector<pair<double,string>> resVec){
    sort(resVec.begin(), resVec.end());
}

