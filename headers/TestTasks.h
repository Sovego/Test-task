#pragma once
#include <tuple>

#include "EngineSimulation.h"
/**
 * \brief Class for test tasks
 */
class TestTasks
{
public:
	TestTasks(double temperature_overheat, double timestep);
	TestTasks();

	double temperature_test(double) const;
	double max_power_test();

private:
	double temperature_overheat;
	double timestep;
};
