#pragma once
#include <string>
#include "Nguoi.h"
#include <iomanip>

using namespace std;
class MonHoc
{
protected:
	wstring MaMonHoc;
	wstring TenMonHoc;
	int SoTinChi;
public:
	// Khởi tạo môn học
	MonHoc();

	// Khởi tạo môn học
	MonHoc(wstring a, wstring b, int c);
	
	// Lấy mã môn học
	wstring getMaMonHoc();

	// Lấy tên môn học
	wstring getTenMonHoc();

	// Lấy số tín chỉ
	int getSoTinChi();

	// Xuất môn học
	void getMonHoc();
};

