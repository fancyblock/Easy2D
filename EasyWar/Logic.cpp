#include "stdafx.h"
#include "Logic.h"

Logic::Logic()
{
	m_LogicState = eLogicInit;
}

Logic::~Logic()
{
}

//Logic����
void Logic::Update( unsigned int time )
{
	switch( m_LogicState )
	{
	case eLogicInit:	//��ʼ��һ��
		Init( m_host );
		m_LogicState = eLogicRun;
		break;
	case eLogicRun:		//����̬
		Run( m_host, time );
		break;
	case eLogicEnd:		//����һ��
		End( m_host );
		m_LogicState = eLogicDead;
		break;
	case eLogicPause:	//��̬ͣ
		Sleep( m_host );
		m_LogicState = eLogicSleep;
		break;
	case eLogicSleep:	//˯�ߣ���ִ̬ͣ��һ�κ�
	case eLogicDead:	//����̬
	default:
		break;
	}
}

//�ж�Logic�Ƿ�����
bool Logic::Dead()
{
	if( m_LogicState == eLogicDead )
	{
		return true;
	}

	return false;
}

//��ͣLogic
void Logic::Pause()
{
	if( m_LogicState == eLogicDead )	//����Logic�����Ͳ�����ͣ�ˣ�����������������Logic
	{
		return;
	}

	m_LastState = m_LogicState;
	m_LogicState = eLogicPause;
}

//�ָ�Logic������
void Logic::Resume()
{
	m_LogicState = m_LastState;
	Awake( m_host );
}

//�˳�Logic
void Logic::Exit()
{
	m_LogicState = eLogicEnd;
}

//����Logic������
void Logic::SetHost( void* host )
{
	m_host = host;
}

//������Ϣ������Ϣ�洢��Logic��Ϣ������
void Logic::SendMessage( int ID, void* data )
{
	sLogicMsg message;
	
	message.ID = ID;
	message.data = data;

	m_msg.push( message );
}

//��ȡ��Ϣ
bool Logic::GetMessage( sLogicMsg* msg )
{
	if( m_msg.empty() )
	{
		return false;
	}

	msg->ID = m_msg.back().ID;			//��ȡ��Ϣ���������һ����Ϣ
	msg->data = m_msg.back().data;
	m_msg.pop();

	return true;
}

//����ͣʱ������һ��
void Logic::Sleep( void* host )
{
}

//����ʱ������һ��
void Logic::Awake( void* host )
{
}
