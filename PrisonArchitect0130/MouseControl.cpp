
#include "stdafx.h"
#include "MouseControl.h"
#include "TileObject.h"
/*
void MouseControl::Init()
{
	_mouseObj = DATAMANAGER->FindTileObject("가스레인지");
	_state = MOUSESTATE::NONE;
}

void MouseControl::Release()
{
}

void MouseControl::Update()
{
	/*
	//항상
	template<T>

	if(KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	ClickObject() -> Click(); //클릭함수에서 마우스가 렌더하는 이미지 또는 오브젝트를 끼워준다?

	Script(컴포넌트)

	for(UI)
	ptinrect return ui;

	if(선택)
	for(사람)
	ptinrect return 사람;

	for(오브젝트)
	ptinrect return 오브젝트;

	for(벽)
	ptrinrect return 벽;



	if(설치, 철거)
	for(타일)
	ptinrect return 타일

	*/

	//Control();
/*
	Move();

	if (KEYMANAGER->isOnceKeyDown('R'))
	{
		int num = (int)_mouseObj->_direction;

		if (num == (int)DIRECTION::RIGHT) num = -1;
		_mouseObj->_direction = (DIRECTION)(num + 1);
	}

	if (KEYMANAGER->isOnceKeyDown('0'))
	{
		_mouseObj = NULL;
	}

	if (KEYMANAGER->isOnceKeyDown('1'))
	{
		_mouseObj = DATAMANAGER->FindTileObject("가스레인지");
	}

	if (KEYMANAGER->isOnceKeyDown('2'))
	{
		_mouseObj = DATAMANAGER->FindTileObject("배식대");
	}

	if (KEYMANAGER->isOnceKeyDown('3'))
	{
		_mouseObj = DATAMANAGER->FindTileObject("벤치");
	}

	if (KEYMANAGER->isOnceKeyDown('4'))
	{
		_mouseObj = DATAMANAGER->FindTileObject("wall0");
	}

	if (KEYMANAGER->isOnceKeyDown('5'))
	{
		_mouseObj = DATAMANAGER->FindTileObject("wall1");
	}

	if (KEYMANAGER->isOnceKeyDown('6'))
	{
		_mouseObj = DATAMANAGER->FindTileObject("사무실책상");
	}

	if (KEYMANAGER->isOnceKeyDown('7'))
	{
		_mouseObj = DATAMANAGER->FindTileObject("GRASS2");
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
		switch (_mouseObj->_type)
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
				_mouseObj->_img->FrameRender(Vector2(_endPoint.x + (_mouseObj->_count.x * TILESIZE) / 2,
					TILESIZE / 2 + _endPoint.y + (_mouseObj->_count.y*TILESIZE) / 2 - _mouseObj->_img->GetFrameSize().y / 2)
					, _mouseObj->_frame[(int)_mouseObj->_direction], 0, CAMERAMANAGER->GetVCamera()[0]);
			}
			else if (_mouseObj->_direction == DIRECTION::RIGHT || _mouseObj->_direction == DIRECTION::LEFT)
			{
				_mouseObj->_img->FrameRender(Vector2(_endPoint.x + (_mouseObj->_count.y * TILESIZE) - TILESIZE / 2,
					_endPoint.y + (_mouseObj->_count.x*TILESIZE) - _mouseObj->_img->GetFrameSize().y / 2)
					, _mouseObj->_frame[(int)_mouseObj->_direction], 0, CAMERAMANAGER->GetVCamera()[0]);
			}
		}
		break;
		case OBJECTTYPE::END:
			break;
		default:
			break;
		}
	}
}

void MouseControl::Control()
{
	if (!_mouseObj)	//마우스에 오브젝트가 없다면
	{
		_drag = MOUSEDRAG::END;
	}
	else // 마우스 오브젝트의 타입에 따라 드래그를 결정
	{
		switch (_mouseObj->_type)
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
		if (_drag == MOUSEDRAG::POINT) _tileMap->BuildTileObject(Vector2(_endIndex.x, _endIndex.y), new TileObject(*_mouseObj));
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
					_tileMap->BuildTileObject(Vector2(_vSelectIndex[i].x, _vSelectIndex[i].y), new TileObject(*_mouseObj));
				}
			}
			break;
			case MOUSEDRAG::RECT:
			{
				for (int i = 0; i < _vSelectIndex.size(); i++)
				{
					_tileMap->BuildTileObject(Vector2(_vSelectIndex[i].x, _vSelectIndex[i].y), new TileObject(*_mouseObj));
				}
			}
			break;
			}
		}
	}
}

void MouseControl::Move()
{
	/*
	//항상
	template<T>

	if(KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	ClickObject() -> Click(); //클릭함수에서 마우스가 렌더하는 이미지 또는 오브젝트를 끼워준다?

	Script(컴포넌트)

	for(UI)
	ptinrect return ui;

	if(선택)
	for(사람)
	ptinrect return 사람;

	for(오브젝트)
	ptinrect return 오브젝트;

	for(벽)
	ptrinrect return 벽;



	if(설치, 철거)
	for(타일)
	ptinrect return 타일

	*/
/*
	//UI와 ptInRect 된다면 상태를 UI로
	{
		SCENEMANAGER->GetCurrentScene();
	}

	switch (_state)
	{
		case MOUSESTATE::ONUI:
		{
			
		}
		break;
		case MOUSESTATE::NONE:
		{

		}
		break;
		default:
		break;
	}




}
*/