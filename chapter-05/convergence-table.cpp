#include "convergence-table.hpp"

convergence_table::convergence_table (const wrapper<statistics_mc> &inner)
    : inner_ (inner)
{
  stopping_point_ = 2;
  paths_done_ = 0;
}

statistics_mc *
convergence_table::clone () const
{
  return new convergence_table (*this);
}

void
convergence_table::dump_one_result (double result)
{
  inner_->dump_one_result (result);
  ++paths_done_;

  if (paths_done_ == stopping_point_)
    {
      stopping_point_ *= 2;
      std::vector<std::vector<double>> this_results (
          inner_->get_results_so_far ());

      for (unsigned long i = 0; i < this_results.size (); i++)
        {
          this_results[i].push_back (paths_done_);
          results_so_far_.push_back (this_results[i]);
        }
    }
}

std::vector<std::vector<double>>
convergence_table::get_results_so_far () const
{
  std::vector<std::vector<double>> tmp (results_so_far_);

  if (paths_done_ * 2 != stopping_point_)
    {
      std::vector<std::vector<double>> this_result (
          inner_->get_results_so_far ());

      for (unsigned long i = 0; i < this_result.size (); i++)
        {
          this_result[i].push_back (paths_done_);
          tmp.push_back (this_result[i]);
        }
    }

  return tmp;
}