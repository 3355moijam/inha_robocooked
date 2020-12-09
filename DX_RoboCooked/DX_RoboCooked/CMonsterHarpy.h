#pragma once
#include "CMonster.h"
class CMonsterHarpy :
	public CMonster
{
public:
	CMonsterHarpy(IInteractCenter* pInteractCenter);
	~CMonsterHarpy();

	eSkill FirstSkill() override { return eSkill::KeyRevers; }
	eSkill SecondSkill() override;
	eSkill UltimateSkill() override { return eSkill::SandWind; }

	FLOAT FirstSkillTime() override { return 5.0f; };
	FLOAT SecondSkillTime() override { return 7.0f; };
	FLOAT UltimateSkillTime() override { return 10.0f; };

};

