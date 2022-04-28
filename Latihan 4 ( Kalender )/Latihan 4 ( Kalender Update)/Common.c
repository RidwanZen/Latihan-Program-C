// Header File
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static const char *months[] = {"January","February","March","April","May","June","July","August","September","October","November","December"}; // Pointer array
static const int monthDays[] = {31,28,31,30,31,30,31,31,30,31,30,31};
enum state {False, True};	// tipedata enum dengan variabel state, False = 0, True = 1

// Deklarasi Struct
typedef struct{
 char **dataOut;
 int ndata;
 int nDay;
} dataPrint;	// Nama variabel dari function struct

//Deklarasi Union
union monthtype{
	int num; 
	char str[20];
}month;		// nama variabel dari function union
	
// Function konvert integer to string
char *IntToStr(int x){
	char *str=(char *)malloc(1 * sizeof (char));	// Mengalokasikan blok memory sebesar 1byte dan di pointing ke pointer str
	sprintf(str, "%d", x);	// Memasukkan data integer x ke str
	return str;
}	

// Function untuk mendapatkan string bit-size dari index	
char *get_string_from_index(char *string, int in1, int in2){
	char *cr1 = (char*)malloc(strlen(string));	//Mengalokasikan memory byte-size dari string untuk value pointer cr1
	char *cr2 = (char*)malloc(strlen(string));	//Mengalokasikan memory byte-size dari string untuk value pointer cr2
	char *Result = (char*)malloc(strlen(string)); 	//Mengalokasikan memory byte-size dari string untuk value pointer Result
	
	strcpy(cr1,&string[in1]);	// mengcopy isi string[in1] ke cr1
	strncat (cr2, cr1, (in2+1-in1));	// menambahkan string pada cr2 dari cr1 sebesar value in2+1-in1
	
	strcat(Result, cr2); // memasukkan value cr2 ke Result
	return Result;	// mengembalikan ke result
}

// Function untuk menggabungkan kata pada string
char* gabung_kata(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1);	//Mengalokasikan memory byte-size dari s1+s2+1 ke pointer Result
    strcpy(result, s1);	// Mengcopy isi value s1 ke result
    strcat(result, s2);	// Mengcopy isi value s2 ke result
    return result;	// mengembalikan ke result
}

// Fungsi untuk mengubah sebuah karakter pada sebuah string
char* replaceWordInString(const char* s, const char* oldW, const char* newW){ 
    char* result; 
    int i, cnt = 0; 
    int newWlen = strlen(newW);	// Variabel newWlen menampung banyaknya data string pada newW
    int oldWlen = strlen(oldW); // Variabel oldWlen menampung banyaknya data string pada oldW
    for (i = 0; s[i] != '\0'; i++) { 	// Pengulangan isian string s sampai diakhir '\0'
        if (strstr(&s[i], oldW) == &s[i]) {	//mengecek string s sesuai kata oldW dan dilakukan compare karakter index ke i
            cnt++; 
            i += oldWlen - 1; 
        } 
    } 
    result = (char*)malloc(i + cnt * (newWlen - oldWlen) + 1); 
	//malloc akan mengalokasi sebanyak byte-size memory ke result
    i = 0; 
    while (*s) { // Perulangan sebanyak panjang pointer s selama tidak menunjuk ke '\0'(terminal string)
        if (strstr(s, oldW) == s) { 	// Cek data s apakah berisi value oldW
            strcpy(&result[i], newW); 	// Jika benar akan dicopy dari newW ke result[i]
            i += newWlen; 
            s += oldWlen; 
        } 
        else
            result[i++] = *s++; // Jika salah, result[i++] sama dengan value pointer s++
    } 
  
    result[i] = '\0'; // Memberikan terminator string di akhir
    return result; // Mengembalikan ke result
}

// Membuat function untuk menghilangkan space diawal string
char *trim(char *s) {
	int count = -1;
	for(int i=0;i<strlen(s)+1;i++){	// Pengulangan sebanyak data s
		if(isspace(s[i])==0){	// Jika tidak berisi spasi ,nilai count sebesar i,dan break(pengulangan berhenti)
			count = i;
			break;	// Keluar dari for()
		}
	}
	//calloc akan mengalokasikan hasil kali length s dengan bit-size char ke pointer result
	char *result = calloc((strlen(s)+1),sizeof(char));	
	int count1 = -1;
	for(int i=count;i<strlen(s)+1;i++){	// Pengulagan sebanyak bit-size s+1
		count1++;
		result[count1] = s[i];	// isi nilai result[count1] dengan nilai s[i]
	}
	
	return result;	// mengembalilkan ke result
}

// membuat Function untuk menghilangkan space di akhir string
char *shift_trim(char *s) {
	int count;
	for(int i=1;i<strlen(s)+1;i++){	// Pengulangan sebanyak bit-size s+1
		count = strlen(s)-i;	// value count = panjang data s -i
		if(isspace(s[count])==0){	// Jika tidak berisi spasi ,nilai count sebesar s-1,dan break(pengulangan berhenti)
			count = strlen(s)-i;
			break;	// Keluar dari for()
		}
	}
	//calloc akan mengalokasikan hasil kali length s dengan bit-size char ke pointer result
	char *result = calloc((strlen(s)+1),sizeof(char));
	int count1 = -1;
	for(int i=0;i<count+1;i++){	// Pengulangan sebanyak i kurang dari count+1
		count1++;	// count1 +1
		result[count1] = s[i];	// isi nilai result[count1] dengan nilai s[i]
	}
	
	result = trim(result);	// result = Function trim(result)
	return result;	// mengembalikan ke result
}

//Function pembulatan
int c_round(double x){
	return x < 0 ? x - 0.5 : x + 0.5;	// Jika x kurang dari 0, maka x - 0.5 , jika tidak x + 0.5
}

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
        return 28 + leap_days;	//28+1 hari = 29 Hari
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

// Function menghitung jumlah baris sesuai data bulan
int JumlahBaris(int hari_awal,int jumlah_hari){
	int baris;
	int nbaris = (hari_awal-1)+jumlah_hari;	// nbaris berisi (hariawal-1)+ jumlah hari
	
	if (nbaris < 29){	//jika bulannya 28 hari dan dimulai hari senin maka ada 4 baris 
		baris = 4;
	}
	else if (nbaris >35){ // jika nbaris lebih dari 35 maka value baris = 6
		baris = 6;
	}else{	// Jika tidak makan value baris = 5
		baris = 5;
	}
	
	return baris;	// mengembalikan ke baris
}

// Struct Function dataPrint diberi variabel ProcessData yang berisi integer dan char data
dataPrint ProcessData(int DayBegin,int JumlahHari, char *lineborderTop, char *lineborderVet, char *space, char *whitespace, char *dayName[], int nBaris){
	static int TanggalDummy[50];
	static int nHari = 7;
	static char *valBaris[200];
	static int HitungHari=-1;
	static char *lineborderTop1;
	static int BatasMargin1,BatasMargin2;
	static char *txtResult = NULL;
	char **datain = calloc(9999,sizeof(char)); // mengalokasikan memory
	static int countBorder = 0;
	static char *tmpchar1 = "";
	static char *tmpchar = "";
	static char *sspace = " ";
	static char *space1[7],*space2[7];
	static int pt1[7],pt2[7];
	lineborderTop1 = gabung_kata("+",lineborderTop); // Menggabungkan kata dari variabel lineborderTop dengan "+" ke dalam lineborderTop1
	datain[0] = "";
	//Mengkondisikan agar kolom hanya sebanyak 1 sampai 7
	if(DayBegin<1 || DayBegin>7){printf("Error! Day coloumn must be between 1-7\n");exit(1);}
	
	// Pengulangan TanggalDummy[i] +1 sebanyak jumlah i kurang dari Jumlah Hari
	for(int i=0;i<JumlahHari;i++){TanggalDummy[i]=i+1;}
	for(int i=0;i<nHari;i++){
		space1[i]="";
		space2[i]="";
		pt1[i] = c_round((strlen(lineborderTop)+2-strlen(dayName[i]))/2);
		pt2[i] = strlen(lineborderTop)+1-(strlen(dayName[i])+pt1[i]);
		
		for(int s=0;s<pt1[i];s++){space1[i] = gabung_kata(sspace,space1[i]);}
		for(int s=0;s<pt2[i];s++){space2[i] = gabung_kata(sspace,space2[i]);}
	}
	
	for(int i=0;i<nHari;i++){
		datain[0] = gabung_kata(datain[0],gabung_kata(gabung_kata(space1[i],dayName[i]),space2[i]));
	}
	
	for(int k=0;k<nBaris+2;k++){
		countBorder++;
		datain[countBorder] = "";
		for(int i=0;i<nHari;i++){
			txtResult = i<(nHari)-1 ? lineborderTop1 : gabung_kata(lineborderTop1,"+");
			datain[countBorder] = gabung_kata(datain[countBorder],txtResult);
		}
		if(k<nBaris){
			
			for(int j=0;j<3;j++){
				txtResult=space;
				countBorder++;
				int ndata = (strlen(lineborderTop1)*(nHari+1));
				for(int i=0;i<ndata;i++){
					tmpchar1 = tmpchar;
					if(i%strlen(lineborderTop1) == 0 || i==0){
						BatasMargin1 = i+1;
						BatasMargin2 = i+2;
						if(j==1 && i<strlen(lineborderTop1)*(nHari)){
							if(k==0 && i>=(DayBegin-1)*strlen(lineborderTop1)){HitungHari++;}
							else if(k>0){HitungHari++;}
						}
						valBaris[i]=lineborderVet;
					}
					else{valBaris[i]=" ";}
					
					if(j==1 && i<=BatasMargin2 && i>BatasMargin1 && i<strlen(lineborderTop1)*(nHari)){
						valBaris[i]=get_string_from_index(IntToStr(TanggalDummy[HitungHari]),0,0);
					}
					
					tmpchar = shift_trim(get_string_from_index(valBaris[i],0,0));
					
					if(TanggalDummy[HitungHari] > 9 && TanggalDummy[HitungHari] < 20){
						if(atoi(tmpchar1)==1){valBaris[i]=get_string_from_index(IntToStr(TanggalDummy[HitungHari]),1,1);}
					}else if(TanggalDummy[HitungHari] > 19 && TanggalDummy[HitungHari] < 30){
						if(atoi(tmpchar1)==2){valBaris[i]=get_string_from_index(IntToStr(TanggalDummy[HitungHari]),1,1);}
					}else if(TanggalDummy[HitungHari] > 29 && TanggalDummy[HitungHari] < 40){
						if(atoi(tmpchar1)==3){valBaris[i]=get_string_from_index(IntToStr(TanggalDummy[HitungHari]),1,1);}
					}else if(TanggalDummy[HitungHari] > 39 && TanggalDummy[HitungHari] < 50){
						if(atoi(tmpchar1)==4){valBaris[i]=get_string_from_index(IntToStr(TanggalDummy[HitungHari]),1,1);}
					}

					txtResult = gabung_kata(txtResult,valBaris[i]);
					for(int i=32;i<50;i++){
						if(strstr(txtResult, shift_trim(IntToStr(i))) != NULL){txtResult=replaceWordInString(txtResult,shift_trim(IntToStr(i)),"0 ");}
					}
					if(strstr(txtResult, gabung_kata(lineborderVet," 0")) != NULL){
						txtResult=replaceWordInString(txtResult,gabung_kata(lineborderVet," 0"),gabung_kata(lineborderVet,"  "));
					}
				}
				datain[countBorder] = shift_trim(txtResult);
				if(strstr(datain[countBorder], " ") != NULL){datain[countBorder]=replaceWordInString(datain[countBorder]," ",whitespace);}
			}
		}
	
	}
	
	dataPrint dataout;
	dataout.dataOut = calloc(9999,sizeof(char));
	for(int i=0;i<countBorder;i++){
		dataout.dataOut[i] = gabung_kata(space,datain[i]);
	}
	dataout.ndata = countBorder;
	dataout.nDay = TanggalDummy[HitungHari] > 31 ? 31 : TanggalDummy[HitungHari];
	
	free(datain),datain=NULL;
	
	return dataout;
}
