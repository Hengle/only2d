//
// Created by leafnsand on 2015/6/4.
//

#include "Sample.h"

int main(int argc, char *argv[])
{
    auto app = Module::open<Sample>(ModuleType::APPLICATION);
    return app->run(argc, argv);
}