#pragma once
#include "EngineDebug.h"

// ���� : ���� ���(FSM)�� �����ϴ� Ŭ����
class UFSMStateManager
{
public:
	// constrcuter destructer
	UFSMStateManager() {}
	~UFSMStateManager() {}

	// delete Function
	UFSMStateManager(const UFSMStateManager& _Other) = delete;
	UFSMStateManager(UFSMStateManager&& _Other) noexcept = delete;
	UFSMStateManager& operator=(const UFSMStateManager& _Other) = delete;
	UFSMStateManager& operator=(UFSMStateManager&& _Other) noexcept = delete;

	// FSMState Ŭ����: �� ������ ����, ������Ʈ, ���� ����� ����
	class FSMState
	{
	public:
		std::function<void()> StartFunction = nullptr;
		std::function<void(float)> UpdateFunction = nullptr;
		std::function<void()> EndFunction = nullptr;
	};

	// ���� ���� �Լ� ���ø� 
	template<typename EnumType>
	void CreateState(EnumType _Key, std::function<void(float)> _UpdateFunction, std::function<void()> _StartFunction = nullptr)
	{
		CreateState(static_cast<int>(_Key), _UpdateFunction, _StartFunction);
	}

	void CreateState(int _Key, std::function<void(float)> _UpdateFunction, std::function<void()> _StartFunction = nullptr)
	{
		if (true == States.contains(_Key))
		{
			MSGASSERT("�̹� �����ϴ� ������Ʈ�� �� ������� �߽��ϴ�.");
			return;
		}
		States[_Key].UpdateFunction = _UpdateFunction;
		States[_Key].StartFunction = _StartFunction;
	}

	void Update(float _DeltaTime)
	{
		if (nullptr == CurState)
		{
			MSGASSERT("���°� �������� ���� ������Ʈ�ӽ� �Դϴ�.");
			return;
		}
		CurState->UpdateFunction(_DeltaTime);
	}

	template<typename EnumType>
	void ChangeState(EnumType _Key)
	{
		ChangeState(static_cast<int>(_Key));
	}

	void ChangeState(int _Key)
	{
		if (false == States.contains(_Key))
		{
			MSGASSERT("�������� ���� ������Ʈ�� ü���� �Ϸ��� �߽��ϴ�.");
			return;
		}
		// ���� ���¸� ���ο� ���·� ����
		CurState = &States[_Key];
		// ���ο� ������ StartFunction�� �����ϸ� ȣ��
		if (nullptr != CurState->StartFunction)
		{
			CurState->StartFunction();
		}
	}

protected:

private:
	// ���� ���¸� ����Ű�� ������
	FSMState* CurState = nullptr;
	// ���µ��� �����ϴ� �� (������ Ű�� FSMState�� ����)
	std::map<int, FSMState> States;
};

