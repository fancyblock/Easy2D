#include "stdafx.h"
#include "Unit2D.h"

Unit2D::Unit2D()
{
	m_exist= true;
}

Unit2D::~Unit2D()
{
}

//���룬�Զ���Advance2D����Ⱦ�б��б��޳�
void Unit2D::Leave()
{
	m_exist= false;
}

//����λ��
void Unit2D::SetPos( int x, int y )
{
	m_pos._x= x;
	m_pos._y= y;
}
