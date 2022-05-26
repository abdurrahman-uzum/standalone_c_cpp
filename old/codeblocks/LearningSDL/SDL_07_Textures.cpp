#include <stdio.h>
#include <SDL.h>
#include <SDL_Image.h>
#include <string>


const int WIDTH = 640;
const int HEIGTH = 480;

bool init();
bool loadMedia();
void close();
SDL_Texture* loadTexture ( std::string path );

SDL_Window* window = NULL;

SDL_Renderer* renderer = NULL;

SDL_Texture* texture = NULL;


bool init()
{
    bool success = true;

    if ( SDL_Init ( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize. ERROR: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        if ( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
        {
            printf( "Something that i don't understand. ERROR: %s\n", SDL_GetError() );
        }


        window = SDL_CreateWindow ( "Window Name", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGTH, SDL_WINDOW_SHOWN );
        if ( window == NULL )
        {
            printf( "Failed to create window. ERROR: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            renderer = SDL_CreateRenderer ( window, -1, SDL_RENDERER_ACCELERATED );
            if ( renderer == NULL )
            {
                printf( "Failed to create renderer. ERROR: %s\n", SDL_GetError() );
                success = false;
            }
            else
            {
                SDL_SetRenderDrawColor ( renderer, 255,255,255,255 );

                int imgFlags = IMG_INIT_PNG;
                if ( !(IMG_Init ( imgFlags) & imgFlags ) )
                {
                    printf( "Failed to initialize SDL_Image. ERROR: %s\n", IMG_GetError() );
                    success = false;
                }
            }
        }
    }

    return success;
}

bool loadMedia()
{
    bool success = true;

    texture = loadTexture ( "SDL_Tutorial_Media/texture.png" );
    if ( texture == NULL )
    {
        printf( "Failed to load texture. ERROR: %s\n", IMG_GetError() );
        success = false;
    }

    return success;
}



void close()
{
    SDL_DestroyTexture ( texture );
    texture = NULL;

    SDL_DestroyRenderer ( renderer );
    renderer = NULL;

    SDL_DestroyWindow ( window );
    window = NULL;

    IMG_Quit();
    SDL_Quit();

}




SDL_Texture* loadTexture ( std::string path )
{
    SDL_Texture* newTexture = NULL;

    SDL_Surface* loadedSurface = IMG_Load ( path.c_str() );
    if ( loadedSurface == NULL )
    {
        printf( "Failed to load image. ERROR: %s\n", IMG_GetError() );
    }
    else
    {
        newTexture = SDL_CreateTextureFromSurface ( renderer, loadedSurface );
        if ( newTexture == NULL )
        {
            printf( "Failed to create texture. ERROR: %s\n", IMG_GetError() );
        }
        SDL_FreeSurface ( loadedSurface );
    }

    return newTexture;
}


int main ( int argc, char* args[] )
{
    if ( !init() )
    {
        printf("ERROR#1\n");
    }
    else
    {
        if ( !loadMedia() )
        {
            printf("ERROR#2\n");
        }
        else
        {
            bool quit = false;

            SDL_Event event;

            while ( !quit )
            {
                while ( SDL_PollEvent ( &event ) != 0 )
                {
                    if ( event.type == SDL_QUIT )
                    {
                        quit = true;
                    }
                }

                SDL_RenderClear ( renderer );

                SDL_RenderCopy ( renderer, texture, NULL, NULL );

                SDL_RenderPresent ( renderer );
            }
        }
    }

    close();

    return 0;
}




























