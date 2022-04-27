// Memanggil header File
#include "soal_common.c"

// Main Program
int main(int argc, char *argv[]){
	read_file("data_asli.txt");		// Membaca File "data_asli.txt" dengan memanggil fungsi read_file
	printf("jumlah data = %d\n",number_data);	// Mencetak Banyaknya jumlah Data
	
	intdata get;	// Variabel baru dari struct intdata
	get = getdata();	// Memasukkan Function getdata() kedalam variabel get
	
	dataInput dataBaca;			// Variabel baru dari struct dataInput
	dataBaca.Input1 = calloc(9999,sizeof(char)); // Mengalokasikan memory
	dataBaca.Input2 = calloc(9999,sizeof(char));
	
	int count=0;
	
	for(int i=1;i<number_data+1;i++){	// mengulang sebanyak number_data+1
		count++;										// count + 1
		dataBaca.Input1[count]=IntToChr(get.indata1[i]);	// Mengisi struct dataBaca.Input1 dengan get.indata1
															// dengan mengubah data dari integer ke char
		
	}
	
	for(int i=1;i<number_data+1;i++){	// mengulang sebanyak number_data+1
		count++;											// count + 1
		dataBaca.Input1[count]=IntToChr(get.indata2[i]);	// Mengisi struct dataBaca.Input1 dengan get.indata2
															// dengan mengubah data dari integer ke char
	}
	
	dataBaca.ndata = count;		// Mengisi dataBaca.ndata dengan data count
	for(int i=1;i<dataBaca.ndata+1;i++){	// mengulang sebanyak dataBaca.ndata+1
		if(dataBaca.Input1[i]==NULL){dataBaca.Input1[i]="";}	// Jika dataBaca.Input1==NULL , maka berisi ""
		dataBaca.Input2[i]="";	// Mengisi dataBaca.Input2 dengan ""
		char *number = IntToStr(i);		// Pointer number = Konvert integer variabel i ke string
		strcat (dataBaca.Input1[i], number);	// menambahkan string dari belakang strcat(Variabel tujuan, variabel string tambahan);
		
	}
	
	save_data_file("data_copy.txt",dataBaca);	// Menyimpan data ke dalam file dengan memanggil Function
	
	free(dataBaca.Input1),dataBaca.Input1=NULL;	// Membebaskan memory pada struct dataBaca
	free(dataBaca.Input2),dataBaca.Input2=NULL;
}
