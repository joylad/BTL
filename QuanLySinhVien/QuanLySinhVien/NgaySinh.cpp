#include "NgaySinh.h"
#include <string>
#include <io.h>
#include <fcntl.h>

NgaySinh::NgaySinh()
{
	Ngay = 0;
	Thang = 0;
	Nam = 0;
}

NgaySinh::NgaySinh(int a, int b, int c)
{
	Ngay = a;
	Thang = b;
	Nam = c;
}

void NgaySinh::XuatNgaySinh()
{
	if (Ngay < 10)
		wcout << '0';
	wcout << Ngay << '/';
	if (Thang < 10)
		wcout << '0';
	wcout << Thang << '/';
	wcout << Nam;
}