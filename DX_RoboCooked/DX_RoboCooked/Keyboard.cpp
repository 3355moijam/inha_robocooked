#include "stdafx.h"
#include "Keyboard.h"


CKeyboard::CKeyboard()
	:m_elapsedTime(0)
	,m_dwPrevKey(0)
{
	m_eKeyState = E_NONE;

	m_stInputKey[0].moveFowardKey = 'W';
	m_stInputKey[0].moveLeftKey = 'A';
	m_stInputKey[0].moveBackKey = 'S';
	m_stInputKey[0].moveRightKey = 'D';
	m_stInputKey[0].interactableKey1 = 'F';
	m_stInputKey[0].interactableKey2 = 'G';
	m_stInputKey[0].interactableKey3 = 'H';

	m_stInputKey[1].moveFowardKey = VK_UP;
	m_stInputKey[1].moveLeftKey = VK_LEFT;
	m_stInputKey[1].moveBackKey = VK_DOWN;
	m_stInputKey[1].moveRightKey = VK_RIGHT;
	m_stInputKey[1].interactableKey1 = VK_OEM_COMMA;
	m_stInputKey[1].interactableKey2 = VK_OEM_PERIOD;
	m_stInputKey[1].interactableKey3 = VK_OEM_2;

	g_EventManager->CallEvent(eEvent::Player1KeyChange, (void*)&m_stInputKey[0]);
	g_EventManager->CallEvent(eEvent::Player2KeyChange, (void*)&m_stInputKey[1]);
}

CKeyboard::~CKeyboard()
{
}

void CKeyboard::Update()
 {
	ST_KeyInputEvent data;

	unordered_set<WPARAM>::iterator it;
	for(it = m_setKey.begin(); it != m_setKey.end(); it++)
	{
		data.wKey = *it;
		//std::cout << *it << std::endl;
		g_EventManager->CallEvent(eEvent::KeyPress, (void*)&data);
	}
}

void CKeyboard::PressKey(WPARAM keyID, LPARAM lParam)
{
	WPARAM new_vk = keyID;
	UINT scancode = (lParam & 0x00ff0000) >> 16;
	int extended = (lParam & 0x01000000) != 0;

	switch (keyID)
	{
	case VK_SHIFT:
		new_vk = MapVirtualKey(scancode, MAPVK_VSC_TO_VK_EX);
		break;

	case VK_PROCESSKEY:
	case VK_HANJA:
		new_vk = extended ? VK_RCONTROL : VK_LCONTROL;
		break;

	case VK_MENU:
		new_vk = extended ? VK_RMENU : VK_LMENU;
		break;
	default:
		new_vk = keyID;
		break;
	}

	m_setKey.insert(new_vk);
	m_dwPrevKey = new_vk;
	m_eKeyState = E_BTNDOWN;

	/*while (m_eKeyState == E_BTNDOWN)
	{
		DWORD currentTime = GetTickCount();

		if (currentTime - m_elapsedTime < 500 && keyID == m_dwPrevKey && m_eKeyState == E_BTNUP)
		{
			std::cout << "Ȧ��" << std::endl;
			m_eKeyState = E_HOLD;
		}
		m_elapsedTime = GetTickCount();
	}*/
}

void CKeyboard::ReleaseKey(WPARAM keyID, LPARAM lParam)
{
	WPARAM new_vk = keyID;
	UINT scancode = (lParam & 0x00ff0000) >> 16;
	int extended = (lParam & 0x01000000) != 0;

	switch (keyID)
	{
	case VK_SHIFT:
		new_vk = MapVirtualKey(scancode, MAPVK_VSC_TO_VK_EX);
		break;
		
	case VK_PROCESSKEY:
	case VK_HANJA:
		new_vk = extended ? VK_RCONTROL : VK_LCONTROL;
		break;
		
	case VK_MENU:
		new_vk = extended ? VK_RMENU : VK_LMENU;
		break;
	default:
		new_vk = keyID;
		break;
	}

	m_setKey.erase(new_vk);
	m_eKeyState = E_BTNUP;
	g_EventManager->CallEvent(eEvent::KeyRelease, NULL);
}

void CKeyboard::OnEvent(eEvent eEvent, void* _value)
{
	switch (eEvent)
	{
	case eEvent::Player1KeyChange:
		SetKeyChange(1, _value);
		break;
	case eEvent::Player2KeyChange:
		SetKeyChange(2, _value);
		break;
	}
}

void CKeyboard::SetKeyChange(int n, void* _value)
{
	ST_PLAYER_INPUTKEY *data = static_cast<ST_PLAYER_INPUTKEY*>(_value);
	m_stInputKey[n - 1] = *data;
}

//void CKeyboard::JudgeDash(WPARAM keyID)
//{
//	DWORD currentTime = GetTickCount();
//
//	if (currentTime - m_elapsedTime < 500 && keyID == m_dwPrevKey && m_eKeyState == E_BTNUP)
//	{
//		std::cout << "�뽬" << std::endl;
//		m_eKeyState = E_DBLDOWN;
//	}
//	m_elapsedTime = GetTickCount();
//}