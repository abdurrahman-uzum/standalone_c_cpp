#include <SDL.h>
#include <stdio.h>

const int SCREEN_WIDTH = 1152;
const int SCREEN_HEIGHT = 648;

int init();
int loadMedia();
void close();

SDL_Window* window = NULL;

SDL_Surface* surface = NULL;

SDL_Surface* image = NULL;


int init ()
{
    int success = 1;

    if ( SDL_Init ( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! Error: %s\n", SDL_GetError() );
        success = 0;
    }
    else
    {
            window = SDL_CreateWindow ( "Window Name", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );

            if ( window == NULL )
            {
                printf(" Window could not initialize! Error: %s\n", SDL_GetError() );
                success = 0;
            }
            else
            {
                surface = SDL_GetWindowSurface ( window );
            }
    }
    return success;
}




int loadMedia(const int mediaNumber)
{
    int success = 1;

    switch ( mediaNumber )
    {
    case 1:
        image = SDL_LoadBMP ("animation/frame1.bmp");
        if ( image == NULL ) { success = 0; }
        break;
    case 2:
        image = SDL_LoadBMP ("animation/frame2.bmp");
        if ( image == NULL ) { success = 0; }
        break;
    case 3:
        image = SDL_LoadBMP ("animation/frame3.bmp");
        if ( image == NULL ) { success = 0; }
        break;
    case 4:
        image = SDL_LoadBMP ("animation/frame4.bmp");
        if ( image == NULL ) { success = 0; }
        break;
    case 5:
        image = SDL_LoadBMP ("animation/frame5.bmp");
        if ( image == NULL ) { success = 0; }
        break;
    case 6:
        image = SDL_LoadBMP ("animation/frame6.bmp");
        if ( image == NULL ) { success = 0; }
        break;
    case 7:
        image = SDL_LoadBMP ("animation/frame7.bmp");
        if ( image == NULL ) { success = 0; }
        break;
    case 8:
        image = SDL_LoadBMP ("animation/frame8.bmp");
        if ( image == NULL ) { success = 0; }
        break;
    case 9:
        image = SDL_LoadBMP ("animation/frame9.bmp");
        if ( image == NULL ) { success = 0; }
        break;
    case 10:
        image = SDL_LoadBMP ("animation/frame10.bmp");
        if ( image == NULL ) { success = 0; }
        break;
    case 11:
        image = SDL_LoadBMP ("animation/frame11.bmp");
        if ( image == NULL ) { success = 0; }
        break;
    case 12:
        image = SDL_LoadBMP ("animation/frame12.bmp");
        if ( image == NULL ) { success = 0; }
        break;
    case 13:
        image = SDL_LoadBMP ("animation/frame13.bmp");
        if ( image == NULL ) { success = 0; }
        break;
    case 14:
        image = SDL_LoadBMP ("animation/frame14.bmp");
        if ( image == NULL ) { success = 0; }
        break;
    case 15:
        image = SDL_LoadBMP ("animation/frame15.bmp");
        if ( image == NULL ) { success = 0; }
        break;
    case 16:
        image = SDL_LoadBMP ("animation/frame16.bmp");
        if ( image == NULL ) { success = 0; }
        break;
    case 17:
        image = SDL_LoadBMP ("animation/frame17.bmp");
        if ( image == NULL ) { success = 0; }
        break;
    case 18:
        image = SDL_LoadBMP ("animation/frame18.bmp");
        if ( image == NULL ) { success = 0; }
        break;
    case 19:
        image = SDL_LoadBMP ("animation/frame19.bmp");
        if ( image == NULL ) { success = 0; }
        break;
    case 20:
        image = SDL_LoadBMP ("animation/frame20.bmp");
        if ( image == NULL ) { success = 0; }
        break;
    case 21:
        image = SDL_LoadBMP ("animation/frame21.bmp");
        if ( image == NULL ) { success = 0; }
        break;
    case 22:
        image = SDL_LoadBMP ("animation/frame22.bmp");
        if ( image == NULL ) { success = 0; }
        break;
    case 23:
        image = SDL_LoadBMP ("animation/frame23.bmp");
        if ( image == NULL ) { success = 0; }
        break;
    case 25:
        image = SDL_LoadBMP ("animation/frame25.bmp");
        if ( image == NULL ) { success = 0; }
        break;
    case 26:
        image = SDL_LoadBMP ("animation/frame26.bmp");
        if ( image == NULL ) { success = 0; }
        break;
    case 27:
        image = SDL_LoadBMP ("animation/frame27.bmp");
        if ( image == NULL ) { success = 0; }
        break;
    case 28:
        image = SDL_LoadBMP ("animation/frame28.bmp");
        if ( image == NULL ) { success = 0; }
        break;
    case 29:
        image = SDL_LoadBMP ("animation/frame29.bmp");
        if ( image == NULL ) { success = 0; }
        break;
    case 30:
        image = SDL_LoadBMP ("animation/frame30.bmp");
        if ( image == NULL ) { success = 0; }
        break;
    default :
        printf("Something has gone really bad!\n");
        break;
    }




    return success;
}

void close()
{
    SDL_FreeSurface ( image );
    image = NULL;

    SDL_DestroyWindow ( window );
    window = NULL;

    SDL_Quit();

}



int main ( int argc, char* args[] )
{



    if ( !init() )
    {
            printf( "Could not initialize!\n" );
    }
    else
    {
        int i;
        for (i=1; i<7; i++)
        {
            int n = i%2 + 1;
            if ( !loadMedia(n) )
            {
                printf("Failed to load media!\n");
            }
            else
            {
                SDL_BlitSurface ( image, NULL, surface, NULL );

                SDL_UpdateWindowSurface ( window );

                SDL_Delay(200);
            }
        }



        for (i=1; i<24; i++)
        {
            if ( !loadMedia(i) )
            {
                printf("Failed to load media!\n");
            }
            else
            {
                SDL_BlitSurface ( image, NULL, surface, NULL );

                SDL_UpdateWindowSurface ( window );

                SDL_Delay(200);
            }
        }

        if ( !loadMedia(23) )
            {
                printf("Failed to load media!\n");
            }
            else
            {
                SDL_BlitSurface ( image, NULL, surface, NULL );

                SDL_UpdateWindowSurface ( window );

                SDL_Delay(750);
            }
        for (i=25; i<31; i++)
        {
            if ( !loadMedia(i) )
            {
                printf("Failed to load media!\n");
            }
            else
            {
                SDL_BlitSurface ( image, NULL, surface, NULL );

                SDL_UpdateWindowSurface ( window );

                SDL_Delay(200);
            }
        }
        SDL_Delay(1000);


    }
    close();



    return 0;
}











