#pragma once

class TimeEventFunction
{
public:
	float Time = 0.0f;
	float MaxTime = 0.0f;
	std::function<void()> Event;
	bool IsUpdate = false;
	bool Loop = false;
};

// 설명 : 일정시간동안 실행되는 함수, 일정시간 후에 실행되는 함수를 관리하는 클래스 ( 둘이 조합 가능 )
class UTimeEvent
{
public:
	// constrcuter destructer
	UTimeEvent();
	~UTimeEvent();

	// delete Function
	UTimeEvent(const UTimeEvent& _Other) = delete;
	UTimeEvent(UTimeEvent&& _Other) noexcept = delete;
	UTimeEvent& operator=(const UTimeEvent& _Other) = delete;
	UTimeEvent& operator=(UTimeEvent&& _Other) noexcept = delete;

	void PushEvent(float _Time, std::function<void()> _Function, bool _IsUpdate = false, bool _Loop = false) {
		Events.push_front({ _Time, _Time, _Function, _IsUpdate, _Loop });
	}

	void Update(float _DeltaTime) {
		std::list<TimeEventFunction>::iterator StartIter = Events.begin();
		std::list<TimeEventFunction>::iterator EndIter = Events.end();
		for (; StartIter != EndIter; ) {
			TimeEventFunction& TimeEvent = *StartIter;
			TimeEvent.Time -= _DeltaTime;
			// 일정시간동안 타임이벤트실행
			if (true == TimeEvent.IsUpdate && 0.0f < TimeEvent.Time) {
				TimeEvent.Event();
			}
			//일정시간 후에 타임이벤트 실행
			if (0.0f >= TimeEvent.Time) {
				TimeEvent.Event();

				if (!TimeEvent.Loop) {
					//현재 요소 제거 후 다음요소 리턴
					StartIter = Events.erase(StartIter);
					continue;
				}
				else {
					//루프일경우 타임 초기화
					TimeEvent.Time = TimeEvent.MaxTime;
				}
			}
			++StartIter;
		}
	}

protected:

private:
	std::list<TimeEventFunction> Events;

};

