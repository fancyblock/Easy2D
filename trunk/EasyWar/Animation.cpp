#include "stdafx.h"
#include "Animation.h"
#include "Graph.h"


Animation::Animation()
{
	m_frameCount= 0;
	m_currFrame= 0;
	m_groupNum= -1;
	m_loop= 0;
	m_frameInterval= 0;
	m_timer= 0;
	m_state= eAniStop;
}

Animation::~Animation()
{
}

//���º���
void Animation::Update( unsigned int time )
{
	if( m_state == eAniPlaying )
	{
		DRAW.Draw( m_groupNum, m_currFrame, m_pos._x, m_pos._y );

		//ʱ�䵽��û�֡��ʱ��
		if( m_timer >= m_frameInterval )
		{
			m_timer= 0;
			m_currFrame++;
			if( m_currFrame >= m_frameCount )			//һ�ζ���������
			{
				m_currFrame= 0;
				m_loop--;
				if( m_loop == 0 )						//������ϣ����Ŵ���������
				{
					m_state= eAniStop;
				}else if( m_loop < 0 )					//����ѭ�����ŵĶ���
				{
					m_loop= 0;
				}
			}
		}
		m_timer+= time;
	}else if( m_state == eAniPause )
	{
		DRAW.Draw( m_groupNum, m_currFrame, m_pos._x, m_pos._y );
	}

}

//���ö�����֡��
void Animation::SetFrameCount( int count )
{
	//����ͼ���飬�������
	m_groupNum=	DRAW.AddSpriteGroup( count );
	//��֡��
	m_frameCount= count;

}

//����ĳһ֡��ͼ��
void Animation::SetFrame( int index, char* fileName, Rect& clip )
{
	if( index < 0 || index >= m_frameCount || m_groupNum < 0 )
	{
		return;
	}

	DRAW.AddSprite( m_groupNum, index, fileName );
	DRAW.GetSprite( m_groupNum, index ).Clip( clip );

}

//���ţ�0Ϊ����ѭ�����ţ�
void Animation::Play( int loop )
{
	m_currFrame= 0;
	m_loop= loop;
	m_state= eAniPlaying;
	m_timer= 0;
}

//ֹͣ����
void Animation::Stop()
{
	m_state= eAniStop;
}

//����ÿ֡�ļ��ʱ��
void Animation::SetFrameTime( unsigned int interval )
{
	m_frameInterval= interval;
}

//�����ض�ͼƬ����ʽ�Զ�����һ���������У���������Ϊʵ��֡��������������������Ϊ֡��
void Animation::CreateAniAuto( char* fileName, int wid, int hei, int count )
{
	SetFrameCount( count );

	int cnts= 0;
	float u1, v1, u2, v2;
	float uW= 1.0f / (float)wid;
	float vH= 1.0f / (float)hei;

	for( int i(0); i< hei; i++ )
	{
		for( int j(0); j< wid; j++ )
		{
			DRAW.AddSprite( m_groupNum, cnts, fileName );
			u1= j * uW;
			v1= i * vH;
			u2= u1 + uW;
			v2= v1 + vH;
			DRAW.GetSprite( m_groupNum, cnts ).Clip( u1, v1, u2, v2 );

			cnts++;
			if( cnts >= count )
			{
				return;
			}
		}
	}

}

//����Ŀ��ĸ���
void Animation::Duplicate( Animation& orgAni )
{
	m_groupNum= orgAni.m_groupNum;
	m_frameCount= orgAni.m_frameCount;
	m_frameInterval= orgAni.m_frameInterval;

}

//��ͣ���ţ�����ʾ��
void Animation::Pause( int frame )
{
	m_state= eAniPause;
	m_currFrame= frame;

}
