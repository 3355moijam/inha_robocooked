﻿#include "stdafx.h"
#include "CTestPhysics.h"
#include "CActor.h"

//void CTestPhysics::ApplyPhysics(CActor* pA, CActor* pB)
//{
//	ApplyGravity(pA);
//	ApplyBound(pA, pB);
//}

void CTestPhysics::ApplyGravity(CActor* pA)
{
	return;
	D3DXVECTOR3 gravity(0, -0.01f, 0);
	pA->AddForce(gravity);
}

void CTestPhysics::ApplyBound(CActor* pA, CActor* pB)
{
	D3DXVECTOR3 vNormal(0, 0, 0);
	if (pA->Collide(pB, &vNormal))
	{
		// 마찰력 = -1 * 마찰계수 * 수직항력 * Normalization(velocity)
		// 수직항력 = vNormal * dot(vNormal, -velocity)
		//D3DXVECTOR3 vNormalForce = vNormal * 0.02;
		// 노멀과 방향의 각도가 같으면 생략
		float power = -D3DXVec3Dot(&vNormal, &pA->GetAcceleration());
		D3DXVECTOR3 vNormalForce;
		if (power > 0)
		{
			vNormalForce = vNormal * power; // 임시. 나중에 가속도를 속도로 바꿔야함.
			pA->AddForce(vNormalForce);
		}
		
		D3DXVECTOR3 vTempVelocity = pA->GetVelocity() + pA->GetAcceleration();
		_DEBUG_COMMENT cout << "vNormal : " << vNormal.x << ", " << vNormal.y << ", " << vNormal.z << endl;
		_DEBUG_COMMENT cout << "vNormalForce : " << vNormalForce.x << ", " << vNormalForce.y << ", " << vNormalForce.z << endl;
		//D3DXVECTOR3 vNormalForce = vNormal * (D3DXVec3Dot(&vNormal, &vTempVelocity) * -1.f);
		vTempVelocity = pA->GetVelocity() + pA->GetAcceleration();
		vTempVelocity *= -0.02f;
		//D3DXVECTOR3 vMinusVelocity;
		//D3DXVec3Normalize(&vMinusVelocity, &pA->GetVelocity());
		//D3DXVec3Normalize(&vMinusVelocity, &pA->GetAcceleration());
		//vMinusVelocity *= -1 * 0.02f;
		//pA->AddForce(vTempVelocity);
	}
}
