#pragma once
#include "GameObject.h"
class Enemys :
    public GameObject
{
    int hImage_; //�摜�n���h��
    float x_, y_;//�G�̍��W
    float speed_;//�G�̈ړ����x
    bool isAlive_; //�G�̐���
public:
    Enemys();
    ~Enemys();
    void Update() override;
    void Draw() override;
    void SetPos(float x, float y) { x_ = x; y_ = y; }//�G�̍��W��ݒ�
};