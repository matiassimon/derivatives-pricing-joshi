#ifndef DOUBLEDIGITAL_HPP
#define DOUBLEDIGITAL_HPP

#include "payoff-2.hpp"

class payoff_double_digital : public payoff
{
public:
  payoff_double_digital (double lower_level, double upper_level);
  ~payoff_double_digital (){};
  virtual double operator() (double spot) const override;

private:
  double lower_level_;
  double upper_level_;
};

#endif