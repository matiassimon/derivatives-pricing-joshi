#include <cmath>
#include <iostream>

#include "random-1.hpp"

using namespace std;

double
simple_montecarlo_1 (double expirity, double lower_strike, double upper_strike,
                     double spot, double vol, double r,
                     unsigned long number_of_paths)
{
  double variance = vol * vol * expirity;
  double root_variance = sqrt (variance);
  double ito_correction = -0.5 * variance;

  double moved_spot = spot * exp (r * expirity + ito_correction);
  double this_spot;
  unsigned long running_sum = 0;

  for (unsigned long i = 0; i < number_of_paths; i++)
    {
      double this_gaussian = get_one_gaussian_by_box_muller ();
      this_spot = moved_spot * exp (root_variance * this_gaussian);
      if (this_spot > lower_strike && this_spot < upper_strike)
        running_sum++;
    }

  double mean = static_cast<double> (running_sum) / number_of_paths;
  mean *= exp (-r * expirity);
  return mean;
}

int
main ()
{
  double expirity;
  double lower_strike;
  double upper_strike;
  double spot;
  double vol;
  double r;
  unsigned long number_of_paths;

  cout << "Enter expirity" << endl;
  cin >> expirity;

  cout << "Enter lower strike" << endl;
  cin >> lower_strike;

  cout << "Enter upper strike" << endl;
  cin >> upper_strike;

  cout << "Enter spot" << endl;
  cin >> spot;

  cout << "Enter vol" << endl;
  cin >> vol;

  cout << "Enter r" << endl;
  cin >> r;

  cout << "Enter number of paths" << endl;
  cin >> number_of_paths;

  double result = simple_montecarlo_1 (expirity, lower_strike, upper_strike,
                                       spot, vol, r, number_of_paths);

  cout << "The price is " << result << endl;
}
