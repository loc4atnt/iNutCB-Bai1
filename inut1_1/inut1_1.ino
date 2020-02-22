#include <iNut.h>

iNut inut;// Khởi tạo đối tượng iNut

void setup() {
  // Lệnh thiết lập kết nối Arduino với iNut cảm biến,
  // trong đó 8 là số luồng dữ liệu của iNut cảm biến
  inut.setup(8);
                
  // Bắt buộc phải có bước này: Đặt giá trị ban đầu cho 8 luồng khi mới kết nối
  for(int i = 0;i<8;i++){
    // Lệnh đặt giá trị dữ liệu cho luồng thứ i
    // Ban đầu thì cứ cho cả 8 luồng nhận giá trị là 0
    inut.setValue(i, 0);
  }
}

void loop() {
  int val = analogRead(A5);// Đọc giá trị quang trở
  inut.setValue(0, val);// Đặt giá trị dữ liệu cho luồng số 0 là giá trị quang trở

  // Cần chạy câu lệnh này trong hàm loop
  inut.loop();
}
