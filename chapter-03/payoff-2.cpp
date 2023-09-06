#include <algorithm>

#include "payoff-2.hpp"

payoff_call::payoff_call (double strike) : strike_ (strike){};

double
payoff_call::operator() (double spot) const
{
  return std::max (spot - strike_, 0.0);
}

payoff_put::payoff_put (double strike) : strike_ (strike){};

double
payoff_put::operator() (double spot) const
{
  return std::max (strike_ - spot, 0.0);
}