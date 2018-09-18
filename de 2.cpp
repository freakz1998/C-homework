#include<iostream>
#include<string>
using namespace std;
class DAY_DEP{
	friend class CAC_LOAI;
	private:
		string maHang;
		int loai;
		int gia;
	public:
		friend istream &operator >> (istream &input, DAY_DEP &giayDep);
		friend ostream &operator << (ostream &output, DAY_DEP &giayDep);
};

class CAC_LOAI{
	private:
		int soLuong;
		DAY_DEP *d;
	public:
		void nhap();
		void xuat();
		void thongKe();
};
int main(){
	CAC_LOAI matHang;
	matHang.nhap();
	matHang.xuat();
	matHang.thongKe();
}

istream &operator >> (istream &input, DAY_DEP &giayDep){
	input.ignore();
	cout<<"Nhap ma hang:";
	getline(input, giayDep.maHang);
	do{
		cout<<"Nhap loai giay dep:";
		input>>giayDep.loai;
		if(giayDep.loai <= 0 | giayDep.loai >=5){
			cout<<"Nhap sai moi nhap lai!";
		}
	}while(giayDep.loai <= 0 | giayDep.loai >=5);
	cout<<"Nhap gia: ";
	input>>giayDep.gia;
	return input;
}

ostream &operator << (ostream &output, DAY_DEP &giayDep){
	output<<"Ma hang: "<<giayDep.maHang<<endl;
	output<<"Loai giay dep:"<<giayDep.loai<<endl;
	output<<"Gia: "<<giayDep.gia<<endl;
	return output;
}

void CAC_LOAI::nhap(){
	cout<<"Nhap so luong: ";
	cin>>soLuong;
	d = new DAY_DEP[soLuong + 1];
	for(int i=0; i< soLuong; i++){
		cin>>d[i];
	}
}

void CAC_LOAI::xuat(){
	for(int i=0; i< soLuong; i++){
		cout<<d[i];
	}
}

void CAC_LOAI::thongKe(){
	int loai1 =0, loai2 =0, loai3 =0, loai4 =0;
	for(int i=0; i< soLuong; i++){
		if(d[i].loai == 1){
			loai1++;
		}
		if(d[i].loai == 2){
			loai2++;
		}
		if(d[i].loai == 3){
			loai3++;
		}
		if(d[i].loai == 4){
			loai4++;
		}
	}
	cout<<"So Luong loai 1:"<<loai1<<endl;
	cout<<"So Luong loai 2:"<<loai2<<endl;
	cout<<"So Luong loai 3:"<<loai3<<endl;
	cout<<"So Luong loai 4:"<<loai4<<endl;
}
