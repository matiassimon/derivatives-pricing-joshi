#ifndef PAYOFF1_HPP
#define PAYOFF1_HPP

class payoff
{
public:
  enum option_type
  {
    call,
    put
  };

  payoff (double strike, option_type type);
  double operator() (double spot) const;

private:
  double strike_;
  option_type type_;
};

#endif