#include <stdio.h>
#include <stdlib.h>
#include "chessLib.h"
#define M 8
#define N 8


int **matrisOlustur(){
	int i, j;
    int **a = (int **)calloc(M ,sizeof(int *));
	for(i = 0; i<8; i++){
		a[i] = (int *)calloc(N,sizeof(int));
	} 	
	for(i = 0; i< M; i++){
		for(j = -1; j<N; j++){
			a[i][j] = 0;
		}
	}
	
	for(i=0;i<8;i++){
      	a[i][-1] = 8-i;
      }
      
	
 return a;
}



 void matrisYaz(int **a){
	int i,j;
		for(i = 0; i<8; i++){
		for(j = -1; j<8 ; j++){
			printf(" %d ",a[i][j]);
			
		}
		puts("");
		
	}

	printf("    A  B  C  D  E  F  G  H");
	
}




 struct poz *hareketSah(struct poz ilkPoz){
	 
	int yty = 7 -(ilkPoz.yatay - 1);
    int dky = (ilkPoz.dusey - 65);
    int **board=matrisOlustur();
    
    int i,j;
    for(i = yty-1; i < yty+2; i++){
    	for(j = dky-1; j <dky+2; j++){
    	    if(!(j<0 || j>7 || i<0 || i>7)){
		        board[i][j] = 1; 
		    }
		 	if(i == yty && j == dky ){
    			board[i][j] = 2;
			}
}
}
matrisYaz(board);

}

struct poz *hareketVezir(struct poz ilkPoz){
    int yty = 7 -(ilkPoz.yatay - 1);
    int dky = (ilkPoz.dusey - 65);
    int **board=matrisOlustur();
    int i,j;
    
	for(i=yty-7;i<yty+8;i++){
		for(j=dky-7;j<dky+8;j++){
			
			if(!(j<0 || j>7 || i<0 || i>7)){
				if(i-yty==j-dky||i-yty==(j-dky)*(-1)||i==yty||j==dky){
				
		        board[i][j] = 1; 
				 
		    }	
		}
		if(i == yty && j == dky ){
    			board[i][j] = 2;
	    }
    }
    } 
	matrisYaz(board); 
}

struct poz *hareketFil(struct poz ilkPoz){
	 int yty = 7 -(ilkPoz.yatay - 1);
    int dky = (ilkPoz.dusey - 65);
    int **board=matrisOlustur();
    int i,j;
    
	for(i=yty-7;i<yty+8;i++){
		for(j=dky-7;j<dky+8;j++){
			
			if(!(j<0 || j>7 || i<0 || i>7)){
				if(i-yty==j-dky||i-yty==(j-dky)*(-1)){
				
		        board[i][j] = 1; 
				 
		    }	
		}
		if(i == yty && j == dky ){
    			board[i][j] = 2;
	    }
    }
	
    } 
	matrisYaz(board); 

	
}
struct poz *hareketAt(struct poz ilkPoz){
	int yty = 7 -(ilkPoz.yatay - 1);
    int dky = (ilkPoz.dusey - 65);
    int **board=matrisOlustur();
    int i,j;
    
	for(i=yty-2;i<yty+3;i++){
		for(j=dky-2;j<dky+3;j++){
			
			if(!(j<0 || j>7 || i<0 || i>7)){
				if((i-yty)*(j-dky)==2||(i-yty)*(j-dky)==-2){
				
		        board[i][j] = 1; 
				 
		    }	
		}
	
    }
	
    } 
    	board[yty][dky] = 2;
	matrisYaz(board); 

}
struct poz *hareketKale(struct poz ilkPoz){
	 int yty = 7 -(ilkPoz.yatay - 1);
    int dky = (ilkPoz.dusey - 65);
    int **board=matrisOlustur();
    int i,j;
    
	for(i=yty-7;i<yty+8;i++){
		for(j=dky-7;j<dky+8;j++){
			
			if(!(j<0 || j>7 || i<0 || i>7)){
				if(i==yty||j==dky){
				
		        board[i][j] = 1; 
				 
		    }	
		}
		if(i == yty && j == dky ){
    			board[i][j] = 2;
	    }
    }
	
    } 
	matrisYaz(board); 


}
struct poz *hareketPiyon(struct poz ilkPoz){
	 int yty = 7 -(ilkPoz.yatay - 1);
    int dky = (ilkPoz.dusey - 65);
    int **board=matrisOlustur();
    int i,j;
    
        
		if(yty==6){
			board[5][dky] = 1;
			board[4][dky] = 1;
			board[yty][dky] = 2;
	matrisYaz(board); 	
		}
		if(yty==1){
			board[2][dky] = 1;
			board[3][dky] = 1;
			board[yty][dky] = 2;
	matrisYaz(board); 	
		}
	
	if(!(yty==6||yty==1)){
		
		
   	   board[yty-1][dky] = 1;
	    board[yty][dky] = 2;
	 printf("beyaz icin hamle:\n\n\n");
	    matrisYaz(board); 
	    printf("\n\n\n");
	    board[yty+1][dky] = 1;
	    board[yty-1][dky] = 0;
	 printf("siyah icin hamle:\n\n\n");
     	 matrisYaz(board);
				
		}
    
	
    
	
}


void hareketYazdir(char tas, struct poz ilkPozisyon){
	switch (tas){
		case 'S':
		     *hareketSah(ilkPozisyon);
		break;
			case 'V':
			*hareketVezir(ilkPozisyon);
		break;
			case 'F':
			*hareketFil(ilkPozisyon);
		break;
			case 'A':
			*hareketAt(ilkPozisyon);
		break;
			case 'K':
			*hareketKale(ilkPozisyon);
		break;
	        case 'P':
			*hareketPiyon(ilkPozisyon);
		break;
		default:
			printf("\n Yanlis bir tas adi girdiniz !!!");
	}
}



int main(int argc, char *argv[]) {
	while(1){
	
   //pointer function oluþturma 
	void (*pHareketYazdir)(char,struct poz) = &hareketYazdir;
	void(*satrancFonksiyonlari)(char,struct poz) = pHareketYazdir;
    struct poz p;
   char tas;
  short yatay;
   
 	//kullanicidan veri isteme  
    printf(" \nHangi satranc tasinin hareket durumunu gostereyim ?  sah(S), vezir(V), fil(F), at(A), kale(K), piyon(P) Hangisi Seciniz \n ");
   scanf(" %c",&tas);
   printf(" Girdiginiz tas icin satranc tahtasi uzerinde ki konumu belirtiniz. A3, D5,F7 gibi\n");
 	printf("\nyatay ve duseyi girin");  
	scanf(" %c",&p.dusey);
  	scanf("%d",&p.yatay);
	printf("degerler :");
	printf("%c\n",tas);
	printf("%c %d\n",p.dusey, p.yatay);
	

   // Pointer function ile istenilen taþ için uygun fonksiyonu çaðýrma
   satrancFonksiyonlari(tas,p);
}
	return 0;
}

