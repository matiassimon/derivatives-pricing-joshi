#ifndef PAYOFF1_HPP
#define PAYOFF1_HPP

class payoff
{
public:
  payoff (double lower_strike, double upper_strike);
  double operator() (double spot) const;

private:
  double lower_strike_;
  double upper_strike_;
};

#endif