#include"iostream"
using namespace std;

class Daythuc
{
	private:
		int soPhanTu;
		float *a;
	public:
		friend istream &operator >>(istream &in, Daythuc &b);
		friend ostream &operator <<(ostream &out, const Daythuc b);
		friend void liet_ke(Daythuc &b);
};

istream &operator >>(istream &in, Daythuc &b)
{
	cout <<"\nSo phan tu : ";
	in>>b.soPhanTu;
	b.a=new float[b.soPhanTu];
	for(int i=0;i<b.soPhanTu;i++)
	{
		cout <<"\n\ta["<<(i+1)<<"] : ";
		in >>b.a[i];
	}
	return in;
}

ostream &operator <<(ostream &out, const Daythuc b)
{
	int i;
	for(i=0;i<b.soPhanTu;i++)
		out <<b.a[i];
	return out;
}

void liet_ke(Daythuc &b)
{
	int i;
	for(i=1;i<b.soPhanTu - 1;i++)
		if(b.a[i-1]+b.a[i]==2*b.a[i+1] || b.a[i-1]+b.a[i+1]==2*b.a[i] || b.a[i]+b.a[i+1]==2*b.a[i-1])
			cout <<"\n"<<b.a[i-1]<<"\t"<<b.a[i]<<"\t"<<b.a[i+1];
}

int main()
{
	Daythuc b;
	cin>>b;
	cout <<"\nDay so thuc : "<<b;
	cout <<"\n3 cap so lien tiep tao thanh cap so cong : ";
	liet_ke(b);
}

