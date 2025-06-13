#pragma once
#include "GameObject.h"
#include "global.h"
#include  <vector>
enum ETYPE
{
    ZAKO,MID,KNIGHT,BOSS,MAX_ETYPE
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
    void SetPos(float x, float y) { x_ = x; y_ = y; } //“G‚ÌÀ•W‚ğİ’è
    Rect GetRect() const { return { x_, y_, imageSize_.x, imageSize_.y }; } // “G‚Ì‹éŒ`‚ğæ“¾	
    //void SetID(int id) { ID_ = id; } //“G‚ÌID‚ğİ’è
    void SetMaxMoveX(float xmax) { xMoveMax_ = xmax; }
    void SetXorigin(float x) { xorigin_ = x; }
protected:
private:
    int hImage_;  //“G‚Ì‰æ‘œƒnƒ“ƒhƒ‹
    float x_, y_; //“G‚ÌÀ•W
    float speed_; //“G‚ÌˆÚ“®‘¬“x
    float xMoveMax_;//‰¡•ûŒü‚ÌˆÚ“®Å‘å’l
    float xorigin_;
    float moveTime_;
    Point imageSize_;

    int ID_; //“G‚ÌID
    ETYPE type_; //“G‚Ìí—Ş
};