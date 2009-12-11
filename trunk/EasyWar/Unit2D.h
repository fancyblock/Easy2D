#pragma once
#include "BasicUtility.h"

class Advanced2D;

//һ��2D��Ⱦ��Ԫ
class Unit2D
{
	friend class Advanced2D;

public:
	Unit2D();
	~Unit2D();
	virtual void Update( unsigned int time );					//���º���
	void Leave();												//���룬�Զ���Advance2D����Ⱦ�б��б��޳�
	void SetPos( int x, int y );								//����λ��
	void SetHead();												//����Ϊͷ��Ԫ����Ч��
	void SetPrior( Unit2D* prior );
	void SetNext( Unit2D* next );

protected:
	Point m_pos;												//����Ⱦ��Ԫ��λ��
	bool m_head;

	Unit2D* m_prior;
	Unit2D* m_next;

};
