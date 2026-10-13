// SDL_Learn.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include <SDL.h>
SDL_Window* windows = NULL;
SDL_Renderer* reder = NULL;
SDL_Rect rect = {100,100,100,100};

int init()
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
        SDL_Log("SDL_Init ERROR %s", SDL_GetError());
        return -1;
    }

    windows = SDL_CreateWindow("HELLO",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, SDL_WINDOW_RESIZABLE);
    if (windows == NULL)
    {
        SDL_Log("SDL_CreateWindow ERROR %s", SDL_GetError());
        return -1;
    }

    reder = SDL_CreateRenderer(windows, -1, 0);
    if (reder == NULL)
    {
        SDL_Log("SDL_CreateRenderer ERROR %s", SDL_GetError());
        return -1;
    }
    return 0;
}

void deinit()
{
    //SDL_FreeSurface(sufrface);
    SDL_DestroyWindow(windows);
    SDL_DestroyRenderer(reder);
    // ...
    SDL_Quit();
}

void draw(int x,int y)
{
    SDL_SetRenderDrawColor(reder, 0, 0, 255, 255);
    // 全屏设置颜色
    SDL_RenderClear(reder);

    if (x != 0|| y != 0)
    {
        rect = { x-50,y-50,100,100 };
    }
    SDL_SetRenderDrawColor(reder, 255, 0, 0, 255);

    SDL_RenderFillRect(reder, &rect);
    // 渲染
    SDL_RenderPresent(reder);
}

void event_loop()
{
    //SDL_Delay(3000);
    SDL_Event event;
    while (true)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
             case SDL_QUIT:
                 return;
             case SDL_WINDOWEVENT:
                 if (event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
                 {
                     draw(0,0);
                 }
             case SDL_MOUSEMOTION:
                 SDL_Log("X = %d Y= %d", event.motion.x, event.motion.y);
                 draw(event.motion.x, event.motion.y);
                 break;
             case SDL_MOUSEBUTTONDOWN:
                 SDL_Log("click= %d ", event.button.clicks);
                 break;
             //case SDL_MOUSEBUTTONUP:
             //    SDL_Log("click= %d ", event.button.clicks);
             //    break;
             case SDL_KEYDOWN:
                 SDL_Log("down sym = %d, scancode = %d", event.key.keysym.sym, event.key.keysym.scancode);
                 break;
             default:
                 break;
            }
        }
    }
}

int main(int argc, char* argv[]) 
{
    if (init() == -1)
    {
        return -1;
    }

    draw(0,0);

    event_loop();

    deinit();
   
    return 0;
}
