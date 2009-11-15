#pragma once
#include "Logic.h"
#include "AdvancedFrame.h"

//����
enum{ eDirUp= 0, eDirDown, eDirLeft, eDirRight };

//[Demo01]�����������ҿ���һ��̹��������ȥ
class Demo01 : public Logic
{
public:

	virtual void Init( void* host );					//��ʼ��
	virtual void Run( void* host, unsigned int time  );	//ÿ֡����
	virtual void End( void* host );						//����

private:
	Animation m_tank[4];								//̹�˶�����

	int m_x;											//λ��
	int m_y;
	int m_dir;											//����
	int m_nextDir;										//�´�һҪת�ķ���
	int m_sndId;										//������ID

};
