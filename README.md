# Studentų pažymių valdymo programa 

# # Naudojimosi instrukcija

Programa veikia meniu principu ir leidžia valdyti studentų pažymius.

## Paleidimas

- Linux/MacOS: `./studentai`  
- Windows: `studentai.exe`

## Pagrindinis meniu

Pasirinkite veiksmą:

1. **Pridėti studentą rankiniu būdu**  
   - Įveskite vardą, pavardę, namų darbų ir egzamino pažymius (arba generuokite atsitiktinius).

2. **Nuskaityti studentus iš failo**  
   - Failas turi turėti antraštę: `Vardas Pavarde ND1 ND2 ... Egzaminas`.

3. **Rodyti studentų rezultatus**  
   - Pasirinkite galutinio balo skaičiavimo metodą: Vidurkis / Mediana / Abu.  
   - Rezultatai išsaugomi `rezultatai.txt`.  
   - Galima skirstyti studentus į:  
     - **Kietiakiai** (≥5) – `kietiakiai.txt`  
     - **Vargsiukai** (<5) – `vargsiukai.txt`

4. **Baigti programą**  

5. **Generuoti studentų failus (1k–10 mln)**  
   - Sukuria atsitiktinius studentų duomenų failus testavimui.

6. **Testuoti konteinerius (vector vs list)**  
   - Atliekami našumo testai nuskaitymui, rūšiavimui ir įrašymui.

7. **Automatinis testavimas su visais failais**  
   - Paleidžia visus testus automatiškai dideliems failams.

**Jūsų pasirinkimas yra:**



## v.01

Ši programa leidžia valdyti studentų pažymius, skaičiuoti galutinius balus ir išsaugoti rezultatus į failą. Programa suteikia galimybę studentus įvesti rankiniu būdu arba nuskaityti iš failo, generuoti atsitiktinius pažymius, ir skaičiuoti galutinį rezultatą naudojant vidurkį arba medianą.

---

## Funkcionalumas

1. **Studentų įvedimas rankiniu būdu**
   - Įvedamas vardas ir pavardė.
   - Galima įvesti namų darbų pažymius rankiniu būdu arba sugeneruoti atsitiktinius.
   - Egzamino pažymį galima įvesti rankiniu būdu arba sugeneruoti atsitiktinį.
   - Galutinis balas skaičiuojamas pagal vidurkį ir medianą:
     - `Galutinis (Vid.) = 0.4 * namų darbų vidurkis + 0.6 * egzamino pažymys`
     - `Galutinis (Med.) = 0.4 * namų darbų mediana + 0.6 * egzamino pažymys`

2. **Studentų nuskaitymas iš failo**
   - Failas turi būti tekstinis, su pirmąja eilute kaip header, pvz.:
     ```
     Vardas Pavarde ND1 ND2 ND3 ... Egzaminas
     ```
   - Programa perskaito studentus, patikrina, ar įvesti bent du pažymiai (namų darbai + egzaminas).

3. **Rezultatų atvaizdavimas ir išsaugojimas**
   - Rezultatai gali būti skaičiuojami pagal:
     - Vidurkį
     - Medianą
     - Abu (vidurkis ir mediana)
   - Rezultatai išsaugomi faile `rezultatai.txt`.

4. **Programa veikia meniu principu**
   - Galimi veiksmai:
     1. Pridėti studentą rankiniu būdu
     2. Nuskaityti studentus iš failo
     3. Rodyti studentų rezultatus
     4. Baigti programą
## Rezultatai

Programa skaičiuoja ir išsaugo studentų galutinius balus faile `rezultatai.txt`. Galutinis balas gali būti apskaičiuotas naudojant:

1. **Vidurkį (Galutinis (Vid.))**  
   - Skaičiuojamas taip:
     ```
     Galutinis (Vid.) = 0.4 * namų darbų vidurkis + 0.6 * egzamino pažymys
     ```
   - Šis metodas pabrėžia egzamino reikšmę (60% galutinio balo) ir naudoja visų namų darbų vidurkį kaip 40% galutinio balo dalį.
   - Tinka, kai norima, kad visų pažymių suma būtų atspindima vienu vidurkiu.

2. **Medianą (Galutinis (Med.))**  
   - Skaičiuojama taip:
     ```
     Galutinis (Med.) = 0.4 * namų darbų mediana + 0.6 * egzamino pažymys
     ```
   - Naudojama namų darbų mediana vietoje vidurkio, todėl vienas itin žemas arba aukštas pažymys mažiau įtakoja galutinį rezultatą.
   - Šis metodas suteikia stabilesnį galutinį balą, kai namų darbų pažymiai yra nevienodi.

3. **Abi (Vidurkis ir Mediana)**  
   - Programa gali išsaugoti tiek `Galutinis (Vid.)`, tiek `Galutinis (Med.)` stulpelius.
   - Tai leidžia palyginti, kaip skirtingi skaičiavimo metodai veikia studentų galutinius rezultatus.

**Pastaba:**  
- Visi rezultatai yra suformatuoti su dviem skaitmenimis po kablelio.
- Studentai rūšiuojami pagal vardą, kad rezultatai būtų tvarkingi ir lengvai skaitomi.
- Rezultatai išsaugomi faile `rezultatai.txt` tame pačiame kataloge, kuriame paleista programa.

# Studentų pažymių valdymo programa – Versija v.02

Ši dokumentacija tęsia ankstesnės versijos (v.01) aprašymą ir aptaria naujoves bei patobulinimus, įdiegtus versijoje Nr. 2.

---

## Naujos funkcijos ir patobulinimai v.02

1. **Studentų rūšiavimas pagal vardą**
   - Visi studentai dabar rūšiuojami pagal vardą prieš išvedant rezultatus.
   - Tai pagerina rezultatų tvarkingumą ir palengvina peržiūrą didesnėse grupėse.

2. **Galutinių balų pasirinkimas**
   - Vartotojas gali pasirinkti, kaip skaičiuoti galutinį balą:
     - Vidurkis (`Galutinis (Vid.)`)
     - Mediana (`Galutinis (Med.)`)
     - Abu variantai vienu metu
   - Šis patobulinimas suteikia daugiau lankstumo vertinant studentus.

3. **Studentų skirstymas į kategorijas**
   - Įdiegta funkcija automatiškai skirstyti studentus į dvi kategorijas:
     - **Kietiakiai** – galutinis balas ≥ 5
     - **Vargsiukai** – galutinis balas < 5
   - Rezultatai išsaugomi atskiruose failuose:
     - `kietiakiai.txt`
     - `vargsiukai.txt`

4. **Failų generavimas**
   - Pridėta galimybė generuoti studentų failus su atsitiktiniais duomenimis dideliam kiekiui studentų (nuo 1 tūkst. iki 10 mln.).
   - Naudinga testuojant programą su dideliais duomenų rinkiniais.

5. **Laikmatio matavimas**
   - Matuojamas laiką, reikalingą:
     - studentų rūšiavimui
     - rezultatų išvedimui į failą
     - skirstymui į kietiakiai/vargsiukai
   - Tai leidžia stebėti operacijų efektyvumą didelėse grupėse.

6. **Modulinė struktūra**
   - Programa padalinta į atskirus modulius:
     - `main.cpp` – pagrindinis meniu
     - `funkcijos.cpp/h` – studentų įvedimas, skaičiavimai, rezultatų spausdinimas
     - `duomenys.cpp/h` – failų nuskaitymas ir generavimas
     - `studentas.h` – studento struktūra
     - `laikmatis.h` – operacijų laiko matavimas

---

## Rezultatų aptarimas v.02

- **Galutinis balas pagal vidurkį:** naudoja visų namų darbų vidurkį; egzamino reikšmė – 60%.
- **Galutinis balas pagal medianą:** atsparus itin žemiems ar aukštiems pažymiams; egzamino reikšmė – 60%.
- **Skirstymas į kategorijas:** leidžia greitai identifikuoti stipriausius ir silpniausius studentus.
- **Išsaugomi failai:**
  - `rezultatai.txt` – visi studentai su galutiniu balu.
  - `kietiakiai.txt` – studentai su galutiniu balu ≥ 5.
  - `vargsiukai.txt` – studentai su galutiniu balu < 5.
- **Papildomas efektyvumo matavimas:** leidžia stebėti programos našumą dideliuose duomenų rinkiniuose.

---

## Pastabos

- Egzamino ir namų darbų pažymiai turi būti tarp 1 ir 10.
- Atsitiktinių pažymių generavimui naudojamas `rand()` su `srand(time(nullptr))`.
- Versija 0.02 išlaiko visą ankstesnės versijos funkcionalumą, bet prideda patogesnį rezultatų valdymą, rūšiavimą ir efektyvumo matavimą.






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
# v.1.0
# Testų rezultatai: vector vs list


# Studentų konteinerių testavimas

Šioje projekto dalyje testuojamas **std::vector** ir **std::list** konteinerių našumas skirtingais atvejais: nuskaitymas, skirstymas ir įrašymas į failus.  
Taip pat atliktas papildomas testas su **std::vector**, naudojant **STL algoritmus**.

---

## Skirstymo strategijos

1. **Dvi kopijos** – sukuriami atskiri konteineriai *kietiakiams* ir *vargšiukams*.  
2. **Viena kopija su trynimu** – duomenys skirstomi vietoje, ištrinant nereikalingus.  
3. **Automatinis pasirinkimas** – parenkama greičiausia strategija pagal konteinerį.

---


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


# Studentų konteinerių testavimas (std::vector (pridėtas ir std::list, nors parametrai nekeisti) su STL

Šiame projekto etape testuojamas `std::vector` konteineris studentų duomenų nuskaitymui, skirstymui ir įrašymui į failus. Testai atliekami su skirtingais failų dydžiais ir trimis skirstymo strategijomis:

---
| Failo dydis | Konteineris | Strategija | Failo nuskaitymas (s) | Skirstymas (s)  | Įrašymas į failus (s) | Bendras studentų konteineris (B) | Kietiakiai (B) | Vargsiukai (B) | Viso (apytiksliai) (B) | Visas testas (s) |
| ----------- | ----------- | ---------- | --------------------- | --------------- | --------------------- | -------------------------------- | -------------- | -------------- | ---------------------- | ---------------- |
| 1 000       | vector      | 1          | 0.0198                | 0.00037         | 0.0108                | 72 000                           | 42 912         | 29 088         | 144 000                | 4.308            |
| 1 000       | list        | 1          | 0.0183                | 0.00086         | 0.0135                | 80 000                           | 47 680         | 32 320         | 160 000                | 1.958            |
| 1 000       | vector      | 2          | 0.0134                | 0.0067          | 0.0099                | 42 912                           | 42 912         | 29 088         | 114 912                | 3.848            |
| 1 000       | list        | 2          | 0.0193                | 0.00053         | 0.00778               | 47 680                           | 47 680         | 32 320         | 127 680                | 1.070            |
| 1 000       | vector      | 3          | 0.0117                | 0.00045/0.00087 | 0.00735               | 72 000                           | 42 912         | 29 088         | 144 000                | 1.404            |
| 1 000       | list        | 3          | 0.0132                | 0.00068/0.00063 | 0.00846               | 80 000                           | 47 680         | 32 320         | 160 000                | 1.019            |
| 10 000      | vector      | 1          | 0.115                 | 0.0021          | 0.0343                | 720 000                          | 425 736        | 294 264        | 1 440 000              | 2.105            |
| 10 000      | list        | 1          | 0.106                 | 0.0048          | 0.0372                | 800 000                          | 473 040        | 326 960        | 1 600 000              | 1.276            |
| 10 000      | vector      | 2          | 0.107                 | 0.4178          | 0.0415                | 425 736                          | 425 736        | 294 264        | 1 145 736              | 2.596            |
| 10 000      | list        | 2          | 0.120                 | 0.0077          | 0.0363                | 473 040                          | 473 040        | 326 960        | 1 273 040              | 2.063            |
| 10 000      | vector      | 3          | 0.106                 | 0.0024/0.0040   | 0.0365                | 720 000                          | 425 736        | 294 264        | 1 440 000              | 3.216            |
| 10 000      | list        | 3          | 0.110                 | 0.0048/0.0066   | 0.0408                | 800 000                          | 473 040        | 326 960        | 1 600 000              | 3.180            |
| 100 000     | vector      | 1          | 1.075                 | 0.0199          | 0.3371                | 7 200 000                        | 4 210 920      | 2 989 080      | 14 400 000             | 3.219            |
| 100 000     | list        | 1          | 1.063                 | 0.0477          | 0.3495                | 8 000 000                        | 4 678 800      | 3 321 200      | 16 000 000             | 2.673            |
| 100 000     | vector      | 2          | 1.089                 | 46.211          | 0.3149                | 4 210 920                        | 4 210 920      | 2 989 080      | 11 410 920             | 49.474           |
| 100 000     | list        | 2          | 1.071                 | 0.0623          | 0.3211                | 4 678 800                        | 4 678 800      | 3 321 200      | 12 678 800             | 5.332            |
| 100 000     | vector      | 3          | 1.114                 | 0.0212/0.0617   | 0.3175                | 7 200 000                        | 4 210 920      | 2 989 080      | 14 400 000             | 4.168            |
| 100 000     | list        | 3          | 1.093                 | 0.0366/0.0773   | 0.3341                | 8 000 000                        | 4 678 800      | 3 321 200      | 16 000 000             | 4.737            |
| 1 000 000   | vector      | 1          | 10.85                 | 0.203           | 3.406                 | 72 000 000                       | 42 194 664     | 29 805 336     | 144 000 000            | 33.051           |
| 1 000 000   | list        | 1          | 11.005                | 0.426           | 3.521                 | 80 000 000                       | 46 882 960     | 33 117 040     | 160 000 000            | 21.441           |


## Testų rezultatai



## Vector su STL algoritmais

- **Strategija 1 (dvi kopijos)** – dažniausiai greičiausia.  
- **Strategija 2 (viena kopija su trynimu)** – efektyvi tik su mažais failais.  
- **Strategija 3 (automatinė)** – paprastai pasirenka 1 strategiją.  
- Atminties naudojimas auga proporcingai failo dydžiui.  
- Naudojant **STL algoritmus**, programa veikia greitai, bet sunaudoja šiek tiek daugiau atminties dėl laikinų kopijų.

---

## Bendros išvados
# Vector ir List palyginimas pagal strategijas

## Strategija 1 – Dvi kopijos (kietiakiai + vargšiukai)

- **Vector**: labai greitas ir stabilus, nes duomenys saugomi nuosekliai atmintyje.  
- **List**: šiek tiek lėtesnis dėl rodyklių ir išskaidytos atminties.  
- **Išvada:** ši strategija **labiausiai tinka vector**, ypač dideliems failams.

---

## Strategija 2 – Viena kopija su trynimu

- **Vector**: labai **lėtas**, nes kiekvieno elemento trynimas perstumia kitus (ypač kai duomenų daug).  
- **List**: **greitas**, nes elementų trynimas tik pakeičia rodykles, be papildomų kopijų.  
- **Išvada:** ši strategija tinkama tik **list** konteineriui.  
  Naudojant ją su **vector**, laikas stipriai išauga (iki šimtų sekundžių su dideliais failais).

---

## Strategija 3 – Automatinis pasirinkimas

- **Vector** automatiškai pasirenka **1 strategiją**, nes ji greičiausia jam.  
- **List** pasirenka **2 strategiją**, kuri efektyviausia jam.  
- **Išvada:** ši strategija užtikrina optimalų pasirinkimą pagal konteinerį.

---

## Bendros išvados

- **Vector** – geriausias pasirinkimas su **1 strategija** ir dideliais duomenimis.  
- **List** – geriausias su **2 strategija**, kai reikia daug trynimų arba duomenų mažiau.  
- **Strategija 2** yra **labai neefektyvi vector konteineriui**, nes trynimai užtrunka ilgai.  
- **Automatinis režimas (3)** išsprendžia šią problemą, pasirinkdamas greitesnį metodą.

---
# Studentų pažymių valdymo programa – Įdiegimas

## Reikalavimai

- **CMake** ≥ 3.10  
- Kompiliatorius: Visual Studio (Windows), GCC / Clang (Linux / Mac)  
- Projekto failai: `main.cpp`, `funkcijos.cpp/h`, `duomenys.cpp/h`, `studentas.h`, `laikmatis.h`  
- `CMakeLists.txt` projekte

---

## Projekto įdiegimas

1. Atidarykite terminalą ir eikite į projekto katalogą:
```bash
cd /path/to/project
2. Sukurkite katalogą build ir pereikite į jį:
mkdir build
cd build
3. Generuokite projektą pagal savo OS/kompiliatorių:
Windows/Visual Studio
cmake .. -G "Visual Studio 17 2022"
Sugeneruotas .sln failas leis atidaryti projektą Visual Studio.
Projekto kompiliavimas ir paleidimas atliekamas tiesiai iš Visual Studio.
Linux / Mac
cmake ..
make
Sukuriamas vykdomasis failas studentai.

Paleidimas
Windows (Visual Studio): atidarykite .sln ir paleiskite projektą.

Linux / Mac: terminale:
./studentai



 

