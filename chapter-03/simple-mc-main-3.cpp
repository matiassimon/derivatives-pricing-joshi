#include <iostream>

#include "simple-mc-2.hpp"
#include "power.hpp"

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
  double i;

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

  cout << "Enter power i" << endl;
  cin >> i;

  payoff_power_call po_call (i, strike);
  payoff_power_put po_put (i, strike);

  double result_call = simple_monte_carlo_2 (po_call, expirity, spot, vol, r,
                                             number_of_paths);

  double result_put
      = simple_monte_carlo_2 (po_put, expirity, spot, vol, r, number_of_paths);

  cout << "The prices for power options are " << result_call << " for the call and "
       << result_put << " for the put" << endl;
}
