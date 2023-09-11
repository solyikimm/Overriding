#include <iostream>
#include <vector>
#include <conio.h>
#include <Windows.h>

using namespace std;

class BaseObject
{
public:
    int _X = 0;

public:
    virtual bool Update() = 0;  // 리턴으로 파괴 여부 결정
    virtual void Render() = 0;
};

class OneStar : public BaseObject
{
public:
    OneStar(int x) { _X = x; }

    bool Update()
    {
        if (_X >= 75)
            return true;

        _X += 1;
        return false;
    }

    void Render()
    {
        cout << string(_X, ' ') << "*";
    }
};

class TwoStar : public BaseObject
{
public:
    TwoStar(int x) { _X = x; }

    bool Update()
    {
        if (_X >= 75)
            return true;

        _X += 2;
        return false;
    }

    void Render()
    {
        cout << string(_X, ' ') << "**";
    }
};

class ThreeStar : public BaseObject
{
public:
    ThreeStar(int x) { _X = x; }

public:
    bool Update()
    {
        if (_X >= 75)
        {
            return true;
        }

        _X += 3;
        return false;
    }

    void Render()
    {
        cout << string(_X, ' ') << "***";
    }
};

BaseObject* star[20];

void KeyProcess()
{
    if (_kbhit())
    {
        char key = _getch();

        if (key == '1')
        {
            for (int i = 0; i < 20; i++)
            {
                if (star[i] == nullptr)
                {
                    star[i] = new OneStar(0);
                    break;
                }
            }
        }
        else if(key == '2')
        {
            for (int i = 0; i < 20; i++)
            {
                if (star[i] == nullptr)
                {
                    star[i] = new TwoStar(0);
                    break;
                }
            }
        }
        else if (key == '3')
        {
            for (int i = 0; i < 20; i++)
            {
                if (star[i] == nullptr)
                {
                    star[i] = new ThreeStar(0);
                    break;
                }
            }
        }
    }
}

void Update()
{
    for (int i = 0; i < 20; i++)
    {
        if (star[i] != nullptr)
        {
            if (star[i]->Update())
            {
                delete star[i];
                star[i] = nullptr;
            }
        }
    }
}

void Render()
{
    for (int i = 0; i < 20; i++)
    {
        if (star[i] != nullptr)
        {
            star[i]->Render();
            cout << endl;
        } 
    }
    //BaseObject 객체 배열 전체를 돌면서
    //    Array[N]->Render();
    // 각 배열에 객체가 있던 없던 줄 바꿈을 해주자.
    // 새로운 객체를 생성시 빈 배열을 찾아서 넣고 있는데
    // 비어있는 배열에 대해서 줄 바꿈을 안해주면 
    // 자꾸 줄이 바뀌어서 보기가 안좋음 !
}

int main()
{
    while (1)
    {
        KeyProcess();
        Update();
        system("cls");
        Render();
        Sleep(30);
    }

    return 0;
}