#include "Function.h"


void waiting(unsigned int mseconds)
{
	clock_t goal = mseconds + clock();
	while (goal > clock());
}







void HOME_SCREEN(ACCOUNT DANHSACH[], int n)
{
	bool kiem_tra = true;
	do
	{
		system("cls");
		cout << " 1 : Dang Ky." << endl;
		cout << " 2 : Dang nhap." << endl;
		cout << " 3 : Kiem tra kho tien trong may ATM" << endl;
		cout << " 4 : Thoat." << endl;

		int lua_chon;
		cout << "Lua chon cua ban: ";
		cin >> lua_chon;

		switch (lua_chon)
		{
		case 1: {
			system("cls");
			waiting(1000);
			DANGKY();
			system("pause");
			break;
		}
		case 2: 
		{
			system("cls");
			waiting(1000);
			ACCOUNT X;
			if(DANGNHAP(DANHSACH, n, X))
			{
				MENU(DANHSACH, n, X);
			}
			system("pause");
			break;
		}
		case 4:
		{
			cout << "BAN THAT SU MUON THOAT? " << endl;
			cout << " 1: CO." << endl;
			cout << " 2: KHONG." << endl;

			int lc;
			cout << "Nhap lua chon cua ban: ";
			cin >> lc;

			if (lc == 1) {
				kiem_tra = false;
				break;
			}
		}
		case 3:
		{
			system("cls");
			CHECK_ATM();
			system("pause");
			break;
		}
		}
	} while (kiem_tra);

}


void DANGKY()
{
	ACCOUNT X;
	cout << "Nhap ID cua ban: ";
	cin >> X.ID;
	string password2;
	
	do {
		cout << "Nhap PASSWORD: ";
		cin >> X.PASSWORD;
		cout << "\nNhap lai PASSWORD: ";
		cin >> password2;
	} while (X.PASSWORD != password2);
	cout << "Dang Ky Thanh Cong." << endl;
	HAMGHI(X);


}

void HAMGHI(ACCOUNT X)
{
	ofstream FILE;
	FILE.open("Danh_Sach.txt", ios::app);
	FILE << X.ID << " " << X.PASSWORD << " " << X.money << endl;
	FILE.close();
}


int HAMDOC(ACCOUNT DANHSACH[], int &n)
{
	n = 0;
	ifstream F;
	F.open("Danh_Sach.txt", ios::in);
	if (F.fail()) return 0;
	while (!F.eof())
	{
		ACCOUNT t;
		getline(F, t.ID, ' ');
		getline(F, t.PASSWORD, ' ');
		long long money;
		F >> money;
		t.money = money;
		DANHSACH[n] = t;
		n++;
		string line;
		getline(F, line);
	}
	n--;
	
	return n;
}

bool CHECK_DANGNHAP(ACCOUNT DANHSACH[], int n, ACCOUNT X)
{
	for (int i = 0; i < n; i++)
	{

		if (DANHSACH[i].ID == X.ID)
		{
			if (DANHSACH[i].PASSWORD == X.PASSWORD)
			{
				return true;
			}
		}
	}
	return false;
}

bool DANGNHAP(ACCOUNT DANHSACH[], int n, ACCOUNT X)
{
	int dem = 0;
	system("cls");
	waiting(1000);
	do
	{
		cout << "Nhap ID: ";
		cin >> X.ID;
		cout << "\nNhap PASSWORD: ";
		cin >> X.PASSWORD;
		dem++;
		if (dem > 5) {
			cout << "Bn dang nhap sai qua 5 lan, chung toi tam khoa tai khoan!";
			return false;
		}
	} while (!CHECK_DANGNHAP(DANHSACH, n, X));
	cout << "\n\nDANG NHAP THANH CONG" << endl;
	waiting(1000);
	return true;
}



int MANG[6] = { 0 };

void MENU(ACCOUNT DANHSACH[], int n, ACCOUNT &X)
{
	bool kiem_tra = true;
	do
	{
		system("cls");
		cout << "MENU" << endl;
		cout << "1: Gui tien" << endl;
		cout << "2: Rut tien" << endl;
		cout << "3: Kiem Tra Tai Khoan" << endl;
		cout << "4: Dang Xuat Tai Khoan" << endl;
		cout << "5: Thoat" << endl;

		int lua_chon;
		cout << "Lua chon cua ban: ";
		cin >> lua_chon;

		switch (lua_chon) {
		case 5:
		{
			system("cls");
			cout << "BAN THAT SU MUON THOAT? " << endl;
			cout << " 1: CO." << endl;
			cout << " 2: KHONG." << endl;

			int lc;
			cout << "Nhap lua chon cua ban: ";
			cin >> lc;

			if (lc == 2) {
				system("pause");
				break;
			}
			else exit(0);
		}
		case 1:
		{
			GUITIEN(X, DANHSACH, n);
			system("pause");
			break;
		}
		case 3:
		{
			system("cls");
			KIEM_TRA_TAI_KHOAN(X);
			system("pause");
			break;
		}
		case 2:
		{
			system("cls");
			RUTTIEN(X, DANHSACH, n);
			system("pause");
			break;
		}
		case 4:
		{
			system("cls");
			DANGXUAT();
			system("pause");
			break;
		}
		}
	} while (kiem_tra);
}


// Quy uoc mang 0-->500k.  1--->200, ....


void GUITIEN(ACCOUNT &X, ACCOUNT DANHSACH[], int& n)
{
	system("cls");
	cout << "BAN MUON GUI TIEN" << endl;
	cout << "Menh gia tien ban gui: ";
	int money;
	cin >> money;
	cout << "So to: ";
	int so_to;
	cin >> so_to;
	cout << "DA GUI THANH CONG" << endl;
	cout << "Nhan enter de quay lai MENU" << endl;

	doc_tien_vao_ATM();


	if (money == 500000) MANG[0] += so_to;
	 else if (money == 200000) MANG[1] += so_to;
	 else if (money == 100000) MANG[2] += so_to;
	 else if (money == 50000) MANG[3] += so_to;
	 else if (money == 20000) MANG[4] += so_to;
	 else if (money == 10000) MANG[5] += so_to;

	ghi_tien_vao_ATM();

	HAMDOC(DANHSACH, n);
	X.money += money * so_to;
	
	for (int i = 0; i < n; i++)
	{
		if (DANHSACH[i].ID == X.ID) {
			DANHSACH[i].money = X.money;
			
			break;
		}
	}
		HAM_GHI_DANHSACH(n, DANHSACH);
}

void HAM_GHI_DANHSACH(int n, ACCOUNT DANHSACH[])
{
	ofstream F;
	F.open("Danh_Sach.txt", ios::out);
	for (int i = 0; i < n; i++)
	{
		F << DANHSACH[i].ID << " " << DANHSACH[i].PASSWORD << " " << DANHSACH[i].money << endl;

	}
	F.close();
}


void ghi_tien_vao_ATM()
{
	ofstream F;
	F.open("tien_ATM.txt", ios::out);
	for (int i = 0; i < 6; i++)
	{
		F << MANG[i] << " ";
	}
	F.close();
}


void doc_tien_vao_ATM()
{
	ifstream F;
	F.open("tien_ATM.txt", ios::in);
	if (F.fail()) return;
	for (int i = 0; i < 6; i++)
	{
		F >> MANG[i];
	}
	F.close();

}



void KIEM_TRA_TAI_KHOAN(ACCOUNT &X)
{
	cout << "So tien hien co:" <<X.money << endl;
}

void RUTTIEN(ACCOUNT &X, ACCOUNT DANHSACH[], int& n)
{
	cout << "Ban muon rut tien:" << endl;
	cout << "\nSo tien can rut: ";
	long long money;
	cin >> money;
	int tien_rut = money;

	doc_tien_vao_ATM();

	int so_to = 0;
	int dem1 = 0, dem2 = 0, dem3 = 0, dem4 = 0, dem5 = 0, dem6 = 0;
	if (money >= 500000)
	{
		for (; money >= 500000 && dem1 <= MANG[0]; money -= 500000) {
			dem1++;
			MANG[0]--;
		}
	}
	if (money >= 200000)
	{
		for (; money >= 200000 && dem2 <= MANG[1]; money -= 200000) {
			dem2++;
			MANG[1]--;
		}
	}
	if (money >= 100000)
	{
		for (; money >= 100000 && dem3 <= MANG[2]; money -= 100000) {
			dem3++;
			MANG[2]--;
		}
	}
	if (money >= 50000)
	{
		for (; money >= 50000 && dem4 <= MANG[3]; money -= 50000) {
			dem4++;
			MANG[3]--;
		}
	}
	if (money >= 20000)
	{
		for (; money >= 20000 && dem5 <= MANG[4]; money -= 20000) {
			dem5++;
			MANG[4]--;
		}
	}
	if (money >= 10000)
	{
		for (; money >= 10000 && dem6 <= MANG[5]; money -= 10000) {
			dem6++;
			MANG[5]--;
		}
	}


	if (dem1 > 0)cout << "So to 500.000: " << dem1 << " to." << endl;
	if (dem2 > 0)cout << "So to 200.000: " << dem2 << " to." << endl;
	if (dem3 > 0)cout << "So to 100.000: " << dem3 << " to." << endl;
	if (dem4 > 0)cout << "So to 50.000: " << dem4<< " to." << endl;
	if (dem5 > 0)cout << "So to 20.000: " << dem5 << " to." << endl;
	if (dem6 > 0)cout << "So to 10.000: " << dem6 << " to." << endl;
	cout << "TONG CONG: " << tien_rut << " VND" << endl;


	cout << "RUT THANH CONG!" << endl;
	cout << "NHAN ENTER DE TRO VE MENU." << endl;
	system("pause");

	X.money -= money;

	ghi_tien_vao_ATM();

	HAMDOC(DANHSACH, n);
	

	for (int i = 0; i < n; i++)
	{
		if (DANHSACH[i].ID == X.ID) {
			DANHSACH[i] = X;

			break;
		}
	}
	HAM_GHI_DANHSACH(n, DANHSACH);
}


void DANGXUAT()
{
	cout << "XAC NHAN DANG XUAT" << endl;
	cout << "1: CO" << endl;
	cout << "2: KHONG" << endl;
	
	int lc;
	cout << "LUA CHON CUA BAN: ";
	cin >> lc;
	if (lc == 2) return;
	else exit(0);
}

void CHECK_ATM()
{
	ifstream F;
	F.open("tien_ATM.txt", ios::in);
	if (!F.fail())
	{
		while (!F.eof()) {
			int n;
			if (F >> n) {
				cout << "So to 500.00 trong may ATM la:" << n << " to." << endl;
			}
		}
	}
	F.close();
	cout << "\n\n NHAN ENTER DE THOAT" << endl;
}


void CHUYENTIEN(ACCOUNT& X , ACCOUNT DANHSACH[], int n) 
{

}