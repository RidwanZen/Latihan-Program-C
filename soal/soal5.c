// Memanggil header File
#include "soal_common.c"

// Main Program
int main(int argc, char *argv[]){
	read_file("data.txt");		// Membaca File "data.txt" dengan memanggil fungsi read_file
	printf("jumlah data = %d\n",number_data);	// Mencetak Banyaknya jumlah Data
	
	get_data_from_rawdata();	// Mengambil data dari rawdata
	dataInput dataBaca;			// Variabel baru dari struct dataInput
	dataBaca.Input1 = calloc(9999,sizeof(char)); // Mengalokasikan memory
	dataBaca.Input2 = calloc(9999,sizeof(char));
	dataBaca.Input3 = calloc(9999,sizeof(char));
	
	int count=0;
	for(int i=1;i<number_data+1;i++){	// mengulang sebanyak number_data+1
		count++;											// count + 1
		dataBaca.Input1[count]=IntToStr(datainput_1[i]);	// Mengisi struct dataBaca.Input1 dengan datainput_1
		count++;											// count + 1
		dataBaca.Input1[count]=IntToStr(datainput_2[i]);	// Mengisi struct dataBaca.Input1 dengan datainput_2
		count++;											// count + 1
		dataBaca.Input1[count]=IntToStr(datainput_3[i]);	// Mengisi struct dataBaca.Input1 dengan datainput_3
	}
	dataBaca.ndata = count;		// Mengisi dataBaca.ndata dengan data count
	for(int i=1;i<dataBaca.ndata+1;i++){	// mengulang sebanyak dataBaca.ndata+1
		if(dataBaca.Input1[i]==NULL){dataBaca.Input1[i]="";}	// Jika dataBaca.Input1==NULL , maka berisi ""
		dataBaca.Input2[i]="";	// Mengisi dataBaca.Input2 dengan ""
		dataBaca.Input3[i]="";	// Mengisi dataBaca.Input3 dengan ""
		
		// Jika modulus databaca.Input1==1 dan lebih besar dari 5(> 5) , maka dataBaca.Input1 = "ganjil > 5"
		if(isGanjil(atoi(dataBaca.Input1[i]))==1 && atoi(dataBaca.Input1[i]) > 5){dataBaca.Input1[i]="ganjil > 5";}
		// Dan jika modulus dataBaca.Input1==0 dan lebih besar dari 5(> 5) , maka dataBaca.Input1 = "genap > 5"
		else if(isGanjil(atoi(dataBaca.Input1[i]))==0 && atoi(dataBaca.Input1[i]) > 5){dataBaca.Input1[i]="genap > 5";}
		// Jika bukan , maka dataBaca.Input1 = dataBaca.Input1
		else{dataBaca.Input1[i]=dataBaca.Input1[i];}
	}
	
	save_data_file("data_copy5.txt",dataBaca);	// Menyimpan data ke dalam file dengan memanggil Function
	
	free(dataBaca.Input1),dataBaca.Input1=NULL;	// Membebaskan memory pada struct dataBaca
	free(dataBaca.Input2),dataBaca.Input2=NULL;
	free(dataBaca.Input3),dataBaca.Input3=NULL;
}
