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

  payoff po_call (strike, payoff::call);
  payoff po_put (strike, payoff::put);

  double result_call = simple_monte_carlo_2 (po_call, expirity, spot, vol, r,
                                             number_of_paths);

  double result_put
      = simple_monte_carlo_2 (po_put, expirity, spot, vol, r, number_of_paths);

  cout << "The prices are " << result_call << " for the call and "
       << result_put << " for the put" << endl;
}
