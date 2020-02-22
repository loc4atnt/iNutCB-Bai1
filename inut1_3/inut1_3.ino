#include <iNut.h>

iNut inut;// Khởi tạo đối tượng iNut

const int SO_LED = 2;
int led[SO_LED] = {8, 9};// 2 bóng led được nối với chân 8,9 - Lưu trong mảng led

void setup() {
  // Thiết lập chế độ OUTPUT cho 2 chân nối với led
  pinMode(led[0], OUTPUT);
  pinMode(led[1], OUTPUT);

  // Trạng thái ban đầu của các led là tắt
  digitalWrite(led[0], LOW);
  digitalWrite(led[1], LOW);

  // Lệnh thiết lập kết nối Arduino với iNut cảm biến,
  // trong đó 8 là số luồng dữ liệu của iNut cảm biến
  inut.setup(8);

  // Bắt buộc phải có bước này: Đặt giá trị ban đầu cho 8 luồng khi mới kết nối
  for (int i = 0; i < 8; i++) {
    // Lệnh đặt giá trị dữ liệu cho luồng thứ i
    // Ban đầu thì cứ cho cả 8 luồng nhận giá trị là 0
    inut.setValue(i, 0);
  }

  // Khai báo cho iNut cảm biến: Khi nhận được lệnh "ON" thì chạy hàm onLed
  inut.addCommand("ON", onLed);
  // Khai báo cho iNut cảm biến: Khi nhận được lệnh "OFF" thì chạy hàm offLed
  inut.addCommand("OFF", offLed);
}

void loop() {
  // Cần chạy câu lệnh này trong hàm loop
  inut.loop();
}

void onLed() {
  char *thamSo = inut.next();// Lấy tham số
  int giaTri = atoi(thamSo);// Lệnh atoi sẽ chuyển 1 chuỗi thành số nguyên
  int thuTuLed = giaTri - 200;// Trừ 200 ra được thứ tự trong mảng led
  digitalWrite(led[thuTuLed], HIGH);
}

void offLed() {
  char *thamSo = inut.next();// Lấy tham số
  int giaTri = atoi(thamSo);// Lệnh atoi sẽ chuyển 1 chuỗi thành số nguyên
  int thuTuLed = giaTri - 200;// Trừ 200 ra được thứ tự trong mảng led
  digitalWrite(led[thuTuLed], LOW);
}
