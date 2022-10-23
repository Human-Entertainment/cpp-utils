//
// Created by Bastian Inuk Christensen on 2022-10-23.
//

#pragma once

template<typename T, typename Stream>
    concept Emitter =
    requires(Stream stream, T value) {
        { stream.emit(value) };
    };
template<typename T, typename Stream>
    concept Observer =
    requires(Stream stream) {
        { stream.observe([](T value){}) };
    };

template<typename InputStream, typename OutputStrem, typename Input, typename Output>
requires Observer<Input, InputStream> &&
         Observer<Output, OutputStrem> &&
         Emitter<Input, OutputStrem>
OutputStrem operator |(InputStream left,OutputStrem right);