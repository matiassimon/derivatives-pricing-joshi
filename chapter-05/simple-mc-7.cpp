#include <cmath>

#include "chapter-01/random-1.hpp"
#include "simple-mc-7.hpp"

using namespace std;

void
simple_monte_carlo_5 (const vanilla_option &option, double spot,
                      const parameters &vol, const parameters &r,
                      unsigned long number_of_paths, statistics_mc &gatherer)
{
  double expirity = option.get_expirity ();
  double variance = vol.integral_square (0, expirity);
  double root_variance = sqrt (variance);
  double ito_correction = -0.5 * variance;
  double moved_spot = spot * exp (r.integral (0, expirity) + ito_correction);
  double this_spot;
  double discounting = exp (-r.integral (0, expirity));

  for (unsigned long i = 0; i < number_of_paths; i++)
    {
      double this_gaussian = get_one_gaussian_by_box_muller ();
      this_spot = moved_spot * exp (root_variance * this_gaussian);
      double this_payoff = option.option_payoff (this_spot);
      gatherer.dump_one_result (this_payoff * discounting);
    }

  return;
}