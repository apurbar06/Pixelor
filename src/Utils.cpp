/*
 *
 *
 */
#include "Utils.hpp"




float euclidianDistance(sf::Vector3f& vA, sf::Vector3f& vB)
{
    return(sqrt(pow(vA.x - vB.x, 2) + pow(vA.y - vB.y, 2) + pow(vA.z - vB.z, 2)));
}

float euclidianDistance(sf::Color& cA, sf::Color& cB)
{
    auto a = sf::Vector3f(cA.r, cA.g, cA.b);
    auto b = sf::Vector3f(cB.r, cB.g, cB.b);

    return(euclidianDistance(a,b));
}






bool checkFileName(std::string& filename)
{
    //TODO Make this function validate if the name is valid
    return true;
}



bool sizeIsValid(unsigned sizeX, unsigned sizeY, unsigned pixDiv)
{
    bool isValid = true;

    if (sizeX % pixDiv != 0)
    {
        std::cout << "ERROR: Image width is not divisible by pixel size (" << pixDiv << ").\n";
        std::cout << "Width is size " << sizeX <<'\n';
        std::cout << "Modulo: " << sizeX % pixDiv << "\n";

        isValid = false;
    }

    if (sizeY % pixDiv != 0)
    {
        std::cout << "ERROR: Image height is not divisible by pixel size (" << pixDiv << ").\n";
        std::cout << "Height is size " << sizeY <<'\n';
        std::cout << "Modulo: " << sizeY % pixDiv << "\n";

        isValid = false;
    }

    return isValid;
}
