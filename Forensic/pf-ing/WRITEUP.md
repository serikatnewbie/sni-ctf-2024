Tidak ditemukan proses mencurigakan pada pstree dan pslist

Oleh karena itu coba cari recent opened apps dengan melihat file prefetch

https://www.geeksforgeeks.org/prefetch-files-in-windows/ 

```vol -f dump.dmp windows.filescan | grep ".pf"```

![image](https://github.com/user-attachments/assets/2bd0ab77-5b92-4e6e-a017-b576fb25d638)


coba analisa file2 prefetch tersebut dan ingat bahwa proses microsoft edge adalah msedge.exe bukan Edge.exe

Ketika parsing prefetch Edge.exe dengan PECmd
Ditemukan ini bahwa Edge.exe melakukan loading beberapa file yang berada dalam folder “Documents” lalu load sebuah file .dll di folder %localappdata%/temp. Hal ini tentu sangat mencurigakan

![image](https://github.com/user-attachments/assets/38a79151-b37b-44b8-a180-aee06970919e)

Oleh karena itu bisa diasumsikan bahwa Edge.exe lah yang merupakan malicious program dan mungkin data2 itu adalah data asli dan data terenkripsi yang dihasilkan
dumping Edge.exe dan file2 yang terkenkripsi

![image](https://github.com/user-attachments/assets/e3eac30c-7083-40b7-be43-5d0608e166e7)

Decompile Edge.exe

![image](https://github.com/user-attachments/assets/8c0a06c2-f112-4341-8090-ffb841856c9a)

Fungsi enkripsi dengan XOR,

![image](https://github.com/user-attachments/assets/3dc14694-d4c2-4e97-a728-89048fd146a9)

Key dirand namun hanya dalam rentang % 256. Maka bisa dibruteforce

Dumping Encrypted File

![image](https://github.com/user-attachments/assets/a3fc04a7-6b88-44d7-83be-00f7abb014ba)
![image](https://github.com/user-attachments/assets/7021999f-05dc-409f-8d6b-271421acf34b)


Command:

```vol -f dump.dmp windows.dumpfiles --virtaddr {offset}```

Decrypt:

![image](https://github.com/user-attachments/assets/0ff673c6-1b14-465f-af2d-5658028e6b6c)
