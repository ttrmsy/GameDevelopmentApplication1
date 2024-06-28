#include "Player_Bullet.h"
#include"DxLib.h"


Player_Bullet::Player_Bullet() : image(),IsHit()
{
	animation = LoadGraph("Resource/images/Bomb/Bomb.png");
}


Player_Bullet::~Player_Bullet()
{

}

void Player_Bullet::Initialize()
{
	velocity.y += 2.0;
	image = animation;

	radian = 4.7f;

	object = BomObject;
}

void Player_Bullet::Update()
{
	Movement();
}

//移動処理
void Player_Bullet::Movement()
{
	location.y += velocity.y;
}

//当たり判定通知処理
void Player_Bullet::OnHitCollision(GameObject* hit_object)
{
	if (hit_object->GetType() == EnemyObject)
	{
		//当たった時の処理
		location = 0.0f;
		IsHit = TRUE;
	}
}

bool Player_Bullet::DeleteCheck()
{
	bool ret = FALSE;
	if (location.y > 640.0f + box_size.x || IsHit == TRUE)
	{
		ret = TRUE;
	}

	return ret;
}

void Player_Bullet::Draw() const
{
	//ボム画像の描画
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

void Player_Bullet::Finalize()
{
	DeleteGraph(animation);
}
