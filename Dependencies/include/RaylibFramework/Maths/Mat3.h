#pragma once

#include <RaylibFramework/RaylibFramework.h>
#include <RaylibFramework/Maths/Vec2.h>

/**
 * @brief A 3x3 matrix used for 2D transformations (translation, rotation, scale).
 *
 * Elements are stored in column-major order as m1 through m9.
 */
struct DLL Mat3
{
public:
    /**
     * @brief Creates a translation matrix from a Vec2.
     * @param trans The translation vector (x and y components are used).
     * @return A Mat3 representing the translation.
     */
    static Mat3 MakeTranslate(const Vec2& trans);

    /**
     * @brief Creates a translation matrix from x and y values.
     * @param x Translation along the x-axis.
     * @param y Translation along the y-axis.
     * @return A Mat3 representing the translation.
     */
    static Mat3 MakeTranslate(float x, float y);

    /**
     * @brief Creates a rotation matrix.
     * @param rad The angle of rotation in radians.
     * @return A Mat3 representing the rotation.
     */
    static Mat3 MakeRotate(float rad);

    /**
     * @brief Creates a scale matrix from a Vec2.
     * @param scale The scale vector (x and y components are used).
     * @return A Mat3 representing the scale.
     */
    static Mat3 MakeScale(const Vec2& scale);

    /**
     * @brief Creates a scale matrix from x and y values.
     * @param x Scale factor along the x-axis.
     * @param y Scale factor along the y-axis.
     * @return A Mat3 representing the scale.
     */
    static Mat3 MakeScale(float x, float y);

public:
    /** @brief Row 1, Column 1 */
    float m1;
    /** @brief Row 2, Column 1 */
    float m2;
    /** @brief Row 3, Column 1 */
    float m3;
    /** @brief Row 1, Column 2 */
    float m4;
    /** @brief Row 2, Column 2 */
    float m5;
    /** @brief Row 3, Column 2 */
    float m6;
    /** @brief Row 1, Column 3 */
    float m7;
    /** @brief Row 2, Column 3 */
    float m8;
    /** @brief Row 3, Column 3 */
    float m9;

public:
    /**
     * @brief Default constructor. Initialises the matrix to the identity matrix.
     */
    Mat3();

    /**
     * @brief Constructs a matrix with explicit element values.
     * @param m1 Element at row 1, column 1.
     * @param m2 Element at row 2, column 1.
     * @param m3 Element at row 3, column 1.
     * @param m4 Element at row 1, column 2.
     * @param m5 Element at row 2, column 2.
     * @param m6 Element at row 3, column 2.
     * @param m7 Element at row 1, column 3.
     * @param m8 Element at row 2, column 3.
     * @param m9 Element at row 3, column 3.
     */
    Mat3(float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9);

    /**
     * @brief Copy constructor.
     * @param rhs The matrix to copy from.
     */
    Mat3(const Mat3& rhs) = default;

    /**
     * @brief Move constructor
     * @param rhs The Mat3 to move from
     */
    Mat3(Mat3&& rhs) noexcept = default;

    /**
     * @brief The destructor. Only needed for Rule of three-and-five
     */
    ~Mat3() = default;

public:
    /**
     * @brief Returns the right vector (first column) of the matrix.
     * @return A Vec2 representing the right direction.
     */
    [[nodiscard]] Vec2 GetRight() const;

    /**
     * @brief Returns the forward vector (second column) of the matrix.
     * @return A Vec2 representing the forward direction.
     */
    [[nodiscard]] Vec2 GetForward() const;

    /**
     * @brief Returns the translation component (third column) of the matrix.
     * @return A Vec3 representing the translation.
     */
    [[nodiscard]] Vec2 GetTranslate() const;

    /**
     * @brief Returns the scale encoded in the matrix.
     * @return A Vec2 whose x and y components hold the x and y scale factors.
     */
    [[nodiscard]] Vec2 GetScale() const;

    /**
     * @brief Extracts the rotation angle encoded in the matrix.
     * @return The rotation angle in radians.
     */
    [[nodiscard]] float GetRotation() const;

    /**
     * @brief Checks whether this matrix is approximately equal to another.
     * @param matrix The matrix to compare against.
     * @param e The epsilon tolerance for floating-point comparison. Defaults to 1e-4.
     * @return True if all corresponding elements are within epsilon of each other.
     */
    [[nodiscard]] bool IsApproximatelyEqual(const Mat3& matrix, float e = 1e-4f) const;

public:

    /**
     * @brief Copy assignment operator.
     * @param rhs The Mat3 to assign from.
     * @return A reference to this Mat3.
     */
    Mat3& operator=(const Mat3& rhs) = default;

    /**
     * @brief Move assignment operator.
     * @param rhs The Mat3 to move from.
     * @return A reference to this Mat3.
     */
    Mat3& operator=(Mat3&& rhs) noexcept = default;

    /**
     * @brief Transforms a Vec3 by this matrix.
     * @param rhs The vector to transform.
     * @return The resulting transformed Vec3.
     */
    Vec2 operator*(const Vec2& rhs) const;

    /**
     * @brief Multiplies two matrices together.
     * @param rhs The right-hand side matrix.
     * @return The resulting Mat3 product.
     */
    Mat3 operator*(const Mat3& rhs) const;

    /**
     * @brief Multiplies this matrix by another in-place.
     * @param rhs The right-hand side matrix.
     * @return A reference to this matrix after multiplication.
     */
    Mat3& operator*=(const Mat3& rhs);

    /**
     * @brief Equality comparison operator.
     * @param rhs The matrix to compare against.
     * @return True if all elements are exactly equal.
     */
    bool operator==(const Mat3& rhs) const;

    /**
     * @brief Inequality comparison operator.
     * @param rhs The matrix to compare against.
     * @return True if any element differs.
     */
    bool operator!=(const Mat3& rhs) const;

    /**
     * @brief Provides indexed access to matrix elements (column-major).
     * @param index The index of the element (0 - 8).
     * @return A reference to the element at the given index.
     */
    float& operator[](int index);

    /**
     * @brief Provides const indexed access to matrix elements (column-major).
     * @param index The index of the element (0 - 8).
     * @return A const reference to the element at the given index.
     */
    const float& operator[](int index) const;
};