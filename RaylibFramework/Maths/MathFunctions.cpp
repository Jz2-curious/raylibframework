#include "RaylibFramework/Maths/MathFunctions.h"

#include <algorithm>
#include <cmath>

bool MathFunctions::Approx(const float a, const float b, const float e)
{
	return std::abs(a - b) <= e * std::max({1.f, std::abs(a), std::abs(b)});
}

float MathFunctions::Clamp(float value, const float min, const float max)
{
	value = std::max(value, min);
	value = std::min(value, max);

	return value;
}

float MathFunctions::Clamp01(const float value)
{
	return Clamp(value, 0.f, 1.f);
}