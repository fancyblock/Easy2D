#pragma once
#include "Unit2D.h"

//������״̬ö��
enum{ eAniPlaying, eAniPause, eAniStop };

//2D������
class Animation : public Unit2D
{
public:
	Animation();
	~Animation();
	virtual void Update( unsigned int time );				//���º���
	void SetFrameCount( int count );						//���ö�����֡��-��1��
	void SetFrame( int index, char* fileName, Rect& clip );	//����ĳһ֡��ͼ��-��2��
	void CreateAniAuto( char* fileName, int wid, int hei, int count );
															//����һ��ͼƬ����ʽ�Զ�����һ����������
	void Play( int loop );									//���ţ�0Ϊ����ѭ�����ţ�
	void Stop();											//ֹͣ���ţ�����ʾ��
	void Pause( int frame = 0 );							//��ͣ���ţ�����ʾ��
	void SetFrameTime( unsigned int interval );				//����ÿ֡�ļ��ʱ��
	void Duplicate( Animation& orgAni );					//����Ŀ��ĸ���

protected:
	int m_state;											//����״̬
	int m_currFrame;										//��ǰ֡��
	int m_groupNum;											//ͼ�������
	int m_frameCount;										//֡��
	int m_loop;												//ѭ������
	unsigned int m_frameInterval;							//ÿ֡���ʱ��
	unsigned int m_timer;									//������¼ʱ�䣬���ƶ���֡��

};
