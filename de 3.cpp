#include<iostream>
#include<string>
using namespace std;
class THI_SINH{
	friend class CAC_THI_SINH;
	private:
		int soBaoDanh;
		string hoTen, truong;
		float diem;
	public:
		friend istream &operator>>(istream &input, THI_SINH &ts);
		friend ostream &operator<<(ostream &output, THI_SINH &ts);
};

class CAC_THI_SINH{
	private:
		int soThiSinh;
		THI_SINH *ts;
	public:
		void nhap();
		void xuat();
		void thongKe();
};
int main(){
	CAC_THI_SINH thiSinh;
	thiSinh.nhap();
	cout<<"-----------------------------"<<endl;
	cout<<"Xuat thi Sinh:"<<endl;
	thiSinh.xuat();
	thiSinh.thongKe();
}

istream &operator>>(istream &input, THI_SINH &ts){
	cout<<"Nhap so bao danh:";
	input>>ts.soBaoDanh;
	input.ignore();
	cout<<"Nhap ho ten: ";
	getline(input, ts.hoTen);
	cout<<"Nhap truong: ";
	getline(input, ts.truong);
	cout<<"Nhap diem: ";
	input>>ts.diem;
	return input;
}

ostream &operator<<(ostream &output, THI_SINH &ts){
	output<<"So bao danh: "<<ts.soBaoDanh<<endl;
	output<<"Ho ten: "<<ts.hoTen<<endl;
	output<<"Nhap truong: "<<ts.truong<<endl;
	output<<"Nhap diem: "<<ts.diem<<endl;
	return output;
}

void CAC_THI_SINH::nhap(){
	cout<<"Nhap so thi sinh: ";
	cin>>soThiSinh;
	ts = new THI_SINH[soThiSinh + 1];
	for(int i=0; i< soThiSinh; i++){
		cout<<"Nhap Thi Sinh"<<i+1<<endl;
		cin>>ts[i];
	}
}

void CAC_THI_SINH::xuat(){
	for(int i=0; i< soThiSinh; i++){
		cout<<ts[i]<<endl;
	}
}

void CAC_THI_SINH::thongKe(){
	int dem =0, max = 0, imax;
	float s;
	for(int i=0; i< soThiSinh-1; i++){
		s = ts[i].diem;
		for(int j= i+1; j< soThiSinh; j++ ){
			if(ts[i].truong.compare(ts[j].truong) == 0){
				s = s + ts[j].diem;
			}
			if(s > max){
				max = s;
				imax = i;
			}
			for(int k = i-1; k>=0; k--){            //kiem tra khong bi lap thi sinh
				if(ts[k].truong.compare(ts[i].truong) == 0){
					dem++;
				}
			}
		}
		if(dem == 0){
				cout<<"Tong diem cua truong "<<ts[i].truong<<" la: "<<s<<endl;
		}
	}
	cout<<"Truong co diem cao nhat la: "<<ts[imax].truong<<", Tong diem: "<<max;
}
