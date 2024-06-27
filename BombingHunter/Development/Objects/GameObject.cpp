#include "GameObject.h"

//�R���X�g���N�^
GameObject::GameObject() :
	location(0.0f),
	scale(0.0),
	radian(0.0),
	image(0),
	sound(0)
{

}

//�f�X�g���N�^
GameObject::~GameObject()
{

}

//����������
void GameObject::Initialize()
{
	
}

//�X�V����
void GameObject::Update()
{

}

//�`�揈��
void GameObject::Draw() const
{

}

//�I��������
void GameObject::Finalize()
{

}

bool GameObject::DeleteCheck()
{
	bool ret = false;
	return ret;
}

//�����蔻��ʒm����
void GameObject::OnHitCollision(GameObject* hit_object)
{
	//�����������ɍs������

}

int GameObject::GetType()
{
	return object;


}

//�ʒu���擾����
Vector2D GameObject::GetLocation() const
{
	return this->location;
}

//�ʒu���ݒ菈��
void GameObject::SetLocation(const Vector2D& location)
{
	this->location = location;

}

Vector2D GameObject::GetBoxSize() const
{
	return this->scale;
}