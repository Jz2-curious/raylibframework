#pragma once

#include <ostream>
#include <raylib/raylib.h>
#include <RaylibFramework/RaylibFramework.h>

using std::ostream;

/**
 * @brief A 3D vector with x, y, and z components.
 */
struct DLL Vec3
{
public:
    /** @brief The x component. */
    float x;
    /** @brief The y component. */
    float y;
    /** @brief The z component. */
    float z;

public:
    /**
     * @brief Default constructor. Initialises x, y, and z to zero.
     */
    Vec3();

    /**
     * @brief Constructs a Vec3 with given x, y, and z values.
     * @param x The x component.
     * @param y The y component.
     * @param z The z component.
     */
    Vec3(float x, float y, float z);

    /**
     * @brief Constructs a Vec3 from a Vector3 (engine type conversion).
     * @param rhs The Vector3 to convert from.
     */
    Vec3(const Vector3& rhs);

    /**
     * @brief Copy constructor.
     * @param rhs The Vec3 to copy from.
     */
    Vec3(const Vec3& rhs) = default;

    /**
     * @brief Move constructor
     * @param rhs The Vec3 to move from
     */
    Vec3(Vec3&& rhs) noexcept = default;

    /**
     * @brief The destructor. Only needed for Rule of three-and-five
     */
    ~Vec3() = default;

public:
    /**
     * @brief Computes the dot product of this vector and another.
     * @param rhs The other vector.
     * @return The scalar dot product.
     */
    [[nodiscard]] float Dot(const Vec3& rhs) const;

    /**
     * @brief Computes the cross product of this vector and another.
     * @param rhs The other vector.
     * @return A Vec3 perpendicular to both input vectors.
     */
    [[nodiscard]] Vec3 Cross(const Vec3& rhs) const;

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
     * @return A unit-length Vec3 in the same direction.
     */
    [[nodiscard]] Vec3 Normalised() const;

    /**
     * @brief Checks whether this vector is approximately equal to another.
     * @param rhs The vector to compare against.
     * @param e The epsilon tolerance. Defaults to 1e-4.
     * @return True if all components are within epsilon of each other.
     */
    [[nodiscard]] bool IsApproximatelyEqual(const Vec3& rhs, float e = 1e-4f) const;

    /**
     * @brief Computes the angle between this vector and another.
     * @param rhs The other vector.
     * @return The angle in radians.
     */
    [[nodiscard]] float AngleBetween(const Vec3& rhs) const;

    /**
     * @brief Computes the distance between this vector and another.
     * @param rhs The other vector.
     * @return The distance as a float.
     */
    [[nodiscard]] float Distance(const Vec3& rhs) const;

    /**
     * @brief Returns the 2D angle of this vector using only the x and y components.
     * @return The angle in radians relative to the positive x-axis.
     */
    [[nodiscard]] float Angle2D() const;

public:

    /**
     * @brief Implicit conversion to the engine's Vector3 type.
     */
    operator Vector3() const;

    /**
     * @brief Copy assignment operator.
     * @param rhs The Vec3 to assign from.
     * @return A reference to this Vec3.
     */
    Vec3& operator=(const Vec3& rhs) = default;

    /**
     * @brief Move assignment operator.
     * @param rhs The Vec3 to move from.
     * @return A reference to this Vec3.
     */
    Vec3& operator=(Vec3&& rhs) noexcept = default;

    /**
     * @brief Unary negation operator.
     * @return A Vec3 with all components negated.
     */
    Vec3 operator-() const;

    /**
     * @brief Equality comparison operator.
     * @param rhs The Vec3 to compare against.
     * @return True if all components are exactly equal.
     */
    bool operator==(const Vec3& rhs) const;

    /**
     * @brief Inequality comparison operator.
     * @param rhs The Vec3 to compare against.
     * @return True if any component differs.
     */
    bool operator!=(const Vec3& rhs) const;

    /**
     * @brief Less-than comparison operator (lexicographic order).
     * @param rhs The Vec3 to compare against.
     * @return True if this vector is less than rhs.
     */
    bool operator<(const Vec3& rhs) const;

    /**
     * @brief Adds two vectors component-wise.
     * @param rhs The vector to add.
     * @return The resulting Vec3.
     */
    Vec3 operator+(const Vec3& rhs) const;

    /**
     * @brief Adds another vector to this one in-place.
     * @param rhs The vector to add.
     * @return A reference to this Vec3.
     */
    Vec3& operator+=(const Vec3& rhs);

    /**
     * @brief Subtracts another vector component-wise.
     * @param rhs The vector to subtract.
     * @return The resulting Vec3.
     */
    Vec3 operator-(const Vec3& rhs) const;

    /**
     * @brief Subtracts another vector from this one in-place.
     * @param rhs The vector to subtract.
     * @return A reference to this Vec3.
     */
    Vec3& operator-=(const Vec3& rhs);

    /**
     * @brief Multiplies two vectors component-wise.
     * @param rhs The vector to multiply by.
     * @return The resulting Vec3.
     */
    Vec3 operator*(const Vec3& rhs) const;

    /**
     * @brief Multiplies this vector by another component-wise in-place.
     * @param rhs The vector to multiply by.
     * @return A reference to this Vec3.
     */
    Vec3& operator*=(const Vec3& rhs);

    /**
     * @brief Multiplies this vector by a scalar.
     * @param rhs The scalar multiplier.
     * @return The resulting Vec3.
     */
    Vec3 operator*(float rhs) const;

    /**
     * @brief Multiplies this vector by a scalar in-place.
     * @param rhs The scalar multiplier.
     * @return A reference to this Vec3.
     */
    Vec3& operator*=(float rhs);

    /**
     * @brief Divides this vector by a scalar.
     * @param rhs The scalar divisor.
     * @return The resulting Vec3.
     */
    Vec3 operator/(float rhs) const;

    /**
     * @brief Divides this vector by a scalar in-place.
     * @param rhs The scalar divisor.
     * @return A reference to this Vec3.
     */
    Vec3& operator/=(float rhs);

    /**
     * @brief Provides indexed access to the vector components.
     * @param index 0 for x, 1 for y, 2 for z.
     * @return A reference to the component at the given index.
     */
    float& operator[](int index);

    /**
     * @brief Provides const indexed access to the vector components.
     * @param index 0 for x, 1 for y, 2 for z.
     * @return A const reference to the component at the given index.
     */
    const float& operator[](int index) const;

    /**
     * @brief Stream insertion operator for printing a Vec3.
     * @param stream The output stream.
     * @param vec The Vec3 to print.
     * @return The output stream after insertion.
     */
    friend ostream& operator<<(ostream& stream, const Vec3& vec);

};