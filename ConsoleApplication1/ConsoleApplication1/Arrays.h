#pragma once

#define N 1000
int flag[N];
double prev[N];
double x[N];
double a[N][N];
double b[N];
double dif[N];
double norm;
double check[N];
double prevDiv[N];
int breakFlag;

void GenerateMatrixValues();
void CalculateMatrix(int index);
void CheckMatrix();
void MultiplyLast();
void Reset();