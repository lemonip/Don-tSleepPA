#include "stdafx.h"
#include "TileMap.h"

HRESULT TileMap::init()
{
	return S_OK;
}

void TileMap::release()
{
}

void TileMap::update()
{


}

void TileMap::render()
{
	//바닥 렌더
	for (int i = 0; i < _tileCount; i++)
	{
		if (_vTile[i]->_terrain) _vTile[i]->_terrain->_img->FrameRender(Vector2(TILESIZE / 2 + TILESIZE * (i % (int)_count.x), TILESIZE / 2 + TILESIZE * (i / (int)_count.x)), 0, (int)_vTile[i]->_terrain->_terrainType * 2, CAMERAMANAGER->GetVCamera()[0]);
	}

	//벽 렌더
	for (int i = 0; i < _tileCount; i++)
	{
		if (_vTile[i]->_wall) _vTile[i]->_wall->_img->FrameRender(Vector2(TILESIZE / 2 + TILESIZE * (i % (int)_count.x), TILESIZE / 2 + TILESIZE * (i / (int)_count.x)), _vTile[i]->_wallIndex % 7, _vTile[i]->_wallIndex / 7, CAMERAMANAGER->GetVCamera()[0]);
	}

	//오브젝트 렌더
	for (int i = 0; i < _tileCount; i++)
	{
		//타일에 오브젝트가 있고, 마스터 타일이 렌더한다.
		if (_vTile[i]->_tileObj && _vTile[i]->_tileObj->_startIndex == Vector2(i % (int)_count.x, i / (int)_count.x))
		{
			if (_vTile[i]->_tileObj->_direction == DIRECTION::FRONT || _vTile[i]->_tileObj->_direction == DIRECTION::BACK)
			{
				_vTile[i]->_tileObj->_img->FrameRender(Vector2(TILESIZE * (i % (int)_count.x) + (_vTile[i]->_tileObj->_count.x*TILESIZE) / 2,
					TILESIZE / 2 + TILESIZE * (i / (int)_count.x) + (_vTile[i]->_tileObj->_count.y*TILESIZE) / 2 - _vTile[i]->_tileObj->_img->GetFrameSize().y / 2),
					_vTile[i]->_tileObj->_frame[(int)_vTile[i]->_tileObj->_direction], 0, CAMERAMANAGER->GetVCamera()[0]);

			}
			else if (_vTile[i]->_tileObj->_direction == DIRECTION::RIGHT || _vTile[i]->_tileObj->_direction == DIRECTION::LEFT)
			{
				//왼쪽 방향이면 가로로 뒤집어 준다.
				if (_vTile[i]->_tileObj->_direction == DIRECTION::LEFT) _vTile[i]->_tileObj->_img->SetReverseX(true);

				_vTile[i]->_tileObj->_img->FrameRender(Vector2(TILESIZE * (i % (int)_count.x) + (_vTile[i]->_tileObj->_count.y*TILESIZE) / 2,
					TILESIZE * (i / (int)_count.x) + (_vTile[i]->_tileObj->_count.x*TILESIZE) - _vTile[i]->_tileObj->_img->GetFrameSize().y / 2),
					_vTile[i]->_tileObj->_frame[(int)_vTile[i]->_tileObj->_direction], 0, CAMERAMANAGER->GetVCamera()[0]);
			}
		}
	}

}

void TileMap::SetTileMap(Vector2 count)
{
	//x, y 인덱스 개수를 정한다.
	_count = count;
	//타일 총 개수를 구한다.
	_tileCount = _count.x * _count.y;

	for (int i = 0; i < _tileCount; i++)
	{
		Tile* tile = new Tile;
		tile->_index = Vector2(i % (int)_count.x, i / (int)_count.x);

		_vTile.push_back(tile);

		BuildTileObject(Vector2(tile->_index.x, tile->_index.y), new TileObject(*DATAMANAGER->FindTileObject("GRASS1")));
		tile->_wall = NULL;
		tile->_tileObj = NULL;
	}
}

void TileMap::BuildTileObject(Vector2 index, TileObject * tileObj)
{
	switch (tileObj->_type)
	{
	case OBJECTTYPE::END:

		break;
	case OBJECTTYPE::TERRAIN:
	{
		//예외에 해당하면 만들지 않음.
		if (!CanBuildTile(index, tileObj)) return;

		//이전 타일의 메모리를 삭제하고 지형 타일을 바꿔 준다.
		if (_vTile[index.y * _count.x + index.x]->_terrain)
		{
			delete _vTile[index.y * _count.x + index.x]->_terrain;
			_vTile[index.y * _count.x + index.x]->_terrain = NULL;
		}
		_vTile[index.y * _count.x + index.x]->_terrain = tileObj;
	}
	break;
	case OBJECTTYPE::WALL:
	{
		//예외에 해당하면 만들지 않음.
		if (!CanBuildTile(index, tileObj)) return;

		//이미 벽이 있는데
		if (_vTile[index.y * _count.x + index.x]->_wall)
		{
			//타입이 다르다면 이전 타일의 메모리를 삭제한다.
			delete _vTile[index.y * _count.x + index.x]->_wall;
			_vTile[index.y * _count.x + index.x]->_wall = NULL;
		}

		//타일을 생성 해 준다.
		_vTile[index.y * _count.x + index.x]->_wall = tileObj;
		_vTile[index.y * _count.x + index.x]->_wallIndex = 22;
		_vTile[index.y * _count.x + index.x]->_wall->_startIndex = index;

		//주변 네 타일을 검사하고 프레임을 바꿔 준다.
		_vTile[index.y * _count.x + index.x]->_wallIndex = GetWallFrame(index, tileObj);

		//상
		if (_vTile[(index.y - 1) * _count.x + index.x]->_wall)
		{
			_vTile[(index.y - 1) * _count.x + index.x]->_wallIndex = GetWallFrame(Vector2(index.x, index.y - 1), tileObj);
		}
		//하
		if (_vTile[(index.y + 1) * _count.x + index.x]->_wall)
		{
			_vTile[(index.y + 1) * _count.x + index.x]->_wallIndex = GetWallFrame(Vector2(index.x, index.y + 1), tileObj);
		}
		//좌
		if (_vTile[index.y * _count.x + index.x - 1]->_wall)
		{
			_vTile[index.y * _count.x + index.x - 1]->_wallIndex = GetWallFrame(Vector2(index.x - 1, index.y), tileObj);
		}
		//우
		if (_vTile[index.y * _count.x + index.x + 1]->_wall)
		{
			_vTile[index.y * _count.x + index.x + 1]->_wallIndex = GetWallFrame(Vector2(index.x + 1, index.y), tileObj);
		}

	}
	break;
	case OBJECTTYPE::OBJECT:
	{
		//방향이 오른쪽 또는 왼쪽이라면 차지하는 x, y 칸의 개수를 뒤집어 검사 해 준다.
		Vector2 count = tileObj->_count;
		if (tileObj->_direction == DIRECTION::RIGHT || tileObj->_direction == DIRECTION::LEFT)
		{
			count.x = tileObj->_count.y;
			count.y = tileObj->_count.x;
		}

		//예외에 해당하면 만들지 않음.
		for (int i = 0; i < count.x; i++)
		{
			for (int j = 0; j < count.y; j++)
			{
				if (!CanBuildTile(Vector2(index.x + i, index.y + j), tileObj)) return;
			}
		}

		//해당 타일에 인덱스를 만들고, 오브젝트의 시작 인덱스로 설정한다.
		tileObj->_startIndex = index;

		for (int i = 0; i < count.x; i++)
		{
			for (int j = 0; j < count.y; j++)
			{
				//카운트 인덱스를 전부 해당 오브젝트로 링크 시켜 준다.
				_vTile[(index.y + j) * _count.x + index.x + i]->_tileObj = tileObj;
			}
		}
	}
	break;
	}
}

int TileMap::GetWallFrame(Vector2 index, TileObject * tileObj)
{
	//주변 네 타일을 검사하고 프레임을 바꿔 줌.
	int wall = 0;

	//상
	if (_vTile[(index.y - 1) * _count.x + index.x]->_wall) wall += 1;
	//하
	if (_vTile[(index.y + 1) * _count.x + index.x]->_wall) wall += 2;
	//좌
	if (_vTile[index.y * _count.x + index.x - 1]->_wall) wall += 4;
	//우
	if (_vTile[index.y * _count.x + index.x + 1]->_wall) wall += 8;

	int wallIndex;

	switch (wall)
	{
		case 0:	 wallIndex = 22;	break;		//무
		case 1:	 wallIndex = 14;	break;		//상
		case 2:	 wallIndex = 7;		break;		//하
		case 3:	 wallIndex = 0;		break;		//상하
		case 4:	 wallIndex = 15;	break;		//좌
		case 5:	 wallIndex = 10;	break;		//상좌
		case 6:	 wallIndex = 3;		break;		//하좌
		case 7:	 wallIndex = 19;	break;		//상하좌
		case 8:	 wallIndex = 8;		break;		//우
		case 9:	 wallIndex = 9;		break;		//상우
		case 10: wallIndex = 2;		break;		//하우
		case 11: wallIndex = 18;	break;		//상하우
		case 12: wallIndex = 1;		break;		//좌우
		case 13: wallIndex = 11;	break;		//상좌우
		case 14: wallIndex = 4;		break;		//하좌우
		case 15: wallIndex = 20;	break;		//상하좌우
		default:
		break;
	}
	return wallIndex;
}

bool TileMap::CanBuildTile(Vector2 index, TileObject * tileObj)
{
	//if(소지금이 적을 경우) return false;

	//범위가 타일맵을 넘어가면 만들지 않음.
	if (index.x >= _count.x - 1 || index.y >= _count.y - 1) return false;

	switch (tileObj->_type)
	{
		case OBJECTTYPE::TERRAIN:
		{
		}
		break;
		case OBJECTTYPE::WALL:
		{
			//이미 오브젝트가 있다면 만들지 못 함.
			if (_vTile[(index.y) * _count.x + index.x]->_tileObj) return false;

			//이미 같은 타입의 벽이 있다면 만들지 못 함.
			if (_vTile[index.y * _count.x + index.x]->_wall && _vTile[index.y * _count.x + index.x]->_wall->_wallType == tileObj->_wallType) return false;
		}
		break;
		case OBJECTTYPE::OBJECT:
		{
			//이미 벽이나 오브젝트가 있으면 만들지 않음.
			if (_vTile[(index.y) * _count.x + index.x]->_wall || _vTile[(index.y) * _count.x + index.x]->_tileObj) return false;
		}
		break;
	}
	return true;
}
