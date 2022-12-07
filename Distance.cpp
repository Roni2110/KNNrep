#include <vector>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "Distance.h"

using namespace std;
int p = 2;

/**
 * this function calculate the euclidean distance between two vectors.
 * @param v1 - the first vector.
 * @param v2 - the second vector.
 */
void getEucDis(vector <double> v1, vector <double> v2){
    double sum = 0;
    int power = 2;
    int i;
    int value = 16;
    double res;
    for(i = 0; i < v1.size(); i++){
        sum+= pow(v1.at(i)-v2.at(i), power);
    }
    res = sqrt(sum);
    if(res != (int)res) {
        cout.precision(value);
        cout << fixed << res << endl;
    } else {
        value = 1;
        cout.precision(value);
        cout << fixed << res << endl;
    }
}

/**
 * this function calculate the canberra distance between two vectors.
 * @param v1 - the first vector.
 * @param v2 - the second vector.
 */
void getCanDis(vector <double> v1, vector <double> v2){
    double sum = 0;
    int i;
    int value = 16;
    for(i = 0; i < v1.size() ;i++){
        if(abs(v1.at(i))+abs(v2.at(i)) == 0) {
            cout << "Can not divide by zero!" << endl;
        }
        sum += (abs(v1.at(i)-v2.at(i))/(abs(v1.at(i))+abs(v2.at(i))));
    }
    if(sum != (int)sum) {
        cout.precision(value);
        cout << fixed << sum << endl;
    } else {
        value = 1;
        cout.precision(value);
        cout << fixed << sum << endl;
    }
}

/**
 * this function calculate the chebyshev distance between two vectors.
 * @param v1 - the first vector.
 * @param v2 - the second vector.
 */
void getChebDis(vector<double> v1, vector<double> v2) {
    int i;
    int value = 16;
    double max = abs(v1.at(0) - v2.at(0));
    for(i = 1; i < v1.size(); i++) {
        if(abs(v1.at(i) - v2.at(i)) > max) {
            max = abs(v1.at(i) - v2.at(i));
        }
    }
    if(max != (int)max) {
        cout.precision(value);
        cout << fixed << max << endl;
    } else {
        value = 1;
        cout.precision(value);
        cout << fixed << max << endl;
    }
}

/**
 * this function calculate the manhattan distance between two vectors.
 * @param v1 - the first vector.
 * @param v2 - the second vector.
 */
void getManDis(vector<double> v1, vector<double> v2) {
    double sum = 0;
    int i;
    int value = 16;
    for(i = 0; i < v1.size(); i++) {
        sum += abs((v1.at(i) - v2.at(i)));
    }
    if(sum != (int)sum) {
        cout.precision(value);
        cout << fixed << sum << endl;
    } else {
        value = 1;
        cout.precision(value);
        cout << fixed << sum << endl;
    }
}

/**
 * this function calculate the minkowski distance between two vectors.
 * @param v1 - the first vector.
 * @param v2 - the second vector.
 */
void getMinkDis(vector<double> v1, vector<double> v2) {
    double sum = 0;
    int i;
    int value = 16;
    double res;
    for(i = 0; i< v1.size(); i++) {
        sum += pow(abs(v1.at(i) - v2.at(i)),p);
    }
    res = pow(sum, (1.0/p));
    if(res != (int)res) {
        cout.precision(value);
        cout << fixed << res << endl;
    } else {
        value = 1;
        cout.precision(value);
        cout << fixed << res << endl;
    }
}