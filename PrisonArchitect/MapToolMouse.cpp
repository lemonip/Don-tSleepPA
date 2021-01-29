#include "stdafx.h"
#include "MapToolMouse.h"
#include "MapToolScene.h"

MapToolMouse::MapToolMouse(MapToolScene* scene)
{
	_scene = scene;
	_tileMap = _scene->GetMapM()->GetTileMap();
}

void MapToolMouse::Init()
{

	_buildObj = DATAMANAGER->FindTileObject("가스레인지");
	_state = MOUSESTATE::SELECT;

}

void MapToolMouse::Release()
{
}

void MapToolMouse::Update()
{
	Control();

	if (KEYMANAGER->isOnceKeyDown('0'))
	{
		_buildObj = NULL;
	}

	if (KEYMANAGER->isOnceKeyDown('1'))
	{
		_buildObj = DATAMANAGER->FindTileObject("가스레인지");
	}

	if (KEYMANAGER->isOnceKeyDown('2'))
	{
		_buildObj = DATAMANAGER->FindTileObject("배식대");
	}

	if (KEYMANAGER->isOnceKeyDown('3'))
	{
		_buildObj = DATAMANAGER->FindTileObject("벤치");
	}

	if (KEYMANAGER->isOnceKeyDown('4'))
	{
		_buildObj = DATAMANAGER->FindTileObject("wall0");
	}

	if (KEYMANAGER->isOnceKeyDown('5'))
	{
		_buildObj = DATAMANAGER->FindTileObject("wall1");
	}

	if (KEYMANAGER->isOnceKeyDown('6'))
	{
		_buildObj = DATAMANAGER->FindTileObject("사무실책상");
	}

	if (KEYMANAGER->isOnceKeyDown('7'))
	{
		_buildObj = DATAMANAGER->FindTileObject("GRASS2");
	}

	////////

	

}

void MapToolMouse::Render()
{
	if (_isDragging)
	{
		if (_drag == MOUSEDRAG::LINE)
		{
			//드래그 선을 렌더한다.
			FloatRect dragRc = FloatRect(_startPoint.x, _startPoint.y, _endPoint.x + TILESIZE, _endPoint.y + TILESIZE);
			dragRc = CAMERAMANAGER->GetVCamera()[0]->GetRelativePos(dragRc);
			_D2DRenderer->DrawRectangle(dragRc, D2DRenderer::DefaultBrush::Blue, 5.0f);
		}
		else
		{
			//드래그 렉트를 렌더한다.
			FloatRect dragRc = FloatRect(_startPoint.x, _startPoint.y, _endPoint.x + TILESIZE, _endPoint.y + TILESIZE);
			dragRc = CAMERAMANAGER->GetVCamera()[0]->GetRelativePos(dragRc);
			_D2DRenderer->FillRectangle(dragRc, D2DRenderer::DefaultBrush::Blue);
		}
	}

	if (_buildObj)
	{
		switch (_buildObj->_type)
		{
		case OBJECTTYPE::TERRAIN:		case OBJECTTYPE::WALL:
		{
			//엔드 렉트를 렌더한다.
			FloatRect dragRc = FloatRect(_endPoint.x, _endPoint.y, _endPoint.x + TILESIZE, _endPoint.y + TILESIZE);
			dragRc = CAMERAMANAGER->GetVCamera()[0]->GetRelativePos(dragRc);
			_D2DRenderer->FillRectangle(dragRc, D2DRenderer::DefaultBrush::Green);
		}
		break;
		case OBJECTTYPE::OBJECT:
		{
			//오브젝트가 차지하는 인덱스 렉트를 렌더한다.
			FloatRect objRc;
			if (_buildObj->_direction == DIRECTION::FRONT || _buildObj->_direction == DIRECTION::BACK)
			{
				objRc = FloatRect(_endPoint.x, _endPoint.y, _endPoint.x + _buildObj->_count.x*TILESIZE, _endPoint.y + _buildObj->_count.y*TILESIZE);
				objRc = CAMERAMANAGER->GetVCamera()[0]->GetRelativePos(objRc);
				_D2DRenderer->FillRectangle(objRc, D2DRenderer::DefaultBrush::Green);
			}
			else if (_buildObj->_direction == DIRECTION::RIGHT || _buildObj->_direction == DIRECTION::LEFT)
			{
				objRc = FloatRect(_endPoint.x, _endPoint.y, _endPoint.x + _buildObj->_count.y*TILESIZE, _endPoint.y + _buildObj->_count.x*TILESIZE);
				objRc = CAMERAMANAGER->GetVCamera()[0]->GetRelativePos(objRc);
				_D2DRenderer->FillRectangle(objRc, D2DRenderer::DefaultBrush::Green);
			}

			//왼쪽이라면 이미지를 가로로 뒤집는다.
			if (_buildObj->_direction == DIRECTION::LEFT) _buildObj->_img->SetReverseX(true);

			//마우스에 오브젝트를 렌더한다.
			_buildObj->_img->SetAlpha(0.5f);
			if (_buildObj->_direction == DIRECTION::FRONT || _buildObj->_direction == DIRECTION::BACK)
			{
				_buildObj->_img->FrameRender(Vector2(_endPoint.x + (_buildObj->_count.x * TILESIZE) / 2,
					TILESIZE / 2 + _endPoint.y + (_buildObj->_count.y*TILESIZE) / 2 - _buildObj->_img->GetFrameSize().y / 2)
					, _buildObj->_frame[(int)_buildObj->_direction], 0, CAMERAMANAGER->GetVCamera()[0]);
			}
			else if (_buildObj->_direction == DIRECTION::RIGHT || _buildObj->_direction == DIRECTION::LEFT)
			{
				_buildObj->_img->FrameRender(Vector2(_endPoint.x + (_buildObj->_count.y * TILESIZE) - TILESIZE / 2,
					_endPoint.y + (_buildObj->_count.x*TILESIZE) - _buildObj->_img->GetFrameSize().y / 2)
					, _buildObj->_frame[(int)_buildObj->_direction], 0, CAMERAMANAGER->GetVCamera()[0]);
			}
		}
		break;
		case OBJECTTYPE::END:
			break;
		default:
			break;
		}
	}

	//보여주면 안됨. 차라리 색을 바꿔 주기?
	if (_selectObj)
	{
		_selectObj->_img->FrameRender(Vector2(_endPoint.x + (_selectObj->_count.y * TILESIZE) - TILESIZE / 2,
			_endPoint.y + (_selectObj->_count.x*TILESIZE) - _selectObj->_img->GetFrameSize().y / 2)
			, _selectObj->_frame[(int)_selectObj->_direction], 0, CAMERAMANAGER->GetVCamera()[0]);
	}

}

void MapToolMouse::Control()
{
	//UI를 선택하는 경우
	UIControl();
	if (_isOnUI) return;

	//마우스가 있을 경우
	if (_buildObj)
	{
		_state = MOUSESTATE::BUILD;
		if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
		{
			_buildObj = NULL;
			_state = MOUSESTATE::SELECT;
		}
	}

	//선택 오브젝트가 있을 경우
	if (_selectObj)
	{
		_state = MOUSESTATE::DESTROY;
	}


	switch (_state)
	{
		case MOUSESTATE::BUILD:
		{
			BuildControl();
		}
		break;
		case MOUSESTATE::DESTROY:
		{
			cout << "파괴상태" << endl;

			if (_selectObj->_type == OBJECTTYPE::WALL)
			{
				_tileMap->GetvTile()[_selectObj->_startIndex.x + _selectObj->_startIndex.y]->_wall =  NULL;
			}

			if (_selectObj->_type == OBJECTTYPE::OBJECT)
			{
				for (int i = _selectObj->_startIndex.x; i < _selectObj->_startIndex.x + _selectObj->_count.x + 1; i++)
				{
					for (int j = _startIndex.y; j < _startIndex.y + _selectObj->_count.y + 1; j++)
					{
						_tileMap->GetvTile()[i + j * _tileMap->GetCount().x]->_tileObj = NULL;
					}
				}
			}
			_selectObj = NULL;
			_state = MOUSESTATE::SELECT;
		}
		break;
		case MOUSESTATE::SELECT:
		{
			//사람 선택
			for (int i = 0; i < _scene->GetvCharacter().size(); i++)
			{
				if (PtInRect(&(_scene->GetvCharacter()[i]->GetTransform()->GetRect()), { (LONG)_ptMouse.x, (LONG)_ptMouse.y }))
				{
					if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON)) OnCollisionEnter(_scene->GetvCharacter()[i]);
					if (KEYMANAGER->isStayKeyDown(VK_LBUTTON)) OnCollisionStay(_scene->GetvCharacter()[i]);
					if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON)) OnCollisionExit(_scene->GetvCharacter()[i]);
				}
			}
			//물건 선택


			//타일 선택

			//선택한 끝점
			_endIndex.x = (int)CAMERAMANAGER->GetVCamera()[0]->GetAbsolutePos(_ptMouse).x / TILESIZE;
			_endIndex.y = (int)CAMERAMANAGER->GetVCamera()[0]->GetAbsolutePos(_ptMouse).y / TILESIZE;

			if (_endIndex.x < 0) _endIndex.x = 0;
			if (_endIndex.y < 0) _endIndex.y = 0;
			if (_endIndex.x >= _tileMap->GetCount().x) _endIndex.x = _tileMap->GetCount().x - 1;
			if (_endIndex.y >= _tileMap->GetCount().y) _endIndex.y = _tileMap->GetCount().y - 1;

			_endPoint.x = _endIndex.x * TILESIZE;
			_endPoint.y = _endIndex.y * TILESIZE;

			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				//OnCollisionEnter(_scene->GetMapM()->GetTileMap()->GetvTile()[i]);
				_selectObj = _tileMap->GetvTile()[ _endIndex.y * _tileMap->GetCount().x+ _endIndex.x]->MouseEnter();
			}
			if (KEYMANAGER->isStayKeyDown(VK_LBUTTON)) OnCollisionStay	(_tileMap->GetvTile()[_ptMouse.y / TILESIZE * _tileMap->GetCount().x + _ptMouse.x/TILESIZE]);
			if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))   OnCollisionExit	(_tileMap->GetvTile()[_ptMouse.y / TILESIZE * _tileMap->GetCount().x + _ptMouse.x/TILESIZE]);
		}
		break;
		default:
		break;
	}

}

void MapToolMouse::UIControl()
{
	// UI 위에 있을 경우, 마우스 상태를 UI로 변경한다.
	for (BarButtonUI* u : _scene->GetvUnderBarUI())
	{
		if (u->getButton()->getRect().PtInRect(_ptMouse))
		{
			_isOnUI = true;
			return;
		}
		else
		{
			_isOnUI = false;
		}
	}

	for (WindowUI* w : _scene->GetvUnderBarWindowUI())
	{
		for (Button* b : w->getVButton())
		{
			if (b->getRect().PtInRect(_ptMouse))
			{
				_isOnUI = true;
				return;
			}
			else
			{
				_isOnUI = false;
			}
		}
	}
}

void MapToolMouse::BuildControl()
{
	// 마우스에 오브젝트가 달려 있는 경우 설치한다.
	if (KEYMANAGER->isOnceKeyDown('R'))
	{
		int num = (int)_buildObj->_direction;

		if (num == (int)DIRECTION::RIGHT) num = -1;
		_buildObj->_direction = (DIRECTION)(num + 1);
	}

	if (!_buildObj)	//마우스에 오브젝트가 없다면
	{
		_drag = MOUSEDRAG::END;
	}
	else // 마우스 오브젝트의 타입에 따라 드래그를 결정
	{
		switch (_buildObj->_type)
		{
		case OBJECTTYPE::END:
			_drag = MOUSEDRAG::END;
			break;
		case OBJECTTYPE::TERRAIN:
			_drag = MOUSEDRAG::RECT;
			break;
		case OBJECTTYPE::WALL:
			_drag = MOUSEDRAG::LINE;
			break;
		case OBJECTTYPE::OBJECT:
			_drag = MOUSEDRAG::POINT;
			break;
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		//선택한 시작점
		_startIndex.x = (int)CAMERAMANAGER->GetVCamera()[0]->GetAbsolutePos(_ptMouse).x / TILESIZE;
		_startIndex.y = (int)CAMERAMANAGER->GetVCamera()[0]->GetAbsolutePos(_ptMouse).y / TILESIZE;

		if (_startIndex.x < 0) _startIndex.x = 0;
		if (_startIndex.y < 0) _startIndex.y = 0;
		if (_startIndex.x >= _tileMap->GetCount().x) _startIndex.x = _tileMap->GetCount().x - 1;
		if (_startIndex.y >= _tileMap->GetCount().y) _startIndex.y = _tileMap->GetCount().y - 1;

		_startPoint.x = _startIndex.x * TILESIZE;
		_startPoint.y = _startIndex.y * TILESIZE;

		cout << _startIndex.x << "," << _startIndex.y << endl;

		if (_drag != MOUSEDRAG::POINT) _isDragging = true;
	}

	//선택한 끝점
	_endIndex.x = (int)CAMERAMANAGER->GetVCamera()[0]->GetAbsolutePos(_ptMouse).x / TILESIZE;
	_endIndex.y = (int)CAMERAMANAGER->GetVCamera()[0]->GetAbsolutePos(_ptMouse).y / TILESIZE;

	if (_endIndex.x < 0) _endIndex.x = 0;
	if (_endIndex.y < 0) _endIndex.y = 0;
	if (_endIndex.x >= _tileMap->GetCount().x) _endIndex.x = _tileMap->GetCount().x - 1;
	if (_endIndex.y >= _tileMap->GetCount().y) _endIndex.y = _tileMap->GetCount().y - 1;

	_endPoint.x = _endIndex.x * TILESIZE;
	_endPoint.y = _endIndex.y * TILESIZE;

	if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
	{
		if (_drag == MOUSEDRAG::POINT) _tileMap->BuildTileObject(Vector2(_endIndex.x, _endIndex.y), new TileObject(*_buildObj));
	}

	if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
	{
		_vSelectIndex.clear();

		Vector2 tempPoint;
		if (_startPoint.x > _endPoint.x)
		{
			tempPoint.x = _startPoint.x;
			_startPoint.x = _endPoint.x;
			_endPoint.x = tempPoint.x;
		}

		if (_startPoint.y > _endPoint.y)
		{
			tempPoint.y = _startPoint.y;
			_startPoint.y = _endPoint.y;
			_endPoint.y = tempPoint.y;
		}

		if (_isDragging)
		{
			//떼는 순간 인덱스들을 선택 벡터에 넣는다.
			for (int i = _startIndex.x; i < _endIndex.x + 1; i++)
			{
				for (int j = _startIndex.y; j < _endIndex.y + 1; j++)
				{
					_vSelectIndex.push_back(Vector2(i, j));
				}
			}
		}

		//드래그를 끈다.
		_isDragging = false;

		if (_buildObj)	//마우스에 오브젝트가 있다면 생성한다
		{
			switch (_drag)
			{
			case MOUSEDRAG::END:
				break;
			case MOUSEDRAG::POINT:	//포인트는 Down에서 바로 그린다.
				//TILEMAP->BuildTileObject(Vector2(_endIndex.x, _endIndex.y), new TileObject(*_mouseObj));
				break;
			case MOUSEDRAG::LINE:
			{
				for (int i = 0; i < _vSelectIndex.size(); i++)
				{
					if (_vSelectIndex[i].x > _vSelectIndex[0].x && _vSelectIndex[i].x < _vSelectIndex[_vSelectIndex.size() - 1].x
						&&_vSelectIndex[i].y != _vSelectIndex[0].y&& _vSelectIndex[i].y < _vSelectIndex[_vSelectIndex.size() - 1].y) continue;
					_tileMap->BuildTileObject(Vector2(_vSelectIndex[i].x, _vSelectIndex[i].y), new TileObject(*_buildObj));
				}
			}
			break;
			case MOUSEDRAG::RECT:
			{
				for (int i = 0; i < _vSelectIndex.size(); i++)
				{
					_tileMap->BuildTileObject(Vector2(_vSelectIndex[i].x, _vSelectIndex[i].y), new TileObject(*_buildObj));
				}
			}
			break;
			}
		}
	}
}

void MapToolMouse::SelectControl()
{
}

void MapToolMouse::ObjectControl()
{
}

void MapToolMouse::TileObjectControl()
{
}
