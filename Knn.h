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
public:
    Knn(int k, string file, string disName);
};
#endif //KNNREP_KNN_H
