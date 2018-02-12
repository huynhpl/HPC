//
// Created by huynh on 1/31/2018.
//

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

#include "importData.h"

using namespace std;
using namespace Eigen;

#define MAXBUFSIZE ((int) 1e5)

Eigen::MatrixXd readCSV(std::string file, int rows, int cols) {

    std::ifstream in(file);

    string line;

    int row = 0;
    int col = 0;

    Eigen::MatrixXd res(rows, cols);

    if (in.is_open()) {

        while (std::getline(in, line)) {
            istringstream f(line);
            string token;
            col = 0;
            while(getline(f,token,',')){
                double d = atof(token.c_str());
                res(row,col) = d;
                col++;
            }
            row++;
        }

        in.close();
    }
    return res;
}

MatrixXd ImportData::loadData(const char * filename){
    int cols = 0, rows = 0;

    cout << filename << endl;
    ifstream infile;
    infile.open(filename);
    string line;
    getline(infile, line);
    for(int i = 0; i < line.size();i++){
        if(line[i] == ','){
            cols++;
        }
    }
    cols++;
    while (! infile.eof()){
        string line;
        getline(infile, line);
        rows++;
    }

    infile.close();
    cout << rows << " " << cols << endl;
    return readCSV(filename,rows,cols);
}

VectorXd ImportData::loadLabel(const char * filename, long rows){
    VectorXd y(rows);
    ifstream infile;
    long iter = 0;
    infile.open(filename);
    while (! infile.eof() && iter < rows){
        int label;
        infile >> label;
        y(iter) = label;
        iter++;
    }
    infile.close();
    return y;
}

