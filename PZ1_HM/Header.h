#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>
using namespace std;

void input(vector<float> &A, vector<float> &F, vector<int> &ai, int &n, int &m);
void input(vector<double>& A, vector<double>& F, vector<int>& ai, int& n, int& m);
void decomposition(vector<float> &A, vector<int> ai, vector<float> &E, int n, int m);
void decomposition(vector<double> &A, vector<int> ai, vector<double> &E, int n, int m);
void straight_step(vector<float> L, vector<int> ai, vector<float> &F, int n, int m);	
void straight_step(vector<double> L, vector<int> ai, vector<double> &F, int n, int m);
void middle_step(vector<float> &Y, vector<float> E, int n);			
void middle_step(vector<double> &Y, vector<double> E, int n);
void reverse_step(vector<float> L, vector<float> &Z, vector<int> ai, int n, int m);
void reverse_step(vector<double> L, vector<double> &Z, vector<int> ai, int n, int m);
void gauss(vector<float> A, vector<float> &F, vector<int> ai, int n, int m);			
void gauss(vector<double> A, vector<double> &F, vector<int> ai, int n, int m);
void read_info(int& n);
void read_ai(vector<int>& ai, int n, int& m);