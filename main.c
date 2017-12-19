/*
M.Alper Uslu 
Dpu Bilgisayar m.(io)
201513172025
17.12.2017
*/

#include <stdio.h>
#include <stdlib.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"

struct kisi{
	
	int tc;
	char isim[15];
	char soyisim[15];
	char tel[13];
	char bolum[30];
	
};	 

void clrscr();
void tercih();
int control(secim,alt,ust);
void islem (secim);
void ekle();
void sil();
void liste();
void guncelle();
void ara();
void menu();
int step;

int main(int argc, char *argv[]) {
	
	 menu(0);
	 
	return 0;	
}

void clrscr()
{
    system("@cls||clear");
}

int control(secim,alt,ust){
		int tmp;
if(secim>ust || secim<alt)
	tmp=1;		
 
 else 
 	tmp=0;
	
return tmp;	
}

void tercih(){
	printf("\n----------------------------\n");	
	printf("1- Tekrar\n");
	printf("2- Menuye Don\n");
	printf("3- Cikis Yap\n");
	int sec;
	scanf("%d",&sec);
	
	if(control(sec,1,2)){//aralýk dýþýndayda 1 döner ve tekrar seçim istenir
		 clrscr();
			tercih();	
	}
	else{
	if(sec==1){
		clrscr();
			islem (step);
	}
	else if(sec==2){
		menu(0);
	}else{		
		exit(0);		
	}
	}	
}

void islem (secim){
	
	switch(secim) {

   case 1  :
   	 step=1;
     liste();     
      break; 	
   case 2  :
   	  step=2;
      ara();      
      break;       
   case 3  :
     	step=3;
      ekle();      
      break;      
   case 4  :
   	  step=4;
      sil();      
      break;
   case 5  :
     	step=5;
      guncelle();      
      break;      
   default :
			   clrscr(); 
     	exit(0);
     break;  
}	
}

void ekle(){
	
	struct kisi con;
 		  		
	printf(ANSI_COLOR_GREEN "Kisi Ekle\n" ANSI_COLOR_RESET);
	printf("----------------------------\n");
	printf("TC Girin :");	
	scanf("%d",&con.tc); 
	printf("Isim Girin :");	
	scanf("%s",con.isim);
	printf("Soyisim Girin :");	
	scanf("%s",con.soyisim);	
	printf("Telefon Girin :");	
	scanf("%s",con.tel);
	printf("Bolum Girin :");	
	scanf("%s",con.bolum);
	
	FILE *fp;

	if(fopen("kayit.txt","a")){
		
	fp= fopen("kayit.txt","a");   
					
}else{
  fp= fopen("kayit.txt","w"); 	
	}
	
	if(fprintf(fp,"%d %s %s %s %s\n",con.tc,con.isim,con.soyisim,con.tel,con.bolum)){
			printf(ANSI_COLOR_BLUE  "\nBasarili!"  ANSI_COLOR_RESET);
	}else{
		printf(ANSI_COLOR_RED  "Hata!"  ANSI_COLOR_RESET);
	}
			
	fclose(fp);
	tercih();	
}
void ara(){
	 
	 	printf(ANSI_COLOR_GREEN "Kayit Arama\n" ANSI_COLOR_RESET);
	  printf("----------------------------\n");
 struct kisi con;
  
 printf("Arananicak Kelime :");
 char ara[30];
		scanf("%s",ara);
		 
		FILE *fp;
		fp= fopen("kayit.txt","r"); 
  char ctrl=0;
  int fCtrl;
  int say=0;
  
	if(fp != NULL){
		  
			while(!feof(fp)){				
							
		fscanf(fp,"%d %s %s %s %s",&con.tc,con.isim,con.soyisim,con.tel,con.bolum);
		
		if(strcmp(con.isim,ara)==0||strcmp(con.soyisim,ara)==0||strcmp(con.bolum,ara)==0){					
			if(fCtrl!=con.tc){
				say++;
	 	if(say%2==0)printf( ANSI_COLOR_CYAN);
	  else printf( ANSI_COLOR_YELLOW);
	  printf("%d - ",say);	
	 printf("%d %s %s %s %s\n",con.tc,con.isim,con.soyisim,con.tel,con.bolum);
		 ctrl= 1; 		 
			}				
		}
		printf(ANSI_COLOR_RESET);
		fCtrl=con.tc;
	}
	if(ctrl==0){
		printf(ANSI_COLOR_RED  "Kayit Bulunamadi!"  ANSI_COLOR_RESET);
	}else{
		printf(ANSI_COLOR_BLUE  "\nBasarili!"  ANSI_COLOR_RESET);
	}		
}else{
  printf(ANSI_COLOR_RED  "Dosyada hic veri yok!"  ANSI_COLOR_RESET);
  return 0;
	}	

	fclose(fp);
	tercih();
	
}
void liste(){
	
	struct kisi con;
	
	printf(ANSI_COLOR_GREEN "Kisi Listesi\n" ANSI_COLOR_RESET);
	printf("-----------------------------\n");
	
	FILE *fp = fopen("kayit.txt","r"); ;
 int say=0;
 int fCtrl;
 //fCtrl = (int *) malloc(12);
	if(fp != NULL){
	printf(ANSI_COLOR_MAGENTA "No  TC  Isim  Soyisim  Telefon  Bolum \n" ANSI_COLOR_RESET);
	
	while(!feof(fp)){
		
		
		fscanf(fp,"%d %s %s %s %s",&con.tc,con.isim,con.soyisim,con.tel,con.bolum);
		 
			if(con.tc!=fCtrl){
				say++;
				if(say%2 ==0)printf( ANSI_COLOR_CYAN);
		 else printf( ANSI_COLOR_YELLOW);
				printf("%d -",say);			
			 printf( " %d %s %s %s %s\n",con.tc,con.isim,con.soyisim,con.tel,con.bolum); 					
		  printf(ANSI_COLOR_RESET);	 	
				
			}			
			fCtrl=con.tc;
		
		}
			
}else{
  printf(ANSI_COLOR_RED  "Dosyada hic veri yok!"  ANSI_COLOR_RESET);
  return 0;
	}
	
	fclose(fp);
	tercih();
	
}
void sil(){
	
	 	printf(ANSI_COLOR_GREEN "Kisi Sil\n" ANSI_COLOR_RESET);
	  printf("----------------------------\n");
 struct kisi con;
  
 printf("Silinecek isim :");
 char a[30];
		scanf("%s",a);
		printf("Silinecek soyisim :");
 char s[30];
		scanf("%s",s);
		 
		FILE *fp,*yeni;
		char ctrl= 0;
		int fCtrl;
		fp=fopen("kayit.txt","r"); //bilgiler dosyadan okunacak.
  yeni=fopen("gecici.txt","w"); //yeni bilgiler bu dosyaya yazýlacak.

	if(fp != NULL){
		  
			while(!feof(fp)){
		fscanf(fp,"%d %s %s %s %s",&con.tc,con.isim,con.soyisim,con.tel,con.bolum);
		if(strcmp(con.isim,a)==0&&strcmp(con.soyisim,s)==0){
			 ctrl= 1; 		
		}else{
			fprintf(yeni,"%d %s %s %s %s \n",con.tc,con.isim,con.soyisim,con.tel,con.bolum);
			
		}
		fCtrl= con.tc;	 		
	}
	
	if(ctrl==0){
		printf(ANSI_COLOR_RED  "Kayit Bulunamadi!"  ANSI_COLOR_RESET);
	}	else{
		printf(ANSI_COLOR_BLUE  "\nBasarili!"  ANSI_COLOR_RESET);
	}
	
 fclose(fp);
 fclose(yeni);
 
 remove("kayit.txt");
 rename("gecici.txt","kayit.txt"); 
					
}else{
  printf(ANSI_COLOR_RED  "Dosyada hic veri yok!"  ANSI_COLOR_RESET);
  return 0;
	}
	
	tercih();	
}

void guncelle(){
	
	printf(ANSI_COLOR_GREEN "Kayit Guncelle\n" ANSI_COLOR_RESET);
	printf("----------------------------\n");
  struct kisi con;
  
 printf("Kisi isim :");
 char a[30];
		scanf("%s",a);
		printf("Kisi soyisim :");
 char s[30];
		scanf("%s",s);
		 
		FILE *fp,*yeni;
		char ctrl= 0;
		int fCtrl;
		fp=fopen("kayit.txt","r"); //bilgiler dosyadan okunacak.
  yeni=fopen("gecici.txt","w"); //yeni bilgiler bu dosyaya yazýlacak.
  
	if(fp != NULL){
		  
			while(!feof(fp)){
			fscanf(fp,"%d %s %s %s %s",&con.tc,con.isim,con.soyisim,con.tel,con.bolum);
		if(strcmp(con.isim,a)==0 && strcmp(con.soyisim,s)==0&&ctrl==0){
		printf(ANSI_COLOR_YELLOW);
	printf("%d %s %s %s %s \n",con.tc,con.isim,con.soyisim,con.tel,con.bolum );	
	printf(ANSI_COLOR_RESET);	
	printf("TC Girin :");
	scanf("%d",&con.tc);
	printf("Isim Girin :");
	scanf("%s",con.isim);
	printf("Soyisim Girin :");
	scanf("%s",con.soyisim);	
	printf("Telefon Girin :");
	scanf("%s",con.tel);
	printf("Bolum Girin :");
	scanf("%s",con.bolum);
			
			 ctrl= 1; 		
		}		
			if(fCtrl!= con.tc)fprintf(yeni,"%d %s %s %s %s \n",con.tc,con.isim,con.soyisim,con.tel,con.bolum);
			
		fCtrl= con.tc;	 		
	}
	
	if(ctrl==0){
		printf(ANSI_COLOR_RED  "Kayit Bulunamadi!"  ANSI_COLOR_RESET);
	}	else{
		printf(ANSI_COLOR_BLUE  "Basarili!"  ANSI_COLOR_RESET);
	}	
 fclose(fp);
 fclose(yeni);
 
 remove("kayit.txt");
 rename("gecici.txt","kayit.txt"); 
					
}else{
  printf(ANSI_COLOR_RED  "Dosyada hic veri yok!"  ANSI_COLOR_RESET);
  //return 0;
	}
	
	tercih();	
}

void menu(error){	

		clrscr();
	 
	printf(ANSI_COLOR_CYAN "Personel Kayit Programi\n" ANSI_COLOR_RESET);
	printf("----------------------------\n");
	printf("1 - Kayitlari Listele\n");
	printf("2 - Kayit Ara\n");
	printf("3 - Kayit Ekle\n");
	printf("4 - Kayit Sil\n");
	printf("5 - Kayit Guncelle\n");
	printf("6 - Programdan Cik\n" );
 printf("----------------------------\n");
	
	int secim;
 printf(ANSI_COLOR_YELLOW "Seciminiz : " );
 if(error){
 	printf(ANSI_COLOR_RED " Hatali Secim!\n" ANSI_COLOR_RESET);
 	printf(ANSI_COLOR_MAGENTA " Tekrar :" ANSI_COLOR_RESET);
	}
	scanf("%d",&secim);	
	
	if(control(secim,1,6)){
		menu(1);
	}
	else{
			clrscr();
			islem(secim);
	} 
}
