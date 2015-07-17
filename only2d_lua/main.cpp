//
// Created by leafnsand on 2015/7/10.
//

#include "LuaOnly2D.h"

using namespace only2d;

int main(int argc, char *argv[])
{
	auto app = Module::open<LuaOnly2D>(ModuleType::APPLICATION);
	return app->run(argc, argv);
}
