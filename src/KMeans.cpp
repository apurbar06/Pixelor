// Code adapted from Peter Goldsborough's code
// http://www.goldsborough.me/c++/python/cuda/2017/09/10/20-32-46-exploring_k-means_in_python,_c++_and_cuda/

#include "KMeans.hpp"


using Frame = std::vector<sf::Color>;


Frame KMeans(Frame& data, size_t K, size_t numberOfIterations)
{



    std::random_device seed;
    std::mt19937 rng(seed());
    std::uniform_int_distribution<size_t> indices(0, data.size() - 1);

    // Pick centroids as random points from the dataset.
    Frame means(K, sf::Color::Black);
    for (auto& cluster : means)
        cluster = data[indices(rng)];

    std::vector<size_t> assignments(data.size());
    for (size_t iteration(0); iteration < numberOfIterations; ++iteration)
    {
        // Find assignments.
        for (size_t point(0); point < data.size(); ++point)
        {

          double bestDistance = std::numeric_limits<double>::max();
          size_t bestCluster = 0;

          for (size_t cluster(0); cluster < K; ++cluster)
          {

            const double distance = euclidianDistance(data[point], means[cluster]);

            if (distance < bestDistance)
            {
              bestDistance = distance;
              bestCluster = cluster;
            }
          }
          //std::cout << "clust  " << bestCluster << std::endl;
          assignments[point] = bestCluster;
        }

        // Sum up and count points for each cluster.
        std::vector<sf::Vector3f> newMeans(K); // Needed as sf::Color r,g,b are uint8 variables
        std::vector<size_t> counts(K, 0);
        for (size_t point = 0; point < data.size(); ++point)
        {
            const auto cluster = assignments[point];
            newMeans[cluster].x += data[point].r;
            newMeans[cluster].y += data[point].g;
            newMeans[cluster].z += data[point].b;
            counts[cluster] += 1;
        }

        // Divide sums by counts to get new centroids.
        for (size_t cluster = 0; cluster < K; ++cluster)
        {
            // Turn 0/0 into 0/1 to avoid zero division.
            const auto count = std::max<size_t>(1, counts[cluster]);
            means[cluster].r = newMeans[cluster].x / count;
            means[cluster].g = newMeans[cluster].y / count;
            means[cluster].b = newMeans[cluster].z / count;
        }
    }

    return means;

}
