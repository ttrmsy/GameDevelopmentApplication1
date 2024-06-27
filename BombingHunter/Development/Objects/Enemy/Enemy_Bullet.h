#pragma once
#include"../GameObject.h"

class Enemy_Bullet : public GameObject
{
private:
	int animation;
	 Vector2D velocity;    //�i�s���擾
	 int image;

public:
	Enemy_Bullet();
	~Enemy_Bullet();

	virtual void Initialize() override;   //����������
	virtual void Update() override;    //�X�V����
	virtual void Draw() const override;  //�`�揈��
	virtual void Finalize() override;   //�I��������

	


private:

	void Movement(); //�ړ�����

};

