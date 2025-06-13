#include "Effect.h"
#include <DxLib.h>
#include <string>
namespace
{
	const float ANIME_TIME = { 1.0f };
	const int EFFECT_IMAGE_SIZE = 48;
	const std::string EIMGE_PATH = "Aseets/explosion.png";
	const int MAX_FRAME = 9;//画像の分割
	const int DIV_NUM = 3;//画像の分割数
	//frame_ アニメの総時間の初期値
	const float FRAME_TIME = ANIME_TIME / MAX_FRAME;
}
Effect::Effect(Point _pos) :GameObject(), pos_({ _pos.x,_pos.y }),
animtime_(ANIME_TIME), hImage_(std::vector<int>(MAX_FRAME, -1)),
frametimer_(FRAME_TIME), frame_(0)
{
	//animtime_ = GetNowCount();

	LoadDivGraph(EIMGE_PATH.c_str(), MAX_FRAME, DIV_NUM, DIV_NUM,
		EFFECT_IMAGE_SIZE, EFFECT_IMAGE_SIZE, hImage_.data());
	AddGameObject(this);
}

Effect::~Effect()
{
	/*if (hImage_ != 1)
	{
		DeleteGraph(hImage_);
	}
	hImage_ = -1;*/

	for (auto& itr : hImage_)
		DeleteGraph(itr);
	hImage_.clear();
}

void Effect::Update()
{
	float dt = GetDeltaTime();
	animtime_ = animtime_ - dt;
	if (animtime_ < 0)
	{
		this->isAlive_ = false;
	}
	frametimer_ = frametimer_ - dt;
	if (frametimer_ < 0)
	{
		frame_++;//フレームを１増やす
		frametimer_ = FRAME_TIME - frametimer_;//リセット
	}



}

void Effect::Draw()
{

	DrawExtendGraphF(pos_.x, pos_.y,
		pos_.x + EFFECT_IMAGE_SIZE, pos_.y + EFFECT_IMAGE_SIZE, hImage_[frame_], TRUE);


}