#pragma once
#include "Mouse.h"

enum class OBJECTTYPE;
enum class MOUSEDRAG;
enum class MOUSESTATE;

class TileMap;
class MapToolScene;

class MapToolMouse : public Mouse
{
private:

	Vector2 _startPoint;				//시작 점
	Vector2 _startIndex;				//시작 인덱스

	Vector2 _endPoint;					//끝 점
	Vector2 _endIndex;					//끝 인덱스

	bool _isDragging;					//드래그 중인지
	MOUSEDRAG _drag;					//드래그 상태


	vector<Vector2> _vSelectIndex;		//선택 타일 인덱스
	TileObject* _mouseObj;				//마우스 타일 오브젝트
	TileArea* _mouseArea;				//마우스 지역
	TileMap* _tileMap;					//타일 맵
	MapToolScene* _scene;				//씬

public:
	MapToolMouse(MapToolScene* scene);
	~MapToolMouse() {};

	virtual void Init();
	virtual void Release();
	virtual void Update();
	virtual void Render();

	//마우스 컨트롤
	void Control();

	void UIControl();
	void BuildControl();
	void SelectControl();
	void ObjectControl();
	void TileObjectControl();


	template<typename T>
	void OnCollisionEnter(T* obj);

	template<typename T>
	void OnCollisionExit(T* obj);

	template<typename T>
	void OnCollisionStay(T* obj);


};

