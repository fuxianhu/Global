// https://www.arealme.com/colors/cn/
#include <windows.h>
#include <iostream>
#include <ctime>
void scrollMouse(int delta)
{
    INPUT input = {0};
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_WHEEL;
    input.mi.mouseData = delta;
    SendInput(1, &input, sizeof(INPUT));
}
void clickMouse(int x, int y)
{
    SetCursorPos(x, y);
    INPUT down = {0};
    down.type = INPUT_MOUSE;
    down.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    SendInput(1, &down, sizeof(INPUT));
    INPUT up = {0};
    up.type = INPUT_MOUSE;
    up.mi.dwFlags = MOUSEEVENTF_LEFTUP;
    SendInput(1, &up, sizeof(INPUT));
}
int main()
{
    std::cout << "Start before 3 seconds...\n";
    Sleep(3000);
    SetCursorPos(954, 816);
    scrollMouse(1000);
    Sleep(100);
    clickMouse(954, 816);
    Sleep(1000);
    time_t start_time = time(nullptr);
    while (true)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                clickMouse(790 + i * 80, 530 + j * 80);
                if ((GetKeyState(VK_SPACE) & 0x8000) != 0)
                {
                    std::cout << "Space is press. Program stop.\n";
                    system("pause");
                    return 0;
                }
            }
        }
    }
    std::cout << "TLE. Program stop.\n";
    system("pause");
    return 0;
}