#pragma once
#include <tuple>

#include "./EngineSimulation.h"
/**
 * \brief Class for test tasks
 */
class test_tasks
{
public:
	test_tasks(double temperature_overheat, double timestep);
	test_tasks();

	double temperature_test(double) const;
	double max_power_test() const;

private:
	double temperature_overheat;
	double timestep;
};
