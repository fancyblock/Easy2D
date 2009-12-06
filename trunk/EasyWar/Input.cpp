#include "stdafx.h"
#include "Input.h"


//������̬����
bool Input::m_mouseKeyState[2] = {false, false };
int Input::m_mouseEvent[2] = {eMouseNon, eMouseNon };
int Input::m_mouseX;
int Input::m_mouseY;
Uint8* Input::m_KeyState = NULL;
SDL_Event Input::m_evt;


//�����¼�
void Input::Update()
{
	memset( &m_evt, 0, sizeof(m_evt) );
	SDL_PollEvent( &m_evt );

	//���洦���������
	m_KeyState = SDL_GetKeyState( NULL );

	//���洦���������
	Uint8 mouseKey;
	mouseKey = SDL_GetMouseState( &m_mouseX, &m_mouseY );

	if( mouseKey & SDL_BUTTON(1) )	//�������״̬
	{
		if( m_mouseKeyState[eLButton] )
		{
			m_mouseEvent[eLButton] = eMouseNon;	//��ΰ��£��ϴ�Ҳ���£���ȡ��������¼�
		}else
		{
			m_mouseEvent[eLButton] = eMouseDown;	//��ΰ��£��ϴ�û���£��������������¼�
			m_mouseKeyState[eLButton] = true;
		}
	}else							//���û����״̬
	{
		if( m_mouseKeyState[eLButton] )
		{
			m_mouseEvent[eLButton] = eMouseUp;	//���û���£��ϴΰ��£���������̧���¼�
			m_mouseKeyState[eLButton] = false;
		}else
		{
			m_mouseEvent[eLButton] = eMouseNon;	//���û���£��ϴ�Ҳû���£���ȡ�����̧���¼�
		}
	}

	if( mouseKey & SDL_BUTTON(3) )	//�Ҽ�����״̬
	{
		if( m_mouseKeyState[eRButton] )
		{
			m_mouseEvent[eRButton] = eMouseNon;	//��ΰ��£��ϴ�Ҳ���£���ȡ����갴���¼�
		}else
		{
			m_mouseEvent[eRButton] = eMouseDown;	//��ΰ��£��ϴ�û���£����������갴���¼�
			m_mouseKeyState[eRButton] = true;
		}
	}else
	{
		if( m_mouseKeyState[eRButton] )
		{
			m_mouseEvent[eRButton] = eMouseUp;	//���û���£��ϴΰ��£���������̧���¼�
			m_mouseKeyState[eRButton] = false;
		}else
		{
			m_mouseEvent[eRButton] = eMouseNon;	//���û���£��ϴ�Ҳû���£���ȡ�����̧���¼�
		}
	}
}

//�жϳ����Ƿ��˳�
bool Input::Quit()
{

	if( m_evt.quit.type == SDL_QUIT )
	{
		return true;
	}

	return false;
}
