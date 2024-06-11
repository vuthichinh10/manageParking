File main.exe là file code cũ chưa update đủ tính năng 
File program.exe đã update đủ tính năng bao gồm :
  1. list: in ra danh sách xe trong bãi, theo thứ tự của input. Lưu ý chỉ trả về biển số. 

  2. find <plate>: tìm xe có biển số <plate> có trong bãi hay không. Ví dụ: find 31K1-123.45: in ra chỉ số của xe trong danh sách nếu tìm thấy, -1 nếu không tìm thấy 

  3. in <hh:mm:ss> <plate>: lúc <hh:mm:ss> cho xe biển số <plate> vào bãi. Ví dụ: in 10:00:02 31K1-123.45 trả về -1 nếu lỗi (xe đang trong bãi), 1 nếu thành công 

  4. out <hh:mm:ss> <plate>: lúc <hh:mm:ss> cho xe biển số <plate> ra. Ví dụ: out 03:04:56 31K1-123.45 trả về -1 nếu lỗi (xe không có trong bãi), 1 nếu thành công 

  5. cnt-moto: đếm số xe máy đang có trong bãi 

  6. bill <hh:mm:ss> <plate>: tính tiền gửi xe cho xe có biển <plate>. nếu không tìm thấy xe trong bãi trả về -1. Chú ý, chỉ tính tiền, xe vẫn ở trong bãi, không cho xe ra khỏi bãi. 

  7. billall: tính tổng số tiền gửi xe thu được từ khi bắt đầu chạy chương trình, việc thu tiền được thực hiện khi xe ra khỏi bãi.


Các hàng số đã được khai báo : success (1)
                               error   (-1)

Hàm đã được viết để người dùng có thể test các test case liên tục mà không cần chạy lại chương trình bằng các nhấn các phím bất kì sau khi 1 lượt chương trình kết 
  thúc và nhấn phím 'N' để thoát khỏi chương trình 
