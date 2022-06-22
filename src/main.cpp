#include <iostream>

#include <glad/glad.h>
#include <SDL.h>
#include <string>

#include "clock.hpp"

void update(double deltaTime);
void render();

int width = 800;
int height = 600;
bool vsync = true;
std::string windowTitle = "Legacy OpenGL Test";

int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cerr << "Error Initializing SDL" << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow(windowTitle.c_str(),
                                          SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                          800, 600, SDL_WINDOW_OPENGL);

    if (!window)
    {
        std::cerr << "Error Creating Window" << std::endl;
        return 1;
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);

    SDL_GLContext context = SDL_GL_CreateContext(window);

    if (!gladLoadGLLoader((GLADloadproc) SDL_GL_GetProcAddress))
    {
        std::cerr << "Failed to initialize the OpenGL context." << std::endl;
    }

    SDL_GL_SetSwapInterval(vsync ? 1 : 0);

    Clock clock;

    bool running = true;
    while (running)
    {
        clock.tick();

        SDL_SetWindowTitle(window, (windowTitle + " - FPS: " + std::to_string(clock.getFPS())).c_str());

        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    running = false;
                    break;
            }
        }

        update(clock.getDeltaTime());
        render();

        SDL_GL_SwapWindow(window);
    }

    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);

    SDL_Quit();


    return 0;
}

void update(double deltaTime)
{

}

void render()
{
    glViewport(0, 0, width, height);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0f, 1.0f, 0.0f, 1.0f, -1.0f, 1.0f);

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    {
        glVertex3f(0.25f, 0.25f, 0.0f);
        glVertex3f(0.75f, 0.25f, 0.0f);
        glVertex3f(0.75f, 0.75f, 0.0f);
        glVertex3f(0.25f, 0.75f, 0.0f);
    }
    glEnd();

    glFlush();
}