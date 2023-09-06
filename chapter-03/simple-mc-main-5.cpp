#include <iostream>

#include "double-digital.hpp"
#include "simple-mc-2.hpp"

using namespace std;

int
main ()
{
  double expirity;
  double low;
  double up;
  double spot;
  double vol;
  double r;
  unsigned long number_of_paths;

  cout << "Enter expirity" << endl;
  cin >> expirity;

  cout << "Enter low barrier" << endl;
  cin >> low;

  cout << "Enter up barrier" << endl;
  cin >> up;

  cout << "Enter spot" << endl;
  cin >> spot;

  cout << "Enter vol" << endl;
  cin >> vol;

  cout << "Enter r" << endl;
  cin >> r;

  cout << "Enter number of paths" << endl;
  cin >> number_of_paths;

  payoff_double_digital po (low, up);

  double result
      = simple_monte_carlo_2 (po, expirity, spot, vol, r, number_of_paths);

  cout << "The price is " << result << endl;
}
