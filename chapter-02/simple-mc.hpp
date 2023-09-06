#ifndef SIMPLEMC_HPP
#define SIMPLEMC_HPP

#include "payoff-1.hpp"

double simple_monte_carlo_2 (const payoff& po, double expirity, double spot,
                             double vol, double r,
                             unsigned long number_of_paths);

#endif