//
// Created by huynh on 1/6/2018.
//

#ifndef SGD_LOSSFUCTION_H
#define SGD_LOSSFUCTION_H
#include <Eigen/Dense>

using namespace Eigen;

class LossFunction {
public:
    static double Sigmoid(double x);
    static double Sigmoid_Loss(MatrixXd X, VectorXd Y, VectorXd W);
    static VectorXd predict(MatrixXd X, VectorXd W);
    static double predict_ex(VectorXd X, VectorXd W);


};


#endif //SGD_LOSSFUCTION_H
