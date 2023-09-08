#include "payoff-bridge.hpp"

payoff_bridge::payoff_bridge (const payoff_bridge &original)
{
  po_ = original.po_->clone ();
}

payoff_bridge::payoff_bridge (const payoff &po) { po_ = po.clone (); }

payoff_bridge::~payoff_bridge () { delete po_; }

payoff_bridge &
payoff_bridge::operator= (const payoff_bridge &original)
{
  if (this != &original)
    {
      delete po_;
      po_ = original.po_->clone ();
    }

  return *this;
}
