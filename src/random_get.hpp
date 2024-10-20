#pragma once

#include <random>

class RandomGenerator {
public:
    static std::mt19937& getGenerator() {
        static std::mt19937 generator(std::random_device{}()); // 静态局部变量，只初始化一次  
        return generator;
    }

    static std::normal_distribution<>& getNormalDistribution() {
        static std::normal_distribution<> distribution(1.0, 0.1); // 静态局部变量，只初始化一次  
        return distribution;
    }

    // 其他成员函数...  
};

inline double getDis() 
{
    return RandomGenerator::getNormalDistribution()(RandomGenerator::getGenerator());
}
