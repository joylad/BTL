#include "MonHoc.h"


MonHoc::MonHoc()
{
	MaMonHoc = L"Unkown";
	TenMonHoc = L"Unkown";
	SoTinChi = 0;
}

MonHoc::MonHoc(wstring a, wstring b, int c)
{
	MaMonHoc = a;
	TenMonHoc = b;
	SoTinChi = c;
}

wstring MonHoc::getMaMonHoc()
{
	return MaMonHoc;
}

wstring MonHoc::getTenMonHoc()
{
	return TenMonHoc;
}

int MonHoc::getSoTinChi()
{
	return SoTinChi;
}

void MonHoc::getMonHoc()
{
	wcout << setw(15) << left << MaMonHoc;
	wcout << setw(60) << left << TenMonHoc;
	wcout << SoTinChi;
}