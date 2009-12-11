//һ��Logic��һ������λ
//�̳�Logic��������غ����������Լ�������
#pragma once
#include <queue>
#include "GameFrame.h"

using namespace std;

//Logic״̬ö��
enum{ eLogicInit, eLogicRun, eLogicEnd, eLogicDead, eLogicPause, eLogicSleep };

//Logic��Ϣ�ṹ
struct sLogicMsg
{
	int ID;
	void* data;
};

//Logic��
class Logic
{
friend class GameFrame;

public:
	Logic();
	~Logic();

	bool Dead();								//��Logic�Ƿ���������GameFrame�������������Logic��
	void Exit();								//������Logic������
	void Pause();								//��ͣ��Logic������
	void Resume();								//�ָ���Logic������
	void SendMessage( int ID, void* data );		//������Ϣ������Logicͨ�ţ���һ��Logic������һ����

	//[�������������뱻����]
	virtual void Init( void* host ) = 0;		//��ʼ��
	virtual void Run( void* host, unsigned int time ) = 0;	
												//ÿ֡���У�timeΪ��֡����֡�ĺ�������
	virtual void Sleep( void* host );			//����ͣʱ������һ��
	virtual void Awake( void* host );			//����ʱ������һ��
	virtual void End( void* host ) = 0;			//����

private:
	int m_LogicState;							//��ǰLogic��״̬
	int m_LastState;							//����ʱLogic��״̬
	void* m_host;								//ָ��Logic������ָ��
	queue<sLogicMsg> m_msg;						//��Logic����Ϣ����

private:
	void Update( unsigned int time );			//����
	void SetHost( void* host );					//��������
	bool GetMessage( sLogicMsg* msg );			//��ȡ��Ϣ������ȡ����Ϣ����Ϣ�������Զ�ɾ����

};
