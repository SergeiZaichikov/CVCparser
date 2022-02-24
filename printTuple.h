#pragma once
#include <iostream>
#include <tuple>
#include <functional>
#include <sstream>

template<typename... Args>
auto& operator<<(std::ostream& stream, std::tuple<Args...> const& theTuple) {
    std::apply(
        [&stream](Args const&... args) {
            stream << '[';
            std::size_t n{ 0 };
            ((stream << args << (++n != sizeof...(Args) ? "; " : "")), ...);
            stream << ']';
        }, theTuple
    );
    return stream;
}