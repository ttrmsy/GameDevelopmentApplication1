#include "Player_Bullet.h"
#include"DxLib.h"


Player_Bullet::Player_Bullet() : image(),IsHit(),sound()
{
	for (int i = 0; i < 2; i++)
	{
		sound[i] = NULL;
	}

	animation = LoadGraph("Resource/images/Bomb/Bomb.png");
	sound[0] = LoadSoundMem("Resource/Sounds/pan.wav");
	sound[1] = LoadSoundMem("Resource/Sounds/pokan.wav");
}


Player_Bullet::~Player_Bullet()
{

}

void Player_Bullet::Initialize()
{
	velocity.y += 2.0;
	image = animation;

	radian = -1.6f;

	object = BomObject;


	PlaySoundMem(sound[0], DX_PLAYTYPE_BACK);
}

void Player_Bullet::Update()
{
	Movement();
}

//�ړ�����
void Player_Bullet::Movement()
{
	location.y += velocity.y;
}

//�����蔻��ʒm����
void Player_Bullet::OnHitCollision(GameObject* hit_object)
{
	if (hit_object->GetType() == EnemyObject)
	{
		//�����������̏���
		location = 0.0f;
		IsHit = TRUE;
		PlaySoundMem(sound[1], DX_PLAYTYPE_BACK);

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
	//�{���摜�̕`��
	DrawRotaGraphF(location.x, location.y, 1.0, radian, image, TRUE, TRUE);
	//�f�o�b�N�p
#if _DEBUG
	//�����蔻��̉���
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
