#include <cmath>

#include "chapter-01/random-1.hpp"
#include "simple-mc.hpp"

using namespace std;

double
simple_monte_carlo_2 (const payoff po, double expirity, double spot,
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
      double this_payoff = po(this_spot);
      running_sum += this_payoff;
    }

  double mean = running_sum / number_of_paths;
  mean *= exp (-r * expirity);
  return mean;
}