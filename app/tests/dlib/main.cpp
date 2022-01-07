#include <iostream>
#include <dlib/matrix.h>
using namespace dlib;
using namespace std;
int main() {
  matrix<double,3,1> y;
  matrix<double> M(3,3);

  M = 54.2, 7.4, 12.1, 1, 2, 3, 5.9, 0.05, 1;
  y = 3.5, 1.2, 7.8;

  matrix<double> x = inv(M)*y;
  cout << "x: \n" << x << endl;
  cout << "M*x - y: \n" << M*x -y << endl;

  matrix<double,0,1> runtime_sized_column_vector;
  matrix<double,1,0> runtime_sized_row_vector;
  runtime_sized_column_vector.set_size(3);
  x.set_size(3,4);
  cout << M(0,1) << endl;
  cout << y(1) << endl;

  return 0;
}
