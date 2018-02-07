//
// Created by huynh on 1/7/2018.
//

#include "Algorithms.h"
#include "Constant.h"
#include "LearningAlgorithm.h"
#include "LossFunction.h"
#include <iostream>

using namespace std;

using namespace Eigen;
double Algorithms::getTol() const {
    return tol;
}

void Algorithms::setTol(double tol) {
    Algorithms::tol = tol;
}

int Algorithms::getAlg() const {
    return alg;
}

void Algorithms::setAlg(int alg) {
    Algorithms::alg = alg;
}

long Algorithms::getN_iters() const {
    return n_iters;
}

void Algorithms::setN_iters(long n_iters) {
    Algorithms::n_iters = n_iters;
}

Algorithms::Algorithms(double tol, int alg, long n_iters) : tol(tol), alg(alg), n_iters(n_iters) {
    Algorithms::tol = tol;
    Algorithms::alg = alg;
    Algorithms::n_iters = n_iters;
}
Algorithms::Algorithms() {
    Algorithms::tol = Constant::TOLERANCE();
    Algorithms::n_iters = Constant::MAX_ITER();
    Algorithms::alg = SGD;
}
void Algorithms::fit(MatrixXd X, VectorXd Y) {
    VectorXd W_init =  VectorXd::Random(X.cols());
    cout << alg << endl;
    LearningAlgorithm learningAlgorithm(tol,n_iters,alg);
    W = learningAlgorithm.fit(X,Y,W_init);
}
VectorXd Algorithms::predict(MatrixXd X) {
	VectorXd Y(X.rows());
    Y = LossFunction::predict(X, Algorithms::W);
    long n = Y.rows();
    for(long  i = 0; i < n; i++){
        if(Y(i) < 0.5) Y(i) = 0;
        else Y(i) = 1;
    }
    return Y;
}
VectorXd Algorithms::getW() {
    return W;
}
