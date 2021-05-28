#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<iomanip>
#include<cmath>
class man {
protected:
	string name, sex, ngaysinh;
public:
	man() {
		name =sex=ngaysinh= ' ';	
	}
   virtual  void set() {
		cout << " Nhap ten:";
		cin.ignore();
		getline (cin, name);	
		cout << " Nhap ngay,thang,nam sinh: ";
		cin >> ngaysinh;
		cin.ignore();
		cout << " Gioi tinh: ";
		cin >> sex;
		
	}
	virtual void get() {

		cout <<"Ho ten:"<<name;
		cout << "\nSinh ngay:" << ngaysinh;
		cout << "\nGioi tinh:" << sex;
	}
};

class nhansu :public man{
protected:
	string chucvu;
	int namvaolam;
	string id;
public:
	nhansu() {
		chucvu = " ";
		namvaolam;
		id = " ";
	}
	
    void set() {
	    man::set();
		cout << " Nhap chuc vu:(GD=Giam Doc,TP=Truong phong,NV=Nhan vien):";
		cin.ignore();
		getline(cin, chucvu);
		cout << " Nhap id:";
		cin >> id;
		cout << " Nam vao lam:";
		cin >> namvaolam;
	}
	void get(){	
		man::get();
		cout << "\nChuc vu: " << chucvu;
		cout << "\nNam vao lam: " << namvaolam;
		cout << "\nid:" << id<<endl;
	}
};
class quanly :public nhansu {
protected:
	int songaynghi, tangca;
	vector<quanly*> ds;
public:
	//nhap danh sach cac nhan su
	void nhapdanhsach() {
		int x;
		cout << "So luong nhan su can nhap thong tin:";
		cin >> x;
		for(int i=0;i<x;i++){
			quanly* ns = new quanly();
			cout << "Nhan su thu " << i+1 << endl;
			fflush(stdin);
			ns->set();
			ds.push_back(ns);
		} 
	}
	//xuat danh sach nhan su
	void xuatdanhsach() {
		for (int i =0, lent = ds.size(); i < lent; i++) {
			cout << "STT:" << i + 1<<endl;
			ds[i]->get();
		}
	}
	float tinhluong() {
		//tinhcong;
		for (int i = 0, lent = ds.size(); i < lent; i++) {
			system("cls");
			ds[i]->get();
			cout << " Nhap so ngay nghi :";
			cin >> ds[i]->songaynghi;
			cout << " Nhap so ngay tang ca :";
			cin >> ds[i]->tangca;
			system("pause");
		}
		//tinh luong
		system("cls");
		cout << "\t=====BANG LUONG NHAN SU TRONG THANG=====\n\n "<<endl;
		cout << setw(3) << "  STT" << setw(12) << "Ho va Ten" << setw(12) << "Chuc vu" << setw(6) << "ID" << setw(16) << "Luong(USD $)" << setw(4) << endl;
		for (int i = 0, lent = ds.size(); i < lent; i++) {
			if (ds[i]->chucvu =="GD") {
				cout << setw(3) << i+1 << setw(16) << ds[i]->name << setw(9) << ds[i]->chucvu << setw(10) <<ds[i]->id<<setw(10)<< pow(1.1,2021 - ds[i]->namvaolam)*(100 * (28 - ds[i]->songaynghi) + 150 * ds[i]->tangca)<<endl  ;		
			}
			if (ds[i]->chucvu =="TP") {
				cout << setw(3) << i + 1 << setw(16) << ds[i]->name << setw(9) << ds[i]->chucvu << setw(10) << ds[i]->id << setw(10) << pow(1.1, 2021 - ds[i]->namvaolam)*(40 * (28 - ds[i]->songaynghi) + 60 * ds[i]->tangca) << endl;
			}
			if (ds[i]->chucvu == "NV") {
				cout << setw(3) << i + 1 << setw(16) << ds[i]->name << setw(9) << ds[i]->chucvu << setw(10) << ds[i]->id << setw(10) << pow(1.1, 2021 - ds[i]->namvaolam)*(20 * (28 - ds[i]->songaynghi) + 30 * ds[i]->tangca) << endl;
			}
		}
		return 0;
	
	}
	//tìm kiếm nhân viên theo id
	 void timkiem() {
		string idx;
		fflush(stdin);
		int k=0;
		do {
			system("cls");
			cout << "Nhap id nhan su can tim :";
			cin >> idx;
			for (int i = 0, lent = ds.size(); i < lent; i++) {
				if (ds[i]->id == idx) {
					k = 1;
					ds[i]->get();
					break;
				}
			}
				if (k == 0) {
					cout << "\nNhan su khong ton tai ! nhan 0 de nhap lai hoac so bat ki de thoat. "<<endl;
					cin >> k;
				}
    
		} while (k == 0);
	}
	
	//xóa nhân viên theo id;
	 void xoathongtin() {
		 string idx;
		 fflush(stdin);
		 int k=0 ;
		 do {
			 system("cls");
			 cout << "Nhap id nhan su can xoa:";
			 cin >> idx;
			 for (int i = ds.size() - 1; i >= 0; i--) {
				 if (ds[i]->id == idx) {
					 k = 1;
					 ds.erase(ds.begin() + i);
					 cout << "Da xoa nhan su " << endl;
					 break;
				 }
			 }
			 if (k == 0) {
				 cout << "\nNhan su khong ton tai ! nhan 0 de nhap lai hoac so bat ki de thoat. " << endl;
				 cin >> k;
			 }
		 } while (k == 0);
	 }
	 void suathongtin() {
		 string idx;
		 fflush(stdin);
		 int a = 0;
		 do {
			 system("cls");
			 cout << "Nhap id nhan su :";
			 cin >> idx;
			 int k;
			 for (int i = 0, lent = ds.size(); i < lent; i++) {
				 if (ds[i]->id == idx) {
					 a = 1;
					 do {
						 system("cls");
						 ds[i]->get();
						 cout << "\nChon thong tin can sua :" << endl;
						 cout << "1.Ho va ten." << endl;
						 cout << "2.Chuc vu." << endl;
						 cout << "3.ID" << endl;
						 cout << "0.Thoat." << endl;
						 cin >> k;
						 switch (k) {
						 case 1: {
							 cout << "Ho ten:";
							 cin.ignore();
							 getline(cin, ds[i]->name);
							 break;
						 }
						 case 2: {
							 cout << "\nChuc vu:";
							 cin >> ds[i]->chucvu;
							 break;
						 }
						 case 3: {
							 cout << "\nID:";
							 cin >> ds[i]->id;
							 break;
						 }
						 case 0: {
							 break;
						 }
						 }
					 } while (k != 0);
				 }
			 }
		if (a==0){
		cout << "Khong tim thay.Moi nhap lai!";	
		}
		 } while (a == 0);	
	 }
};

int main() {
	quanly n;
	int chon;
	do {
		system("cls");
		cout << "\t\t\t\t\t=========CHUONG TRINH QUAN LY NHAN SU=============" << endl;
		cout << "Vui long chon chuc nang ban muon thao tac :" << endl;
		cout << "  1.Them nhan su moi. " << endl;
		cout << "  2.Xem danh sach nhan su." << endl;
		cout << "  3.Xoa nhan su. " << endl;
		cout << "  4.Tim kiem nhan su." << endl;
		cout << "  5.Sua thong tin." << endl;
		cout << "  6.Bang luong thang. "<<endl;
		cout << "  0.Thoat" << endl;
		cin >> chon;
		switch (chon) {
		case 1: {
			system("cls");
			n.nhapdanhsach();
			system("pause");
			break;
		}
		case 2: {
			system("cls");
			cout << "\t\t\tDANH SACH NHAN SU " << endl;
			n.xuatdanhsach();
			system("pause");
			break;
		}
		case 3: {
			system("cls");
			n.xoathongtin();
			system("pause");
			break;
		}
		case 4: {
			system("cls");
			n.timkiem();
			system("pause");
			break;
		}
		case 0: {
			break;
		}
		case 5: {
			system("cls");
			n.suathongtin();
			system("pause");
			break;
		}
		case 6: {
			system("cls");
			n.tinhluong();
			system("pause");
			break;
		}
		}
	} while (chon != 0);
}
