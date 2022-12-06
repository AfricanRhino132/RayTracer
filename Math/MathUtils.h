#pragma once

#include <glm/glm.hpp>
#include <cstdlib>
#include <algorithm>

inline float random01()
{
	return rand() / (float)RAND_MAX;
}

inline float random(float min, float max)
{
	if (min > max)
	{
		std::swap(min, max);
	}

	return min + (max - min) * random01();
}

template <typename T>
inline T interp(T a, T b, float t)
{
	return (a * (1.0f - t)) + (b * t);
}