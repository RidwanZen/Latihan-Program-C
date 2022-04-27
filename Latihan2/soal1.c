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
	dataBaca.Input4 = calloc(9999,sizeof(char));
	dataBaca.Input5 = calloc(9999,sizeof(char));
	
	for(int i=1;i<number_data+1;i++){		// Perulangan sebanyak number_data+1
		dec2biner (&datainput_1[i]);	// Memanggil function untuk mengubah bilangan decimal menjadi biner sebelum dikonvert ke string
		dec2biner (&datainput_2[i]);
		dec2biner (&datainput_3[i]);
		dec2biner (&datainput_4[i]);
		dec2biner (&datainput_5[i]);
	}
	
	for(int i=1;i<number_data+1;i++){		// Perulangan sebanyak number_data+1
		dataBaca.Input1[i]=IntToStr(datainput_1[i]); // Konversi integer ke string dan dimasukkan ke struct dataBaca
		dataBaca.Input2[i]=IntToStr(datainput_2[i]);
		dataBaca.Input3[i]=IntToStr(datainput_3[i]);
		dataBaca.Input4[i]=IntToStr(datainput_4[i]);
		dataBaca.Input5[i]=IntToStr(datainput_5[i]);
	}
	dataBaca.ndata = number_data;	// Mengisi data pada struct dataBaca.ndata dengan number_data
	
	save_data_file("data_biner.txt",dataBaca);	// Menyimpan data ke dalam file dengan memanggil Function
	
	free(dataBaca.Input1),dataBaca.Input1=NULL;	// Membebaskan memory pada struct dataBaca
	free(dataBaca.Input2),dataBaca.Input2=NULL;
	free(dataBaca.Input3),dataBaca.Input3=NULL;
	free(dataBaca.Input4),dataBaca.Input4=NULL;
	free(dataBaca.Input5),dataBaca.Input5=NULL;
}
