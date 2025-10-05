#include <iostream>
#include <string>
#include <random>
#include <iomanip>

// https://cplusplus.com/reference/random/normal_distribution/
constexpr int N = 100;
constexpr int nrolls = 100000;  // number of experiments
constexpr int nstars = 2500;    // maximum number of stars to show

constexpr double mean = 40.0;
constexpr double stddev = 15.0;

int main()
{
    unsigned int arr[N] = {}; // array with counters
    unsigned int dataCount = 0;

    auto feed = [&](int lat) {
        // if latency is within 0..N then increase counter
        if ((lat >= 0) && (lat < N)) {
            ++arr[lat];
            ++dataCount;
        }
    };

    auto quantile = [&](double q) -> int {
        unsigned int targetValue = dataCount * q;

        unsigned int curCount = 0;
        for (int i = 0; i < N; ++i) {
            curCount += arr[i];

            if (curCount >= targetValue)
                return i;
        }

        return 0;
    };

    // generate data
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(mean, stddev);
    for (int i = 0; i < nrolls; ++i) {
        feed(static_cast<int> (distribution(generator)));
    }

    // draw histogram
    for (int i = 0; i < N; ++i) {
        std::cout << std::setw(2) << i << ' ' << std::string(arr[i] * nstars / nrolls, '*') << std::endl;
    }

    // numbers
    for (int i = 0; i < N; ++i) {
        std::cout << std::setw(2) << i << ' ' << arr[i] << std::endl;
    }

    std::cout << "mediana: " << quantile(0.5) << std::endl;

    // Cut off the top 5% and take the median of the remaining
    // 0.5 * (1 - 0.05) = 0.475
    std::cout << "0.475 quantile: " << quantile(0.475) << std::endl;

    return 0;
}