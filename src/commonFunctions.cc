/*
 * commonFunctions.cc
 *
 *  Created on: Nov 30, 2017
 *      Author: henry
 */
#include <cmath>
#include "commonFunctions.h"

using namespace Eigen;

double CommonFunctions::sigmoid(double x){
	return 1.0/(1.0+exp(-x));
}

//Return loss function
double CommonFunctions::loss(VectorXd y,VectorXd z){

	int n = y.size();
	double loss;
	for(int i=0;i<n;i++){
		loss -= (y(i)*log2(z(i)) + (1-y(i))*log2(1-z(i)));
	}
	return loss/n;
}



