#pragma once
#include "Logic.h"
#include "AdvancedFrame.h"

class Demo02 : public Logic
{
public:

	virtual void Init( void* host );					//��ʼ��
	virtual void Run( void* host, unsigned int time  );	//ÿ֡����
	virtual void End( void* host );						//����

private:


};
