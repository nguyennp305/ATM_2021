#pragma once
#pragma once
#include<iostream>
#include<string>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<iomanip>
#include<fstream>

using namespace std;

struct ACCOUNT
{
	string ID;
	string PASSWORD;
	long long money = 0;
};

void waiting(unsigned int mseconds);

void HOME_SCREEN(ACCOUNT DANHSACH[], int n);

void HAMGHI(ACCOUNT X);

void DANGKY();

int HAMDOC(ACCOUNT DANHSACH[], int& n);

bool CHECK_DANGNHAP(ACCOUNT DANHSACH[], int n, ACCOUNT X);

bool DANGNHAP(ACCOUNT DANHSACH[], int n, ACCOUNT X);

void MENU(ACCOUNT DANHSACH[], int n, ACCOUNT &X);

void GUITIEN(ACCOUNT& X, ACCOUNT DANHSACH[], int& n);

void HAM_GHI_DANHSACH(int n, ACCOUNT DANHSACH[]);

void ghi_tien_vao_ATM();

void doc_tien_vao_ATM();

void KIEM_TRA_TAI_KHOAN(ACCOUNT &X);

void RUTTIEN(ACCOUNT &X, ACCOUNT DANHSACH[], int& n);

void DANGXUAT();

void CHECK_ATM();