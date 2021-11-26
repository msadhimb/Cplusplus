/* File : queue.h */
#ifndef queueH
#define queueH

#define true 1
#define false 0
#define boolean unsigned char

#include "stdlib.h"

#define Nil 0
/* Definisi elemen dan address */

typedef int infotype;
typedef int address; /* indeks tabel */
/* Contoh deklarasi variabel bertype Queue : */
/* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */

typedef struct {
	infotype *T; /* tabel penyimpan elemen */
	address HEAD; /* alamat penghapusan */
	address TAIL; /* alamat penambahan */
	int MaxEl; /* MAx elemen queue */
}Queue;

/* Definisi Queue kosong: Head=Nil; TAIL=Nil. */
/* Catatan implementasi: T[0] tidak pernah dipakai. */

/********** AKSES (Selektor) **********/
/* Jika Q adalah Queue, maka akses elemen : */

#define HEAD(Q) (Q).HEAD
#define TAIL(Q) (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]
#define MaxE1(Q) (Q).MaxEl

/********** Prototype **********/

bool IsEmpty(Queue Q);
/* Mengirim true jika Q kosong: lihat definisi di atas */

bool IsFull(Queue Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/*yaitu mengandung MaxEl elemen*/

int NBElmt(Queue Q);
/* Mengirimkan banyaknya elemen queue.Mengirimkan 0 jika kosong */

/**********  Kreator ********** /
void CreateEmpty (Queue *Q, int Max);
/* I.S. sembarang */
/* F.S Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
/*atau : jika alokasi gagal, Q kosong dg Maksimum elemen=0 */
/* Proses % Melakukan alokasi, Membuat sebuah 2 kosong */
/* Destruktor */

void CreateEmpty(Queue *Q, int Max);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
/* atau : jika alokasi gagal, Q kosong dg Maksimum elemen=0 */
/* Proses : Melakukan alokasi, Membuat sebuah Q kosong */
/* yaitu mengandung MaxEl elemen */

void DeAlokasi(Queue *Q);
/* Proses: Mengembalikan memori 2 */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl (Q) diset 0 */
/* Primitif Add/Delete */

void Add(Queue *Q, infotype X);
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* IS. Q mungkin kosong, tabel penampung elemen 2 TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" */
/* Jika Tail (Q)=MaxE1+1 maka geser isi tabel, shg Head (Q) =1 */

void Del(Queue *Q, infotype* X);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S , HEAD "maju"; Q mungkin kosong */

#endif
