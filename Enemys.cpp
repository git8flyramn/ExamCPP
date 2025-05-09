#include "Enemys.h"
#include "DxLib.h"

namespace
{
	const int ENEMY_IMAGE_WIDTH = 48;
	const int ENEMY_IMAGE_HEIGHT = 48;
	const int ENEMY_INIT_X = 100;
	const int ENEMY_INIT_Y = 100;
	const float ENEMY_INIT_SPEED = 100.0f;
}
Enemys::Enemys()
	:GameObject(),hImage_(-1),x_(0),y_(0),speed_(0),isAlive_(true)
{
	hImage_ = LoadGraph("Aseets/tiny_ship10.png");
	if (hImage_ == -1)
		//�G���[���N�������ɔ������鏈��
	{

	}
	x_ = ENEMY_INIT_X;//�������W
	y_ = ENEMY_INIT_Y;//�������W
	speed_ = ENEMY_INIT_SPEED;//�����X�s�[�h
}

Enemys::~Enemys()
{
	if (hImage_ != -1)
	{
		DeleteGraph(hImage_);//�摜�̃n���h�������
	}
}

void Enemys::Update()
{
}

void Enemys::Draw()
{
	DrawExtendGraph(x_,y_,x_+ ENEMY_IMAGE_WIDTH ,y_+ ENEMY_IMAGE_HEIGHT, hImage_, TRUE);
}
