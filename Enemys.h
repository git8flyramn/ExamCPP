#pragma once
#include "GameObject.h"

enum ETYPE
{
    ZAKO,MID,KNIGHT,BOSS,MAX_ETYPE
};
class Enemys :
    public GameObject
{
    int hImage_; //‰æ‘œƒnƒ“ƒhƒ‹
    float x_, y_;//“G‚ÌÀ•W
    float speed_;//“G‚ÌˆÚ“®‘¬“x
    bool isAlive_; //“G‚Ì¶€
    int ID_; //“G‚ÌID
    ETYPE type_; //“G‚Ìí—Ş
public:
    Enemys(int id,ETYPE type);
   // Enemys();
    ~Enemys();
    void Update() override;
    void Draw() override;
    void SetPos(float x, float y) { x_ = x; y_ = y; }//“G‚ÌÀ•W‚ğİ’è
    //void SetID(int id) { ID_ = id; }
};