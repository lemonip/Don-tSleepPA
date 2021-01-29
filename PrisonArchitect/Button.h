#pragma once
class Button
{
private:
	FloatRect _rc;
	Vector2 _pos;
	Vector2 _size;
	string _name;

	Image* _img; // 마우스 포인터가 닿으면 살짝 하얘짐 + 종이 넘기는 듯한 소리가 남
	float _scale;
	int _frameX, _frameY;

	function<void()> fn;
public:
	Button(string strName, Vector2 pos, float scale, Image* img);
	Button(string strName, Vector2 pos, float scale, Image* img, int frameX, int frameY);
	~Button();

	void render();

	FloatRect getRect() { return _rc; }
	Vector2 getPos() { return _pos; }
	Vector2 getSize() { return _size; }
	Image* getImage() { return _img; }
	string getName() { return _name; }

	int getFrameX() { return _frameX; }
	int getFrameY() { return _frameY; }

	void setFunction(function<void()> fn) { this->fn = fn; }
	void invokeFunction() { fn(); }
};

