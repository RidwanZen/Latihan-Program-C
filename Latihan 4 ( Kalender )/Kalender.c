// Header file berisi function
#include "Common.c"

int main(void) {
    enum state x ;	// enum variabel x
    
    int year;
    int day = 1; // 1-based day
        
    month.num = get_int("Month :\n");
    
    if (month.num > 0 && month.num <= 12){	// Jika nilai lebih besar dari 0 dan lebih kecil sama dengan 12
		x = True;	// variabel x = True atau x = 1
	}else {
		x = False;	// x = False atau x = 0
		printf("Bulan Salah\n");
	}
	
	if( x == 1){	// jika nilai x = 1 atau True
    	month.num-=1;			// month0 - 1
    	year = get_int("Year :\n");
    
		int dow      = get_startingDays(year, month.num, day);	// Variabel dow diisi dengan memanggil function get_startingDays(year,month.num,day)
		int num_days = get_days_in_month(year, month.num);	// Variabel num_days diisi dengan memanggil function get_days_in_month(year,month.num)
		
		strcpy(month.str, months[month.num]); //assign month.str dengan nama bulan dari array months[]
		printf("%50s %d\n\n", month.str, year);//display bulan dan tahun


		//perulangan untuk display hari senin - minggu
		for (int i = 0; i < 7; i++){	// Pengulangan sebanyak i kurang dari 7
			printf("   %s   ",hari[i]);
		}printf("\n");
		printf("+");
		
		// perulangan display pettern
		for (int i = 0; i < 7; i++){	// Pengulangan sebanyak i kurang dari 7
			printf(" ---------- +");
		}printf("\n");
		
		// Pengulangan menentukan tanggal 1 pada hari dibulan itu
		for(int i=0 ; i < 1; i++){	// pengulangan i kurang dari 1 artinya hanya menjalankan sekali
			for(int j=0; j < dow; j++)	// pengulangan sebanyak j kurang dari data dow
			printf("|            ");
			
			// Perulangan display tanggal
			while (day <= num_days) {	// perulangan jika nilai day kurang dari sama dengan num_days
					
					printf("|%11d ", day++);
					dow = ( dow + 1 ) % 7;	// nilai dow = hasil modulus dari (dow +1) %7
					
					if (!dow){	// jika kondisi bukan dow
						printf("|\n");
						for(int j=0; j<2;j++){	// peulangan untuk cetak pettern sebanyak j < 2
							printf("|");
						for (int i = 0; i < 7; i++){	// perulangan sebanyak i kurang dari 7
							printf("            |");
						}printf("\n");
					}
					printf("+");
					for (int i = 0; i < 7; i++){	// perulangan sebanyak i kurang dari 7
						printf(" ---------- +");
					}printf("\n");
					
					}
			}
			// kondisi ketika sudah diakhir tanggal pada bulan tersebut
			if (dow){
				printf("|\n");
				for(int j=0; j<2;j++){	// perulangan pettern sebanyak j < 2
					printf("|");
					for (int i = 0; i < 7; i++){	// perulangan sebanyak i kurang dari 7
						printf("            |");
					}printf("\n");
				}	
					printf("+");
					for (int i = 0; i < 7; i++){	// perulangan sebanyak i kurang dari 7
						printf(" ---------- +");
					}printf("\n");
			}
		}
		
	}
	
	while ((getchar()) != '\n'); //flush buffer agar dapat menerima input user kembali
    //Membuat prompt untuk lanjut atau tidak
    char ch; 
	printf("Press 1 to continue or 0 to close : ");
	ch = getchar();
	while(1){
		if((ch != '1') && (ch != '0')){ //looping terus hingga mendapatkan value char '1' atau '0'
			while ((getchar()) != '\n'); //flush
			printf("\nPress 1 to continue or 0 to close : ");
			ch = getchar();
		}else if(ch == '1'){
			return main(); //kembali ke atas 
		}else {
			return 0; //program selesai
		}
	}
	
	return 0;
}
