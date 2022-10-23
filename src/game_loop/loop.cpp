//
// Created by Bastian Inuk Christensen on 2022-10-23.
//

#include "loop.h"

#include <chrono>

using namespace kuni;

loop loop::begin()
{
    return loop(_shouldQuit);
}

loop loop::end()
{
    return loop(_shouldQuit);
}

bool loop::operator!=(const kuni::loop &_)
{
    return *_shouldQuit;
}

void loop::operator++()
{}

uint64_t loop::operator*()
{
    const uint64_t now = std::chrono::system_clock::now()
            .time_since_epoch()
            .count();

    const uint64_t delta =
            lastTimestamp == 0
            ? 0
            : now - lastTimestamp;
    lastTimestamp = now;

    return delta;
}