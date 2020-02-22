#include <iNut.h>

iNut inut;// Khởi tạo đối tượng iNut

int chanCamBien = 2;
boolean trangThaiTruoc = LOW;

void setup() {
  // Thiết lập chế độ INPUT cho chân nối với cảm biến
  pinMode(chanCamBien, INPUT);

  // Lệnh thiết lập kết nối Arduino với iNut cảm biến,
  // trong đó 8 là số luồng dữ liệu của iNut cảm biến
  inut.setup(8);

  // Bắt buộc phải có bước này: Đặt giá trị ban đầu cho 8 luồng khi mới kết nối
  for (int i = 0; i < 8; i++) {
    // Lệnh đặt giá trị dữ liệu cho luồng thứ i
    // Ban đầu thì cứ cho cả 8 luồng nhận giá trị là 0
    inut.setValue(i, 0);
  }
}

void loop() {
  boolean trangThaiCamBien = digitalRead(chanCamBien);// Đọc giá trị cảm biến
  if (trangThaiCamBien != trangThaiTruoc) {
    if (trangThaiCamBien == HIGH) { // Nếu không có vật cản - Trạng thái cảm biến là HIGH
      // Lệnh đặt giá trị 1 (trạng thái HIGH) cho vị trí digital thứ 0 của luồng số 0
      inut.turnOn(0, 0);// turnOn(<luồng>, <vị trí digital>);
    } else { // Ngược lại nếu có vật cản
      // Lệnh đặt giá trị 0 (trạng thái LOW) cho vị trí digital thứ 0 của luồng số 0
      inut.turnOff(0, 0);// turnOff(<luồng>, <vị trí digital>);
      inut.alarm(0);// Gửi báo động đến máy chủ với mã báo động là 0
    }
    trangThaiTruoc = trangThaiCamBien;
  }

  // Cần chạy câu lệnh này trong hàm loop
  inut.loop();
}
