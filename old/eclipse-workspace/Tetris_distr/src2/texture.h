#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <stdio.h>
#include <string>
#include <SDL.h>


class Texture
{
	public:

		Texture();
		~Texture();

		bool load( std::string path );

		void free();

		void render( int x, int y );

	private:
		int textureWidth;
		int textureHeight;

		SDL_Texture* texture;
};



#endif /* TEXTURE_H_ */
