//
// Created by Bastian Inuk Christensen on 2022-10-23.
//

#include "pipe.h"

template<typename InputStream, typename OutputStrem, typename Input, typename Output>
requires Observer<Input, InputStream> &&
         Observer<Output, OutputStrem> &&
         Emitter<Input, OutputStrem>
OutputStrem operator |(InputStream left,OutputStrem right)
{
    left.observe([&](auto value){
        right.emit(value);
    });

    return right;
}