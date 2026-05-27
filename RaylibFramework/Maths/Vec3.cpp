#include "RaylibFramework/Maths/Vec3.h"

#include <cassert>
#include <format>
#include <RaylibFramework/Maths/MathFunctions.h>

enum : unsigned char
{
	Size = 3
};

Vec3::Vec3()
	: x{ 0.f }, y{ 0.f }, z{ 0.f }
{}

Vec3::Vec3(const float x, const float y, const float z)
	: x{ x }, y{ y }, z{ z }
{}

Vec3::Vec3(const Vector3& rhs)
	: x{ rhs.x }, y{ rhs.y }, z{ rhs.z }
{}

float Vec3::Dot(const Vec3& rhs) const
{
	return x * rhs.x + y * rhs.y + z * rhs.z;
}

Vec3 Vec3::Cross(const Vec3& rhs) const
{
	return
	{
		y * rhs.z - z * rhs.y,
		z * rhs.x - x * rhs.z,
		x * rhs.y - y * rhs.x
	};
}

float Vec3::Magnitude() const
{
	return sqrtf(x * x + y * y + z * z);
}

void Vec3::Normalise()
{
	float mag = Magnitude();

	if (MathFunctions::Approx(mag, 0.f))
	{
		x = 0.f;
		y = 0.f;
		z = 0.f;
	}
	else
	{
		x /= mag;
		y /= mag;
		z /= mag;
	}
}

Vec3 Vec3::Normalised() const
{
	const float mag = Magnitude();

	return MathFunctions::Approx(mag, 0.f) ? Vec3{ 0.f, 0.f, 0.f } : Vec3{ x / mag, y / mag, z / mag };
}

bool Vec3::IsApproximatelyEqual(const Vec3& rhs, const float e) const
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

float Vec3::AngleBetween(const Vec3& rhs) const
{
	return acos(Dot(rhs) / (Magnitude() * rhs.Magnitude()));
}

float Vec3::Distance(const Vec3& rhs) const
{
	return (*this - rhs).Magnitude();
}

float Vec3::Angle2D() const
{
	return atan2(y, x);
}

Vec3::operator Vector3() const
{
	return { x, y, z };
}

Vec3 Vec3::operator-() const
{
	return Vec3{ -x, -y, -z };
}

bool Vec3::operator==(const Vec3& rhs) const
{
	return IsApproximatelyEqual(rhs);
}

bool Vec3::operator!=(const Vec3& rhs) const
{
	return !(*this == rhs);
}

bool Vec3::operator<(const Vec3& rhs) const
{
	return Magnitude() < rhs.Magnitude();
}

Vec3 Vec3::operator+(const Vec3& rhs) const
{
	return Vec3{ x + rhs.x, y + rhs.y, z + rhs.z };
}

Vec3& Vec3::operator+=(const Vec3& rhs)
{
	*this = *this + rhs;
	return *this;
}

Vec3 Vec3::operator-(const Vec3& rhs) const
{
	return Vec3{ x - rhs.x, y - rhs.y, z - rhs.z };
}

Vec3& Vec3::operator-=(const Vec3& rhs)
{
	*this = *this - rhs;
	return *this;
}

Vec3 Vec3::operator*(const Vec3& rhs) const
{
	return Vec3{ x * rhs.x, y * rhs.y, z * rhs.z };
}

Vec3& Vec3::operator*=(const Vec3& rhs)
{
	*this = *this * rhs;
	return *this;
}

Vec3 Vec3::operator*(const float rhs) const
{
	return Vec3{ x * rhs, y * rhs, z * rhs };
}

Vec3& Vec3::operator*=(const float rhs)
{
	*this = *this * rhs;
	return *this;
}

Vec3 Vec3::operator/(const float rhs) const
{
	return Vec3{ x / rhs, y / rhs, z / rhs };
}

Vec3& Vec3::operator/=(const float rhs)
{
	*this = *this / rhs;
	return *this;
}

float& Vec3::operator[](const int index)
{
	assert(index >= 0 && index < Size);

	return (&x)[index];
}

const float& Vec3::operator[](const int index) const
{
	assert(index >= 0 && index < Size);

	return (&x)[index];
}

ostream& operator<<(ostream& stream, const Vec3& vec)
{
	stream << std::format("({:.2f}, {:.2f}, {:.2f})", vec.x, vec.y, vec.y);

	return stream;
}
