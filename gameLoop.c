#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

SDL_Window* window;
SDL_Renderer* renderer;
// Creacion de struct ball que nos va a definir un cuadrado en la pantalla x e y son las coordenadas
// de la esquina superior izquierda, y width y height son su tamaño (ancho y alto)
struct ball 
{
    float x;
    float y;
    float width;
    float height;
} ball;

bool initialize_window();
void process_input(bool *game_is_running);
void setup();
void update();
void render();
void destroy_window();

int main(int argc, char** argv)
{
    bool game_running = initialize_window();
    //eventos como teclas, raton, etc
    setup();

    while (game_running)
    {
        process_input(&game_running);
        update();
        render();
    }

    destroy_window();
    return 0;
    
}

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

void setup()
{
    ball.x = 20;
    ball.y = 20;
    ball.width = 10;
    ball.height = 10;
}

void update()
{
    ball.x += 1;
    ball.y += 1;
}

void process_input(bool *game_is_running)
{
    SDL_Event sdl_event;

    SDL_PollEvent(&sdl_event);

    switch (sdl_event.type)
    {
        case SDL_QUIT:
            *game_is_running = false;
            break;
        case SDL_KEYDOWN:
            if (sdl_event.key.keysym.sym == SDLK_ESCAPE)
            {
                *game_is_running = false;
            }
            break;
    }
}

void render()
{
    // Clear the renderer
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Create a ball object
    SDL_Rect ball_rect = {
        (int)ball.x,
        (int)ball.y,
        (int)ball.width,
        (int)ball.height
    };

    // Draw the object on the screen
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &ball_rect);

    // Swap the video buffer
    SDL_RenderPresent(renderer);

}

void destroy_window()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}



/*This is a GameLoop that depends on the hardware and does not take into account
the frame rate on the computer
*/



