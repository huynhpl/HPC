/*
 * dataPreprocessing.h
 *
 *  Created on: Nov 30, 2017
 *      Author: henry
 */

#ifndef IMPORTDATA_H_
#define IMPORTDATA_H_

#include <Eigen/Dense>
#include <string>

using namespace Eigen;
using namespace std;

class ImportData{
public:
	static MatrixXd loadData1(const char * filename);
	static VectorXd loadLabel1(const char * filename);
};

#endif /* IMPORTDATA_H_ */
