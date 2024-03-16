#include "Gmath.h"

sf::Vector2f Gmath::NormalizeVector2f(const sf::Vector2f& vector)
{
    float module = sqrt((vector.x * vector.x) + (vector.y * vector.y));

    sf::Vector2f normalized;

    normalized.x = vector.x / module;
    normalized.y = vector.y / module;

    return normalized;
}

