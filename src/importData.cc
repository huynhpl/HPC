/*
 * dataPreprocessing.cc
 *
 *  Created on: Nov 30, 2017
 *      Author: henry
 */
#include <Eigen/Dense>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#include "importData.h"

using namespace std;
using namespace Eigen;


#define MAXBUFSIZE ((int) 1e5)

MatrixXd ImportData::loadData1(const char * filename){
	int cols = 0, rows = 0;
	double buff[MAXBUFSIZE];

	cout << filename << endl;
	ifstream infile;
	infile.open(filename);
	while (! infile.eof()){
		string line;
		getline(infile, line);

		int temp_cols = 0;
		stringstream stream(line);
		while(! stream.eof())
			stream >> buff[cols*rows+temp_cols++];

		if (temp_cols == 0)
			continue;
		if (cols == 0)	VectorXd y;

			cols = temp_cols;

		rows++;
	}

	infile.close();
	rows--;
	MatrixXd X(rows,cols);
	for (int i = 0; i<rows; i++){
		for (int j = 0; j<cols; j++){
			X(i,j) = buff[cols*i+j];
		}
	}
	return X;
}

VectorXd ImportData::loadLabel1(const char * filename){
	int rows=0;
	double buff[MAXBUFSIZE];

	ifstream infile;
	infile.open(filename);
	while (! infile.eof()){
		string line;
		getline(infile, line);

		stringstream stream(line);
		while(! stream.eof()){
			stream >> buff[rows];

		}
		rows++;
	}
	infile.close();
	rows--;
	VectorXd y(rows);
	for (int i = 0; i<rows; i++){
		y(i) = buff[i];
	}
	return y;
}

