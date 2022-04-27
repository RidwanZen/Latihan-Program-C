// Headers File
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Inisialisasi Variable
int datainput_1[99999],datainput_2[99999],datainput_3[99999],datainput_4[99999],datainput_5[99999];
int number_data;
char *txtResult = NULL;
char datain1[200],dataraw[999999][200];

// Fungsi mennyederhanakan variabel Pointer ke pointer
typedef struct{
 char **Input1;
 char **Input2;
 char **Input3;
 char **Input4;
 char **Input5;
 int ndata;
} dataInput;	// Nama Variabel dari fungsi struct

// Fungsi untuk mengubah sebuah karakter pada sebuah string
char* replaceWordInString(const char* s, const char* oldW, const char* newW){ 
    char* result; 
    int i, cnt = 0; 
    int newWlen = strlen(newW); // Variabel newWlen menampung banyaknya data string pada newW
    int oldWlen = strlen(oldW); // Variabel oldWlen menampung banyaknya data string pada oldW
    for (i = 0; s[i] != '\0'; i++) { 	// Pengulangan isian string s sampai diakhir '\0'
        if (strstr(&s[i], oldW) == &s[i]) { //mengecek string s sesuai kata oldW dan dilakukan compare karakter index ke i
            cnt++; 
            i += oldWlen - 1; 
        } 
    } 
    result = (char*)malloc(i + cnt * (newWlen - oldWlen) + 1); // i=22,+ cnt=8,* (newWlen=1, oldWlen=1)+1 hasilnya = 23 banyaknya string
    //malloc akan mengalokasi sebanyak 23byte memory yang dipointing ke pointer result
  
    i = 0; 
    while (*s) { // Perulangan sebanyak panjang pointer s selama tidak menunjuk ke '\0'(terminal string)
        if (strstr(s, oldW) == s) { // Cek data s apakah berisi karakter ","
            strcpy(&result[i], newW); // Jika benar akan diubah menjadi " "
            i += newWlen; 
            s += oldWlen; 
        } 
        else
            result[i++] = *s++; 
    } 
  
    result[i] = '\0'; // Memberikan terminator string di akhir
    return result; 
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
	
	char *result = calloc((strlen(s)+1),sizeof(char));	// mengalokasi blok memory sebanyak s+1
	int count1 = -1;
	for(int i=count;i<strlen(s)+1;i++){	// Pengulangan untuk copy data string ke result
		count1++;
		result[count1] = s[i];
	}
	
	return result;
}
// membuat Function untuk menghilangkan space di akhir string
char *shift_trim(char *s) {	
	int count;
	for(int i=1;i<strlen(s)+1;i++){
		count = strlen(s)-i;
		if(isspace(s[count])==0){	// Jika tidak berisi spasi ,nilai count sebesar s-1,dan break(pengulangan berhenti)
			count = strlen(s)-i;
			break;	// Keluar dari for()
		}
	}
	char *result = calloc((strlen(s)+1),sizeof(char));	// mengalokasikan blok memory sebanyak s+1
	int count1 = -1;
	for(int i=0;i<count+1;i++){
		count1++;
		result[count1] = s[i];
	}
	
	result = trim(result);	// Menghilangkan space diawal string
	return result;
}

// Mengkonvert dari Integer ke String
char *IntToStr(int x){
	char *str=(char *)malloc(1 * sizeof (char));	// Mengalokasikan blok memory sebesar 1byte dan di pointing ke pointer str
	sprintf(str, "%d", x);	// Memasukkan data integer x ke str
	return str;
}

// Membuat Fungsi untuk membaca sebuah isi File
void read_file(char *namafile){
	FILE *fileinput = fopen(namafile, "r");		// Membuka file dengan format Read/hanya dibaca
    	
	int i = 0;	// Variabel i dengan nilai = 0
	int j = 0;	// Variabel j dengan nilai = 0
	while(!feof(fileinput)){	// Melakukan perulangan selama belum mencapai End Of File
		i++;
		fgets(datain1,200,fileinput);	// Mengambil 1baris data dan dimasukkan ke datain1
		strcpy(dataraw[i], shift_trim(datain1));	// Copy datain1 ke dataraw
		if(strlen(dataraw[i])>=0){j++;strcpy(dataraw[j], shift_trim(datain1));}	// Melakukan pengecekan dan copy data
	}
	
	fclose(fileinput);	// Menutup file
	number_data = j;	// isi variabel number_data sama dengan variabel j

	if(strlen(dataraw[number_data]) == strlen(dataraw[number_data-1])){number_data=j-1;} // mengecek panjang baris akhir dan baris akhir-1
	else{number_data = j;}	// kondisi jika salah
}

// Membuat Fungsi untuk mengambil data dari rawdata
void get_data_from_rawdata(){
	char datain1[100],datain2[100],datain3[100],datain4[100],datain5[100];	// Variabel karakter sebagai array dengan nilai array 100
	for(int i=1;i<number_data+1;i++){
		txtResult = replaceWordInString(dataraw[i],","," ");	// Mengubah suatu karakter pada string dari "," menjadi " " 
		sscanf(txtResult,"%s %s %s %s %s",datain1,datain2, datain3, datain4, datain5);	// Mengambil data dari txtresult, datain1,datain2,datain3,datain4,datain5 sebagai string
		datainput_1[i] = atoi(datain1);	// Mengubah string ke integer
		datainput_2[i] = atoi(datain2);	// Mengubah string ke integer
		datainput_3[i] = atoi(datain3);
		datainput_4[i] = atoi(datain4);
		datainput_5[i] = atoi(datain5);
	}
}

// Membuat Fungsi untuk menyimpan dan menuliskan sebuah file text
void save_data_file(char *namafile, dataInput datatulis){
	FILE *fileoutput = fopen(namafile, "w"); 	// Membuka File dengan format write/menulis
    for (int i = 1;i < (datatulis.ndata+1);i++){
		fprintf(fileoutput, "%s,%s,%s,%s,%s\n",  datatulis.Input1[i], datatulis.Input2[i],datatulis.Input3[i],datatulis.Input4[i],datatulis.Input5[i]);
	}
    fclose(fileoutput);	// Menutup File
}

// Function convert integer ke biner
void dec2biner(int *num1){
  int n = *num1;	// Variabel n = nilai *num1
  int bin = 0;		// Variabel bin = 0
  int rem, i = 1;	// variabel rem , i = 1

  while (n!=0) {	// pengulangan jika nilai n bukan samadengan 0,dan berhenti jika nilai n = 0
    rem = n % 2;	// variabel rem = nilai n sisa bagi(%) 2
    n /= 2;			// nilai n dibagi 2
    bin += rem * i;	// variabel bin += nilai rem dikali i
    i *= 10;		// nilai i dikali 10
  }
  *num1 = bin;		// nilai pointer num1 sama dengan nilai variabel bin
}

// Function untuk operasi perpangkatan
int pangkat(int x, int y){	// function pangkat (integer x, integer y)
	int result = 1;			// Variabel result = 1
	for(int i = 0; i<y; i++){	// Pengulangan sebanyak i kurang dari nilai y
		result *= x;	// result dikali= nilai x
	}
	return result;	// mengulang kembali ke result
}
	
//function Konvert biner ke decimal
void biner2dec(int *num) {
  int dec = 0, rem, i = 0;

  while (*num!=0) {	// mengulang jika nilai *num tidak samadengan 0 , dan berhenti ketika nilainya = 0
    rem = *num % 10;	// variabel rem = *num sisabagi 10
    *num /= 10;			// *num dibagi= 10
    dec += rem * pangkat(2,i);	// dec += rem dikali function pangkat(2,i)
    ++i;	// i + 1
  }
  *num = dec;	// nilai *num sama dengan nilai dec
}

