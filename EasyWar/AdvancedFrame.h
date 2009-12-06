#pragma once
#include "GameFrame.h"
#include "Advanced2D.h"


//�̳���ԭ����GameFrame���ṩ���๦��
class AdvancedFrame : public GameFrame
{
public:
	AdvancedFrame();
	~AdvancedFrame();
	void Initial( int wid, int hei, char* wndName = "Demo", char* icon = NULL, bool fullscreen = false );
													//��ʼ��
	void Destroy();									//����
	Advanced2D* ADRAW(){ return m_adv2d; }			//�õ�ָ��Advanced2D�����ָ�루����ͼ�β�����

protected:
	Advanced2D* m_adv2d;							//Advanced2D�����ָ�루ֻ��һ����

};


#define ADVANCE_FRAME( x ) ((AdvancedFrame*)x)		//ָ��ת���ĺ�
