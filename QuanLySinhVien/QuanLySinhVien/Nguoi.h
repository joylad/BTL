#pragma once
#include "NgaySinh.h"
#include <string>
#include <iomanip>

using namespace std;

class Nguoi
{
protected:
	wstring HoTen;
	wstring DiaChi;
	wstring SDT;
	NgaySinh mNgaySinh;
public:
	// Khởi tạo người không tham số
	Nguoi();

	// Khởi tạo người với tham số đầu vào
	Nguoi(wstring a, wstring b, wstring c, int d, int e, int f);

	// Xuất người
	void XuatNguoi();
};
