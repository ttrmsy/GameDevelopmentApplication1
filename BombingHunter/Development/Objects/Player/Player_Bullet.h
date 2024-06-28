#pragma once
#include"../GameObject.h"

class Player_Bullet : public GameObject
{
private:
	int animation;
	Vector2D velocity;    //�i�s���擾
	int image;
	bool IsHit;
	bool bom_count;

public:
	Player_Bullet();
	~Player_Bullet();

	virtual void Initialize() override;   //����������
	virtual void Update() override;    //�X�V����
	virtual void Draw() const override;  //�`�揈��
	virtual void Finalize() override;   //�I��������

	//�����蔻��ʒm����
	virtual void OnHitCollision(GameObject* hit_object)override;

	virtual bool DeleteCheck() override;

private:

	void Movement(); //�ړ�����


};

