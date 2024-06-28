#pragma once
#include"../GameObject.h"

class Player_Bullet : public GameObject
{
private:
	int animation;
	Vector2D velocity;    //進行情報取得
	int image;
	bool IsHit;
	bool bom_count;

public:
	Player_Bullet();
	~Player_Bullet();

	virtual void Initialize() override;   //初期化処理
	virtual void Update() override;    //更新処理
	virtual void Draw() const override;  //描画処理
	virtual void Finalize() override;   //終了時処理

	//当たり判定通知処理
	virtual void OnHitCollision(GameObject* hit_object)override;

	virtual bool DeleteCheck() override;

private:

	void Movement(); //移動処理


};

