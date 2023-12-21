#include "Nguoi.h"

Nguoi::Nguoi()
{
	HoTen = L"Unkown";
	DiaChi = L"Unkown";
	SDT = L"Unkown";
	mNgaySinh = NgaySinh();
}

Nguoi::Nguoi(wstring a, wstring b, wstring c, int d, int e, int f)
{
	HoTen = a;
	DiaChi = b;
	SDT = c;
	mNgaySinh = NgaySinh(d, e, f);
}

void Nguoi::XuatNguoi()
{
	wcout << setw(25) << left << HoTen;
	wcout << setw(13) << left << DiaChi;
	wcout << setw(17) << left << SDT;
	mNgaySinh.XuatNgaySinh();
}