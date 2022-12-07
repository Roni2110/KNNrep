//
// Created by danas on 07/12/2022.
//

#ifndef KNNREP_DISTANCECLASS_H
#define KNNREP_DISTANCECLASS_H


#include <vector>

class DistanceClass{
public:
    static void getEucDis(std::vector <double> v1, std::vector <double> v2);
    static void getCanDis(std::vector <double> v1, std::vector <double> v2);
    static void getChebDis(std::vector<double> v1, std::vector<double> v2);
    static void getManDis(std::vector<double> v1, std::vector<double> v2);
    static void getMinkDis(std::vector<double> v1, std::vector<double> v2);
};


#endif //KNNREP_DISTANCECLASS_H
