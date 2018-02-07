/*
 * logisticRegression.h
 *
 *  Created on: Nov 30, 2017
 *      Author: henry
 */

#ifndef LOGISTICREGRESSION_H_
#define LOGISTICREGRESSION_H_


#include <Eigen/Dense>
#include <string>

using namespace Eigen;

class LR{
public:
	LR(int max_i=100,double alp=0.1, double l2_lambda=0.05,double tolerance=0.01);
	~LR();
	 void fit(MatrixXd X,VectorXd y);
	 VectorXd getW();
	 VectorXd predict_prob(MatrixXd X);
	 VectorXd predict(MatrixXd X);

private:
	VectorXd W;
	int max_iter;
	double lambda;
	double tol;
	double alpha;
};


#endif /* LOGISTICREGRESSION_H_ */
