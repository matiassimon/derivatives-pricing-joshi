#ifndef SIMPLEMC6_HPP
#define SIMPLEMC6_HPP

#include "chapter-04/parameters.hpp"
#include "chapter-04/vanilla-3.hpp"
#include "mc-statistics.hpp"

void simple_monte_carlo_5 (const vanilla_option &option, double spot,
                           const parameters &vol, const parameters &r,
                           unsigned long number_of_paths,
                           statistics_mc &gatherer);

#endif