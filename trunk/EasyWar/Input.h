#pragma once

#define MOUSEDOWN	1
#define MOUSEUP		2

//���ְ�������
#define ESC			SDLK_ESCAPE
#define ENTER		SDLK_RETURN
#define UP			SDLK_UP
#define DOWN		SDLK_DOWN
#define RIGHT		SDLK_RIGHT
#define LEFT		SDLK_LEFT
#define SPACE		SDLK_SPACE


//��갴���õ���һЩö��
enum{ eLButton= 0, eRButton };
enum{ eMouseNon= 0, eMouseDown, eMouseUp };

//��ȡ������ࣨ�ṩ��̬������
class Input
{
public:
	static void Update();				//�����¼�״̬
	static bool Quit();					//�Ƿ����˳��¼�������
	static int LButtonEvent()			//��������¼�
	{
		return m_mouseEvent[eLButton];
	}
	static int RButtonEvent()			//�����Ҽ��¼�
	{
		return m_mouseEvent[eRButton];
	}
	static bool LButtonDown()			//����Ƿ���
	{
		return m_mouseKeyState[eLButton];
	}
	static bool RButtonDown()			//�Ҽ��Ƿ���
	{
		return m_mouseKeyState[eRButton];
	}
	static int Xpos()					//��������X����
	{
		return m_mouseX;
	}
	static int Ypos()					//��������Y����
	{
		return m_mouseY;
	}
	static int KeyDown( int key )		//�ж�ĳ���Ƿ���		//** ����û������Խ��ļ��
	{
		return m_KeyState[key];
	}
	static SDL_Event* _GetEvtStruct()	//�ײ�ӿڣ����Ƽ�ʹ��
	{
		return &m_evt;
	}

protected:
	static bool m_mouseKeyState[2];		//��갴��״̬
	static int m_mouseEvent[2];			//����¼�
	static int m_mouseX;				//���λ��X
	static int m_mouseY;				//���λ��Y
	static Uint8 *m_KeyState;			//����״̬

	static SDL_Event m_evt;				//�¼��ṹ

};


/*
RButton�ĵ����̧���¼��е����⣬�������Σ���֪�����ұ�������⻹��SDL������
�����İ����¼�û����ֻ���˿����жϸü��ǰ��»���̧���
*/