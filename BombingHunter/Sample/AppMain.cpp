#include "DxLib.h"
#include "Utility/InputControl.h"
#include "Scene/Scene.h"

//���C���֐��y�v���O�����͂�������n�܂�܂��B�z
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	//window���[�h�ŋN��
	ChangeWindowMode(TRUE);

	//�E�B���h�E�T�C�Y�i��: 640px,�c�F480px�j��ݒ�
	SetGraphMode(640, 480, 32);

	//DX���C�u�����̏�����
	if (DxLib_Init() == -1)
	{
		//�ُ��ʒm
		return -1;
	}


	//���[�J���ϐ���`
	Scene* scene = new Scene();   //�V�[�����
	int result = 0;     //�I����ԏ��

	//�`���𗠉�ʂ���n�߂�悤�Ɏw�肷��
	SetDrawScreen(DX_SCREEN_BACK);

	try
	{
		//�V�[���̏�����
		scene->Initialize();

		//���C�����[�v(�E�B���h�E�ُ̈픭��orESC�L�[�������ꂽ��A���[�v�I��)
		while (ProcessMessage() != -1 && CheckHitKey(KEY_INPUT_ESCAPE) !=
			TRUE)
		{
			//���͋@�\�̍X�V
			InputControl::Update();

			//�V�[���̍X�V����
			scene->Update();

			//��ʂ̏�����
			ClearDrawScreen();

			//�V�[���̕`�揈��
			scene->Draw();

			//����ʂ̓��e��\��ʂɔ��f����
			ScreenFlip();
		}
	}
	catch (const char* error_log)
	{
		//�G���[����log.txt�ɏo�͂���
		OutputDebugString(error_log);
			//�ُ��ԂɕύX����
			result = -1;
	}

	//�V�[�����̍폜����
	if (scene != nullptr)
	{
		scene->Finalize();
		delete scene;
		scene = nullptr;
	}

	//DX���C�u�����̏I��������
	DxLib_End();

	//�I����Ԃ�ʒm
	return result;
}