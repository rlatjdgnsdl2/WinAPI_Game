#include "PreCompile.h"
#include "EngineSerializer.h"

UEngineSerializer::UEngineSerializer()
{
}

UEngineSerializer::~UEngineSerializer()
{
}

void UEngineSerializer::Write(void* _Data, unsigned int _Size)
{
	// 버퍼 크기가 충분하지 않으면 버퍼 크기를 2배로 확장
	if (WriteOffset + _Size >= Data.size())
	{
		Data.resize(Data.size() * 2 + _Size);
	}
	// 버퍼의 현재 쓰기 위치에 데이터를 복사
	memcpy_s(&Data[WriteOffset], _Size, _Data, _Size);
	WriteOffset += _Size;
}

void UEngineSerializer::operator<<(SerializableObject& _Data)
{
	_Data.Serialize(*this);
}

void UEngineSerializer::Read(void* _Data, unsigned int _Size)
{
	// 버퍼의 현재 읽기 위치에서 데이터를 복사
	memcpy_s(_Data, _Size, &Data[ReadOffset], _Size);
	ReadOffset += _Size;
}

void UEngineSerializer::operator>>(SerializableObject& _Data)
{
	_Data.DeSerialize(*this);
}
