#pragma once
#include"../GameObject.h"

class Enemy_Bullet : public GameObject
{
private:
	int animation;
	 Vector2D velocity;    //進行情報取得
	 int image;

public:
	Enemy_Bullet();
	~Enemy_Bullet();

	virtual void Initialize() override;   //初期化処理
	virtual void Update() override;    //更新処理
	virtual void Draw() const override;  //描画処理
	virtual void Finalize() override;   //終了時処理

	


private:

	void Movement(); //移動処理

};

