#ifndef VANILLA1_HPP
#define VANILLA1_HPP

#include "chapter-03/payoff-2.hpp"

class vanilla_option
{
public:
  vanilla_option (payoff &po, double expirity);
  double get_expirity () const;
  double option_payoff (double spot) const;

private:
  double expirity_;
  payoff &po_;
};

#endif