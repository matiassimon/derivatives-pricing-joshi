#ifndef PAYOFF2_HPP
#define PAYOFF2_HPP

class payoff
{
public:
  payoff (){};
  virtual ~payoff (){};
  virtual double operator() (double spot) const = 0;
};

class payoff_call : public payoff
{
public:
  payoff_call (double strike);
  virtual ~payoff_call () {};
  virtual double operator() (double spot) const override;

private:
  double strike_;
};

class payoff_put : public payoff
{
public:
  payoff_put (double strike);
  virtual ~payoff_put () {};
  virtual double operator() (double spot) const override;

private:
  double strike_;
};

#endif