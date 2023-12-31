#pragma once
#include "Nguoi.h"

class GiangVien : public Nguoi
{
private:
	static int MaGV_TuDong;
	int MaGiangVien;
	wstring HocVi;
	wstring ChuyenMon;
	int Password;
public:
	// Khơir tạo giảng viên
	GiangVien();

	// Khởi tạo giảng viên
	GiangVien(wstring a, wstring b, wstring c, int d, int e, int f, wstring g, wstring h)
		: Nguoi(a, b, c, d, e, f)
	{
		MaGiangVien = MaGV_TuDong++;
		HocVi = g;
		ChuyenMon = h;
		Password = MaGiangVien;
	}

	// Lấy ra mã giảng viên
	int getMagiangVien();

	// Lấy ra mật khẩu giảng viên
	int getPassWord();

	// Xuất giangr viên
	void XuatGiangVien();
};

