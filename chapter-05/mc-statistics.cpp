#include "mc-statistics.hpp"

using namespace std;

statistics_mean::statistics_mean () : running_sum_ (0.0), paths_done_ (0UL) {}

statistics_mc *
statistics_mean::clone () const
{
  return new statistics_mean (*this);
}

void
statistics_mean::dump_one_result (double result)
{
  paths_done_++;
  running_sum_ += result;
}

vector<vector<double>>
statistics_mean::get_results_so_far () const
{
  vector<vector<double>> results (1);
  results[0].resize (1);
  results[0][0] = running_sum_ / paths_done_;

  return results;
}