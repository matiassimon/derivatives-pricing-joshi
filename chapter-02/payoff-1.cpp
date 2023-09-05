#include <algorithm>

#include "payoff-1.hpp"

payoff::payoff (double strike, option_type type)
    : strike_ (strike), type_ (type)
{
}

double
payoff::operator() (double spot) const
{
  switch (type_)
    {
    case option_type::call:
      return std::max (spot - strike_, 0.0);
    case option_type::put:
      return std::max (strike_ - spot, 0.0);
    default:
      throw ("unknown option type found");
    }
}