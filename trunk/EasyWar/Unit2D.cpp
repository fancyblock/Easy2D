#include "stdafx.h"
#include "Unit2D.h"

Unit2D::Unit2D()
{
	m_head = false;
	m_prior = NULL;
	m_next = NULL;
}

Unit2D::~Unit2D()
{
}

//���º���
void Unit2D::Update( unsigned int time )
{
}

//���룬�Զ���Advance2D����Ⱦ�б��б��޳�
void Unit2D::Leave()
{
	if( m_prior )
	{
		m_prior->m_next = m_next;
	}
	if( m_next )
	{
		m_next->m_prior = m_prior;
	}
}

//����λ��
void Unit2D::SetPos( int x, int y )
{
	m_pos._x = x;
	m_pos._y = y;
}

//����Ϊͷ��Ԫ����Ч��
void Unit2D::SetHead()
{
	m_head = true;
	m_prior = NULL;
	m_next = NULL;
}

//����ǰһ���ڵ�
void Unit2D::SetPrior( Unit2D* prior )
{
	m_prior = prior;
}

//���ú�һ���ڵ�
void Unit2D::SetNext( Unit2D* next )
{
	m_next = next;
}
