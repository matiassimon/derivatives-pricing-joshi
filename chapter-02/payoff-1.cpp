#include <algorithm>

#include "payoff-1.hpp"

payoff::payoff (double lower_strike, double upper_strike)
    : lower_strike_ (lower_strike), upper_strike_ (upper_strike)
{
}

double
payoff::operator() (double spot) const
{
  return spot > lower_strike_ && spot < upper_strike_ ? 1.0 : 0.0;
}