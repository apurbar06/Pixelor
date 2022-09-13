//
 // Quantization.hpp
 // Methods for changing the number of color in an image
 //

 #ifndef Quantization_hpp
 #define Quantization_hpp

#include <algorithm>
#include <random>

#include <SFML/Graphics.hpp>

#include "Utils.hpp"
#include "KMeans.hpp"



sf::Image quantize_random(sf::Image image, unsigned nColors);
sf::Image quantize_KMeans(sf::Image image, unsigned nColors);
sf::Image quantize_Hist(sf::Image image, unsigned nColors);

#endif /* Quantization_hpp */
