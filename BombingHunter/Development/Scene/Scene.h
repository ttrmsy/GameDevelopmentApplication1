#pragma once

#include <vector>
#include "../Objects/GameObject.h"
#include"DxLib.h"

class Scene : public GameObject 
{
private:
	std::vector<GameObject*> objects; //オブジェクトリスト
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
	//当たり判定チェック処理
	void HitCheckObject(GameObject* a, GameObject* b);
	//フレームカウント
	void FlameControl();

	template <class T>
	T* CreateObject(const Vector2D& location)
	{
		//指定したクラスを生成する
		T* new_instance = new T();
		//GameObjectクラスを継承しているか確認
		GameObject* new_object = dynamic_cast<GameObject*>(new_instance);

		//エラーチェック
		if (new_object == nullptr)
		{
			delete new_instance;
			throw ("ゲームオブジェクトが生成できませんでした");

		}

		//位置情報の設定
		new_object->SetLocation(location);
		//初期化処理
		new_object->Initialize();

		//オブジェクトに追加
		objects.push_back(new_object);

		//インスタンスのポインタを返却
		return new_instance;
	}
};

