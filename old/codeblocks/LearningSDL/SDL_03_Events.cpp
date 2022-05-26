#include <stdio.h>
#include <SDL.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int init();

int loadMedia();

void close();

SDL_Window* window = NULL;
SDL_Surface* surface = NULL;
SDL_Surface* image = NULL;

int init()
{
    int success = 1;

    if ( SDL_Init(SDL_INIT_VIDEO) < 0 )
    {
        printf( "Could not initialize SDL. ERROR: %s\n", SDL_GetError() );
        success = 0;
    }
    else
    {
        window = SDL_CreateWindow ( "Window Name", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if ( window == NULL )
        {
            printf( "Could not create window. ERROR: %s\n", SDL_GetError() );
            success = 0;
        }
        else
        {
            surface = SDL_GetWindowSurface ( window );
        }
    }

    return success;
}


int loadMedia()
{
    int success = 1;

    image = SDL_LoadBMP ("SDL_Tutorial_Media/image03.bmp");
    if ( image == NULL )
    {
        printf( "Failed to load media. ERROR: %s\n", SDL_GetError() );
        success = 0;
    }

    return success;
}


void close ()
{

    SDL_FreeSurface ( image );
    image = NULL;

    SDL_DestroyWindow ( window );
    window = NULL;

    SDL_Quit();
}

int main( int argc, char* args[] )
{
    if ( !init() )
    {
        printf( "Failed to initialize.\n");
    }
    else
    {
        if ( !loadMedia() )
        {
            printf("Failed to load media.\n");
        }
        else
        {
            int quit = 0;

            SDL_Event event;

            while ( !quit )
            {
                while ( SDL_PollEvent(&event) != 0 )
                {
                    if ( event.type == SDL_QUIT )
                    {
                        quit = 1;
                    }
                }

                SDL_BlitSurface ( image, NULL, surface, NULL );

                SDL_UpdateWindowSurface ( window );
            }
        }
    }
    close();

    return 0;
}






























