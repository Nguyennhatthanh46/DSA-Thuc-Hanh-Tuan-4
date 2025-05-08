/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
#include <bits/stdc++.h>
using namespace std;


struct DONTHUC{
	int somu;
	double heso;
	
	DONTHUC(double _heso = 0,int _somu=0){
		heso = _heso;
		somu  = _somu;
	}
	
	DONTHUC& operator = (const DONTHUC &rhs){
		if (this == &rhs) return *this;
		this->heso = rhs.heso;
		this->somu = rhs.somu;
		return *this;
	}
};


struct Node{
	DONTHUC* data;
	Node* next;
	
	Node(DONTHUC* _data = nullptr){
		this->data = _data;
		this->next = nullptr;
	}
	
};

struct DATHUC{
	Node* head;
	Node* tail;
	DATHUC(){
		this->head = nullptr;
		this->tail = nullptr;
	}
};


//###INSERT CODE HERE 
void Nhap(DATHUC &B, double heso, int somu) {
    DONTHUC* donthuc = new DONTHUC(heso, somu);
    Node* tmp = new Node(donthuc);

    if (B.head==NULL) {
        B.head = B.tail = tmp;
    } else {
        B.tail->next = tmp;
        B.tail = tmp;
    }
}

void Xuat(DATHUC B) {
    Node* p = B.head;
    bool first = true;
    bool xet = false;

while (p!=NULL) {
double heso = p->data->heso;
int somu = p->data->somu;
if (heso != 0){
xet = true;
if(!first){
if(heso > 0) cout << "+";
}
if(somu == 0){
cout << heso;
}else{
if(heso == -1)cout<< "-";
else if (heso != 1) cout << heso;
cout << "x";
if(somu != 1) cout << "^" << somu;
}
first = false;
}
p = p->next;
}
if(!xet) cout << "0";
}

double TinhDaThuc(DATHUC B, double x) {
    double kq = 0;
    Node* p = B.head;
    while (p!=NULL) {
        kq += (p->data->heso) * pow(x, p->data->somu);
        p = p->next;
    }
return kq;
}
//

int main() {
    DATHUC B;
    int N;
    
    cin >> N;
    for (int test = 0; test < N; test++){
		double heso; int somu;
		cin >> heso >> somu;
		Nhap(B,heso,somu);
    }
    
    
    cout << "Da thuc vua nhap la: "; Xuat(B);
    double x; cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "
         << setprecision(2) << fixed << TinhDaThuc(B, x);
    return 0;
}
