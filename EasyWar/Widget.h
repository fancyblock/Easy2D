#pragma once


//����GUI�ؼ���Ļ���
class Widget
{
public:
	Widget(void);
	~Widget(void);
	virtual void Update()= 0;
	void SetVisible( bool visible );								//���ÿؼ��Ŀɼ���

protected:
	bool m_visible;

};
