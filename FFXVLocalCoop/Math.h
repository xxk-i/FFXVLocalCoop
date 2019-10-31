#pragma once
#include <xmmintrin.h>

struct VectorA
{
	__m128 vec;
};

struct __double4
{
	long double f64[4];
};

struct DoubleVector4
{
	__double4 vec;
};