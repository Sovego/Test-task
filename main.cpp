#include "TestTasks.h"
#include "TUI.h"

int main(int argc, const char* argv[])
{
	const double suf_temp = tui::input_dialog();
	test_tasks test;
	const double time = test.temperature_test(suf_temp);
	const double N = test.max_power_test();
	tui::output_dialog(time, N);
	return 0;
}
