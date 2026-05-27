#include "RaylibFramework/Maths/Mat3.h"

#include <cassert>
#include <RaylibFramework/Maths/MathFunctions.h>

enum : unsigned char
{
	Size = 9
};

Mat3 Mat3::MakeTranslate(const Vec2& trans)
{
	return
	{
		1.f, 0.f, 0.f,
		0.f, 1.f, 0.f,
		trans.x, trans.y, 1.f
	};
}

Mat3 Mat3::MakeTranslate(float x, float y)
{
	return MakeTranslate({ x, y });
}

Mat3 Mat3::MakeRotate(const float rad)
{
	const float c = cos(rad);
	const float s = sin(rad);

	return
	{
		c, s, 0.f,
		-s, c, 0.f,
		0.f, 0.f, 1.f
	};
}

Mat3 Mat3::MakeScale(const Vec2& scale)
{
	return
	{
		scale.x, 0.f, 0.f,
		0.f, scale.y, 0.f,
		0.f, 0.f, 1.f
	};
}

Mat3 Mat3::MakeScale(float x, float y)
{
	return MakeScale({ x, y });
}

Mat3::Mat3() :
	m1{ 1.f }, m2{ 0.f }, m3{ 0.f },
	m4{ 0.f }, m5{ 1.f }, m6{ 0.f },
	m7{ 0.f }, m8{ 0.f }, m9{ 1.f }
{}

Mat3::Mat3(const float m1, const float m2, const float m3,
	const float m4, const float m5, const float m6,
	const float m7, const float m8, const float m9) :
	m1{ m1 }, m2{ m2 }, m3{ m3 },
	m4{ m4 }, m5{ m5 }, m6{ m6 },
	m7{ m7 }, m8{ m8 }, m9{ m9 }
{}

Vec2 Mat3::GetRight() const
{
	return Vec2{ m1, m2 };
}

Vec2 Mat3::GetForward() const
{
	return Vec2{ m4, m5 };
}

Vec2 Mat3::GetTranslate() const
{
	return Vec2{ m7, m8 };
}

Vec2 Mat3::GetScale() const
{
	const Vec2 xAxis = GetRight();
	const Vec2 yAxis = GetForward();

	return
	{
		xAxis.Magnitude(),
		yAxis.Magnitude()
	};
}

float Mat3::GetRotation() const
{
	return atan2(m2, m1);
}

bool Mat3::IsApproximatelyEqual(const Mat3& matrix, const float e) const
{
	for (int i = 0; i < Size; ++i)
	{
		if (!MathFunctions::Approx((*this)[i], matrix[i], e))
		{
			return false;
		}
	}

	return true;
}

Vec2 Mat3::operator*(const Vec2& rhs) const
{
	return
	{
		m1 * rhs.x + m4 * rhs.y + m7,
		m2 * rhs.x + m5 * rhs.y + m8
	};
}

Mat3 Mat3::operator*(const Mat3& rhs) const
{
	return
	{
		// Column 0 of result
		m1 * rhs.m1 + m4 * rhs.m2 + m7 * rhs.m3,
		m2 * rhs.m1 + m5 * rhs.m2 + m8 * rhs.m3,
		m3 * rhs.m1 + m6 * rhs.m2 + m9 * rhs.m3,
		// Column 1 of result
		m1 * rhs.m4 + m4 * rhs.m5 + m7 * rhs.m6,
		m2 * rhs.m4 + m5 * rhs.m5 + m8 * rhs.m6,
		m3 * rhs.m4 + m6 * rhs.m5 + m9 * rhs.m6,
		// Column 2 of result
		m1 * rhs.m7 + m4 * rhs.m8 + m7 * rhs.m9,
		m2 * rhs.m7 + m5 * rhs.m8 + m8 * rhs.m9,
		m3 * rhs.m7 + m6 * rhs.m8 + m9 * rhs.m9
	};
}

Mat3& Mat3::operator*=(const Mat3& rhs)
{
	*this = *this * rhs;
	return *this;
}

bool Mat3::operator==(const Mat3& rhs) const
{
	return IsApproximatelyEqual(rhs);
}

bool Mat3::operator!=(const Mat3& rhs) const
{
	return !(*this == rhs);
}

float& Mat3::operator[](const int index)
{
	assert(index >= 0 && index < Size);

	return (&m1)[index];
}

const float& Mat3::operator[](const int index) const
{
	assert(index >= 0 && index < Size);

	return (&m1)[index];
}