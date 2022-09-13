//
//
//

#ifndef Utils_hpp
#define Utils_hpp

#include <cmath>
#include <iostream>
#include <map>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

float euclidianDistance(sf::Vector3f& vA, sf::Vector3f& vB);
float euclidianDistance(sf::Color& vA, sf::Color& vB);

bool checkFileName(std::string& filename);


// Determine if the size of an image is valid;
bool sizeIsValid(unsigned sizeX, unsigned sizeY, unsigned pixDiv);


// Generic helper
template<typename A, typename B>
inline std::pair<B,A> flip_pair(const std::pair<A,B> &p)
{
    return std::pair<B,A>(p.second, p.first);
}

template<typename A, typename B>
inline std::multimap<B,A> flip_map(const std::map<A,B> &src)
{
    std::multimap<B,A> dst;
    std::transform(src.begin(), src.end(), std::inserter(dst, dst.begin()),
                   flip_pair<A,B>);
    return dst;
}


#endif /* Utils_hpp */
