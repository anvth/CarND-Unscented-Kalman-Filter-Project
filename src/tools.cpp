#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
  TODO:
    * Calculate the RMSE here.
  */
  VectorXd rmse = VectorXd(4);
  rmse << 0, 0, 0, 0;

  // check for the following conditions:
  //  * the size of estimation vector should be greater than zero
  //  * the size of both input vectors should be same
  if (estimations.size() != ground_truth.size() ||
      estimations.size() == 0) {
    std::cout << "Invalid estimation or ground_truth data" << std::endl;
    return rmse;
  }

  for (unsigned int i = 0; i < estimations.size(); ++i){

    VectorXd residual = estimations[i] - ground_truth[i];

    residual = residual.array()*residual.array();
    rmse += residual;
  }

  rmse = rmse / estimations.size();

  rmse = rmse.array().sqrt();

  return rmse;
}
