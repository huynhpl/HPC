/*
 * logisticRegression.cc
 *
 *  Created on: Nov 30, 2017
 *      Author: henry
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "logisticRegression.h"
#include "commonFunctions.h"

using namespace Eigen;

LR::LR(int max_interation, double alp, double l2_lambda, double tolerance){
	lambda = l2_lambda;
	max_iter = max_interation;
	alpha = alp;
	tol = tolerance;
}

LR::~LR(){}

void LR::fit(MatrixXd X, VectorXd y){
//	initialize vector w
	W = VectorXd::Random(X.cols()+1);

//X_new = add column 1 to X
	MatrixXd X_new(X.rows(), X.cols()+1);
	X_new<<X,MatrixXd::Ones(X.rows(),1);

	int iter;
	for ( iter = 0;  iter < max_iter; ++ iter) {
		VectorXd z = predict_prob(X);

		W = W - alpha*X_new.transpose()*(z-y);

		double loss = CommonFunctions::loss(y,z);
		if(loss<=tol) break;
	}

}

//Return prediction of X
VectorXd LR::predict_prob(MatrixXd X){

	MatrixXd X_new(X.rows(),X.cols()+1);
	X_new<<X,MatrixXd::Ones(X.rows(),1);
	int number_samples = X.rows();
	VectorXd y_pred_prob = VectorXd::Zero(number_samples);
	int num;
	for (num = 0; num < number_samples; ++num) {
		//	y_pred_prob = sigmod(X(i)*W)
		y_pred_prob(num) = CommonFunctions::sigmoid(X_new.row(num).dot(W));
	}

	return y_pred_prob;

}

VectorXd LR::predict(MatrixXd X){
	VectorXd y_pred_prob = predict_prob(X);
	VectorXd y_pred(y_pred_prob.size());

	int num;
	for (num = 0; num < y_pred_prob.size(); ++num) {
		y_pred(num) = y_pred_prob(num)>0.5?1.0:0.0;
	}

	return y_pred;
}

VectorXd LR::getW(){
	return W;
}
