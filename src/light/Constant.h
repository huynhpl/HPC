//
// Created by huynh on 1/6/2018.
//

#ifndef SGD_CONSTANT_H
#define SGD_CONSTANT_H

#include <Eigen/Dense>

using namespace Eigen;
class Constant {
public :
    static void setLISPCHITZ(MatrixXd X);
    static double TOLERANCE();
    static double LAMBDA();
    static long MAX_ITER();
    static double L();
    static double ETA();
    static int get_num_threads();

public:
    static double LISPCHITZ;
    static double tol;
};


#endif //SGD_CONSTANT_H
