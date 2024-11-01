## desc:
Kata-katanya dong buat hari ini.
> https://drive.google.com/file/d/1Y-nRtuoGJORsQbN9YscZhmirZN7hDhnv/view?usp=drive_link
Jangan lupa flagnya nanti diwrapped dengan `SNI{}`

## flag:
```SNI{jika_seseorang_bercerita_tentang_buruknya_diriku_kabari_aku_siapa_tau_ceritanya_kurang_lengkap_e35983a5738e}```

## poc
- It is not a PNG file, remove first 16 bytes
- Reverse the hexdump to get a PE32 executable file
- Run the executable file to get the first part
- Extract the embedded strings to get the second part
- Use GHidra or just `strings` to see the hidden variable to get the third part

## topic:
- corrupted file
