#pragma once

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void input(int &n, int &m, vector <vector <int> > &adj);

void init(int n, int *d, int *parent, bool *isVisit);

void inputWithLength(int &n, int &m, vector <vector <pair<int, int>> > &adj);
