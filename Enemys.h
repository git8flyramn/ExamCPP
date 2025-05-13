#pragma once
#include "GameObject.h"

enum ETYPE
{
    ZAKO,MID,KNIGHT,BOSS,MAX_ETYPE
};
class Enemys :
    public GameObject
{
    int hImage_; //�摜�n���h��
    float x_, y_;//�G�̍��W
    float speed_;//�G�̈ړ����x
    bool isAlive_; //�G�̐���
    int ID_; //�G��ID
    ETYPE type_; //�G�̎��
public:
    Enemys(int id,ETYPE type);
   // Enemys();
    ~Enemys();
    void Update() override;
    void Draw() override;
    void SetPos(float x, float y) { x_ = x; y_ = y; }//�G�̍��W��ݒ�
    //void SetID(int id) { ID_ = id; }
};