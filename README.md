# Kata-Kata
## Verdict 
AC Saat Revisi

## Bukti
![Verdict Kata-Kata](https://user-images.githubusercontent.com/81666422/116954995-87ac2600-acbb-11eb-88d8-126ea5fc2004.jpg)

## Penjelasan Soal
Pada soal kata-kata diminta untuk mencari kata yang tersimpan.

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








     
       

