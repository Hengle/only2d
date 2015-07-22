#include "Console.h"

namespace only2d
{
	const std::string Console::endl = "\n";

	const Console Console::debug = Console();
	const Console Console::log = Console();
	const Console Console::error = Console();
}