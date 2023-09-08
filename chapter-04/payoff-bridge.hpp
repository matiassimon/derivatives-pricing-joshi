#ifndef PAYOFFBRIDGE_HPP
#define PAYOFFBRIDGE_HPP

#include "payoff-3.hpp"

class payoff_bridge
{
public:
  payoff_bridge (const payoff_bridge &original);
  payoff_bridge (const payoff &po);
  ~payoff_bridge ();

  inline double operator() (double spot) const;
  payoff_bridge &operator= (const payoff_bridge &original);

private:
  payoff *po_;
};

inline double
payoff_bridge::operator() (double spot) const
{
  return po_->operator() (spot);
}

#endif