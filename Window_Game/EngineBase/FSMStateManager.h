#pragma once
#include "EngineDebug.h"

// 설명 : 상태 기계(FSM)를 관리하는 클래스
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

	// FSMState 클래스: 각 상태의 시작, 업데이트, 종료 기능을 정의
	class FSMState
	{
	public:
		std::function<void()> StartFunction = nullptr;
		std::function<void(float)> UpdateFunction = nullptr;
		std::function<void()> EndFunction = nullptr;
	};

	// 상태 생성 함수 템플릿 
	template<typename EnumType>
	void CreateState(EnumType _Key, std::function<void(float)> _UpdateFunction, std::function<void()> _StartFunction = nullptr)
	{
		CreateState(static_cast<int>(_Key), _UpdateFunction, _StartFunction);
	}

	void CreateState(int _Key, std::function<void(float)> _UpdateFunction, std::function<void()> _StartFunction = nullptr)
	{
		if (true == States.contains(_Key))
		{
			MSGASSERT("이미 존재하는 스테이트를 또 만들려고 했습니다.");
			return;
		}
		States[_Key].UpdateFunction = _UpdateFunction;
		States[_Key].StartFunction = _StartFunction;
	}

	void Update(float _DeltaTime)
	{
		if (nullptr == CurState)
		{
			MSGASSERT("상태가 지정되지 않은 스테이트머신 입니다.");
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
			MSGASSERT("만든적이 없는 스테이트로 체인지 하려고 했습니다.");
			return;
		}
		// 현재 상태를 새로운 상태로 변경
		CurState = &States[_Key];
		// 새로운 상태의 StartFunction이 존재하면 호출
		if (nullptr != CurState->StartFunction)
		{
			CurState->StartFunction();
		}
	}

protected:

private:
	// 현재 상태를 가리키는 포인터
	FSMState* CurState = nullptr;
	// 상태들을 저장하는 맵 (정수형 키와 FSMState로 구성)
	std::map<int, FSMState> States;
};

