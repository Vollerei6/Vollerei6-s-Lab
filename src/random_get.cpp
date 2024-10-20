#include "random_get.hpp"

double getDis()
{
	return RandomGenerator::getNormalDistribution()(RandomGenerator::getGenerator());
}