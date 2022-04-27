#include "soal_common.c"

int main(int argc, char *argv[]){
	read_file("data_copy.txt");		// Membaca File "data_copy.txt" dengan memanggil fungsi read_file
	printf("jumlah data = %d\n",number_data); // Mencetak Banyaknya jumlah Data
	
	intdata get;	// Variabel baru dari struct intdata
	get = getdata();	// Memasukkan Function getdata() kedalam variabel get
	
	dataInput dataBaca;			// Variabel baru dari struct dataInput
	dataBaca.Input1 = calloc(9999,sizeof(char));	// Mengalokasikan memory
	dataBaca.Input2 = calloc(9999,sizeof(char));	// Mengalokasikan memory
	
	int count=0;
	for(int i=1;i<number_data-2;i++){ //perulangan sebanyak number data -2
		count++;	//count + 1
		dataBaca.Input1[i]=IntToChr(get.indata1[count]);	// Mengisi struct dataBaca.Input1 dengan get.indata1[count]
		strcat(dataBaca.Input1[i],",");			// menambahkan string dari belakang dengan ditambah ","
	}
																
	for(int i=1;i<number_data-2;i++){ //perulangan sebanyak number data -2
		count++;	//count + 1
		dataBaca.Input2[i]=IntToChr(get.indata1[count]);	// Mengisi struct dataBaca.Input2 dengan get.indata1[count]
		
	}
	
	dataBaca.ndata = number_data-3;    //Mengisi int dataBaca.ndata dengan numer data-3

	save_data_file("data_asli1.txt",dataBaca);	//menyimpan data ke file baru
	
	free(dataBaca.Input1),dataBaca.Input1=NULL;	//membebaskan memori
	free(dataBaca.Input2),dataBaca.Input2=NULL; //membebaskan memori
	
}
