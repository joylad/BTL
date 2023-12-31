#pragma once
#include "Nguoi.h"
#include "MonHoc.h"
#include <vector>

class SinhVien : public Nguoi
{
private:
	static int MaSV_TuDong;
	int MaSinhVien;
	int Password;
	vector<MonHoc> MonHocSV;

public:
	// Khởi tạo Lớp sinh viên không tham số đầu vào
	SinhVien();

	// Khởi tạo sinh viên với tham số đầu vào
	SinhVien(wstring a, wstring b, wstring c, int d, int e, int f) 
		: Nguoi(a, b, c, d, e, f)
	{
		MaSinhVien = MaSV_TuDong++;
		Password = MaSinhVien;
	}

	// Xuất sinh viên 
	void XuatSinhVien();

	// Lấy ra các môn học của sinh viên
	vector<MonHoc> getMonHocSV();

	// sinh viên đăng kí môn học
	void setMonHocSV(MonHoc a);

	// Lấy ra mã sinh viên
	int getMaSinhVien();

	// Lấy ra mật khẩu tài khoản sinh viên
	int getPassword();
};

