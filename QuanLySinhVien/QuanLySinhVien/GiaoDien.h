#pragma once
#include <iostream>
#include<io.h>
#include<fcntl.h>
#include "Dohoa.h"
#include <iomanip>

using namespace std;

// Sử dụng tiếng việt
void SuDungToanBoTiengViet()
{
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);
}

void KhungMatKhauSinhVien()
{
    wcout << L"╔══════════ ĐĂNG NHẬP SINH VIÊN ═══════════╗" << endl;
    wcout << L"║                                          ║" << endl;
    wcout << L"║  Mã sinh viên:                           ║" << endl;
    wcout << L"║                                          ║" << endl;
    wcout << L"║  Mật khẩu:                               ║" << endl;
    wcout << L"║                                          ║" << endl;
    wcout << L"╚══════════════════════════════════════════╝" << endl;
}

void KhungMatKhauQuanLy()
{
    wcout << L"╔══════════ ĐĂNG NHẬP QUẢN LÝ ═════════════╗" << endl;
    wcout << L"║                                          ║" << endl;
    wcout << L"║  Mã quản lý:                             ║" << endl;
    wcout << L"║                                          ║" << endl;
    wcout << L"║  Mật khẩu:                               ║" << endl;
    wcout << L"║                                          ║" << endl;
    wcout << L"╚══════════════════════════════════════════╝" << endl;
}

void KhungMatKhauGiangVien()
{
    wcout << L"╔══════════ ĐĂNG NHẬP GIẢNG VIÊN ═════════════╗" << endl;
    wcout << L"║                                             ║" << endl;
    wcout << L"║  Mã giảng viên:                             ║" << endl;
    wcout << L"║                                             ║" << endl;
    wcout << L"║  Mật khẩu:                                  ║" << endl;
    wcout << L"║                                             ║" << endl;
    wcout << L"╚═════════════════════════════════════════════╝" << endl;
}

void KhungDangNhap()
{
    wcout << L"╔═════════════════════════════════════════════════════════════════════════════════════════╗" << endl;
    wcout << L"║                                   TRƯỜNG ĐẠI HỌC THỦY LỢI                               ║" << endl;
    wcout << L"║                                         ----***----                                     ║" << endl;
    wcout << L"║                                CHƯƠNG TRÌNH QUẢN LÍ SINH VIÊN                           ║" << endl;
    wcout << L"║                                                                                         ║" << endl;
    wcout << L"║                                      ___ ĐĂNG NHẬP___                                   ║" << endl;
    wcout << L"║                                                                                         ║" << endl;
    wcout << L"║    ┌────────────────────┐        ┌─────────────────────┐       ┌──────────────────┐     ║" << endl;
    wcout << L"║    │ 1.TÔI LÀ SINH VIÊN │        │ 2.TÔI LÀ GIẢNG VIÊN │       │ 3.TÔI LÀ QUẢN LÝ │     ║" << endl;
    wcout << L"║    └────────────────────┘        └─────────────────────┘       └──────────────────┘     ║" << endl;
    wcout << L"║                                                                                         ║" << endl;
    wcout << L"║   VUI LÒNG NHẬP LỰA CHỌN CỦA BẠN:                                                       ║" << endl;
    wcout << L"║                                                                                         ║" << endl;
    wcout << L"╚═════════════════════════════════════════════════════════════════════════════════════════╝" << endl;

};

void KhungGiaoDienSinhVien()
{
    wcout << L"╔═══════════════════════════════════════════════════════════════════════════════════════════════╗" << endl;
    wcout << L"║                                   TRƯỜNG ĐẠI HỌC THỦY LỢI                                     ║" << endl;
    wcout << L"║                                         ----***----                                           ║" << endl;
    wcout << L"║                                CHƯƠNG TRÌNH QUẢN LÍ SINH VIÊN                                 ║" << endl;
    wcout << L"║                                                                                               ║" << endl;
    wcout << L"║                                 ___ TÀI KHOẢN SINH VIÊN___                                    ║" << endl;
    wcout << L"║                                                                                               ║" << endl;
    wcout << L"║    ┌────────────────────────┐        ┌───────────────┐       ┌──────────────────────────┐     ║" << endl;
    wcout << L"║    │ 1. THÔNG TIN SINH VIÊN │        │ 2.ĐĂNG KÝ HỌC │       │ 3. TRA CỨU ĐIỂM TỔNG HỢP │     ║" << endl;
    wcout << L"║    └────────────────────────┘        └───────────────┘       └──────────────────────────┘     ║" << endl;
    wcout << L"║                                                                                               ║" << endl;
    wcout << L"║   VUI LÒNG NHẬP LỰA CHỌN CỦA BẠN:                                                             ║" << endl;
    wcout << L"║                                                                                               ║" << endl;
    wcout << L"╚═══════════════════════════════════════════════════════════════════════════════════════════════╝" << endl;
};

void KhungGiaoDienGiangVien()
{
    wcout << L"╔══════════════════════════════════════╗" << endl;
    wcout << L"║      TRƯỜNG ĐẠI HỌC THỦY LỢI         ║" << endl;
    wcout << L"║            ----***----               ║" << endl;
    wcout << L"║   CHƯƠNG TRÌNH QUẢN LÍ SINH VIÊN     ║" << endl;
    wcout << L"║                                      ║" << endl;
    wcout << L"║   ___ TÀI KHOẢN GIẢNG VIÊN___        ║" << endl;
    wcout << L"║                                      ║" << endl;
    wcout << L"║    ┌─────────────────────────┐       ║" << endl;
    wcout << L"║    │ 1. THÔNG TIN GIẢNG VIÊN │       ║" << endl;
    wcout << L"║    └─────────────────────────┘       ║" << endl;
    wcout << L"║                                      ║" << endl;
    wcout << L"║   VUI LÒNG NHẬP LỰA CHỌN CỦA BẠN:    ║" << endl;
    wcout << L"║                                      ║" << endl;
    wcout << L"╚══════════════════════════════════════╝" << endl;
};

void KhungGiaoDienQuanLy()
{
    wcout << L"╔═══════════════════════════════════════════════════════════════════════════════════════════════════╗" << endl;
    wcout << L"║                                       TRƯỜNG ĐẠI HỌC THỦY LỢI                                     ║" << endl;
    wcout << L"║                                             ----***----                                           ║" << endl;
    wcout << L"║                                    CHƯƠNG TRÌNH QUẢN LÍ SINH VIÊN                                 ║" << endl;
    wcout << L"║                                                                                                   ║" << endl;
    wcout << L"║                                     ___ TÀI KHOẢN QUẢN LÝ___                                      ║" << endl;
    wcout << L"║                                                                                                   ║" << endl;
    wcout << L"║    ┌────────────────────────┐       ┌────────────────────────┐       ┌──────────────────────┐     ║" << endl;
    wcout << L"║    │ 1. THÔNG TIN SINH VIÊN │       │ 2. THÔNG TIN GIẢNG VIÊN│       │ 3. THÔNG TIN MÔN HỌC │     ║" << endl;
    wcout << L"║    └────────────────────────┘       └────────────────────────┘       └──────────────────────┘     ║" << endl;
    wcout << L"║    ┌───────────────────────┐        ┌────────────────────────┐       ┌──────────────────────┐     ║" << endl;
    wcout << L"║    │ 4. TÌM KIẾM SINH VIÊN │        │ 5. TÌM KIẾM GIẢNG VIÊN │       │ 6. SINH VIEN LỚP HỌC │     ║" << endl;
    wcout << L"║    └───────────────────────┘        └────────────────────────┘       └──────────────────────┘     ║" << endl;
    wcout << L"║                                                                                                   ║" << endl;
    wcout << L"║   VUI LÒNG NHẬP LỰA CHỌN CỦA BẠN:                                                                 ║" << endl;
    wcout << L"║                                                                                                   ║" << endl;
    wcout << L"╚═══════════════════════════════════════════════════════════════════════════════════════════════════╝" << endl;
};
void KhungThongTinSinhVien()
{
    wcout << L"┌───────┬─────────────────────────┬──────────┬─────────────────┬───────────┬─────────┐" << endl;
    wcout << L"│ Mã SV │          TÊN SV         │  ĐỊA CHỈ │  SỐ ĐIỆN THOẠI  │ NGÀY SINH │   LỚP   │" << endl;
    wcout << L"└───────┴─────────────────────────┴──────────┴─────────────────┴───────────┴─────────┘" << endl;
}

void KhungMonHoc()
{
   
    wcout << L"┌──────────────┬─────────────────────────────────────────────────────────┬────────┐" << endl;
    wcout << L"│  MÃ MÔN HỌC  │                      TÊN MÔN HỌC                        │ SỐ TÍN │" << endl;
    wcout << L"└──────────────┴─────────────────────────────────────────────────────────┴────────┘" << endl;

}

void KhungThongTinGiangVien()
{
    wcout << L"┌───────┬─────────────────────────┬──────────┬─────────────────┬───────────┬────────┐" << endl;
    wcout << L"│ Mã GV │          TÊN GV         │  ĐỊA CHỈ │  SỐ ĐIỆN THOẠI  │ NGÀY SINH │ HỌC VỊ |" << endl;
    wcout << L"└───────┴─────────────────────────┴──────────┴─────────────────┴───────────┴────────┘" << endl;
}
void ThanhTimKiemSinhVien()
{
    wcout << L"╔═════════════════════════ TÌM KIẾM ════════════════════════════╗" << endl;
    wcout << L"║  ┌─────────────────────┬───────────────────────────────────┐  ║" << endl;
    wcout << L"║  │  NHẬP MÃ SINH VIÊN  │                                   │  ║" << endl;
    wcout << L"║  └─────────────────────┴───────────────────────────────────┘  ║" << endl;
    wcout << L"╚═══════════════════════════════════════════════════════════════╝" << endl;
}

void ThanhTimKiemGiangVien()
{
    wcout << L"╔═════════════════════════ TÌM KIẾM ════════════════════════════╗" << endl;
    wcout << L"║  ┌─────────────────────┬───────────────────────────────────┐  ║" << endl;
    wcout << L"║  │  NHẬP MÃ GIẢNG VIÊN │                                   │  ║" << endl;
    wcout << L"║  └─────────────────────┴───────────────────────────────────┘  ║" << endl;
    wcout << L"╚═══════════════════════════════════════════════════════════════╝" << endl;
} 

void ThanhTimKiemLop()
{
    wcout << L"╔══════════════════════ TÌM KIẾM ════════════════════════╗" << endl;
    wcout << L"║  ┌──────────────┬───────────────────────────────────┐  ║" << endl;
    wcout << L"║  │  NHẬP MÃ LỚP │                                   │  ║" << endl;
    wcout << L"║  └──────────────┴───────────────────────────────────┘  ║" << endl;
    wcout << L"╚════════════════════════════════════════════════════════╝" << endl;
}

