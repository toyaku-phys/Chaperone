#pragma once
#include <cassert>

namespace cexpr_math{

template <typename T> constexpr T sqr(T s);

template <typename T> constexpr T sqrt(T s);

template <typename T> constexpr double max(const T& v1, const T& v2);

template <typename T> constexpr T pow(const T& a, const unsigned int b);

}

