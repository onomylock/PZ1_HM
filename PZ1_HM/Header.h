#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>
using namespace std;

void input(vector<float> &A, vector<float> &F, vector<int> &ai, int &n, int &m);			// read_note.cpp
void decomposition(vector<float> &A, vector<int> ai, vector<float> &E, int n, int m);							// decomposition.cpp
void straight_step(vector<float> L, vector<int> ai, vector<float> &F, int n, int m);	// solution.cpp
void middle_step(vector<float> &Y, vector<float> E, int n);															// solution.cpp
void reverse_step(vector<float> L, vector<float> &Z, vector<int> ai, int n, int m);		// solution.cpp
void gauss(vector<float> A, vector<float>& F, vector<int> ai, int n, int m);				// gauss.cpp