#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

#include "MultipleResourceManager.h"

class ResourceHolder
{
public:
	ResourceHolder & get()
	{
		static ResourceHolder holder;
		return holder;
	}

	MultipleResourceManager<sf::Font> fonts;
	MultipleResourceManager<sf::Texture> textures;
	MultipleResourceManager<sf::SoundBuffer> sounds;
private:
	ResourceHolder()
	:	fonts		("Fonts",		"ttf")
	,	textures	("Textures",	"png")
	,	sounds		("Sound",		"ogg")
	{}
};