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
float SeedSequence::getNextFloat(float min = -1, float max = 1)
{
		using dist = std::conditional_t<
			std::is_integral<float>::value,
			std::uniform_int_distribution<float>,
			std::uniform_real_distribution<float>
		>;
	return dist{ min, max }(m_randomize);
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
	m_seed = SeedSequence(m_rand);
	return m_seed.getNext(min, max);
}

float Random::getNewFloat(float min = -1, float max = 1)
{
	m_seed = SeedSequence(m_rand);
	return m_seed.getNextFloat(min, max);
}
