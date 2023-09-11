#ifndef SIMPLEMC6_HPP
#define SIMPLEMC6_HPP

#include "vanilla-3.hpp"
#include "parameters.hpp"

double simple_monte_carlo_4 (const vanilla_option &option, double spot,
                             const parameters& vol, const parameters& r,
                             unsigned long number_of_paths);

#endif