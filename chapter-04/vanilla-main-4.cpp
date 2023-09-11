#include <iostream>

#include "simple-mc-6.hpp"
#include "vanilla-3.hpp"

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

  parameters_constant vol_param (vol);
  parameters_constant r_param (r);
  payoff_call po (strike);
  vanilla_option option (po, expirity);

  double result = simple_monte_carlo_4 (option, spot, vol_param, r_param,
                                        number_of_paths);

  cout << "The call price is " << result << endl;

  vanilla_option second_option (option);

  result = simple_monte_carlo_4 (option, spot, vol_param, r_param,
                                 number_of_paths);

  cout << "The call price is " << result << endl;

  payoff_put other_po (strike);
  vanilla_option third_option (other_po, expirity);
  option = third_option;

  result = simple_monte_carlo_4 (option, spot, vol_param, r_param,
                                 number_of_paths);

  cout << "The put price is " << result << endl;
}
