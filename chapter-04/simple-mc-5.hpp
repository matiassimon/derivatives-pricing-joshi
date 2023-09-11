#ifndef SIMPLEMC5_HPP
#define SIMPLEMC5_HPP

#include "vanilla-3.hpp"

double simple_monte_carlo_3 (const vanilla_option &option, double spot,
                             double vol, double r,
                             unsigned long number_of_paths);

#endif