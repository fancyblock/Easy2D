#pragma once
#include "Logic.h"
#include "AdvancedFrame.h"
#include "Demo02.h"

//����
enum{ eDirUp= 0, eDirDown, eDirLeft, eDirRight };


//[Demo01]�����������ҿ���һ��̹��������ȥ������һЩUI������
class Demo01 : public Logic
{
	friend class mouseEvt;
public:

	virtual void Init( void* host );					//��ʼ��
	virtual void Run( void* host, unsigned int time  );	//ÿ֡����
	virtual void End( void* host );						//����
	virtual void Sleep( void* host );					//��ͣʱִ��һ��
	
private:
	Animation m_tank[4];								//̹�˶�����
	Animation m_bg;										//����

	int m_x;											//λ��
	int m_y;
	int m_dir;											//����
	int m_nextDir;										//�´�һҪת�ķ���
	int m_sndId;										//������ID

	void* m_host;

	gcn::Gui m_gui;
	gcn::SDLGraphics m_guiGraph;
	gcn::SDLInput m_guiInput;
	gcn::Container m_guiContainer;
	gcn::Button m_button;
	gcn::ImageButton m_imgButton;
	gcn::Icon m_icon;
	gcn::SDLImage* m_butImg;
	gcn::SDLImage* m_iconImg;
	gcn::SDLImageLoader m_sdlImgLoader;
	gcn::Window m_wnd;
	gcn::CheckBox m_check;

	bool m_iconVisable;

	gcn::MouseListener* m_evtListener;

};


//�¼�������
class mouseEvt: public gcn::MouseListener
{
public:
	virtual void mousePressed( gcn::MouseEvent& mouseEvent )
	{
		string widgetID = mouseEvent.getSource()->getId();

		//�ж����ĸ��������µ�
		if( widgetID == "bt1" )
		{
			ADVANCE_FRAME( m_entity->m_host )->AddLogic( "Demo02", CREATE_LOGIC(Demo02) );
			m_entity->Pause();
//			m_entity->Exit();

		}else if( widgetID == "bt2" )
		{
			m_entity->m_check.setSelected( true );
		}
	}
	
	void SetEntity( Demo01* entity )
	{
		m_entity = entity;
	}

protected:
	Demo01* m_entity;

};