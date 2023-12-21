#include "Lop.h"

Lop::Lop()
{
	MaLop = L"Unkown";
}

Lop::Lop(wstring a)
{
	MaLop = a;
}
vector<SinhVien> Lop::getSinhVienLop()
{
	return SinhVienLop;
}
wstring Lop::getMaLop()
{
	return MaLop;
}
void Lop::setSinhVienLop(SinhVien sv)
{
	SinhVienLop.push_back(sv);
}