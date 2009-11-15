#include "stdafx.h"
#include "GameFrame.h"
#include "Logic.h"

GameFrame::GameFrame()
{
	m_alive = true;
	m_mouseRect= false;
	m_timePerFrame= 0;
	m_autoClear= false;
}

GameFrame::~GameFrame()
{
}

//��ʼ��
void GameFrame::Initial( int wid, int hei, char* wndName, char* icon, bool fullscreen )
{
	//��ʼ��SDL��
	SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER );
	//���ô���ͼ��
	SDL_WM_SetIcon(SDL_LoadBMP( icon ), NULL);
	//��������
	DRAW.CreateWnd( wid, hei, fullscreen );
	//���ô���Caption
	SDL_WM_SetCaption( wndName, NULL );
	//ʱ���ʼ��
	m_time= SDL_GetTicks();
	//����ϵͳ��ʼ��
	SND.InitDevice();
	//�������������ʼ��
	srand( (unsigned int)time(0) );

#ifdef _DEBUG
	md_frames= 0;
	md_lastTime= 0;
#endif

}

//��Ҫ�ĵ��Ȳ���
void GameFrame::Running()
{
	while( m_alive )
	{
		//����֡����
		unsigned int nowTime= SDL_GetTicks();			//�õ��������е���ǰ�������ĺ�����
		unsigned int ticks= nowTime - m_time;			//

		if( ticks < m_timePerFrame )
		{
			SDL_Delay( 0 );
			continue;
		}
		m_time+= m_timePerFrame;

		//������Ϣ��Ҫÿ֡����
		Input::Update();

		//�����˳�
		if( Input::Quit() || Input::KeyDown(ESC) )		//��Ϸ�˳������ڱ��رգ�
		{
			break;
		}

		map<string,Logic*>::iterator logic;
		vector<map<string,Logic*>::iterator> corpse;	//���ڴ洢������Logic�ĵ�����

		if( m_autoClear )
		{
			DRAW.ClearWnd( 0, 0, 0 );
		}

		//����������Logic
		for( logic = m_allLogic.begin() ; logic != m_allLogic.end() ; logic++ )
		{
			logic->second->Update( ticks );
			if( logic->second->Dead() )					//�����Logic��������ɾ����Logic
			{
				delete logic->second;
				corpse.push_back( logic );
			}
		}

		//�����������Logic��ʬ��
		for( unsigned int i(0); i< corpse.size(); i++ )
		{
			m_allLogic.erase( corpse[i] );
		}

		corpse.clear();

		updateMouseRect();								//�������

		DRAW.Flush();									//��Ļ����Ľ���������ͳһ����

#ifdef _DEBUG	//������֡���������console��
		md_frames++;
		unsigned int countTime= nowTime - md_lastTime;
		if( countTime > COUNT_TIME_INTERVAL )
		{
			md_lastTime= nowTime;
			printf( "FPS: %.2f\n", (float)md_frames / ((float)countTime * 0.001f ) );
			md_frames= 0;
		}
#endif

	}

}

//��Ϸ����
void GameFrame::Destroy()
{
	//�������Logic
	map<string,Logic*>::iterator logic;
	for( logic = m_allLogic.begin() ; logic != m_allLogic.end() ; logic++ )
	{
		delete logic->second;
	}
	m_allLogic.clear();
	//����graph
	DRAW.Destory();
	//����sound
	SND.Destroy();
	//SDL��ֹ
	SDL_Quit();
}

//���һ��Logic
bool GameFrame::AddLogic( string logicName, Logic* task )
{
	if( task )								//�����ָ��Ĵ���
	{
		map<string,Logic*>::iterator logic;

		logic = m_allLogic.find( logicName );

		if( logic == m_allLogic.end() )		//����Logic�����ظ�
		{
			task->SetHost( (void*)this );
			m_allLogic[logicName] = task;
			return true;
		}

	}

	return false;
}

//ͨ����������ȡĳ��Logic��ָ��
Logic* GameFrame::GetLogic( string logicName )
{
	map<string,Logic*>::iterator logic;

	logic = m_allLogic.find( logicName );

	if( logic != m_allLogic.end() )
	{
		return m_allLogic[logicName];
	}

	return NULL;

}

//�˳���Ϸ
void GameFrame::Exit()
{
	m_alive = false;
}

//��ʾ����
void GameFrame::EnableMouseRect( int r, int g, int b, int a)
{
	m_rectColor._r= r;
	m_rectColor._g= g;
	m_rectColor._b= b;
	m_rectColor._a= a;

	m_mouseRect= true;

}

//�ر��������ʾ
void GameFrame::DisableMouseRect()
{
	m_mouseRect= false;
}

//��������
void GameFrame::updateMouseRect()
{
	if( !m_mouseRect )				//����û������
	{
		return;
	}

	if( m_rectInfo._show )
	{
		m_rectInfo._x2= Input::Xpos();
		m_rectInfo._y2= Input::Ypos();
		
		DRAW.DrawRect( m_rectInfo._x1, m_rectInfo._y1, m_rectInfo._x2, m_rectInfo._y2,
						  m_rectColor._r, m_rectColor._g, m_rectColor._b, m_rectColor._a );
	}

	if( Input::LButtonEvent() == eMouseDown )
	{
		m_rectInfo._show= true;
		m_rectInfo._x1= m_rectInfo._x2= Input::Xpos();
		m_rectInfo._y1= m_rectInfo._y2= Input::Ypos();
	}else if( Input::LButtonEvent() == eMouseUp )
	{
		m_rectInfo._show= false;
	}

}

//�趨֡��
void GameFrame::SetFPS( float fps )
{
	m_timePerFrame= int( ( 1.0f / fps ) * 1000.0f );
}

//ÿ֡�Ƿ��Զ�����
void GameFrame::AutoClear( bool flag )
{
	m_autoClear= flag;
}

//����һ�������
int GameFrame::Rand()
{
	return rand();
}
