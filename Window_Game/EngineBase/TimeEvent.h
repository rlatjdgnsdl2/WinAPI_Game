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

// ���� : �����ð����� ����Ǵ� �Լ�, �����ð� �Ŀ� ����Ǵ� �Լ��� �����ϴ� Ŭ���� ( ���� ���� ���� )
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
			// �����ð����� Ÿ���̺�Ʈ����
			if (true == TimeEvent.IsUpdate && 0.0f < TimeEvent.Time) {
				TimeEvent.Event();
			}
			//�����ð� �Ŀ� Ÿ���̺�Ʈ ����
			if (0.0f >= TimeEvent.Time) {
				TimeEvent.Event();

				if (!TimeEvent.Loop) {
					//���� ��� ���� �� ������� ����
					StartIter = Events.erase(StartIter);
					continue;
				}
				else {
					//�����ϰ�� Ÿ�� �ʱ�ȭ
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

