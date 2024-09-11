#pragma once
#include "bundler.h"

class Bounds : public sf::RectangleShape
{
public:

    Bounds(const sf::Vector2f& newSize, const sf::Vector2f& newPos,
        const sf::Color& newColor) :
        sf::RectangleShape(newSize)
        {
        this->setFillColor(newColor);
        this->setPosition(newPos);
        }
};
