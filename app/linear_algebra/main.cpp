#include <iostream>
#include <Eigen/Dense>

using Eigen::MatrixXd;

typedef Eigen::Matrix<float, 3, 3> MyMatrix33f;
typedef Eigen::Matrix<float, 3, 1> MyVector3f;
typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> MyMatrix;



int main() {
  //Definitions
  MyMatrix33f a;
  MyVector3f v;
  MyMatrix mym(10, 15);
  MatrixXd m(2, 2);

  // Initializations
  a = MyMatrix33f::Zero(); 
  a = MyMatrix33f::Identity(); 
  v = MyVector3f::Random();

  // Assignments
  m(0,0) = 3;
  m(1,0) = 2.5;
  m(0,1) = -1;
  m(1,1) = m(1,0) + m(0,1);
  a << 1,2,3,
       4,5,6,
       7,8,9;

  // Output
  std::cout << m << std::endl;

  // Mapping (shallow copy)
  int data[] = {1, 2, 3, 4};
  Eigen::Map<Eigen::RowVectorXi> r(data, 4);
  std::vector<float> data2 = {1,2,3,4,5,6,8,9};
  Eigen::Map<MyMatrix33f> n(data2.data());

  // Math
  // what are the types?
  auto x = Eigen::Matrix2d::Random();
  auto y = Eigen::Matrix2d::Random();
  auto res = x + y;
  auto res2 = x.array() * y.array(); // element wise multiplication
  // x = y + x;
  auto res3 = x.array() / y.array();
  //x += y;
  //r = x * y;  // matrix multi
  auto res4 = x.array() * 3;

}
