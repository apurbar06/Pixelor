#include "Histogram.hpp"



using Frame = std::vector<sf::Color>;


Histogram::Histogram(Frame& data, unsigned nBuckets)
: bucketsPerDimension((nBuckets <= DIMENSION_MAX)? nBuckets : DIMENSION_MAX )
, bucketSize(DIMENSION_MAX / nBuckets)
{
    this->build(data);
}

Histogram::Histogram(Frame& data)
: Histogram(data,10)
{}


void Histogram::build(Frame& data)
{
    bins.clear();

    std::string key;
    for(auto& color : data)
    {
        key = getPixelKey(color);
        if (bins.find(key) == bins.end())
        {
            bins.insert(std::make_pair(key,size_t(1)));
        }
        else
        {
            bins[key] += 1;
        }

    }
}

void Histogram::display() const
{
    for(auto& c : bins)
    {
        std::cout << "key: " << c.first << " q: " << c.second << std::endl;
    }
}

// this function return the n most populated bins
Frame Histogram::getPalette(unsigned nColors)
{
    // First we sort the histogram
    std::multimap<size_t, std::string> sortedHist = flip_map(bins);

    // then we make a palette with the first n color
    Frame palette;

    auto it = sortedHist.rbegin();
    for(unsigned i(0) ; i < nColors ; i++)
    {
        std::cout << it->second << std::endl;
        palette.push_back(keyToColor(it->second));
        it++;
    }

    return palette;

}

std::string Histogram::getPixelKey(sf::Color& pixel) const
{

    // A key is computed depending on the bin size of the graph

    unsigned redBucket      = std::floor(pixel.r / bucketSize);
    unsigned greenBucket    = std::floor(pixel.g / bucketSize);
    unsigned blueBucket     = std::floor(pixel.b / bucketSize);

    return  std::to_string(redBucket)   + ":" + std::to_string(greenBucket) + ":" + std::to_string(blueBucket);

}


size_t Histogram::getBinWeight(std::string key) const
{
    size_t weight(0);

    auto bin = bins.find(key);
    if (bin != bins.end())
        weight = bin->second;

    return weight;
}


size_t Histogram::getBinWeight(sf::Color& color) const
{
    return this->getBinWeight(this->getPixelKey(color));
}


// void Histogram::setBucketsPerDimension(unsigned nBuckets)
// {
//     this->bucketsPerDimension = (nBuckets <= DIMENSION_MAX)? nBuckets : DIMENSION_MAX;;
//     this->bucketSize = DIMENSION_MAX / nBuckets;
//
//     build();
// }



sf::Color Histogram::keyToColor(const std::string& color)
{
    std::vector<unsigned> cmp;
    std::stringstream ss(color);
    std::string item;
    while (std::getline(ss, item, ':'))
    {
        cmp.push_back(std::stoi(item));
    }

    return sf::Color(cmp[0]*bucketSize,cmp[1]*bucketSize,cmp[2]*bucketSize);
}
