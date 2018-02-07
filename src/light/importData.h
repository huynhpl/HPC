//
// Created by huynh on 1/31/2018.
//

#ifndef SGD_IMPORTDATA_H
#define SGD_IMPORTDATA_H


#include <Eigen/Dense>
#include <string>

using namespace Eigen;
using namespace std;

class ImportData{
public:
	static MatrixXd loadData(const char * filename);
	static VectorXd loadLabel(const char * filename, long rows);
};


#endif //SGD_IMPORTDATA_H
