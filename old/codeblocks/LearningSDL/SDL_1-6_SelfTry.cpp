#include <stdio.h>
#include <SDL.h>
#include <SDL_Image.h>
#include <string>


const int WIDTH = 640;
const int HEIGTH = 480;

enum keys {
    DEFAULT, //0
    UP,      //1
    DOWN,    //2
    LEFT,    //3
    RIGHT,   //4
    WTF,     //5
    TOTAL    //6
};


bool init();
bool loadMedia();
void close();
SDL_Surface* loadSurface ( std::string path );

SDL_Window* window = NULL;

SDL_Surface* surface = NULL;
SDL_Surface* image = NULL;
SDL_Surface* keySurfaces[TOTAL];  // Array of surface pointers in the number of enum elements.
SDL_Surface* currentSurface = NULL;
SDL_Surface* surfacePNG = NULL;







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
            //surface = SDL_GetWindowSurface ( window );
            int imgFlags = IMG_INIT_PNG;
            if ( !(IMG_Init ( imgFlags ) &imgFlags ) )
            {
                printf( "SDL_Image could not initialize. ERROR: %s\n", IMG_GetError() );
                success = false;
            }
            else
            {
                surface = SDL_GetWindowSurface ( window );
            }
        }
    }
    return success;
}



bool loadMedia()
{
    bool success = true;

    keySurfaces[DEFAULT] = loadSurface("SDL_Tutorial_Media/keyPressesMedia/press.bmp");
    keySurfaces[UP] = loadSurface("SDL_Tutorial_Media/keyPressesMedia/up.bmp");
    keySurfaces[DOWN] = loadSurface("SDL_Tutorial_Media/keyPressesMedia/down.bmp");
    keySurfaces[LEFT] = loadSurface("SDL_Tutorial_Media/keyPressesMedia/left.bmp");
    keySurfaces[RIGHT] = loadSurface("SDL_Tutorial_Media/keyPressesMedia/right.bmp");
    keySurfaces[WTF] = loadSurface("SDL_Tutorial_Media/keyPressesMedia/wtfFormatPNG.png");

    if ( keySurfaces[DEFAULT] == NULL ||
         keySurfaces[UP] == NULL ||
         keySurfaces[DOWN] == NULL ||
         keySurfaces[LEFT] == NULL ||
         keySurfaces[RIGHT] == NULL  )
    {
        printf("Check your goddamn BMP files! ERROR: %s\n", SDL_GetError());
        success = false;
    }

    return success;
}




SDL_Surface* loadSurface ( std::string path )
{
    SDL_Surface* optimizedSurface = NULL;
    //SDL_Surface* loadedSurface = SDL_LoadBMP ( path.c_str() );
    SDL_Surface* loadedSurface = IMG_Load ( path.c_str() );

    if ( loadedSurface == NULL )
    {
        printf("#1 In loadSurface(std::string path) ERROR: %s\n", SDL_GetError() );
    }
    else
    {
        optimizedSurface = SDL_ConvertSurface ( loadedSurface, surface->format, 0 );
        if ( optimizedSurface == NULL )
        {
            printf( "#2 In loadSurface(std::string path) ERROR: %s\n", SDL_GetError() );
        }
        SDL_FreeSurface ( loadedSurface );
    }

    return optimizedSurface;
}




void close()
{
    for ( int i=0; i<TOTAL; i++ )
    {
        SDL_FreeSurface ( keySurfaces[i] );
        keySurfaces[i] = NULL;
    }

    SDL_DestroyWindow ( window );

    IMG_Quit();
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
        if ( !loadMedia() )
        {
            printf("ERROR#2\n");
        }
        SDL_Event event;

        currentSurface = keySurfaces[DEFAULT];


        bool quit = false;

        while ( !quit )
        {
            while ( SDL_PollEvent ( & event ) != 0 )
            {
                if ( event.type == SDL_QUIT )
                {
                    printf("Sorry to see you leaving :(\n ");
                    quit = true;
                }
                else if ( event.type == SDL_KEYDOWN )
                {
                    switch ( event.key.keysym.sym )
                    {
                    case SDLK_UP: case SDLK_w:
                        currentSurface = keySurfaces[UP];
                        break;
                    case SDLK_DOWN: case SDLK_s:
                        currentSurface = keySurfaces[DOWN];
                        break;
                     case SDLK_LEFT: case SDLK_a:
                        currentSurface = keySurfaces[LEFT];
                        break;
                     case SDLK_RIGHT: case SDLK_d:
                        currentSurface = keySurfaces[RIGHT];
                        break;
                     default:
                        currentSurface = keySurfaces[WTF];
                        break;
                    }
                }

            }
            /*
            SDL_Rect rect;
            rect.x = 0;
            rect.y = 0;
            rect.w = WIDTH;
            rect.h = HEIGTH;

            SDL_BlitScaled ( currentSurface, NULL, surface, &rect );*/

            SDL_BlitSurface ( currentSurface, NULL, surface, NULL );
            SDL_UpdateWindowSurface ( window );
        }
    }
    close();
    return 0;

}















