#include "TUI.h"


/**
 * \brief This method input user information
 * \return surface temperature (or other user information)
 */
double tui::input_dialog()
{
	double temp_suf;
	std::cout << "---------------------------" << std::endl;
	std::cout << "Input surface temperature: ";
	std::cin >> temp_suf;
	std::cout << "---------------------------" << std::endl;
	return temp_suf;
}

/**
 * \brief This method write to console output of tests
 * \param time Overheating time
 * \param N Max Power
 */
void tui::output_dialog(const double time, const double N)
{
	std::cout << "------------------" << std::endl;
	std::cout << "Overheating time: " << time << std::endl;
	std::cout << "Max power: " << N << std::endl;
	std::cout << "------------------" << std::endl;
}
