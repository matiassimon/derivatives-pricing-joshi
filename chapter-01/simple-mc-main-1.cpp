#include <cmath>
#include <iostream>

#include "random-1.hpp"

using namespace std;

double
simple_montecarlo_1_call (double expirity, double strike, double spot,
                          double vol, double r, unsigned long number_of_paths)
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

double
simple_montecarlo_1_put (double expirity, double strike, double spot,
                         double vol, double r, unsigned long number_of_paths)
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
      double this_payoff = strike - this_spot;
      this_payoff = this_payoff > 0 ? this_payoff : 0;
      running_sum += this_payoff;
    }

  double mean = running_sum / number_of_paths;
  mean *= exp (-r * expirity);
  return mean;
}

double
simple_montecarlo_1_double_digital (double expirity, double lower_strike,
                                    double upper_strike, double spot,
                                    double vol, double r,
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
  double spot;
  double vol;
  double r;
  unsigned long number_of_paths;
  string payoff_type;

  cout << "Enter expirity" << endl;
  cin >> expirity;

  cout << "Enter spot" << endl;
  cin >> spot;

  cout << "Enter vol" << endl;
  cin >> vol;

  cout << "Enter r" << endl;
  cin >> r;

  cout << "Enter number of paths" << endl;
  cin >> number_of_paths;

  cout << "Enter option payoff (c: call, p: put, dd: double digital)" << endl;
  cin >> payoff_type;

  if (payoff_type == "c")
    {
      double strike;

      cout << "Enter strike" << endl;
      cin >> strike;

      double result = simple_montecarlo_1_call (expirity, strike, spot, vol, r,
                                                number_of_paths);

      cout << "The price is " << result << endl;
    }
  else if (payoff_type == "p")
    {
      double strike;

      cout << "Enter strike" << endl;
      cin >> strike;

      double result = simple_montecarlo_1_put (expirity, strike, spot, vol, r,
                                               number_of_paths);

      cout << "The price is " << result << endl;
    }
  else if (payoff_type == "dd")
    {
      double lower_strike;
      double upper_strike;

      cout << "Enter lower strike" << endl;
      cin >> lower_strike;

      cout << "Enter upper strike" << endl;
      cin >> upper_strike;

      double result = simple_montecarlo_1_double_digital (
          expirity, lower_strike, upper_strike, spot, vol, r, number_of_paths);

      cout << "The price is " << result << endl;
    }
  else
    {
      cout << "Invalid payoff type" << endl;
    }
}
