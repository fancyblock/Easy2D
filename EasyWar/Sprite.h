#pragma once
#include "BasicUtility.h"

class SpriteGroup;

//Sprite�࣬���ڱ�ʾ2Dͼ��
class Sprite
{
	friend class SpriteGroup;

public:
	Sprite();
	Sprite( const char* filename );
	~Sprite();
	void Load( const char* filename );		//����ͼƬ
	void Kill();							//ɾ��Sprite
	void SetAlpha( int alpha );				//���ð�͸��
	void SetAngleZoom( double angle, double zoom );
											//��ת����
	void Clip( int x, int y, int wid, int hei );
											//���У��Եõ�ԭͼ�ľֲ���
	void Clip( Rect& region );				//����
	void Clip( float u1, float v1, float u2, float v2 );
											//���У�����UV��������

protected:
	SDL_Surface* m_spr;						//�洢��ͼ���surface

};
