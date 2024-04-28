#pragma once

#define ARRAY_SIZE 50
extern int array[ARRAY_SIZE];

bool (*SelectAlgorithm(int selectedAlgorithm))(int &, int &);
bool BubbleSortStep(int &i, int &j);
bool InsertionSortStep(int &i, int &j);
