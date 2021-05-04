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
Pertama kita menginputkan testcase pertama dengan ``` cin << testcase; ```, lalu memasukkan kata yang ingin disimpan ``` cin >> kata ```. Kemudian memnginputkan kembali testcase kedua dengan ``` cin >> casetest; ``` dan juga memasukkan kata yang dicari. ``` if (set.search(cari_kata)) ``` berfungsi untuk mencari kata apakah kata yang dicari tersimpan, jika kata yang dicari tersimpan makan akan mengeluarkan angka 1 dengan fugsi ``` cout << "1" << endl; ``` dan sebaliknya jika kata yang dicari tidak tersimpan makan akan mengeluarkan angka 0 dengan fungsi ``` cout << "0" << endl;```.

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

 
