#include "Random.h"

//seed
SeedSequence::SeedSequence(int seed = 0)
	:
	m_seed(seed)
{
}

SeedSequence::SeedSequence(std::random_device& rand_device)
	:
	m_randomize(rand_device())
{
}

SeedSequence::~SeedSequence()
{
}

int SeedSequence::getNext(int min = -1, int max = 1)
{
	std::uniform_int_distribution<int> dist(min, max);
	return dist(m_randomize);
}

//random
Random::Random()
{
}

Random::~Random()
{
}

int Random::getNew(int min = -1, int max = 1)
{
	seed = SeedSequence(rand);
	return seed.getNext(min, max);
}
