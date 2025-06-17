#include "Enemys.h"
#include "DxLib.h"
#include <string>
#include "Effect.h"
#include "EnemyBeam.h"
#include "Bullet.h"
namespace
{
	const int ENEMY_IMAGE_WIDTH = 48;
	const int ENEMY_IMAGE_HEIGHT = 48;
	const int ENEMY_INIT_X = 100;
	const int ENEMY_INIT_Y = 100;
	const float ENEMY_INIT_SPEED = 100.0f;
	const int ENEMY_BULLET_NUM = 100;
}


Enemys::Enemys()
	:GameObject(), hImage_(-1), x_(0), y_(0), speed_(0),
	imageSize_({ ENEMY_IMAGE_WIDTH,ENEMY_IMAGE_HEIGHT })
{
	hImage_ = LoadGraph("Aseets//tiny_ship10.png");
	if (hImage_ == -1)
	{

	}
	x_ = ENEMY_INIT_X; //�������W
	y_ = ENEMY_INIT_Y;//�������W
	speed_ = ENEMY_INIT_SPEED;//�������x
}
Enemys::Enemys(int id, ETYPE type)
	:GameObject(),
	hImage_(-1),
	x_(0), y_(0),
	speed_(0),
	ID_(id), type_(type), imageSize_({ ENEMY_IMAGE_WIDTH, ENEMY_IMAGE_HEIGHT })


{

	//ETYPE::ZAKO =>  "Assets/tiny_ship10.png"
	//ETYPE::MID = > "Assets/tiny_ship18.png"
	//ETYPE::KNIGHT = > "Assets/tiny_ship16.png"
	//ETYPE::BOSS = > "Assets/tiny_ship9.png"
	// �摜�̓ǂݍ���
	std::string imagePath[MAX_ETYPE] = {
		"Aseets//tiny_ship10.png", // ZAKO
		"Aseets//tiny_ship18.png", // MID
		"Aseets//tiny_ship16.png", // KNIGHT
		"Aseets//tiny_ship9.png"   // BOSS
	};
	moveTime_ = 0.0f;
	hImage_ = LoadGraph(imagePath[type_].c_str()); // �G�̉摜��ǂݍ���
	if (hImage_ == -1) {
		// �摜�̓ǂݍ��݂Ɏ��s�����ꍇ�̃G���[�n���h�����O
		// �G���[��Ԃ��ăQ�[���I��
	}
	x_ = ENEMY_INIT_X; // �������W
	y_ = ENEMY_INIT_Y; // �������W
	speed_ = ENEMY_INIT_SPEED; // �ړ����x
	AddGameObject(this); // �G�I�u�W�F�N�g���Q�[���I�u�W�F�N�g�̃x�N�^�[�ɒǉ�
}



Enemys::~Enemys()
{
	new Effect({ x_,y_ });
	if (hImage_ != -1)
	{
		DeleteGraph(hImage_);//�摜�̃n���h�������
	}
}

void Enemys::Update()
{

	static float beamTimer = 3.0f;

	float period = 10.0f;
	float omega = 2.0f * 3.14159265f / period;
	moveTime_ = moveTime_ + GetDeltaTime();
	x_ = xorigin_ + xMoveMax_ / 2.0 * sinf(omega * moveTime_ );
	y_ = y_;
	if (beamTimer < 0)
	{
		new EnemyBeam(x_ + ENEMY_IMAGE_WIDTH / 2, y_ + ENEMY_IMAGE_HEIGHT);
		beamTimer = 3.0f;
	}
	beamTimer -= GetDeltaTime();
}

void Enemys::Draw()
{
	DrawExtendGraphF(x_, y_,
		x_ + ENEMY_IMAGE_WIDTH, y_ + ENEMY_IMAGE_HEIGHT,
		hImage_, TRUE);
}

