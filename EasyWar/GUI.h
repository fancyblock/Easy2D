#pragma once
#include "Graph.h"
#include "Input.h"
#include "Logic.h"
#include <vector>

using namespace std;


//�򵥵�GUIϵͳ��
class GUI : public Logic
{
public:
	GUI(void);
	~GUI(void);
	virtual void Init( void* host );							//��ʼ��
	virtual void Run( void* host, unsigned int time );			//ÿ֡���У�timeΪ��֡����֡�ĺ�������
	virtual void End( void* host );								//����

protected:
	;

};
