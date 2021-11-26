#include <iostream>

using namespace std;

void pointerku(int *b){
    printf("Nilai dari b adalah %d\n", *b);
    printf("Alamat dari b adalah %d\n", b);
}

void kuadrat(int *nilai){
    *nilai= (*nilai) * (*nilai);
    printf("Nilai dari nilai kuadrat adalah %d\n", *nilai);
    printf("Alamat dari nilai kuadrat adalah %d\n", nilai);
}

void faktorial(int *fakt){
    int hasil=1;
    for(int i=1;i<=*fakt;i++){
        hasil=hasil*i;
    }
    *fakt=hasil;
    printf("Nilai dari nilai faktorial adalah %d\n", *fakt);
    printf("Alamat dari nilai faktorial adalah %d\n", fakt);
}


int main()
{
    int a;
    string jawab,jawab2;

    printf("\nMasukkan nilai a : ");
    cin>>a;
    printf("\n");

    printf("Nilai dari a adalah %d\n", a);
    printf("Alamat dari a adalah %d\n", &a);

    pointerku(&a);
    cout<<endl;

    printf("\nIngin menampilkan nilai faktorial atau kuadrat ? \n");
    cin>>jawab;

    if(jawab=="faktorial"){
        faktorial(&a);
        printf("\nIngin memulai lagi ?(ya/tidak)\n");
        cin>>jawab2;
        if (jawab2=="ya"){
            main();
        }else{
            return 0;
        }
    }else if(jawab=="kuadrat"){
        kuadrat(&a);
        printf("\nIngin memulai lagi ?(ya/tidak)\n");
        cin>>jawab2;
        if (jawab2=="ya"){
            main();
        }else{
            return 0;
        }
    }

}
