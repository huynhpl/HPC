//
// Created by huynh on 1/6/2018.
//

#include "LearningAlgorithm.h"
#include "Constant.h"
#include "Gradient.h"
#include "LossFunction.h"
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <omp.h>
#include <time.h>

using namespace std;
using namespace Eigen;
VectorXd LearningAlgorithm::fit(MatrixXd X, VectorXd Y, VectorXd W_init) {
        return fit(X,Y,W_init,alg);
}
VectorXd LearningAlgorithm::fit(MatrixXd X, VectorXd Y, VectorXd W_init, int alg) {
    switch (alg){
        case GD: return fit_GD(X,Y,W_init);
        case SGD: return fit_SGD(X,Y,W_init);
        case SVRG: return fit_SVRG(X,Y,W_init);
        case MiniBatchSGD: return fit_MiniBatchSGD(X,Y,W_init);
        case Hogwild: return fit_Hogwild(X,Y,W_init);
        case HogBatch: return fit_HogBatch(X,Y,W_init);
        case SAG: return fit_SAG(X,Y,W_init);
        default: return fit_SGD(X,Y,W_init);
    }
}
VectorXd LearningAlgorithm::fit_SGD(MatrixXd X, VectorXd Y, VectorXd W_init) {
	clock_t tStart = clock();
	cout << "Learning..." << endl;
    VectorXd W = W_init;
    VectorXd W_pre =  W_init;
    long iter = 1;
    long n =  X.rows();
    srand(time(NULL));
    while(iter <= n_iters){
        int i =  rand()%n;
        double step =  Constant::ETA();
        VectorXd G = Gradient::logistic_ex(X,Y,W,i);
        W = W + step*G;
        iter++;
//        if(iter % 50 == 0){
//        	double loss = (W - W_pre).norm();
//        	if(loss < tol) break;
//        	W_pre = W;
//        }
//        double loss = LossFunction::Sigmoid_Loss(X,Y,W);
//        if(abs(loss) < tol) break;
    }
    cout << "Learned. " << iter << endl;
    clock_t tEnd = clock();
    cout << "Time: " << (double)(tEnd -  tStart)/CLOCKS_PER_SEC << endl;
    return  W;
}
VectorXd LearningAlgorithm::fit_MiniBatchSGD(MatrixXd X, VectorXd Y, VectorXd W_init){
	double tStart = omp_get_wtime();
	cout << "Learning MiniBatch..." << endl;
	int SIZE = 64;
//	cout << SIZE << endl;
	long num_samples = X.rows();
	n_threads = Constant::get_num_threads();
	long num_features =  X.cols();
	long iter = 0;
	srand(time(NULL));
	VectorXd W = W_init;
	VectorXd W_pre = W_init;
	VectorXd W_tid[100];
	VectorXd Zero = VectorXd::Zero(X.cols());
	omp_set_num_threads(n_threads);
while(iter <= n_iters){
	for(int i = 0; i < 10; i++) W_tid[i] = Zero;
	 double step = Constant::ETA();
	 long start =  rand()%(num_samples-SIZE+1);
// Parallel for computing batch SGD
		#pragma omp parallel for schedule(dynamic) num_threads(n_threads)
		for(int index = start; index < start + SIZE; index++){
			long TID = omp_get_thread_num();
//			cout << TID << endl;
			VectorXd g =  step * Gradient::logistic_ex(X,Y,W,index);
			for(long i = 0; i < g.rows(); i++){
				if(g[i] != 0){
					W_tid[TID][i] = W_tid[TID][i] + g[i];
				}
			}

		}
		#pragma omp parallel for schedule(static) num_threads(n_threads)
		for(long f = 0; f < num_features; f++){
			for(int t = 0; t < omp_get_num_threads(); t++){
				W[f] = W[f] + W_tid[t][f];
			}
		}
//		for(int i = 0; i < num_features; i++) cout << W[i] << "|";
//		cout << endl;
//		char c; cin >> c;
//	if(iter % 50 == 0){
//		        	double loss = (W - W_pre).norm();
//		        	if(loss < tol) break;
//		        	W_pre = W;
//		        }
	iter += SIZE;
//	cout << iter << endl;
}
	cout << "Learned" << endl;
	double tEnd = omp_get_wtime();
    cout << "Time: " << (double)(tEnd -  tStart) << endl;
	return W;
}
VectorXd LearningAlgorithm::fit_Hogwild(MatrixXd X, VectorXd Y, VectorXd W_init){
		double tStart = omp_get_wtime();
		cout << "Learning HogWild..." << endl;
		VectorXd W = W_init;
	   	VectorXd W_pre =  W_init;
	    long iter = 1;
	    long n =  X.rows();
	    srand(time(NULL));
	    omp_set_num_threads(n_threads);
		#pragma omp parallel for schedule(dynamic) num_threads(n_threads)
	    for(iter = 1; iter <= n_iters; iter++){
	        int i =  rand()%n;
	        double step =  Constant::ETA();
	        VectorXd G = step*Gradient::logistic_ex(X,Y,W,i);
	        for(long i = 0; i < G.rows(); i++){
	        	if(G[i]!=0){
		        	W[i] = W[i] + G[i];
	        	}
	        }
	    }
	    cout << "Learned HogWild. " << endl;
	    double tEnd = omp_get_wtime();
	    cout << "Time: " << (double)(tEnd -  tStart) << endl;
	    return  W;
}
VectorXd LearningAlgorithm::fit_HogBatch(MatrixXd X, VectorXd Y, VectorXd W_init){
	cout << "Learning HogBatch ..." << endl;
	double tStart = omp_get_wtime();
		int SIZE = 4;
		long num_samples = X.rows();
		long num_features =  X.cols();
		long iter = 0;
		srand(time(NULL));
		VectorXd W = W_init;
		VectorXd W_pre = W_init;
		W = VectorXd::Zero(X.cols());
		VectorXd W_tid[100];
		omp_set_num_threads(n_threads);
	#pragma omp parallel for schedule(dynamic) num_threads(n_threads)
	for(iter = 1; iter <= n_iters; iter = iter + SIZE){
		for(int i = 0; i < 10; i++) W_tid[i] = VectorXd::Zero(X.cols());
		 double step = Constant::ETA();
		 long start =  rand()%(num_samples-SIZE+1);
		 for(int index = start; index < start + SIZE; index++){
		 			long TID = omp_get_thread_num();
		 			VectorXd g =  step * Gradient::logistic_ex(X,Y,W,index);
		 			for(long i = 0; i < g.rows(); i++){
		 				if(g[i] != 0){
		 					W_tid[TID][i] = W_tid[TID][i] + g[i];
		 				}
		 			}

		 		}

			for(long f = 0; f < num_features; f++){
				for(int t = 0; t < omp_get_num_threads(); t++){
					W[f] = W[f] + W_tid[t][f];
				}
			}
	}
	cout << "Learned HogBatch" << endl;
	double tEnd = omp_get_wtime();
	cout << "Time: " << (double)(tEnd -  tStart) << endl;
	return W;
}
VectorXd LearningAlgorithm::fit_GD(MatrixXd X, VectorXd Y, VectorXd W_init) {
	double tStart = omp_get_wtime();
	VectorXd W = W_init;
    VectorXd W_pre =  W_init;
    long iter = 1;
    while(iter <= n_iters){

        double step =  Constant::ETA();
        VectorXd G = Gradient::logistic(X,Y,W);
        W = W + step*G;
        iter++;
                if(iter % 50 == 0){
                	cout << iter << endl;
                	double loss = (W - W_pre).norm();
                	if(loss < tol) break;
                	W_pre = W;
                }
    }
    double tEnd = omp_get_wtime();
    cout << "Time: " << (double)(tEnd -  tStart) << endl;
    return  W;
}
VectorXd LearningAlgorithm::fit_SVRG(MatrixXd X, VectorXd Y, VectorXd W_init) {
	double tStart = omp_get_wtime();
    VectorXd W = W_init;
    VectorXd W_pre = W;
    long m = X.rows();
    long M = m;
    srand(time(NULL));
    for (long epoch = 1; epoch <= n_iters/M; epoch ++){
    	cout << epoch << endl;
    	VectorXd mu_sum = VectorXd::Zero(X.cols());
    	W_pre = W;
    	for(long i = 0; i < m; i++){
    		mu_sum = mu_sum + Gradient::logistic_ex(X,Y,W,i);
    	}
    	VectorXd mu(X.cols());
    		mu = mu_sum / m;
    	double step =  Constant::ETA();
    	for(long j = 1; j <= M; j++){
    		int i =  rand()%m;
    		VectorXd g = Gradient::logistic_ex(X,Y,W,i);
    		VectorXd g_pre = Gradient::logistic_ex(X,Y,W_pre,i);
    		W = W + step*(g-g_pre+mu);
    	}
    	double loss = (W - W_pre).norm();
    	       if(loss < tol) break;
    	W_pre = W;
    	cout << loss << endl;
    }
    double tEnd = omp_get_wtime();
    cout << "Time: " << (double)(tEnd -  tStart) << endl;
    return  W;
}
VectorXd LearningAlgorithm::fit_SAG(MatrixXd X, VectorXd Y, VectorXd W_init) {
	double tStart = omp_get_wtime();
    VectorXd W = W_init;
    VectorXd W_pre = W;
    long m = X.rows();
    srand(time(NULL));
    VectorXd p[m];
    VectorXd sum = VectorXd::Zero(X.cols());
    for(long i = 0; i < m; i++){
    	p[i] = VectorXd::Zero(X.cols());
    }
    for (long iter = 1; iter <= n_iters; iter++){
    	W_pre = W;
    	double step =  Constant::ETA();
    	int i =  rand()%m;
    	VectorXd g = Gradient::logistic_ex(X,Y,W,i);
//    	VectorXd g_pre = Gradient::logistic_ex(X,Y,W_pre,i);
    	W = W + (double)(step/(double)m)*(g-p[i]+sum);
    	sum = sum - p[i] + g;
    	p[i] = g;
//    	double loss = (W - W_pre).norm();
//    	       if(loss < tol) break;
    }
    double tEnd = omp_get_wtime();
    cout << "Time: " << (double)(tEnd -  tStart) << endl;
    return  W;
}


LearningAlgorithm::LearningAlgorithm(double tol, long n_iters, int alg) : tol(tol), n_iters(n_iters), alg(alg) {
    LearningAlgorithm::tol = tol;
    LearningAlgorithm::n_iters = n_iters;
    LearningAlgorithm::alg = alg;
    LearningAlgorithm::n_threads =  Constant::get_num_threads();
}

LearningAlgorithm::LearningAlgorithm() {
    tol = Constant::TOLERANCE();
    n_iters = Constant::MAX_ITER();
    alg = SGD;
    n_threads = Constant::get_num_threads();
}

LearningAlgorithm::~LearningAlgorithm() {

}
