//
// Created by huynh on 1/6/2018.
//

#ifndef SGD_LEARNINGALGORITHM_H
#define SGD_LEARNINGALGORITHM_H
#include <Eigen/Dense>
#include <cstring>
#include <omp.h>
using namespace Eigen;
using namespace std;

#define GD 1
#define SGD 2
#define SVRG 3
#define SAG 4
#define MiniBatchSGD 5
#define Hogwild 6
#define HogBatch 7

class LearningAlgorithm {
public:
     VectorXd fit(MatrixXd X, VectorXd Y, VectorXd W_init);
     VectorXd fit(MatrixXd X, VectorXd Y, VectorXd W_init, int alg);
private:
    double tol;
    long n_iters;
    int n_threads;
public:
    virtual ~LearningAlgorithm();

public:
    LearningAlgorithm();

public:
    LearningAlgorithm(double tol, long n_iters, int alg);

private:
    int alg;
    VectorXd fit_SGD(MatrixXd X, VectorXd Y, VectorXd W_init);
    VectorXd fit_GD(MatrixXd X, VectorXd Y, VectorXd W_init);
    VectorXd fit_SVRG(MatrixXd X, VectorXd Y, VectorXd W_init);
    VectorXd fit_SAG(MatrixXd X, VectorXd Y, VectorXd W_init);
    VectorXd fit_MiniBatchSGD(MatrixXd X, VectorXd Y, VectorXd W_init);
    VectorXd fit_Hogwild(MatrixXd X, VectorXd Y, VectorXd W_init);
    VectorXd fit_HogBatch(MatrixXd X, VectorXd Y, VectorXd W_init);
};


#endif //SGD_LEARNINGALGORITHM_H
