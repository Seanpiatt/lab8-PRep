// maybe something here...
#include "vector_util.h"
#include <SFML/System/Vector2.hpp>

struct BasicTransform {
    // methods...
    BasicTransform(sf::Vector2f t = {0,0}, sf::Vector2f s = {1,1}): scale(s),translation(t)
    {}

    sf::Vector2f applyPoint(const sf::Vector2f& p){
        sf::Vector2f newPoint;
        newPoint= (p * scale) + translation;
        return newPoint;
    }

    sf::Vector2f applyVector(const sf::Vector2f& p){
        sf::Vector2f newVector; 
        newVector= (p * scale);
        return newVector;
    }

    bool operator==(const BasicTransform& other){
        if(translation.x == translation.y){
            if(scale.x == scale.y){
                return true;
            }
        }
        return false;
    }
    
    sf::Vector2f scale;
    sf::Vector2f translation;
};
