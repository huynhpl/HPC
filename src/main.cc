/*
 * main.cc
 *
 *  Created on: Dec 6, 2017
 *      Author: henry
 */
#include <iostream>
#include <stdio.h>

#include "light/importData.h"
#include <Eigen/Dense>
#include "light/Algorithms.h"
#include "light/Constant.h"
#include "light/Score.h"

using namespace std;
using namespace Eigen;



int main(){
	cout << "!!!Hello World DKM!!!" << endl; // prints !!!Hello World!!!

	MatrixXd X_train = ImportData::loadData("./data/X_train.txt");

	MatrixXd X_new(X_train.rows(),X_train.cols()+1);
	    X_new<<X_train,MatrixXd::Ones(X_train.rows(),1);
	X_train = X_new;
    long n_samples =  X_train.rows();
	MatrixXd X_test = ImportData::loadData("./data/X_test.txt");
    long n_test =  X_test.cols();
	VectorXd y_train = ImportData::loadLabel("./data/y_train.txt",n_samples);
	VectorXd  y_test = ImportData::loadLabel("./data/y_test.txt",n_test);

    Constant::setLISPCHITZ(X_train);
    Algorithms learning;
    learning.setAlg(4);
    cout << "Fitting" << endl;
    learning.fit(X_train,y_train);
    learning.setAlg(2);
    learning.fit(X_train,y_train);
    learning.setAlg(5);
    learning.fit(X_train,y_train);
//    learning.setAlg(1);
//    learning.fit(X_train,y_train);
    cout << "Fitted" << endl;

    VectorXd y_predict = learning.predict(X_train);
    double acc = Score::accuracy(y_train,y_predict);
    cout << acc << endl;




//
//	LR::fit(X_train,y_train);
//	VectorXd y_pred = LR::predict(X_test);
//
//	cout << "hello"<< y_pred <<endl;

//	std::cout << "Here is the matrix m:\n" << 1 << std::endl;
////	std::cout << "Here is the matrix m:\n" << X_train <<endl;
//
//	std::cout << "Here is the matrix m:\n" << 1 << std::endl;
	return 0;
}



