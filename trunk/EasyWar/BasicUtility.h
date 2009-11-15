#pragma once
#include <cmath>

using namespace std;


//�����ṩ��һЩ�����Ķ������㣬��ɫ�����εĽṹ��һЩ�򵥲��������

#define CREATE_LOGIC( x )	new x


//��ɫ�ṹ
struct Color
{
	int _r;
	int _g;
	int _b;
	int _a;

	Color():_r(0),_g(0),_b(0),_a(0){}
	Color( int r, int g, int b, int a ):_r(r),_g(g),_b(b),_a(a){}
};

//��ṹ��������
struct Point
{
	int _x;
	int _y;

	Point():_x(0),_y(0){}
	Point( int x, int y ):_x(x),_y(y){}
};

//��ṹ��ʵ����
struct Pointf
{
	float _x;
	float _y;

	Pointf():_x(0.0f),_y(0.0f){}
	Pointf( float x, float y ):_x(x),_y(y){}
};


//���νṹ
struct Rect
{
	int _left;
	int _top;
	int _right;
	int _bottom;

	Rect():_left(0),_top(0),_right(0),_bottom(0){}
	Rect( int _l, int _t, int _r, int _b ):_left(_l),_top(_t),_right(_r),_bottom(_b){}
};
