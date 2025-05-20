#pragma once
#include "GameObject.h"
class Bullet :
    public GameObject
{
private:
    int hImage_; //�摜
    float x_, y_;//���W
    float speed_;//�ړ����x
    bool IsAlive_;
    int isize_x, isize_y; //�摜�̕\���T�C�Y
public:
    Bullet();
    Bullet(float x, float y);
    ~Bullet();
    void Update() override;
    void Draw() override;

    void SetPos(float x, float y);
};

