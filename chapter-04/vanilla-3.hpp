#ifndef VANILLA3_HPP
#define VANILLA3_HPP

#include "payoff-bridge.hpp"

class vanilla_option
{
public:
  vanilla_option (const payoff_bridge &po, double expirity);

  double get_expirity () const;
  double option_payoff (double spot) const;

private:
  double expirity_;
  payoff_bridge po_;
};

#endif