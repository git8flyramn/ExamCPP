#pragma once
#include "GameObject.h"
#include "global.h"

class Bullet :
    public GameObject
{
public:
    Bullet();
    Bullet(float x, float y);
    ~Bullet();
    void Update() override;
    void Draw() override;

    void SetPos(float x, float y);
    void SetFired(bool fired) { isFired_ = fired; } //発射状態を設定
    bool IsFired() const { return isFired_; } //発射状態を取得
    Rect GetRect() const { return   { x_,y_,imageSize_.x,imageSize_.y }; }
protected:
private:
    int hImage_; //画像
    float x_, y_;//座標
    float speed_;//移動速度
    Point imageSize_;
    //int isize_x, isize_y; //画像の表示サイズ
    bool isFired_; //発射されているかどうか true:発射されている

};