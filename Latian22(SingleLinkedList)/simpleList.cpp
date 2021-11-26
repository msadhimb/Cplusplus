#include "simpleList.h"

boolean ListEmpty(List L){
    return First(L) == Nil; // Cek list kosong atau tidak
    // jika tidak kosong fungsi return tidak akan terpenuhi
}

void CreateList(List *L){
    First(*L) = Nil; // Fungsi untuk membuat list
}

address Alokasi(infotype X){ // untuk membuat alokasi pada infotype X
    address P;

    P = (address)malloc(sizeof(ElmtList));
    // fungsi malloc adalah fungsi untuk menyediakan memori yang hanya jika dibutuhkan dia akan otomatis ada
    if(P != Nil){ // Jika P tidak sama dengan Nil
        Info(P) = X; // data yag ada pada address P = infotype X
        Next(P) = Nil; // kemudian untuk alamat yang selanjutnya = Nil
    }
    return P; // mereturn address P
}

void Dealokasi(address *P){
    // Untuk menghapus memori yang telah dibuat
    free(*P);
}

void PrintInfo(List L){ // Fungsi untuk menampilkan List
    address P;

    if(ListEmpty(L)){ // Jika List L Kosong
        printf("*List ini Kosong \n"); // akan menampilkan tulisan List kosong
    }else{ // Jika tidak kosong
        P = First(L); // address P = First(L)
        //melakukan loop
        do{ // akan melakukan print
            printf("|%d| ", Info(P));
            // dengan P = Next(P)
            P = Next(P);
        }while(P != Nil); // ketika P != Nil
        // jadi ketika P = Nil maka loop akan berhenti
    }
}

// Insert and Delete

void InsertFirst(List *L, address P){ // menambahkan elemen dengan arah kedepan
    Next(P) = First(*L);
    First(*L) = P;
}

void InsertLast(List *L, address P){ // menambahkan elemen dengan arah kebelakang
    address Last; // membuat address baru bernama Last
    if(First(*L) == Nil){ // jika First(*L) == 0
        InsertFirst(L,P); // maka dia akan melakukan insert first
    }else{ // jika First(*L) tidak sama dengan 0
        Last = First(*L); // address last sama dengan First(*L)
        while(Next(Last) != Nil){ // ketika Next(First(*L) tidak sama dengan 0
            Last = Next(Last); // maka last sama dengan Next(last)
        }
        InsertAfter(&(*L),P,Last); // memanggil fungsi insert after
    }
}

void InsertTengah(List *L, address P, infotype X){
    address Head; // membuat address baru bernama head

    Head = Search(*L, X); // address head dicari berdasarkan infotype X
    // dengan fungsi Search
    InsertAfter(&(*L),P,Head); // Memanggil fungsi insert after
}

void InsertAfter(List *L, address P, address Prec){ // insert after adalah menginputkan angka setelah address dari elemen P
    Next(P) = Next(Prec); // Next dari P sama dengan next dari Prec
    Next(Prec) = P; // next dari prec sama dengan P
}

void DelFirst(List *L, address *P){ // menghapus elemen yang berada di depan
    (*P) = First(*L); // jika pointer P (int) = First nya dari list L
    First(*L) = Next(First(*L)); // maka First L berpindah ke next dari first L
    Next(*P) = Nil; // next dari pointer P(int) adalah 0
}

void DelLast(List *L, address *P){ // menghapus elemen terakhir dari list
    address Last, PrecLast; // membuat address baru bernama Last dan Preclast

    Last = First(*L); // address last sama dengan First dari list L
    PrecLast = Nil; // PrecLast sama dengan 0 atau kosong
    while(Next(Last) != Nil){ // // ketika next dari last tidak sama dengan 0 atau kosong
        PrecLast = Last; // maka preclast sama dengan last atau First dari list L
        Last = Next(Last); // last didefinisikan lagi dengan next dari last atau next dari first list L
    }

    (*P) = Last; // pointer address P adalah last
    if(PrecLast == Nil){ // jika preclast sama dengan 0 atau kosong
        First(*L) = Nil; // first dari list l adalah 0 atau kosong
    }else{ // jika tidak
        Next(PrecLast) = Nil; // maka next dari preclast sama dengan 0 atau kosong
    }
}

void DelAfter(List *L, address Prec, address *Pdel){
    (*Pdel) = Next(Prec); // pointer address Pdel sama dengan next dari address prec
    Next(Prec) = Next(Next(Prec)); // next dari prec adalah nextnya dari next Prec
    Next(*Pdel) = Nil; // next dari pinter Pdel sama dengan 0 atau kosong
}

// Insert V and Delete V

void InsVFirst(List *L, infotype X){
    address P;

    P = Alokasi(X);
    if(P != Nil){
        InsertFirst(&(*L),P);
    }
}

void InsVLast(List *L, infotype X){
    address P;

    P = Alokasi(X);
    if(P != Nil){
        InsertLast(&(*L),P);
    }
}

void DelVFirst(List *L, infotype *X){
    address P;

    DelFirst(&(*L), &P);
    *X = Info(P);
    Dealokasi(&P);
}

void DelVLast(List *L, infotype *X){
    address P;

    DelLast(&(*L), &P);
    *X = Info(P);
    Dealokasi(&P);
}

void DelP(List *L, infotype X){ // fungsi untuk menghapus elemen yang dipilih
    address P,t; // membuat address berhnama P dan t

    P = Search(*L, X); // address p dicari berdasarkan address infotype X
    if(P != Nil){ // jika address P tidak sama dengan 0
        if(P == First(*L)){ // jika address P sama dengan first dari L
            DelFirst(*(&L),&t); // maka akan menghapus elemen yang ada didepan
        }else{
            P = SearchPrec(*L,X);
            DelAfter(*(&L),P,&t);
        }
        Dealokasi(&t); // menghapus memori yang telah dibuat oleh t
    }
}

boolean IsGengan(List L){ // mengecek apakah list yang ada berjumlah genap atau ganjil
    boolean gengan = true; // jika genap maka akan mereturn true
    address P;
    P = First(L);
    while(Next(P)!=Nil){
        if((Info(P))%2 == ((Info(Next(P))%2))){ // jika ganjil akan mereturn false
            gengan = false;
            break;
        }
        P = Next(P);
    }
    return gengan;
}

// Merge

void Konkat1(List *L1,List *L2,List *L3){ // menggabungkan list
    address S; // membuat address baru bernama S
    CreateList(&(*L3)); // Membuat list L3
    // membuat while loop
    while(!ListEmpty(*L1)){ // ketika L1 tidak kosong
        DelFirst(&(*L1), &S); // akan menghapus elemen yang berada pada list L1
        InsertLast(&(*L3), S); // kemudian elemen pada list L1 ditambahkan ke List L3 dengan metode
        // insert last
    }
    while(!ListEmpty(*L2)){ // ketika L2 tidak kosong
        DelFirst(&(*L2), &S);
        InsertLast(&(*L3), S);
    }
}

// Search

address Search(List L, infotype X){ // fungsi untuk mencari alamat elemen dalam list
    address P;

    P = First(L); // address P sama dengan first dari L
    while(P != Nil && Info(P) != X){ // ketika P tidak sama dengan 0 dan data dari P tidak sama dengan
        // infotype X
        P = Next(P); // maka address P berpindah ke next dari P
    }
    return P; // mereturn P
}

address SearchPrec(List L, infotype X){ // fungsi untuk mencari apakah ada list dengan info(P) = X
    address P,Prec; // membuat address bernama P dan Prec

    P = Search(L,X); // P ini sama dengan mencari apakah alamat L ada pada list L
    Prec = First(L); // Prec didefinisikan dengan First L
    while(Next(Prec) != Nil && Next(Prec) != P){ // ketika next dari prec tidak sama dengan 0
    // dan next dari prec tidak sama dengan address P
        Prec = Next(Prec); // maka address Prec sama dengan next dari address Prec
    }
    if(Next(Prec) == P){ // jika Next prec sama dengan P
        return Prec; // maka dia akan return address Prec
    }else{ // jika tidak
        return Nil; // maka akan mereturn 0 atau kosong
    }
}
