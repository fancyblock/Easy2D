#pragma once
#include <vector>

using namespace std;

#define MAX_CHANNEL	4


//���������Ĳ���
class Sound
{
public:
	~Sound();
	static Sound* GetSingle();							//��ȡ����
	bool InitDevice();									//��ʼ����Ƶ�豸
	void Destroy();										//�ݻٺ���
	int LoadSE( const char* fileName );					//����һ����Ч����
	int LoadBGM( const char* fileName );				//����һ����������
	void PlaySE( int num, int loop = 0 );				//������Ч
	void PlayBGM( int num, int loop = -1 );				//���ű�������
	void StopBGM();										//��ͣBGM�Ĳ���
	void StopSE();										//��ͣSE�Ĳ���
	void FreeAllSE();									//�ͷ����е�SE
	void FreeAllBGM();									//�ͷ����е�BGM

protected:
	Sound();

protected:
	static Sound* m_me;									//����ָ�򱾶����Ψһ������ָ��

	vector<Mix_Chunk*> m_allSE;							//�������е���Ч����SE
	vector<Mix_Music*> m_allBGM;						//�������еı�������BGM

	int m_curChannel;									//��ǰ����ͨ��

};

#define SND	(*Sound::GetSingle())
