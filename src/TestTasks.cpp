#include "TestTasks.h"


/**
 * \brief This is constructor with custom settings of Test
 * \param temperature_overheat Overheat temperature
 * \param timestep Model time step
 */
TestTasks::TestTasks(const double temperature_overheat, const double timestep):
	temperature_overheat(temperature_overheat), timestep(timestep)
{
}

/**
 * \brief This is constructor with default settings of Test
 */
TestTasks::TestTasks(): temperature_overheat(110), timestep(0.5)
{
}

/**
 * \brief Test for time to engine overheating
 * \param temp_suf Surface temperature
 * \return Time when the test ended 
 */
double TestTasks::temperature_test(const double temp_suf) const
{
	double TestTime = 0;
	EngineParameters parameters;
	engine_simulation simulation(parameters, temp_suf);
	double temperature = temp_suf, M, V;
	while (temperature < this->temperature_overheat)
	{
		std::tie(temperature, M, V) = simulation.simulation_step(TestTime);
		TestTime += this->timestep;
	}
	return TestTime;
}

/**
 * \brief Maximum engine power test
 * \return Maximum engine power
 */
double TestTasks::max_power_test()
{
	double TestTime = 0;
	EngineParameters parameters;
	engine_simulation simulation(parameters, 0);
	double temperature = 0, M, V;
	double N = 1, Nmax = -10, N_pred = -1;
	while (true)
	{
		std::tie(temperature, M, V) = simulation.simulation_step(TestTime);
		N = M * V / 1000;
		if (N > Nmax)
		{
			Nmax = N;
		}
		else
		{
			break;
		}
		TestTime += this->timestep;
	}
	return Nmax;
}
