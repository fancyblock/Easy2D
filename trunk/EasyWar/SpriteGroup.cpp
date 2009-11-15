#include "stdafx.h"
#include "SpriteGroup.h"

SpriteGroup::SpriteGroup()
{
}

SpriteGroup::SpriteGroup( int groupsize )
{
	m_allSpr.resize( groupsize );
}

SpriteGroup::~SpriteGroup()
{
	ClearAll();
}

//���ÿ������ɶ��ٸ�Sprite
void SpriteGroup::SetSize( int groupsize )
{
	m_allSpr.resize( groupsize );
}

//���һ��Sprite
bool SpriteGroup::AddSprite( int index, const char* fileName )
{
	FILE* pic;
	pic= fopen( fileName, "rb");

	if( pic == NULL )								//�ļ������ڣ������ʧ��
	{
		return false;
	}
	fclose( pic );

	if( index < 0 || index >= (int)m_allSpr.size() )//λ��Խ�磬�����ʧ��
	{
		return false;
	}

	m_allSpr[index].Load( fileName );

	return true;
}

//������������Sprite
void SpriteGroup::ClearAll()
{
	m_allSpr.clear();
}

//�õ�ĳ��Sprite��Surface��ָ��
SDL_Surface* SpriteGroup::operator[]( int index )
{
	return m_allSpr[index].m_spr;
}

//�õ������һ����һ������
Sprite& SpriteGroup::GetSprite( int index )
{
	return m_allSpr[index];
}
