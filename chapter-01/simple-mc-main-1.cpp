#include <cmath>
#include <iostream>

#include "random-1.hpp"

using namespace std;

double
simple_montecarlo_1 (double expirity, double strike, double spot, double vol,
                     double r, unsigned long number_of_paths)
{
  double variance = vol * vol * expirity;
  double root_variance = sqrt (variance);
  double ito_correction = -0.5 * variance;

  double moved_spot = spot * exp (r * expirity + ito_correction);
  double this_spot;
  double running_sum = 0;

  for (unsigned long i = 0; i < number_of_paths; i++)
    {
      double this_gaussian = get_one_gaussian_by_box_muller ();
      this_spot = moved_spot * exp (root_variance * this_gaussian);
      double this_payoff = this_spot - strike;
      this_payoff = this_payoff > 0 ? this_payoff : 0;
      running_sum += this_payoff;
    }

  double mean = running_sum / number_of_paths;
  mean *= exp (-r * expirity);
  return mean;
}

int
main ()
{
  double expirity;
  double strike;
  double spot;
  double vol;
  double r;
  unsigned long number_of_paths;

  cout << "Enter expirity" << endl;
  cin >> expirity;

  cout << "Enter strike" << endl;
  cin >> strike;

  cout << "Enter spot" << endl;
  cin >> spot;

  cout << "Enter vol" << endl;
  cin >> vol;

  cout << "Enter r" << endl;
  cin >> r;

  cout << "Enter number of paths" << endl;
  cin >> number_of_paths;

  double result
      = simple_montecarlo_1 (expirity, strike, spot, vol, r, number_of_paths);

  cout << "The price is " << result << endl;
}
