#include "stdafx.h"
#include "Sprite.h"

Sprite::Sprite()
{
	m_spr= NULL;
}

Sprite::Sprite( const char* filename )
{
	m_spr= IMG_Load( filename );
}

Sprite::~Sprite()
{
	Kill();
}

//����ͼƬ
void Sprite::Load( const char* filename )
{
	Kill();

	m_spr= IMG_Load( filename );
}

//ɾ��Sprite
void Sprite::Kill()
{
	if( m_spr )
	{
		SDL_FreeSurface( m_spr );
	}
}

//���ð�͸��
void Sprite::SetAlpha( int alpha )
{
	if( m_spr )
	{
		SDL_gfxSetAlpha( m_spr, alpha );
	}
}

//��ת����
void Sprite::SetAngleZoom( double angle, double zoom )
{
	if( m_spr )
	{
		SDL_Surface* obj= m_spr;

		m_spr= rotozoomSurface( m_spr, angle, zoom, 1 );
		
		SDL_FreeSurface( obj );
	}
}

//���У��Եõ�ԭͼ�ľֲ���
void Sprite::Clip( int x, int y, int wid, int hei )
{
	if( m_spr == NULL )
	{
		return;
	}

	SDL_Rect rect;
	rect.x= x;
	rect.y= y;
	rect.w= wid;
	rect.h= hei;

	Uint32 rmask= m_spr->format->Rmask;
	Uint32 gmask= m_spr->format->Gmask;
	Uint32 bmask= m_spr->format->Bmask;
	Uint32 amask= m_spr->format->Amask;

	int depth= m_spr->format->BitsPerPixel;
	if( depth < 24 )
	{
		depth= 24;
	}

	//�����±���
	SDL_Surface* newFace;
	newFace= SDL_CreateRGBSurface( SDL_HWSURFACE|SDL_SRCALPHA, wid, hei, depth, rmask, gmask, bmask, amask );

	//ָ�������Ƶ��±���
	if( m_spr->format->BytesPerPixel == 4 )				//��͸��ɫ��
	{
		SDL_gfxBlitRGBA( m_spr, &rect, newFace, NULL );
	}else												//��͸��ɫ��
	{
		SDL_BlitSurface( m_spr, &rect, newFace, NULL );
	}

	//ɾ���ɱ���
	SDL_FreeSurface( m_spr );
	m_spr= newFace;

}

//����
void Sprite::Clip( Rect& region )
{
	int wid= region._right - region._left + 1;
	int hei= region._bottom - region._top + 1;

	Clip( region._left, region._top, wid, hei );
}

//���У�����UV��������
void Sprite::Clip( float u1, float v1, float u2, float v2 )
{
	float wid= (float)m_spr->w;
	float hei= (float)m_spr->h;

	Rect region;
	region._left= int( wid * u1 );
	region._top= int( hei * v1 );
	region._right= int( wid * u2 );
	region._bottom= int( hei * v2 );

	Clip( region );

}
