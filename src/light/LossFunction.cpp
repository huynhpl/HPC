//
// Created by huynh on 1/6/2018.
//

#include "LossFunction.h"
#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Constant.h"
using namespace Eigen;
using namespace std;

 double LossFunction::Sigmoid(double x) {
     return (double)1.0/(double)(1.0+exp(-x));
 }
VectorXd LossFunction::predict(MatrixXd X, VectorXd W) {
     long n_samples = X.rows();
     VectorXd Z = VectorXd::Zero(n_samples);
     for(long i = 0; i < n_samples; i++ ){
         Z(i) = LossFunction::Sigmoid(X.row(i).dot(W));
     }
     return Z;
 }
double LossFunction::predict_ex(VectorXd X, VectorXd W) {
    double z = 0.0;
    z = LossFunction::Sigmoid((double)X.transpose().dot(W));
    return z;
}
 double LossFunction::Sigmoid_Loss(MatrixXd X, VectorXd Y, VectorXd W) {
    VectorXd Z = LossFunction::predict(X,W);
    double loss = 0.0;
    long n_samples = Y.rows();
    for(long i = 0; i < n_samples; i++){
        double l_i =  Y(i)*log2(Z(i))+(1-Y(i))*log2(1-Z(i));// ylog(z)+(1-y)log(1-z)
        loss += l_i;
    }
    return loss/n_samples + Constant::LAMBDA()/2*W.dot(W);
}
