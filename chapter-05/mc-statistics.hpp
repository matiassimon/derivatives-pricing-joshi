#ifndef MCSTATISTICS_HPP
#define MCSTATISTICS_HPP

#include <vector>

class statistics_mc
{
public:
  statistics_mc (){};
  virtual ~statistics_mc (){};

  virtual statistics_mc *clone () const = 0;
  virtual void dump_one_result (double result) = 0;
  virtual std::vector<std::vector<double> > get_results_so_far () const = 0;
};

class statistics_mean : public statistics_mc
{
public:
  statistics_mean ();

  virtual statistics_mc *clone () const override;
  virtual void dump_one_result (double result) override;
  virtual std::vector<std::vector<double> >
  get_results_so_far () const override;

private:
  double running_sum_;
  unsigned long paths_done_;
};

#endif