#pragma once
#include "BasicUtility.h"


//һ��2D��Ⱦ��Ԫ
class Unit2D
{
public:
	Unit2D();
	~Unit2D();
	virtual void Update( unsigned int time )= 0;				//���º���
	void Leave();												//���룬�Զ���Advance2D����Ⱦ�б��б��޳�
	void SetPos( int x, int y );								//����λ��

protected:
	Point m_pos;												//����Ⱦ��Ԫ��λ��
	bool m_exist;

};
