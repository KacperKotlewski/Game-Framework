#pragma once

//#include <SFML\Graphics.hpp>
#include <random>

class SeedSequence
{
public:
	SeedSequence(int);
	SeedSequence(std::random_device&);
	~SeedSequence();

	int getNext(int, int);
	float getNextFloat(float, float);

private:
	std::mt19937 m_randomize;
	int m_seed;
};

class Random
{
public:
	Random();
	~Random();

	int getNew(int, int);
	float getNewFloat(float, float);

private:
	std::random_device m_rand;
	SeedSequence m_seed;
};
