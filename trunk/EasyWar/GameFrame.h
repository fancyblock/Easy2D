//��Ϸ�����
#pragma once

#include <map>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Graph.h"
#include "Input.h"
#include "Sound.h"

using namespace std;

//����λ�õ���Ϣ��¼�ṹ
struct mouserectinfo
{
	int _x1;
	int _y1;
	int _x2;
	int _y2;

	bool _show;

	mouserectinfo():_show( false ){}
};

class Logic;

class  GameFrame
{
public:
	GameFrame();
	~GameFrame();

	void Initial( int wid, int hei, char* wndName= "Demo", char* icon= NULL, bool fullscreen= false );
													//��ʼ��
	void Running();									//������
	void Destroy();									//����
	void Exit();									//ʹ��Ϸ�˳�

	bool AddLogic( string logicName, Logic* task );	//���һ��Logic
	Logic* GetLogic( string logicName );			//ͨ����������ȡĳ��Logic��ָ��
	void EnableMouseRect( int r, int g, int b, int a );
													//��ʾ����
	void DisableMouseRect();						//�ر��������ʾ
	void SetFPS( float fps );						//�趨֡��
	void AutoClear( bool flag );					//ÿ֡�Ƿ��Զ�����
	int Rand();										//����һ�������

protected:
	map<string,Logic*> m_allLogic;					//�洢���е�Logic
	bool m_alive;									//��Ϸ�Ƿ��ڽ���

	Color m_rectColor;								//�������ɫ
	bool m_mouseRect;								//�Ƿ���Ҫ������
	mouserectinfo m_rectInfo;						//�����Ϣ�����������

	unsigned int m_timePerFrame;					//ÿ֡�ĺ�ʱ�����룩
	unsigned int m_time;							//��ϷӦ�ý��е�ʱ�䣨���룩
	bool m_autoClear;								//������־

protected:
	void updateMouseRect();							//��������

	//�����ô���
#ifdef _DEBUG

#define COUNT_TIME_INTERVAL		5000				//ͳ��һ��FPS�ļ��ʱ��
	int md_frames;
	unsigned int md_lastTime;

#endif

};


//ָ��ת���ĺ�
#define GAME_FRAME( x )	((GameFrame*)x)
