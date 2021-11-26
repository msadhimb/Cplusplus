#include <iostream>
#include "queue.h"

using namespace std;


bool IsEmpty(Queue Q){
	/* Mengirim true jika Q kosong: lihat definisi di atas */
	/* Kamus Lokal */

	/* Algoritma */
	if((HEAD(Q)==Nil) && (TAIL(Q)==Nil)){
        return true;
	}else{
        return false;
	}
}

bool IsFull(Queue Q){
	/* Mengirim true jika tabel penampung elemen Q sudah penuh */
	/* yaitu mengandung MaxEl elemen */

	/* Kamus Lokal */
	/* Algoritma */
	if((HEAD(Q)==1) && (TAIL(Q)==MaxE1(Q))){
        return true;
	}else{
        return false;
	}
}

int NBElmt(Queue Q){
	/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
	/* Kamus Lokal */

	/* Algoritma */
	int jumlah;
	if(IsEmpty(Q)){
        jumlah=0;
	}else{
        jumlah=TAIL(Q);
	}
	return jumlah;
}

void CreateEmpty(Queue *Q, int Max){
	/* Kamus Lokal */

	/* Algoritma */
	(*Q).T = (infotype*)malloc((Max+1)*sizeof(infotype));
	if ((*Q).T != NULL){
		MaxE1(*Q) = Max;
		HEAD(*Q) = Nil;
		TAIL(*Q) = Nil;
	}else /* alokasi gagal */ {
		MaxE1(*Q) = Nil;
	}
}

void DeAlokasi(Queue *Q){
	/* Proses: Mengembalikan memori 2 */
	/* I.S. Q pernah dialokasi */
	/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl (Q) diset O

	/* Kamus Lokal */

	/* Algoritma */
	free((*Q).T);
	MaxE1(*Q) = Nil;
}

void Add(Queue *Q, infotype X){
	/* Proses: Menambahkan X pada Q dengan aturan FIFO */
	/* IS. Q mungkin kosong, tabel penampung elemen Q TIDAK penun
	/* F.S. X menjadi TAIL yang baru, TAIL "maju" */
	/* Jika Tail (Q) =MaxE1+1 maka geser isi tabel, shg Head (Q) =1 */
	/* yaitu mengandung MaxEl elemen */

	/* Kamus Lokal */

	/* Algoritma*/
	if (IsEmpty(*Q)){
		HEAD(*Q) = 1; TAIL(*Q) = 1;
		InfoTail(*Q) = X;
	}else /* Q tidak kosong*/ {
		if (IsFull(*Q)){ /* Tail berada di MaxEI*/
			printf("\n Antrian penuh...");
		}else{
			TAIL(*Q)++;
            InfoTail(*Q)=X;
		}
	}
}

void Del(Queue *Q, infotype* X){
	/* Proses: Menghapus X pada Q dengan aturan FIFO */
	/* I.S. Q tidak mungkin kosong * /
	/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju"; Q mungkin kosong */
	/* yaitu mengandung MaxEl elemen */

	/* Kamus Lokal */

	/* Algoritma */
	int i;
	if(IsEmpty(*Q)){
        printf("\n Antrian Kosong...");
	}else{
        *X = InfoHead(*Q);
        TAIL(*Q)--;
        if (TAIL(*Q)==0){
            /* Set mjd queue kosong */
            HEAD(*Q)=0;
        }else{
            i++;
            while(i<=TAIL(*Q)){
                (*Q).T[i]=(*Q).T[i+1];
                i++;
            }
        }
	}

}
