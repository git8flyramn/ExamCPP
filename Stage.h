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
    //<Enemys*> はEnemys*の配列を持っている
    std::vector<Enemys*> enemy_;//敵オブジェクト
public:
    Stage();
    ~Stage();
    void Update() override;
    void Draw() override;
};

