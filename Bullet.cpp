#include "global.h"
#include "Bullet.h"
#include "DxLib.h"
#include <string>
namespace {
	const int BULLET_IMAGE_WIDTH = 13; //弾の画像の幅
	const int BULLET_IMAGE_HEIGHT = 33;//弾の画像の高さ
	const float BULLET_INIT_SPEED = 200.0f; //弾のスピード
	const std::string BULLET_IMAGE_PATH = "Aseets//laserBlue03.png";
	//const std::string  BULLET_IMAGE_PATH = "Aseets//laserBlue07.png";
	//const std::string  BULLET_IMAGE_PATH = "Aseets//laserBlue06.png";
	//const std::string  BULLET_IMAGE_PATH = "Aseets//laserBlue01.png";


}
Bullet::Bullet()
	:GameObject(), hImage_(-1),
	x_(0), y_(0), speed_(0), isFired_(false),
	imageSize_({ BULLET_IMAGE_WIDTH,BULLET_IMAGE_HEIGHT })
{
	hImage_ = LoadGraph(BULLET_IMAGE_PATH.c_str()); //弾の画像を読み込む c_str = ｃの配列としてstring持ってくる
	speed_ = BULLET_INIT_SPEED; //移動速度
	AddGameObject(this);
}

Bullet::Bullet(float x, float y)
	:GameObject(), hImage_(-1),
	x_(x), y_(y), speed_(0), isFired_(false),
	imageSize_({ BULLET_IMAGE_WIDTH,BULLET_IMAGE_HEIGHT })
{
	hImage_ = LoadGraph(BULLET_IMAGE_PATH.c_str()); //弾の画像を読み込む c_str = ｃの配列としてstring持ってくる
	speed_ = BULLET_INIT_SPEED; //移動速度	
	AddGameObject(this);
}

Bullet::~Bullet()
{
	if (hImage_ != 1)
	{
		DeleteGraph(hImage_); //画像の解放
	}
	hImage_ = -1; //画像ハンドルを無効化
}

void Bullet::Update()
{
	float dt = GetDeltaTime();
	y_ = y_ - speed_ * dt; //弾の移動
	if (y_ < 0)
	{
		isFired_ = false; //画面外にでたら準備状態に戻す
	}
}

void Bullet::Draw()
{
	//発射されていたら描画
	if (isFired_)
	{
		DrawExtendGraphF(x_, y_, x_ + imageSize_.x, y_ + imageSize_.y,
			hImage_, TRUE);//弾の描画
	}
}

void Bullet::SetPos(float x, float y)
{
	x_ = x;
	y_ = y;
}