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
	int animation[11];    //アニメーション画像
	int animation_count;    //アニメーション時間
	int flip_flag;            //反転フラフ
	Vector2D velocity;    //進行情報取得
	int enemy_type[4];
	bool IsHit;
	int sound[2];

public:
	Enemy();
	~Enemy();

	virtual void Initialize() override;   //初期化処理
	virtual void Update() override;    //更新処理
	virtual void Draw() const override;  //描画処理
	virtual void Finalize() override;   //終了時処理

	//当たり判定通知処理
	virtual void OnHitCollision(GameObject* hit_object)override;

	virtual bool DeleteCheck() override;

private:
	//移動処理
	void Movement();
	//アニメーション制御
	void AnimeControl();
};
