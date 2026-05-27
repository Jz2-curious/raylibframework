#include "RaylibFramework/Maths/Vec2.h"

#include <cassert>
#include <format>
#include <RaylibFramework/Maths/MathFunctions.h>

enum : unsigned char
{
	Size = 2
};

Vec2::Vec2()
	: x{ 0.f }, y{ 0.f }
{}

Vec2::Vec2(const float x, const float y)
	: x{ x }, y{ y }
{}

Vec2::Vec2(const Vector2& rhs)
	: x{ rhs.x }, y{ rhs.y }
{}

float Vec2::Dot(const Vec2& rhs) const
{
	return x * rhs.x + y * rhs.y;
}

float Vec2::Magnitude() const
{
	return sqrtf(x * x + y * y);
}

void Vec2::Normalise()
{
	float mag = Magnitude();

	if (MathFunctions::Approx(mag, 0.f))
	{
		x = 0.f;
		y = 0.f;
	}
	else
	{
		x /= mag;
		y /= mag;
	}
}

Vec2 Vec2::Normalised() const
{
	float mag = Magnitude();

	return MathFunctions::Approx(mag, 0.f) ? Vec2{ 0.f, 0.f } : Vec2{ x / mag, y / mag };
}

bool Vec2::IsApproximatelyEqual(const Vec2& rhs, const float e) const
{
	for (int i = 0; i < Size; ++i)
	{
		if (!MathFunctions::Approx((*this)[i], rhs[i], e))
		{
			return false;
		}
	}

	return true;
}

float Vec2::AngleBetween(const Vec2& rhs) const
{
	return acos(Dot(rhs) / (Magnitude() * rhs.Magnitude()));
}

float Vec2::Distance(const Vec2& rhs) const
{
	return (*this - rhs).Magnitude();
}

float Vec2::Angle() const
{
	return atan2(y, x);
}

void Vec2::Rotate(const float radians)
{
	const float xRotated = x * cos(radians) - y * sin(radians);
	const float yRotated = x * sin(radians) + y * cos(radians);

	x = xRotated;
	y = yRotated;
}

void Vec2::RotateAround(const Vec2& pivot, const float radians)
{
	x -= pivot.x;
	y -= pivot.y;

	Rotate(radians);

	x += pivot.x;
	y += pivot.y;
}

Vec2 Vec2::Lerp(const Vec2& b, const float t) const
{
	return *this * (1.f - t) + b * t;
}

Vec2::operator Vector2() const
{
	return { x, y };
}

Vec2 Vec2::operator-() const
{
	return Vec2{ -x, -y };
}

bool Vec2::operator==(const Vec2& rhs) const
{
	return IsApproximatelyEqual(rhs);
}

bool Vec2::operator!=(const Vec2& rhs) const
{
	return !(*this == rhs);
}

bool Vec2::operator<(const Vec2& rhs) const
{
	return Magnitude() < rhs.Magnitude();
}

Vec2 Vec2::operator+(const Vec2& rhs) const
{
	return Vec2{ x + rhs.x, y + rhs.y };
}

Vec2& Vec2::operator+=(const Vec2& rhs)
{
	*this = *this + rhs;
	return *this;
}

Vec2 Vec2::operator-(const Vec2& rhs) const
{
	return Vec2{ x - rhs.x, y - rhs.y };
}

Vec2& Vec2::operator-=(const Vec2& rhs)
{
	*this = *this - rhs;
	return *this;
}

Vec2 Vec2::operator*(const Vec2& rhs) const
{
	return Vec2{ x * rhs.x, y * rhs.y };
}

Vec2& Vec2::operator*=(const Vec2& rhs)
{
	*this = *this * rhs;
	return *this;
}

Vec2 Vec2::operator*(const float rhs) const
{
	return Vec2{ x * rhs, y * rhs };
}

Vec2& Vec2::operator*=(const float rhs)
{
	*this = *this * rhs;
	return *this;
}

Vec2 Vec2::operator/(const float rhs) const
{
	return Vec2{ x / rhs, y / rhs };
}

Vec2& Vec2::operator/=(const float rhs)
{
	*this = *this / rhs;
	return *this;
}

float& Vec2::operator[](const int index)
{
	assert(index >= 0 && index < Size);

	return (&x)[index];
}

const float& Vec2::operator[](const int index) const
{
	assert(index >= 0 && index < Size);

	return (&x)[index];
}

ostream& operator<<(ostream& stream, const Vec2& vec)
{
	stream << std::format("({:.2f}, {:.2f})", vec.x, vec.y);

	return stream;
}