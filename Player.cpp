#include "Player.h"
#include "DxLib.h"
#include "global.h"
#include "Input.h"
#include "Bullet.h"
namespace
{
	const float PLAYER_INIT_SPEED = 200.0f; //初期移動速度
	const int PLAYER_IMAGE_WIDTH  = 48;
	const int PLAYER_IMAGE_HEIGHT = 48;
	const int PLAYER_BASE_MARSIN = 32; //プレイヤーの基準マージン
	const float PLAYER_INIT_X = WIN_WIDTH / 2 - PLAYER_IMAGE_WIDTH / 2;
	const float PLAYER_INIT_Y = WIN_HEIGHT - PLAYER_IMAGE_HEIGHT - PLAYER_BASE_MARSIN;
	const int BULLET_IMAGE_MARZIN = 17; //弾の画像のマージン
	// PW/ 2 - BW / 2 = BULLET_IMAGE_MARZIN
	const float BULLET_INTERVAL = 0.5f; //弾の発射間隔
}


Player::Player()
	:GameObject(), hImage_(-1), x_(0), y_(0), speed_(0)
{
	hImage_ = LoadGraph("Aseets/tiny_ship5.png");
	if (hImage_ == -1)
		 //エラーが起きた時に発生する処理
	{

	}
	x_ = PLAYER_INIT_X;//初期座標
	y_ = PLAYER_INIT_Y;
	speed_ = PLAYER_INIT_SPEED;
	AddGameObject(this);
}

Player::~Player()
{
	//画像サイズを解放(後で書く)
}

void Player::Update()
{
	float dt = GetDeltaTime(); //フレーム間の時間差を取得
	if (Input::IsKeepKeyDown(KEY_INPUT_LEFT))
	{
		x_ = x_ - speed_ * dt;
		
	}
	if (Input::IsKeepKeyDown(KEY_INPUT_RIGHT))
	{
		x_ = x_ + speed_  * dt;
	}
	static float bulletTimer = 0.0f; //弾の発射タイマー
	
	if (bulletTimer > 0.0f)
	{
		bulletTimer -= dt;
	}
	if (Input::IsKeyDown(KEY_INPUT_SPACE)) 
	{
		if (bulletTimer <= 0.0f)
		{
			new Bullet(x_ + BULLET_IMAGE_MARZIN, y_); //弾を発射
			bulletTimer = BULLET_INTERVAL; //弾の発射間隔をリセット
		}
	}
		
}

void Player::Draw()
{
	//プレイヤーの画像を描画(画像の原点は左上)
	DrawExtendGraph(x_, y_, x_ + PLAYER_IMAGE_WIDTH, y_ + PLAYER_IMAGE_HEIGHT,
		            hImage_, TRUE);
}
