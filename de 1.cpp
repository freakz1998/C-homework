#include<iostream>
#include<string>
using namespace std;
class LAPTOP{
	friend class CAC_LAPTOP;
	private:
		string model, hangSanXuat;
		int gia, thoiGianBh;
	public:
		friend istream &operator >>(istream &input, LAPTOP &lap);
		friend ostream &operator << (ostream &output, LAPTOP &lap);
};

class CAC_LAPTOP{
	private:
		int soLuong;
		LAPTOP *p;
	public:
		void nhap();
		void xuat();
		void inDanhSach(); // tang dan;
};
int main(){
	CAC_LAPTOP laptop;
	laptop.nhap();
	laptop.xuat();
	cout<<"--------------------------"<<endl;
	laptop.inDanhSach();

}

istream &operator >> (istream &input, LAPTOP &lap){
	input.ignore();
	cout<<"Nhap model:"	;
	getline(input, lap.model);
	cout<<"Nhap hang san xuat: ";
	getline(input, lap.hangSanXuat);
	cout<<"Nhap gia:";
	input>>lap.gia;
	cout<<"Nhap thoi gian bao hanh: ";
	input>>lap.thoiGianBh;
	return input;
}

ostream &operator << (ostream &output, LAPTOP &lap){
	output<<"Model: "<<lap.model<<endl;
	output<<"Hang san xuat: "<<lap.hangSanXuat<<endl;
	output<<"Gia: "<<lap.gia<<endl;
	output<<"Thoi gian bao hanh: "<<lap.thoiGianBh<<endl;
	return output;
}

void CAC_LAPTOP::nhap(){
	cout<<"Nhap so luong: ";
	cin>>soLuong;
	p = new LAPTOP[soLuong + 1];
	for(int i=0; i< soLuong; i++){
		cin>>p[i];
	}
}

void CAC_LAPTOP::xuat(){
	for(int i=0; i< soLuong; i++){
		cout<<p[i];
	}
}

void CAC_LAPTOP::inDanhSach(){
	LAPTOP bienDem;
	for(int i=0; i< soLuong-1; i++){
		for(int j= i + 1; j < soLuong; j++){
			if(p[i].gia > p[j].gia){
				bienDem = p[i];
				p[i] = p[j];
				p[j] = bienDem;
			}
		}
	}
	cout<<p[2]<<endl;
	cout<<bienDem;
}
