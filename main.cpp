#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stdio.h>
using namespace std ;
#define error (-1) ;
#define success (1);

struct data{
    int16_t h ;
	int16_t m;
	int16_t s;
    string plate ;
};
//Chuyển từ kiểu char sang int
int charToInt(char x){
	return (int)x - 48 ;
}
//In ra danh sách xe có trong bãi
void list_C(vector<data> x){
	int n = x.size() ;
	if(n > 0 ){
		for (int i = 0 ; i < n ; i++){
			std::cout << x[i].h << ":" << x[i].m << ":" << x[i].s << "  " << x[i].plate << endl;
		}
	}

}
//Tìm kiếm xe có biến số cho trước
int find_C(string plate , vector<data> x){
	int n = x.size() ;
	if(n > 0 ){
		for (int i = 0 ; i < n ; i++){
			if(plate == x[i].plate)
			{
				return i ;	
			}
		}
	}
	return error ;
}
//cho xe vào bãi 
int in_C(data a , vector<data> &x){
	int n = find_C(a.plate , x ) ;
	if(n != -1){
		return error ;
	}
	x.push_back(a) ;
	return success ;
}
// cho xe ra bãi 
int out_C(data a , vector<data> &x){
    int n = find_C(a.plate , x ) ;
    if(n != -1){
        x.erase(x.begin() + n);
        return success ;
    }
		return error;
}


//tính tổng xe máy có trong bãi

int cnt_moto_C(vector<data> x){
	int n = x.size() ;
	int count = 0 ;
	for(int i = 0 ; i < n ; i++){
		if(x[i].plate.find("xxxx") == string::npos) {
			count++;
		}
	}
	return count ;
}
//Tính tiền cho xe đã vào một thời điểm nào đó
int bill_C(data a , vector<data> x){
	int n = find_C(a.plate , x) ;
	int total = 0 ;
	if(n == -1 ){
		return error ;
	}
	int day = ((x[n].h >= 6 && x[n].h < 18) && (a.h > x[n].h && a.h < 18)) || (a.h == x[n].h && a.m > x[n].m);
	int night = ((x[n].h >= 0 && x[n].h < 6) && (a.h > x[n].h && a.h < 6 )) || ((x[n].h >= 18 && x[n].h < 24) && (a.h > x[n].h && a.h < 24 )) || (a.h == x[n].h && a.m > x[n].m);
	int day_night = ((x[n].h >= 0 && x[n].h < 6) && (a.h >= 6 && a.h < 18 )) || ((x[n].h >= 6 && x[n].h < 18) && (a.h >= 18 && a.h < 24 )) ;
	int night_day_night = (x[n].h >= 0 && x[n].h < 6) && (a.h >= 18 && a.h < 24 );
	if(a.plate.find("xxxx") == string::npos){
		if(day){
			total = 3 ;
		}
		if(night){
			total = 5 ;
		}
		if(day_night){
			total = 8 ;
		}
		if(night_day_night){
			total = 13;
		}
		return total ;
	}
	if(day){
		total = 1 ;
	}
	if(night){
		total = 2;
	}
	if(day_night){
		total = 3 ;
	}
	if(night_day_night){
		total = 5;
	}	
	return total ;
}
//Tính tổng tiền từ khi chương trình chạy
int billAll_C(vector<data> x , vector<data> y){
	int n = x.size() ;
	int billAll = 0 ;
	int i = 0;
	if(n > 0){
		while(i < n){
			billAll += bill_C(x[i] , y) ;
			i++;
		}
	}
	return billAll ;
}
// Hiển thị thông tin phần input
void showInput(vector<string> l){
	int n = l.size() ;
	int i = 0 ;
	while ( i < n )
	{	
		if(l[i] == "***"){
			break ;
		}
		if((l[i] == "list") || (l[i] == "cnt-moto") || (l[i] == "*") ){
			std::cout << l[i] << endl ;
			i++;
		}else if((l[i] == "in") || (l[i] == "out") || (l[i] == "bill")){
			std::cout << l[i] << " " << l[i+1] << " " << l[i+2] << endl ;
			i += 3;
		}else{
			std::cout << l[i] << " " << l[i+1] << endl ;
			i += 2;
		}
	}
}


int main(){
	char state = ' ' ;
	while(1){
	vector<data> parking ;
	vector<string> listInput ;
	vector<data> listAfterOut ;
	vector<data> listBeforeOut ;
// Nhập dữ liệu
	std::cout<<"Please enter a list of times and license plates and command ! " <<endl;
	while (1)
	{
		string cp = " ";
		std::cin>> cp ;
		if (cp == "***"){
			listInput.push_back(cp);
			break;
		}
		listInput.push_back(cp);
	}

 	int n = listInput.size() ;
	int i = 0 ;
	if(n>2){
		std::cout << "---------------------------------------------------------------" << endl ;
		while (i<n){
			if(listInput[i] == "*"){
				i++ ;
				continue;
			}
			if(listInput[i] == "***"){
				break;
			}
			if(listInput[i] == "list"){
				list_C(parking) ;
				i++ ;
			}else if (listInput[i] == "find")
			{
				std::cout << find_C(listInput[i+1] , parking) << endl; 
				i += 2 ;
			}else if(listInput[i] == "billall"){
				std::cout<< billAll_C(listAfterOut , listBeforeOut) << endl ;
				i++;

			}else if (listInput[i] == "cnt-moto")
			{
				std::cout << cnt_moto_C(parking) << endl ;
				i++ ;
			}else if (listInput[i] == "in")
			{	
				int h1 , h2 , h , m1 , m2 , m , s1 , s2 , s ;
				h1 = charToInt(listInput[i+1][0]) ;
				h2 = charToInt(listInput[i+1][1]) ;
				h = h1*10 + h2 ;
				m1 = charToInt(listInput[i+1][3]) ;
				m2 = charToInt(listInput[i+1][4]) ;
				m = m1*10 + m2 ;
				s1 = charToInt(listInput[i+1][6]) ;
				s2 = charToInt(listInput[i+1][7]) ;
				s = s1*10 + s2 ;
				data a = {h ,m, s , listInput[i+2]} ;
				std::cout << in_C(a , parking) << endl ;
				i += 3 ;
			}else if (listInput[i] == "out")
			{
				int h1 , h2 , h , m1 , m2 , m , s1 , s2 , s ;
				h1 = charToInt(listInput[i+1][0]) ;
				h2 = charToInt(listInput[i+1][1]) ;
				h = h1*10 + h2 ;
				m1 = charToInt(listInput[i+1][3]) ;
				m2 = charToInt(listInput[i+1][4]) ;
				m = m1*10 + m2 ;
				s1 = charToInt(listInput[i+1][6]) ;
				s2 = charToInt(listInput[i+1][7]) ;
				s = s1*10 + s2 ;
				data a = {h ,m, s , listInput[i+2]} ;
				int index = find_C(listInput[i+2], parking) ;
				if(index != -1)
				{
					listBeforeOut.push_back(parking[index]) ;
				}
				listAfterOut.push_back(a); 
				std::cout << out_C(a , parking) << endl ;
				i += 3 ;
			}else if (listInput[i] == "bill")
			{
				int h1 , h2 , h , m1 , m2 , m , s1 , s2 , s ;
				h1 = charToInt(listInput[i+1][0]) ;
				h2 = charToInt(listInput[i+1][1]) ;
				h = h1*10 + h2 ;
				m1 = charToInt(listInput[i+1][3]) ;
				m2 = charToInt(listInput[i+1][4]) ;
				m = m1*10 + m2 ;
				s1 = charToInt(listInput[i+1][6]) ;
				s2 = charToInt(listInput[i+1][7]) ;
				s = s1*10 + s2 ;
				data a = {h ,m, s , listInput[i+2]} ;
				std::cout << bill_C(a,parking) << endl ;
				i += 3 ;
			}else{
				int h1 , h2 , h , m1 , m2 , m , s1 , s2 , s ;
				h1 = charToInt(listInput[i][0]) ;
				h2 = charToInt(listInput[i][1]) ;
				h = h1*10 + h2 ;
				m1 = charToInt(listInput[i][3]) ;
				m2 = charToInt(listInput[i][4]) ;
				m = m1*10 + m2 ;
				s1 = charToInt(listInput[i][6]) ;
				s2 = charToInt(listInput[i][7]) ;
				s = s1*10 + s2 ;				
				data a = {h ,m, s , listInput[i+1]} ;
				in_C(a , parking)  ;
				i += 2 ;			
			}
			
		}
		
	}
	std::cout<< "Enter 'N' to exit , 'Y' to continue test" << endl;
	std::cin >> state ;
	if(state == 'N'){
		break;
	}
}
return 0 ;
}