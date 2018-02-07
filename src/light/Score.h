//
// Created by huynh on 1/7/2018.
//

#ifndef SGD_SCORE_H
#define SGD_SCORE_H

#include <Eigen/Dense>
using namespace Eigen;
class Score {
public:
    static double accuracy(VectorXd Y, VectorXd Y_pre);

};
#endif //SGD_SCORE_H
