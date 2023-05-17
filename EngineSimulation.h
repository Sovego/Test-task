#pragma once
#include "EngineParameters.h"
#include <math.h>
/**
 * \brief Class for engine simulation
 */
class engine_simulation
{
public:
	engine_simulation(const engine_parameters& param, double temperature_suf);
	std::tuple<double, double, double> simulation_step(double);

private:
	engine_parameters param;
	double temperature_suf;
	double temperature;
	double M;
	double V;
	double calculateM(double);
};
