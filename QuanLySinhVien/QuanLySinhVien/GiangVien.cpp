#include "GiangVien.h"


int GiangVien::MaGV_TuDong = 1000;

GiangVien::GiangVien()
{
	MaGiangVien = MaGV_TuDong++;
	HocVi = L"Unkown";
	ChuyenMon = L"Unkown";
	Password = MaGiangVien;
}

int GiangVien::getMagiangVien()
{
	return MaGiangVien;
}

int GiangVien::getPassWord()
{
	return Password;
}

void GiangVien::XuatGiangVien()
{
	wcout << setw(10) << left << MaGiangVien;
	XuatNguoi();
	wcout << setw(3) << left << " ";
	wcout << setw(15) << left << HocVi;
}