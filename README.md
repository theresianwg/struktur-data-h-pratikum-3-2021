# Kata-Kata
## Verdict 
AC Saat Revisi

## Bukti
![Verdict Kata-Kata](https://user-images.githubusercontent.com/81666422/116954995-87ac2600-acbb-11eb-88d8-126ea5fc2004.jpg)

## Penjelasan Soal
Pada soal kata-kata diminta untuk mencari setiap kata yang dicari, menentukan apakah kata yang dicari merupakan kata yang tersimpan.

## Penjelasan Solusi
```
    void insert(string kata) {
        TrieNode *current = head;
        current->node++;
        int temp=0;
        int panjang= kata.length();
        for(int i=0; i<panjang; i++)     {
            temp = (int)kata[i] - (int)'a';        
            if(current->child[temp] == NULL) {   
                current->child[temp] = new TrieNode();
            }
            current->child[temp]->node++;
            current = current->child[temp];        
        }
        current->cek = true;
    }

    bool search(string kata) {
        TrieNode *current = head;
        int temp=0;
        int panjang= kata.length();
        for(int i=0; i<panjang; i++) {
            temp=(int)kata[i]-(int)'a';     
            if(current->child[temp] == NULL){
                return false;        
            }
            current = current->child[temp];
        }
        return current->cek;
    }
   ```
   ``` void insert ``` dan ``` bool search ``` digunakan untuk memasukkan kata dan mencari kata yang tersimpan.
   
   ``` 
   int main(){
    AVL set;
    set.init();

    int testcase, casetest;
    string kata, cari_kata;
    cin >> testcase;
    for (int i=1; i<= testcase; i++){
        cin >> kata;
        set.insert(kata);
    }

    cin >> casetest;
    for (int i=1; i<= casetest; i++){
        cin >> cari_kata;
        if (set.search(cari_kata)){
            cout << "1" << endl;
        }
        else{
            cout << "0" << endl;
        }
    }

    return 0;
}
```
Pertama menginisialisasi AVL menggunakan ``` AVL set;``` ```set.init();```, dilanjutkan menginputkan testcase pertama dengan ``` cin << testcase; ```, lalu memasukkan kata yang ingin disimpan ``` cin >> kata ```. Kemudian memnginputkan kembali testcase kedua dengan ``` cin >> casetest; ``` dan juga memasukkan kata yang dicari. ``` if (set.search(cari_kata)) ``` berfungsi untuk mencari kata apakah kata yang dicari tersimpan, jika kata yang dicari tersimpan makan akan mengeluarkan angka 1 dengan fugsi ``` cout << "1" << endl; ``` dan sebaliknya jika kata yang dicari tidak tersimpan makan akan mengeluarkan angka 0 dengan fungsi ``` cout << "0" << endl;```.

## Visualisasi Solusi
![Visualisasi Kata-kata](https://user-images.githubusercontent.com/81666422/116956611-e378ae00-acbf-11eb-9d79-b37464b77aba.jpg)

# Malur Nguli
## Verdict 
AC Saat Revisi

## Bukti
![Verdict Malur Nguli](https://user-images.githubusercontent.com/81666422/116956729-2f2b5780-acc0-11eb-9bed-e02b01df700f.jpg)

## Penjelasan Soal
Pada soal Malur nguli diminta untuk memasukkan angka pada tree, dilanjutkan dengan menjumlahkan nilai node pada setiap kolom dan dimulai pada kolom kiri.

## Penjelasan Solusi
```
void Nilai(AVLNode *node, int cek) {
        if(node) { 
          
            if(cek==0) {    
                kanan[0]+=node->data; 
            } else if(cek<0) {
                if(abs(cek)>left_part) { 
                    left_part++;         
                }
                
                kiri[abs(cek)]+=node->data;  
            } else if(cek>0) {
                kanan[cek]+=node->data;
            }
            Nilai(node->left, cek-1);
            Nilai(node->right, cek+1);
        }
    }
 ```
 ``` void Nilai ``` berfungsi untuk mengecek angka pada setiap kolom kanan dan kiri.
 
 ```
 void total() {
        for(int i=0; i<1000; i++) {    
            kanan[i]=0;
            kiri[i]=0;
        }
        this->Nilai(_root, 0);
    }
 ```
 ``` void total ``` berfungsi untuk menjumlahkan nilai node di setiap kolom.
 ```
   int kolomKanan() {
        int temp=0;          
        AVLNode *currNode = _root;      
        while (currNode && currNode->right != NULL) {       
            currNode = currNode->right;        
            temp++;         
        }
        return temp;    
    }
    
    int kolomKiri() {
        int temp=0;
        AVLNode *currNode = _root;  
        while (currNode && currNode->left != NULL) {     
            currNode = currNode->left;          
            temp++;                  
        }
        return temp;     
    }
```
``` void kolomKanan ``` dan ``` void kolomKiri ``` berfungsi sebagai letak kolom kanan dan kiri.

```
int main () {
    AVL set;
    set.init();
    
    int testcase,N;
    string masuk;
    
    cin >> testcase;
    for (int i=1; i<= testcase; i++){
        cin >> masuk;
        if(masuk=="insert"){
            cin >> N;
            set.insert(N);
        }
        
        else if  (masuk=="print" && !set.isEmpty()){
            right_part = set.kolomKanan();
            left_part = set.kolomKiri();
            set.total();
                for (int m=left_part; m>0; m--){
                    cout << kiri[m] << " ";
                }
                for (int n=0; n<=right_part; n++){
                    cout << kanan[n] << " ";
                }
            cout << endl;
            
        }
    }
    
    return 0;
}
```
Pertama menginisialisasi AVL menggunakan ``` AVL set;``` ```set.init();```, dilanjutkan menginputkan sebuah testcase jika di soal yaitu 9 dengan ``` cin >> testcase; ```. Lalu manginputkan insert dengan ``` cin >> masuk; ``` dan ``` if(masuk=="insert") ```. ``` cin >> N; ``` berfungsi untuk menginputkan nilai node, kemudian ``` set.insert(N); ``` untuk memasukkan nilai node pada tree. Karena di soal di sebutkan jika yang diminta print maka nilai node akan dijumlahkan menggunakan ``` set.total();```, lalu angka akan dicetak menggunakan ``` cout << kiri[m] << " ";``` dan ```  cout << kanan[n] << " "; ```sesuai yang diminta soal yaitu menjumlahkan dari kolom kiri.

## Visualisasi Solusi
![Visualisasi Malur Nguli](https://user-images.githubusercontent.com/81666422/117013340-f8822b00-ad19-11eb-9dbb-287d16dd17b2.jpg)

# Cayo Niat
## Verdict
AC Saat Revisi (Kompensasi Mas Daniel)

## Bukti
![Verdict Cayo Niat](https://user-images.githubusercontent.com/81666422/117013708-4d25a600-ad1a-11eb-9f5c-89699939ed82.jpg)

## Penjelasan Soal
Pada soal Cayo Niat diminta untuk mengurutkan sebuah kata(nama) dimana kata(nama) yang diinputkan masih berantakan, dan disusun sesuai format ``` [string1]--<3--[string2]--<3--[string3]...--<3--[stringN] untuk N string```.

## Penjelasan Solusi
```
void inorderAngka(AVL *avl) {
    int angka = 1;     
    _inorderNum(avl->_root, &angka);
}

void _inorderRantai(AVLNode *root, int *angka) {
    if (root) {
        _inorderRantai(root->left, angka);
        if (*angka == 1){
            cout<<root->key;
        } else{
            cout<<"--<3--"<<root->key;
        }
        *angka = *angka+1;
        _inorderRantai(root->right, angka);
    }
}
void inorderRantai(AVL *avl) {
    int angka = 1;
    _inorderRantai(avl->_root, &angka);
}
```
Berfungsi sebagai perbandingan, jika benar maka akan scan nama mahasiswa dan jika sebaliknya salah maka akan scan rantai sesuai dengan output yang diminta soal.

```
int main(){
    AVL set;
    avl_init(&set);
    
    char mahasiswa[1005];
    int test;
    while(true){            
        test = scanf("%s", mahasiswa);
        if (test == -1 || test == EOF) {       
        
            break;
        }
        avl_insert(&set, mahasiswa);   
    }
    inorderAngka(&set);
    inorderRantai(&set);
    
    return 0;
}
```
Pertama menginisialisasi AVL menggunakan ``` AVL set;``` ```avl_init(&set);```, karena pada soal tidak ada format input maka nama mahasiswa diinputkan dengan ``` test = scanf("%s", mahasiswa); ```. Kemudian ``` if (test == -1 || test == EOF) ``` berfungsi untuk memberi batasan saat ``` break; ```. Dilanjutkan nama mahasiswa dimasukkan pada tree dengan ``` avl_insert(&set, mahasiswa) ```. Nama akan tercetak sesuai dengan format urutan yang diminta dengan ```inorderAngka(&set);``` dan ``` inorderRantai(&set); ```.

## Visualisasi Solusi
Memasukkan kata yang masih acak
![Visualisasi Cayo Niat 1](https://user-images.githubusercontent.com/81666422/117016142-9ecf3000-ad1c-11eb-91f2-ec828ed60a61.jpg)

Dilanjutkan dengan mencetak kata dengan urutan dimulai no 1 (satu). 
![Visualisasi Cayo Niat 2](https://user-images.githubusercontent.com/81666422/117016311-c625fd00-ad1c-11eb-95d8-55d2f64068fc.jpg)

Mencetak output sesuai format yang diminta soal
![Visualisasi Cayo Niat 3](https://user-images.githubusercontent.com/81666422/117016444-ebb30680-ad1c-11eb-9345-29068568ead6.jpg)

# Part Time
## Verdict
AC Saat Revisi

## Bukti
![Verdict Part Time](https://user-images.githubusercontent.com/81666422/117038604-0774d780-ad32-11eb-9538-3726b1d07f97.jpg)

## Penjelasan Soal
Pada soal Part Time diminta untuk mengurutkan id barang dimulai dari nomor 1 (satu), dan menghitung berapa banyak pendapatan toko hari tersebut. Kemudian menjumlah pendapatan dari tiap transaksi yang berlangsung pada hari itu.

## Penjelasan Solusi
```
int main(){
    AVL pohon;
    avl_init(&pohon);
 
    int banyakbarang, banyaktransaksi;
    int temp_idbarang, temp_harga;
    int sum = 0;
    int temp_banyakbeli, temp_idbeli;
    
    scanf("%d%d", &banyakbarang, &banyaktransaksi);
 
    for(int i = 0; i < banyakbarang; i++){
        scanf("%d%d", &temp_idbarang, &temp_harga);
 
        if(temp_idbarang != i + 1)
        {
            printf("ID harus urut\n");
            return 0;
        }
        else {
            avl_insert(&pohon, temp_harga, temp_idbarang);
        }
    }
 
    for(int i = 0; i < banyaktransaksi; i++){
        scanf("%d%d", &temp_banyakbeli, &temp_idbeli);
 
        if(temp_idbeli > banyakbarang || temp_idbeli < 0){
            printf("Maaf barang tidak tersedia\n");
        }
        else{
            sum = sum + (SumUtil(&pohon, temp_idbeli) * temp_banyakbeli);
        }
    }
    printf("%d\n", sum);
 
}
```
Pertama menginisialisasi AVL menggunakan ```AVL pohon;``` ``` avl_init(&pohon);```, dilanjutkan dengan menginputkan banyak barang dan banyak transaksi dengan ```  scanf("%d%d", &banyakbarang, &banyaktransaksi);``` lalu dilanjutkan dengan menginputkan id barang dan harga barang ``` scanf("%d%d", &temp_idbarang, &temp_harga);```. Jika id barang tidak urut ```  if(temp_idbarang != i + 1) ``` maka akan mencetak ``` printf("ID harus urut\n");```. Lalu jika id barang sesuai urutan makan akan menginputkan banyaknya membeli barang dan id harga barang yang dibeli ``` scanf("%d%d", &temp_banyakbeli, &temp_idbeli); ``` dan jika id harga barang yang dibeli  diinputkan tidak ada/ tidak tersimpan maka akan tercetak barang tidak tersedia, dengan fungsi ``` printf("Maaf barang tidak tersedia\n");```. Lalu jika id harga barang yang dibeli ada maka jumlah transkasi dapat dijumlahkan dengan ```sum = sum + (SumUtil(&pohon, temp_idbeli) * temp_banyakbeli);```.

## Visualisasi Solusi
Contoh Input dan Output 0 pada Soal ( Jika ID tidak urut)
![Visualisasi Part Time 1](https://user-images.githubusercontent.com/81666422/117040844-8539e280-ad34-11eb-9467-8c0d30501f20.jpg)

Contoh Input dan Output 1 pada Soal ( Jumlah transaksi )
![Visualisasi Part Time 2](https://user-images.githubusercontent.com/81666422/117040967-a6023800-ad34-11eb-958c-3882b1045500.jpg)

# Bucyn
## Verdict
AC Saat Revisi

## Bukti
![Verdict Bucyn](https://user-images.githubusercontent.com/81666422/117043116-02665700-ad37-11eb-8aee-aa2e20f30b15.jpg)

## Penjelasan Soal
Pada soal Bucyn diminta untuk menaruh dan mencari kaset, untuk setiap kaset diberi nama yang berupa episode keberapa dari drakor yang ditonton. Lalu membuat sebuah program untuk mempermudah bucin dalam melaksanakan perintah dari pacarnya.

## Penjelasan Solusi
```
int main(){
    SinglyList myList;
    slist_init(&myList);
    
    AVL avlavl;
    avl_init(&avlavl);

    int testcase;
    scanf("%d", &testcase);
    for(int i=1; i<=testcase; i++){
        char command [1000000];
        int angka;
        scanf(" %s", command);
        scanf("%d", &angka);

        if (strcmp(command, "Taro")==0){
            avl_insert(&avlavl, angka);
        }
        else if(strcmp(command, "Cari")==0){
                inorder(&avlavl, &myList);
                angka=slist_getIndex(&myList, angka);
                

            if(angka==-1)
                printf("Kasetnya gak ada!\n");
            else
                printf("Kasetnya ada di tumpukan ke - %d\n", angka);

            while (!slist_isEmpty(&myList)) slist_popFront(&myList);
        }
        else {
            printf("AKU TUH GATAU HARUS NGAPAIN!\n");
        }
    }
        return 0;
}
```
Pertama di soal Bucyn menggunakan Singly List dan AVL tree dengan menginisialisasi singly list menggunakan ``` SinglyList myList;``` ```slist_init(&myList);```, dan juga untuk AVL menggunakan ``` AVL avlavl;``` ```avl_init(&avlavl);```. Dilanjutkan dengan menginputkan testcase jika contoh pada soal yaitu 11 (sebelas) menggunakan ```scanf("%d", &testcase);``` Lalu menginputkan command yang diartikan Taro dan Cari, dan angka dengan ``` scanf(" %s", command);``` ```scanf("%d", &angka);```. Lalu jika command nya adalah Taro maka ``` avl_insert(&avlavl, angka);``` dan jika command nya adalah Cari maka ``` inorder(&avlavl, &myList);``` ```angka=slist_getIndex(&myList, angka);```. Dan jika pada tumpukan tidak maka akan mencetak dengan fungsi ```  printf("Kasetnya gak ada!\n"); ``` dan jika terdapat pada suatu tumpukan ke- maka akan tercetak dengan ```printf("Kasetnya ada di tumpukan ke - %d\n", angka);```. Kemudian jika ada inputan selain command yaitu Tari dan Cari maka akan mencetak  ``` printf("AKU TUH GATAU HARUS NGAPAIN!\n");```.

## Visual Solusi
contoh jika Taro 100 Cari 100 maka,
![Visual Bucyn](https://user-images.githubusercontent.com/81666422/117045046-435f6b00-ad39-11eb-9e22-456e19570a19.jpg)
menghitung tumpukan dimulai dari node paling bawah kiri hingga node yang ditentukan, tumpukan merupakan jumlah node yang dilewati.

# Nadut Belajar
## Verdict
AC Saat Revisi

## Bukti
![Verdict Nadut Belajar](https://user-images.githubusercontent.com/81666422/117022184-3a16d400-ad22-11eb-920b-1b6749ee1832.jpg)

## Penjelasan Soal
Pada soal Nadut Belajar diminta untuk menghitung bilangan selisih antara parent sebuah node dengan siblingnya.

## Penjelasan Solusi
```
void findsiblings(AVLNode *root, int val){
        if (val == root->data){
            cout << "0";
            return;
        }

        AVLNode *temp = root;
        cari = val;

        findparent(temp, cari, root->data);
        if (cari !=root->data){
            findparent(temp, cari, root->data);
            sumsiblings(temp, cari);
        }
        else{
            cout << cari;
        }
    }
    
    void findsiblings(AVLNode *root, int val){
        if (val == root->data){
            cout << "0";
            return;
        }

        AVLNode *temp = root;
        cari = val;

        findparent(temp, cari, root->data);
        if (cari !=root->data){
            findparent(temp, cari, root->data);
            sumsiblings(temp, cari);
        }
        else{
            cout << cari;
        }
    }
 ```
 Berfungsi untuk mecari praent dan sibling.
 
 ```
 int main () {
    AVL set;
    set.init();

    int testcase,N,M;
    cin >> testcase >> N;
        for (int i=1; i<=testcase; i++){
             cin >> M;
            set.insert(M);
        }
    
        for (int i=1; i<=N; i++){
        cin >> M;
        if (set.find(M)){
            set.findsiblings2(M);
            if (i < N - 0){
               cout << "\n";
            }
        }
            else{
            cout << "0\n";
        }
    }
    return 0;
}
```
Pertama menginisialisasi AVL menggunakan ``` AVL set;``` ```avl_init(&set);```,  dilanjutkan dengan menginputkan testcase yang diartikan jumlah(banyaknya) nilai node pada tree  dan jumlah(banyaknya) nilai node yang akan di cek dengan ``` cin >> testcase >> N; ```. Dan ``` cin >> M; ``` merupakan node yang yang di cek pada tree. ``` if (set.find(M))``` dan ``` set.findsiblings2(M); ``` digunakan untuk mencari parent dan sibling nilai node yang di cek, jika sudah ditemukan maka parent dan sibling akan dihitung selisihnya ``` if (i < N - 0) ``` maka akan tercetak hasil selisihnya ``` cout << "\n"; ``` dan jika parentnya merupakan sebuah root maka akan tercetak ``` cout << "0\n"; ```.

## Visualisasi Solusi
![Visualisasi Nadut Belajar](https://user-images.githubusercontent.com/81666422/117029764-2d49ae80-ad29-11eb-850d-fa02e0554b0f.jpg)








     
       

