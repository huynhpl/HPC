//
// Created by huynh on 1/7/2018.
//

#include "Score.h"
#include <iostream>
using namespace std;

double Score::accuracy(VectorXd Y, VectorXd Y_pre) {
    double r = 0.0;
    long n = Y.rows();
    for(long  i = 0; i < n; i++){
        r += 1-abs(Y(i)-Y_pre(i));
    }
    return r/n;
}