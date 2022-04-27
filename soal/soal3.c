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
	
	int count1=0;	// Variabel integer awal 0
	int count2=0;	// Variabel integer awal 0
	for(int i=1;i<number_data+1;i++){	// Melakukan perulangan sebanyak number_data+1
		if(isGanjil(datainput_1[i])==0){	// Jika modulus datainput_1 = 0 (Genap),maka count1 + 1
			count1++;
			dataBaca.Input1[count1] = IntToStr(datainput_1[i]);	// Mengisi Struct dataBaca.Input1 dengan datainput_1
		}
		if(isGanjil(datainput_2[i])==0){	// Jika modulus datainput_2 = 0 (Genap),maka count1 + 1
			count1++;
			dataBaca.Input1[count1] = IntToStr(datainput_2[i]);	// Mengisi Struct dataBaca.Input1 dengan datainput_2
		}
		if(isGanjil(datainput_3[i])==0){	// Jika modulus datainput_3 = 0 (Genap),maka count1 + 1
			count1++;
			dataBaca.Input1[count1] = IntToStr(datainput_3[i]);	// Mengisi Struct dataBaca.Input1 dengan datainput_3
		}
		
		if(isGanjil(datainput_1[i])==1){	// Jika modulus datainput_1 = 1 (Ganjil),maka count2 + 1
			count2++;
			dataBaca.Input2[count2] = IntToStr(datainput_1[i]);	// Mengisi Struct dataBaca.Input2 dengan datainput_1
		}
		if(isGanjil(datainput_2[i])==1){	// Jika modulus datainput_2 = 1 (Ganjil),maka count2 + 1
			count2++;
			dataBaca.Input2[count2] = IntToStr(datainput_2[i]);	// Mengisi Struct dataBaca.Input2 dengan datainput_2
		}
		if(isGanjil(datainput_3[i])==1){	// Jika modulus datainput_3 = 1 (Ganjil),maka count2 + 1
			count2++;
			dataBaca.Input2[count2] = IntToStr(datainput_3[i]);	// Mengisi Struct dataBaca.Input2 dengan datainput_3
		}
	}
	
	dataBaca.ndata = (count1 > count2 ? count1 : count2); // Mengisi data jika count1 lebih besar dari count2,maka hasilnya count1,
															//jika tidak hasilnya count2
	
	for(int i=1;i<dataBaca.ndata+1;i++){	// Mengulang sebanyak dataBaca.ndata+1
		if(dataBaca.Input1[i]==NULL){dataBaca.Input1[i]="";} // Jika dataBaca.Input1==NULL , maka berisi ""
		if(dataBaca.Input2[i]==NULL){dataBaca.Input2[i]="";} // Jika dataBaca.Input2==NULL , maka berisi ""
		dataBaca.Input3[i]="";					// Mengisi dataBaca.Input3 dengan ""
	}
	
	save_data_file("data_copy3.txt",dataBaca);	// Menyimpan data ke dalam file dengan memanggil Function
	
	free(dataBaca.Input1),dataBaca.Input1=NULL;	// Membebaskan memory pada struct dataBaca
	free(dataBaca.Input2),dataBaca.Input2=NULL;
	free(dataBaca.Input3),dataBaca.Input3=NULL;
}
