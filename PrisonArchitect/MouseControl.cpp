#include "stdafx.h"
#include "MouseControl.h"
#include "TileObject.h"

void MouseControl::Init()
{
	_mouseObj = new TileObject(TILEOBJECT::가스레인지, DIRECTION::FRONT);
}

void MouseControl::Release()
{
}

void MouseControl::Update()
{
	Control();

	if (KEYMANAGER->isOnceKeyDown('R'))
	{
		int num = (int)_mouseObj->_direction;

		if (num == (int)DIRECTION::RIGHT) num = -1;
		_mouseObj->_direction = (DIRECTION)(num + 1);
	}

	if (KEYMANAGER->isOnceKeyDown('1'))
	{
		_mouseObj = new TileObject(TILEOBJECT::가스레인지, DIRECTION::FRONT);
	}

	if (KEYMANAGER->isOnceKeyDown('2'))
	{
		_mouseObj = new TileObject(TILEOBJECT::배식대, DIRECTION::FRONT);
	}

	if (KEYMANAGER->isOnceKeyDown('3'))
	{
		_mouseObj = new TileObject(TILEOBJECT::벤치, DIRECTION::FRONT);
	}

	if (KEYMANAGER->isOnceKeyDown('4'))
	{
		_mouseObj = NULL;
	}

	if (KEYMANAGER->isOnceKeyDown('5'))
	{
		_mouseObj = new TileObject(TILETERRAIN::ASPHALT);
	}

	if (KEYMANAGER->isOnceKeyDown('6'))
	{
		_mouseObj = new TileObject(TILEOBJECT::변기, DIRECTION::FRONT);
	}

	if (KEYMANAGER->isOnceKeyDown('7'))
	{
		_mouseObj = new TileObject(TILEOBJECT::사무실책상, DIRECTION::FRONT);
	}

	if (KEYMANAGER->isOnceKeyDown('8'))
	{
		_mouseObj = new TileObject(TILEWALL::WALL0);
	}

	if (KEYMANAGER->isOnceKeyDown('9'))
	{
		_mouseObj = new TileObject(TILEWALL::WALL1);
	}
}

void MouseControl::Render()
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

	if (_mouseObj)
	{
		if (_mouseObj->_type == OBJECTTYPE::OBJECT)
		{
			//오브젝트가 차지하는 인덱스 렉트를 렌더한다.
			FloatRect objRc;
			if (_mouseObj->_direction == DIRECTION::FRONT || _mouseObj->_direction == DIRECTION::BACK)
			{
				objRc = FloatRect(_endPoint.x, _endPoint.y, _endPoint.x + _mouseObj->_count.x*TILESIZE, _endPoint.y + _mouseObj->_count.y*TILESIZE);
				objRc = CAMERAMANAGER->GetVCamera()[0]->GetRelativePos(objRc);
				_D2DRenderer->FillRectangle(objRc, D2DRenderer::DefaultBrush::Green);
			}
			else if (_mouseObj->_direction == DIRECTION::RIGHT || _mouseObj->_direction == DIRECTION::LEFT)
			{
				objRc = FloatRect(_endPoint.x, _endPoint.y, _endPoint.x + _mouseObj->_count.y*TILESIZE, _endPoint.y + _mouseObj->_count.x*TILESIZE);
				objRc = CAMERAMANAGER->GetVCamera()[0]->GetRelativePos(objRc);
				_D2DRenderer->FillRectangle(objRc, D2DRenderer::DefaultBrush::Green);
			}

			//왼쪽이라면 이미지를 가로로 뒤집는다.
			if (_mouseObj->_direction == DIRECTION::LEFT) _mouseObj->_img->SetReverseX(true);

			//마우스에 오브젝트를 렌더한다.
			_mouseObj->_img->SetAlpha(0.5f);
			if (_mouseObj->_direction == DIRECTION::FRONT || _mouseObj->_direction == DIRECTION::BACK)
			{
				_mouseObj->_img->FrameRender(Vector2(_endPoint.x + (_mouseObj->_count.x * TILESIZE)/2,
					TILESIZE / 2 + _endPoint.y + (_mouseObj->_count.y*TILESIZE) / 2 - _mouseObj->_img->GetFrameSize().y / 2)
					, _mouseObj->_frame[(int)_mouseObj->_direction], 0, CAMERAMANAGER->GetVCamera()[0]);
			}
			else if (_mouseObj->_direction == DIRECTION::RIGHT || _mouseObj->_direction == DIRECTION::LEFT)
			{
				_mouseObj->_img->FrameRender(Vector2(_endPoint.x + (_mouseObj->_count.y * TILESIZE) - TILESIZE/2,
					_endPoint.y + (_mouseObj->_count.x*TILESIZE) - _mouseObj->_img->GetFrameSize().y / 2 )
					, _mouseObj->_frame[(int)_mouseObj->_direction], 0, CAMERAMANAGER->GetVCamera()[0]);
			}
		}
		//else if (_mouseObj->_type != OBJECTTYPE::WALL)
		//{
		//	//엔드 렉트를 렌더한다.
		//	FloatRect dragRc = FloatRect(_endPoint.x, _endPoint.y, _endPoint.x + TILESIZE, _endPoint.y + TILESIZE);
		//	dragRc = CAMERAMANAGER->GetVCamera()[0]->GetRelativePos(dragRc);
		//	_D2DRenderer->FillRectangle(dragRc, D2DRenderer::DefaultBrush::Blue);
		//}
	}
}

void MouseControl::Control()
{
	if (!_mouseObj)	//마우스에 오브젝트가 없다면
	{
		_drag = MOUSEDRAG::NONE;
	}
	else // 마우스 오브젝트의 타입에 따라 드래그를 결정
	{
		switch (_mouseObj->_type)
		{
		case OBJECTTYPE::NONE:
			_drag = MOUSEDRAG::NONE;
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
		if (_startIndex.x >= TILEMAP->GetCount().x) _startIndex.x = TILEMAP->GetCount().x-1;
		if (_startIndex.y >= TILEMAP->GetCount().y) _startIndex.y = TILEMAP->GetCount().y-1;

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
	if (_endIndex.x >= TILEMAP->GetCount().x) _endIndex.x = TILEMAP->GetCount().x-1;
	if (_endIndex.y >= TILEMAP->GetCount().y) _endIndex.y = TILEMAP->GetCount().y-1;

	_endPoint.x = _endIndex.x * TILESIZE;
	_endPoint.y = _endIndex.y * TILESIZE;

	if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
	{
		if (_drag == MOUSEDRAG::POINT) TILEMAP->BuildTileObject(Vector2(_endIndex.x, _endIndex.y), new TileObject(*_mouseObj));
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

		if (_mouseObj)	//마우스에 오브젝트가 있다면 생성한다
		{
			switch (_drag)
			{
				case MOUSEDRAG::NONE:
				break;
				case MOUSEDRAG::POINT:	//포인트는 Down에서 바로 그린다.
					//TILEMAP->BuildTileObject(Vector2(_endIndex.x, _endIndex.y), new TileObject(*_mouseObj));
				break;
				case MOUSEDRAG::LINE:
				{
					for (int i = 0; i < _vSelectIndex.size(); i++)
					{
						if (_vSelectIndex[i].x > _vSelectIndex[0].x && _vSelectIndex[i].x < _vSelectIndex[_vSelectIndex.size()-1].x
						&&_vSelectIndex[i].y != _vSelectIndex[0].y&& _vSelectIndex[i].y < _vSelectIndex[_vSelectIndex.size() - 1].y) continue;
						TILEMAP->BuildTileObject(Vector2(_vSelectIndex[i].x, _vSelectIndex[i].y), new TileObject(*_mouseObj));
					}
				}
				break;
				case MOUSEDRAG::RECT:
				{
					for (int i = 0; i < _vSelectIndex.size(); i++)
					{
						TILEMAP->BuildTileObject(Vector2(_vSelectIndex[i].x, _vSelectIndex[i].y), new TileObject(*_mouseObj));
					}
				}
				break;

			}			
		}
	}
}
