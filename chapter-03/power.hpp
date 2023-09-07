#ifndef POWER_HPP
#define POWER_HPP

#include "payoff-2.hpp"

class payoff_power : public payoff
{
public:
  payoff_power (double i, double strike);
  virtual ~payoff_power (){};

protected:
  double i_;
  double strike_;
};

class payoff_power_call : public payoff_power
{
public:
  using payoff_power::payoff_power;
  virtual double operator() (double spot) const override;
};

class payoff_power_put : public payoff_power
{
public:
  using payoff_power::payoff_power;
  virtual double operator() (double spot) const override;
};

#endif