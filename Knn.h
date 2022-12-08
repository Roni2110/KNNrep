//
// Created by danas on 07/12/2022.
//

#ifndef KNNREP_KNN_H
#define KNNREP_KNN_H
#include "DistanceClass.h"
#include <string>
using namespace std;

class Knn {

private:
    int k;
    string disName;
    string file;
    vector<double> vecInput;
    vector<double> doubleVec;
    vector<string> stringVec;
    vector<pair<double,string>> resVec;
    DistanceClass distanceClass;

public:
    Knn(int k, string file, string disName, vector<double> v1);
    void uploadFiles(string stringPath);
    void pushingToPairs(vector<double> d1, vector<string> s1);
};
#endif //KNNREP_KNN_H