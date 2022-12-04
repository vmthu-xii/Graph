#pragma once

#include "header.h"
#include <queue>

void initDijkstra(int n, int *dist, int *pre);

void dijkstra(int n, vector <vector <pair<int, int>> > adj, int *dist, int *pre);

void mainDijkstra();

