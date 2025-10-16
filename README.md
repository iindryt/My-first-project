Programos Testavimo Rezultatai v0.3
Šioje projekto dalyje atliekamas dviejų  C++ konteinerių našumo testavimas, skirtas studentų duomenų nuskaitymui, rūšiavimui ir įrašymui. Šiame dokumente pateikiami išsamūs programos testavimo rezultatai, įskaitant dviejų konteinerių našumo matavimus pagal skirtingo dydžio failus.
Testavimo data: 2025–10–15
Sistemos Parametrai
- Procesorius (CPU): AMD Ryzen 5 3550H with Radeon Vega Mobile Gfx, 2.10 GHz  
- RAM: 8 GB (naudojama ~5,88 GB)  
- Grafika: 6 GB, Radeon Vega Mobile Gfx  
- Atmintis (HDD/SSD): 477 GB (SSD)  
- Operacinė sistema (OS): Windows 11, 64-bit  
Testavimo Metodika
Testuojami du C++ standartiniai konteineriai: std::vector ir std::list.  
Matavimai atliekami trimis pagrindinėmis operacijomis:
  1. Nuskaitymas – duomenų nuskaitymas iš failo į konteinerį.
  2. Rūšiavimas – duomenų rūšiavimas konteineryje.
  3. Įrašymas – duomenų įrašymas atgal į failą.
Laikas matuojamas sekundėmis su tikslumu iki šešių (įskaitant) skaičių po kablelio.
Testavimo Rezultatai:
| Failas                 | Konteineris | Nuskaitymas (s) | Skirstymas (s) | Įrašymas (s)  | Visas testas (s) |
| ---------------------- | ----------- | --------------- | -------------- | ------------- | ---------------- |
| studentai_1000.txt     | std::vector | 0.0056859       | 0.000215       | 0.002819      | 0.011070         |
| studentai_1000.txt     | std::list   | 0.006416        | 0.000157       | 0.014394      | 0.022621         |
| studentai_10000.txt    | std::vector | 0.042181        | 0.002711       | 0.016948      | 0.066189         |
| studentai_10000.txt    | std::list   | 0.043124        | 0.002033       | 0.016385      | 0.064150         |
| studentai_100000.txt   | std::vector | 0.440618        | 0.026316       | 0.133719      | 0.604092         |
| studentai_100000.txt   | std::list   | 0.426942        | 0.020604       | 0.140861      | 0.592571         |
| studentai_1000000.txt  | std::vector | 4.40848         | 0.271929       | 1.274328      | 5.957573         |
| studentai_1000000.txt  | std::list   | 4.367253        | 0.209767       | 1.425252      | 6.005412         |
| studentai_10000000.txt | std::vector | 44.783089       | 5.682959       | 13.204492     | 63.676864        |
| studentai_10000000.txt | std::list   | 43.502372       | 2.101811       | 14.136841     | 59.744353        |

Išvados
1. Maži failai (1000–10 000 įrašų):
  1.1 std::vector šiek tiek greitesnis įrašant duomenis su 1000, taip ir ir nuskaitant failą, o std::list greitesnis rūšiuojant. Bendras laikas greitesnis su vektoriumi. 
  1.2 std::list įrašymas, rūšiavimas yra šiek tiek greitesnis, tačiau nuskaitymas užtrunka ilgiau. Bendras laikas labai panašus, tačiau std::list greitesnis. (10 000)
2. Vidutinio dydžio failai (100 000–1 000 000 įrašų):
   2.1 std::list (100 000) pranašesnis nuskaityme ir skirstyme, o std::vector – įrašyme. 
   2.2 Bendras laikas rodo, kad skirtumas tarp std::vector ir std::list mažėja – std::list pranašesnis vos 0.1 sek. 
   2.3 std::vector (1 000 000) lėtesnis už std::list tiek nuskaityme, skirstyme, bet greitesnis įrašyme. 
   2.4 Bendrame laike std::vector laimi 0,05 sek. 
3. Dideli failai (10 000 000 įrašų):
   3.1 std::vector įrašymo laikas yra šiek tiek trumpesnis nei std::list, 1,1 sek.
   3.2 Abu konteineriai užtrunka daug laiko, tačiau std::list šiek tiek greitesnis bendrame rezultate,  daugiausia dėl efektyvesnio rūšiavimo.
Bendros išvados
Mažuose duomenų kiekiuose (iki 10 000 įrašų) reikšmingo skirtumo tarp konteinerių beveik nėra.
Vidutinio dydžio failuose (100 000–1 000 000 įrašų) našumo skirtumas tarp konteinerių pakankamai mažas.
Labai dideliuose duomenų kiekiuose (10 000 000 įrašų) skirtumai išryškėja.
