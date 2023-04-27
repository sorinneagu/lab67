#pragma once
#include <type_traits>
// Create an enum class called EntityType with the following values : EMPTY, FOX, GOPHER, PLANT

enum class EntityType {
    Empty,
    Fox,
    Gopher,
    Plant
};

template <typename T>
constexpr auto to_underlying(T e)
{
    return static_cast<std::underlying_type_t<T>>(e);
}