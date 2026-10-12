// SDL_Learn.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include <SDL.h>


int main(int argc, char* argv[])  // 必须带上这两个参数
{
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) < 0)
    {
        SDL_Log("SDL_Init ERROR %s", SDL_GetError());
        return -1;
    }

    SDL_Window*  windows = SDL_CreateWindow("HELLO", 
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, SDL_WINDOW_RESIZABLE);
    if (windows == NULL)
    {
        SDL_Log("SDL_CreateWindow ERROR %s", SDL_GetError());
        return -1;
    }

    SDL_Renderer* reder =  SDL_CreateRenderer(windows, -1, 0);
    if (reder == NULL)
    {
        SDL_Log("SDL_CreateRenderer ERROR %s", SDL_GetError());
        return -1;
    }

    SDL_SetRenderDrawColor(reder, 0, 0, 255, 255);
    // 全屏设置颜色
    SDL_RenderClear(reder);

    SDL_SetRenderDrawColor(reder, 0, 0, 0, 255);
    SDL_RenderDrawPoint(reder, 200, 200);

    SDL_Point pt[5] = { {0,0},{100,200},{200,300},{300,100},{400,200} };
    SDL_RenderDrawLines(reder, pt, 5);
    // 渲染
    SDL_RenderPresent(reder);


    //获取窗口
    //SDL_Surface* sufrface = SDL_GetWindowSurface(windows);
    //if (sufrface == NULL)
    //{
    //    SDL_Log("SDL_GetWindowSurface ERROR %s", SDL_GetError());
    //    return -1;
    //}

    // 绘制内容高宽
    //SDL_Rect rec = { 100,100,100,100 };
    //SDL_FillRect(sufrface, &rec, 0xff0000);

    //Uint32 * px = (Uint32*)sufrface->pixels;
    //for (int i = 30000;i < 31100;i++)
    //{
    //    px[i] = 0xfffffff;
    //}

    // 更新显示内容
    //SDL_UpdateWindowSurface(windows);

    //SDL_Delay(3000);
    SDL_Event event;
    while (true)
    {
        if (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                goto quit;
            }
        }

        //// 绘制内容高宽
        //SDL_FillRect(sufrface, &rec, 0x0000ff);
        //rec.x++;
        //SDL_FillRect(sufrface, &rec, 0xff0000);
        //// 更新显示内容
        //SDL_UpdateWindowSurface(windows);
        //SDL_Delay(20);
    }

    quit:
    
    //SDL_FreeSurface(sufrface);
    SDL_DestroyWindow(windows);
    // ...
    SDL_Quit();
    return 0;
}
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
