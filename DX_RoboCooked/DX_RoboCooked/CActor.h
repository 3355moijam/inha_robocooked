#pragma once
class CActor
{
public:
	CActor();
	virtual  ~CActor();

protected:
	D3DXMATRIXA16 m_matS;
	D3DXMATRIXA16 m_matR;
	D3DXMATRIXA16 m_matT;
	//�ݶ��̴� ���߰�

public:
	virtual void Render() = 0;
	virtual void Update() = 0;
	
};

