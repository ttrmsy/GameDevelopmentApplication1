#include "GameObject.h"

//コンストラクタ
GameObject::GameObject() :
	location(0.0f),
	scale(0.0),
	radian(0.0),
	image(0),
	sound(0),
	object_type(),
	object()
{

}

//デストラクタ
GameObject::~GameObject()
{

}

//初期化処理
void GameObject::Initialize()
{
	
}

//更新処理
void GameObject::Update()
{

}

//描画処理
void GameObject::Draw() const
{

}

//終了時処理
void GameObject::Finalize()
{

}

bool GameObject::DeleteCheck()
{
	bool ret = false;
	return ret;
}

//当たり判定通知処理
void GameObject::OnHitCollision(GameObject* hit_object)
{
	//当たった時に行う処理

}

int GameObject::GetType()
{
	return object;


}


//位置情報取得処理
Vector2D GameObject::GetLocation() const
{
	return this->location;
}

//位置情報設定処理
void GameObject::SetLocation(const Vector2D& location)
{
	this->location = location;

}

Vector2D GameObject::GetBoxSize() const
{
	return this->scale;
}