#include "stdafx.h"
#include "playGround.h"
#include "MapToolScene.h"
#include "ComponentTest.h"
playGround::playGround()
{
}

playGround::~playGround()
{
}

//초기화 함수
HRESULT playGround::init()
{
	gameNode::init(true);

	// ============================ 디버그 용 ============================
	#include <iostream>
	#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
	using namespace std;
	// ==================================================================
	
	AddSource();

	//카메라 생성과 뷰포트 영역 설정

	//메인 맵툴 카메라
	CAMERAMANAGER->CreateCamera(FloatRect(0, 0, WINSIZEX, WINSIZEY));

	//UI 카메라
	CAMERAMANAGER->CreateCamera(FloatRect(0, 0, WINSIZEX, WINSIZEY));

	SCENEMANAGER->addScene("맵씬", new MapToolScene);
	SCENEMANAGER->addScene("컴포넌트씬", new ComponentTest);
	//SCENEMANAGER->changeScene("씬");
	SCENEMANAGER->changeScene("맵씬");

	//csv테스트
	_csv.read();
	return S_OK;
}

//메모리 해제
void playGround::release()
{

}

//연산
void playGround::update()
{
	gameNode::update();
	SCENEMANAGER->update();
	UIMANAGER->update();
}

//그리기 전용
void playGround::render()
{	
	D2DRenderer::GetInstance()->BeginRender(D2D1::ColorF::White);

	//씬을 렌더한다.
	{
		SCENEMANAGER->render();
		UIMANAGER->render();
	}
	
	//벡버퍼 렌더를 끝낸다.
	D2DRenderer::GetInstance()->EndRender();
}
