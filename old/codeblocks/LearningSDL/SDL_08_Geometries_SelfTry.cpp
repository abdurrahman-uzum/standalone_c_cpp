#include <stdio.h>
#include <SDL.h>

const int WIDTH = 640;
const int HEIGTH = 480;
void close();
bool init();

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;


bool init()
{
    bool success = true;

    if ( SDL_Init ( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "Failed to initialize SDL. ERROR: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        if ( !SDL_SetHint ( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
        {
            printf( "Something that i don't understand. ERROR: %s\n", SDL_GetError() );
            success = false;
        }

        window = SDL_CreateWindow ( "Window Name", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGTH, SDL_WINDOW_SHOWN );
        if ( window == NULL )
        {
            printf( "Failed to initialize window. ERROR: %s\n", SDL_GetError() );
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


void close()
{
    SDL_DestroyRenderer ( renderer );
    SDL_DestroyWindow ( window );
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

        SDL_Rect rect;
        rect.x = 0;
        rect.y = 0;
        rect.w = 100;
        rect.h = 100;

        SDL_SetRenderDrawColor ( renderer, 255,255,255,255 );
        SDL_RenderClear( renderer );
        SDL_SetRenderDrawColor ( renderer, 0,255,0,255 );
        SDL_RenderFillRect ( renderer, &rect );
        SDL_RenderPresent ( renderer );
        while ( !quit )
        {


            while ( SDL_PollEvent (&event) != 0 )
            {
                if ( event.type == SDL_QUIT )
                {
                    quit = true;
                }
                else if ( event.type == SDL_KEYDOWN )
                {
                    switch ( event.key.keysym.sym )
                    {
                        case SDLK_w:
                            SDL_SetRenderDrawColor ( renderer, 255,255,255,255 );
                            SDL_RenderClear( renderer );
                            SDL_SetRenderDrawColor ( renderer, 0,255,0,255 );
                            rect.y -= 10;
                            break;
                        case SDLK_s:
                            SDL_SetRenderDrawColor ( renderer, 255,255,255,255 );
                            SDL_RenderClear( renderer );
                            SDL_SetRenderDrawColor ( renderer, 0,255,0,255 );
                            rect.y += 10;
                            break;
                        case SDLK_a:
                            SDL_SetRenderDrawColor ( renderer, 255,255,255,255 );
                            SDL_RenderClear( renderer );
                            SDL_SetRenderDrawColor ( renderer, 0,255,0,255 );
                            rect.x -= 10;
                            break;
                        case SDLK_d:
                            SDL_SetRenderDrawColor ( renderer, 255,255,255,255 );
                            SDL_RenderClear( renderer );
                            SDL_SetRenderDrawColor ( renderer, 0,255,0,255 );
                            rect.x += 10;
                            break;
                    }
                    SDL_RenderFillRect ( renderer, &rect );
                    SDL_RenderPresent ( renderer );
                }

            }





        }
    }

    close ();

    return 0;
}


























