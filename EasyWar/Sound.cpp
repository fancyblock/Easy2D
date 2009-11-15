#include "stdafx.h"
#include "Sound.h"

Sound* Sound::m_me= NULL;


Sound::Sound()
{
}

Sound::~Sound()
{
}

//��ȡ����ĵ���
Sound* Sound::GetSingle()
{
	if( m_me == NULL )
	{
		m_me= new Sound();
	}

	return m_me;
}

//�ݻٺ���
void Sound::Destroy()
{
	if( m_me )
	{
		Mix_CloseAudio();

		FreeAllSE();
		FreeAllBGM();

		delete m_me;
		m_me= NULL;
	}

}

//��ʼ����Ƶ�豸
bool Sound::InitDevice()
{
	int TMP_FREQ= MIX_DEFAULT_FREQUENCY;
	Uint16 TMP_FORMAT= MIX_DEFAULT_FORMAT;
	int TMP_CHUNK_SIZE= 512;

	//4ͨ������
	int result=	Mix_OpenAudio(TMP_FREQ,TMP_FORMAT,MAX_CHANNEL,TMP_CHUNK_SIZE);

	m_curChannel= 0;

	return result == 1 ? true : false;
}

//�ͷ����е�SE
void Sound::FreeAllSE()
{
	size_t len= m_allSE.size();

	for( size_t i(0); i< len; i++ )
	{
		Mix_FreeChunk( m_allSE[i] );
	}

	m_allSE.clear();
}

//�ͷ����е�BGM
void Sound::FreeAllBGM()
{
	size_t len= m_allBGM.size();

	for( size_t i(0); i< len; i++ )
	{
		Mix_FreeMusic( m_allBGM[i] );
	}

	m_allBGM.clear();
}

//������Ч
void Sound::PlaySE( int num, int loop )
{
	Mix_PlayChannel( m_curChannel++, m_allSE[num], loop );

	if( m_curChannel >= MAX_CHANNEL )
	{
		m_curChannel= 0;
	}
}

//���ű�������
void Sound::PlayBGM( int num, int loop )
{
	Mix_PlayMusic( m_allBGM[num], loop );
}

//����һ����Ч����
int Sound::LoadSE( const char* fileName )
{
	Mix_Chunk* music;

	music= Mix_LoadWAV( fileName );

	//����ʧ��
	if( music == NULL )
	{
		return -1;
	}

	m_allSE.push_back( music );

	return (int)m_allSE.size() - 1;
}

//����һ����������
int Sound::LoadBGM( const char* fileName )
{
	Mix_Music* music;

	music= Mix_LoadMUS( fileName );

	//����ʧ��
	if( music == NULL )
	{
		return -1;
	}

	m_allBGM.push_back( music );

	return (int)m_allBGM.size() - 1;
}

//��ͣBGM�Ĳ���
void Sound::StopBGM()
{
	Mix_FadeOutMusic( 1000 );
}

//��ͣSE�Ĳ���
void Sound::StopSE()
{
	Mix_FadeOutChannel( 0, 0 );
	Mix_FadeOutChannel( 1, 0 );
	Mix_FadeOutChannel( 2, 0 );
	Mix_FadeOutChannel( 3, 0 );
}
