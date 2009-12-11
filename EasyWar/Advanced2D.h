#pragma once
#include "Graph.h"
#include "Animation.h"
#include "Logic.h"

enum{  eLevelBottom = 0, eLevelMid,  eLevelTop, eMaxLevel };

//��ԭ����Graph���Ͻ���һ���װ���ṩһЩ����
class Advanced2D : public Logic
{
public:
	Advanced2D();
	~Advanced2D();
	virtual void Init( void* host );							//��ʼ��
	virtual void Run( void* host, unsigned int time );			//ÿ֡���У�timeΪ��֡����֡�ĺ�������
	virtual void End( void* host );								//����
	void AddUnit( Unit2D* obj, int level = 0 );					//���һ����Ⱦ����

protected:
	Unit2D* m_2dsLevels[eMaxLevel];								//�洢����Ҫ��Ⱦ��2D���󣨷ֲ㣩����Ⱦ��˳��ͬ��Top���ϣ�Bottom���£�Mid�м�

	Unit2D* m_listTail[eMaxLevel];

};
