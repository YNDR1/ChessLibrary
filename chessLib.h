#define CHESSLIB_H_


typedef struct poz{
	char dusey;
	short yatay;
}poz;

 int **matrisOlustur();
 
 void matrisYaz(int **);
 
 struct poz *hareketSah(struct poz);
 
 struct poz *hareketVezir(struct poz);
 
 struct poz *hareketFil(struct poz);
 
 struct poz *hareketAt(struct poz);
 
 struct poz *hareketKale(struct poz);
 
 struct poz *hareketPiyon(struct poz);
 
 void hareketYazdir(char, struct poz);
  
