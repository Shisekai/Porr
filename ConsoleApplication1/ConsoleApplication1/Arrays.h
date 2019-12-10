#pragma once

#define N 3000
int flag[N];
double prev[N];
int counter[N];
double dif[N];
double norm;
double check[N];
int breakFlag;

void GenerateMatrixValues();
void CalculateMatrix(int index);
void CheckMatrix();
void Reset();