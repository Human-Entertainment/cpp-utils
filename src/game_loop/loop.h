//
// Created by Bastian Inuk Christensen on 2022-10-23.
//
#pragma once

#include <cstdint>

namespace kuni {
    class loop {
        uint64_t lastTimestamp = 0;
        bool *_shouldQuit;
    public:
        /**
         *
         * @param shouldQuit pointer to quit handler
         * @note THIS IS UNTESTED
         */
        loop(bool *shouldQuit): _shouldQuit(shouldQuit)
        {}

        loop begin();

        loop end();

        bool operator !=(const loop &_);

        uint64_t operator *();

        void operator ++();
    };
}

