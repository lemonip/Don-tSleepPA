#pragma once

enum class OBJECTTYPE;
enum class MOUSEDRAG;
enum class MOUSESTATE;

class TileMap;

class MouseControl
{
public:
	static MouseControl* GetInstance()
	{
		static MouseControl istance;
		return &istance;
	}
public:

	//마우스 관련 변수

	MOUSESTATE _state;					//마우스 스테이트

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

public:

	void Init();
	void Release();
	void Update();
	void Render();
	
	void Control();
	void Move();

	void LinkTileMap(TileMap* tileMap) { _tileMap = tileMap; }


	template<typename T>
	void OnCollisionEnter(T* obj);

	template<typename T>
	void OnCollisionExit(T* obj);

	template<typename T>
	void OnCollisionStay(T* obj);

};
