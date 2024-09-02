#include <iostream>
#include <random>
#include <limits>

int main()
{
    std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<int> distributionCount(1, 1000);
    int count = distributionCount(generator);

    std::uniform_int_distribution<int32_t> distributionA(std::numeric_limits<int32_t>::min(), std::numeric_limits<int32_t>::max());
    std::uniform_int_distribution<int64_t> distributionP(std::numeric_limits<int64_t>::min(), std::numeric_limits<int64_t>::max());
    std::cout << count << std::endl;
    for (int i = 0; i < count; i++)
    {
        std::cout << distributionA(generator) << " " << distributionA(generator) << " " << distributionP(generator) << std::endl;
    }
    return 0;
}