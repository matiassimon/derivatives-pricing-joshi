#ifndef PARAMETERS_HPP
#define PARAMETERS_HPP

#include <memory>

class parameters_inner
{
public:
  parameters_inner (){};
  virtual ~parameters_inner (){};
  virtual parameters_inner *clone () const = 0;
  virtual double integral (double time_1, double time_2) const = 0;
  virtual double integral_square (double time_1, double time_2) const = 0;
};

class parameters
{
public:
  parameters (const parameters_inner &inner_object);
  virtual ~parameters ();

  // Movable
  parameters (parameters &&original);
  parameters &operator= (parameters &&original);

  // Copyable
  parameters (const parameters &original);
  parameters &operator= (const parameters &original);

  inline double integral (double time_1, double time_2) const;
  inline double integral_square (double time_1, double time_2) const;

  double mean (double time_1, double time_2) const;
  double root_mean_square (double time_1, double time_2) const;

private:
  std::unique_ptr<parameters_inner> inner_object_;
};

inline double
parameters::integral (double time_1, double time_2) const
{
  return inner_object_->integral (time_1, time_2);
}

inline double
parameters::integral_square (double time_1, double time_2) const
{
  return inner_object_->integral_square (time_1, time_2);
}

class parameters_constant : public parameters_inner
{
public:
  parameters_constant (double constant);

  virtual parameters_inner *clone () const;
  virtual double integral (double time_1, double time_2) const;
  virtual double integral_square (double time_1, double time_2) const;

private:
  double constant_;
  double constant_square_;
};

#endif