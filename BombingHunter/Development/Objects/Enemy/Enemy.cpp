#include "Enemy.h"
#include "../../Utility/InputControl.h"
#include "DxLib.h"
#include "random"

//�R���X�g���N�^
Enemy::Enemy() :animation_count(0), flip_flag(FALSE),IsHit(FALSE)
{
	for (int i = 0; i < 11; i++)
	{
		animation[i] = NULL;
	}


	for (int i = 0; i < 4; i++)
	{
		enemy_type[i] = 5;
	}

}

//�f�X�g���N�^
Enemy::~Enemy()
{
	//�Y��h�~
	Finalize();

}

//����������
void Enemy::Initialize()
{
	
	int rand_count = GetRand(100);

	if (rand_count <= 50)
	{
			rand_count = HANE;	
	}
	else if (rand_count <= 70)
	{
			rand_count = HARPY;	
	}
	else if (rand_count <= 95)
	{
			rand_count = HAKO;
	}
	else
	{
			rand_count = GOLD;
	}

	if (enemy_type[rand_count] >= 0)
	{
			switch (rand_count)
			{

			case HARPY:
				animation[0] = LoadGraph("Resource/Images/Harpy/1.png");
				animation[1] = LoadGraph("Resource/Images/Harpy/2.png");

				enemy_type[HARPY]--;

				switch (GetRand(1))
				{
				case 0:
					location.y = 360;
					break;

				case 1:
					location.y = 480;
					break;

				default:
					break;
				}

				if (GetRand(1) == 0)
				{
					location.x = 928.0f;
					flip_flag = TRUE;
					if (GetRand(1) == 0)
					{
						velocity.x = -1.0f;
					}
					else
					{
						velocity.x = -1.5f;
					}
				}
				else
				{
					location.x = 32.0f;
					flip_flag = FALSE;
					if (GetRand(1) == 0)
					{
						velocity.x = 1.0f;
					}
					else
					{
						velocity.x = 1.5f;
					}

				}
				//�����摜�̐ݒ�
				image = animation[0];
				break;

			case HANE:

				animation[2] = LoadGraph("Resource/Images/WingEnemy/1.png");
				animation[3] = LoadGraph("Resource/Images/WingEnemy/2.png");

				enemy_type[HANE]--;

				switch (GetRand(2))
				{
				case 0:
					location.y = 240;
					break;

				case 1:
					location.y = 360;
					break;

				case 2:
					location.y = 480;
					break;

				default:
					break;
				}

				if (GetRand(1) == 0)
				{
					location.x = 928.0f;
					flip_flag = TRUE;
					if (GetRand(4) == 0)
					{
						velocity.x = -1.0f;
					}
					else if (GetRand(4) == 1)
					{
						velocity.x = -2.0f;
					}
					else if (GetRand(4) == 2)
					{
						velocity.x = -3.0f;
					}
					else if (GetRand(4) == 3)
					{
						velocity.x = -4.0f;
					}
					else
					{
						velocity.x = -5.0f;
					}
				}
				else
				{
					location.x = 32.0f;
					flip_flag = FALSE;
					if (GetRand(4) == 0)
					{
						velocity.x = 1.0f;
					}
					else if (GetRand(4) == 1)
					{
						velocity.x = 2.0f;
					}
					else if (GetRand(4) == 2)
					{
						velocity.x = 3.0f;
					}
					else if (GetRand(4) == 3)
					{
						velocity.x = 4.0f;
					}
					else
					{
						velocity.x = 5.0f;
					}
				}
				//�����摜�̐ݒ�
				image = animation[2];
				break;

			case HAKO:

				animation[4] = LoadGraph("Resource/Images/BoxEnemy/1.png");
				animation[5] = LoadGraph("Resource/Images/BoxEnemy/2.png");

				enemy_type[HAKO]--;
				location.y = 600;

				if (GetRand(1) == 0)
				{
					location.x = 928.0f;
					flip_flag = TRUE;
					if (GetRand(1) == 0)
					{		
						velocity.x = -2.0f;
					}
					else
					{
						velocity.x = -3.0f;
					}
				}
				else
				{
					location.x = 32.0f;
					flip_flag = FALSE;
					if (GetRand(1) == 0)
					{
						velocity.x = 2.0f;
					}
					else
					{
						velocity.x = 3.0f;
					}
				}

				//�����摜�̐ݒ�
				image = animation[4];
				break;

				object = HAKO;

			case GOLD:

				animation[6] = LoadGraph("Resource/Images/GoldEnemy/1.png");
				animation[7] = LoadGraph("Resource/Images/GoldEnemy/2.png");
				animation[8] = LoadGraph("Resource/Images/GoldEnemy/3.png");
				animation[9] = LoadGraph("Resource/Images/GoldEnemy/4.png");
				animation[10] = LoadGraph("Resource/Images/GoldEnemy/5.png");

				enemy_type[GOLD]--;
				location.y = 600;

				if (GetRand(1) == 0)
				{
					location.x = 928.0f;
					flip_flag = TRUE;
					velocity.x = -4.0f;
				}
				else
				{
					location.x = 32.0f;
					flip_flag = FALSE;
					velocity.x = 4.0f;

				}

				//�����摜�̐ݒ�
				image = animation[6];
				break;

			default:
				break;

			}
		
		}
		

		//�G���[�`�F�b�N
		if (animation[0] == -1 || animation[1] == -1)
		{
			throw ("Enemy�̉摜������܂���\n");

		}

		velocity.y = 0.0f;

		//�����̐ݒ�
		radian = 0.0f;

		//�����蔻��̑傫����ݒ�
		scale = 64.0f;
}

//�X�V����
void Enemy::Update()
{
	//�ړ�����
	Movement();
	//�A�j���[�V��������
	AnimeControl();

}

//�`�揈��
void Enemy::Draw()const
{

	//Enemy�摜�̕`��
	DrawRotaGraphF(location.x, location.y, 1.0, radian, image, TRUE, flip_flag);

	//�f�o�b�N�p
#if _DEBUG
	//�����蔻��̉���
	Vector2D a = location - ((float)scale / 2.0f);
	Vector2D b = location + ((float)scale / 2.0f);
	DrawBoxAA(a.x, a.y, b.x, b.y, GetColor(255, 0, 0), FALSE);
#endif

}

//�I��������
void Enemy::Finalize()
{
	//�g�p�����摜���J��
	for (int i = 0; i < 11; i++)
	{
		DeleteGraph(animation[i]);
	}

}

//�����蔻��ʒm����
void Enemy::OnHitCollision(GameObject* hit_object)
{
	if (hit_object->GetType() == BomObject)
	{
		//�����������̏���
		location = 0.0f;
		IsHit = TRUE;
	}
}

bool Enemy::DeleteCheck()
{
	bool ret = FALSE;
	if (location.x > 960.0f + box_size.x || location.x < 0.0f - box_size.x || IsHit == TRUE)
	{
		ret = TRUE;
	}

	return ret;
}
//�ړ�����
void Enemy::Movement()
{	
	location.x += velocity.x;
}

//�A�j���[�V��������
void Enemy::AnimeControl()
{
	//�t���[���J�E���g�����Z����
	animation_count += 1;

	//60�t���[���ڂɓ��B������
	if (animation_count >= 60)
	{
		//�J�E���g�̃��Z�b�g
		animation_count = 0;

		//�摜�̐؂�ւ�
		if (image == animation[0])
		{
			image = animation[1];
		}
		else if(image ==animation[1])
		{
			image = animation[0];
		}

		if (image == animation[2])
		{
			image = animation[3];
		}
		else if(image == animation[3])
		{
			image = animation[2];
		}

		if (image == animation[4])
		{
			image = animation[5];
		}
		else if (image == animation[5])
		{
			image = animation[4];
		}

		if (image == animation[9])
		{
			image = animation[6];
		}
		else if (image == animation[6])
		{
			image = animation[7];
		}
		else if (image == animation[7])
		{
			image = animation[8];
		}
		else if (image == animation[8])
		{
			image = animation[9];
		}
		
	}
}

