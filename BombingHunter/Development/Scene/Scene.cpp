#include "Scene.h"

#include"../Objects/Player/Player.h"
#include"../Objects/Player/Player_Bullet.h"
#include"../Objects/Enemy/Enemy.h"
#include"../Utility/InputControl.h"
#include"DxLib.h"

#define D_PIVOT_CENTER


//コンストラクタ
Scene::Scene() :objects(),time(0),stage(),flame_count(0)
{

}

//デストラクタ
Scene::~Scene()
{

	//忘れ防止
	Finalize();

}

//初期化処理
void Scene::Initialize()
{
	//プレイヤーを生成する
	CreateObject<Player>(Vector2D(320.0f, 120.0f));
		 
	stage = LoadGraph("Resource/images/BackGround.png");

	time = 60;

}

//更新処理
void Scene::Update()
{

	//シーンに存在するオブジェクトの更新処理
	for (GameObject* obj : objects)
	{
		obj->Update();
	}
	
	//zキーを押したら、ボムを生成する
	if (InputControl::GetKeyDown(KEY_INPUT_Z))
	{

		CreateObject<Player_Bullet>(objects.at(0)->GetLocation());
	}

	//オブジェクト同士の当たり判定チェック
	for (int i = 0; i < objects.size(); i++)
	{
		for (int j = i + 1; j < objects.size(); j++)
		{

			//当たり判定チェック
			HitCheckObject(objects[i], objects[j]);

		}

	}
	//オブジェクト判定チェック
	for (int i = 0; i < objects.size(); i++)
	{
		if (objects[i]->GetLocation().x < 0)
		{
			objects.erase(objects.begin() + i);
		}
	}

	//当たった時の処理
	for (int i = 0; i < objects.size(); i++)
	{
		//判定チェック処理
		if (objects[i]->DeleteCheck() == TRUE)
		{
			objects.erase(objects.begin() + i);
		}
	}

	FlameControl();

}

//タイマー制御
void Scene::FlameControl()
{
	//フレームカウントを加算する
	flame_count += 1;

	//60フレーム目に到達したら
	if (flame_count >= 60)
	{
		//カウントのリセット
		flame_count = 0;

		//タイマーカウント
		time -= 1;

		CreateObject<Enemy>(Vector2D(32.0f, 540.0f));
		
		if (GetType() == HAKO)
		{
			CreateObject<Enemy_Bullet>(Vector2D(objects.at(HAKO)->GetLocation()));
		}
	}
}

//描画処理
void Scene::Draw() const
{
	DrawGraph(0, 0, stage, TRUE);

	//シーンに存在するオブジェクトの描画処理
	for (GameObject* obj : objects)
	{
		obj->Draw();
	}

}

//終了時処理
void Scene::Finalize()
{
	DeleteGraph(stage);

	//動画的配列がからなら処理をする
	if (objects.empty())
	{
		return;
	}

	//各オブジェクトを削除する
	for (GameObject* obj : objects)
	{
		obj->Finalize();
		delete  obj;
	}

	//動的配列の開放
	objects.clear();
}

#ifdef D_PIVOT_CENTER

//当たり判定チェック処理(矩形の中心で当たり判定を取る)
void Scene::HitCheckObject(GameObject* a, GameObject* b)
{
	//2つのオブジェクトの距離を取得
	Vector2D diff = a->GetLocation() - b->GetLocation();

	//2つのオブジェクトの当たり判定の大きさを取得
	Vector2D box_size = (a->GetBoxSize() + b->GetBoxSize()) / 2.0f;

	//距離より大きさが大きい場合、Hit判定とする
	if ((fabsf(diff.x) < box_size.x) && (fabsf(diff.y) < box_size.y))
	{
		//当たったことをオブジェトに通知する
		a->OnHitCollision(b);
		b->OnHitCollision(a);
	}
}
#else

//当たり判定チェック処理（左上頂点の座標から当たり判定計算を行う）
void Scene::HitCheckObject(GameObject* a, GameObject* b)
{
	//右下頂点座標を取得する
	Vector2D a_lower_right = a->GetLocation() + a->GetBoxSize();
	Vector2D a_lower_right = b->GetLocation() + b->GetBoxSize();

	//矩形Aと矩形Bの位置関係を調べる
	if ((a->GetLocation().x < b_lower_right.x) &&
		(a->GetLocation().y < b_lower_right.y) &&
		(a\loewr_right.x > b->Getlocation().x) &&
		(a\loewr_right.y > b->Getlocation().y))
	{
		//オブジェクトに対してHit判定を通知する
		a->OnHitCollision(b);
		b->OnHitCollision(a);
	}
}

#endif // D_PIVOT_CENTER


