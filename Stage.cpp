#include "Stage.h"
#include "Player.h"
#include "Enemys.h"

namespace
{
    const int ENEMY_NUM = 10*7;
    const int ENEMY_COL_SIZE = 10; //�G�̗�
    const int ENEMY_ROW_SIZE = 7; //�G�̍s��
}
Stage::Stage()
    :GameObject(),player_(nullptr)
{
    player_ = new Player(); //�v���C���[�I�u�W�F�N�g
    enemy_ = std::vector<Enemys*>(ENEMY_NUM);
  
       
    for (int i = 0; i < ENEMY_NUM; i++)
    {
        int col = i % ENEMY_COL_SIZE;//��
        int row = i / ENEMY_COL_SIZE;//�s
        ETYPE enemytype[ENEMY_ROW_SIZE] = {BOSS,KNIGHT,MID,ZAKO,ZAKO,ZAKO};
        enemy_[i] = new Enemys(i,enemytype[row]); //�G�̃I�u�W�F�N�g�̐���
        enemy_[i]->SetPos(col * 55, row * 50);
        //enemy_[1]->

    }
    //i% ENEMY_ROW_SIZE * 50
}


Stage::~Stage()
{
}

void Stage::Update()
{
    player_->Update(); //player�̍X�V
    for (auto& i : enemy_)
    {
        i->Update(); //�G�̍X�V
    }
}

void Stage::Draw()
{
    player_->Draw(); //player�̕`��
    // enemy�̎���\���̂�elm�Ƃ���
    for (auto& elm : enemy_)
    {
        elm->Draw();//�G�̕`��
    }
}
