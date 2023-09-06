#include <iostream>

#include "simple-mc.hpp"

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

  payoff po_eu_call (strike, payoff::european_call);
  payoff po_eu_put (strike, payoff::european_put);
  payoff po_dig_call (strike, payoff::digital_call);
  payoff po_dig_put (strike, payoff::digital_put);

  double result_eu_call = simple_monte_carlo_2 (po_eu_call, expirity, spot,
                                                vol, r, number_of_paths);

  double result_eu_put = simple_monte_carlo_2 (po_eu_put, expirity, spot, vol,
                                               r, number_of_paths);

  double result_dig_call = simple_monte_carlo_2 (po_dig_call, expirity, spot,
                                                vol, r, number_of_paths);

  double result_dig_put = simple_monte_carlo_2 (po_dig_put, expirity, spot, vol,
                                               r, number_of_paths);

  cout << "The prices for European options are " << result_eu_call << " for the call and "
       << result_eu_put << " for the put" << endl;

  cout << "The prices for digital options are " << result_dig_call << " for the call and "
       << result_dig_put << " for the put" << endl;
       
}
