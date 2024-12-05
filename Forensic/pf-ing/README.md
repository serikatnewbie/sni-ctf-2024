## desc:
believe me, its just an intro to DFIR about ransom cases
> https://mega.nz/file/Eu4VHSKJ#6bC9BSbdrHiG4r9j7fh2YefZWtf7nmBOGtvjJ2oZreo

## flag:
```SNI{intr0_t0_df1r_and_th1s_g1rl_is_w4y_b3tter_than_Chizuru}```

## scenario
- flag is in C:\Users\Documents\My-Beloved-Wife.png
- the users ran a program named Edge.exe it will encrypt all files in Documents folder into {n+1}.dll and move it to new folder in %localappdata%\Temp\Store

## topic:
- memdump
- prefetch
- encryption

## poc:
- volatility filescan to look for prefetch files
- prefetch to see recent apps and loaded file
- volatility filescan to search for files
- volatility dumpfiles to dump files
- reverse engineer the ransomware
- decrypt encrypted files

## related article:
https://medium.com/@k.eii/leveraging-prefetch-files-in-memory-forensics-uncovering-hidden-evidence-beyond-volatile-memory-a1329fe136b0

## rar password:
```k.eii_1s_just_a_cut3_l1ttl3_b1rb```
