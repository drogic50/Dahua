// stdafx.cpp : ֻ������׼�����ļ���Դ�ļ�
// VTODemo.pch ����ΪԤ����ͷ
// stdafx.obj ������Ԥ����������Ϣ

#include "stdafx.h"

#if defined(_WIN64)

#pragma comment(lib, "../../../Lib/Win64/dhconfigsdk.lib")
#pragma comment(lib, "../../../Lib/Win64/dhnetsdk.lib")
#else
#pragma comment(lib,"../../../Lib/Win32/dhconfigsdk.lib")
#pragma comment(lib,"../../../Lib/Win32/dhnetsdk.lib")
#endif