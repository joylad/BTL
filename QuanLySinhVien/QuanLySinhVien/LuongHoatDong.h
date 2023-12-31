#include <io.h>
#include <fcntl.h>
#include "SinhVien.h"
#include "Lop.h"
#include "GiangVien.h"
#include "DoHoa.h"
#include "GiaoDien.h"
#include "MonHoc.h"
#include <fstream>
#include <locale>
#include <codecvt>

// 2. Luồng cho Sinh viên sử dụng
void LuongSinhVienSuDung()
{
	// Sử dụng để nhập xuất file tiếng việt
	locale loc(locale(), new codecvt_utf8<wchar_t>);  // UTF-8


	///////////////////////////////////////////////////////
	// Lấy dữ liệu sinh viên
	///////////////////////////////////////////////////////
	// Danh sách các Lớp
	vector<Lop> ListLop;
	// Đọc dữ liệu 
	wifstream fin(L"DuLieuSinhVien.txt");
	if (!fin) {
		wcout << L"Không thể đọc file DuLieuSinhVien.txt\n";
	}
	else
	{
		fin.imbue(loc);
		while (!fin.eof()) // Đọc đến cuối file
		{
			wstring s_temp;
			// Lấy dữ liệu -> Họ Tên
			wstring HoTen_temp = L"";
			do
			{
				fin >> s_temp;
				HoTen_temp += L" " + s_temp;
			} while (HoTen_temp[HoTen_temp.size() - 1] != ',');
			HoTen_temp.pop_back();
			HoTen_temp.erase(0, 1);

			// Lấy dữ liệu -> Địa chỉ
			wstring DiaChi_temp = L"";
			do
			{
				fin >> s_temp;
				DiaChi_temp += L" " + s_temp;
			} while (DiaChi_temp[DiaChi_temp.size() - 1] != ',');
			DiaChi_temp.pop_back();
			DiaChi_temp.erase(0, 1);

			// Lấy dữ liệu -> Số điện thoại
			wstring SDT_temp;
			fin >> SDT_temp;
			SDT_temp.pop_back();

			wchar_t t_temp_c;
			// Lấy dữ liệu -> Ngày sinh
			int Ngay_sinh;
			wstring t_temp_d = L"";
			do
			{
				fin >> t_temp_c;
				t_temp_d += t_temp_c;
			} while (t_temp_d[t_temp_d.size() - 1] != '/');
			t_temp_d.pop_back();
			Ngay_sinh = stoi(t_temp_d);

			// Lấy dữ liệu -> Tháng sinh
			int Thang_sinh;
			wstring t_temp_m = L"";
			do
			{
				fin >> t_temp_c;
				t_temp_m += t_temp_c;
			} while (t_temp_m[t_temp_m.size() - 1] != '/');
			t_temp_m.pop_back();
			Thang_sinh = stoi(t_temp_m);

			// Lấy dữ liệu -> Năm sinh
			int Nam_sinh;
			wstring t_temp_y = L"";
			do
			{
				fin >> t_temp_c;
				t_temp_y += t_temp_c;
			} while (t_temp_y[t_temp_y.size() - 1] != ',');
			t_temp_y.pop_back();
			Nam_sinh = stoi(t_temp_y);

			// Tạo ra sinh viên với dữ liệu vừa lấy
			SinhVien SinhVien_temp(HoTen_temp, DiaChi_temp, SDT_temp, Ngay_sinh, Thang_sinh, Nam_sinh);

			// Lấy dữ liệu -> Lớp
			wstring Lop_temp;
			fin >> Lop_temp;

			int i = 0;
			// Trường hợp Lớp đã tồn tại, chỉ thêm sinh viên vào
			for (i; i < ListLop.size(); i++)
			{
				if (ListLop[i].getMaLop() == Lop_temp)
				{
					ListLop[i].setSinhVienLop(SinhVien_temp);
					break;
				}
			}

			// Lớp chưa tồn tại, tạo ra lớp
			if (i >= ListLop.size())
			{
				Lop LopMoi = Lop(Lop_temp);
				ListLop.push_back(LopMoi);
				ListLop[i].setSinhVienLop(SinhVien_temp);
			}
		}
		fin.close();
	}

	///////////////////////////////////////////////////////////////
	// Lấy dữ liệu môn học
	///////////////////////////////////////////////////////////////
	vector<MonHoc> ListMonHoc;
	wifstream fiin(L"DuLieuMonHoc.txt");
	if (!fiin) {
		wcout << L"Không thể đọc file DuLieuMonHoc.txt\n";
	}
	else
	{
		fiin.imbue(loc);
		while (!fiin.eof()) // Đọc đến cuối file
		{
			// Lấy dữ liệu -> Mã môn
			wstring MaMon_temp;
			fiin >> MaMon_temp;
			MaMon_temp.pop_back();

			wstring s_temp;
			// Lấy dữ liệu -> Tên môn
			wstring TenMon_temp = L"";
			do
			{
				fiin >> s_temp;
				TenMon_temp += L" " + s_temp;
			} while (TenMon_temp[TenMon_temp.size() - 1] != ',');
			TenMon_temp.pop_back();
			TenMon_temp.erase(0, 1);

			// Lấy dữ liệu -> Số tín chỉ
			int SoTin_temp;
			fiin >> SoTin_temp;

			ListMonHoc.push_back(MonHoc(MaMon_temp, TenMon_temp, SoTin_temp));
		}
		fiin.close();
	}

	/////////////////////////////////////////////////////
	// Sinh viên hoạt động
	///////////////////////////////////////////////////////
	//
	// Đăng nhập mật khẩu tài khoản sinh viên
	int BienTaiKhoan, vtlop;
	int BienMatKhau, vtsv;
	bool XacDinhDangNhap = false;

		/// Kiểm tra đăng nhập đúng tài khoản
	loop1: while (XacDinhDangNhap == false)
	{
		KhungMatKhauSinhVien();
		gotoxy(18, 3);

		wcin >> BienTaiKhoan;

		for (int i = 0; i < ListLop.size(); i++)
		{
			for (int j = 0; j < ListLop[i].getSinhVienLop().size(); j++)
			{
				if (BienTaiKhoan == ListLop[i].getSinhVienLop()[j].getMaSinhVien())
				{
					gotoxy(14, 5);
					wcin >> BienMatKhau;
					if (BienMatKhau == ListLop[i].getSinhVienLop()[j].getPassword())
					{
						vtlop = i;
						vtsv = j;
						XacDinhDangNhap = true;
						system("cls");
						goto loop2;
					}
				}
			}
		}
		system("cls");
	}

	// Lựa chọn các tác vụ (
	int temp_1;
	loop2:do
	{
		KhungGiaoDienSinhVien();
		gotoxy(38, 12);
		wcin >> temp_1; wcin.ignore();
		system("cls");
	} while (temp_1 < 1 || temp_1 > 3);
	system("cls");

	// Xem thông tin sinh viên
	if (temp_1 == 1)
	{
		KhungThongTinSinhVien();
		ListLop[vtlop].getSinhVienLop()[vtsv].XuatSinhVien();
		wcout << setw(10) << right << ListLop[vtlop].getMaLop() << endl;

		wchar_t a;
		do {
			wcout << L"Nhập q để thoát: "; wcin >> a;
		} while (a != 'q');
		system("cls");
		goto loop2;
	}

	// Đăng kí học
	if (temp_1 == 2)
	{
		KhungMonHoc();
		for (int i = 0; i < ListMonHoc.size(); i++)
		{
			ListMonHoc[i].getMonHoc();
			wcout << endl;
		}

		wchar_t a;
	loop3: do {
		wcout << L"Chọn r để đăng kí, q để thoát: "; wcin >> a;
	} while (a != 'r' && a != 'q');

	if (a == 'r')
	{
		wstring b;
		wcout << "Nhập mã môn đăng kí: "; wcin >> b;
		for (int i = 0; i < ListMonHoc.size(); i++)
		{
			if (b == ListMonHoc[i].getMaMonHoc())
			{
				ListLop[vtlop].getSinhVienLop()[vtsv].setMonHocSV(ListMonHoc[i]);
				break;
			}
		}
		goto loop3;
	}
	else
	{
		system("cls");
		goto loop2;
	}
	}

	if (temp_1 == 3)
	{
		KhungMonHoc();
		for (int i = 0; i < ListLop[vtlop].getSinhVienLop()[vtsv].getMonHocSV().size(); i++)
		{
			ListLop[vtlop].getSinhVienLop()[vtsv].getMonHocSV()[i].getMonHoc();
		}
		wchar_t a;
		do {
			wcout << L"Nhập q để thoát: "; wcin >> a;
		} while (a != 'q');
		system("cls");
		goto loop2;
	}
}

// 3. Luồng quản lý sử dụng
void LuongQuanLySuDung()
{
	// Sử dụng để nhập xuất file tiếng việt
	locale loc(locale(), new codecvt_utf8<wchar_t>);  // UTF-8


	///////////////////////////////////////////////////////
	// Lấy dữ liệu sinh viên
	///////////////////////////////////////////////////////
	// Danh sách các Lớp
	vector<Lop> ListLop;
	// Đọc dữ liệu 
	wifstream fin(L"DuLieuSinhVien.txt");
	if (!fin) {
		wcout << L"Không thể đọc file DuLieuSinhVien.txt\n";
	}
	else
	{
		fin.imbue(loc);
		while (!fin.eof()) // Đọc đến cuối file
		{
			wstring s_temp;
			// Lấy dữ liệu -> Họ Tên
			wstring HoTen_temp = L"";
			do
			{
				fin >> s_temp;
				HoTen_temp += L" " + s_temp;
			} while (HoTen_temp[HoTen_temp.size() - 1] != ',');
			HoTen_temp.pop_back();
			HoTen_temp.erase(0, 1);

			// Lấy dữ liệu -> Địa chỉ
			wstring DiaChi_temp = L"";
			do
			{
				fin >> s_temp;
				DiaChi_temp += L" " + s_temp;
			} while (DiaChi_temp[DiaChi_temp.size() - 1] != ',');
			DiaChi_temp.pop_back();
			DiaChi_temp.erase(0, 1);

			// Lấy dữ liệu -> Số điện thoại
			wstring SDT_temp;
			fin >> SDT_temp;
			SDT_temp.pop_back();

			wchar_t t_temp_c;
			// Lấy dữ liệu -> Ngày sinh
			int Ngay_sinh;
			wstring t_temp_d = L"";
			do
			{
				fin >> t_temp_c;
				t_temp_d += t_temp_c;
			} while (t_temp_d[t_temp_d.size() - 1] != '/');
			t_temp_d.pop_back();
			Ngay_sinh = stoi(t_temp_d);

			// Lấy dữ liệu -> Tháng sinh
			int Thang_sinh;
			wstring t_temp_m = L"";
			do
			{
				fin >> t_temp_c;
				t_temp_m += t_temp_c;
			} while (t_temp_m[t_temp_m.size() - 1] != '/');
			t_temp_m.pop_back();
			Thang_sinh = stoi(t_temp_m);

			// Lấy dữ liệu -> Năm sinh
			int Nam_sinh;
			wstring t_temp_y = L"";
			do
			{
				fin >> t_temp_c;
				t_temp_y += t_temp_c;
			} while (t_temp_y[t_temp_y.size() - 1] != ',');
			t_temp_y.pop_back();
			Nam_sinh = stoi(t_temp_y);

			// Tạo ra sinh viên với dữ liệu vừa lấy
			SinhVien SinhVien_temp(HoTen_temp, DiaChi_temp, SDT_temp, Ngay_sinh, Thang_sinh, Nam_sinh);

			// Lấy dữ liệu -> Lớp
			wstring Lop_temp;
			fin >> Lop_temp;

			int i = 0;
			// Trường hợp Lớp đã tồn tại, chỉ thêm sinh viên vào
			for (i; i < ListLop.size(); i++)
			{
				if (ListLop[i].getMaLop() == Lop_temp)
				{
					ListLop[i].setSinhVienLop(SinhVien_temp);
					break;
				}
			}

			// Lớp chưa tồn tại, tạo ra lớp
			if (i >= ListLop.size())
			{
				Lop LopMoi = Lop(Lop_temp);
				ListLop.push_back(LopMoi);
				ListLop[i].setSinhVienLop(SinhVien_temp);
			}
		}
		fin.close();
	}

	///////////////////////////////////////////////////////////////
	// Lấy dữ liệu môn học
	///////////////////////////////////////////////////////////////
	vector<MonHoc> ListMonHoc;
	wifstream fin2(L"DuLieuMonHoc.txt");
	if (!fin2) {
		wcout << L"Không thể đọc file DuLieuMonHoc.txt\n";
	}
	else
	{
		fin2.imbue(loc);
		while (!fin2.eof()) // Đọc đến cuối file
		{
			// Lấy dữ liệu -> Mã môn
			wstring MaMon_temp;
			fin2 >> MaMon_temp;
			MaMon_temp.pop_back();

			wstring s_temp;
			// Lấy dữ liệu -> Tên môn
			wstring TenMon_temp = L"";
			do
			{
				fin2 >> s_temp;
				TenMon_temp += L" " + s_temp;
			} while (TenMon_temp[TenMon_temp.size() - 1] != ',');
			TenMon_temp.pop_back();
			TenMon_temp.erase(0, 1);

			// Lấy dữ liệu -> Số tín chỉ
			int SoTin_temp;
			fin2 >> SoTin_temp;

			ListMonHoc.push_back(MonHoc(MaMon_temp, TenMon_temp, SoTin_temp));
		}
		fin2.close();
	}

	////////////////////////////////////////////////////
	// La
	///////////////////////////////////////////////////
	vector<GiangVien> ListGiangVien;
	// Đọc dữ liệu 
	wifstream fin3(L"DuLieuGiangVien.txt");
	if (!fin3) {
		wcout << L"Không thể đọc file DuLieuGiangVien.txt\n";
	}
	else
	{
		fin3.imbue(loc);
		while (!fin3.eof()) // Đọc đến cuối file
		{
			wstring s_temp;
			// Lấy dữ liệu -> Họ Tên
			wstring HoTen_temp = L"";
			do
			{
				fin3 >> s_temp;
				HoTen_temp += L" " + s_temp;
			} while (HoTen_temp[HoTen_temp.size() - 1] != ',');
			HoTen_temp.pop_back();
			HoTen_temp.erase(0, 1);

			// Lấy dữ liệu -> Địa chỉ
			wstring DiaChi_temp = L"";
			do
			{
				fin3 >> s_temp;
				DiaChi_temp += L" " + s_temp;
			} while (DiaChi_temp[DiaChi_temp.size() - 1] != ',');
			DiaChi_temp.pop_back();
			DiaChi_temp.erase(0, 1);

			// Lấy dữ liệu -> Số điện thoại
			wstring SDT_temp;
			fin3 >> SDT_temp;
			SDT_temp.pop_back();

			wchar_t t_temp_c;
			// Lấy dữ liệu -> Ngày sinh
			int Ngay_sinh;
			wstring t_temp_d = L"";
			do
			{
				fin3 >> t_temp_c;
				t_temp_d += t_temp_c;
			} while (t_temp_d[t_temp_d.size() - 1] != '/');
			t_temp_d.pop_back();
			Ngay_sinh = stoi(t_temp_d);

			// Lấy dữ liệu -> Tháng sinh
			int Thang_sinh;
			wstring t_temp_m = L"";
			do
			{
				fin3 >> t_temp_c;
				t_temp_m += t_temp_c;
			} while (t_temp_m[t_temp_m.size() - 1] != '/');
			t_temp_m.pop_back();
			Thang_sinh = stoi(t_temp_m);

			// Lấy dữ liệu -> Năm sinh
			int Nam_sinh;
			wstring t_temp_y = L"";
			do
			{
				fin3 >> t_temp_c;
				t_temp_y += t_temp_c;
			} while (t_temp_y[t_temp_y.size() - 1] != ',');
			t_temp_y.pop_back();
			Nam_sinh = stoi(t_temp_y);

			// Lấy ra dữ liệu học vị của giảng viên 
			wstring HocVi_temp;
			fin3 >> HocVi_temp;
			HocVi_temp.pop_back();

			// Lấy dữ liệu chuyên môn của giảng viên
			wstring ChuyenMon_temp;
			getline(fin3, ChuyenMon_temp);
			ChuyenMon_temp.erase(0, 1);

			ListGiangVien.push_back(GiangVien(HoTen_temp, DiaChi_temp, SDT_temp, Ngay_sinh, Thang_sinh, Nam_sinh, HocVi_temp, ChuyenMon_temp));
		}
		fin3.close();
	}

	/////////////////////////////////////////////////////
	// Quản lý hoạt động
	///////////////////////////////////////////////////////
	//
	// Đăng nhập mật khẩu tài khoản quản lý
	wstring BienTaiKhoan;
	wstring BienMatKhau;
	bool XacDinhDangNhap = false;

	/// Kiểm tra đăng nhập đúng tài khoản
	while (XacDinhDangNhap == false)
	{
		KhungMatKhauQuanLy();
		gotoxy(16, 3);

		wcin >> BienTaiKhoan;

		if (BienTaiKhoan == L"Admin")
		{
			gotoxy(14, 5);
			wcin >> BienMatKhau;
			if (BienMatKhau == L"Admin")
			{
				XacDinhDangNhap = true;
			}
		}
		system("cls");
	}

	int temp;
	loop1: do {
		KhungGiaoDienQuanLy();
		gotoxy(37, 15);
		wcin >> temp;
		system("cls");
	} while (temp > 6 || temp < 1);

	// Chọn xem thông tin sinh viên
	if (temp == 1)
	{
		KhungThongTinSinhVien();
		for (int i = 0; i < ListLop.size(); i++)
		{
			for (int k = 0; k < ListLop[i].getSinhVienLop().size(); k++)
			{
				ListLop[i].getSinhVienLop()[k].XuatSinhVien();
				wcout << setw(10) << right << ListLop[i].getMaLop();
				wcout << endl;
			}
		}

		wcout << endl;

		wchar_t a;
		do {
			wcout << L"Nhập q để thoát: "; wcin >> a;
		} while (a != 'q');

		system("cls");
		goto loop1;
	}

	// Chọn xem thông tin giảng viên
	if (temp == 2)
	{
		KhungThongTinGiangVien();
		for (int i = 0; i < ListGiangVien.size(); i++)
		{
			ListGiangVien[i].XuatGiangVien();
			wcout << endl;
		}

		wcout << endl;

		wchar_t a;
		do {
			wcout << L"Nhập q để thoát: "; wcin >> a;
		} while (a != 'q');

		system("cls");
		goto loop1;
	}

	// Chọn xem thông tin môn học
	if (temp == 3)
	{
		KhungMonHoc();
		for (int i = 0; i < ListMonHoc.size(); i++)
		{
			ListMonHoc[i].getMonHoc();
			wcout << endl;
		}
		wcout << endl;

		wchar_t a;
		do {
			wcout << L"Nhập q để thoát: "; wcin >> a;
		} while (a != 'q');

		system("cls");
		goto loop1;
	}

	// Chọn tìm kiếm thông tin sinh viên
	if (temp == 4)
	{
		int s, vtlop, vtsv;
		bool ok = false;
		do {
			ThanhTimKiemSinhVien();
			gotoxy(28, 3);
			wcin >> s;
			for (int i = 0; i < ListLop.size(); i++)
			{
				for (int j = 0; j < ListLop[i].getSinhVienLop().size(); j++)
				{
					if (s == ListLop[i].getSinhVienLop()[j].getMaSinhVien())
					{
						vtlop = i;
						vtsv = j;
						ok = true;
						system("cls");
						goto vt1;
						break;
					}

				}
			}
			system("cls");
		} while (ok == false);

	vt1: KhungThongTinSinhVien();
		ListLop[vtlop].getSinhVienLop()[vtsv].XuatSinhVien();

		wcout << endl;

		wchar_t a;
		do {
			wcout << L"Nhập q để thoát: "; wcin >> a;
		} while (a != 'q');

		system("cls");
		goto loop1;
}

/// Tìm kiếm Giảng viên
if (temp == 5)
{
	int s;
	int vtlop;
	bool ok = false;
	do {
		ThanhTimKiemGiangVien();
		gotoxy(28, 3);
		wcin >> s;
		for (int i = 0; i < ListGiangVien.size(); i++)
		{
			if (s == ListGiangVien[i].getMagiangVien())
			{
				vtlop = i;
				system("cls");
				ok = true;
				break;
			}
		}
		system("cls");
	} while (ok == false);

	KhungThongTinGiangVien();
	ListGiangVien[vtlop].XuatGiangVien();

	wcout << endl;

	wchar_t a;
	do {
		wcout << L"Nhập q để thoát: "; wcin >> a;
	} while (a != 'q');

	system("cls");
	goto loop1;
}

	if (temp == 6)
	{
		wstring s;
		int vtlop;
		bool ok = false;
		do {
			ThanhTimKiemLop();
			gotoxy(21, 3);
			wcin >> s;
			for (int i = 0; i < ListLop.size(); i++)
			{
				if (s == ListLop[i].getMaLop())
				{
					vtlop = i;
					system("cls");
					ok = true;
					goto vt2;
					break;
				}
			}
			system("cls");
		} while (ok == false);

	vt2:KhungThongTinSinhVien();
		for (int i = 0; i < ListLop[vtlop].getSinhVienLop().size(); i++)
		{
			ListLop[vtlop].getSinhVienLop()[i].XuatSinhVien();
			wcout << setw(10) << right << s;
			wcout << endl;
		}

		wcout << endl;

		wchar_t a;
		do {
			wcout << L"Nhập q để thoát: "; wcin >> a;
		} while (a != 'q');

		system("cls");
		goto loop1;
	}
}

void LuongSuDungGiangVien()
{
	////////////////////////////////////////////////////
	// La
	///////////////////////////////////////////////////

	// Sử dụng để nhập xuất file tiếng việt
	locale loc(locale(), new codecvt_utf8<wchar_t>);  // UTF-8 
	vector<GiangVien> ListGiangVien;
	// Đọc dữ liệu 
	wifstream fin3(L"DuLieuGiangVien.txt");
	if (!fin3) {
		wcout << L"Không thể đọc file DuLieuGiangVien.txt\n";
	}
	else
	{
		fin3.imbue(loc);
		while (!fin3.eof()) // Đọc đến cuối file
		{
			wstring s_temp;
			// Lấy dữ liệu -> Họ Tên
			wstring HoTen_temp = L"";
			do
			{
				fin3 >> s_temp;
				HoTen_temp += L" " + s_temp;
			} while (HoTen_temp[HoTen_temp.size() - 1] != ',');
			HoTen_temp.pop_back();
			HoTen_temp.erase(0, 1);

			// Lấy dữ liệu -> Địa chỉ
			wstring DiaChi_temp = L"";
			do
			{
				fin3 >> s_temp;
				DiaChi_temp += L" " + s_temp;
			} while (DiaChi_temp[DiaChi_temp.size() - 1] != ',');
			DiaChi_temp.pop_back();
			DiaChi_temp.erase(0, 1);

			// Lấy dữ liệu -> Số điện thoại
			wstring SDT_temp;
			fin3 >> SDT_temp;
			SDT_temp.pop_back();

			wchar_t t_temp_c;
			// Lấy dữ liệu -> Ngày sinh
			int Ngay_sinh;
			wstring t_temp_d = L"";
			do
			{
				fin3 >> t_temp_c;
				t_temp_d += t_temp_c;
			} while (t_temp_d[t_temp_d.size() - 1] != '/');
			t_temp_d.pop_back();
			Ngay_sinh = stoi(t_temp_d);

			// Lấy dữ liệu -> Tháng sinh
			int Thang_sinh;
			wstring t_temp_m = L"";
			do
			{
				fin3 >> t_temp_c;
				t_temp_m += t_temp_c;
			} while (t_temp_m[t_temp_m.size() - 1] != '/');
			t_temp_m.pop_back();
			Thang_sinh = stoi(t_temp_m);

			// Lấy dữ liệu -> Năm sinh
			int Nam_sinh;
			wstring t_temp_y = L"";
			do
			{
				fin3 >> t_temp_c;
				t_temp_y += t_temp_c;
			} while (t_temp_y[t_temp_y.size() - 1] != ',');
			t_temp_y.pop_back();
			Nam_sinh = stoi(t_temp_y);

			// Lấy ra dữ liệu học vị của giảng viên 
			wstring HocVi_temp;
			fin3 >> HocVi_temp;
			HocVi_temp.pop_back();

			// Lấy dữ liệu chuyên môn của giảng viên
			wstring ChuyenMon_temp;
			getline(fin3, ChuyenMon_temp);
			ChuyenMon_temp.erase(0, 1);

			ListGiangVien.push_back(GiangVien(HoTen_temp, DiaChi_temp, SDT_temp, Ngay_sinh, Thang_sinh, Nam_sinh, HocVi_temp, ChuyenMon_temp));
		}
		fin3.close();
	}

	///////////////////////////////////////////
	/////
	//////////////////////////////////////////////

	int BienTaiKhoan, vtgv;
	int BienMatKhau;
	bool XacDinhDangNhap = false;

	/// Kiểm tra đăng nhập đúng tài khoản
	loop1: while (XacDinhDangNhap == false)
	{
		KhungMatKhauGiangVien();
		gotoxy(19, 3);

		wcin >> BienTaiKhoan;

		for (int i = 0; i < ListGiangVien.size(); i++)
		{
			if (ListGiangVien[i].getMagiangVien() == BienTaiKhoan)
			{
				gotoxy(14, 5);
				wcin >> BienMatKhau;
				if (BienMatKhau == ListGiangVien[i].getPassWord())
				{
					vtgv = i;
					XacDinhDangNhap = true;
					system("cls");
					//goto loop2;
					break;
				}
			}
		}
		system("cls");
	}

	int a;
	do {
		KhungGiaoDienGiangVien();
		gotoxy(37, 12);
		wcin >> a;
		system("cls");
	} while (a != 1);

	KhungThongTinGiangVien();
	ListGiangVien[vtgv].XuatGiangVien();

	wcout << endl;

	wchar_t b;
	do {
		wcout << L"Nhập q để thoát: "; wcin >> b;
	} while (b != 'q');

	system("cls");
	goto loop1;
}


// 1. Đăng Nhập
void LuongSuDung()
{
	int BienDangNhap;
	do
	{
		KhungDangNhap();
		gotoxy(37, 12);
		wcin >> BienDangNhap;
		system("cls");
	} while (BienDangNhap > 3 || BienDangNhap < 1);
	
	if (BienDangNhap == 1)
		LuongSinhVienSuDung();
	else if (BienDangNhap == 2)
		LuongSuDungGiangVien();
	else LuongQuanLySuDung();
}

