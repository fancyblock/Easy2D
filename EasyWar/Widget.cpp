#include "StdAfx.h"
#include "Widget.h"

Widget::Widget(void)
{
	m_visible= true;
}

Widget::~Widget(void)
{
}

//���ÿؼ��Ŀɼ���
void Widget::SetVisible( bool visible )
{
	m_visible= visible;
}
