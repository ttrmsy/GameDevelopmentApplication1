#pragma once

#include <vector>
#include "../Objects/GameObject.h"
#include"DxLib.h"

class Scene : public GameObject 
{
private:
	std::vector<GameObject*> objects; //�I�u�W�F�N�g���X�g
	int stage;

public:
	Scene();
	~Scene();

	void Initialize();
	void Update();
	void Draw() const;
	void Finalize();
	bool GetBomCount();
	int time;
	int flame_count;
	bool bom_count;

private:
	//�����蔻��`�F�b�N����
	void HitCheckObject(GameObject* a, GameObject* b);
	//�t���[���J�E���g
	void FlameControl();

	template <class T>
	T* CreateObject(const Vector2D& location)
	{
		//�w�肵���N���X�𐶐�����
		T* new_instance = new T();
		//GameObject�N���X���p�����Ă��邩�m�F
		GameObject* new_object = dynamic_cast<GameObject*>(new_instance);

		//�G���[�`�F�b�N
		if (new_object == nullptr)
		{
			delete new_instance;
			throw ("�Q�[���I�u�W�F�N�g�������ł��܂���ł���");

		}

		//�ʒu���̐ݒ�
		new_object->SetLocation(location);
		//����������
		new_object->Initialize();

		//�I�u�W�F�N�g�ɒǉ�
		objects.push_back(new_object);

		//�C���X�^���X�̃|�C���^��ԋp
		return new_instance;
	}
};

