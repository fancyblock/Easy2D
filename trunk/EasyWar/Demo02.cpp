#include "stdafx.h"
#include "Demo02.h"

//��ʼ��
void Demo02::Init( void* host )
{
	GAME_FRAME( host )->AutoClear( true );

	int bgmID = SND.LoadBGM("close.wav");

	SND.PlayBGM( bgmID, 0 );
}

//ÿ֡����
void Demo02::Run( void* host, unsigned int time  )
{
	;
}

//����
void Demo02::End( void* host )
{
	;
}
