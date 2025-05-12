#include <windows.h>
#include <iostream>
#include <chrono>
#include <conio.h>

void simulateKeyPress(WORD vKey) {
    // 准备按键输入事件
    INPUT input = { 0 };
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = vKey;  // 按下虚拟按键
    SendInput(1, &input, sizeof(INPUT));
    Sleep(30);
    // 准备按键释放事件
    input.ki.dwFlags = KEYEVENTF_KEYUP;  // 按键释放
    SendInput(1, &input, sizeof(INPUT));
}

void simulateRightClick() {
    // 准备按键输入事件
    INPUT input = { 0 };
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
    SendInput(1, &input, sizeof(INPUT));
    Sleep(50);
    // 准备按键释放事件
    input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
    SendInput(1, &input, sizeof(INPUT));
}


bool isKeyDown(WORD vKey) {
    return GetAsyncKeyState(vKey) & 0x8000 || GetAsyncKeyState(vKey+32) & 0x8000;
}

//切A
void AutoChangeA(){
    printf("已开启切A\n");
    printf("请将装备放在左起第一个格子\n");
    printf("武器\\头盔\\护甲\n");
    while (true) {
        if (isKeyDown('F')) {
            Sleep(330);
            if(isKeyDown('F'))simulateKeyPress(0x31);//按下切装备
            Sleep(60);
        }
        // 加一个小延时，避免高CPU占用
        Sleep(1);
    }
}

void AutoRunA() {
    printf("已开启走A\n");
    char key, a, b;
    key = a = 'W';
    b = 'S';
    while (true) {
        if (isKeyDown('F')) {
            Sleep(298);
            if (isKeyDown('F'))
            {
                simulateKeyPress(key);
                key = (key == a ? b : a);
                Sleep(60);
            }
        }
        Sleep(1);
    }
}

void AutoCheckA() {
    printf("已开启检查A\n");
    printf("请将交互物品放在左起第一个格子\n");
    while (true) {
        if (isKeyDown('F')) {
            Sleep(360);
            if (isKeyDown('F'))
            {
                //simulateRightClick();//右键单机
                simulateKeyPress(0x31);
            }
        }
        // 加一个小延时，避免高CPU占用
        Sleep(1);
    }
}

int main() {
    printf("1.切A    关闭延补\n");
    printf("2.走A    开启延补\n");
    printf("3.检查A  开启延补\n");
    printf("长按F即可自动A.\n");
    printf("切A和检查A 需将 交互物品 放在从左第1个格子!\n\n");

    printf("请选择操作编号:");
    char c = _getch();
    printf("%c\n",c);
    switch (c) {
    case '1':AutoChangeA(); break;
    case '2':AutoRunA(); break;
    case '3':AutoCheckA(); break;
    default:break;
    }
    system("pause");
    return 0;
}
