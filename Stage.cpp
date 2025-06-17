#include <DxLib.h>
#include "Stage.h"
#include "Player.h"
#include "Enemys.h"
#include "Bullet.h"
namespace
{
    const int ENEMY_NUM = 10*7;
    const int PLAYER_NUM = 1;
    const int ENEMY_COL_SIZE = 10; //敵の列数
    const int ENEMY_ROW_SIZE = 7; //敵の行数
    const float ENEMY_ALIGN_X = 55.0f; //敵の1匹
    const float ENEMY_ALIGN_Y = 50.0f;
    const int ENEMY_LEFT_MARGIN = (WIN_WIDTH - (ENEMY_ALIGN_X * ENEMY_COL_SIZE)) / 2;
    const int ENEMY_TOP_MARGIN = 75;
    bool IntersepctRect(const Rect &a,const Rect &b)
    {

        bool xOverlap = (a.x < b.x + b.width) && (b.x < a.x + a.width);

        bool yOverlap = (a.y < b.y + b.height) && (b.y < a.y + a.height);
 
        return xOverlap && yOverlap;
    }
}
Stage::Stage()
    :GameObject(),player_(nullptr),hBackGround(-1)
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
        enemy_[i]->SetMaxMoveX(ENEMY_LEFT_MARGIN);
        enemy_[i]->SetPos(col * ENEMY_ALIGN_X + ENEMY_LEFT_MARGIN,
                          row * ENEMY_ALIGN_Y + ENEMY_TOP_MARGIN); //敵の初期位置
        enemy_[i]->SetXorigin(col * ENEMY_ALIGN_X + ENEMY_LEFT_MARGIN);

    }
    hBackGround = LoadGraph("Aseets///bg.png");


}


Stage::~Stage()
{
}

void Stage::Update()
{
    //ここに当たり判定を描きたい

    std::vector<Bullet*> bullets = player_->GetAllBullets();
    for (auto& e : enemy_)
    {
        for (auto& b : bullets)
        {
            if (b->IsFired() && e->IsAlive()) {
                if (IntersepctRect(e->GetRect(), b->GetRect()))
                {
                    if (b->IsFired())
                    {
                        b->SetFired(false);
                        if (e->IsAlive())
                        {
                            e->SetAlive(false);
                        }
                    }
                }
            }
        }
    }
  
} 

void Stage::Draw()
{
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
    DrawExtendGraph(0, 0, WIN_WIDTH, WIN_HEIGHT, hBackGround, FALSE);
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND ,0);
}
