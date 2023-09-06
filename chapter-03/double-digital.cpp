#include <algorithm>

#include "double-digital.hpp"

payoff_double_digital::payoff_double_digital (double lower_level,
                                              double upper_level)
    : lower_level_ (lower_level), upper_level_ (upper_level){};

double
payoff_double_digital::operator() (double spot) const
{
  if (spot <= lower_level_)
    return 0;
  if (spot >= upper_level_)
    return 0;

  return 1;
}
