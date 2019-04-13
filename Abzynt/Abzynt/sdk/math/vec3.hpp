#pragma once
#include "../sdk.hpp"

class vec3 {
public:
	float x, y, z;

	vec3()
	{
		x = y = z = std::numeric_limits<float>::infinity();
	}

	vec3(float a, float b, float c)
	{
		x = a;
		y = b;
		z = c;
	}

	bool is_good()
	{
		return std::isfinite(x) && std::isfinite(y) && std::isfinite(z);
	}
};