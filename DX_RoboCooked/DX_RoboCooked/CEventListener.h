#pragma once
class CEventListener
{

public:
	virtual ~CEventListener();
	virtual bool OnEvent(eEvent eEvent, void* _value) { return true; } // false�� ��ȯ�ϸ� �ش� �̺�Ʈ�� detach�Ѵ�
};

