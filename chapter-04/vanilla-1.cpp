#include "vanilla-1.hpp"

vanilla_option::vanilla_option (payoff &po, double expirity)
    : po_ (po), expirity_ (expirity)
{
}

double
vanilla_option::get_expirity () const
{
  return expirity_;
}

double
vanilla_option::option_payoff (double spot) const
{
  return po_ (spot);
}
