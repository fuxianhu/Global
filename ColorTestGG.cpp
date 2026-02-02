// https://www.arealme.com/colors/cn/
#include <windows.h>
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
    Sleep(3000);
    scrollMouse(1000);
    Sleep(100);
    clickMouse(949, 636);
    Sleep(1000);
    time_t start_time = time(nullptr);
    while (difftime(time(nullptr), start_time) < 61)
    {
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                clickMouse(670 + i * 100, 290 + j * 100);
                if ((GetKeyState(VK_SPACE) & 0x8000) != 0)
                {
                    return 0;
                }
            }
        }
    }
    return 0;
}