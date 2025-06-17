#pragma once
#include "GameObject.h"
#include <vector>

class Player; //前方宣言　
class Enemys;//前方宣言

class Stage :
    public GameObject
{
private:
    Player* player_; //プレイヤーオブジェクト
    Player* PBullet_;
    Enemys* Enemy_;
    std::vector<Enemys*> enemy_;//敵オブジェクト <Enemys*> はEnemys*の配列を持っている
    std::vector<Player*> Player_;
    int hBackGround;
public:
    Stage();
    ~Stage();
    void Update() override;
    void Draw() override;
};

