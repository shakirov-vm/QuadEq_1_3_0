#ifndef FUNCTION_H
#define FUNCTION_H

#include <stdio.h>
#include <math.h>

int IsZero (double forCompare);
int SolveLinear (double b, double c, double* x);
int SolveQuadratic (double a, double b, double c, double* x1, double* x2, double* x);
double ScanNumber(double scanned);


/*
#ifdef  name <- if defined (name) {
#ifndef name <- if not defined (name) {
#endif       <- }
*/
#endif
