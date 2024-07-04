#pragma once

#define HARPY (0)
#define HANE (1)
#define HAKO (2)
#define GOLD (3)

#include "../GameObject.h"
#include "random"
#include"Enemy_Bullet.h"

class Enemy :public GameObject
{
private:
	int animation[11];    //�A�j���[�V�����摜
	int animation_count;    //�A�j���[�V��������
	int flip_flag;            //���]�t���t
	Vector2D velocity;    //�i�s���擾
	int enemy_type[4];
	bool IsHit;
	int sound[2];

public:
	Enemy();
	~Enemy();

	virtual void Initialize() override;   //����������
	virtual void Update() override;    //�X�V����
	virtual void Draw() const override;  //�`�揈��
	virtual void Finalize() override;   //�I��������

	//�����蔻��ʒm����
	virtual void OnHitCollision(GameObject* hit_object)override;

	virtual bool DeleteCheck() override;

private:
	//�ړ�����
	void Movement();
	//�A�j���[�V��������
	void AnimeControl();
};
