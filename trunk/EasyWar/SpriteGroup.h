#pragma once
#include "Sprite.h"
#include <vector>

using namespace std;

//���ڴ洢����һ��Sprite
class SpriteGroup
{
public:
	SpriteGroup();
	SpriteGroup( int groupsize );
	~SpriteGroup();
	void SetSize( int groupsize );							//���ÿ������ɶ��ٸ�Sprite
	bool AddSprite( int index, const char* fileName );		//���һ��Sprite
	void ClearAll();										//������������Sprite
	Sprite& GetSprite( int index );							//�õ������һ����һ������
	SDL_Surface* operator[]( int index );					//�õ�ĳ��Sprite��Surface��ָ��

protected:
	vector<Sprite> m_allSpr;								//��Sprite�������Sprite

};
