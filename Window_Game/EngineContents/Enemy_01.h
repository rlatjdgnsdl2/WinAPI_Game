#pragma once
#include "Enemy.h"

//	����:
class AEnemy_01 :public AEnemy
{
public:
	//	constrcuter, destructer
	AEnemy_01();
	virtual ~AEnemy_01();

	//	delete Function
	AEnemy_01(const AEnemy_01& _Other) = delete;
	AEnemy_01(AEnemy_01&& _Other) noexcept = delete;
	AEnemy_01& operator=(const AEnemy_01& _Other) = delete;
	AEnemy_01& operator=(AEnemy_01&& _Other) noexcept = delete;

	

protected:

private:


	// AEnemy��(��) ���� ��ӵ�
	void AnimationSetting() override;

};

