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

private:
	std::random_device rand;
	SeedSequence seed;
};
