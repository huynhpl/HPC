//
// Created by huynh on 1/6/2018.
//

#include "Gradient.h"
#include "LossFunction.h"
#include "Constant.h"
#include <iostream>
using namespace Eigen;
using namespace std;
// \nabla L = 1/N * sum_{i=1}^N ((z_i-y_i)x_i) + lambda*W
VectorXd Gradient::logistic(MatrixXd X, VectorXd Y, VectorXd W) {
    long n_samples =  X.rows();
    VectorXd G = VectorXd::Zero(W.rows());
    VectorXd Z = LossFunction::predict(X,W);
    for(long i = 0; i < n_samples; i++){
    		for(long j = 0; j < X.cols(); j++){
    			G(j) = G(j) + (Z(i)-Y(i))*X(i,j);
    		}
    }
    VectorXd R = G/n_samples + Constant::LAMBDA()*W;
    return R;
}
// \nabla L_i = (z_i-y_i)*x_i + lambda*W/N
VectorXd Gradient::logistic_ex(MatrixXd X, VectorXd Y, VectorXd W, int i) {
    VectorXd X_i =  X.row(i);
    long n_samples = X.rows();
    VectorXd G = VectorXd::Zero(n_samples);
    double z = LossFunction::predict_ex(X_i,W);
    G = (-z+Y(i))*X_i;
    return G + (double)Constant::LAMBDA()*W/n_samples;
}
VectorXd Gradient::perceptron(MatrixXd X, VectorXd Y, VectorXd W) {
	return W;
}
VectorXd Gradient::perceptron_ex(MatrixXd X, VectorXd Y, VectorXd W, int i) {
	return W;
}
