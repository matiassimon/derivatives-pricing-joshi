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
    case option_type::european_call:
      return std::max (spot - strike_, 0.0);
    case option_type::european_put:
      return std::max (strike_ - spot, 0.0);
    case option_type::digital_call:
      return spot > strike_ ? 1.0 : 0.0;
    case option_type::digital_put:
      return spot > strike_ ? 0.0 : 1.0;
    default:
      throw ("unknown option type found");
    }
}