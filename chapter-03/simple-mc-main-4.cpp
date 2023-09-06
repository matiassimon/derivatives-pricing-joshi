#include <iostream>

#include "simple-mc-2.hpp"

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

  unsigned long option_type;

  cout << "Enter 0 for call, otherwise put" << endl;
  cin >> option_type;

  payoff *po;

  if (option_type == 0)
    po = new payoff_call (strike);
  else
    po = new payoff_put (strike);

  double result
      = simple_monte_carlo_2 (*po, expirity, spot, vol, r, number_of_paths);

  cout << "The price is " << result << endl;
}
