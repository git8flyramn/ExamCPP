#include "Enemys.h"
#include "DxLib.h"
#include "global.h"
#include <string>
namespace
{
	const int ENEMY_IMAGE_WIDTH = 48;
	const int ENEMY_IMAGE_HEIGHT = 48;
	const int ENEMY_INIT_X = 100;
	const int ENEMY_INIT_Y = 100;
	const float ENEMY_INIT_SPEED = 100.0f;
}
//Enemys::Enemys()
//	:GameObject(),hImage_(-1), 
//	x_(0), y_(0), 
//	speed_(0), 
//	isAlive_(true)
//{
//
//}
Enemys::Enemys(int id, ETYPE type)
	:GameObject(),hImage_(-1),x_(0),y_(0),
	speed_(0),ID_(id),type_(type)
{
	//ETYPE::ZAKO;  // 10番
	//ETYPE::MID;   // 16
	//ETYPE::KNIGHT;// 18
	//ETYPE::BOSS;   // 9
	//画像の読み込み
	std::string imgPath[MAX_ETYPE] =
	{
		"Aseets/tiny_ship10.png",
		"Aseets/tiny_ship16.png",
		"Aseets/tiny_ship18.png",
		"Aseets/tiny_ship9.png"
	};
	hImage_ = LoadGraph(imgPath[type_].c_str());

	if (hImage_ == -1)
		//エラーが起きた時に発生する処理
	{

	}
	x_ = ENEMY_INIT_X;//初期座標
	y_ = ENEMY_INIT_Y;//初期座標
	speed_ = ENEMY_INIT_SPEED;//初期スピード
	AddGameObject(this);
	//idとtypeを指定されなかった時の処理を書く
}

Enemys::~Enemys()
{
	if (hImage_ != -1)
	{
		DeleteGraph(hImage_);//画像のハンドルを解放
	}
}

void Enemys::Update()
{
}

void Enemys::Draw()
{
	DrawExtendGraphF(x_,y_,
		              x_+ ENEMY_IMAGE_WIDTH ,y_+ ENEMY_IMAGE_HEIGHT,
		            hImage_, TRUE);
}
