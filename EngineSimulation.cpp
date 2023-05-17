#include "EngineSimulation.h"

/**
 * \brief This is constructor of engine simulation
 * \param param Engine parameters class
 * \param temperature_suf Surface temperature
 */
engine_simulation::engine_simulation(const engine_parameters& param, const double temperature_suf):
	param(param),
	temperature_suf(temperature_suf),
	temperature(temperature_suf),
	M(0),
	V(0)
{
}

/**
 * \brief This method calculates torque based on a linear function of velocity
 * \param V Velocity
 * \return torque
 */
double engine_simulation::calculateM(double V)
{
	/*double M;
	switch (static_cast<int>(V))
	{
	case 0:
		M = 20.0;
		break;
	case 75:
		M = 75.0;
		break;
	case 150:
		M = 100.0;
		break;
	case 200:
		M = 105.0;
		break;
	case 250:
		M = 75.0;
		break;
	case 300:
		M = 0.0;
		break;
	default:
		if (V > 0 && V < 75)
		{
			M = 20.0 + (V - 0.0) * (75.0 - 20.0) / (75.0 - 0.0);
		}
		else if (V > 75 && V < 150)
		{
			M = 75.0 + (V - 75.0) * (100.0 - 75.0) / (150.0 - 75.0);
		}
		else if (V > 150 && V < 200)
		{
			M = 100.0 + (V - 150.0) * (105.0 - 100.0) / (200.0 - 150.0);
		}
		else if (V > 200 && V < 250)
		{
			M = 105.0 + (V - 200.0) * (75.0 - 105.0) / (250.0 - 200.0);
		}
		else if (V > 250 && V < 300)
		{
			M = 75.0 + (V - 250.0) * (0.0 - 75.0) / (300.0 - 250.0);
		}
		else
		{
			M = 0.0;
		}
		break;
	}

	return M;*/
	size_t n = this->param.get_velocity().size();

	// Проверка граничных условий
	if (V <= this->param.get_velocity()[0])
	{
		return this->param.get_torque()[0];
	}
	if (V >= param.get_velocity()[n - 1])
	{
		return this->param.get_torque()[n - 1];
	}

	// Поиск соответствующих интервалов
	size_t leftIndex = 0;
	size_t rightIndex = n - 1;

	for (size_t i = 1; i < n; ++i)
	{
		if (V < this->param.get_velocity()[i])
		{
			rightIndex = i;
			break;
		}
		leftIndex = i;
	}

	// Интерполяция линейной зависимости
	double leftV = this->param.get_velocity()[leftIndex];
	double rightV = this->param.get_velocity()[rightIndex];
	double leftM = param.get_torque()[leftIndex];
	double rightM = param.get_torque()[rightIndex];

	double slope = (rightM - leftM) / (rightV - leftV);
	double interpolatedM = leftM + slope * (V - leftV);

	return interpolatedM;
}

/**
 * \brief This method make engine simulation step
 * \param time current model time
 * \return tuple of temperature, torque and velocity
 */
std::tuple<double, double, double> engine_simulation::simulation_step(const double time)
{
	this->M = calculateM(V); // Текущий момент
	double a = this->M / param.get_inertia(); // Расчет ускорения
	double VH = M * this->param.get_heat_velocity_torque() + V * this->param.get_heat_rate_crankshaft_rotation_speed();
	// Расчет скорости нагрева
	double deltaT = VH * time; // Изменение температуры (deltaT = VH * t)
	this->temperature += deltaT; // Обновление значения температуры
	double VC = this->param.get_cooling_rate() * (this->temperature_suf - this->temperature);
	// Расчет скорости охлаждения
	double deltaTCooling = VC * time; // Изменение температуры от охлаждения (deltaTCooling = VC * t)
	this->temperature += deltaTCooling; // Обновление значения температуры от охлаждения
	this->V += a * time; // Обновление значения V
	return std::make_tuple(temperature, M, V); // Возращаем текущую температуру, момент и скорость
}
