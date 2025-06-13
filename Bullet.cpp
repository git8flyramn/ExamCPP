#include "global.h"
#include "Bullet.h"
#include "DxLib.h"
#include <string>
namespace {
	const int BULLET_IMAGE_WIDTH = 13; //�e�̉摜�̕�
	const int BULLET_IMAGE_HEIGHT = 33;//�e�̉摜�̍���
	const float BULLET_INIT_SPEED = 200.0f; //�e�̃X�s�[�h
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
	hImage_ = LoadGraph(BULLET_IMAGE_PATH.c_str()); //�e�̉摜��ǂݍ��� c_str = ���̔z��Ƃ���string�����Ă���
	speed_ = BULLET_INIT_SPEED; //�ړ����x
	AddGameObject(this);
}

Bullet::Bullet(float x, float y)
	:GameObject(), hImage_(-1),
	x_(x), y_(y), speed_(0), isFired_(false),
	imageSize_({ BULLET_IMAGE_WIDTH,BULLET_IMAGE_HEIGHT })
{
	hImage_ = LoadGraph(BULLET_IMAGE_PATH.c_str()); //�e�̉摜��ǂݍ��� c_str = ���̔z��Ƃ���string�����Ă���
	speed_ = BULLET_INIT_SPEED; //�ړ����x	
	AddGameObject(this);
}

Bullet::~Bullet()
{
	if (hImage_ != 1)
	{
		DeleteGraph(hImage_); //�摜�̉��
	}
	hImage_ = -1; //�摜�n���h���𖳌���
}

void Bullet::Update()
{
	float dt = GetDeltaTime();
	y_ = y_ - speed_ * dt; //�e�̈ړ�
	if (y_ < 0)
	{
		isFired_ = false; //��ʊO�ɂł��珀����Ԃɖ߂�
	}
}

void Bullet::Draw()
{
	//���˂���Ă�����`��
	if (isFired_)
	{
		DrawExtendGraphF(x_, y_, x_ + imageSize_.x, y_ + imageSize_.y,
			hImage_, TRUE);//�e�̕`��
	}
}

void Bullet::SetPos(float x, float y)
{
	x_ = x;
	y_ = y;
}