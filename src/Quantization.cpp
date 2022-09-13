/*
 *
 *
 */
#include "Quantization.hpp"

#include <iostream>

#include "Histogram.hpp"
sf::Image quantize_random(sf::Image image, unsigned nColors)
{
    // Preparing the output image...
    unsigned width  = image.getSize().x;
    unsigned height = image.getSize().y;

    sf::Image result;
    result.create(width, height, sf::Color::White);


    //Transforming the 2D image matrix into a 1D color array
    std::vector<sf::Color> colorArray;
    for(size_t y(0); y < height; y++)
    for(size_t x(0); x < width; x++)
    {
        colorArray.push_back(image.getPixel(x,y));
    }

    // Selecting the palette
    std::random_device seed;
    std::mt19937 rng(seed());

    auto shuffled = colorArray;
    std::shuffle(shuffled.begin(), shuffled.end(), rng);
    std::vector<sf::Color> palette(shuffled.begin(), shuffled.begin() + nColors);

    // For each point in colorArray, computing the closest color in the palette
    // TODO Optimize this part as it is a function in O(N*Z) where Z <= N

    std::vector<sf::Color> colorArray_quantized;
    std::pair<int, float> minimalDistance; // first is the pos, second the distance
    float distance;

    for(auto &c : colorArray)
    {
        minimalDistance.first = -1;
        minimalDistance.second = std::numeric_limits<float>::max();;

        for(unsigned i(0); i < nColors; i++)
        {
            distance = euclidianDistance(c, palette[i]);
            if(minimalDistance.second > distance)
            {
                minimalDistance.first = i;
                minimalDistance.second = distance;
            }
        }

        colorArray_quantized.push_back(palette[minimalDistance.first]);
    }


    // Going back to a 2D Image
    for(size_t x(0); x < width; x++)
    for(size_t y(0); y < height; y++)
    {
        result.setPixel(x,y,colorArray_quantized[(y * width) + x]);
    }


    // return ...

    return result;

}



sf::Image quantize_KMeans(sf::Image image, unsigned nColors)
{
    // Preparing the output image...
    unsigned width  = image.getSize().x;
    unsigned height = image.getSize().y;

    sf::Image result;
    result.create(width, height, sf::Color::White);

    //Transforming the 2D image matrix into a 1D color array
    std::vector<sf::Color> colorArray;
    for(size_t y(0) ; y < height ; y++)
    for(size_t x(0) ; x < width ; x++)
    {
        colorArray.push_back(image.getPixel(x,y));
    }

    // // Selecting the palette
    // std::random_device rd;
    // std::mt19937 rng(rd());
    //
    // auto shuffled = colorArray;
    // std::shuffle(shuffled.begin(), shuffled.end(), rng);
     std::vector<sf::Color> palette = KMeans(colorArray, nColors, 5);

    // For each point in colorArray, computing the closest color in the palette
    // TODO Optimize this part as it is a function in O(N*Z) where Z <= N
    //
    std::vector<sf::Color> colorArray_quantized;
    std::pair<int, float> minimalDistance; // first is the pos, second the distance
    float distance;

    for(auto &c : colorArray)
    {
        minimalDistance.first = -1;
        minimalDistance.second = std::numeric_limits<float>::max();;

        for(unsigned i(0) ; i < nColors ; i++)
        {
            distance = euclidianDistance(c, palette[i]);
            if(minimalDistance.second > distance)
            {
                minimalDistance.first = i;
                minimalDistance.second = distance;
            }
        }

        colorArray_quantized.push_back(palette[minimalDistance.first]);
    }


    // Going back to a 2D Image
    for(size_t x(0); x < width; x++)
    for(size_t y(0); y < height; y++)
    {
        result.setPixel(x,y,colorArray_quantized[(y * width) + x]);
    }


    // return ...

    return result;

}


sf::Image quantize_Hist(sf::Image image, unsigned nColors)
{
    // Preparing the output image...
    unsigned width  = image.getSize().x;
    unsigned height = image.getSize().y;

    sf::Image result;
    result.create(width, height, sf::Color::White);

    //Transforming the 2D image matrix into a 1D color array
    std::vector<sf::Color> colorArray;
    for(size_t y(0) ; y < height ; y++)
    for(size_t x(0) ; x < width ; x++)
    {
        colorArray.push_back(image.getPixel(x,y));
    }

    Histogram hist(colorArray, 10);
    auto palette = hist.getPalette(nColors);



    // For each point in colorArray, computing the closest color in the palette
    // TODO Optimize this part as it is a function in O(N*Z) where Z <= N
    //
    std::vector<sf::Color> colorArray_quantized;
    std::pair<int, float> minimalDistance; // first is the pos, second the distance
    float distance;

    for(auto &c : colorArray)
    {
        minimalDistance.first = -1;
        minimalDistance.second = std::numeric_limits<float>::max();;

        for(unsigned i(0) ; i < nColors ; i++)
        {
            distance = euclidianDistance(c, palette[i]);
            if(minimalDistance.second > distance)
            {
                minimalDistance.first = i;
                minimalDistance.second = distance;
            }
        }

        colorArray_quantized.push_back(palette[minimalDistance.first]);
    }


    // Going back to a 2D Image
    for(size_t x(0); x < width; x++)
    for(size_t y(0); y < height; y++)
    {
        result.setPixel(x,y,colorArray_quantized[(y * width) + x]);
    }


    // return ...

    return result;

}
