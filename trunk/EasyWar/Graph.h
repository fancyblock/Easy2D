#pragma once

#include <list>
#include <map>
#include <vector>
#include "SpriteGroup.h"

using namespace std;


//ͼ����
class Graph
{
public:
	~Graph();
	void Destory();								//���٣�������ڵĻ���
	bool IsWndExist();							//�����Ѵ���
	void CreateWnd( int wid, int hei, bool fullscreen= false );
												//����ָ����ߴ���һ������
	static Graph* GetSingle();					//��ȡ����ĵ���
	int AddSpriteGroup( int size );				//���һ��SpriteGroup�飨���ظ����������
	bool AddSprite( int group, int pos, const char* filename );
												//��ָ��SpriteGroup�����Sprite
	Sprite& GetSprite( int group, int pos );	//�õ�ָ��Sprite������
	void ClearAllSpriteGroup();					//������е�SpriteGroup

	void Flush();								//ÿ��ͼ�����������ô�
	void ClearWnd( int r, int g, int b );		//��ָ����ɫ���������ܺ�ʱ�䡿
	void DrawRect( int x1, int y1, int x2, int y2, int r, int g, int b, int a );
												//����ĳЩ�ض��ĵط����ܻ��õ���
	void Draw( int group, int sprite, int x, int y );
												//����һ��Sprite�����ڣ���ͨ��
	void Draw( int group, int sprite, int x, int y, double angle, double zoom );
												//����һ��Sprite�����ڣ���ת�����ţ�
	void Draw( int group, int sprite, int x, int y, int alpha );
												//����һ��Sprite�����ڣ���͸����ϣ����������⡿

protected:
	Graph();

protected:
	static Graph* m_me;							//����ָ����Ψһ�����ָ��
	int m_wndWid;								//���ڵĿ�
	int m_wndHei;								//���ڵĸ�
	bool m_beInit;								//�ѱ���ʼ�����������˴��ڣ�

	SDL_Surface* m_mainWnd;						//������
	vector<SpriteGroup*> m_spriteGroup;			//���е�SpriteGroup��

};

#define DRAW (*Graph::GetSingle())
