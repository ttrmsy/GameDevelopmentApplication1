#pragma once

#define PlayerObject (0)
#define BomObject (1)
#define EnemyObject (2)
#define EnemyBullet (3)

#include "../Utility/Vector2D.h"

//�Q�[���I�u�W�F�N�g���N���X
class GameObject
{
protected:
	Vector2D location;   //�ʒu���
	Vector2D box_size;  //�傫��
	double scale;    //�傫��
	double radian;   //����
	int image;    //�`�悷��摜
	int sound;    //�Đ����鉹��
	int object;

public:
	GameObject();
	virtual ~GameObject();

	virtual void Initialize();   //����������
	virtual void Update();    //�X�V����
	virtual void Draw() const;  //�`�揈��
	virtual void Finalize();    //�I��������
	virtual int GetType();

	virtual bool DeleteCheck();

	int object_type[2];

	//�����蔻��ʒm����;
	virtual void OnHitCollision(GameObject* hit_object);

	//�ʒu���擾����
	Vector2D GetLocation() const;

	//�ʒu���ύX����
	void SetLocation(const Vector2D& location);

	//�����蔻��̑傫�����擾����
	Vector2D GetBoxSize() const;
};

