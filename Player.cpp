#include "Player.h"
#include "DxLib.h"
#include "global.h"
#include "Input.h"
#include "Bullet.h"
namespace
{
	const float PLAYER_INIT_SPEED = 200.0f; //�����ړ����x
	const int PLAYER_IMAGE_WIDTH  = 48;
	const int PLAYER_IMAGE_HEIGHT = 48;
	const int PLAYER_BASE_MARSIN = 32; //�v���C���[�̊�}�[�W��
	const float PLAYER_INIT_X = WIN_WIDTH / 2 - PLAYER_IMAGE_WIDTH / 2;
	const float PLAYER_INIT_Y = WIN_HEIGHT - PLAYER_IMAGE_HEIGHT - PLAYER_BASE_MARSIN;
	const int BULLET_IMAGE_MARZIN = 17; //�e�̉摜�̃}�[�W��
	// PW/ 2 - BW / 2 = BULLET_IMAGE_MARZIN
	const float BULLET_INTERVAL = 0.5f; //�e�̔��ˊԊu
}


Player::Player()
	:GameObject(), hImage_(-1), x_(0), y_(0), speed_(0)
{
	hImage_ = LoadGraph("Aseets/tiny_ship5.png");
	if (hImage_ == -1)
		 //�G���[���N�������ɔ������鏈��
	{

	}
	x_ = PLAYER_INIT_X;//�������W
	y_ = PLAYER_INIT_Y;
	speed_ = PLAYER_INIT_SPEED;
	AddGameObject(this);
}

Player::~Player()
{
	//�摜�T�C�Y�����(��ŏ���)
}

void Player::Update()
{
	float dt = GetDeltaTime(); //�t���[���Ԃ̎��ԍ����擾
	if (Input::IsKeepKeyDown(KEY_INPUT_LEFT))
	{
		x_ = x_ - speed_ * dt;
		
	}
	if (Input::IsKeepKeyDown(KEY_INPUT_RIGHT))
	{
		x_ = x_ + speed_  * dt;
	}
	static float bulletTimer = 0.0f; //�e�̔��˃^�C�}�[
	
	if (bulletTimer > 0.0f)
	{
		bulletTimer -= dt;
	}
	if (Input::IsKeyDown(KEY_INPUT_SPACE)) 
	{
		if (bulletTimer <= 0.0f)
		{
			new Bullet(x_ + BULLET_IMAGE_MARZIN, y_); //�e�𔭎�
			bulletTimer = BULLET_INTERVAL; //�e�̔��ˊԊu�����Z�b�g
		}
	}
		
}

void Player::Draw()
{
	//�v���C���[�̉摜��`��(�摜�̌��_�͍���)
	DrawExtendGraph(x_, y_, x_ + PLAYER_IMAGE_WIDTH, y_ + PLAYER_IMAGE_HEIGHT,
		            hImage_, TRUE);
}
