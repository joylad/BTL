#include "SinhVien.h"

int SinhVien::MaSV_TuDong = 10000;

SinhVien::SinhVien()
{
	MaSinhVien = MaSV_TuDong++;
	Password = MaSinhVien;
}

// Xuất sinh viên 
void SinhVien::XuatSinhVien()
{
	wcout << setw(10) << left << MaSinhVien;
	XuatNguoi();
}

// Lấy ra các môn học của sinh viên
vector<MonHoc> SinhVien::getMonHocSV()
{
	return MonHocSV;
}

// sinh viên đăng kí môn học
void SinhVien::setMonHocSV(MonHoc a)
{
	MonHocSV.push_back(a);
}

// Lấy ra mã sinh viên
int SinhVien::getMaSinhVien()
{
	return MaSinhVien;
}

// Lấy ra mật khẩu tài khoản sinh viên
int SinhVien::getPassword()
{
	return Password;
}