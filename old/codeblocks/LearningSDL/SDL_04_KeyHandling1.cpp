#include <stdio.h>
#include <SDL.h>
#include <string>


const int WIDTH = 640;
const int HEIGHT = 480;


enum Keys
{
    DEFAULT,
    UP,
    DOWN,
    RIGHT,
    LEFT,
    TOTAL
};

bool init();

bool loadMedia();

void close();

SDL_Window* window = NULL;

SDL_Surface* loadSurface( std::string path );

SDL_Surface* surface = NULL;

SDL_Surface* keySurfaces [ TOTAL ];

SDL_Surface* currentSurface = NULL;


bool init()
{
    bool success = true;

    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "In SDL_Init ERROR: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        window = SDL_CreateWindow ( "Window Name", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN );
        if ( window == NULL )
        {
            printf( "In window creation, ERROR: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            surface = SDL_GetWindowSurface ( window );
        }
    }

    return success;
}



bool loadMedia()
{
    bool success = true;

    keySurfaces[DEFAULT] = loadSurface("SDL_Tutorial_Media/keyPressesMedia/press.bmp");
    if ( keySurfaces[DEFAULT] == NULL )
    {
        printf("ERROR: %s\n", SDL_GetError());
    }

    keySurfaces[UP] = loadSurface("SDL_Tutorial_Media/keyPressesMedia/up.bmp");
    if ( keySurfaces[UP] == NULL )
    {
        printf("ERROR: %s\n", SDL_GetError());
    }

    keySurfaces[DOWN] = loadSurface("SDL_Tutorial_Media/keyPressesMedia/down.bmp");
    if ( keySurfaces[DOWN] == NULL )
    {
        printf("ERROR: %s\n", SDL_GetError());
    }

    keySurfaces[LEFT] = loadSurface("SDL_Tutorial_Media/keyPressesMedia/left.bmp");
    if ( keySurfaces[LEFT] == NULL )
    {
        printf("ERROR: %s\n", SDL_GetError());
    }

    keySurfaces [RIGHT] = loadSurface("SDL_Tutorial_Media/keyPressesMedia/right.bmp");
    if ( keySurfaces[RIGHT] == NULL )
    {
        printf("ERROR: %s\n", SDL_GetError());
    }

    return success;
}

void close()
{
    for ( int i=0; i < TOTAL; ++i )
    {
        SDL_FreeSurface ( keySurfaces[i] );
        keySurfaces[i] = NULL;
    }

    SDL_DestroyWindow ( window );

    SDL_Quit();
}


SDL_Surface* loadSurface( std::string path )
{
    SDL_Surface* loadedSurface = SDL_LoadBMP ( path.c_str() );
    if ( loadedSurface == NULL )
    {
        printf("ERROR: %s\n", SDL_GetError());
    }

    return loadedSurface;
}


int main ( int argc, char* args[] )
{
    if ( !init() )
    {
        printf("Coult not initialize, ERROR: %s\n", SDL_GetError());
    }
    else
    {
        if ( !loadMedia() )
        {
            printf("Failed to load media, ERROR: %s\n", SDL_GetError());
        }
        else
        {
            bool quit = false;

            SDL_Event event;

            currentSurface = keySurfaces[DEFAULT];

            while ( !quit )
            {
                while ( SDL_PollEvent(&event) != 0 )
                {
                    if ( event.type == SDL_QUIT )
                    {
                        quit = true;
                    }
                    else if ( event.type == SDL_KEYDOWN )
                    {
                        switch( event.key.keysym.sym )
                        {
                        case SDLK_w:
                            currentSurface = keySurfaces[UP];
                            printf("Pressed %c\n", event.key.keysym.sym);
                            break;
                        case SDLK_s:
                            currentSurface = keySurfaces[DOWN];
                            printf("Pressed S\n");
                            break;
                        case SDLK_a:
                            currentSurface = keySurfaces[LEFT];
                            printf("Pressed A\n");
                            break;
                        case SDLK_d:
                            currentSurface = keySurfaces[RIGHT];
                            printf("Pressed D\n");
                            break;
                        default:
                            currentSurface = keySurfaces[DEFAULT];
                            printf("WTF are you doing!?\n");
                            break;
                        }
                    }
                }
                SDL_BlitSurface ( currentSurface, NULL, surface, NULL );

                SDL_UpdateWindowSurface ( window );
            }
        }
    }

    close();

    return 0;
}































