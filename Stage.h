#pragma once
#include "GameObject.h"
#include <vector>

class Player; //�O���錾�@
class Enemys;//�O���錾

class Stage :
    public GameObject
{
private:
    Player* player_; //�v���C���[�I�u�W�F�N�g
    Player* PBullet_;
    Enemys* Enemy_;
    std::vector<Enemys*> enemy_;//�G�I�u�W�F�N�g <Enemys*> ��Enemys*�̔z��������Ă���
    std::vector<Player*> Player_;
    int hBackGround;
public:
    Stage();
    ~Stage();
    void Update() override;
    void Draw() override;
};

