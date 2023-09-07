#ifndef SIMPLEMC2_HPP
#define SIMPLEMC2_HPP

#include "payoff-2.hpp"

double simple_monte_carlo_2 (const payoff& po, double expirity, double spot,
                             double vol, double r,
                             unsigned long number_of_paths);

#endif