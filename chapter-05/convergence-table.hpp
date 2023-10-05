#ifndef CONVERGENCETABLE_HPP
#define CONVERGENCETABLE_HPP

#include "mc-statistics.hpp"
#include "wrapper.hpp"

class convergence_table : public statistics_mc
{
public:
  convergence_table (const wrapper<statistics_mc> &inner);
  virtual statistics_mc *clone () const override;
  virtual void dump_one_result (double result) override;
  virtual std::vector<std::vector<double>>
  get_results_so_far () const override;

private:
  wrapper<statistics_mc> inner_;
  std::vector<std::vector<double>> results_so_far_;
  unsigned long stopping_point_;
  unsigned long paths_done_;
};

#endif