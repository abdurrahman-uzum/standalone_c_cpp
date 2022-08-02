#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <stdio.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>

extern SDL_Window* gWindow;
extern SDL_Renderer* gRenderer;
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;


class Texture
{
	public:
		Texture();
		~Texture();

		bool load( std::string path );

		void free();

		void render( int x, int y, SDL_Rect* clip = NULL );

		int getWidth();
		int getHeight();

	private:
		int mWidth;
		int mHeight;

		SDL_Texture* mTexture;
};



























#endif /* TEXTURE_H_ */
