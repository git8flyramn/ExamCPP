#pragma once
#include "GameObject.h"
#include "global.h"
#include  <vector>
class Bullet;
enum ETYPE
{
    ZAKO, MID, KNIGHT, BOSS, MAX_ETYPE
};
class Enemys :
    public GameObject
{
public:
    Enemys(int id, ETYPE type);
    Enemys();
    ~Enemys();
    void Update() override;
    void Draw() override;
    void SetPos(float x, float y) { x_ = x; y_ = y; } //敵の座標を設定
    Rect GetRect() const { return { x_, y_, imageSize_.x, imageSize_.y }; }// 敵の矩形を取得	
    //void SetID(int id) { ID_ = id; } //敵のIDを設定
    void SetMaxMoveX(float xmax) { xMoveMax_ = xmax; }
    void SetXorigin(float x) { xorigin_ = x; }
    Bullet* GetActiveBullet();
    std::vector<Bullet*> GetAllBullets() const { return ebullets_; } //全ての弾を取得
private:
    int hImage_;  //敵の画像ハンドル
    float x_, y_; //敵の座標
    float speed_; //敵の移動速度
    float xMoveMax_;//横方向の移動最大値
    float xorigin_;
    float moveTime_;
    Point imageSize_;
    int ID_; //敵のID
    std::vector<Bullet*> ebullets_; //エネミーが発射した弾のベクター
    ETYPE type_; //敵の種類
 

};