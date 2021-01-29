#include "stdafx.h"
#include "playGround.h"


void playGround::AddSource()
{
	//이미지 추가
	AddImage();
}

void playGround::AddImage()
{
	//png 이미지
	wstring path = L"source/image/";
	wstring filter = L".png";

	//tileset
	wstring folder = L"tileset/";
	ImageManager::GetInstance()->AddFrameImage("terrain", path + folder + L"terrain" + filter, 10, 20);

	//wall
	folder = L"tileset/wall/";
	for (int i = 0; i < (int)TILEWALL::END; i++)
	{
		string key1 = "wall" + to_string(i);
		wstring key2 = L"wall" + to_wstring(i);
		ImageManager::GetInstance()->AddFrameImage(key1, path + folder + key2 + filter, 7, 4);
	}

	//tileObject
	folder = L"tileset/tileObject/";
	ImageManager::GetInstance()->AddFrameImage("가스레인지", path + folder + L"가스레인지" + filter, 3, 1);
	ImageManager::GetInstance()->AddFrameImage("배식대", path + folder + L"배식대" + filter, 3, 1);
	ImageManager::GetInstance()->AddFrameImage("벤치", path + folder + L"벤치" + filter, 3, 1);
	ImageManager::GetInstance()->AddFrameImage("변기", path + folder + L"변기" + filter, 3, 1);
	ImageManager::GetInstance()->AddFrameImage("사무실책상", path + folder + L"사무실책상" + filter, 3, 1);
	ImageManager::GetInstance()->AddFrameImage("서류보관함", path + folder + L"서류보관함" + filter, 3, 1);
	ImageManager::GetInstance()->AddFrameImage("쇼파", path + folder + L"쇼파" + filter, 3, 1);
	ImageManager::GetInstance()->AddFrameImage("식탁", path + folder + L"식탁" + filter, 3, 1);
	ImageManager::GetInstance()->AddFrameImage("싱크대", path + folder + L"싱크대" + filter, 3, 1);
	ImageManager::GetInstance()->AddFrameImage("의자", path + folder + L"의자" + filter, 3, 1);
	ImageManager::GetInstance()->AddFrameImage("이중철창문", path + folder + L"이중철창문" + filter, 3, 1);
	ImageManager::GetInstance()->AddFrameImage("자판기", path + folder + L"자판기" + filter, 3, 1);
	ImageManager::GetInstance()->AddFrameImage("직원문", path + folder + L"직원문" + filter, 3, 1);
	ImageManager::GetInstance()->AddImage("창문", path + folder + L"창문" + filter);
	ImageManager::GetInstance()->AddFrameImage("철창문", path + folder + L"철창문" + filter, 3, 1);
	ImageManager::GetInstance()->AddFrameImage("침대", path + folder + L"침대" + filter, 3, 1);
	ImageManager::GetInstance()->AddImage("하수구", path + folder + L"하수구" + filter);
	
	// UI
	folder = L"ui/";

	ImageManager::GetInstance()->AddImage("clock", path + folder + L"clock" + filter);
	ImageManager::GetInstance()->AddImage("codex", path + folder + L"codex" + filter);
	ImageManager::GetInstance()->AddFrameImage("buttonBlue", path + folder + L"buttonBlue" + filter, 7, 1);
	ImageManager::GetInstance()->AddImage("screenEdge", path + folder + L"screenEdge" + filter);
	
	//사람
	folder = L"character/";
	
	ImageManager::GetInstance()->AddFrameImage("accountant", path + folder + L"accountant" + filter, 4, 1);

	ImageManager::GetInstance()->AddImage("hand", path + folder + L"hand" + filter);
	ImageManager::GetInstance()->AddFrameImage("bod0", path + folder + L"bod0" + filter, 4, 1);
	ImageManager::GetInstance()->AddFrameImage("head0", path + folder + L"head0" + filter, 4, 1);
	



	/*
	char imgNameTemp[256];
	//l이 뭐지..?
	for (int i = 0; i < 4; i++)
	{
		sprintf_s(imgNameTemp, "bod%d", i);
		ImageManager::GetInstance()->AddFrameImage(imgNameTemp, path + folder + L"buttonBlue" + filter, 4, 1);

	}*/

}
