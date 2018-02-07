/*
 * commonFunctions.h
 *
 *  Created on: Nov 30, 2017
 *      Author: henry
 */

#ifndef COMMONFUNCTIONS_H_
#define COMMONFUNCTIONS_H_

#include <Eigen/Dense>

using namespace Eigen;

class CommonFunctions{
public:
	static double sigmoid(double x);
	static double loss(VectorXd y,VectorXd z);
};



#endif /* COMMONFUNCTIONS_H_ */
