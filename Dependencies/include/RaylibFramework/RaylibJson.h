#pragma once

#include <nlohmann/json.hpp>
#include <raylib/raylib.h>

using Json = nlohmann::json;

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Color, r, g, b, a)
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Vector2, x, y)
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Rectangle, x, y, width, height)