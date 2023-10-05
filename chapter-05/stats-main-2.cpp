#include <iostream>

#include "chapter-04/vanilla-3.hpp"
#include "convergence-table.hpp"
#include "mc-statistics.hpp"
#include "simple-mc-7.hpp"

using namespace std;

int
main ()
{
  double expirity;
  double strike;
  double spot;
  double vol;
  double r;
  unsigned long number_of_paths;

  cout << "Enter expirity" << endl;
  cin >> expirity;

  cout << "Enter strike" << endl;
  cin >> strike;

  cout << "Enter spot" << endl;
  cin >> spot;

  cout << "Enter vol" << endl;
  cin >> vol;

  cout << "Enter r" << endl;
  cin >> r;

  cout << "Enter number of paths" << endl;
  cin >> number_of_paths;

  payoff_call po (strike);

  vanilla_option option (po, expirity);

  parameters_constant vol_param (vol);
  parameters_constant r_param (r);

  statistics_mean gatherer;
  convergence_table gatherer_two (gatherer);

  simple_monte_carlo_5 (option, spot, vol_param, r_param, number_of_paths,
                        gatherer_two);

  vector<vector<double>> results = gatherer_two.get_results_so_far ();

  cout << "For the call price the results are " << endl;

  for (unsigned long i = 0; i < results.size (); i++)
    {
      for (unsigned long j = 0; j < results[i].size (); j++)
        cout << results[i][j] << " ";

      cout << endl;
    }
}
