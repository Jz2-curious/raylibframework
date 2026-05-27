#pragma once

#include <ostream>
#include <raylib/raylib.h>
#include <RaylibFramework/RaylibFramework.h>

using std::ostream;

/**
 * @brief A 2D vector with x and y components.
 */
struct DLL Vec2
{
public:
    /** @brief The x component. */
    float x;
    /** @brief The y component. */
    float y;

public:
    /**
     * @brief Default constructor. Initialises x and y to zero.
     */
    Vec2();

    /**
     * @brief Constructs a Vec2 with given x and y values.
     * @param x The x component.
     * @param y The y component.
     */
    Vec2(float x, float y);

    /**
     * @brief Constructs a Vec2 from a Vector2 (engine type conversion).
     * @param rhs The Vector2 to convert from.
     */
    Vec2(const Vector2& rhs);

    /**
     * @brief Copy constructor.
     * @param rhs The Vec2 to copy from.
     */
    Vec2(const Vec2& rhs) = default;

    /**
     * @brief Move constructor.
     * @param rhs The Vec2 to move from.
     */
    Vec2(Vec2&& rhs) = default;

    /**
     * @brief The destructor. Only needed for Rule of three-and-five
     */
    ~Vec2() = default;

public:
    /**
     * @brief Computes the dot product of this vector and another.
     * @param rhs The other vector.
     * @return The scalar dot product.
     */
    [[nodiscard]] float Dot(const Vec2& rhs) const;

    /**
     * @brief Computes the magnitude (length) of this vector.
     * @return The magnitude as a float.
     */
    [[nodiscard]] float Magnitude() const;

    /**
     * @brief Normalises this vector in-place.
     * @note If the vector has zero magnitude, behaviour is undefined.
     */
    void Normalise();

    /**
     * @brief Returns a normalised copy of this vector.
     * @return A unit-length Vec2 in the same direction.
     */
    [[nodiscard]] Vec2 Normalised() const;

    /**
     * @brief Checks whether this vector is approximately equal to another.
     * @param rhs The vector to compare against.
     * @param e The epsilon tolerance. Defaults to 1e-4.
     * @return True if both components are within epsilon of each other.
     */
    [[nodiscard]] bool IsApproximatelyEqual(const Vec2& rhs, float e = 1e-4f) const;

    /**
     * @brief Computes the angle between this vector and another.
     * @param rhs The other vector.
     * @return The angle in radians.
     */
    [[nodiscard]] float AngleBetween(const Vec2& rhs) const;

    /**
     * @brief Computes the distance between this vector and another.
     * @param rhs The other vector.
     * @return The distance as a float.
     */
    [[nodiscard]] float Distance(const Vec2& rhs) const;

    /**
     * @brief Returns the angle this vector makes with the positive x-axis.
     * @return The angle in radians.
     */
    [[nodiscard]] float Angle() const;

    /**
     * @brief Rotates this vector in-place by the given angle.
     * @param radians The angle to rotate by, in radians.
     */
    void Rotate(float radians);

    /**
     * @brief Rotates this vector around a pivot point by the given angle.
     * @param pivot The point to rotate around.
     * @param radians The angle to rotate by, in radians.
     */
    void RotateAround(const Vec2& pivot, float radians);

    /**
     * @brief Linearly interpolates between this vector and another.
     * @param b The target vector.
     * @param t The interpolation factor, typically in [0, 1].
     * @return The interpolated Vec2.
     */
    [[nodiscard]] Vec2 Lerp(const Vec2& b, float t) const;

public:

    /**
     * @brief Implicit conversion to the engine's Vector2 type.
     */
    operator Vector2() const;

    /**
     * @brief Copy assignment operator.
     * @param rhs The Vec2 to assign from.
     * @return A reference to this Vec3.
     */
    Vec2& operator=(const Vec2& rhs) = default;

    /**
     * @brief Move assignment operator.
     * @param rhs The Vec3 to move from.
     * @return A reference to this Vec3.
     */
    Vec2& operator=(Vec2&& rhs) noexcept = default;

    /**
     * @brief Unary negation operator.
     * @return A Vec2 with both components negated.
     */
    Vec2 operator-() const;

    /**
     * @brief Equality comparison operator.
     * @param rhs The Vec2 to compare against.
     * @return True if both components are exactly equal.
     */
    bool operator==(const Vec2& rhs) const;

    /**
     * @brief Inequality comparison operator.
     * @param rhs The Vec2 to compare against.
     * @return True if any component differs.
     */
    bool operator!=(const Vec2& rhs) const;

    /**
     * @brief Less-than comparison operator (lexicographic order).
     * @param rhs The Vec2 to compare against.
     * @return True if this vector is less than rhs.
     */
    bool operator<(const Vec2& rhs) const;

    /**
     * @brief Adds two vectors component-wise.
     * @param rhs The vector to add.
     * @return The resulting Vec2.
     */
    Vec2 operator+(const Vec2& rhs) const;

    /**
     * @brief Adds another vector to this one in-place.
     * @param rhs The vector to add.
     * @return A reference to this Vec2.
     */
    Vec2& operator+=(const Vec2& rhs);

    /**
     * @brief Subtracts another vector component-wise.
     * @param rhs The vector to subtract.
     * @return The resulting Vec2.
     */
    Vec2 operator-(const Vec2& rhs) const;

    /**
     * @brief Subtracts another vector from this one in-place.
     * @param rhs The vector to subtract.
     * @return A reference to this Vec2.
     */
    Vec2& operator-=(const Vec2& rhs);

    /**
     * @brief Multiplies two vectors component-wise.
     * @param rhs The vector to multiply by.
     * @return The resulting Vec2.
     */
    Vec2 operator*(const Vec2& rhs) const;

    /**
     * @brief Multiplies this vector by another component-wise in-place.
     * @param rhs The vector to multiply by.
     * @return A reference to this Vec2.
     */
    Vec2& operator*=(const Vec2& rhs);

    /**
     * @brief Multiplies this vector by a scalar.
     * @param rhs The scalar multiplier.
     * @return The resulting Vec2.
     */
    Vec2 operator*(float rhs) const;

    /**
     * @brief Multiplies this vector by a scalar in-place.
     * @param rhs The scalar multiplier.
     * @return A reference to this Vec2.
     */
    Vec2& operator*=(float rhs);

    /**
     * @brief Divides this vector by a scalar.
     * @param rhs The scalar divisor.
     * @return The resulting Vec2.
     */
    Vec2 operator/(float rhs) const;

    /**
     * @brief Divides this vector by a scalar in-place.
     * @param rhs The scalar divisor.
     * @return A reference to this Vec2.
     */
    Vec2& operator/=(float rhs);

    /**
     * @brief Provides indexed access to the vector components.
     * @param index 0 for x, 1 for y.
     * @return A reference to the component at the given index.
     */
    float& operator[](int index);

    /**
     * @brief Provides const indexed access to the vector components.
     * @param index 0 for x, 1 for y.
     * @return A const reference to the component at the given index.
     */
    const float& operator[](int index) const;

    /**
     * @brief Stream insertion operator for printing a Vec2.
     * @param stream The output stream.
     * @param vec The Vec2 to print.
     * @return The output stream after insertion.
     */
    friend ostream& operator<<(ostream& stream, const Vec2& vec);
};