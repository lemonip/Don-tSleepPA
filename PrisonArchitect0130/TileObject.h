#pragma once
enum class TILETERRAIN;
enum class TILEWALL;
enum class TILEOBJECT;
enum class OBJECTTYPE;
enum class DIRECTION;
enum class OBJECTSTATE;

class TileObject
{
private:

public:
	TileObject(TILETERRAIN type);
	TileObject(TILEWALL type);
	TileObject(TILEOBJECT type);
	~TileObject() {}

	OBJECTTYPE _type;			//타입
	OBJECTSTATE _state;			//상태

	TILETERRAIN _terrainType;	//지형 타입
	TILEWALL	_wallType;		//벽 타입
	TILEOBJECT	_objType;		//오브젝트 타입

	string		_key;			//키 (이미지 파일이름)
	string		_name;			//이름
	string		_tag;			//태그
	int			_price;			//가격

	Image*		_img;			//이미지

	Vector2		_startIndex;	//시작 인덱스
	Vector2		_count;			//x, y로 차지하는 칸

	int			_frame[4];		//프레임 인덱스
	vector<int> _vUsable;		//사용 가능한 인덱스
	vector<int> _vUsing;		//사용 중인 인덱스

	DIRECTION _direction;		//방향
	

public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

};

