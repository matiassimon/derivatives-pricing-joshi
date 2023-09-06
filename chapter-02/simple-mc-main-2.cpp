#include <iostream>

#include "simple-mc.hpp"

using namespace std;

int
main ()
{
  double expirity;
  double lower_strike;
  double upper_strike;
  double spot;
  double vol;
  double r;
  unsigned long number_of_paths;

  cout << "Enter expirity" << endl;
  cin >> expirity;

  cout << "Enter lower strike" << endl;
  cin >> lower_strike;

  cout << "Enter upper strike" << endl;
  cin >> upper_strike;

  cout << "Enter spot" << endl;
  cin >> spot;

  cout << "Enter vol" << endl;
  cin >> vol;

  cout << "Enter r" << endl;
  cin >> r;

  cout << "Enter number of paths" << endl;
  cin >> number_of_paths;

  payoff po (lower_strike, upper_strike);

  double result
      = simple_monte_carlo_2 (po, expirity, spot, vol, r, number_of_paths);

  cout << "The price is " << result << endl;
}
