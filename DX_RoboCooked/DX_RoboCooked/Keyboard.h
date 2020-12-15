#pragma once


class CKeyboard
{
	enum eKeyBoardState { E_NONE, E_BTNDOWN, E_BTNUP, E_DBLDOWN, E_HOLD };
	eKeyBoardState	m_eKeyState;
	DWORD			m_dwPrevKey;
	DWORD			m_elapsedTime;

	std::array<ST_PLAYER_INPUTKEY,2>	m_arrBaseInputKey;
	std::array<ST_PLAYER_INPUTKEY, 2>	m_arrInputKey;
public:
	CKeyboard();
	~CKeyboard();

	std::unordered_set<WPARAM> m_setKey;

	void Update();
	void PressKey(WPARAM keyID, LPARAM lParam);
	void ReleaseKey(WPARAM keyID, LPARAM lParam);
	//void JudgeDash(WPARAM keyID);
	bool OnEvent(eEvent eEvent, void* _value);
	void SetKeyChange(int n, void* _value);		//� �÷��̾��� Ű�� �ٲܰ�����, � ������ �ٲܰ�����
	void Reset();
	ST_PLAYER_INPUTKEY* GetInputKey(int n) { return &m_arrInputKey[n]; }
};
