#include <windows.h>
#include <iostream>
#include <chrono>
#include <conio.h>

void simulateKeyPress(WORD vKey) {
    // ׼�����������¼�
    INPUT input = { 0 };
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = vKey;  // �������ⰴ��
    SendInput(1, &input, sizeof(INPUT));
    Sleep(30);
    // ׼�������ͷ��¼�
    input.ki.dwFlags = KEYEVENTF_KEYUP;  // �����ͷ�
    SendInput(1, &input, sizeof(INPUT));
}

void simulateRightClick() {
    // ׼�����������¼�
    INPUT input = { 0 };
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
    SendInput(1, &input, sizeof(INPUT));
    Sleep(50);
    // ׼�������ͷ��¼�
    input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
    SendInput(1, &input, sizeof(INPUT));
}


bool isKeyDown(WORD vKey) {
    return GetAsyncKeyState(vKey) & 0x8000 || GetAsyncKeyState(vKey+32) & 0x8000;
}

//��A
void AutoChangeA(){
    printf("�ѿ�����A\n");
    printf("�뽫װ�����������һ������\n");
    printf("����\\ͷ��\\����\n");
    while (true) {
        if (isKeyDown('F')) {
            Sleep(330);
            if(isKeyDown('F'))simulateKeyPress(0x31);//������װ��
            Sleep(60);
        }
        // ��һ��С��ʱ�������CPUռ��
        Sleep(1);
    }
}

void AutoRunA() {
    printf("�ѿ�����A\n");
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
    printf("�ѿ������A\n");
    printf("�뽫������Ʒ���������һ������\n");
    while (true) {
        if (isKeyDown('F')) {
            Sleep(360);
            if (isKeyDown('F'))
            {
                //simulateRightClick();//�Ҽ�����
                simulateKeyPress(0x31);
            }
        }
        // ��һ��С��ʱ�������CPUռ��
        Sleep(1);
    }
}

int main() {
    printf("1.��A    �ر��Ӳ�\n");
    printf("2.��A    �����Ӳ�\n");
    printf("3.���A  �����Ӳ�\n");
    printf("����F�����Զ�A.\n");
    printf("��A�ͼ��A �轫 ������Ʒ ���ڴ����1������!\n\n");

    printf("��ѡ��������:");
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
