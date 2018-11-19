#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int day, month, year;
	int prevDay, prevMonth, prevYear;
	
	prevDay = day;
	prevMonth = month;
	prevYear = year;
	
	printf("Ciao! Sono un validatore di date!");
	printf("\nInserisci un giorno valido: ");
	scanf("%d", &day);
	printf("Hai inserito il giorno %d\n", day);
	
	printf("\nInserisci un mese valido: ");
	scanf("%d", &month);
	printf("Hai inserito il mese %d \n", month);
	
	printf("\nInserisci un anno valido: ");
	scanf("%d", &year);
	printf("Hai inserito l'anno %d \n", year);
	printf("\n", year);
	
	prevDay = day;
	prevMonth = month;
	prevYear = year;
	
	
	if(checkDate(&day, &month, &year)==0) {
		printf("\nLa data %d/%d/%d non e' una data valida.", day, month, year);
		
	} else {
		printf("\nLa data %d/%d/%d e' una data valida.", day, month, year);
	}
	
	prevDate(&prevDay, &prevMonth, &prevYear);
	
	printf("\nData precedente a quella inserita: %d/%d/%d", prevDay, prevMonth, prevYear);

	return 0;
}



/*
	0 data NON valida
	1 data valida
*/
int checkDate(int *day, int *month, int *year) {
	
	if(initialCheck(day, month, year) == 1){	
	
		// 31 days
		if((*month==1 || *month==3 || *month==5 || *month==7 || *month==8 || *month==10 || *month==12) && (*day>0 && *day<=31)){
			/*printf("31 days");
			printf("Giorno: %d, Mese: %d, Anno: %d", *day, *month, *year);*/
			return 1;
		}
		
		// Febbraio
		else if (((*day>0 && *day<=28) && checkYear(year)==0) || ((*day>0 && *day<=29) && checkYear(year)==1)) {
		     if(*month==2 && (*day>0 && *day<=28) && checkYear(year)==0){
				/*printf("Febbraio (non bisestile) \n");
				printf("Giorno: %d, Mese: %d, Anno: %d", *day, *month, *year);*/
				return 1;
			} else if(*month==2 && (*day>0 && *day<=29) && checkYear(year)==1){
			/*printf("Febbraio (bisestile)\n");*/
				return 1;
			}
		} 
		else if (((*day>0 && *day>28) && checkYear(year)==0) || ((*day>0 && *day>29) && checkYear(year)==1)){
			printf("Mmmmhhh... qualche problema con febbraio.");
			return 0;
		}
		
		// 30 days
	    else if((*month==4 || *month==6 || *month==9 || *month==11) && (*day>0 && *day<=30)){
			/*printf("30 days");
			printf("Giorno: %d, Mese: %d, Anno: %d", *day, *month, *year);*/
			return 1;
		} 		
		
	} else {
			
			return 0;
	}
	return 0;
}





/*
	0 data NON accettata
	1 data accettata
*/
int initialCheck(int *day, int *month, int *year){
	if((*day>0 && *day<=31) && (*month>0 && *month<=12) && (*year>1900 && *month<=2300)){
		return 1;
	}
	else {
		return 0;
	}
	return 0;	
}



/*
	0 non bisestile
	1 bisestile
*/
int checkYear(int *year) {
	if(*year%4==0){
		if(*year%100==0){
			if(*year%400==0){
				//printf("\n %d e' BISESTILE", *year);
				return 1;
			}else{
				//printf("\n %d NON e' BISESTILE", *year);
				return 0;
			}
		} else{
			//printf("\n %d e' BISESTILE", *year);
			return 1;
		}
		
	}else{
	//	printf("\n %d NON e' BISESTILE", *year);
		return 0;
	}
	return 0;
}



/*
	FUNZIONE CHE TORNA DATA PRECEDENTE AD UNA VALIDA INSERITA:
	1. Se il mese inserito è 1 (gennaio) e il giorno è 1, 
		allora: giorno 31, mese 12, anno = anno -1   //FUNZIONA
		
	2. Se il mese inserito è 3 (marzo) e il giorno è 1, allora:
		2.1 verifico se l'anno è bisestile, se bisestile giorno=29 mese=2 anno=stesso anno
		2.2 se non è bisestile allora giorno = 28 mese = 2 //FUNZIONA
	
	3. Considerare altre opzioni
		
	
*/
void prevDate(int *day, int *month, int *year){
	if(checkDate(day, month, year)==1){
		
		// verifico primo giorno dell'anno
		if(*day==1 && *month==1) {
			*day=31; 
			*month=12;
			*year = *year -1;
		} //verifico febbraio
		else if(*day==1 && *month==3){
			if(checkYear(year) == 0){
				*day = 28;
				*month = 2;
			} else {
				*day = 29;
				*month = 2;
			}
		} else if((*month==5 || *month==7 || *month==8 || *month==10 || *month==12) && *day==1) {
			*day = 30;	
			*month = *month - 1;
			
		} else if((*month==2 || *month==4 || *month==6 || *month==9 || *month==11) && *day==1) {
			*day = 31;	
			*month = *month - 1;
		} else if(*month>0 && *month<=12 && *day!=1){
			*day= *day -1;
		}
		
	} else {
    	printf("\nLa data %d/%d/%d non e' una data valida.", *day, *month, *year);
	}
	
}


/*
	FUNZIONE CHE CALCOLA DISTANZA TRA DUE DATE
	1. La prima è quella più recente
	2. Decremento la data finche' la non raggiungo la data precedente
*/
void gapDate(int* day, int *month, int* year){
	
}





/*
	gennaio, di 31 giorni
	febbraio, di 28 giorni (29 se l'anno ï¿½ bisestile)
	marzo, di 31 giorni
	aprile, di 30 giorni
	maggio, di 31 giorni
	giugno, di 30 giorni
	luglio, di 31 giorni
	agosto, di 31 giorni
	settembre, di 30 giorni
	ottobre, di 31 giorni
	novembre, di 30 giorni
	dicembre, di 31 giorni
*/
