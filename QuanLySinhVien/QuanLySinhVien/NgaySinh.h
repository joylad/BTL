#include <iostream>

using namespace std;

class NgaySinh
{
private:
	int Ngay;
	int Thang;
	int Nam;
public:

	// Khởi tạo ngày sinh không tham số
	NgaySinh();

	// Khởi tạo ngày sinh với tham số
	NgaySinh(int a, int b, int c);

	// Xuất ra ngày sinh
	void XuatNgaySinh();
};

