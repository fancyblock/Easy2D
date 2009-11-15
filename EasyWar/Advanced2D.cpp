#include "stdafx.h"
#include "Advanced2D.h"

Advanced2D::Advanced2D()
{
}

Advanced2D::~Advanced2D()
{
}
//��ʼ��
void Advanced2D::Init( void* host )
{
}

//ÿ֡���У�timeΪ��֡����֡�ĺ�������
void Advanced2D::Run( void* host, unsigned int time )
{
	list<Unit2D*>::iterator unitPt;

	//��Ⱦ�ײ���
	for( unitPt= m_2dsBottom.begin(); unitPt != m_2dsBottom.end(); unitPt++ )
	{
		(*unitPt)->Update( time );
	}

	//��Ⱦ�в�
	for( unitPt= m_2dsMid.begin(); unitPt != m_2dsMid.end(); unitPt++ )
	{
		(*unitPt)->Update( time );
	}

	//��ȾTop��
	for( unitPt= m_2dsTop.begin(); unitPt != m_2dsTop.end(); unitPt++ )
	{
		(*unitPt)->Update( time );
	}

}

//����
void Advanced2D::End( void* host )
{
	m_2dsTop.clear();
	m_2dsMid.clear();
	m_2dsBottom.clear();
}

//���һ����Ⱦ����ָ�������Ⱦ�б�
void Advanced2D::AddUnit( Unit2D* obj, int level )
{
	switch( level )
	{
	case eLevelTop:
		m_2dsTop.push_back( obj );
		break;
	case eLevelMid:
		m_2dsMid.push_back( obj );
		break;
	case eLevelBottom:
		m_2dsBottom.push_back( obj );
		break;
	default:
		break;
	}

}
