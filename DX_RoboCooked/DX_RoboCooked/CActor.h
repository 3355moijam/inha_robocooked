#pragma once
#include "CEventListener.h"

class ICollisionArea;

class CActor : public CEventListener
{
public:
	CActor();
	virtual  ~CActor();

protected:
	D3DXMATRIXA16 m_matS;
	D3DXMATRIXA16 m_matR;
	D3DXMATRIXA16 m_matT;
	D3DXMATRIXA16 m_matWorld;

	//�ݶ��̴� ���߰�
	ICollisionArea* m_pCollision;
public:
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual bool Collide(CActor* target);

	ICollisionArea* GetCollsion() { return m_pCollision; }
};

