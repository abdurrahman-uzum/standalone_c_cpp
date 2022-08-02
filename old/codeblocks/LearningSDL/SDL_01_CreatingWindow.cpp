#include <stdio.h>
#include <SDL.h>

const int WIDTH = 640;
const int HEIGTH = 480;

bool init();
bool loadMedia();
void close();

SDL_Window* window;
SDL_Surface* surface;
SDL_Surface* image;


bool init()
{
    bool success = true;

    if ( SDL_Init ( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "Could not initialized SDL. ERROR: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        window = SDL_CreateWindow ( "Window Name", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGTH, SDL_WINDOW_SHOWN );
        if ( window == NULL )
        {
            printf( "Could not create window. ERROR: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            surface = SDL_GetWindowSurface ( window );

            SDL_FillRect ( surface, NULL, SDL_MapRGB( surface->format, 255,255,255 ) );

            SDL_UpdateWindowSurface ( window );
        }
    }
    return success;
}



bool loadMedia()
{
    bool success;

    image = SDL_LoadBMP ( "SDL_Tutorial_Media/hello_world.bmp");
    if ( image == NULL )
    {
        printf( "Failed to load image. ERROR: %s\n", SDL_GetError() );
        success = false;
    }

    return success;
}



void close()
{
    SDL_FreeSurface ( surface );

    SDL_DestroyWindow ( window );

    SDL_Quit();
}



int main ( int argc, char* args[] )
{
    if ( !init() )
    {
        printf("ERROR\n");
    }
    else
    {
        if ( !loadMedia() )
        {
            printf("ERROR\n");
        }
        SDL_Event event;
        bool quit = false;

        while ( !quit )
        {
            while ( SDL_PollEvent ( & event ) != 0 )
            {
                if ( event.type == SDL_QUIT )
                {
                    quit = true;
                }
            }

            SDL_BlitSurface ( image, NULL, surface, NULL );
            SDL_UpdateWindowSurface ( window );
        }


    }


    close();


    return 0;
}



















