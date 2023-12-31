#pragma once
#include "SinhVien.h"
#include <vector>

class Lop
{
private:
	wstring MaLop;
	vector<SinhVien> SinhVienLop;
public:
	Lop();

	// Khởi tạo có mã lớp
	Lop(wstring a);

	// Lấy ra danh sách sinh viên
	vector<SinhVien> getSinhVienLop();

	// Lấy ra mã lớp
	wstring getMaLop();
	
	// Thêm 1 lớp vào lớp
	void setSinhVienLop(SinhVien sv);
};
