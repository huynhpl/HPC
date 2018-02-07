//
// Created by huynh on 1/6/2018.
//

#ifndef SGD_GRADIENT_H
#define SGD_GRADIENT_H

#include <Eigen/Dense>

using namespace Eigen;
class Gradient {
public:
    static VectorXd logistic(MatrixXd X, VectorXd Y, VectorXd W);
    static VectorXd perceptron(MatrixXd X, VectorXd Y, VectorXd W);
    static VectorXd logistic_ex(MatrixXd X, VectorXd Y, VectorXd W,int i);
    static VectorXd perceptron_ex(MatrixXd X, VectorXd Y, VectorXd W, int i);
};


#endif //SGD_GRADIENT_H
