#include "Enemy_Bullet.h"
#include"DxLib.h"

//コンストラクタ
Enemy_Bullet::Enemy_Bullet():image(0)
{
	animation = LoadGraph("Resource/images/EnemyBullet/1.png");
}

//デストラクタ
Enemy_Bullet::~Enemy_Bullet()
{
	Finalize();
}

//初期化処理
void Enemy_Bullet::Initialize()
{
	image = animation;
	object = EnemyBullet;

	velocity.x = -1.0;
	velocity.y = -1.0;
}

//更新処理
void Enemy_Bullet::Update()
{
	Movement();
}

//描画処理
void Enemy_Bullet::Draw ()const
{
	DrawRotaGraphF(location.x, location.y, 1.0, radian, image, TRUE, TRUE);
	//デバック用
#if _DEBUG
	//当たり判定の可視化
	Vector2D box_collision_upper_left = location - (Vector2D(1.0f) *
		(float)scale / 2.0f);
	Vector2D box_collision_lower_right = location + (Vector2D(1.0f) *
		(float)scale / 2.0f);
	DrawBoxAA(box_collision_upper_left.x, box_collision_upper_left.y,
		box_collision_lower_right.x, box_collision_lower_right.y,
		GetColor(255, 0, 0), TRUE
	);
#endif

}

//移動処理
void Enemy_Bullet:: Movement()
{
	location.x += velocity.x;
	location.y += velocity.y;
}


//終了時処理
void Enemy_Bullet::Finalize()
{
	DeleteGraph(animation);
}