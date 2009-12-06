#include "stdafx.h"
#include "AdvancedFrame.h"

AdvancedFrame::AdvancedFrame()
{
	m_adv2d = NULL;
}

AdvancedFrame::~AdvancedFrame()
{
}

//��ʼ��
void AdvancedFrame::Initial( int wid, int hei, char* wndName, char* icon, bool fullscreen )
{
	GameFrame::Initial( wid, hei, wndName, icon, fullscreen );

	//��Ӹ߼�2D��Ⱦģ���Logic
	m_adv2d = CREATE_LOGIC( Advanced2D );
	AddLogic( "AdvancedGraph", m_adv2d );

}

//����
void AdvancedFrame::Destroy()
{
	GameFrame::Destroy();

	m_adv2d = NULL;
}
