// Header File
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char *months[] = {"January","February","March","April","May","June","July","August","September","October","November","December"}; // Pointer array
const char hari[7][10] = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"}; //multidimensional array
static const int monthDays[] = {31,28,31,30,31,30,31,31,30,31,30,31};
enum state {False, True};	// tipedata enum dengan variabel state, False = 0, True = 1

//Declare union
union monthtype{
	int num; 
	char str[20];
}month;	
	
//Function untuk ambil data integer dari user 
int get_int(char text[]){
    int num;
    printf("%s", text);
    scanf("%i", &num);	// Input data num
    return num;	// Mengembalikan nilai num
}

// Returns 0 or 1
static int is_leap_year(int year) {	//Function cek tahun kabisat
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
		return True;	// 1
	}else {
		return False;	// 0
	}
}

// Function untuk mendapatkan hari dalam sebulan
static int get_days_in_month(int year, int month0) {
    if (month0 == 1) {	// jika month0 == 1
        int leap_days = is_leap_year(year);	// variabel leap_days berisi data dari function is_leap _year
        return 28 + leap_days;
    } else {
        return monthDays[month0];	// mengembalikan nilai data pada monthDays[month0]
    }
}

//Function untuk menentukan hari awal dalam suatu bulan
int get_startingDays(int y,int m,int d){      /* 0 = Monday */
	m++; //menyesuaikan pada array months karna element january berada di index 0
	d--; //menyesuaikan agar hari pertama adalah hari senin
    
    //algoritma hari awal dalam suatu bulan
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    y -= m < 3;
    return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}
