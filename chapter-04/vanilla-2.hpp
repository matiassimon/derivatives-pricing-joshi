#ifndef VANILLA2_HPP
#define VANILLA2_HPP

#include "payoff-3.hpp"

class vanilla_option
{
public:
  vanilla_option (const payoff &po, double expirity);
  vanilla_option (const vanilla_option &original);
  vanilla_option &operator= (const vanilla_option &original);
  ~vanilla_option ();

  double get_expirity () const;
  double option_payoff (double spot) const;

private:
  double expirity_;
  payoff *po_;
};

#endif