#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

SDL_Window* window;
SDL_Renderer* renderer;

bool initialize_window()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        fprintf(stderr, "Error creating SDL. \n");
        return false;
    }
    window = SDL_CreateWindow("Hello", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    if(!window)
    {
        fprintf(stderr, "Error creating SDL Window. \n");
        return false;
    }
    renderer = SDL_CreateRenderer(window, -1, 0);
    if(!renderer)
    {
        fprintf(stderr, "Error creating SDL renderer. \n");
        return false;
    }

    return true;
}

int main(int argc, char* argv[])
{
    if(initialize_window())
    {
        //Clean the video buffer
        SDL_RenderClear(renderer);

        //Create a ball object
        SDL_Rect ball_rect = {100,100,20,20};

        //Draw the object on the screen
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &ball_rect);

        //Swap the video buffer
        SDL_RenderPresent(renderer);

        //Wait two seconds
        SDL_Delay(2000);

        //Destroy the window to free its memory
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
    return 0;
}