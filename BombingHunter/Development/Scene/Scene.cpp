#include "Scene.h"

#include"../Objects/Player/Player.h"
#include"../Objects/Player/Player_Bullet.h"
#include"../Objects/Enemy/Enemy.h"
#include"../Utility/InputControl.h"
#include"DxLib.h"

#define D_PIVOT_CENTER


//�R���X�g���N�^
Scene::Scene() :objects(),time(0),stage(),flame_count(0)
{

}

//�f�X�g���N�^
Scene::~Scene()
{

	//�Y��h�~
	Finalize();

}

//����������
void Scene::Initialize()
{
	//�v���C���[�𐶐�����
	CreateObject<Player>(Vector2D(320.0f, 120.0f));
		 
	stage = LoadGraph("Resource/images/BackGround.png");

	time = 60;

}

//�X�V����
void Scene::Update()
{

	//�V�[���ɑ��݂���I�u�W�F�N�g�̍X�V����
	for (GameObject* obj : objects)
	{
		obj->Update();
	}
	
	//z�L�[����������A�{���𐶐�����
	if (InputControl::GetKeyDown(KEY_INPUT_Z))
	{

		CreateObject<Player_Bullet>(objects.at(0)->GetLocation());
	}

	//�I�u�W�F�N�g���m�̓����蔻��`�F�b�N
	for (int i = 0; i < objects.size(); i++)
	{
		for (int j = i + 1; j < objects.size(); j++)
		{

			//�����蔻��`�F�b�N
			HitCheckObject(objects[i], objects[j]);

		}

	}
	//�I�u�W�F�N�g����`�F�b�N
	for (int i = 0; i < objects.size(); i++)
	{
		if (objects[i]->GetLocation().x < 0)
		{
			objects.erase(objects.begin() + i);
		}
	}

	//�����������̏���
	for (int i = 0; i < objects.size(); i++)
	{
		//����`�F�b�N����
		if (objects[i]->DeleteCheck() == TRUE)
		{
			objects.erase(objects.begin() + i);
		}
	}

	FlameControl();

}

//�^�C�}�[����
void Scene::FlameControl()
{
	//�t���[���J�E���g�����Z����
	flame_count += 1;

	//60�t���[���ڂɓ��B������
	if (flame_count >= 60)
	{
		//�J�E���g�̃��Z�b�g
		flame_count = 0;

		//�^�C�}�[�J�E���g
		time -= 1;

		CreateObject<Enemy>(Vector2D(32.0f, 540.0f));
		
		if (GetType() == HAKO)
		{
			CreateObject<Enemy_Bullet>(Vector2D(objects.at(HAKO)->GetLocation()));
		}
	}
}

//�`�揈��
void Scene::Draw() const
{
	DrawGraph(0, 0, stage, TRUE);

	//�V�[���ɑ��݂���I�u�W�F�N�g�̕`�揈��
	for (GameObject* obj : objects)
	{
		obj->Draw();
	}

}

//�I��������
void Scene::Finalize()
{
	DeleteGraph(stage);

	//����I�z�񂪂���Ȃ珈��������
	if (objects.empty())
	{
		return;
	}

	//�e�I�u�W�F�N�g���폜����
	for (GameObject* obj : objects)
	{
		obj->Finalize();
		delete  obj;
	}

	//���I�z��̊J��
	objects.clear();
}

#ifdef D_PIVOT_CENTER

//�����蔻��`�F�b�N����(��`�̒��S�œ����蔻������)
void Scene::HitCheckObject(GameObject* a, GameObject* b)
{
	//2�̃I�u�W�F�N�g�̋������擾
	Vector2D diff = a->GetLocation() - b->GetLocation();

	//2�̃I�u�W�F�N�g�̓����蔻��̑傫�����擾
	Vector2D box_size = (a->GetBoxSize() + b->GetBoxSize()) / 2.0f;

	//�������傫�����傫���ꍇ�AHit����Ƃ���
	if ((fabsf(diff.x) < box_size.x) && (fabsf(diff.y) < box_size.y))
	{
		//�����������Ƃ��I�u�W�F�g�ɒʒm����
		a->OnHitCollision(b);
		b->OnHitCollision(a);
	}
}
#else

//�����蔻��`�F�b�N�����i���㒸�_�̍��W���瓖���蔻��v�Z���s���j
void Scene::HitCheckObject(GameObject* a, GameObject* b)
{
	//�E�����_���W���擾����
	Vector2D a_lower_right = a->GetLocation() + a->GetBoxSize();
	Vector2D a_lower_right = b->GetLocation() + b->GetBoxSize();

	//��`A�Ƌ�`B�̈ʒu�֌W�𒲂ׂ�
	if ((a->GetLocation().x < b_lower_right.x) &&
		(a->GetLocation().y < b_lower_right.y) &&
		(a\loewr_right.x > b->Getlocation().x) &&
		(a\loewr_right.y > b->Getlocation().y))
	{
		//�I�u�W�F�N�g�ɑ΂���Hit�����ʒm����
		a->OnHitCollision(b);
		b->OnHitCollision(a);
	}
}

#endif // D_PIVOT_CENTER


