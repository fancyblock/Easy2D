#pragma once
#include "Graph.h"
#include "Animation.h"
#include "Logic.h"
#include <list>

using namespace std;

enum{ eLevelTop = 0, eLevelMid, eLevelBottom };

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
	list<Unit2D*> m_2dsTop;										//�洢����Ҫ��Ⱦ��2D���󣨷ֲ㣩
	list<Unit2D*> m_2dsMid;										//��Ⱦ��˳��ͬ
	list<Unit2D*> m_2dsBottom;									//Top���ϣ�Bottom���£�Mid�м�

};
