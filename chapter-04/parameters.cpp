#include "parameters.hpp"

parameters::parameters (const parameters_inner &inner_object)
{
  inner_object_ = inner_object.clone ();
}

parameters::parameters (const parameters &original)
{
  inner_object_ = original.inner_object_->clone ();
}

parameters::~parameters () { delete inner_object_; }

parameters &
parameters::operator= (const parameters &original)
{
  if (this != &original)
    {
      delete inner_object_;
      inner_object_ = original.inner_object_->clone ();
    }

  return *this;
}

double
parameters::mean (double time_1, double time_2) const
{
  double total = integral (time_1, time_2);
  return total / (time_2 - time_1);
}

double
parameters::root_mean_square (double time_1, double time_2) const
{
  double total = integral_square (time_1, time_2);
  return total / (time_2 - time_1);
}

parameters_constant::parameters_constant (double constant)
    : constant_ (constant), constant_square_ (constant * constant)
{
}

parameters_inner *
parameters_constant::clone () const
{
  return new parameters_constant (*this);
}

double
parameters_constant::integral (double time_1, double time_2) const
{
  return (time_2 - time_1) * constant_;
}

double
parameters_constant::integral_square (double time_1, double time_2) const
{
  return (time_2 - time_1) * constant_square_;
}
