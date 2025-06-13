#pragma once
#include "GameObject.h"
#include "global.h"
class Bullet; //前方宣言
class Player:
    public GameObject
{
    int hImage_; //画像ハンドル
    float x_, y_;//プレイヤーの座標
    Point imageSize_;//画像のサイズ
    float speed_;//プレイヤーの移動速度
    std::vector<Bullet*> bullets_; //プレイヤーが発射した弾のベクター 
    Bullet* GetActiveBullet();
public:
    Player();
    ~Player();
    void Update() override;
    void Draw() override;
    void Shoot();//弾を発射する関数
    Rect GetRect() const { return { x_,y_,imageSize_.x,imageSize_.y }; }//プレイヤーの矩形を取得
    std::vector<Bullet*> GetAllBullets() const { return bullets_; } //全ての弾を取得

};

