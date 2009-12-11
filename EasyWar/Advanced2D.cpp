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
	for( int i = eLevelBottom; i < eMaxLevel; i++ )
	{
		m_2dsLevels[i] = new Unit2D();
		m_2dsLevels[i]->SetHead();
		m_listTail[i] = m_2dsLevels[i];
	}
}

//ÿ֡���У�timeΪ��֡����֡�ĺ�������
void Advanced2D::Run( void* host, unsigned int time )
{
	Unit2D* point;

	for( int i = eLevelBottom; i < eMaxLevel; i++ )
	{
		point = m_2dsLevels[i]->m_next;
		while( point )
		{
			point->Update( time );
			point = point->m_next;
		}
	}
}

//����
void Advanced2D::End( void* host )
{
	for( int i = eLevelBottom; i < eMaxLevel; i++ )
	{
		delete m_2dsLevels[i];
	}
}

//���һ����Ⱦ����ָ�������Ⱦ�б�
void Advanced2D::AddUnit( Unit2D* obj, int level )
{
	m_listTail[level]->SetNext( obj );
	obj->SetPrior( m_listTail[level] );
	m_listTail[level] = obj;
	m_listTail[level]->SetNext( NULL );

}
