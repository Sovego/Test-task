#include "EngineParameters.h"

/**
 * \brief This is constructor with default settings
 */
engine_parameters::engine_parameters():
	inertia(10),
	torque({20, 75, 100, 105, 75, 0}),
	veloсity({0, 75, 150, 200, 250, 300}),
	heat_velocity_torque(0.01),
	heat_rate_crankshaft_rotation_speed(0.0001),
	cooling_rate(0.1)
{
}

/**
 * \brief Setter for torque
 * \param torque torque values as a function of velocity
 */
void engine_parameters::set_torgue(const std::vector<int>& torque)
{
	this->torque = torque;
}

/**
 * \brief Getter fot torque
 * \return torque
 */
std::vector<int> engine_parameters::get_torque()
{
	return this->torque;
}

/**
 * \brief Setter for velocity
 * \param velocity velocity values as a function of the torque dependence 
 */
void engine_parameters::set_velocity(const std::vector<int>& velocity)
{
	this->veloсity = velocity;
}

/**
 * \brief Getter for velocity
 * \return velocity
 */
std::vector<int> engine_parameters::get_velocity()
{
	return this->veloсity;
}

/**
 * \brief Setter for inertia
 * \param inertia Engine moment of inertia
 */
void engine_parameters::set_inertia(const double inertia)
{
	this->inertia = inertia;
}

/**
 * \brief Getter for inertia
 * \return inertia
 */
double engine_parameters::get_inertia() const
{
	return this->inertia;
}

/**
 * \brief Setter for Heating rate-torque relationship coefficient
 * \param heat_velocity_torque Heating rate-torque relationship coefficient
 */
void engine_parameters::set_heat_velocity_torque(const double heat_velocity_torque)
{
	this->heat_velocity_torque = heat_velocity_torque;
}

/**
 * \brief Getter for heat_velocity_torque
 * \return Heating rate-torque relationship coefficient
 */
double engine_parameters::get_heat_velocity_torque() const
{
	return this->heat_velocity_torque;
}

/**
 * \brief Setter for heat_rate_crankshaft_rotation_speed
 * \param heat_rate_crankshaft_rotation_speed Heating rate coefficient as a function of crankshaft rotation speed
 */
void engine_parameters::set_heat_rate_crankshaft_rotation_speed(const double heat_rate_crankshaft_rotation_speed)
{
	this->heat_rate_crankshaft_rotation_speed = heat_rate_crankshaft_rotation_speed;
}

/**
 * \brief Getter for heat_rate_crankshaft_rotation_speed
 * \return Heating rate coefficient as a function of crankshaft rotation speed
 */
double engine_parameters::get_heat_rate_crankshaft_rotation_speed() const
{
	return this->heat_rate_crankshaft_rotation_speed;
}

/**
 * \brief Setter for cooling_rate
 * \param cooling_rate Coefficient of dependence of cooling rate on engine temperature and ambient temperature
 */
void engine_parameters::set_cooling_rate(const double cooling_rate)
{
	this->cooling_rate = cooling_rate;
}

/**
 * \brief Getter for cooling_rate
 * \return Coefficient of dependence of cooling rate on engine temperature and ambient temperature
 */
double engine_parameters::get_cooling_rate() const
{
	return this->cooling_rate;
}

/**
 * \brief This is constructor with custom engine settings
 * \param inertia Engine moment of inertia
 * \param torque Torque values as a function of velocity
 * \param veloсity Velocity values as a function of the torque dependence 
 * \param heat_velocity_torque Heating rate-torque relationship coefficient
 * \param heat_rate_crankshaft_rotation_speed Heating rate coefficient as a function of crankshaft rotation speed
 * \param cooling_rate Coefficient of dependence of cooling rate on engine temperature and ambient temperature
 */
engine_parameters::engine_parameters(const double inertia, std::vector<int> torque, const std::vector<int>& veloсity,
                                     const double heat_velocity_torque,
                                     const double heat_rate_crankshaft_rotation_speed, const double cooling_rate):
	inertia(inertia),
	torque(std::move(torque)),
	veloсity(veloсity),
	heat_velocity_torque(heat_velocity_torque),
	heat_rate_crankshaft_rotation_speed(heat_rate_crankshaft_rotation_speed),
	cooling_rate(cooling_rate)
{
}
