#pragma once

#include <RaylibFramework/RaylibFramework.h>

/**
 * @brief A collection of general-purpose mathematical utility functions.
 */
class DLL MathFunctions
{
public:
    /**
     * @brief Compares two floats for approximate equality within a given epsilon.
     * @param a The first value.
     * @param b The second value.
     * @param e The epsilon tolerance. Defaults to 1e-4.
     * @return True if the absolute difference between a and b is less than or equal to e.
     */
    static bool Approx(float a, float b, float e = 1e-4f);

    /**
     * @brief Clamps a value to the range [min, max].
     * @param value The value to clamp.
     * @param min The lower bound.
     * @param max The upper bound.
     * @return The clamped value.
     */
    static float Clamp(float value, float min, float max);

    /**
     * @brief Clamps a value to the range [0, 1].
     * @param value The value to clamp.
     * @return The clamped value.
     */
    static float Clamp01(float value);
};