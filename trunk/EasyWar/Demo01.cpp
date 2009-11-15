#include "stdafx.h"
#include "Demo01.h"

#define ANI_SPEED	50

void Demo01::Init( void* host )
{
	//̹�˵ĳ�ʼλ�úͷ���
	m_x= 0;
	m_y= 0;
	m_dir= m_nextDir= eDirRight;

	//����̹�˸�������Ķ���
	m_tank[eDirUp].CreateAniAuto( "TankUp.png", 7, 1, 7 );
	m_tank[eDirUp].SetFrameTime( ANI_SPEED );
	m_tank[eDirDown].CreateAniAuto( "TankDown.png", 7, 1, 7 );
	m_tank[eDirDown].SetFrameTime( ANI_SPEED );
	m_tank[eDirLeft].CreateAniAuto( "TankLeft.png", 1, 7, 7 );
	m_tank[eDirLeft].SetFrameTime( ANI_SPEED );
	m_tank[eDirRight].CreateAniAuto( "TankRight.png", 1, 7, 7 );
	m_tank[eDirRight].SetFrameTime( ANI_SPEED );

	//��������ӵ�Advance2D
	ADVANCE_FRAME( host )->ADRAW()->AddUnit( &m_tank[eDirUp], eLevelTop );
	ADVANCE_FRAME( host )->ADRAW()->AddUnit( &m_tank[eDirDown], eLevelTop );
	ADVANCE_FRAME( host )->ADRAW()->AddUnit( &m_tank[eDirLeft], eLevelTop );
	ADVANCE_FRAME( host )->ADRAW()->AddUnit( &m_tank[eDirRight], eLevelTop );

	//ת����
	m_sndId= SND.LoadSE( "turn.wav" );

	m_tank[m_dir].SetPos( m_x, m_y );
	m_tank[m_dir].Play( 0 );

}

void Demo01::Run( void* host, unsigned int time  )
{
	if( Input::KeyDown( UP ) )
	{
		m_y--;
		m_nextDir= eDirUp;
	}else if( Input::KeyDown( DOWN ) )
	{
		m_y++;
		m_nextDir= eDirDown;
	}else if( Input::KeyDown( LEFT ) )
	{
		m_x--;
		m_nextDir= eDirLeft;
	}else if( Input::KeyDown( RIGHT ) )
	{
		m_x++;
		m_nextDir= eDirRight;
	}

	//̹�˷���ı䣬��������
	if( m_dir != m_nextDir )
	{
		m_dir= m_nextDir;
//		SND.PlaySE( m_sndId );

		for( int i(0); i< 4; i++ )
		{
			if( i == m_dir )
			{
				m_tank[i].Play( 0 );
			}else
			{
				m_tank[i].Stop();
			}
		}
	}

	//����λ�øı�
	m_tank[m_dir].SetPos( m_x, m_y );
	
}

void Demo01::End( void* host )
{
}
