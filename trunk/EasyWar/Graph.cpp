#include "stdafx.h"
#include "Graph.h"

//�洢����ĵ���
Graph* Graph::m_me= NULL;

Graph::Graph()
{
	m_mainWnd= NULL;
	m_beInit= false;
}

//�������������ͷű�����
Graph::~Graph()
{
}

//��ȡ����ĵ���
Graph* Graph::GetSingle()
{
	if( m_me == NULL )
	{
		m_me= new Graph();
	}

	return m_me;
}

//���٣�������ڵĻ���
void Graph::Destory()
{
	if( m_me )
	{
		m_me->ClearAllSpriteGroup();

		if( m_me->m_mainWnd )
		{
			SDL_FreeSurface( m_me->m_mainWnd );
			m_mainWnd= NULL;
			m_beInit= false;
		}

 		delete m_me;
		m_me= NULL;
	}
}

//����ָ����ߴ���һ������
void Graph::CreateWnd( int wid, int hei, bool fullscreen )
{
	if( m_mainWnd )		//�����Ѵ��ھͲ����ٴ�����
	{
		return;
	}

	if( fullscreen )
	{
		m_mainWnd= SDL_SetVideoMode( wid, hei, 24, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN );
	}else
	{
		m_mainWnd= SDL_SetVideoMode( wid, hei, 24, SDL_HWSURFACE | SDL_DOUBLEBUF );
	}

	m_wndWid= wid;
	m_wndHei= hei;

	m_beInit= true;

}

//ʹ��ָ����ɫ������
void Graph::ClearWnd( int r, int g, int b )
{
	Uint32 color;
	
	color= SDL_MapRGBA( m_mainWnd->format, r, g, b, 0);

	SDL_FillRect( m_mainWnd, NULL, color );

}

//���һ��SpriteGroup��
int Graph::AddSpriteGroup( int size )
{
	SpriteGroup* newGroup= new SpriteGroup( size );

	m_spriteGroup.push_back( newGroup );

	return (int)m_spriteGroup.size() - 1;
}

//��ָ��SpriteGroup�����Sprite
bool Graph::AddSprite( int group, int pos, const char* filename )
{
	if( group < 0 || group >= (int)m_spriteGroup.size() )	//���Խ�磬���ʧ��
	{
		return false;
	}

	return m_spriteGroup[group]->AddSprite( pos, filename );

}

//������е�SpriteGroup
void Graph::ClearAllSpriteGroup()
{
	size_t len= m_spriteGroup.size();

	for( size_t i(0); i< len; i++ )
	{
		delete m_spriteGroup[i];
	}

	m_spriteGroup.clear();
}

//ÿ��ͼ�����������ô�
void Graph::Flush()
{
	SDL_Flip( m_mainWnd );
}

//����ĳЩ�ض��ĵط����ܻ��õ���
void Graph::DrawRect( int x1, int y1, int x2, int y2, int r, int g, int b, int a )
{
	rectangleRGBA( m_mainWnd, x1, y1, x2, y2, r, g, b, a );
}												

//����һ��Sprite�����ڣ���ͨ��
void Graph::Draw( int group, int sprite, int x, int y )
{
	SDL_Surface* obj= (*m_spriteGroup[group])[sprite];
	SDL_Rect pos;
	pos.x= x;
	pos.y= y;
	pos.h= obj->h;
	pos.w= obj->w;

	SDL_BlitSurface( obj, NULL, m_mainWnd, &pos );

}

//����һ��Sprite�����ڣ���ת�����ţ�
void Graph::Draw( int group, int sprite, int x, int y, double angle, double zoom )
{
	SDL_Surface* obj= (*m_spriteGroup[group])[sprite];

	obj= rotozoomSurface( obj, angle, zoom, 1 );
	SDL_Rect pos;
	pos.h= obj->h;
	pos.w= obj->w;
	pos.x= x - pos.w/2;
	pos.y= y - pos.h/2;

	SDL_BlitSurface( obj, NULL, m_mainWnd, &pos );

	SDL_FreeSurface( obj );

}

//����һ��Sprite�����ڣ���͸����ϣ�
void Graph::Draw( int group, int sprite, int x, int y, int alpha )
{
	SDL_Surface* obj= (*m_spriteGroup[group])[sprite];

	SDL_Rect pos;
	pos.x= x;
	pos.y= y;
	pos.w= obj->w;
	pos.h= obj->h;

	SDL_gfxBlitRGBA( obj, NULL, m_mainWnd, &pos );

}

//�õ�ָ��Sprite������
Sprite& Graph::GetSprite( int group, int pos )
{
	return m_spriteGroup[group]->GetSprite( pos );
}

//�����Ѵ���
bool Graph::IsWndExist()
{
	return m_beInit;
}
