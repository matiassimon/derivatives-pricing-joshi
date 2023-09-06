#ifndef PAYOFF1_HPP
#define PAYOFF1_HPP

class payoff
{
public:
  enum option_type
  {
    european_call,
    european_put,
    digital_call,
    digital_put
  };

  payoff (double strike, option_type type);
  double operator() (double spot) const;

private:
  double strike_;
  option_type type_;
};

#endif