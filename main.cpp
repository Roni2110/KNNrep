#include <string>
#include <string.h>
#include <iostream>
#include <vector>
#include <float.h>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include "DistanceClass.h"
#include "Knn.h"

using namespace std;

/**
 * this function checks that the two vectors are at the same size.
 * also, this function checks that that the vectors are not empty - that their size is not 0.
 * if they have no values or they are not at the same size - it prints an error to the user.
 * @param vec1 - the first vector.
 * @param vec2 - the second vector.
 */
void checkingVec(vector<double>vec1, vector<double> vec2) {
    if(vec1.size() > vec2.size() || vec2.size() > vec1.size()) {
        cout << "The vectors are in different size!" << endl;
        exit(0);
    } else if (vec1.size() == 0) {
        cout << "No parameters added!" << endl;
        exit(0);
    } else {
        DistanceClass::getEucDis(vec1, vec2);
        DistanceClass::getManDis(vec1, vec2);
        DistanceClass::getChebDis(vec1, vec2);
        DistanceClass::getCanDis(vec1, vec2);
        DistanceClass::getMinkDis(vec1, vec2);
    }
}

/**
 * this function checks that all the values in the vectors are numbers. if not - it prints an error to the user.
 * @param str1 - the values of the first vector.
 * @param str2 - the values of the second vector.
 */
void checkingInput(string str1, string str2) {
    vector<double> v1;
    vector<double> v2;
    double num;
    stringstream stringstream1(str1);
    stringstream stringstream2(str2);
    while(stringstream1 >> num) {
        v1.push_back(num);
    }
    if(!stringstream1.eof()) {
        cout << "Input not valid!" << endl;
        exit(0);
    }
    while (stringstream2 >> num) {
        v2.push_back(num);
    }
    if(!stringstream2.eof()) {
        cout << "Input not valid!" << endl;
        exit(0);
    }
    checkingVec(v1,v2);
}

/**
 * this function checks that the arguments that the user entered to main are valids.
 * if not - it prints an error to the user.
 * @param argv - the arguments that the user entered.
 */
void checkingArgv(char *argv[]) {
    if((stoi(argv[1])<=0) ||
            ((strcmp(argv[3],"AUC")!=0) && (strcmp(argv[3],"MAN")!=0) && (strcmp(argv[3],"CHB")!=0)
            && (strcmp(argv[3],"CAN")!=0) && (strcmp(argv[3],"MIN")!=0))) {
        cout << "Input not valid!" << endl;
        exit(0);
    }
}

/**
 * this if the main function. this function calls the other functions and checks if the input does not cause an overflow.
 * @return 0 if code works.
 */
int main (int argc, char *argv[]) {
    checkingArgv(argv);
/*    cout << stoi(argv[1]) << endl;
    cout << argv[2] << endl;
    cout << argv[3] << endl;*/
    int k = stoi(argv[1]);
    string file = argv[2];
    string dis = argv[3];
/*    cout << k << endl;
    cout << file << endl;
    cout << dis << endl;*/
    string input1;
    string input2;
    getline(cin,input1);
    getline(cin, input2);
    if((double)input1.size() >= log(DBL_MAX) - 1) {
        input1 = input1.substr(0, sizeof(double ));
    }
    if((double)input2.size() >= log(DBL_MAX) - 1) {
        input2 = input2.substr(0, sizeof(double ));
    }
    checkingInput(input1,input2);
    Knn(k,file,dis);
    return 0;
}
