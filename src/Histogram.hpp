//
//
//

#ifndef Histogram_hpp
#define Histogram_hpp

#include <cmath>
#include <map>
#include <string>
#include <sstream>
#include <utility>
#include <vector>

#include <iostream>

#include <SFML/Graphics.hpp>

#include "Utils.hpp"

const unsigned DIMENSION_MAX = 256;

using Frame = std::vector<sf::Color>;

class Histogram
{
public:

    // Constructors
    Histogram(Frame& data, unsigned nBuckets);
    Histogram(Frame& data);

    //
    void build(Frame& data);
    void display() const;

    sf::Color keyToColor(const std::string& color);

    // this function return the n most populated bins
    Frame       getPalette(unsigned nColors);
    // getters
    std::string getPixelKey(sf::Color& pixel) const;
    size_t      getBinWeight(std::string key) const;
    size_t      getBinWeight(sf::Color& color) const;



private:

    std::map<std::string, size_t> bins;

    unsigned bucketsPerDimension;
    unsigned bucketSize;

};


#endif /* Histogram_hpp */
