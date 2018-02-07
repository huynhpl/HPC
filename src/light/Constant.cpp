//
// Created by huynh on 1/6/2018.
//

#include "Constant.h"
#include <math.h>
using namespace Eigen;

double Constant::LAMBDA() {return 0.001;};
double Constant::L() {return 0.25;}
long Constant::MAX_ITER() {return 30000;}
double Constant::TOLERANCE() {return 0.0001;}
double Constant::ETA() {return 1/Constant::LISPCHITZ ? Constant::LISPCHITZ > 0: 0.05;}
double Constant::LISPCHITZ = 0;
void Constant::setLISPCHITZ(MatrixXd X) {
    long n =  X.rows();
    Constant::LISPCHITZ = 0;
    for(long i = 0; i < n; i++){
        VectorXd X_i =  X.row(i);
        double norm =  X_i.norm();
        Constant::LISPCHITZ = Constant::LISPCHITZ?Constant::LISPCHITZ>norm:norm;// max(LISPCHITZ,norm)
    }
    Constant::LISPCHITZ = 0.25*Constant::LISPCHITZ*Constant::LISPCHITZ + LAMBDA();
}
