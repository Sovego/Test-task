#pragma once
#include <vector>

/**
 * \brief Engine parameters class
 */
class EngineParameters
{
public:
	EngineParameters(double inertia, std::vector<int> torque, const std::vector<int>& veloсity,
	                 double heat_velocity_torque,
	                 double heat_rate_crankshaft_rotation_speed, double cooling_rate);

	EngineParameters();
	void set_torgue(const std::vector<int>&);
	std::vector<int> get_torque();
	void set_velocity(const std::vector<int>&);
	std::vector<int> get_velocity();
	void set_inertia(double);
	double get_inertia() const;
	void set_heat_velocity_torque(double);
	double get_heat_velocity_torque() const;
	void set_heat_rate_crankshaft_rotation_speed(double);
	double get_heat_rate_crankshaft_rotation_speed() const;
	void set_cooling_rate(double);
	double get_cooling_rate() const;

private:
	double inertia;
	std::vector<int> torque;
	std::vector<int> veloсity;

	double heat_velocity_torque;
	double heat_rate_crankshaft_rotation_speed;
	double cooling_rate;
};
