#include "Bullet.h"
#include "DxLib.h"
#include <string>
#include "global.h"
#include "Player.h"
#include "GameObject.h"
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
	x_(0), y_(0), speed_(0),
	isize_x(BULLET_IMAGE_WIDTH), isize_y(BULLET_IMAGE_HEIGHT)
{
	hImage_ = LoadGraph(BULLET_IMAGE_PATH.c_str()); //�e�̉摜��ǂݍ��� c_str = ���̔z��Ƃ���string�����Ă���
	speed_ = BULLET_INIT_SPEED; //�ړ����x
	isAlive_ = true;
	AddGameObject(this);
}

Bullet::Bullet(float x, float y)
	:GameObject(), hImage_(-1),
	x_(x), y_(y), speed_(0),
	isize_x(BULLET_IMAGE_WIDTH), isize_y(BULLET_IMAGE_HEIGHT)
{
	hImage_ = LoadGraph(BULLET_IMAGE_PATH.c_str()); //�e�̉摜��ǂݍ��� c_str = ���̔z��Ƃ���string�����Ă���
	speed_ = BULLET_INIT_SPEED; //�ړ����x	
	isAlive_ = true; //�Q�[���I�u�W�F�N�g�������Ă��邩�ǂ���
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
	y_ = y_ - (speed_ * dt); //�e�̈ړ�
	if (y_ < 0)
	{
		isAlive_ = false; //��ʊO�ɂł���e������
	}
}

void Bullet::Draw()
{
	if (isAlive_)
	{
 		DrawExtendGraph(x_, y_, x_ + isize_x, y_ + isize_y, hImage_, TRUE);//�e�̕`��
	}
}

void Bullet::SetPos(float x, float y)
{
	x_ = x;
	y_ = y;
}
