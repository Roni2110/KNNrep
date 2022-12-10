#include <string>
#include <string.h>
#include <iostream>
#include <vector>
#include <float.h>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include "Knn.h"

using namespace std;


/**
 * this function checks that all the values in the vectors are numbers. if not - it prints an error to the user.
 * @param str1 - the values of the first vector.
 * @param str2 - the values of the second vector.
 */
vector<double> checkingInput(string str1) {
    vector<double> v1;
    double num;
    stringstream stringstream1(str1);
    while(stringstream1 >> num) {
        v1.push_back(num);
    }
    if(!stringstream1.eof()) {
        cout << "Input not valid!" << endl;
        exit(0);
    }
    if (v1.empty()) {
        cout << "No parameters added!" << endl;
        exit(0);
    }
    return v1;
}

/**
 * this function checks that the arguments that the user entered to main are valid.
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
    vector<double> vecInput;
    checkingArgv(argv);
    int k = stoi(argv[1]);
    string file = argv[2];
    string dis = argv[3];
    string input1;
    getline(cin,input1);
    if((double)input1.size() >= log(DBL_MAX) - 1) {
        input1 = input1.substr(0, sizeof(double));
    }
    vecInput = checkingInput(input1);
    Knn* knn = new Knn(3,"iris_classified.csv","MAN", vecInput);
    knn->uploadFiles();
    delete knn;
    return 0;
}
