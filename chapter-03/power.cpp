#include <algorithm>
#include <cmath>

#include "power.hpp"

payoff_power::payoff_power (double i, double strike)
    : i_ (i), strike_ (strike){};

double
payoff_power_call::operator() (double spot) const
{
  return std::max (std::pow (spot, i_) - strike_, 0.0);
}

double
payoff_power_put::operator() (double spot) const
{
  return std::max (strike_ - std::pow (spot, i_), 0.0);
}
