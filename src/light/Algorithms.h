//
// Created by huynh on 1/7/2018.
//

#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <Eigen/Dense>

using namespace Eigen;

#define GD 1
#define SGD 2
#define SAG 3
#define SVRG 4
class Algorithms {
private:
    double tol;
    int alg;
    long n_iters;
    VectorXd W;

 public:


    Algorithms();
    Algorithms(double tol, int alg, long n_iters);

    void fit(MatrixXd X, VectorXd Y);
    VectorXd predict(MatrixXd X);

    double getTol() const;

    void setTol(double tol);

    int getAlg() const;

    void setAlg(int alg);

    long getN_iters() const;

    void setN_iters(long n_iters);

    VectorXd getW();
};


#endif //ALGORITHMS_H
