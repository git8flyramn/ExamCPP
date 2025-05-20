#include "Stage.h"
#include "Player.h"
#include "Enemys.h"

namespace
{
    const int ENEMY_NUM = 10*7;
    const int ENEMY_COL_SIZE = 10; //敵の列数
    const int ENEMY_ROW_SIZE = 7; //敵の行数
}
Stage::Stage()
    :GameObject(),player_(nullptr)
{
    AddGameObject(this); //ステージオブジェクトをゲームオブジェクトに追加
    player_ = new Player(); //プレイヤーオブジェクト
    enemy_ = std::vector<Enemys*>(ENEMY_NUM);
  
    

    for (int i = 0; i < ENEMY_NUM; i++) //敵をENEMY_NUMの数だけ描画させる
    {
        int col = i % ENEMY_COL_SIZE;//列
        int row = i / ENEMY_COL_SIZE;//行
        ETYPE enemytype[ENEMY_ROW_SIZE] = {BOSS,KNIGHT,MID,ZAKO,ZAKO,ZAKO};
        enemy_[i] = new Enemys(i,enemytype[row]); //敵のオブジェクトの生成
        enemy_[i]->SetPos(col * 55, row * 50); //敵の初期位置


    }
}


Stage::~Stage()
{
}

void Stage::Update()
{
    player_->Update(); //playerの更新
    for (auto& i : enemy_)
    {
        i->Update(); //敵の更新
    }
}

void Stage::Draw()
{
    player_->Draw(); //playerの描画
    // enemyの事を表すのにelmに置き換える
    for (auto& elm : enemy_)
    {
        elm->Draw();//敵の描画
    }
}
