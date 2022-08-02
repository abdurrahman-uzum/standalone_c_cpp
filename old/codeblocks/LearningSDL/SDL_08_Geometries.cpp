
#include <stdio.h>
#include <SDL.h>
#include <string>


const int WIDTH = 640;
const int HEIGTH = 480;

bool init();
bool loadMedia();
void close();

SDL_Window* window = NULL;

SDL_Renderer* renderer = NULL;



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
        }
    }

    return success;
}

bool loadMedia()
{
    bool success = true;

    return success;
}



void close()
{
    SDL_DestroyRenderer ( renderer );
    renderer = NULL;

    SDL_DestroyWindow ( window );
    window = NULL;

    SDL_Quit();
}


int main ( int argc, char* args[] )
{
    if ( !init() )
    {
        printf("ERROR#1\n");
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

            SDL_SetRenderDrawColor ( renderer, 255,255,255,255 );
            SDL_RenderClear ( renderer );

          //SDL_Rect <name> = { POSx, POSy, SIZEx, SIZEy };
            SDL_Rect fillRect = { WIDTH/4, HEIGTH/4, WIDTH/2, HEIGTH/2 };
            SDL_SetRenderDrawColor ( renderer, 255, 0, 0, 0 );
            SDL_RenderFillRect ( renderer, &fillRect );

            SDL_Rect outlineRect = { WIDTH/6, HEIGTH/6, WIDTH*2/3, HEIGTH*2/3 };
            SDL_SetRenderDrawColor ( renderer, 0, 255, 0, 255 );
            SDL_RenderDrawRect ( renderer, &outlineRect );

            SDL_SetRenderDrawColor ( renderer, 0,0,255,255 );
            SDL_RenderDrawLine ( renderer, 0, 0, WIDTH, HEIGTH );

            SDL_SetRenderDrawColor ( renderer, 0,0,0,255 );
            for ( int i=0; i<HEIGTH; i += 4 )
            {
                for ( int j=64; j<WIDTH; j += 64 )
                {
                    SDL_RenderDrawPoint ( renderer, j, i);
                }
            }

            SDL_RenderPresent ( renderer );
        }
    }
    close();

    return 0;
}































