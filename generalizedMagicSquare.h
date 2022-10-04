#ifndef GENERALIZEDMAGICSQYARE_H
#define GENERALIZEDMAGICSQYARE_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <string>
using namespace std;

class magicSquare {
public:
	void calcDifferences(int n, int m);
	void initMatrix(int n);
	void print();
private:
	vector<vector<int>>matrix;
};

 #endif