#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <omp.h>
#include <vector>
using namespace std;
int main() {
 int r,c,m1,m2;

 cout<<"Enter rows: ";
 cin >> r;

 cout<<"Enter colums: ";
 cin >> c;

 cout<<"Enter value for  matrix 1: ";
 cin>>m1;
 
 cout<<"Enter value for matrix 2: ";
 cin>>m2;
 
 int matrix[r][c], vector[c], out[r];
 for (int row = 0; row < r; row++) {
 for (int col = 0; col < c; col++) {
 matrix[row][col] = m1;
 }
 }
 cout << "Input matrix" << endl;
 for (int row = 0; row < r; row++) {
 for (int col = 0; col < c; col++) {
 cout << "\t" << matrix[row][col];
 }
 cout << endl;
 }
 for (int col = 0; col < c; col++) {
 vector[col] = m2;
 }
 cout << "Input col-vector" << endl;
 for (int row = 0; row < c; row++) {
 cout << vector[row] << endl;
 }
 #pragma omp parallel for
 for (int row = 0; row < r; row++) {
 out[row] = 0;
 for (int col = 0; col < c; col++) {
 out[row] += matrix[row][col] * vector[col];
 }
 }
 cout << "Resultant col-vector" << endl;
 for (int row = 0; row < r; row++) {
 cout << "\nVector [" << row << "]: " << out[row] << endl;
 } return 0;
}
