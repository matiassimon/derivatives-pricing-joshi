#include <algorithm>

#include "payoff-3.hpp"

payoff_call::payoff_call (double strike) : strike_ (strike){};

double
payoff_call::operator() (double spot) const
{
  return std::max (spot - strike_, 0.0);
}

payoff *
payoff_call::clone () const
{
  return new payoff_call (*this);
}

payoff_put::payoff_put (double strike) : strike_ (strike){};

double
payoff_put::operator() (double spot) const
{
  return std::max (strike_ - spot, 0.0);
}

payoff *
payoff_put::clone () const
{
  return new payoff_put (*this);
}