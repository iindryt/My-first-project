# Programos Testavimo Rezultatai v0.3 ir v1.0 (žemiau)

Šioje projekto dalyje atliekamas dviejų C++ konteinerių našumo testavimas, skirtas studentų duomenų nuskaitymui, rūšiavimui ir įrašymui.  
Šiame dokumente pateikiami išsamūs programos testavimo rezultatai, įskaitant dviejų konteinerių našumo matavimus pagal skirtingo dydžio failus.

**Testavimo data:** 2025–10–15

---

## Sistemos Parametrai

| Komponentas | Aprašymas |
|--------------|-----------|
| **Procesorius (CPU)** | AMD Ryzen 5 3550H with Radeon Vega Mobile Gfx, 2.10 GHz |
| **RAM** | 8 GB (naudojama ~5,88 GB) |
| **Grafika** | 6 GB, Radeon Vega Mobile Gfx |
| **Atmintis (HDD/SSD)** | 477 GB (SSD) |
| **Operacinė sistema (OS)** | Windows 11, 64-bit |

---

## Testavimo Metodika

Testuojami du C++ standartiniai konteineriai:  
- `std::vector`  
- `std::list`

Matavimai atliekami trimis pagrindinėmis operacijomis:
1. **Nuskaitymas** – duomenų nuskaitymas iš failo į konteinerį.  
2. **Rūšiavimas** – vargšiukai/kietiakiai skirstymas konteineryje.  
3. **Įrašymas** – duomenų įrašymas atgal į failą.  

Laikas matuojamas **sekundėmis** su tikslumu iki šešių skaičių po kablelio.

---

## Testavimo Rezultatai

| Failas | Konteineris | Nuskaitymas (s) | Skirstymas (s) | Įrašymas (s) | Visas testas (s) |
|----------------------|-------------|----------------|---------------|----------------|----------------|
| studentai_1000.txt | std::vector | 0.0056859 | 0.000215 | 0.002819 | 0.011070 |
| studentai_1000.txt | std::list | 0.006416 | 0.000157 | 0.014394 | 0.022621 |
| studentai_10000.txt | std::vector | 0.042181 | 0.002711 | 0.016948 | 0.066189 |
| studentai_10000.txt | std::list | 0.043124 | 0.002033 | 0.016385 | 0.064150 |
| studentai_100000.txt | std::vector | 0.440618 | 0.026316 | 0.133719 | 0.604092 |
| studentai_100000.txt | std::list | 0.426942 | 0.020604 | 0.140861 | 0.592571 |
| studentai_1000000.txt | std::vector | 4.40848 | 0.271929 | 1.274328 | 5.957573 |
| studentai_1000000.txt | std::list | 4.367253 | 0.209767 | 1.425252 | 6.005412 |
| studentai_10000000.txt | std::vector | 44.783089 | 5.682959 | 13.204492 | 63.676864 |
| studentai_10000000.txt | std::list | 43.502372 | 2.101811 | 14.136841 | 59.744353 |

---

## Išvados

### 1. Maži failai (1000–10 000 įrašų)
1.1 `std::vector` šiek tiek greitesnis įrašant duomenis su 1000, taip ir nuskaitant failą, o `std::list` greitesnis rūšiuojant. Bendras laikas greitesnis su vektoriumi.  
1.2 `std::list` įrašymas, rūšiavimas yra šiek tiek greitesnis, tačiau nuskaitymas užtrunka ilgiau. Bendras laikas labai panašus, tačiau `std::list` greitesnis. (10 000)

### 2. Vidutinio dydžio failai (100 000–1 000 000 įrašų)
2.1 `std::list` (100 000) pranašesnis nuskaityme ir skirstyme, o `std::vector` – įrašyme.  
2.2 Bendras laikas rodo, kad skirtumas tarp `std::vector` ir `std::list` mažėja – `std::list` pranašesnis vos 0.1 sek.  
2.3 `std::vector` (1 000 000) lėtesnis už `std::list` tiek nuskaityme, skirstyme, bet greitesnis įrašyme.  
2.4 Bendrame laike `std::vector` laimi 0,05 sek.

### 3. Dideli failai (10 000 000 įrašų)
3.1 `std::vector` įrašymo laikas yra šiek tiek trumpesnis nei `std::list`, 1,1 sek.  
3.2 Abu konteineriai užtrunka daug laiko, tačiau `std::list` šiek tiek greitesnis bendrame rezultate, daugiausia dėl efektyvesnio rūšiavimo.

---

## Bendros Išvados

- Mažuose duomenų kiekiuose (iki 10 000 įrašų) reikšmingo skirtumo tarp konteinerių beveik nėra.  
- Vidutinio dydžio failuose (100 000–1 000 000 įrašų) našumo skirtumas tarp konteinerių pakankamai mažas.  
- Labai dideliuose duomenų kiekiuose (10 000 000 įrašų) skirtumai išryškėja.

---

# Testų rezultatai: vector vs list

| Failas | Strategija | Konteineris | Nuskaitymas (s) | Skirstymas (s) | Įrašymas (s) | Visas testas (s) | Studentai (baitai) | Kietiakiai (baitai) | Vargsiukai (baitai) |
|--------|-----------|-------------|----------------|----------------|---------------|-----------------|-------------------|-------------------|-------------------|
| studentai_1000.txt | 1 | vector | 0.011388 | 0.000624 | 0.011908 | 6.587381 | 104000 | 61984 | 42016 |
| studentai_1000.txt | 1 | list   | 0.009837 | 0.000390 | 0.004834 | 4.265823 | 120000 | 71520 | 48480 |
| studentai_1000.txt | 2 | vector | 0.007091 | 0.004588 | 0.003635 | 2.218336 | 61984 | 61984 | 42016 |
| studentai_1000.txt | 2 | list   | 0.008835 | 0.000318 | 0.006600 | 2.499706 | 71520 | 71520 | 48480 |
| studentai_1000.txt | 3 | vector | 0.007307 | 0.000251 | 0.004978 | 3.867256 | 104000 | 61984 | 42016 |
| studentai_1000.txt | 3 | list   | 0.010077 | 0.000502 | 0.004829 | 3.359666 | 71520 | 71520 | 48480 |
| studentai_10000.txt | 1 | vector | 0.103659 | 0.002038 | 0.024930 | 5.170371 | 1040000 | 614952 | 425048 |
| studentai_10000.txt | 1 | list   | 0.068396 | 0.003069 | 0.024734 | 3.392315 | 1200000 | 709560 | 490440 |
| studentai_10000.txt | 2 | vector | 0.064200 | 0.365824 | 0.032874 | 1.867561 | 614952 | 614952 | 425048 |
| studentai_10000.txt | 2 | list   | 0.072235 | 0.005389 | 0.032226 | 2.004752 | 709560 | 709560 | 490440 |
| studentai_10000.txt | 3 | vector | 0.063341 | 0.001482 | 0.022831 | 2.454926 | 1040000 | 614952 | 425048 |
| studentai_10000.txt | 3 | list   | 0.067361 | 0.005128 | 0.026153 | 1.869845 | 709560 | 709560 | 490440 |
| studentai_100000.txt | 1 | vector | 0.678737 | 0.013575 | 0.223477 | 4.181027 | 10400000 | 6082440 | 4317560 |
| studentai_100000.txt | 1 | list   | 0.648155 | 0.034280 | 0.246839 | 2.509687 | 12000000 | 7018200 | 4981800 |
| studentai_100000.txt | 2 | vector | 0.700131 | 43.801200 | 0.221867 | 46.298131 | 6082440 | 6082440 | 4317560 |
| studentai_100000.txt | 2 | list   | 0.629234 | 0.046543 | 0.273114 | 61.246084 | 7018200 | 7018200 | 4981800 |
| studentai_100000.txt | 3 | vector | 0.672563 | 0.013891 | 0.206427 | 2.306455 | 10400000 | 6082440 | 4317560 |
| studentai_100000.txt | 3 | list   | 0.648415 | 0.046395 | 0.220283 | 4.507188 | 7018200 | 7018200 | 4981800 |
| studentai_1000000.txt | 1 | vector | 7.188728 | 0.152040 | 2.279783 | 14.682385 | 104000000 | 60947848 | 43052152 |
| studentai_1000000.txt | 1 | list   | 7.352400 | 0.349458 | 2.243658 | 13.865441 | 120000000 | 70324440 | 49675560 |
| studentai_1000000.txt | 2 | vector | 7.081233 | 63.578412 | 2.325890 | 74.991123 | 60947848 | 60947848 | 43052152 |
| studentai_1000000.txt | 2 | list   | 6.982732 | 0.698352 | 2.356187 | 11.218531 | 70324440 | 70324440 | 49675560 |
| studentai_1000000.txt | 3 | vector | 6.993810 | 0.169437 | 2.291211 | 11.284984 | 104000000 | 60947848 | 43052152 |
| studentai_1000000.txt | 3 | list   | 6.924288 | 0.536978 | 2.304375 | 11.460528 | 70324440 | 70324440 | 49675560 |
| studentai_10000000.txt | 1 | vector | 69.409401 | 3.586494 | 23.406183 | 101.032615 | 1040000000 | 610196392 | 429803608 |
| studentai_10000000.txt | 1 | list   | 69.114784 | 3.592124 | 24.094034 | 100.384979 | 1200000000 | 704072760 | 495927240 |
| studentai_10000000.txt | 2 | vector | 69.271904 | 540.332457 | 23.684832 | 634.021341 | 610196392 | 610196392 | 429803608 |
| studentai_10000000.txt | 2 | list   | 69.072383 | 4.561772 | 24.115682 | 101.181837 | 704072760 | 704072760 | 495927240 |
| studentai_10000000.txt | 3 | vector | 69.492027 | 3.603214 | 23.531784 | 101.105241 | 1040000000 | 610196392 | 429803608 |
| studentai_10000000.txt | 3 | list   | 69.113822 | 4.561882 | 24.062441 | 100.414295 | 1200000000 | 704072760 | 495927240 |


# Studentų konteinerių testavimas (std::vector)

Šiame projekte testuojamas `std::vector` konteineris studentų duomenų nuskaitymui, skirstymui ir įrašymui į failus. Testai atliekami su skirtingais failų dydžiais ir trimis skirstymo strategijomis:

**Skirstymo strategijos:**
1. Dvi kopijos (kietiakiai + vargsiukai)  
2. Viena kopija su trynimu (vargsiukai, studentai = kietiakiai)  
3. Automatinis greičiausios strategijos pasirinkimas  

---

## Testų rezultatai

| Failo pavadinimas         | Strategija | Nuskaitymo laikas (s) | Skirstymo laikas (s) | Įrašymo laikas (s) | Bendras laikas (s) | Bendras atminties kiekis (B) |
|----------------------------|------------|----------------------|---------------------|-------------------|------------------|-----------------------------|
| studentai_1000.txt         | 1          | 0.012621             | 0.000212            | 0.003623          | 2.374976         | 146016                      |
| studentai_1000.txt         | 2          | 0.006690             | 0.000466            | 0.003424          | 2.331519         | 146016                      |
| studentai_1000.txt         | 3          | 0.0055215            | 0.000205            | 0.003518          | 1.572414         | 146016                      |
| studentai_10000.txt        | 1          | 0.0506323            | 0.001345            | 0.014548          | 4.788391         | 1465048                     |
| studentai_10000.txt        | 2          | 0.0469966            | 0.001177            | 0.015930          | 1.913413         | 1465048                     |
| studentai_10000.txt        | 3          | 0.0422042            | 0.001356            | 0.016032          | 2.324799         | 1465048                     |
| studentai_100000.txt       | 1          | 0.432306             | 0.012001            | 0.133513          | 2.740498         | 14717560                    |
| studentai_100000.txt       | 2          | 0.428288             | 0.014004            | 0.138328          | 2.367536         | 14717560                    |
| studentai_100000.txt       | 3          | 0.429712             | 0.012564            | 0.140886          | 2.080882         | 14717560                    |
| studentai_1000000.txt      | 1          | 4.31719              | 0.120427            | 1.349626          | 7.603468         | 147052152                   |
| studentai_1000000.txt      | 2          | 4.34261              | 0.119508            | 1.359096          | 7.345121         | 147052152                   |
| studentai_1000000.txt      | 3          | 4.36461              | 0.114621            | 1.371857          | 7.900922         | 147052152                   |
| studentai_10000000.txt     | 1          | 44.3534              | 1.743203            | 14.110885         | 75.563293        | 1469803608                  |
| studentai_10000000.txt     | 2          | 43.888               | 1.303107            | 14.275346         | 62.486793        | 1469803608                  |
| studentai_10000000.txt     | 3          | 44.6685              | 1.658356            | 14.108276         | 136.162354       | 1469803608                  |

---

## Išvados

- Strategija 1 (dvi kopijos) dažniausiai buvo efektyvi vektoriui didelių failų atveju.  
- Strategija 2 (viena kopija su trynimu) mažina bendrą laiko sąnaudą mažesniuose failuose.  
- Strategija 3 leidžia automatiškai pasirinkti geriausią strategiją pagal failo dydį.  
- Laikas ir atminties naudojimas auga proporcingai failo dydžiui.  

