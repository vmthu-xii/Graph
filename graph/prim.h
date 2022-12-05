#pragma once

#include "header.h"
#include <queue>

void initPrim(int n, int *dist, int *pre);

int prim(int s, vector <vector <pair<int, int>> > adj, int *dist, int *pre);

void mainPrim();

