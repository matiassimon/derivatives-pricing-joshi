#include "vanilla-2.hpp"

vanilla_option::vanilla_option (const payoff &po, double expirity)
    : expirity_ (expirity)
{
  po_ = po.clone ();
}

vanilla_option::vanilla_option (const vanilla_option &original)
{
  expirity_ = original.expirity_;
  po_ = original.po_->clone ();
}

vanilla_option &
vanilla_option::operator= (const vanilla_option &original)
{
  if (this != &original)
    {
      expirity_ = original.expirity_;
      delete po_;
      po_ = original.po_->clone ();
    }

  return *this;
}

vanilla_option::~vanilla_option () { delete po_; }

double
vanilla_option::get_expirity () const
{
  return expirity_;
}

double
vanilla_option::option_payoff (double spot) const
{
  return (*po_) (spot);
}
